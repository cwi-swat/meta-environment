package nl.cwi.sen1.visplugin.table.model;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import javax.swing.table.JTableHeader;

/**
 * Header listener, class which tranforms the header item to buttons. Also
 * listenens to the button events and redirects them.
 *
 * @author Anton Gerdessen
 * @date 12-03-2007
 */

public class HeaderListener extends MouseAdapter {

    JTableHeader header;
    SortButtonRenderer renderer;

    /**
     * Constructor
     *
     * @param header The header to listen to
     * @param renderer The rededer to which the incoming events are directed
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public HeaderListener(JTableHeader header, SortButtonRenderer renderer) {
        this.header = header;
        this.renderer = renderer;
    }

    /**
     * Handle the incoming mouse event from the header button.
     * repaint the header with the sort indication and sort the column.
     *
     * @param event mousePressed event from the header
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public void mousePressed(MouseEvent event) {
        // Determine on which column the sort will be based.
        int coloumToSort = header.columnAtPoint(event.getPoint());
        int sortCol = header.getTable().convertColumnIndexToModel(coloumToSort);
        renderer.setSelectedColumn(coloumToSort);
        header.repaint();

        // Determine the sort order and sort the table based on the column.
        boolean isAscent = false;
        if (renderer.getState(coloumToSort) == SortButtonRenderer.ASC ) {
            isAscent = true;
        }

        ((SortableTableModel) header.getTable().getModel()).sortByColumn(
                sortCol, isAscent);
    }

    /**
     * Handle the mouse released from the header button.
     * Force a repaint to show the 'new' button.
     *
     * @param event mouseReleased event from the header
     * @author Anton Gerdessen
     * @date 12-03-2007
     */
    public void mouseReleased(MouseEvent event) {
        header.repaint();
    }
}
