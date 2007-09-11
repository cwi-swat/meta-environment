package nl.cwi.sen1.gui.plugin.data;

import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import javax.swing.event.TreeModelEvent;
import javax.swing.tree.TreeModel;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.ioapi.types.File;
import aterm.ATerm;

public class ModuleTreeModel extends AbstractModuleTreeModel implements
		TreeModel {
	private ModuleTreeNode root;

	private List<ModuleSelectionListener> moduleSelectionListeners;

	private Map<ATerm, Module> moduleTable;

	public ModuleTreeModel() {
		moduleTable = new HashMap<ATerm, Module>();
		moduleSelectionListeners = new LinkedList<ModuleSelectionListener>();
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
		Iterator<ModuleSelectionListener> iter = moduleSelectionListeners
				.iterator();
		while (iter.hasNext()) {
			ModuleSelectionListener l = iter.next();
			l.moduleSelected(module);
		}
	}

	public Module getModule(ATerm moduleId) {
		return moduleTable.get(moduleId);
	}

	public void addModule(Module module) {
		ATerm moduleId = module.getId();
		File file = module.getFile();

		if (file != null && moduleTable.put(moduleId, module) == null) {
			root.addChild(moduleId, "", file);
			repaintTree();
		}
	}

	public void removeModule(ATerm id) {
		Module module = getModule(id);
		File file = module.getFile();

		moduleTable.remove(id);
		root.removeChild(file);
		repaintTree();
	}

	public void clearModules() {
		moduleTable.clear();
		root.clearChildren();
		repaintTree();
	}

	public TreePath makeTreePath(File file) {
		List<ModuleTreeNode> l = root.makePath(file);

		return new TreePath(l.toArray());
	}

	public void repaintTree() {
		Object path[] = new Object[1];
		path[0] = root;
		fireTreeStructureChanged(new TreeModelEvent(root, path));
	}

	public List<Module> getModules() {
		return new LinkedList<Module>(moduleTable.values());
	}

	public void markError(ATerm moduleId) {
		Module module = getModule(moduleId);
		File file = module.getFile();

		root.setErrorState(file, true);
		repaintTree();
	}

	public void markNormal(ATerm moduleId) {
		Module module = getModule(moduleId);
		File file = module.getFile();

		root.setErrorState(file, false);
		repaintTree();
	}
}
