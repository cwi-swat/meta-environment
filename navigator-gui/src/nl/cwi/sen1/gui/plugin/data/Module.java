package nl.cwi.sen1.gui.plugin.data;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;

import nl.cwi.sen1.ioapi.types.File;
import aterm.ATerm;

public class Module implements Comparable<Module> {
    public static final int STATE_NORMAL = 0;

    public static final int STATE_NEW = 1;

    private ATerm _id;

    private String _name;

    private File _file;

    private List<String> _parent;

    private List<String> _child;

    private ListModel<String> childListModel;

    private ListModel<String> parentListModel;

    private int State = STATE_NORMAL;

    public Module(ATerm id, File file, String name) {
        setId(id);
        setName(name);
        setFile(file);
        initParentList();

        childListModel = new ListModel<String>(_child);
        parentListModel = new ListModel<String>(_parent);
        initChildList();
    }

    public int compareTo(Module module) {
        return _name.compareTo(module.getName());
    }

    public ATerm getId() {
        return _id;
    }

    public String getName() {
        return _name;
    }

    public String getAbbreviation() {
        return _name.substring(_name.lastIndexOf('/'), -1);
    }

    private void setId(ATerm id) {
        _id = id;
    }

    private void setName(String name) {
        _name = name;
    }

    private void setFile(File file) {
        _file = file;
    }

    public void addParent(String parent) {
        _parent.add(parent);
        parentListModel.elementAdded();
    }

    private void initParentList() {
        _parent = new LinkedList<String>();
    }

    public Iterator<String> fetchParentIterator() {
        return _parent.iterator();
    }

    public ListModel<String> fetchParentListModel() {
        return parentListModel;
    }

    public void addChild(String child) {
        _child.add(child);
        childListModel.elementAdded();
    }

    private void initChildList() {
        _child = new LinkedList<String>();
        childListModel.setList(_child);
    }

    public List<String> getChildren() {
        return _child;
    }

    public List<String> getParents() {
        return _parent;
    }

    public Iterator<String> fetchChildIterator() {
        return _child.iterator();
    }

    public ListModel<String> fetchChildListModel() {
        return childListModel;
    }

    public Object[] fetchChildrenArray() {
        return _child.toArray();
    }

    public String toString() {
        return _name;
    }

    public int getState() {
        return State;
    }

    public void setState(int State) {
        this.State = State;
    }

    public File getFile() {
        return _file;
    }
}
