package nl.cwi.sen1.modulemanager.model;

import java.util.HashMap;
import java.util.Iterator;
import java.util.Map;

import nl.cwi.sen1.moduleapi.Factory;
import nl.cwi.sen1.moduleapi.types.TableEntry;
import nl.cwi.sen1.moduleapi.types.TableEntryTable;
import aterm.ATerm;

public class AttributeTable {
    private Map<ATerm, ATerm> entries;

    private Factory factory;

    public AttributeTable(Factory factory) {
        this.factory = factory;
        entries = new HashMap<ATerm, ATerm>();
    }

    public void setEntry(ATerm key, ATerm value) {
        entries.put(key, value);
    }

    public ATerm getValue(ATerm key) {
        return entries.get(key);
    }

    public Map getEntries() {
        return entries;
    }

    public void deleteEntry(ATerm key) {
        entries.remove(key);
    }

    public TableEntryTable getTableEntryTable() {
        TableEntryTable table = factory.makeTableEntryTable();

        for (Iterator iter = entries.keySet().iterator(); iter.hasNext();) {
            ATerm key = (ATerm) iter.next();
            ATerm value = getValue(key);

            TableEntry entry = factory.makeTableEntry_TableEntry(key, value);
            table = table.append(entry);
        }

        return table;
    }
}
