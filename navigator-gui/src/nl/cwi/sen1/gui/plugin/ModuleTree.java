package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;
import java.awt.Component;
import java.awt.event.MouseListener;
import java.util.Enumeration;

import javax.swing.Icon;
import javax.swing.ImageIcon;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultTreeCellRenderer;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.gui.plugin.data.Module;
import nl.cwi.sen1.gui.plugin.data.ModuleSelectionListener;
import nl.cwi.sen1.gui.plugin.data.ModuleSelectionModel;
import nl.cwi.sen1.gui.plugin.data.ModuleTreeModel;
import nl.cwi.sen1.gui.plugin.data.ModuleTreeNode;
import aterm.ATerm;

public class ModuleTree extends JPanel {
	private JTree tree;

	private Enumeration<TreePath> expansionState;

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

		ImageIcon errorIcon = new ImageIcon(getClass().getResource(
				"/resources/images/error.png"));
		tree.setCellRenderer(new TreeIconCellRenderer(errorIcon));

		add(new JScrollPane(tree));

		manager.addModuleSelectionListener(new ModuleSelectionListener() {
			public void moduleSelected(Module module) {
				if (module != null) {
					TreePath path = manager.makeTreePath(module.getFile());
					tree.setSelectionPath(path);
					tree.scrollPathToVisible(path);
				} else {
					tree.clearSelection();
				}
			}
		});
	}

	public void saveExpansionState() {
		expansionState = tree.getExpandedDescendants(new TreePath(tree
				.getModel().getRoot()));
	}

	public void loadExpansionState() {
		if (expansionState != null) {
			while (expansionState.hasMoreElements()) {
				TreePath treePath = expansionState.nextElement();
				tree.expandPath(treePath);
			}
		}
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
	
	/**
     * Internal class responsible for painting the icons on the nodes in the
     * Tree. For different types of nodes different icons will be used
     * 
     * @author Renze de Vries
     * @date 14-02-2007
     */
    class TreeIconCellRenderer extends DefaultTreeCellRenderer {
        private Icon errorIcon;

        public TreeIconCellRenderer(Icon errorIcon) {
            this.errorIcon = errorIcon;
        }

        public Component getTreeCellRendererComponent(JTree tree, Object value,
                boolean sel, boolean expanded, boolean leaf, int row,
                boolean hasFocus) {

            super.getTreeCellRendererComponent(tree, value, sel, expanded,
                    leaf, row, hasFocus);

            ModuleTreeNode treeNode = (ModuleTreeNode) value;
            if (treeNode.hasError() == true) {
            	setIcon(errorIcon);
            }

            return this;
        }
    }
}
