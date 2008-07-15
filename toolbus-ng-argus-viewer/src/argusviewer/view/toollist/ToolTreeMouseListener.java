package argusviewer.view.toollist;

import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

/**
 * MouseListener for ToolTree
 *
 * @author Roberto van der Linden
 */
public class ToolTreeMouseListener implements MouseListener {

	private ToolTreeTable m_toolTreeTable;

	/**
	 * Constructor
	 *
	 * @param toolTreeTable toolTreeTable
	 */
	public ToolTreeMouseListener(ToolTreeTable toolTreeTable) {
		m_toolTreeTable = toolTreeTable;
	}

	/**
	 * Invoked when mouseButton is clicked
	 *
	 * @param e mouseEvent
	 */
	public void mouseClicked(MouseEvent e) {
		m_toolTreeTable.sendClickEvent(e.getClickCount(), e.getX(), e.getY());
	}

	/**
	 * {@inheritDoc}
	 */
	public void mousePressed(MouseEvent e) {
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseReleased(MouseEvent e) {
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseEntered(MouseEvent e) {
	}

	/**
	 * {@inheritDoc}
	 */
	public void mouseExited(MouseEvent e) {
	}
}
