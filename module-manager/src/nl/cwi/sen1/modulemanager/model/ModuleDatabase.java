package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;
import java.util.Stack;

import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;

public class ModuleDatabase {
    private int moduleCount;

    protected Map<ModuleId, Module> modules;

    protected Map<ModuleId, Set<ModuleId>> children;

    private InheritedAttributeMap inheritedAttributes;

    private Map<ModuleId, Set<ModuleId>> parents;

    private Map<SCC, Set<SCC>> sccGraph;

    private Map<ModuleId, SCC> moduleSCCMap = new HashMap<ModuleId, SCC>();

    private AttributeSetListener listener;

    public ModuleDatabase(AttributeSetListener l) {
        moduleCount = 0;
        modules = new HashMap<ModuleId, Module>();
        children = new HashMap<ModuleId, Set<ModuleId>>();
        parents = new HashMap<ModuleId, Set<ModuleId>>();
        sccGraph = new HashMap<SCC, Set<SCC>>();
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
        computeSCCGraph();
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
        for (Iterator<SCC> iter = sccGraph.keySet().iterator(); iter.hasNext();) {
            triggerAllInheritedAttributes(iter.next());
        }
    }

    private void triggerAllInheritedAttributes(SCC scc) {
        for (Iterator<InheritedAttribute> iter = inheritedAttributes.iterator(); iter
                .hasNext();) {
            inherit(iter.next(), scc);
        }
    }

