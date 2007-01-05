package nl.cwi.sen1.gui.plugin.data;

import java.util.Iterator;
import java.util.Vector;

import javax.swing.table.DefaultTableModel;

import nl.cwi.sen1.gui.plugin.ProgressCell;

import aterm.ATerm;

public class ProgressTableModel extends DefaultTableModel {
	public void removeStatus(ATerm id) {
		for (Iterator iter = dataVector.iterator(); iter.hasNext();) {
			Vector row = (Vector) iter.next();
			ProgressCell cell = (ProgressCell) row.elementAt(0);
			if (cell.getId().isEqual(id)) {
				iter.remove();
			}
		}
	}

	public void setStatus(ATerm id, String columnName, String status) {
		Vector found = null;

		for (Iterator iter = dataVector.iterator(); iter.hasNext();) {
			Vector row = (Vector) iter.next();
			ProgressCell cell = (ProgressCell) row.elementAt(0);
			if (cell.getId().isEqual(id)) {
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
			ProgressCell[] rowData = new ProgressCell[getColumnCount()];
			rowData[0] = new ProgressCell(id, id.toString());
			rowData[column] = new ProgressCell(status);
			addRow(rowData);
		}
		fireTableDataChanged();
	}

	public void setMessage(ATerm id, String message) {
		Vector found = null;
		
		for (Iterator iter = dataVector.iterator(); iter.hasNext();) {
			Vector row = (Vector) iter.next();
			ProgressCell cell = (ProgressCell) row.elementAt(0);
			if (cell.getId().isEqual(id)) {
				found = row;
			}
		}
		
		if (found != null) {
			found.setElementAt(message, 0);
		} else {
			ProgressCell[] rowData = new ProgressCell[getColumnCount()];
			rowData[0] = new ProgressCell(id, message);
			addRow(rowData);
		}
		fireTableDataChanged();
	}

	public boolean isCellEditable(int row, int col) {
		return false;
	}
}
