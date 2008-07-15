package argusviewer.view.architectureview.performance.tree;

import java.awt.Component;

import javax.swing.JProgressBar;
import javax.swing.JTable;
import javax.swing.table.TableCellRenderer;

/**
 * Renderer for the processor column. Shows a value as a {@link JProgressBar}.
 * 
 * @author Jeldert Pol
 */
public class ProcessorRenderer implements TableCellRenderer {

	/**
	 * {@inheritDoc}
	 */
	public Component getTableCellRendererComponent(JTable table, Object value,
			boolean isSelected, boolean hasFocus, int row, int column) {
		int processor = ((Integer) value).intValue();

		JProgressBar progressBar = new JProgressBar();
		progressBar.setValue(processor);
		return progressBar;
	}

}
