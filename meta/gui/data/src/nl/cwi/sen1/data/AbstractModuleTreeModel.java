package nl.cwi.sen1.data;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import javax.swing.event.TreeModelEvent;
import javax.swing.event.TreeModelListener;

public abstract class AbstractModuleTreeModel {
	private Set listeners = new HashSet();

	public void addTreeModelListener(TreeModelListener listener) {
		listeners.add(listener);
	}

	public void removeTreeModelListener(TreeModelListener listener) {
		listeners.remove(listener);
	}

	protected void fireTreeNodesChanged(TreeModelEvent e) {
		Iterator iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = (TreeModelListener) iter.next();
			listener.treeNodesChanged(e);
		}
	}

	protected void fireTreeNodesInserted(TreeModelEvent e) {
		Iterator iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = (TreeModelListener) iter.next();
			listener.treeNodesInserted(e);
		}
	}

	protected void fireTreeNodesRemoved(TreeModelEvent e) {
		Iterator iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = (TreeModelListener) iter.next();
			listener.treeNodesRemoved(e);
		}
	}

	protected void fireTreeStructureChanged(TreeModelEvent e) {
		Iterator iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = (TreeModelListener) iter.next();
			listener.treeStructureChanged(e);
		}
	}
}
