package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.Attribute;
import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.DependencyList;
import nl.cwi.sen1.moduleapi.types.Module;
import nl.cwi.sen1.moduleapi.types.ModuleId;
import nl.cwi.sen1.moduleapi.types.TableEntry;
import nl.cwi.sen1.moduleapi.types.TableEntryTable;
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

    public ATerm getModuleId(ATerm namespace, ATerm id) {
        ModuleId moduleId = factory.makeModuleId_ModuleId(namespace, id);

        System.err.println("ModuleId: " + moduleId);

        return factory.getPureFactory().make("snd-value(module-id(<term>))",
                moduleId.toTerm());
    }

    public void createModule(ATerm moduleId) {
        ModuleId id = factory.ModuleIdFromTerm(moduleId);

        if (modules.get(id) != null) {
            System.err.println("MM - createModule: module [" + moduleId
                    + "] already exists");
            return;
        }

        DependencyList emptyDependencyList = factory.makeDependencyList();
        AttributeStore emptyAttributeStore = factory.makeAttributeStore();

        if (emptyAttributeStore.isEmpty()) {
            System.err.println("AttributeStore is empty");
        } else {
            System.err.println("AttributeStore is NOT empty");
        }
        Module module = factory.makeModule_Module(id, emptyDependencyList,
                emptyAttributeStore);

        modules.put(id, module);
    }

    public void deleteModule(ATerm moduleId) {
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        modules.remove(id);
    }

    public void addAttribute(ATerm moduleId, ATerm namespace, ATerm key,
            ATerm value) {
        TableEntryTable table;

        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - addAttribute: no such module [" + moduleId
                    + "]");
            return;
        }

        AttributeStore store = module.getStore();
        table = getAttributeTable(namespace, store);

        if (table == null) {
            TableEntry tableEntry = factory.makeTableEntry_TableEntry(key,
                    value);
            table = factory.makeTableEntryTable(tableEntry);
        } else {
            TableEntry entry = getTableEntry(key, table);

            if (entry == null) {
                entry = factory.makeTableEntry_TableEntry(key, value);
                table = table.append(entry);
            } else {
                // Add boolean overwrite to method arguments??
                System.err.println("MM - addAttribute: key [" + key
                        + "] already exists");
            }
        }

        Attribute attribute = getAttribute(namespace, store);
        if (attribute == null) {
            attribute = factory.makeAttribute_Attribute(namespace, table);
        } else {
            attribute = attribute.setTable(table);
        }

        if (store.isEmpty()) {
            store = store.append(attribute);
        } else {
            store = replaceAttribute(attribute, store);
        }

        System.err.println("Store: " + store);

        module = module.setStore(store);

        modules.put(id, module);
    }

    private Attribute getAttribute(ATerm namespace, AttributeStore store) {
        Attribute attribute = null;
        boolean found = false;

        while (!store.isEmpty() && !found) {
            attribute = store.getHead();
            if (attribute.getNamespace().equals(namespace)) {
                found = true;
            }
            store = store.getTail();
        }

        if (found) {
            return attribute;
        } 
            
        return null;
    }

    private TableEntryTable getAttributeTable(ATerm namespace,
            AttributeStore store) {
        TableEntryTable table = null;
        boolean found = false;

        while (!store.isEmpty() && !found) {
            Attribute attribute = store.getHead();
            if (attribute.getNamespace().equals(namespace)) {
                table = attribute.getTable();
                found = true;
            }
            store = store.getTail();
        }

        if (found) {
            return table;
        } 
        return null;
    }

    private TableEntry getTableEntry(ATerm key, TableEntryTable table) {
        TableEntry entry = null;
        boolean found = false;

        while (!table.isEmpty() && !found) {
            entry = table.getHead();
            if (entry.getKey().equals(key)) {
                found = true;
            }
            table = table.getTail();
        }

        if (found) {
            return entry;
        }
        return null;
    }

    private AttributeStore replaceAttribute(Attribute attribute,
            AttributeStore store) {
        AttributeStore newStore = factory.makeAttributeStore();

        while (!store.isEmpty()) {
            Attribute storedAttribute = store.getHead();
            if (!storedAttribute.getNamespace()
                    .equals(attribute.getNamespace())) {
                newStore = newStore.append(storedAttribute);
            } else {
                newStore = newStore.append(attribute);
            }
            store = store.getTail();
        }

        return newStore;
    }

    public ATerm getAttribute(ATerm t0, ATerm t1, ATerm t2) {
        return null;
    }

    public void deleteAttribute(ATerm t0, ATerm t1, ATerm t2) {
        // TODO Auto-generated method stub

    }

    public void deleteDependencies(ATerm t0) {
        // TODO Auto-generated method stub

    }

    public void addDependency(ATerm t0, ATerm t1) {
        // TODO Auto-generated method stub

    }

    public void deleteDependency(ATerm t0, ATerm t1) {
        // TODO Auto-generated method stub

    }

    public ATerm getDependingModules(ATerm t0) {
        // TODO Auto-generated method stub
        return null;
    }

    public ATerm getDependentModules(ATerm t0) {
        // TODO Auto-generated method stub
        return null;
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
    }
}
