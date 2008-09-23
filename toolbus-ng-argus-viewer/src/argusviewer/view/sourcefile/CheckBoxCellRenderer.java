package argusviewer.view.sourcefile;

import java.awt.Color;
import java.awt.Component;
import java.awt.event.ActionEvent;
import java.awt.event.ActionListener;

import javax.swing.AbstractCellEditor;
import javax.swing.ImageIcon;
import javax.swing.JCheckBox;
import javax.swing.JTable;
import javax.swing.table.TableCellEditor;
import javax.swing.table.TableCellRenderer;

/**
 * class CheckBoxCellRenderer 
 * @author Qais & Bas
 *
 * implements a render for breakpoints
 * 
 * revision 1.0
 */
public class CheckBoxCellRenderer extends AbstractCellEditor implements TableCellRenderer, TableCellEditor {
	private static final long serialVersionUID = -1856670516526394234L;
	
	private static final ImageIcon ICONS_BREAKPOINT_SOURCE = new ImageIcon("resources/icons/breakpoint_source.png");
	private static final ImageIcon ICON_BREAKPOINT_SOURCE_TRANSPARANT = new ImageIcon("resources/icons/breakpoint_source_transparant.png");
	
	private final JCheckBox m_checkBox;
	
    /**
     *  sets images and background of the checkbox
     */
    public CheckBoxCellRenderer() {
        m_checkBox = new JCheckBox(ICON_BREAKPOINT_SOURCE_TRANSPARANT);
        m_checkBox.setSelectedIcon(ICONS_BREAKPOINT_SOURCE);
        m_checkBox.setBackground(Color.WHITE);
        m_checkBox.addActionListener(new ActionListener() {
            public void actionPerformed(ActionEvent actionEvent) {
                fireEditingStopped();
            }
        });
    }

	/**
	 * {@inheritDoc}
	 */
    public Component getTableCellRendererComponent(JTable table, Object value, boolean isSelected, boolean hasFocus, int row, int column) {
        return getComp(Boolean.parseBoolean(value.toString()));
    }
    
	/**
	 * {@inheritDoc}
	 */
    public Component getTableCellEditorComponent(JTable table, Object value, boolean isSelected, int row, int column) {
        return getComp(Boolean.parseBoolean(value.toString()));
    }

	/**
	 * {@inheritDoc}
	 */
    private Component getComp(boolean aBoolean) {
        m_checkBox.setSelected(aBoolean);
        return m_checkBox;
    }

	/**
	 * {@inheritDoc}
	 */
    public Object getCellEditorValue() {
        return Boolean.valueOf(m_checkBox.isSelected());
    }
}