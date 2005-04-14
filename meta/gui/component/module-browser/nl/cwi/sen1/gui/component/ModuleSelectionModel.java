package nl.cwi.sen1.gui.component;

import java.util.ArrayList;
import java.util.List;

import javax.swing.tree.DefaultTreeSelectionModel;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.data.ModuleTreeNode;

public class ModuleSelectionModel extends DefaultTreeSelectionModel {
	public void addSelectionPaths(TreePath[] p) {
		if (p == null)
			return;

		p = filtered(p);

		super.addSelectionPaths(p);
	}

	public void setSelectionPaths(TreePath[] p) {
		if (p == null || p.length == 0) {
			super.setSelectionPaths(p);
			return;
		}

		p = filtered(p);

		if (p.length > 0)
			super.setSelectionPaths(p);
	}

	private TreePath[] filtered(TreePath[] p) {
		List l = new ArrayList(p.length);

		for (int i = 0; i < p.length; i++)
			if (isSelectable(p[i]))
				l.add(p[i]);

		TreePath[] result = new TreePath[l.size()];

		l.toArray(result);

		return result;
	}

	private boolean isSelectable(TreePath p) {
		return ((ModuleTreeNode) p.getLastPathComponent()).isLeaf();
	}
}
