package nl.cwi.sen1.gui.plugin.data;

import java.util.Iterator;
import java.util.LinkedList;

import javax.swing.table.AbstractTableModel;

public class ModuledetailsTableModel extends AbstractTableModel {
    private String[] columnNames;
    private LinkedList<String[]> data;
    
    public ModuledetailsTableModel(String[] columnNames) {
        this.columnNames = columnNames;
        data = new LinkedList<String[]>();
    }
    
    public int getRowCount() {
        return data.size();
    }

    public int getColumnCount() {
        return columnNames.length;
    }

    public String getColumnName(int col) {
        return columnNames[col];
    }
    
    public Object getValueAt(int rowIndex, int columnIndex) {
        String[] row = data.get(rowIndex);
        return row[columnIndex];
    }
    
    public void setDetails(String namespace, String key, String value) {
        String[] found = null;
        
        for (Iterator iter = data.iterator(); iter.hasNext();) {
            String[] row = (String[]) iter.next();
            if (row[0].equals(namespace) && row[1].equals(key)) {
                found = row;
            }
        }
        
        if (found != null) {
            found[2] = value;
        } else {
            found = new String[3];
            found[0] = namespace;
            found[1] = key;
            found[2] = value;
            data.add(found);
        }
        fireTableDataChanged();
    }
}
