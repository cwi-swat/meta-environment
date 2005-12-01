package nl.cwi.sen1.gui.plugin.data;

import java.util.Iterator;
import java.util.LinkedList;

import javax.swing.table.AbstractTableModel;

public class ProgressTableModel extends AbstractTableModel {
    private String[] columnNames;
    private LinkedList data;
    
    
    public ProgressTableModel(String[] columnNames) {
        this.columnNames = columnNames;
        data = new LinkedList();
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
        String[] row = (String[]) data.get(rowIndex);
        return row[columnIndex];
    }
    
    public void setStatus(String modulename, String status) {
        String[] found = null;
        
        for (Iterator iter = data.iterator(); iter.hasNext();) {
            String[] row = (String[]) iter.next();
            if (row[0].equals(modulename)) {
                found = row;
            }
        }
        
        if (found != null) {
            found[1] = status;
        } else {
            found = new String[2];
            found[0] = modulename;
            found[1] = status;
            data.add(found);
        }
        fireTableDataChanged();
    }
}
