package argusviewer.view.toollist;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

/**
 * MouseListener for ToolTree
 *
 * @author Roberto van der Linden
 */
public class ToolTreeMouseListener extends MouseAdapter {
	private final ToolTreeTable m_toolTreeTable;

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
}
