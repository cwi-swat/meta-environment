package nl.cwi.sen1.error.model;

import javax.swing.tree.DefaultMutableTreeNode;

import errorapi.types.Summary;

public class ErrorNode extends DefaultMutableTreeNode {
	private Summary summary;
	
	public ErrorNode(Object userObject, Summary summary) {
		super(userObject);
		this.summary = summary;
	}
	
	public ErrorNode(Object userObject, boolean allowsChildren, Summary summary) {
		super(userObject, allowsChildren);
		this.summary = summary;
	}
}
