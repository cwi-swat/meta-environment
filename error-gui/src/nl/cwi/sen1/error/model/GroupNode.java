package nl.cwi.sen1.error.model;

import javax.swing.tree.DefaultMutableTreeNode;


public class GroupNode extends DefaultMutableTreeNode {
	public final static int NO_GROUP = 0;
	public final static int FILE_GROUP = 1;
	public final static int DESCRIPTION_GROUP = 2;

	private String groupName;
	private int groupType;
	
	public GroupNode(String name, int type) {
		super(name);
		this.groupName = name;
		this.groupType = type;
	}
	
	public String getGroupName() {
		return groupName;
	}
	
	public int getGroupType() {
		return groupType;
	}
	
	public String toString() {
		return groupName + ": " + getChildCount();
	}
}
