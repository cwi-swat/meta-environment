package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;

public class ModuleDatabase {
    private int moduleCount;

    protected Map<ModuleId, Module> modules;

    protected Map<ModuleId, Set<ModuleId>> descendants;

    private InheritedAttributeMap inheritedAttributes;

    private Map<ModuleId, Set<ModuleId>> ascendants;

    private AttributeSetListener listener;

    public ModuleDatabase(AttributeSetListener l) {
        moduleCount = 0;
        modules = new HashMap<ModuleId, Module>();
        descendants = new HashMap<ModuleId, Set<ModuleId>>();
        ascendants = new HashMap<ModuleId, Set<ModuleId>>();
        listener = l;
        inheritedAttributes = new InheritedAttributeMap();
    }

    public int getNextModuleId() {
        return moduleCount++;
    }

    public void addModule(Module module, ModuleId moduleId) {
        modules.put(moduleId, module);
        descendants.put(moduleId, new HashSet<ModuleId>());
        ascendants.put(moduleId, new HashSet<ModuleId>());
    }

    public void removeModule(ModuleId moduleId) {
        deleteAllDependencies(moduleId);
        modules.remove(moduleId);
        descendants.remove(moduleId);
        ascendants.remove(moduleId);
    }

    public void registerInheritedAttribute(ATerm namespace, ATerm key,
            ATerm negation, ATerm oldValue, ATerm childValue, ATerm newValue, ATerm type) {
        inheritedAttributes.put(namespace, key, negation, oldValue, childValue, newValue,
                type);
        triggerAllAttributeOnAllModules();
    }

    public void unregisterInheritedAttribute(ATerm namespace, ATerm key,
            ATerm oldValue, ATerm childValue, ATerm newValue) {
        inheritedAttributes.remove(namespace, key, oldValue, childValue,
                newValue);
    }

