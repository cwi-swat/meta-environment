package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import aterm.ATerm;

public class Module {
    private ATerm name;

    private Map attributes;

    public Module(ATerm name) {
        this.name = name;

        attributes = new HashMap();
    }

    public ATerm getName() {
        return name;
    }
    
    public void setName(ATerm name) {
        this.name = name;
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