    private void triggerInheritedAttributes(SCC scc,
            Set<InheritedAttribute> attrs) {
        for (Iterator<InheritedAttribute> iter = attrs.iterator(); iter
                .hasNext();) {
            inherit(iter.next(), scc);
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

        SCC scc = moduleSCCMap.get(moduleId);

        Set<InheritedAttribute> attrs = inheritedAttributes.getByChildValue(
                namespace, key, value);
        if (!attrs.isEmpty()) {
            setAttribute(scc, namespace, key, value);
        } else {
            ATerm oldValue = module.getAttribute(namespace, key);

            if (oldValue == null || !oldValue.isEqual(value)) {
                module = modules.get(moduleId);
                oldValue = module.getAttribute(namespace, key);
                module.setAttribute(namespace, key, value);

                fireAttributeSetListener(moduleId, namespace, key, oldValue,
                        value);
            }

            // maybe this module now matches the preconditions for an
            // inherited attribute
            triggerAllInheritedAttributes(scc);
        }
    }

    private void setAttribute(SCC scc, ATerm namespace, ATerm key, ATerm value) {
        for (Iterator<ModuleId> iter = scc.getModules().iterator(); iter
                .hasNext();) {
            ModuleId moduleId = iter.next();
            Module module = modules.get(moduleId);
            ATerm oldValue = module.getAttribute(namespace, key);

            if (oldValue == null || !oldValue.isEqual(value)) {
                module = modules.get(moduleId);
                oldValue = module.getAttribute(namespace, key);
                module.setAttribute(namespace, key, value);

                fireAttributeSetListener(moduleId, namespace, key, oldValue,
                        value);
            }
        }
        Set<InheritedAttribute> attrs = inheritedAttributes.getByChildValue(
                namespace, key, value);
        if (!attrs.isEmpty()) {
            propagateToParents(scc, attrs);
        }

        // maybe this module now matches the preconditions for an
        // inherited attribute
        triggerAllInheritedAttributes(scc);
    }

    private void fireAttributeSetListener(ModuleId id, ATerm namespace,
            ATerm key, ATerm oldValue, ATerm newValue) {
        listener.attributeSet(id, namespace, key, oldValue, newValue);
    }

    private void propagateToParents(SCC scc, Set<InheritedAttribute> attrs) {
        for (Iterator<SCC> iter = sccGraph.keySet().iterator(); iter.hasNext();) {
            SCC parent = iter.next();
            Set<SCC> children = sccGraph.get(parent);
            if (children.contains(scc)) {
                triggerInheritedAttributes(parent, attrs);
            }
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
    private void inherit(InheritedAttribute attr, SCC scc) {
        for (Iterator<ModuleId> iter = scc.getModules().iterator(); iter
                .hasNext();) {
            Module module = modules.get(iter.next());
            ATerm comparedValue = getValueOfInheritedAttribute(attr, module);

            if (noMatchForOldValue(attr, comparedValue)) {
                return;
            }
        }

        if (checkPreconditionOnChildren(attr, sccGraph.get(scc))) {
            setAttribute(scc, attr.getNamespace(), attr.getKey(), attr
                    .getNewValue());
        }
    }

    private boolean checkPreconditionOnChildren(InheritedAttribute attr,
            Set<SCC> children) {
        boolean allSet = true;
        boolean oneSet = false;

        for (Iterator<SCC> iter = children.iterator(); iter.hasNext();) {
            SCC scc = iter.next();

            for (Iterator<ModuleId> module = scc.getModules().iterator(); module
                    .hasNext();) {
                Module innerModule = modules.get(module.next());

                ATerm value = getValueOfInheritedAttribute(attr, innerModule);

                if (!value.isEqual(attr.getChildValue())) {
                    allSet = false;
                } else {
                    oneSet = true;
                }
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
            System.err.println("MM - geModuleAttribute: module [" + moduleId
                    + "] doesn't exist");
            return null;
        }

        ATerm value = module.getAttribute(namespace, key);

        return value;
    }

    public ModuleId getModuleIdByAttribute(ATerm namespace, ATerm key,
            ATerm value) {
        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            ModuleId moduleId = iter.next();
            Module module = modules.get(moduleId);

            if (module.getAttribute(namespace, key).equals(value)) {
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

        dependencies = children.get(moduleFromId);
        dependencies.add(moduleToId);

        dependencies = parents.get(moduleToId);
        dependencies.add(moduleFromId);

        computeSCCGraph();
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

        deps = (LinkedList) children.get(moduleFromId);
        deps.remove(moduleToId);

        deps = (LinkedList) parents.get(moduleToId);
        deps.remove(moduleFromId);

        computeSCCGraph();
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

        dependencies = children.get(moduleId);
        dependencies.clear();

        computeSCCGraph();
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

        computeSCCGraph();
    }

    public Map<ModuleId, Set<ModuleId>> getDependencies() {
        return children;
    }

    /*
     * Uses Tarjans SCC algorithm. Taken from Depth-first search and linear
     * graph algorithms (SIAM, Journal on Computing, Vol. 1, No. 2, 1972)
     */
    private void computeSCCGraph() {
        Map<ModuleId, Integer> vertexNumbers = new HashMap<ModuleId, Integer>();
        Map<ModuleId, Integer> vertexLowLinks = new HashMap<ModuleId, Integer>();
        Stack<ModuleId> pointStack = new Stack<ModuleId>();
        int i = 0;

        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            ModuleId id = iter.next();
            if (!vertexNumbers.containsKey(id)) {
                i = computeSCCs(vertexNumbers, vertexLowLinks, pointStack,
                        moduleSCCMap, i, id);
            }
        }

        constructSCCGraph();
    }

    private void constructSCCGraph() {
        sccGraph.clear();
        for (Iterator<ModuleId> iter = modules.keySet().iterator(); iter
                .hasNext();) {
            ModuleId id = iter.next();

            Set<SCC> sccChildren = sccGraph.get(moduleSCCMap.get(id));
            if (sccChildren == null) {
                sccChildren = new HashSet<SCC>();
            }

            Set<ModuleId> children = getChildren(id);
            for (Iterator<ModuleId> child = children.iterator(); child
                    .hasNext();) {
                SCC childSCC = moduleSCCMap.get(child.next());
                if (!childSCC.equals(moduleSCCMap.get(id))) {
                    sccChildren.add(childSCC);
                }
            }

            sccGraph.put(moduleSCCMap.get(id), sccChildren);
        }
    }

    private void printSCCGraph() {
        for (Iterator<SCC> iter = sccGraph.keySet().iterator(); iter.hasNext();) {
            SCC scc = iter.next();
            System.err.println("Root: " + scc.getModules());
            Set<SCC> sccs = sccGraph.get(scc);
            for (Iterator<SCC> childScc = sccs.iterator(); childScc.hasNext();) {
                SCC child = childScc.next();
                System.err.println("+- " + child.getModules());
            }
        }
    }

    private int computeSCCs(Map<ModuleId, Integer> vertexNumbers,
            Map<ModuleId, Integer> vertexLowLinks, Stack<ModuleId> pointStack,
            Map<ModuleId, SCC> moduleSCCMap, int i, ModuleId id) {
        i++;
        vertexNumbers.put(id, i);
        vertexLowLinks.put(id, i);
        pointStack.push(id);

        for (Iterator<ModuleId> childIter = getChildren(id).iterator(); childIter
                .hasNext();) {
            ModuleId child = childIter.next();
            if (!vertexNumbers.containsKey(child)) {
                i = computeSCCs(vertexNumbers, vertexLowLinks, pointStack,
                        moduleSCCMap, i, child);
                Integer lowLinkId = vertexNumbers.get(id);
                Integer lowLinkChild = vertexNumbers.get(child);
                if (lowLinkChild < lowLinkId) {
                    vertexNumbers.put(id, lowLinkChild);
                }
            } else if (vertexNumbers.get(child) < vertexNumbers.get(id)) {
                if (pointStack.contains(child)) {
                    Integer lowLinkId = vertexNumbers.get(id);
                    Integer lowLinkChild = vertexNumbers.get(child);
                    if (lowLinkChild < lowLinkId) {
                        vertexNumbers.put(id, lowLinkChild);
                    }
                }
            }
        }

        if (vertexLowLinks.get(id) == vertexNumbers.get(id)) {
            Boolean complete = false;
            SCC scc = new SCC();

            // System.err.println("Root: " + id.toString());
            while (!pointStack.isEmpty() && !complete) {
                ModuleId top = pointStack.pop();
                if (vertexNumbers.get(top) >= vertexNumbers.get(id)) {
                    scc.add(top);
                    moduleSCCMap.put(top, scc);
                    // System.err.println("+- " + top.toString());
                } else {
                    pointStack.push(top);
                    complete = true;
                }
            }
        }

        return i;
    }
}