    private void triggerAllAttributeOnAllModules() {
        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            triggerAllInheritedAttributes(iter.next());
        }
    }

    private void triggerAllInheritedAttributes(ModuleId id) {
        for (Iterator<InheritedAttribute> iter = inheritedAttributes.iterator(); iter
                .hasNext();) {
            inherit(iter.next(), id);
        }
    }

    public void setAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
            ATerm value) {
        Module module = modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - addAttribute: module [" + moduleId
                    + "] doesn't exist");
            return;
        }

        updateAttribute(moduleId, namespace, key, value);
    }

    private void updateAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
            ATerm value) {
        Module module = modules.get(moduleId);
        ATerm oldValue = module.getAttribute(namespace, key);

        module.deletePredicate(namespace, key);

        if (oldValue == null || !oldValue.isEqual(value)) {
            module.setAttribute(namespace, key, value);
            fireAttributeSetListener(moduleId, namespace, key, oldValue, value);
            triggerAllInheritedAttributes(moduleId);
            propagateToParents(moduleId);
        }
    }

    private void updatePredicate(ModuleId moduleId, ATerm namespace, ATerm key,
            ATerm value) {
        Module module = modules.get(moduleId);
        ATerm oldValue = module.getPredicate(namespace, key);
        if (oldValue == null) {
            oldValue = module.getAttribute(namespace, key);
        }

        if (oldValue == null || !oldValue.isEqual(value)) {
            module.setPredicate(namespace, key, value);
            fireAttributeSetListener(moduleId, namespace, key, oldValue, value);
            propagateToParents(moduleId);
        }
    }

    private void fireAttributeSetListener(ModuleId id, ATerm namespace,
            ATerm key, ATerm oldValue, ATerm newValue) {
        listener.attributeSet(id, namespace, key, oldValue, newValue);
    }

    private void propagateToParents(ModuleId id) {
        Set<ModuleId> parents = getParents(id);
        for (Iterator<ModuleId> iter = parents.iterator(); iter.hasNext();) {
            triggerAllInheritedAttributes(iter.next());
        }
    }

    /**
     * Changes an attribute of a certain module if: (a) the old value of the
     * attribute matches the registered old value (b) {all,one} of it's
     * dependencies is set to the new value
     * 
     * @param attr
     *            all info about an inherited attribute
     * @param moduleId
     *            reference to a module
     */
    private void inherit(InheritedAttribute attr, ModuleId id) {
        Module module = modules.get(id);
        ATerm comparedValue = getValueOfInheritedAttribute(attr, module);
        ATerm namespace = attr.getNamespace();
        ATerm key = attr.getKey();
        ATerm oldPredicate = module.getPredicate(namespace, key);
        ATerm newValue = attr.getNewValue();

        ATerm currentAttribute = module.getAttribute(namespace, key);

        Boolean noMatch = noMatchForOldValue(attr, comparedValue);
        if (attr.isNotSet()) {
            noMatch = !noMatch;
        }
        
        if (noMatch) {
            if (oldPredicate != null && newValue.equals(oldPredicate)) {
                module.deletePredicate(namespace, key);
                fireAttributeSetListener(id, namespace, key, oldPredicate,
                        currentAttribute);
                propagateToParents(id);
            }
            return;
        }

        if (checkPreconditionOnChildren(attr, getAllChildren(id))) {
            updatePredicate(id, namespace, key, newValue);
        } else if (oldPredicate != null && newValue.equals(oldPredicate)) {
            module.deletePredicate(namespace, key);
            fireAttributeSetListener(id, namespace, key, oldPredicate,
                    currentAttribute);
            propagateToParents(id);
        }
    }

    private boolean checkPreconditionOnChildren(InheritedAttribute attr,
            Set<ModuleId> children) {
        boolean allSet = true;
        boolean oneSet = false;

        for (Iterator<ModuleId> iter = children.iterator(); iter.hasNext();) {
            ModuleId id = iter.next();

            Module innerModule = modules.get(id);

            ATerm value = getValueOfInheritedAttribute(attr, innerModule);

            if (!value.isEqual(attr.getChildValue())) {
                allSet = false;
            } else {
                oneSet = true;
            }
        }

        return (attr.inheritFromAll() && allSet)
                || (attr.inheritFromOne() && oneSet);
    }

    private ATerm getValueOfInheritedAttribute(InheritedAttribute attr,
            Module module) {
        return module.getAttribute(attr.getNamespace(), attr.getKey());
    }

    private boolean noMatchForOldValue(InheritedAttribute attr,
            ATerm comparedValue) {
        return (attr.getOldValue().getType() != ATerm.PLACEHOLDER)
                && (comparedValue == null || (comparedValue != null && !attr
                        .getOldValue().isEqual(comparedValue)));
    }

    public ATerm getModuleAttribute(ModuleId moduleId, ATerm namespace,
            ATerm key) {
        Module module = modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - getModuleAttribute: module [" + moduleId
                    + "] doesn't exist");
            return null;
        }

        ATerm value = module.getPredicate(namespace, key);
        if (value == null) {
            value = module.getAttribute(namespace, key);
        }

        return value;
    }

    public ModuleId getModuleIdByAttribute(ATerm namespace, ATerm key,
            ATerm value) {
        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            ModuleId moduleId = iter.next();
            Module module = modules.get(moduleId);

            if (value.equals(module.getPredicate(namespace, key))) {
                return moduleId;
            } else if (module.getAttribute(namespace, key).equals(value)) {
                return moduleId;
            }
        }

        return null;
    }

    public Set<ModuleId> getAllModules() {
        Set<ModuleId> allModules = new HashSet<ModuleId>();

        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            allModules.add(iter.next());
        }

        return allModules;
    }

    public void deleteModuleAttribute(ModuleId moduleId, ATerm namespace,
            ATerm key) {
        Module module = modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - deleteModuleAttribute: module ["
                    + moduleId + "] doesn't exist");
            return;
        }

        module.deleteAttribute(namespace, key);
    }

    public AttributeStore getAllAttributes(ModuleId moduleId) {
        Module module = modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - getAllAttributes: module [" + moduleId
                    + "] doesn't exist");
            return null;
        }

        return module.getAttributes();
    }

    public void addDependency(ModuleId moduleFromId, ModuleId moduleToId) {
        Set<ModuleId> dependencies;
        Module moduleFrom = modules.get(moduleFromId);
        Module moduleTo = modules.get(moduleToId);

        if (moduleFrom == null) {
            System.err.println("MM - addDependency: module [" + moduleFromId
                    + "] doesn't exist");
            return;
        }

        if (moduleTo == null) {
            System.err.println("MM - addDependency: module [" + moduleToId
                    + "] doesn't exist");
            return;
        }

        dependencies = descendants.get(moduleFromId);
        dependencies.add(moduleToId);

        dependencies = ascendants.get(moduleToId);
        dependencies.add(moduleFromId);
    }

    public Set<ModuleId> getChildren(ModuleId moduleId) {
        return descendants.get(moduleId);
    }

    public Set<ModuleId> getAllChildren(ModuleId moduleId) {
        Set<ModuleId> dependencies = new HashSet<ModuleId>();
        LinkedList<ModuleId> temp = new LinkedList<ModuleId>();

        temp.addAll(getChildren(moduleId));

        while (!temp.isEmpty()) {
            ModuleId tempId = temp.getFirst();
            if (!dependencies.contains(tempId)) {
                dependencies.add(tempId);
                temp.addAll(getChildren(tempId));
            }
            temp.removeFirst();
        }

        return dependencies;
    }

    public Set<ModuleId> getParents(ModuleId moduleId) {
        return ascendants.get(moduleId);
    }

    public Set<ModuleId> getAllParents(ModuleId moduleId) {
        Set<ModuleId> dependencies = new HashSet<ModuleId>();
        LinkedList<ModuleId> temp = new LinkedList<ModuleId>();

        temp.addAll(getParents(moduleId));

        while (!temp.isEmpty()) {
            ModuleId tempId = temp.getFirst();
            if (!dependencies.contains(tempId)) {
                dependencies.add(tempId);
                temp.addAll(getParents(tempId));
            }
            temp.removeFirst();
        }

        return dependencies;
    }

    public Set<ModuleId> getClosableModules(ModuleId moduleId) {
        Set<ModuleId> dependencies = getAllChildren(moduleId);
        LinkedList<ModuleId> temp = new LinkedList<ModuleId>();

        dependencies.add(moduleId);
        temp.addAll(dependencies);

        while (!temp.isEmpty()) {
            ModuleId tempId = temp.getFirst();
            Set parents = getParents(tempId);

            if (!dependencies.containsAll(parents)) {
                Set children = getAllChildren(tempId);
                dependencies.removeAll(children);
                dependencies.remove(tempId);
            }

            temp.removeFirst();
        }

        return dependencies;
    }

    public void deleteDependency(ModuleId moduleFromId, ModuleId moduleToId) {
        LinkedList deps;
        Module moduleFrom = modules.get(moduleFromId);

        if (moduleFrom == null) {
            System.err.println("MM - deleteDependency: module [" + moduleFromId
                    + "] doesn't exist");
            return;
        }

        Module moduleTo = modules.get(moduleToId);

        if (moduleTo == null) {
            System.err.println("MM - deleteDependency: module [" + moduleToId
                    + "] doesn't exist");
            return;
        }

        deps = (LinkedList) descendants.get(moduleFromId);
        deps.remove(moduleToId);

        deps = (LinkedList) ascendants.get(moduleToId);
        deps.remove(moduleFromId);
    }

    public void deleteDependencies(ModuleId moduleId) {
        Set dependencies;

        Module module = modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - deleteDependencies: module [" + moduleId
                    + "] doesn't exist");
            return;
        }

        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            ModuleId tempId = iter.next();
            dependencies = getParents(tempId);
            if (dependencies.contains(moduleId)) {
                dependencies.remove(moduleId);
            }
        }

        dependencies = descendants.get(moduleId);
        dependencies.clear();
    }

    private void deleteAllDependencies(ModuleId moduleId) {
        deleteDependencies(moduleId);

        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            Set dependencies = getChildren(iter.next());
            if (dependencies.contains(moduleId)) {
                dependencies.remove(moduleId);
            }
        }
    }

    public Map<ModuleId, Set<ModuleId>> getDependencies() {
        return descendants;
    }
}
