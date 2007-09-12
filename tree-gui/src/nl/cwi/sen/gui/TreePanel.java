package nl.cwi.sen.gui;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.tree.TreeSelectionModel;

public class TreePanel extends JPanel {
	private Tree tree;

	public TreePanel() {
		tree = new Tree();
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
