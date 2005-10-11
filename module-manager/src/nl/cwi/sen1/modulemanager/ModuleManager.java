package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.Iterator;
import java.util.Map;
import java.util.Set;

import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.Dependency;
import nl.cwi.sen1.moduleapi.types.DependencyList;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import nl.cwi.sen1.moduleapi.types.ModuleIdList;
import nl.cwi.sen1.modulemanager.model.Module;
import nl.cwi.sen1.modulemanager.model.ModuleGraph;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class ModuleManager implements ModuleManagerTif {
    private ModuleGraph moduleDB;

    private PureFactory pureFactory = new PureFactory();

    private Factory factory = Factory.getInstance(pureFactory);

    private ModuleManagerBridge bridge;

    public ModuleManager(String[] args) {
        moduleDB = new ModuleGraph(pureFactory);

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

        ModuleId moduleId = factory
                .makeModuleId_Mid(moduleDB.getNextModuleId());
        moduleDB.addModule(new Module(), moduleId);
        return pureFactory.make("snd-value(module-id(<term>))", moduleId
                .toTerm());
    }

    public ATerm getModuleIdByAttribute(ATerm namespace, ATerm key, ATerm value) {
//        System.err.println("MM - getModuleIdByAttribute: namespace ["
//                + namespace + "], key [" + key + "], value [" + value + "]");

        ModuleId moduleId = moduleDB.getModuleIdByAttribute(namespace, key,
                value);

        if (moduleId == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        return pureFactory.make("snd-value(module-id(<term>))", moduleId
                .toTerm());
    }

    public void deleteModule(ATerm id) {
        System.err.println("MM - deleteModule: module [" + id + "]");

        ModuleId moduleId = factory.ModuleIdFromTerm(id);
        moduleDB.removeModule(moduleId);
    }

    public void addAttribute(ATerm id, ATerm namespace, ATerm key, ATerm value) {
        // System.err.println("MM - addAttribute: module [" + id + "], key ["
        // + key + "], value [" + value + "]");

        ModuleId moduleId = factory.ModuleIdFromTerm(id);
        moduleDB.addAttribute(moduleId, namespace, key, value);

    }

    public ATerm getAttribute(ATerm id, ATerm namespace, ATerm key) {
        // System.err.println("MM - getAttribute: module [" + id + "], key ["
        // + key + "]");

        ModuleId moduleId = factory.ModuleIdFromTerm(id);
        ATerm value = moduleDB.getModuleAttribute(moduleId, namespace, key);

        if (value == null) {
            return pureFactory.parse("snd-value(no-such-key)");
        }

        // System.err.println("MM - getAttribute: value [" + value + "]");

        return pureFactory.make("snd-value(attribute(<term>))", value);
    }

    public void deleteAttribute(ATerm id, ATerm namespace, ATerm key) {
        ModuleId moduleId = factory.ModuleIdFromTerm(id);

        moduleDB.deleteModuleAttribute(moduleId, namespace, key);
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
        ModuleId moduleFromId = factory.ModuleIdFromTerm(from);
        ModuleId moduleToId = factory.ModuleIdFromTerm(to);

        moduleDB.addDependency(moduleFromId, moduleToId);
    }

    public ATerm getDependingModules(ATerm id) {
        ModuleId moduleId = factory.ModuleIdFromTerm(id);

        Set dependencies = moduleDB.getDependingModules(moduleId);

        if (dependencies == null) {
            return pureFactory.parse("snd-value(no-such-module)");
        }

        return pureFactory.make("snd-value(depending-modules(<list>))",
                extractATermList(dependencies));
    }

    public ATerm getDependencies() {
        DependencyList list = factory.makeDependencyList();
        Map dependencies = moduleDB.getDependencies();

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
        return pureFactory.make("snd-value(dependencies(<term>))", list
                .toTerm());
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
        ModuleId moduleFromId = factory.ModuleIdFromTerm(from);
        ModuleId moduleToId = factory.ModuleIdFromTerm(to);

        moduleDB.deleteDependency(moduleFromId, moduleToId);
    }

    public void deleteDependencies(ATerm id) {
        ModuleId moduleId = factory.ModuleIdFromTerm(id);
        moduleDB.deleteDependencies(moduleId);
    }

    public ATerm getModuleGraph(ATerm namespace) {
        Graph graph = moduleDB.getModuleGraph(namespace);

        // System.err.println("MM - getModuleGraph: graph [" + graph + "]");

        return pureFactory.make("snd-value(module-graph(<term>))", graph
                .toTerm());
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
    }
}
