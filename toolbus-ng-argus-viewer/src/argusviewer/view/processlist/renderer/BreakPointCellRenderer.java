package argusviewer.view.processlist.renderer;

import java.awt.Component;

import javax.swing.ImageIcon;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTable;
import javax.swing.table.TableCellRenderer;
import argusviewer.view.processlist.data.ProcessTreeNode.BreakPointType;


/**
 * The BreakPointCellRenderer makes sure the right icon is show for the
 * different BreakPointTypes.
 * 
 * @author R.Schuddeboom
 * @author H.Baggelaar
 * @author Jeldert Pol
 */
public class BreakPointCellRenderer implements TableCellRenderer {

	public static final ImageIcon ICON_LINE = new ImageIcon(
			"resources/icons/breakpoint_source.png");
	public static final ImageIcon ICON_PROCESS = new ImageIcon(
			"resources/icons/breakpoint_process.png");
	public static final ImageIcon ICON_BOTH = new ImageIcon(
			"resources/icons/breakpoint_both.png");

	private JButton m_button = new JButton();

	/**
	 * The constructor of the BreakPointCellRenderer class
	 */
	public BreakPointCellRenderer() {
		m_button.setOpaque(false);
		m_button.setText("");
		m_button.setBorderPainted(false);
		m_button.setContentAreaFilled(false);
	}

	/**
	 * Get the CellRenderer for the current Object
	 * 
	 * @param table
	 *            The JTable to act upon
	 * @param value
	 *            The Value of the current cell
	 * @param isSelected
	 *            Whether the cell isSelected
	 * @param hasFocus
	 *            Whether the cell hasFocus
	 * @param row
	 *            The row of the table
	 * @param column
	 *            The column of the table
	 * @return Component the same thing as received
	 */
	public Component getTableCellRendererComponent(JTable table, Object value,
			boolean isSelected, boolean hasFocus, int row, int column) {
		if (isSelected) {
			m_button.setBackground(table.getSelectionBackground());
		} else {
			m_button.setBackground(table.getBackground());

			if (!(value instanceof BreakPointType)) {
				return new JLabel("");
			}
			
			BreakPointType bpType = (BreakPointType) value;
			switch (bpType) {
			case LINE:
				m_button.setIcon(ICON_LINE);
				break;
			case PROCESS:
				m_button.setIcon(ICON_PROCESS);
				break;
			case BOTH:
				m_button.setIcon(ICON_BOTH);
				break;
			case NONE:
				m_button.setIcon(null);
				break;
			default:
				throw new RuntimeException(
						"BreakPointCellRenderer: invalid BreakPointType: "
								+ bpType);
			}
		}
		return m_button;
	}
}

