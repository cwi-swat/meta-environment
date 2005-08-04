package nl.cwi.sen1.error.model;

import javax.swing.tree.DefaultMutableTreeNode;

import nl.cwi.sen1.error.viewer.ErrorViewerBridge;
import nl.cwi.sen1.gui.Studio;

public abstract class SelectableNode extends DefaultMutableTreeNode {
	public SelectableNode(Object userObject) {
		super(userObject);
	}
	
	abstract public void selected(Studio studio, ErrorViewerBridge bridge);
}
