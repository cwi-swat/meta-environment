package metastudio;

import javax.swing.*;
import javax.swing.tree.*;
import javax.swing.event.*;
import java.io.*;
import java.util.*;

public class TreeNode 
{
    String name;
    String prefix;
    ArrayList children;
    boolean leaf;

    public TreeNode(String name, String prefix, boolean leaf) 
    {
	this.name = name;
	this.prefix = prefix;
	this.leaf = leaf;
	children = new ArrayList();
    }

    public String getName() { return name; }

    public String getFullName() { return prefix+getName(); }

    public TreeNode addChild(String p, String n)
    {
	StringTokenizer tokens = new StringTokenizer(n, "/");
	if (tokens.hasMoreTokens()) {
	    String childName = tokens.nextToken();
	    TreeNode childNode = null;
	    int i = 0;

	    for (; i < children.size(); i++) {
		TreeNode curNode = (TreeNode)getChild(i);
		
		if (curNode.getName().equals(childName)) {
		    childNode = curNode;
		}
		if (curNode.getName().compareTo(childName) > 0) {
		    break;
		}
	    }

	    if (tokens.hasMoreTokens()) {
		if (childNode == null) {
		    childNode = new TreeNode(childName, p, 
					     !tokens.hasMoreTokens());
		    children.add(i, childNode);
		}
		return childNode.addChild(p+childName+"/", 
					  n.substring(childName.length()+1));
	    }
	    else {
		if (childNode == null) {
		    childNode = new TreeNode(childName, p, 
					     !tokens.hasMoreTokens());
		    children.add(i, childNode);
		    
		    return childNode;
		}
		return null;
	    }
	}
	return null;
    }

    public void removeChild(String n) 
    {
	StringTokenizer tokens = new StringTokenizer(n, "/");
	if (tokens.hasMoreTokens()) {
	    String childName = tokens.nextToken();
	    int childIndex = getChild(childName);
	    TreeNode childNode = getChild(childIndex);
	    
	    if (childNode != null) {
		if (tokens.hasMoreTokens()) {
		    childNode.removeChild(n.substring(childName.length()+1));
		}
		if (childNode.getChildCount() == 0) {
		    children.remove(childIndex);
		}
	    }
	}
    }

    public void clearChildren() { children.clear(); }
	
    public TreeNode getChild(int index) 
    {
	if ( (index < 0) || (index >= children.size())) {
	    return null;
	}

	return (TreeNode)children.get(index);
    }

    public int getChild(String n) 
    {
	for (int i = 0; i < children.size(); i++) {
	    TreeNode curNode = (TreeNode)children.get(i);
		
	    if (curNode.getName().equals(n)) {
		return i;
	    }
	}

	return -1;
    }

    public int getChildCount() { return children.size(); }

    public boolean isLeaf() { return leaf; }

    public int getIndexOfChild(TreeNode child) {
	if (child == null) 
	    return -1;

	for (int i = 0; i < children.size(); i++) {
	    if (children.get(i) == child) {
		return i;
	    }
	}
	return -1;
    }

    public List makePath(String n, List result) {
	result.add(this);
	if (isLeaf()) {
	    return result;
	}

	StringTokenizer tokens = new StringTokenizer(n, "/");

	if (tokens.hasMoreTokens()) {
	    String childName = tokens.nextToken();
	    int childIndex = getChild(childName);
	    TreeNode childNode = getChild(childIndex);
		
	    if (childNode != null) {
		if (tokens.hasMoreTokens()) {
		    return childNode.makePath(n.substring(childName.length()+1), result);
		}
		else {
		    result.add(childNode);
		}
	    }
	}
	return result;
    }

    public String toString() {
	return name;
    }
}
