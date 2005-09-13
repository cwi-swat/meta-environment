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

    private Factory factory;

    private ModuleManagerBridge bridge;

    public ModuleManager(String[] args) {
        factory = Factory.getInstance(pureFactory);

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
        System.err.println("MM - createModule");

        addModule(new Module());
        return pureFactory.make("snd-value(module-id(<int>))", moduleCount++);
    }

    public ATerm createModule(ATerm name) {
        System.err.println("MM - createModule: module [" + name + "]");

        addModule(new Module(name));
        return pureFactory.make("snd-value(module-id(<int>))", moduleCount++);
    }

    private void addModule(Module module) {
        modules.put(moduleCount, module);
        dependencies.put(moduleCount, new HashSet());
        dependents.put(moduleCount, new HashSet());
    }

    public ATerm getModuleIdByAttribute(ATerm namespace, ATerm key, ATerm value) {
        for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
            int moduleId = ((Integer) iter.next()).intValue();
            Module module = (Module) modules.get(moduleId);

            if (module.getAttribute(namespace, key).equals(value)) {
                return pureFactory
                        .make("snd-value(module-id(<int>))", moduleId);
            }
        }

        return pureFactory.parse("snd-value(no-such-module)");
    }

    public void deleteModule(int id) {
        System.err.println("MM - deleteModule: module [" + id + "]");

        modules.remove(id);
    }

    public void addAttribute(int id, ATerm namespace, ATerm key, ATerm value) {
        // System.err.println("MM - addAttribute: key [" + key + "], value ["
        // + value + "]");

        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - addAttribute: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.setAttribute(namespace, key, value);
    }

    public ATerm getAttribute(int id, ATerm namespace, ATerm key) {
        // System.err.println("MM - getAttribute: key [" + key + "]");

        Module module = (Module) modules.get(id);

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

    public void deleteAttribute(int id, ATerm namespace, ATerm key) {
        Module module = (Module) modules.get(id);

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

    public void addDependency(int from, int to) {
        Set deps;
        Module moduleFrom = (Module) modules.get(from);
        Module moduleTo = (Module) modules.get(to);

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

        deps = (Set) dependencies.get(from);
        deps.add(to);

        deps = (Set) dependents.get(to);
        deps.add(from);
    }

    public ATerm getDependingModules(int id) {
        Module module = (Module) modules.get(id);

        if (module == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        return pureFactory.make("snd-value(depending-modules(<list>))",
                extractATermList((Set) dependencies.get(id)));
    }

    public ATerm getDependenciesByAttribute(ATerm namespace, ATerm key) {
        ATermList deplist = pureFactory.makeList();

        for (Iterator iter = dependencies.keySet().iterator(); iter.hasNext();) {
            int moduleId = ((Integer) iter.next()).intValue();
            Set deps = (Set) dependencies.get(moduleId);

            Module module = (Module) modules.get(moduleId);
            ATerm attribute = module.getAttribute(namespace, key);

            if (attribute != null) {
                ATermList attributes = pureFactory.makeList();
                for (Iterator iter2 = deps.iterator(); iter2.hasNext();) {
                    module = (Module) modules.get(iter2.next());
                    ATerm moduleAttribute = module.getAttribute(namespace, key);

                    if (moduleAttribute != null) {
                        attributes = attributes.append(moduleAttribute);
                    }
                }

                ATermList dependency = pureFactory.makeList(attribute);
                dependency = dependency.append(attributes);
                deplist = deplist.append(dependency);
            }
        }
        return pureFactory.make("snd-value(dependencies-by-attribute(<list>))",
                deplist);
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

    public void deleteDependency(int from, int to) {
        LinkedList deps;
        Module moduleFrom = (Module) modules.get(from);

        if (moduleFrom == null) {
            System.err.println("MM - deleteDependency: module [" + from
                    + "] doesn't exist");
            return;
        }

        Module moduleTo = (Module) modules.get(to);

        if (moduleTo == null) {
            System.err.println("MM - deleteDependency: module [" + to
                    + "] doesn't exist");
            return;
        }

        deps = (LinkedList) dependencies.get(from);
        deps.remove(to);

        deps = (LinkedList) dependents.get(to);
        deps.remove(from);
    }

    public void deleteDependencies(int id) {
        Module moduleFrom = (Module) modules.get(id);

        if (moduleFrom == null) {
            System.err.println("MM - deleteDependency: module [" + id
                    + "] doesn't exist");
            return;
        }

        List deps = (LinkedList) dependencies.get(id);
        for (Iterator iter = deps.iterator(); iter.hasNext();) {
            ((LinkedList) dependents.get(iter.next())).remove(id);
        }
        deps.clear();
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
    }
}
