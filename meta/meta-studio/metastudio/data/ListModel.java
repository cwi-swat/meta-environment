package metastudio.data;

import javax.swing.AbstractListModel;
import java.util.List;

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
}
