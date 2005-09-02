package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Map;

import aterm.ATerm;

public class AttributeTable {
    private Map entries;
    
    public AttributeTable() {
        entries = new HashMap();
    }

    public void addEntry(ATerm key, ATerm value) {
        if (entries.get(key) == null) {
            entries.put(key, value);
        }
    }
    
    public void replaceEntry(ATerm key, ATerm value) {
        entries.put(key, value);
    }
    
    public ATerm getValue(ATerm key) {
        return (ATerm) entries.get(key);
    }
    
    public void deleteEntry(ATerm key) {
        entries.remove(key);
    }
}
