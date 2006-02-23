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

    protected Map<ModuleId, Set<ModuleId>> children;

    private InheritedAttributeMap inheritedAttributes;

    private Map<ModuleId, Set<ModuleId>> parents;

    private AttributeSetListener listener;

    private int indent = 0;

    public ModuleDatabase(AttributeSetListener l) {
        moduleCount = 0;
        modules = new HashMap<ModuleId, Module>();
        children = new HashMap<ModuleId, Set<ModuleId>>();
        parents = new HashMap<ModuleId, Set<ModuleId>>();
        listener = l;
        inheritedAttributes = new InheritedAttributeMap();
    }

    public int getNextModuleId() {
        return moduleCount++;
    }

    public void addModule(Module module, ModuleId moduleId) {
        modules.put(moduleId, module);
        children.put(moduleId, new HashSet<ModuleId>());
        parents.put(moduleId, new HashSet<ModuleId>());
    }

    public void removeModule(ModuleId moduleId) {
        deleteAllDependencies(moduleId);
        modules.remove(moduleId);
        children.remove(moduleId);
        parents.remove(moduleId);
    }

    public void registerInheritedAttribute(ATerm namespace, ATerm key,
            ATerm oldValue, ATerm childValue, ATerm newValue, ATerm type) {
        inheritedAttributes.put(namespace, key, oldValue, childValue, newValue,
                type);
        // TODO: needs only to be done for bottom modules??
        triggerAllAttributeOnAllModules();
    }

    public void unregisterInheritedAttribute(ATerm namespace, ATerm key,
            ATerm oldValue, ATerm childValue, ATerm newValue) {
        inheritedAttributes.remove(namespace, key, oldValue, childValue,
                newValue);
    }

    private void triggerAllAttributeOnAllModules() {
        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            triggerAllInheritedAttributes(moduleId);
        }
    }

    private void triggerAllInheritedAttributes(ModuleId id) {
        for (Iterator iter = inheritedAttributes.iterator(); iter.hasNext();) {
            InheritedAttribute attr = (InheritedAttribute) iter.next();
            inherit(attr, id, id);
        }
    }

    private void triggerInheritedAttributes(ModuleId root, ModuleId id,
            Set attrs) {
        for (Iterator iter = attrs.iterator(); iter.hasNext();) {
            InheritedAttribute attr = (InheritedAttribute) iter.next();
            inherit(attr, root, id);
        }
    }

    public void setAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
            ATerm value) {
        setAttribute(moduleId, namespace, key, value, true);
    }

    /**
     * Set an attribute of a module to a new value if: - the new value is
     * different from the old value
     * 
     * @param moduleId
     * @param namespace
     * @param key
     * @param value
     */
    public void setAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
            ATerm value, boolean propagate) {
        Module module = modules.get(moduleId);

        // indentedPrint("setAttribute: " + key + " to " + value + " on "
        // + moduleId);
        if (module == null) {
            System.err.println("MM - addAttribute: module [" + moduleId
                    + "] doesn't exist");
            return;
        }

        ATerm oldValue = module.getAttribute(namespace, key);

        if (oldValue == null || !oldValue.isEqual(value)) {
            indent++;

            module.setAttribute(namespace, key, value);

            fireAttributeSetListener(moduleId, namespace, key, oldValue, value);

            if (propagate) {
                Set attrs = inheritedAttributes.getByChildValue(namespace, key,
                        value);
                if (!attrs.isEmpty()) {
                    propagateToParents(moduleId, attrs);
                }
            }

            // maybe this module now matches the preconditions for an inherited
            // attribute
            triggerAllInheritedAttributes(moduleId);
            indent--;
        }
    }

    private void fireAttributeSetListener(ModuleId id, ATerm namespace,
            ATerm key, ATerm oldValue, ATerm newValue) {
        listener.attributeSet(id, namespace, key, oldValue, newValue);
    }

    private void propagateToParents(ModuleId id, Set attrs) {
        Set parents = getParents(id);

        for (Iterator iter = parents.iterator(); iter.hasNext();) {
            ModuleId parent = (ModuleId) iter.next();
            triggerInheritedAttributes(id, parent, attrs);
        }
    }

    /**
     * Changes an attribute of a certain module if: (a) the old value of the
     * attribute matches the registered old value (b) {all,one} of it's
     * dependencies is set to the new value
     * 
     * Note the hidden recursion, this function calls setAttribute again which
     * may trigger this method.
     * 
     * If the module is part of a cycle, and all elements of the cycle are set
     * to the old value, we may set this module to the new value too.
     * 
     * @param attr
     *            all info about an inherited attribute
     * @param moduleId
     *            reference to a module
     */
    private void inherit(InheritedAttribute attr, ModuleId root,
            ModuleId moduleId) {
        if (isCyclic(moduleId)) {
            if (root.isEqual(moduleId)) {
                singleModuleInherit(attr, moduleId, false);
            }

            Set<ModuleId> cycle = getModulesInCycle(moduleId);

            Set<ModuleId> children = getCycleChildren(cycle);

            boolean cycleContainsRoot = cycle.contains(root);

            if (attr.inheritFromOne() && cycleContainsRoot) {
                children.add(root);
                children.removeAll(getChildren(root));
                cycle.remove(root);
            } else if (attr.inheritFromAll() && cycleContainsRoot) {
                cycle.remove(root);
            }

            // check all elements of the cycle
            for (Iterator inner = cycle.iterator(); inner.hasNext();) {
                ModuleId elem = (ModuleId) inner.next();
                Module elemModule = modules.get(elem);

                ATerm elemValue = getValueOfInheritedAttribute(attr, elemModule);

                if (noMatchForOldValue(attr, elemValue)) {
                    // System.err.println("\tno because " + elem
                    // + " is not set to old value");
                    return;
                }
            }

            if (checkPreconditionOnChildren(attr, children)) {
                setAttributeOnModules(cycle, attr.getNamespace(),
                        attr.getKey(), attr.getNewValue());

                Set parents = getCycleParents(cycle);
                for (Iterator iter = parents.iterator(); iter.hasNext();) {
                    ModuleId parent = (ModuleId) iter.next();
                    inherit(attr, root, parent);
                }
            }
        } else { /* not cyclic */
            singleModuleInherit(attr, moduleId, true);
        }
    }

    private void singleModuleInherit(InheritedAttribute attr,
            ModuleId moduleId, boolean propagate) {
        Module module = modules.get(moduleId);
        ATerm comparedValue = getValueOfInheritedAttribute(attr, module);

        if (noMatchForOldValue(attr, comparedValue)) {
            return;
        }

        if (checkPreconditionOnChildren(attr, getChildren(moduleId))) {
            setAttribute(moduleId, attr.getNamespace(), attr.getKey(), attr
                    .getNewValue(), propagate);
        }
    }

    private boolean checkPreconditionOnChildren(InheritedAttribute attr,
            Set children) {
        boolean allSet = true;
        boolean oneSet = false;

        for (Iterator iter = children.iterator(); iter.hasNext();) {
            ModuleId child = (ModuleId) iter.next();

            Module innerModule = modules.get(child);

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

    private void setAttributeOnModules(Set cycle, ATerm namespace, ATerm key,
            ATerm value) {
        for (Iterator iter = cycle.iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            Module module = modules.get(moduleId);
            ATerm oldValue = module.getAttribute(namespace, key);

            if (!oldValue.equals(value)) {
                module.setAttribute(namespace, key, value);
                fireAttributeSetListener(moduleId, namespace, key, oldValue,
                        value);
            }
        }
    }

    private Set<ModuleId> getCycleParents(Set<ModuleId> cycle) {
        Iterator iter = cycle.iterator();
        Set<ModuleId> result = new HashSet<ModuleId>();

        if (iter.hasNext()) {
            ModuleId first = (ModuleId) iter.next();
            Set<ModuleId> parents = getAllParents(first);

            result.addAll(parents);
            result.removeAll(cycle);
        }
        return result;
    }

    private Set<ModuleId> getCycleChildren(Set<ModuleId> cycle) {
        Iterator iter = cycle.iterator();
        Set<ModuleId> result = new HashSet<ModuleId>();

        if (iter.hasNext()) {
            ModuleId first = (ModuleId) iter.next();
            Set<ModuleId> children = getAllChildren(first);

            result.addAll(children);
            result.removeAll(cycle);
        }
        return result;
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

    private void findCycles(ModuleId current, Set<ModuleId> modules,
            Set<ModuleId> path) {
        if (path.contains(current)) {
            modules.addAll(path);
        } else {
            path.add(current);
            for (Iterator iter = getChildren(current).iterator(); iter
                    .hasNext();) {
                ModuleId child = (ModuleId) iter.next();
                findCycles(child, modules, path);
            }
            path.remove(current);
        }
    }

    private Set<ModuleId> getModulesInCycle(ModuleId moduleId) {
        Set<ModuleId> cycle = new HashSet<ModuleId>();
        findCycles(moduleId, cycle, new HashSet<ModuleId>());
        return cycle;
    }

    private boolean isCyclic(ModuleId id) {
        Set parents = getAllParents(id);

        return parents.contains(id);
    }

    public ATerm getModuleAttribute(ModuleId moduleId, ATerm namespace,
            ATerm key) {
        Module module = modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - geModuleAttribute: module [" + moduleId
                    + "] doesn't exist");
            return null;
        }

        ATerm value = module.getAttribute(namespace, key);

        return value;
    }

    public ModuleId getModuleIdByAttribute(ATerm namespace, ATerm key,
            ATerm value) {
        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            Module module = modules.get(moduleId);

            if (module.getAttribute(namespace, key).equals(value)) {
                return moduleId;
            }
        }

        return null;
    }

    public Set getAllModules() {
        Set<ModuleId> allModules = new HashSet<ModuleId>();

        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            allModules.add(moduleId);
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

        dependencies = children.get(moduleFromId);
        dependencies.add(moduleToId);

        dependencies = parents.get(moduleToId);
        dependencies.add(moduleFromId);
    }

    public Set<ModuleId> getChildren(ModuleId moduleId) {
        return children.get(moduleId);
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
        return parents.get(moduleId);
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

    public Set getClosableModules(ModuleId moduleId) {
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

        deps = (LinkedList) children.get(moduleFromId);
        deps.remove(moduleToId);

        deps = (LinkedList) parents.get(moduleToId);
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

        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId tempId = (ModuleId) iter.next();
            dependencies = getParents(tempId);
            if (dependencies.contains(moduleId)) {
                dependencies.remove(moduleId);
            }
        }

        dependencies = children.get(moduleId);
        dependencies.clear();
    }

    private void deleteAllDependencies(ModuleId moduleId) {
        deleteDependencies(moduleId);

        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId tempId = (ModuleId) iter.next();
            Set dependencies = getChildren(tempId);
            if (dependencies.contains(moduleId)) {
                dependencies.remove(moduleId);
            }
        }

    }

    public Map getDependencies() {
        return children;
    }
}
