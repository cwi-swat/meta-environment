package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.event.MouseListener;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.gui.plugin.data.Module;
import nl.cwi.sen1.gui.plugin.data.ModuleSelectionListener;
import nl.cwi.sen1.gui.plugin.data.ModuleSelectionModel;
import nl.cwi.sen1.gui.plugin.data.ModuleTreeModel;
import nl.cwi.sen1.gui.plugin.data.ModuleTreeNode;
import aterm.ATerm;

public class ModuleTree extends JPanel {
	private JTree tree;

	private final ModuleTreeModel manager;

	public ModuleTree(Navigator modulebrowser, final ModuleTreeModel manager) {
		this.manager = manager;

		setLayout(new BorderLayout());

		tree = new JTree(manager);
		tree.setRootVisible(false);
		tree.setShowsRootHandles(true);
		tree.setExpandsSelectedPaths(true);
		tree.setSelectionModel(new ModuleSelectionModel());
		tree.addTreeSelectionListener(new TreeSelectionListener() {
			public void valueChanged(TreeSelectionEvent e) {
				manager.selectModule(getCurrentModule());
			}
		});

		add(new JScrollPane(tree));

		manager.addModuleSelectionListener(new ModuleSelectionListener() {
			public void moduleSelected(Module module) {
				if (module != null) {
					TreePath path = manager.makeTreePath(module.getName());
					tree.setSelectionPath(path);
					tree.scrollPathToVisible(path);
				} else {
					tree.clearSelection();
				}
			}
		});
	}

	public ATerm selectModule(int X, int Y) {
		TreePath path = tree.getClosestPathForLocation(X, Y);
		if (path != null) {
			tree.setSelectionPath(path);
			ModuleTreeNode selectedModule = (ModuleTreeNode) path
					.getLastPathComponent();
			return selectedModule.getId();
		}
		return null;
	}

	private Module getCurrentModule() {
		TreePath path = tree.getSelectionPath();

		if (path != null) {
			ModuleTreeNode selectedModule = (ModuleTreeNode) path
					.getLastPathComponent();
			return manager.getModule(selectedModule.getId());
		}

		return null;
	}

	public void addMouseListener(MouseListener l) {
		tree.addMouseListener(l);
	}
}
