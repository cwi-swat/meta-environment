package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.DependencyList;
import nl.cwi.sen1.moduleapi.types.Module;
import nl.cwi.sen1.moduleapi.types.UniqueId;
import aterm.ATerm;
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

    public void createModule(ATerm namespace, ATerm id) {
        System.err.println("Create module: " + id);

        if (modules.get(id) != null) {
            System.err.println("Module bestond al");
            return;
        }

        UniqueId uniqueId = factory.makeUniqueId_UniqueId(namespace, id);

        DependencyList emptyDependencyList = factory.makeDependencyList();
        AttributeStore emptyAttributeStore = factory.makeAttributeStore();
        Module module = factory.makeModule_Module(uniqueId, emptyDependencyList,
                emptyAttributeStore);

        modules.put(uniqueId, module);
    }

    public void deleteModule(ATerm namespace, ATerm id) {
        UniqueId uniqueId = factory.makeUniqueId_UniqueId(namespace, id);
        modules.remove(uniqueId);
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
        System.err.println("Module manager started");
    }
}
