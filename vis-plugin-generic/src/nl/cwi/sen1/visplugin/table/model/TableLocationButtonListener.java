package nl.cwi.sen1.visplugin.table.model;

import java.awt.Cursor;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.awt.event.MouseMotionListener;

import javax.swing.JTable;
import javax.swing.table.TableColumnModel;

import nl.cwi.sen1.relationstores.types.Location;
import nl.cwi.sen1.visplugin.table.TableVisualizationWindow;

/**
 * This class listens for mouse events in the JTable.
 * Preferably we would like to listen for mouse events at the cell level.
 * There was however not a simple solution for this so this isn't a very
 * nice solution, but it works as it should be.
 *
 * @author Anton Lycklama a Nijeholt
 * @author Bas Basten
 * @date 13-03-2007
 */
public class TableLocationButtonListener implements MouseListener, MouseMotionListener {
    private JTable m_table;
    private Cursor mouseOverCursor = new Cursor(Cursor.HAND_CURSOR);
    private TableVisualizationWindow m_window;

    public TableLocationButtonListener(TableVisualizationWindow window, JTable table) {
        m_window = window;
        m_table = table;
    }

    /**
     * Get the cell's location ATerm at the X and Y coordinates of the mouse.
     *
     * @param event
     * @return Returns a location ATerm if found, otherwise return null.
     *
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 13-03-2007
     */
    private Location getLocation(MouseEvent event) {
        TableColumnModel columnModel = m_table.getColumnModel();
        int column = columnModel.getColumnIndexAtX(event.getX());
        int row = event.getY() / m_table.getRowHeight();

        Object value;

        if (row >= m_table.getRowCount() ||
            row < 0 ||
            column >= m_table.getColumnCount() ||
            column < 0) {
            return null;
        }

        value = m_table.getValueAt(row, column);

        if (!(value instanceof Location)) {
            return null;
        }

        return (Location) value;
    }

    /**
     * Handle the mouse click only if is clicked on a cell
     * with a location link.
     *
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 13-03-2007
     */
    public void mouseClicked(MouseEvent e) {
        Location location = getLocation(e);
        if (location != null) {
            m_window.openLocationInEditor(location);
        }
    }

    /**
     * Change the mousecursor if it moves over a location link.
     *
     * @author Bas Basten
     * @author Anton Lycklama a Nijeholt
     * @date 13-03-2007
     */
    public void mouseMoved(MouseEvent e) {
        if (getLocation(e) != null) {
            m_table.setCursor(mouseOverCursor);
        }
        else {
            m_table.setCursor(Cursor.getDefaultCursor());
        }
    }

    public void mouseEntered(MouseEvent e) {
        // No implementation
    }

    public void mouseExited(MouseEvent e) {
        // No implementation
    }

    public void mousePressed(MouseEvent e) {
        // No implementation
    }

    public void mouseReleased(MouseEvent e) {
        // No implementation
    }

    public void mouseDragged(MouseEvent e) {
        // TODO Auto-generated method stub
    }
}
