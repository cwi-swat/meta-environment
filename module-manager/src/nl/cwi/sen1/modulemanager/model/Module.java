package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.HashSet;
import java.util.Map;
import java.util.Set;

import aterm.ATerm;

public class Module {
    private ATerm name;

    private Map attributes;

    private Set dependencies;

    public Module(ATerm name) {
        this.name = name;

        attributes = new HashMap();
        dependencies = new HashSet();
    }

    public ATerm getName() {
        return name;
    }

    public void addAttribute(ATerm namespace, ATerm key, ATerm value) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            table.addEntry(key, value);
        }
    }

    public void replaceAttribute(ATerm namespace, ATerm key, ATerm value) {
        AttributeTable table = getTable(namespace);

        if (table != null) {
            table.replaceEntry(key, value);
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

    public void addDependency(ATerm dependency) {
        if (!dependencies.contains(dependency)) {
            dependencies.add(dependency);
        }
    }

    public Set getDependencies() {
        return dependencies;
    }

    public void deleteDependency(ATerm dependency) {
        dependencies.remove(dependency);
    }
    
    public void deleteDependencies() {
        dependencies.clear();
    }
}
