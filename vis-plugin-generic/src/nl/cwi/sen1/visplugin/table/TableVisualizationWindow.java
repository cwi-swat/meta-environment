package nl.cwi.sen1.visplugin.table;

import java.awt.BorderLayout;
import java.awt.event.ActionEvent;

import javax.swing.AbstractAction;
import javax.swing.JMenu;
import javax.swing.JMenuItem;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;
import javax.swing.JTextArea;
import javax.swing.table.JTableHeader;
import javax.swing.table.TableColumn;
import javax.swing.table.TableColumnModel;

import nl.cwi.sen1.relationstores.types.Location;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationPluginController;
import nl.cwi.sen1.visplugin.VisualizationPluginWindow;
import nl.cwi.sen1.visplugin.table.model.HeaderListener;
import nl.cwi.sen1.visplugin.table.model.LocationButtonRenderer;
import nl.cwi.sen1.visplugin.table.model.SortButtonRenderer;
import nl.cwi.sen1.visplugin.table.model.SortableTableModel;
import nl.cwi.sen1.visplugin.table.model.SortableTableModelExporter;
import nl.cwi.sen1.visplugin.table.model.TableLocationButtonListener;
import aterm.ATerm;

/**
 * The TableVisualizationWindows class. It Extends VisualizationPluginWindow.
 *
 * @author Srinivasan Tharmarajah
 * @author Wasim Alsaqaf
 * @date 08-03-2007
 */
public class TableVisualizationWindow extends VisualizationPluginWindow {

    private SortableTableModel m_model = new SortableTableModel();

    private JTable m_table;

    private static final long serialVersionUID = 1;

    /**
     * Returns JPanel including JTable with Data.
     *
     * @author Srinivasan Tharmarajah
     * @author Wasim Alsaqaf
     * @author Anton Gerdessen
     * @author Anton Lycklama a Nijeholt
     * @author Bas Basten
     * @author Arend van Beelen (refactoring)
     * @date 13-3-2007
     */
    public JPanel render(RTuple fact) {
        JPanel controlArea = new JPanel(new BorderLayout());

        try {
            m_model.setRTupleData(fact);
            
            if (m_model.getRowCount() == 0) {
            	controlArea.add(new JTextArea("This fact is empty."));
            	return controlArea;
            }

            m_table = new JTable(m_model);

            // create the buttons to enable header sorting
            SortButtonRenderer sortRenderer = new SortButtonRenderer();
            TableColumnModel columnModel = m_table.getColumnModel();
            for (int columnNum = 0; columnNum < m_model.getColumnCount(); columnNum++) {
                columnModel.getColumn(columnNum).setHeaderRenderer(sortRenderer);
            }

            // add the listener to the header to catch the mouse clicks
            JTableHeader header = m_table.getTableHeader();
            header.addMouseListener(new HeaderListener(header, sortRenderer));

            // create the buttons for location columns
            for (int columnNum = 0; columnNum < m_model.getColumnCount(); columnNum++) {
                TableColumn modelColumn = columnModel.getColumn(columnNum);
                modelColumn.setIdentifier(new Integer(columnNum));

                if (m_model.getValueAt(0, columnNum) instanceof Location) {
                    LocationButtonRenderer locRenderer = new LocationButtonRenderer();
                    TableColumn tableColumn = m_table.getColumn(new Integer(columnNum));
                    tableColumn.setCellRenderer(locRenderer);
                }
            }

            // ugly code but because there is no time we have to send the window
            // to the listener so that the openLocationEditor function can be called
            TableLocationButtonListener listener = new TableLocationButtonListener(this, m_table);
            m_table.addMouseListener(listener);
            m_table.addMouseMotionListener(listener);

            // finally add the table to a pane and add it to the JPanel
            JScrollPane pane = new JScrollPane(m_table);
            controlArea.add(pane, BorderLayout.CENTER);

        } catch (Exception ex) {
            System.err.println(ex);
            ex.printStackTrace();
        }

        return controlArea;
    }

    /**
     * Create a menu
     *
     * @author Arjen van Schie & Michel Rijnders
     * @date 20-2-2007
     * @return The JMenu
     */
    protected JMenu createExtensionMenu() {
        // create the menu item
        JMenu extensionMenu = super.createExtensionMenu();

        // create the sub-item Export
        JMenuItem export = new JMenuItem("Export to RStore");
        export.addActionListener(new AbstractAction() {
            public void actionPerformed(ActionEvent e) {
                getController().exportToClicked(
                        VisualizationPluginController.requestType.rStore,
                        getWindowId());
            }

            private final static long serialVersionUID = 1;
        });
        extensionMenu.add(export);

        return extensionMenu;
    }

    /**
     * Exports the selected rows from the table to an RStore file.
     *
     * @param filename Filename of the file to export the RStore to.
     *
     * @author Arend van Beelen
     * @date 13-3-2007
     */
    public void exportToRStore(String filename) {
        SortableTableModelExporter exporter = new SortableTableModelExporter(m_model);

        exporter.exportToRStore(filename, m_table.getSelectedRows());

        if( getStudio() != null ) {
            ATerm term = getStudio().getATermFactory().make("vp-rstore-exported(<str>)", filename);
            getController().getBridge().sendEvent(term);
        }
    }
}
