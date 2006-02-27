package nl.cwi.sen1.gui.plugin.data;

import java.util.ArrayList;
import java.util.List;
import java.util.StringTokenizer;

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

    public ModuleTreeNode(ATerm id, String name, String prefix, boolean leaf) {
        this.id = id;
        this.name = name;
        this.prefix = prefix;
        this.leaf = leaf;
        children = new ArrayList<ModuleTreeNode>();
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
            childNode = new ModuleTreeNode(id, childName, p, false);
            children.add(getInsertIndex(childName), childNode);
        }
        path = path.getIoapiFactory().makePath_Relative(segments.getTail());
        file = file.getIoapiFactory().makeFile_File(path, file.getName(),
                file.getExtension());

        return childNode.addChild(id, p + childName + "/", file);
    }

    public void removeChild(StringTokenizer tokens) {
        String childName = tokens.nextToken();
        int childIndex = getChild(childName);
        ModuleTreeNode childNode = getChild(childIndex);

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

    public List<ModuleTreeNode> makePath(StringTokenizer tokens, List<ModuleTreeNode> result) {
        result.add(this);

        if (isLeaf()) {
            return result;
        }

        String childName = tokens.nextToken();
        ModuleTreeNode childNode;
        if (tokens.hasMoreTokens()) {
            childNode = getChild(getNodeChild(childName));
        } else {
            childNode = getChild(getLeafChild(childName));
        }
        if (childNode != null) {
            if (tokens.hasMoreTokens()) {
                return childNode.makePath(tokens, result);
            }
            result.add(childNode);
        }

        return result;
    }

    public String toString() {
        return name;
    }
}
