package nl.cwi.sen1.gui.plugin;

import java.util.Enumeration;
import java.util.Iterator;
import java.util.List;

import javax.swing.BoxLayout;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.DefaultMutableTreeNode;
import javax.swing.tree.DefaultTreeModel;
import javax.swing.tree.TreeNode;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.data.Module;
import nl.cwi.sen1.data.ModuleTreeModel;
import nl.cwi.sen1.util.Preferences;

public class ImportHierarchyPanel extends JPanel {
	private JTree tree;

	private DefaultMutableTreeNode root;

	private DefaultMutableTreeNode imports;

	private DefaultMutableTreeNode importedBy;

	public ImportHierarchyPanel(final ModuleTreeModel model, Preferences preferences) {
		setLayout(new BoxLayout(this, BoxLayout.Y_AXIS));
		setBackground(preferences.getColor("moduleinfo.background"));

		root = new DefaultMutableTreeNode();
		imports = new DefaultMutableTreeNode(preferences
				.getString("moduleinfo.imports"));
		importedBy = new DefaultMutableTreeNode(preferences
				.getString("moduleinfo.importedby"));

		tree = new JTree(root);
		tree.setRootVisible(false);
		tree.setBackground(preferences.getColor("moduleinfo.background"));

		add(new JScrollPane(tree));

		tree.addTreeSelectionListener(new TreeSelectionListener() {
			public void valueChanged(TreeSelectionEvent e) {
				TreePath path = tree.getSelectionPath();

				if (path != null) {
					DefaultMutableTreeNode node = (DefaultMutableTreeNode) path
							.getLastPathComponent();

					if (node.isLeaf()) {
                        System.err.println("ImportHierarchyPanel - addTreeSelectionListener: FIX ME");
//						model.selectModule(node);
					}
				}
			}
		});
	}

	public void setHierarchy(Module module) {
		root.removeAllChildren();

		if (module != null) {
			setLeafs(importedBy, module.getParents());
			makeVisible(importedBy);

			setLeafs(imports, module.getChildren());
			makeVisible(imports);
		}

		refresh();
	}

	private void makeVisible(DefaultMutableTreeNode node) {
		if (node.getChildCount() > 0) {
			root.insert(node, 0);
		}
	}

	private void setLeafs(DefaultMutableTreeNode node, List leafs) {
		node.removeAllChildren();

		Iterator iter = leafs.iterator();
		while (iter.hasNext()) {
			String child = (String) iter.next();
			DefaultMutableTreeNode childNode = new DefaultMutableTreeNode(child);

			node.insert(childNode, node.getChildCount());
		}
	}

	private void refresh() {
		((DefaultTreeModel) tree.getModel()).reload();
		expandAll(tree, true);
	}
	
	public void expandAll(JTree tree, boolean expand) {
		TreeNode root = (TreeNode) tree.getModel().getRoot();

		// Traverse tree from root
		expandAll(tree, new TreePath(root), expand);
	}

	private void expandAll(JTree tree, TreePath parent, boolean expand) {
		// Traverse children
		TreeNode node = (TreeNode) parent.getLastPathComponent();
		if (node.getChildCount() >= 0) {
			for (Enumeration e = node.children(); e.hasMoreElements();) {
				TreeNode n = (TreeNode) e.nextElement();
				TreePath path = parent.pathByAddingChild(n);
				expandAll(tree, path, expand);
			}
		}

		// Expansion or collapse must be done bottom-up
		if (expand) {
			tree.expandPath(parent);
		} else {
			tree.collapsePath(parent);
		}
	}


}
