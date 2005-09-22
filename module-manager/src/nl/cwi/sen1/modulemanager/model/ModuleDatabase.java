package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import aterm.ATerm;

import nl.cwi.sen1.moduleapi.types.ModuleId;

public class ModuleDatabase {
    private int moduleCount;

    protected Map modules;

    protected Map dependencies;

    private Map dependents;

    public ModuleDatabase() {
        moduleCount = 0;
        modules = new HashMap();
        dependencies = new HashMap();
        dependents = new HashMap();
    }

    public int getNextModuleId() {
        return moduleCount++;
    }

    public void addModule(Module module, ModuleId moduleId) {
        // System.err.println("MM - addModule: module [" + moduleId + "]");

        modules.put(moduleId, module);
        dependencies.put(moduleId, new HashSet());
        dependents.put(moduleId, new HashSet());
    }

    public void removeModule(ModuleId moduleId) {
        modules.remove(moduleId);
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
        Set deps;
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

        deps = (Set) dependencies.get(moduleFromId);
        deps.add(moduleToId);

        deps = (Set) dependents.get(moduleToId);
        deps.add(moduleFromId);
    }

    public Set getDependingModules(ModuleId moduleId) {
        return (Set) dependencies.get(moduleId);
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

        deps = (LinkedList) dependencies.get(moduleFromId);
        deps.remove(moduleToId);

        deps = (LinkedList) dependents.get(moduleToId);
        deps.remove(moduleFromId);
    }

    public void deleteDependencies(ModuleId moduleId) {
        Module module = (Module) modules.get(moduleId);

        if (module == null) {
            System.err.println("MM - deleteDependency: module [" + moduleId
                    + "] doesn't exist");
            return;
        }

        List deps = (LinkedList) dependencies.get(moduleId);
        for (Iterator iter = deps.iterator(); iter.hasNext();) {
            ((LinkedList) dependents.get(iter.next())).remove(moduleId);
        }
        deps.clear();
    }

    public Map getDependencies() {
        return dependencies;
    }
}
