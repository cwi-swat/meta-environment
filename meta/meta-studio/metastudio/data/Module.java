package metastudio.data;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;


public class Module implements Comparable {
	public static final int STATE_NORMAL = 0;
	public static final int STATE_NEW = 1;

	private String _name;

	private List _parent;
	private List _child;

    private ListModel childListModel;
	private ListModel parentListModel;

	private int State = STATE_NORMAL;

	public Module(String name) {
		setName(name);
		initParentList();

		childListModel = new ListModel(_child);
		parentListModel = new ListModel(_parent);
		initChildList();
	}

	public int compareTo(Object o) {
		return _name.compareTo(o);
	}

	public String getName() {
		return _name;
	}
    
    public String getAbbreviation() {
        return _name.substring(_name.lastIndexOf('/'),-1);
    }

	private void setName(String name) {
		_name = name;
	}

	public void addParent(String parent) {
		_parent.add(parent);
		parentListModel.elementAdded();
	}

	private void initParentList() {
		_parent = new LinkedList();
	}

	public Iterator fetchParentIterator() {
		return _parent.iterator();
	}

	public ListModel fetchParentListModel() {
		return parentListModel;
	}

	public void addChild(String child) {
		_child.add(child);
		childListModel.elementAdded();
	}

	private void initChildList() {
		_child = new LinkedList();
		childListModel.setList(_child);
	}
    
    public List getChildren() {
        return _child;
    }

    public List getParents() {
        return _parent;
    }
    
	public Iterator fetchChildIterator() {
		return _child.iterator();
	}

	public ListModel fetchChildListModel() {
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
}
