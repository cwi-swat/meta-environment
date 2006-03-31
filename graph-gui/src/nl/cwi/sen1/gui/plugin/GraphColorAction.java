package nl.cwi.sen1.gui.plugin;

import java.util.logging.Logger;

import prefuse.action.assignment.ColorAction;
import prefuse.visual.VisualItem;

public class GraphColorAction extends ColorAction {
    private String m_dataField;

    public GraphColorAction(String group, String dataField, String colorField) {
        super(group, colorField);
        setDataField(dataField);
    }

    public void setDataField(String field) {
        m_dataField = field;
    }

    public int getColor(VisualItem item) {
        Object o = lookup(item);
        if (o != null) {
            if (o instanceof ColorAction) {
                return ((ColorAction) o).getColor(item);
            } else if (o instanceof Integer) {
                return ((Integer) o).intValue();
            } else {
                Logger.getLogger(this.getClass().getName()).warning(
                        "Unrecognized Object from predicate chain.");
            }
        }
        // Only change default color value opposed to super.getColor(item)
        if (item.canGetInt(m_dataField)) {
            return item.getInt(m_dataField);
        }
        return m_defaultColor;
    }
}