package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.Attribute;
import nl.cwi.sen1.moduleapi.types.AttributeStore;
import nl.cwi.sen1.moduleapi.types.TableEntryTable;
import aterm.ATerm;

public class Module {
    private Map<ATerm, AttributeTable> attributes;

    private Factory factory;

    public Module(Factory factory) {
        this.factory = factory;
        attributes = new HashMap<ATerm, AttributeTable>();
    }

    public void setAttribute(ATerm namespace, ATerm key, ATerm value) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            table.setEntry(key, value);
        } else {
            table = new AttributeTable(factory);
            table.setEntry(key, value);
            attributes.put(namespace, table);
        }
    }

    public ATerm getAttribute(ATerm namespace, ATerm key) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            return table.getValue(key);
        }
        return null;
    }

    public AttributeTable getAttributes(ATerm namespace) {
        return getTable(namespace);
    }

    public AttributeStore getAttributes() {
        AttributeStore store = factory.makeAttributeStore();

        for (Iterator<ATerm> iter = attributes.keySet().iterator(); iter.hasNext();) {
            ATerm namespace = iter.next();
            TableEntryTable table = getTable(namespace).getTableEntryTable();

            Attribute attribute = factory.makeAttribute_Attribute(namespace,
                    table);
            store = store.append(attribute);
        }

        return store;
    }

    public void deleteAttribute(ATerm namespace, ATerm key) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            table.deleteEntry(key);
        }
    }

    private AttributeTable getTable(ATerm namespace) {
        AttributeTable table = attributes.get(namespace);
        return table;
    }
}
