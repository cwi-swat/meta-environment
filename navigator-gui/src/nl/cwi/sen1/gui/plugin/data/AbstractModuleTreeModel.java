package nl.cwi.sen1.gui.plugin.data;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import javax.swing.event.TreeModelEvent;
import javax.swing.event.TreeModelListener;

public abstract class AbstractModuleTreeModel {
	private Set<TreeModelListener> listeners = new HashSet<TreeModelListener>();

	public void addTreeModelListener(TreeModelListener listener) {
		listeners.add(listener);
	}

	public void removeTreeModelListener(TreeModelListener listener) {
		listeners.remove(listener);
	}

	protected void fireTreeNodesChanged(TreeModelEvent e) {
		Iterator<TreeModelListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = iter.next();
			listener.treeNodesChanged(e);
		}
	}

	protected void fireTreeNodesInserted(TreeModelEvent e) {
		Iterator<TreeModelListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = iter.next();
			listener.treeNodesInserted(e);
		}
	}

	protected void fireTreeNodesRemoved(TreeModelEvent e) {
		Iterator<TreeModelListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = iter.next();
			listener.treeNodesRemoved(e);
		}
	}

	protected void fireTreeStructureChanged(TreeModelEvent e) {
		Iterator<TreeModelListener> iter = listeners.iterator();
		while (iter.hasNext()) {
			TreeModelListener listener = iter.next();
			listener.treeStructureChanged(e);
		}
	}
}
