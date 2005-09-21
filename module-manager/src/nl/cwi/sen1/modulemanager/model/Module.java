package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Map;



import aterm.ATerm;

public class Module {
    private Map attributes;

    public Module() {
        attributes = new HashMap();
    }
    
    public void setAttribute(ATerm namespace, ATerm key, ATerm value) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            table.setEntry(key, value);
        } else {
            table = new AttributeTable();
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

    public void deleteAttribute(ATerm namespace, ATerm key) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            table.deleteEntry(key);
        }
    }

    private AttributeTable getTable(ATerm namespace) {
        AttributeTable table = (AttributeTable) attributes.get(namespace);
        return table;
    }
}
