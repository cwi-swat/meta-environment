package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.types.ModuleId;
import aterm.ATerm;

public class ModuleDatabase {
    private int moduleCount;

    protected Map modules;

    protected Map children;

    private Map parents;

    public ModuleDatabase() {
        moduleCount = 0;
        modules = new HashMap();
        children = new HashMap();
        parents = new HashMap();
    }

    public int getNextModuleId() {
        return moduleCount++;
    }

    public void addModule(Module module, ModuleId moduleId) {
        modules.put(moduleId, module);
        children.put(moduleId, new HashSet());
        parents.put(moduleId, new HashSet());
    }

    public void removeModule(ModuleId moduleId) {
        deleteDependencies(moduleId);
        modules.remove(moduleId);
        children.remove(moduleId);
        parents.remove(moduleId);
    }

    public void addAttribute(ModuleId moduleId, ATerm namespace, ATerm key,
            ATerm value) {
        Module module = (Module) modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - addAttribute: module [" + moduleId
                    + "] doesn't exist");
            return;
        }

        module.setAttribute(namespace, key, value);
    }

    public ATerm getModuleAttribute(ModuleId moduleId, ATerm namespace,
            ATerm key) {
        Module module = (Module) modules.get(moduleId);

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
            Module module = (Module) modules.get(moduleId);

            if (module.getAttribute(namespace, key).equals(value)) {
                return moduleId;
            }
        }

        return null;
    }

    public Set getAllModulesByAttribute(ATerm namespace, ATerm key) {
        Set allModules = new HashSet();

        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            Module module = (Module) modules.get(moduleId);

            allModules.add(module.getAttribute(namespace, key));
        }

        return allModules;
    }

    public Set getAllModules() {
        Set allModules = new HashSet();

        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            allModules.add(moduleId);
        }

        return allModules;
    }

    public void deleteModuleAttribute(ModuleId moduleId, ATerm namespace,
            ATerm key) {
        Module module = (Module) modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - deleteModuleAttribute: module ["
                    + moduleId + "] doesn't exist");
            return;
        }

        module.deleteAttribute(namespace, key);
    }

    public void addDependency(ModuleId moduleFromId, ModuleId moduleToId) {
        Set dependencies;
        Module moduleFrom = (Module) modules.get(moduleFromId);
        Module moduleTo = (Module) modules.get(moduleToId);

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

        dependencies = (Set) children.get(moduleFromId);
        dependencies.add(moduleToId);

        dependencies = (Set) parents.get(moduleToId);
        dependencies.add(moduleFromId);
    }

    public Set getChildren(ModuleId moduleId) {
        return (Set) children.get(moduleId);
    }

    public Set getParents(ModuleId moduleId) {
        return (Set) parents.get(moduleId);
    }

    public Set getAllChildren(ModuleId moduleId) {
        Set dependencies = new HashSet();
        LinkedList temp = new LinkedList();

        temp.add(moduleId);

        while (!temp.isEmpty()) {
            ModuleId tempId = (ModuleId) temp.getFirst();
            if (!dependencies.contains(tempId)) {
                dependencies.add(tempId);
                temp.addAll(getChildren(tempId));
            }
            temp.removeFirst();
        }

        return dependencies;
    }

    public Set getClosableModules(ModuleId moduleId) {
        Set dependencies = getAllChildren(moduleId);
        LinkedList temp = new LinkedList();

        temp.addAll(dependencies);

        while (!temp.isEmpty()) {
            ModuleId tempId = (ModuleId) temp.getFirst();
            Set parents = getParents(tempId);

            if (!dependencies.containsAll(parents)) {
                Set children = getAllChildren(tempId);
                dependencies.removeAll(children);
            }

            temp.removeFirst();
        }

        return dependencies;
    }

    public void deleteDependency(ModuleId moduleFromId, ModuleId moduleToId) {
        LinkedList deps;
        Module moduleFrom = (Module) modules.get(moduleFromId);

        if (moduleFrom == null) {
            System.err.println("MM - deleteDependency: module [" + moduleFromId
                    + "] doesn't exist");
            return;
        }

        Module moduleTo = (Module) modules.get(moduleToId);

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

        Module module = (Module) modules.get(moduleId);

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

        dependencies = (Set) children.get(moduleId);
        dependencies.clear();
    }

    public Map getDependencies() {
        return children;
    }
}
