package metastudio;

import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

public class TreeNode {
	String name;
	String prefix;
	ArrayList children;
	boolean leaf;

	public TreeNode(String name, String prefix, boolean leaf) {
		this.name = name;
		this.prefix = prefix;
		this.leaf = leaf;
		children = new ArrayList();
	}

	public String getName() {
		return name;
	}

	public String getFullName() {
		return prefix + getName();
	}

	public TreeNode addChild(String p, StringTokenizer tokens) {
		String childName = tokens.nextToken();
		TreeNode childNode = null;
		int i = 0;

		for (; i < children.size(); i++) {
			TreeNode curNode = (TreeNode) getChild(i);

			if (curNode.getName().equals(childName)) {
				childNode = curNode;
			}
			if (curNode.getName().compareTo(childName) > 0) {
				break;
			}
		}

		if (tokens.hasMoreTokens()) {
			if (childNode == null) {
				childNode = new TreeNode(childName, p, !tokens.hasMoreTokens());
				children.add(i, childNode);
			}
			return childNode.addChild(p + childName + "/", tokens);
		} else {
		    //			if (childNode == null) {
				childNode = new TreeNode(childName, p, !tokens.hasMoreTokens());
				children.add(i, childNode);

				return childNode;
				//			}
				//			return null;
		}
	}

	public void removeChild(StringTokenizer tokens) {
		String childName = tokens.nextToken();
		int childIndex = getChild(childName);
		TreeNode childNode = getChild(childIndex);

		if (childNode != null) {
			if (tokens.hasMoreTokens()) {
				childNode.removeChild(tokens);
			}
			if (childNode.getChildCount() == 0) {
				children.remove(childIndex);
			}
		}
	}

	public void clearChildren() {
		children.clear();
	}

	public TreeNode getChild(int index) {
		if ((index < 0) || (index >= children.size())) {
			return null;
		}

		return (TreeNode) children.get(index);
	}

	public int getChild(String n) {
		for (int i = 0; i < children.size(); i++) {
			TreeNode curNode = (TreeNode) children.get(i);

			if (curNode.getName().equals(n)) {
				return i;
			}
		}

		return -1;
	}

	public int getLeafChild(String n) {
		for (int i = 0; i < children.size(); i++) {
			TreeNode curNode = (TreeNode) children.get(i);

			if (curNode.getName().equals(n) && curNode.isLeaf()) {
				return i;
			}
		}

		return -1;
	}

	public int getChildCount() {
		return children.size();
	}

	public boolean isLeaf() {
		return leaf;
	}

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

	public List makePath(StringTokenizer tokens, List result) {
		result.add(this);

		if (isLeaf()) {
			return result;
		}

		String childName = tokens.nextToken();
		int childIndex = getChild(childName);
		TreeNode childNode = getChild(childIndex);

		if (childNode != null) {
			if (tokens.hasMoreTokens()) {
				return childNode.makePath(tokens, result);
			} else {
				result.add(getChild(getLeafChild(childName)));
			}
		}

		return result;
	}

	public String toString() {
		return name;
	}
}
