package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen1.moduledata.Factory;
import nl.cwi.sen1.moduledata.types.AttributeAttributes;
import nl.cwi.sen1.moduledata.types.DependencyDependencies;
import nl.cwi.sen1.moduledata.types.Module;
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

    public void createModule(ATerm id) {
        System.err.println("Create module: " + id);
        
        if (modules.get(id) != null) {
            System.err.println("Module bestond al");
            return;
        }
        
        DependencyDependencies emptyDependencies = factory
                .makeDependencyDependencies();
        AttributeAttributes emptyAttributes = factory.makeAttributeAttributes();
        Module module = factory.makeModule_Module(id, emptyDependencies,
                emptyAttributes);

        modules.put(id, module);
    }

    public void deleteModule(ATerm id) {
        modules.remove(id);
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
        System.err.println("Module manager started");
    }
}
