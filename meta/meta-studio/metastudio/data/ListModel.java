package metastudio.data;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import javax.swing.AbstractListModel;

public class ListModel extends AbstractListModel {
	private List list;

	public ListModel(List list) {
		this.list = list;
	}

	public void setList(List list) {
		this.list = list;
	}

	public Object getElementAt(int index) {
        if (index >= 0 && index < list.size()) {
		  return list.get(index);
        }
        else {
            return null;
        }
	}

	public int getSize() {
		return list.size();
	}
    
	public void elementAdded() {
		fireIntervalAdded(list, list.size() - 1, list.size());
	}
    
    public void add(Object o) {
        list.add(list.size(), o);
        elementAdded();
    }
    
    public void addAll(Collection c) {
        Iterator iter = c.iterator();
        
        while (iter.hasNext()) {
            Object elem = iter.next();
            list.add(list.size(), elem);
        }
        
        fireIntervalAdded(list, list.size() - c.size(), list.size());
    }
}
