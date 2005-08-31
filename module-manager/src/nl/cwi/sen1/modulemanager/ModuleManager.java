package nl.cwi.sen1.modulemanager;

import java.io.IOException;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.Attribute;
import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.Dependency;
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

    public ATerm getAttribute(ATerm moduleId, ATerm namespace, ATerm key) {
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            return factory.getPureFactory().make("snd-value(no-such-module)");
        }

        AttributeStore store = module.getStore();
        TableEntryTable table = getAttributeTable(namespace, store);

        if (table == null) {
            return factory.getPureFactory()
                    .make("snd-value(no-such-namespace)");
        }

        TableEntry entry = getTableEntry(key, table);

        if (entry == null) {
            return factory.getPureFactory().make("snd-value(no-such-key)");
        }

        return factory.getPureFactory().make("snd-value(attribute(<term>))",
                entry.getValue());
    }

    public void deleteAttribute(ATerm moduleId, ATerm namespace, ATerm key) {
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - deleteAttribute: no such module ["
                    + moduleId + "]");
            return;
        }

        AttributeStore store = module.getStore();
        TableEntryTable table = getAttributeTable(namespace, store);

        if (table == null) {
            System.err.println("MM - deleteAttribute: no such namespace ["
                    + namespace + "]");
            return;
        }

        TableEntryTable newTable = removeKey(key, table);

        if (newTable.equals(table)) {
            System.err.println("MM - deleteAttribute: no such key [" + key
                    + "]");
        }

        Attribute attribute = getAttribute(namespace, store);
        attribute = attribute.setTable(table);

        store = replaceAttribute(attribute, store);

        module = module.setStore(store);

        modules.put(id, module);
    }

    private TableEntryTable removeKey(ATerm key, TableEntryTable table) {
        TableEntryTable newTable = factory.makeTableEntryTable();

        while (!table.isEmpty()) {
            TableEntry storedTableEntry = table.getHead();
            if (!storedTableEntry.getKey().equals(key)) {
                newTable = newTable.append(storedTableEntry);
            }
            table = table.getTail();
        }

        return newTable;
    }

    public void addDependency(ATerm moduleId, ATerm dependency) {
        Dependency dep = factory.DependencyFromTerm(dependency);
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - addDependency: no such module ["
                    + moduleId + "]");
            return;
        }

        DependencyList list = module.getList();

        while (!list.isEmpty()) {
            Dependency head = list.getHead();

            if (head.equals(dep)) {
                System.err.println("MM - addDependency: depedency [" + dep
                        + "]already exists");
                return;
            }
            list = list.getTail();
        }

        list = module.getList().append(dep);
        module = module.setList(list);

        modules.put(id, module);
    }

    public void deleteDependencies(ATerm moduleId) {
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - addDependency: no such module ["
                    + moduleId + "]");
            return;
        }

        module = module.setList(factory.makeDependencyList());
        modules.put(id, module);
    }

    public void deleteDependency(ATerm moduleId, ATerm dependency) {
        Dependency dep = factory.DependencyFromTerm(dependency);
        DependencyList newList = factory.makeDependencyList();
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            System.err.println("MM - deleteDependency: no such module ["
                    + moduleId + "]");
            return;
        }

        DependencyList list = module.getList();

        while (!list.isEmpty()) {
            Dependency head = list.getHead();

            if (!head.equals(dep)) {
                newList = newList.append(head);
            }
            list = list.getTail();
        }

        module = module.setList(newList);

        modules.put(id, module);
    }

    public ATerm getDependingModules(ATerm moduleId) {
        ModuleId id = factory.ModuleIdFromTerm(moduleId);
        Module module = (Module) modules.get(id);

        if (module == null) {
            return factory.getPureFactory().make("snd-value(no-such-module)");
        }

        return factory.getPureFactory().make(
                "snd-value(depending-module(<term>))", module.getList());
    }

    public ATerm getDependentModules(ATerm t0) {
    }

    public void recTerminate(ATerm t0) {
    }

    public static void main(String[] args) {
        new ModuleManager(args);
    }
}
