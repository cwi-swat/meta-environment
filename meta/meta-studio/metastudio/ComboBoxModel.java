package metastudio;

import java.util.List;

import javax.swing.AbstractListModel;

public class ComboBoxModel extends AbstractListModel implements javax.swing.ComboBoxModel {
    private Object selected;
    private List list;

    public ComboBoxModel(List list) {
        this.list = list;
    }

    public void setSelectedItem(Object anItem) {
        selected = anItem;
    }

    public Object getSelectedItem() {
        return selected;
    }

    public int getSize() {
        return list.size();
    }

    public Object getElementAt(int index) {
        return list.get(index);
    }
}
