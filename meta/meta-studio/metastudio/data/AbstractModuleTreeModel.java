package metastudio.data;

import java.util.Enumeration;
import java.util.Vector;

import javax.swing.event.TreeModelEvent;
import javax.swing.event.TreeModelListener;

public abstract class AbstractModuleTreeModel {
	private Vector vector = new Vector();

	public void addTreeModelListener(TreeModelListener listener) {
		if (listener != null && !vector.contains(listener)) {
			vector.addElement(listener);
		}
	}

	public void removeTreeModelListener(TreeModelListener listener) {
		if (listener != null) {
			vector.removeElement(listener);
		}
	}

	public void fireTreeNodesChanged(TreeModelEvent e) {
		Enumeration listeners = vector.elements();
		while (listeners.hasMoreElements()) {
			TreeModelListener listener = (TreeModelListener) listeners.nextElement();
			listener.treeNodesChanged(e);
		}
	}

	public void fireTreeNodesInserted(TreeModelEvent e) {
		Enumeration listeners = vector.elements();
		while (listeners.hasMoreElements()) {
			TreeModelListener listener = (TreeModelListener) listeners.nextElement();
			listener.treeNodesInserted(e);
		}
	}

	public void fireTreeNodesRemoved(TreeModelEvent e) {
		Enumeration listeners = vector.elements();
		while (listeners.hasMoreElements()) {
			TreeModelListener listener = (TreeModelListener) listeners.nextElement();
			listener.treeNodesRemoved(e);
		}
	}

	public void fireTreeStructureChanged(TreeModelEvent e) {
		Enumeration listeners = vector.elements();
		while (listeners.hasMoreElements()) {
			TreeModelListener listener = (TreeModelListener) listeners.nextElement();
			listener.treeStructureChanged(e);
		}
	}
}
