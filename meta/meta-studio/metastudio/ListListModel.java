package metastudio;

import javax.swing.AbstractListModel;
import java.util.List;

public class ListListModel extends AbstractListModel {
	private List list;

	public ListListModel(List list) {
		this.list = list;
	}

	public void setList(List list) {
		this.list = list;
	}

	public Object getElementAt(int index) {
		return list.get(index);
	}

	public int getSize() {
		return list.size();
	}

	public void elementAdded() {
		fireIntervalAdded(list, list.size() - 1, list.size());
	}
}
