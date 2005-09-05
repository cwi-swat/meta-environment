package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.HashMap;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import nl.cwi.sen1.modulemanager.model.Module;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class ModuleManager implements ModuleManagerTif {
    private Map modules;

    private PureFactory pureFactory;

    private Factory factory;

    private ModuleManagerBridge bridge;

    public ModuleManager(String[] args) {
        modules = new HashMap();

        pureFactory = new PureFactory();

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

    public ATerm getModuleId(ATerm namespace, ATerm id) {
        ModuleId moduleId = factory.makeModuleId_ModuleId(namespace, id);

        return pureFactory.make("snd-value(module-id(<term>))", moduleId
                .toTerm());
    }

    public void createModule(ATerm id) {
        System.err.println("MM - createModule: module [" + id + "]");

        if (modules.get(id) != null) {
            System.err.println("MM - createModule: module [" + id
                    + "] already exists");
            return;
        }

        modules.put(id, new Module(id));
    }

    public void deleteModule(ATerm id) {
        System.err.println("MM - deleteModule: module [" + id + "]");

        modules.remove(id);
    }

    public void addAttribute(ATerm id, ATerm namespace, ATerm key, ATerm value) {
        System.err.println("MM - addAttribute: module [" + id
                + "], namespace [" + namespace + "], key [" + key
                + "], value [" + value + "]");

        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - addAttribute: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.addAttribute(namespace, key, value);
    }

    public ATerm getAttribute(ATerm id, ATerm namespace, ATerm key) {
        System.err.println("MM - getAttribute: module [" + id
                + "], namespace [" + namespace + "], key [" + key + "]");

        Module module = (Module) modules.get(id);

        if (module == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        ATerm value = module.getAttribute(namespace, key);

        if (value == null) {
            return pureFactory.parse("snd-value(no-such-key)");
        }

        return pureFactory.make("snd-value(attribute(<term>))", value);
    }

    public void deleteAttribute(ATerm id, ATerm namespace, ATerm key) {
        System.err.println("MM - addAttribute: module [" + id
                + "], namespace [" + namespace + "], key [" + key + "]");

        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - deleteAttribute: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.deleteAttribute(namespace, key);
    }

    public void addDependency(ATerm id, ATerm dependency) {
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - addDependency: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.addDependency(dependency);
    }

    public ATerm getDependingModules(ATerm id) {
        Module module = (Module) modules.get(id);

        if (module == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        Set dependencies = module.getDependencies();

        return pureFactory.make("snd-value(depending-modules(<list>))",
                extractATermList(dependencies));
    }

    public ATerm getDependentModules(ATerm id) {
        Module module = (Module) modules.get(id);

        if (module == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        Set dependentModules = getDependents(id);

        return pureFactory.make("snd-value(depending-modules(<list>))",
                extractATermList(dependentModules));
    }

    private ATermList extractATermList(Set dependencies) {
        ATermList list = pureFactory.makeList();
        for (Iterator iter = dependencies.iterator(); iter.hasNext();) {
            list = list.append((ATerm) iter.next());
        }
        return list;
    }

    private Set getDependents(ATerm id) {
        Set dependentModules = new HashSet();
        LinkedList temp = new LinkedList();

        temp.add(id);

        while (!temp.isEmpty()) {
            ATerm cur = (ATerm) temp.getFirst();
            dependentModules.add(cur);
            temp.remove(cur);

            for (Iterator iter = modules.keySet().iterator(); iter.hasNext();) {
                Module dependent = (Module) iter.next();
                if (dependent.getDependencies().contains(cur)
                        && !dependentModules.contains(dependent.getName())) {
                    temp.add(cur);
                }
            }
        }

        return dependentModules;
    }

    public void deleteDependency(ATerm id, ATerm dependency) {
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - deleteDependency: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.deleteDependency(dependency);
    }

    public void deleteDependencies(ATerm id) {
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - deleteDependencies: module [" + id
                    + "] doesn't exist");
            return;
        }

        module.deleteDependencies();
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
    }
}
