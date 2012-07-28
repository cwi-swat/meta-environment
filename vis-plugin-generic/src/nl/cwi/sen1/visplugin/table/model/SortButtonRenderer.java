package nl.cwi.sen1.visplugin.table.model;

import java.awt.Component;

import java.util.Hashtable;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JTable;
import javax.swing.table.TableCellRenderer;
/**
 * Sort button renderer. Class responsible for the button in the header.
 * These buttons will show the order in which the current sort applies.
 * This will be either descending or ascending, the initial state is no sorting.
 *
 * @author Anton Gerdessen
 * @date 12-03-2007
 */
public class SortButtonRenderer extends JButton implements TableCellRenderer {

    private static final long serialVersionUID = 1L;

    // Define the button states.
    public static final int NONE = 0;
    public static final int ASC = 1;
    public static final int DEC = 2;

    private Hashtable<Integer, Integer> state;
    private JButton ascButton;
    private JButton decButton;

    /**
     * Constructor.
     *
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public SortButtonRenderer() {
        state = new Hashtable<Integer, Integer>();

        // Create the ascending button with icon.
        ascButton = new JButton();
        ascButton.setHorizontalTextPosition(LEFT);
        ImageIcon aicon = new ImageIcon(getClass().getResource(
                "/resources/images/sortAsc.gif"));
        ascButton.setIcon(aicon);

        // Create the descending button with icon.
        decButton = new JButton();
        decButton.setHorizontalTextPosition(LEFT);
        ImageIcon bicon = new ImageIcon(getClass().getResource(
                "/resources/images/sortDec.gif"));
        decButton.setIcon(bicon);

    }

    /**
     * Method inherited from the TableCellRenderer
     * Only the column and value attributes are used.
     *
     * @param table <not used>
     * @param value The header buttons text
     * @param isSelected <not used>
     * @param hasFocus <not used>
     * @param row <not used>
     * @param column The column for which to change the header.
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public Component getTableCellRendererComponent(JTable table, Object value,
            boolean isSelected, boolean hasFocus, int row, int column) {

        JButton button = this;

        // Determine the state for sorting.
        Object obj = state.get(new Integer(column));
        if (obj != null) {
            if (((Integer) obj).intValue() == ASC) {
                button = ascButton;
            } else {
                button = decButton;
            }
        }

        // Copy the text from the 'old' to on the 'new' button.
        button.setText((value == null) ? "" : value.toString());

        return button;
    }

    /**
     * Set the column on which the current sort is based.
     *
     * @param column The column for which sort will be based
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    @SuppressWarnings("unchecked")
    public void setSelectedColumn(int column) {

        if (column < 0)
            return;

        // Inial state will be ascending. if a sorting order is already
        // 'active', swap the sorting.
        Integer value = null;
        Object obj = state.get(new Integer(column));
        if (obj == null) {
            value = new Integer(ASC);
        } else {
            if (((Integer) obj).intValue() == ASC) {
                value = new Integer(DEC);
            } else {
                value = new Integer(ASC);
            }
        }

        // Clear the state and add the current column and its order to state.
        state.clear();
        state.put(new Integer(column), value);
    }

    /**
     * Retrieve the current state for a given column.
     *
     * @param col The column for which to retrieve the sort order.
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public int getState(int col) {
        // If no sort order is given return none, else return the sort order.
        int retValue;
        Object obj = state.get(new Integer(col));

        if (obj == null) {
            retValue = NONE;
        } else {
            if (((Integer) obj).intValue() == ASC) {
                retValue = ASC;
            } else {
                retValue = DEC;
            }
        }
        return retValue;
    }

}
