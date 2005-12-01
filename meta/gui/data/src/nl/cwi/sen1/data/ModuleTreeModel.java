package nl.cwi.sen1.data;

import java.io.Serializable;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.StringTokenizer;

import javax.swing.event.TreeModelEvent;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;

import aterm.ATerm;

public class ModuleTreeModel extends AbstractModuleTreeModel implements
		TreeModel, Serializable {
	private ModuleTreeNode root;

	private List moduleSelectionListeners;

	private Map moduleTable;

	public ModuleTreeModel() {
		moduleTable = new HashMap();
		moduleSelectionListeners = new LinkedList();
		root = new ModuleTreeNode(null, "", "", false);
	}

	public Object getRoot() {
		return root;
	}

	public Object getChild(Object parent, int index) {
		return ((ModuleTreeNode) parent).getChild(index);
	}

	public int getChildCount(Object parent) {
		return ((ModuleTreeNode) parent).getChildCount();
	}

	public boolean isLeaf(Object node) {
		return ((ModuleTreeNode) node).isLeaf();
	}

	public void valueForPathChanged(TreePath path, Object newValue) {
	}

	public int getIndexOfChild(Object par, Object ch) {
		ModuleTreeNode parent = (ModuleTreeNode) par;
		ModuleTreeNode child = (ModuleTreeNode) ch;

		if (parent == null)
			return -1;

		return parent.getIndexOfChild(child);
	}

	public void addModuleSelectionListener(ModuleSelectionListener listener) {
		moduleSelectionListeners.add(listener);
	}

	public void selectModule(ATerm moduleId) {
		selectModule(getModule(moduleId));
	}

	public void selectModule(Module module) {
		Iterator iter = moduleSelectionListeners.iterator();
		while (iter.hasNext()) {
			ModuleSelectionListener l = (ModuleSelectionListener) iter.next();
			l.moduleSelected(module);
		}
	}

	public Module getModule(ATerm moduleId) {
		return (Module) moduleTable.get(moduleId);
	}

	public void addModule(Module module) {
		ATerm moduleId = module.getId();
        String name = module.getName();

		if (moduleTable.put(moduleId, module) == null) {
            root.addChild(moduleId, "", new StringTokenizer(name, "/"));
			repaintTree();
		}
	}

	public void removeModule(ATerm id, String name) {
		moduleTable.remove(id);
		root.removeChild(new StringTokenizer(name, "/"));
		repaintTree();
	}

	public void clearModules() {
		moduleTable.clear();
		root.clearChildren();
		repaintTree();
	}

	public TreePath makeTreePath(String name) {
		List l = root.makePath(new StringTokenizer(name, "/"), new ArrayList());

		return new TreePath(l.toArray());
	}

	public void repaintTree() {
		Object path[] = new Object[1];
		path[0] = root;
		fireTreeStructureChanged(new TreeModelEvent(root, path));
	}

	public List getModules() {
		return new LinkedList(moduleTable.values());
	}
}
