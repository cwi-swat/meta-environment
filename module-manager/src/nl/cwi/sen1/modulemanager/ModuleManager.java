package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.Dependency;
import nl.cwi.sen1.moduleapi.types.DependencyList;
import nl.cwi.sen1.moduleapi.types.ModuleAttribute;
import nl.cwi.sen1.moduleapi.types.ModuleAttributeList;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import nl.cwi.sen1.moduleapi.types.ModuleIdList;
import nl.cwi.sen1.modulemanager.model.Module;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class ModuleManager implements ModuleManagerTif {
    private int moduleCount = 0;

    private Map modules = new HashMap();

    private Map dependencies = new HashMap();

    private Map dependents = new HashMap();

    private PureFactory pureFactory = new PureFactory();

    private Factory factory = Factory.getInstance(pureFactory);

    private ModuleManagerBridge bridge;

    public ModuleManager(String[] args) {
        bridge = new ModuleManagerBridge(pureFactory, this);
        try {
            bridge.init(args);
            bridge.connect();
        } catch (IOException e) {
            System.err.println("Could not establish connection to ToolBus: "
                    + e);
            System.exit(1);
        }

        Thread thread = new Thread(new Runnable() {
            public void run() {
                bridge.run();
            }
        });
        thread.setName("ModuleManager");
        thread.start();
    }

    public ATerm createModule() {
        // System.err.println("MM - createModule");

        ModuleId moduleId = factory.makeModuleId_Mid(moduleCount++);
        addModule(new Module(), moduleId);
        return pureFactory.make("snd-value(module-id(<term>))", moduleId
                .toTerm());
    }

    private void addModule(Module module, ModuleId moduleId) {
        // System.err.println("MM - addModule: module [" + moduleId + "]");

        modules.put(moduleId, module);
        dependencies.put(moduleId, new HashSet());
        dependents.put(moduleId, new HashSet());
    }

    public ATerm getModuleIdByAttribute(ATerm namespace, ATerm key, ATerm value) {
        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            Module module = (Module) modules.get(moduleId);

            if (module.getAttribute(namespace, key).equals(value)) {
                return pureFactory.make("snd-value(module-id(<term>))",
                        moduleId.toTerm());
            }
        }

        return pureFactory.parse("snd-value(no-such-module)");
    }

    public void deleteModule(ATerm id) {
        System.err.println("MM - deleteModule: module [" + id + "]");

        ModuleId moduleId = factory.ModuleIdFromTerm(id);
        modules.remove(moduleId);
    }

    public void addAttribute(ATerm id, ATerm namespace, ATerm key, ATerm value) {
        // System.err.println("MM - addAttribute: module [" + id + "], key ["
        // + key + "], value [" + value + "]");

        Module module = getModule(id);

        if (module == null) {
            System.err.println("MM - addAttribute: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.setAttribute(namespace, key, value);
    }

    public ATerm getAttribute(ATerm id, ATerm namespace, ATerm key) {
        // System.err.println("MM - getAttribute: module [" + id + "], key ["
        // + key + "]");

        Module module = getModule(id);

        if (module == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        ATerm value = module.getAttribute(namespace, key);

        if (value == null) {
            return pureFactory.parse("snd-value(no-such-key)");
        }

        // System.err.println("MM - getAttribute: value [" + value + "]");

        return pureFactory.make("snd-value(attribute(<term>))", value);
    }

    public ATerm getModuleAttributeMap(ATerm namespace, ATerm key) {
        ModuleAttributeList map = factory.makeModuleAttributeList();

        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            Module module = (Module) modules.get(moduleId);

            ATerm attribute = module.getAttribute(namespace, key);

            if (attribute != null) {
                ModuleAttribute pair = factory
                        .makeModuleAttribute_ModuleAttribute(moduleId,
                                attribute);
                map = map.append(pair);
            }
        }

        return pureFactory.make("snd-value(module-attribute-map(<term>))",
                factory.makeAttributeMap_AttributeMap(map).toTerm());
    }

    public void deleteAttribute(ATerm id, ATerm namespace, ATerm key) {
        Module module = getModule(id);

        if (module == null) {
            System.err.println("MM - deleteAttribute: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.deleteAttribute(namespace, key);
    }

    // public void addDependencies(ATerm dependencies) {
    // ATermList deps = (ATermList) dependencies;
    //
    // while (!deps.isEmpty()) {
    // Dependency dep = (Dependency) deps.getFirst();
    // addDependency(dep.getFrom(), dep.getTo());
    // deps = deps.getNext();
    // }
    // }

    public void addDependency(ATerm from, ATerm to) {
        Set deps;
        Module moduleFrom = getModule(from);
        Module moduleTo = getModule(to);

        if (moduleFrom == null) {
            System.err.println("MM - addDependency: module [" + from
                    + "] doesn't exist");
            return;
        }

        if (moduleTo == null) {
            System.err.println("MM - addDependency: module [" + to
                    + "] doesn't exist");
            return;
        }

        ModuleId fromId = factory.ModuleIdFromTerm(from);
        ModuleId toId = factory.ModuleIdFromTerm(to);

        deps = (Set) dependencies.get(fromId);
        deps.add(toId);

        deps = (Set) dependents.get(toId);
        deps.add(fromId);
    }

    public ATerm getDependingModules(ATerm id) {
        Module module = getModule(id);

        if (module == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        return pureFactory.make("snd-value(depending-modules(<list>))",
                extractATermList((Set) dependencies.get(id)));
    }

    public ATerm getDependencies() {
        DependencyList list = factory.makeDependencyList();

        for (Iterator iter = dependencies.keySet().iterator(); iter.hasNext();) {
            ModuleId moduleId = (ModuleId) iter.next();
            Set deps = (Set) dependencies.get(moduleId);

            ModuleIdList moduleList = factory.makeModuleIdList();
            for (Iterator depsIter = deps.iterator(); depsIter.hasNext();) {
                ModuleId dependencyId = (ModuleId) depsIter.next();
                moduleList = moduleList.append(dependencyId);
            }

            Dependency dependency = factory.makeDependency_Dependency(moduleId,
                    moduleList);
            list = list.append(dependency);
        }
        return pureFactory.make("snd-value(dependencies(<term>))", list.toTerm());
    }

    // public ATerm getDependentModules(int id) {
    // Module module = (Module) modules.get(id);
    //
    // if (module == null) {
    // return pureFactory.parse("snd-value(no-such-module)");
    // }
    //
    // return pureFactory.make("snd-value(depending-modules(<list>))",
    // extractATermList((Set) dependents.get(id)));
    // }

    private ATermList extractATermList(Set dependencies) {
        ATermList list = pureFactory.makeList();
        for (Iterator iter = dependencies.iterator(); iter.hasNext();) {
            list = list.append((ATerm) iter.next());
        }
        return list;
    }

    public void deleteDependency(ATerm from, ATerm to) {
        LinkedList deps;
        Module moduleFrom = getModule(from);

        if (moduleFrom == null) {
            System.err.println("MM - deleteDependency: module [" + from
                    + "] doesn't exist");
            return;
        }

        Module moduleTo = getModule(to);

        if (moduleTo == null) {
            System.err.println("MM - deleteDependency: module [" + to
                    + "] doesn't exist");
            return;
        }

        ModuleId fromId = factory.ModuleIdFromTerm(from);
        ModuleId toId = factory.ModuleIdFromTerm(to);

        deps = (LinkedList) dependencies.get(fromId);
        deps.remove(toId);

        deps = (LinkedList) dependents.get(toId);
        deps.remove(fromId);
    }

    public void deleteDependencies(ATerm id) {
        Module moduleFrom = getModule(id);
        ModuleId moduleId = factory.ModuleIdFromTerm(id);

        if (moduleFrom == null) {
            System.err.println("MM - deleteDependency: module [" + id
                    + "] doesn't exist");
            return;
        }

        List deps = (LinkedList) dependencies.get(moduleId);
        for (Iterator iter = deps.iterator(); iter.hasNext();) {
            ((LinkedList) dependents.get(iter.next())).remove(moduleId);
        }
        deps.clear();
    }

    private Module getModule(ATerm id) {
        ModuleId moduleId = factory.ModuleIdFromTerm(id);
        Module module = (Module) modules.get(moduleId);

        return module;
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
    }
}
