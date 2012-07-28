package nl.cwi.sen.util;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.tree.TreeSelectionModel;

public class TreePanel extends JPanel {
	private Tree tree;
	private TreeNode root;

	public TreePanel() {
		root = new TreeNode();
		
		tree = new Tree(root);
		tree.setRootVisible(false);
		tree.setShowsRootHandles(true);
		tree.setExpandsSelectedPaths(true);
		tree.getSelectionModel().setSelectionMode(
				TreeSelectionModel.SINGLE_TREE_SELECTION);
		tree.setCellRenderer(new TreeCellRenderer());

		JScrollPane treeView = new JScrollPane(tree);

		this.add(treeView);
	}
}
