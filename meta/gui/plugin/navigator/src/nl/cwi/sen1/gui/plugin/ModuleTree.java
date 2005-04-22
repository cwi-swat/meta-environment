package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.data.Module;
import nl.cwi.sen1.data.ModuleSelectionListener;
import nl.cwi.sen1.data.ModuleTreeModel;
import nl.cwi.sen1.data.ModuleTreeNode;
import aterm.ATermFactory;

public class ModuleTree extends JPanel {
	private JTree tree;

	private final ModuleTreeModel manager;

	private Navigator navigator;

	public ModuleTree(ATermFactory factory, Navigator modulebrowser,
			final ModuleTreeModel manager) {
		this.navigator = modulebrowser;
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
		tree.addMouseListener(new MouseAdapter() {
			public void mousePressed(MouseEvent e) {
				if (e.isPopupTrigger()) {
					handlePopupRequest(e);
				}
			}

			public void mouseReleased(MouseEvent e) {
				mousePressed(e);
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

	private void handlePopupRequest(MouseEvent e) {
		TreePath path = tree.getClosestPathForLocation(e.getX(), e.getY());
		if (path != null) {
			tree.setSelectionPath(path);
		}

		Module current = getCurrentModule();
		if (current != null) {
			navigator.postPopupRequest(e, current);
		}
	}

	private Module getCurrentModule() {
		TreePath path = tree.getSelectionPath();

		if (path != null) {
			ModuleTreeNode selectedModule = (ModuleTreeNode) path
					.getLastPathComponent();
			return manager.getModule(selectedModule.getFullName());
		}

		return null;
	}
}
