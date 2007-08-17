package nl.cwi.sen1.gui.plugin.data;

import java.util.ArrayList;
import java.util.List;

import nl.cwi.sen1.ioapi.types.File;
import nl.cwi.sen1.ioapi.types.Path;
import nl.cwi.sen1.ioapi.types.Segment;
import nl.cwi.sen1.ioapi.types.SegmentList;
import aterm.ATerm;

public class ModuleTreeNode {
	ATerm id;

	String name;

	String prefix;

	ArrayList<ModuleTreeNode> children;

	boolean leaf;

	boolean error;

	public ModuleTreeNode(ATerm id, String name, String prefix, boolean leaf) {
		this.id = id;
		this.name = name;
		this.prefix = prefix;
		this.leaf = leaf;
		children = new ArrayList<ModuleTreeNode>();
	}

	public boolean hasError() {
		if (leaf == true) {
			return error;
		}
		
		for (int i = 0; i < children.size(); i++) {
			if (children.get(i).hasError() == true) {
				return true;
			}
		}
		
		return false;
	}

	public ATerm getId() {
		return id;
	}

	public String getName() {
		return name;
	}

	public String getFullName() {
		return prefix + getName();
	}

	public ModuleTreeNode addChild(ATerm id, String p, File file) {
		Path path = file.getPath();

		SegmentList segments = path.getList();
		ModuleTreeNode childNode = null;

		if (segments.isEmpty()) {
			childNode = new ModuleTreeNode(id, file.getName(), p, true);
			children.add(getInsertIndex(file.getName()), childNode);

			return childNode;
		}

		Segment segment = segments.getHead();
		String childName = segment.getName();
		int childIndex = getNodeChild(childName);

		if (childIndex != -1) {
			childNode = getChild(childIndex);
		}
		if (childNode == null) {
			childNode = new ModuleTreeNode(null, childName, p, false);
			children.add(getInsertIndex(childName), childNode);
		}
		path = path.getIoapiFactory().makePath_Relative(segments.getTail());
		file = file.getIoapiFactory().makeFile_File(path, file.getName(),
				file.getExtension());

		return childNode.addChild(id, p + childName + "/", file);
	}

	public void removeChild(File file) {
		SegmentList segments = file.getPath().getList();
		segments = segments.append(file.getIoapiFactory().makeSegment_Segment(
				file.getName()));
		removeChild(segments);
	}

	public void removeChild(SegmentList segments) {
		if (!segments.isEmpty()) {
			String childName = segments.getHead().getName();
			int childIndex = getChild(childName);
			ModuleTreeNode childNode = getChild(childIndex);

			if (childNode != null) {
				if (!segments.isEmpty()) {
					childNode.removeChild(segments.getTail());
				}
				if (childNode.getChildCount() == 0) {
					children.remove(childIndex);
				}
			}
		}
	}

	public void clearChildren() {
		children.clear();
	}

	public ModuleTreeNode getChild(int index) {
		if ((index < 0) || (index >= children.size())) {
			return null;
		}

		return children.get(index);
	}

	public int getChild(String n) {
		for (int i = 0; i < children.size(); i++) {
			ModuleTreeNode curNode = children.get(i);

			if (curNode.getName().equals(n)) {
				return i;
			}
		}

		return -1;
	}

	public int getLeafChild(String n) {
		for (int i = 0; i < children.size(); i++) {
			ModuleTreeNode curNode = children.get(i);

			if (curNode.getName().equals(n) && curNode.isLeaf()) {
				return i;
			}
		}

		return -1;
	}

	public int getNodeChild(String n) {
		for (int i = 0; i < children.size(); i++) {
			ModuleTreeNode curNode = children.get(i);

			if (curNode.getName().equals(n) && !curNode.isLeaf()) {
				return i;
			}
		}

		return -1;
	}

	public int getInsertIndex(String n) {
		for (int i = 0; i < children.size(); i++) {
			ModuleTreeNode curNode = children.get(i);

			if (curNode.getName().compareTo(n) > 0) {
				return i;
			}
		}

		return children.size();
	}

	public int getChildCount() {
		return children.size();
	}

	public boolean isLeaf() {
		return leaf;
	}

	public int getIndexOfChild(ModuleTreeNode child) {
		if (child == null)
			return -1;

		for (int i = 0; i < children.size(); i++) {
			if (children.get(i) == child) {
				return i;
			}
		}
		return -1;
	}

	public List<ModuleTreeNode> makePath(File file) {
		SegmentList segments = file.getPath().getList();
		segments = segments.append(file.getIoapiFactory().makeSegment_Segment(
				file.getName()));
		return makePath(segments, new ArrayList<ModuleTreeNode>());
	}

	public List<ModuleTreeNode> makePath(SegmentList segments,
			List<ModuleTreeNode> result) {
		result.add(this);

		if (isLeaf()) {
			return result;
		}

		if (!segments.isEmpty()) {
			String childName = segments.getHead().getName();
			segments = segments.getTail();

			ModuleTreeNode childNode;
			int childIndex;
			if (!segments.isEmpty()) {
				childIndex = getNodeChild(childName);
			} else {
				childIndex = getLeafChild(childName);
			}
			childNode = getChild(childIndex);

			if (childNode != null) {
				if (!segments.isEmpty()) {
					return childNode.makePath(segments, result);
				}
				result.add(childNode);
			}
		}

		return result;
	}

	public String toString() {
		return name;
	}

	public void setErrorState(File file, boolean b) {
		SegmentList segments = file.getPath().getList();
		segments = segments.append(file.getIoapiFactory().makeSegment_Segment(
				file.getName()));
		setErrorState(segments, b);
	}

	private void setErrorState(SegmentList segments, boolean b) {
		if (!segments.isEmpty()) {
			String childName = segments.getHead().getName();
			int childIndex = getChild(childName);
			ModuleTreeNode childNode = getChild(childIndex);

			if (childNode != null) {
				if (!segments.isEmpty()) {
					childNode.setErrorState(segments.getTail(), b);
				}
			}
		}
		else {
			error = b;
		}
	}
}
