package nl.cwi.sen1.gui.plugin.data;

import java.util.Collection;
import java.util.Iterator;
import java.util.List;

import javax.swing.AbstractListModel;

public class ListModel<E> extends AbstractListModel {
	private List<E> list;

	public ListModel(List<E> list) {
		this.list = list;
	}

    public void setList(List<E> list) {
		this.list = list;
	}

	 public Object getElementAt(int index) {
        if (index >= 0 && index < list.size()) {
		  return list.get(index);
        }
        return null;
	}

	 public int getSize() {
		return list.size();
	}
    
	public void elementAdded() {
		fireIntervalAdded(list, list.size() - 1, list.size());
	}
    
     public void add(E o) {
        list.add(list.size(), o);
        elementAdded();
    }
    
     public void remove(Object o) {
        list.remove(o);
    }
     
     public void removeAll(Collection<?> c) {
         list.removeAll(c);
     }
    
     public void addAll(Collection<? extends E> c) {
        Iterator<? extends E> iter = c.iterator();
        
        while (iter.hasNext()) {
            list.add(list.size(), iter.next());
        }
        
        fireIntervalAdded(list, list.size() - c.size(), list.size());
    }
    
     public String toString() {
        return list.toString();
    }
     
     public Iterator<E> iterator() {
         return list.iterator();
     }
     
     public boolean contains(Object o) {
         return list.contains(o);
     }
}
