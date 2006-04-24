package nl.cwi.sen1.gui.plugin.data;

import java.util.Iterator;
import java.util.Vector;

import javax.swing.table.DefaultTableModel;

public class ProgressTableModel extends DefaultTableModel {
    public void removeStatus(String message) {
        for (Iterator iter = dataVector.iterator(); iter.hasNext();) {
            Vector row = (Vector) iter.next(); 
            if (row.elementAt(0).equals(message)) {
                iter.remove();
            }
        }
    }

    public void setStatus(String message, String columnName, String status) {
        Vector found = null;
        for (Iterator iter = dataVector.iterator(); iter.hasNext();) {
            Vector row = (Vector) iter.next(); 
            if (row.elementAt(0).equals(message)) {
                found = row;
            }
        }
        
        int column = findColumn(columnName);
        if (column == -1) {
            addColumn(columnName);
            column = findColumn(columnName);
        }
        
        if (found != null) {
            found.setElementAt(status, column);
        } else {
            String[] rowData = new String[getColumnCount()];
            rowData[0] = message;
            rowData[column] = status;
            addRow(rowData);
        }
        fireTableDataChanged();
    }

    public boolean isCellEditable(int row, int col) {
      return false;
    }
}
