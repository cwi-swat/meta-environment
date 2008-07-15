package argusviewer.view.toollist;


import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.ScrollPaneConstants;
import javax.swing.table.TableColumnModel;
import java.awt.BorderLayout;
import java.awt.Color;


/**
 * The component that is returned by the plugin.
 *
 * @author Alexander Bij
 * @author Roberto van der Linden
 */
@SuppressWarnings("serial")
public class ToolListView extends JPanel {

    private ToolTreeTable m_toolTreeTable;

    private static final int VISIBLE_COLUMN_WIDTH = 50;
    private static final int TOOL_NAME_COLUMN_WIDTH = -1;
    private static final int ID_COLUMN_WIDTH = 50;

    //Minimum width of a column is 15.
    private static final int MIN_COLUMN_WIDTH = 15;

    /**
     * Creates the ToolTreeTable with the model and sets the column widths.
     *
     * @param toolTreeModel the Model for the table.
	 * @param toolListController toolListController
     */
    protected void createTable(ToolTreeModel toolTreeModel, ToolListController toolListController) {
        setLayout(new BorderLayout());
        m_toolTreeTable = new ToolTreeTable(toolTreeModel, toolListController);
        toolTreeModel.setParent(m_toolTreeTable);
        
		JScrollPane scrollPane = new JScrollPane(m_toolTreeTable);
        scrollPane.setBackground(Color.WHITE);
        scrollPane.setVerticalScrollBarPolicy(ScrollPaneConstants.VERTICAL_SCROLLBAR_AS_NEEDED);

        setColumnWidth(VISIBLE_COLUMN_WIDTH, TOOL_NAME_COLUMN_WIDTH, ID_COLUMN_WIDTH);

        add(scrollPane, BorderLayout.CENTER);
    }

    /**
     * Set the column with for the ToolTreeTable. Negative numbers and 0 are ignored. Default resize will occor.
     *
     * @param visibleColumnWidth  Max with of Column 1
     * @param toolNameColumnWidth Max with of Column 2
     * @param idColumnWidth       Max with of Column 3
     */
    protected void setColumnWidth(int visibleColumnWidth, int toolNameColumnWidth, int idColumnWidth) {
        TableColumnModel columnModel = m_toolTreeTable.getColumnModel();

        if (visibleColumnWidth > MIN_COLUMN_WIDTH) {
            columnModel.getColumn(ToolTreeModel.VISIBLE_COLUMN).setMaxWidth(visibleColumnWidth);
        }

        if (toolNameColumnWidth > MIN_COLUMN_WIDTH) {
            columnModel.getColumn(ToolTreeModel.TOOL_COLUMN).setMaxWidth(toolNameColumnWidth);
        }

        if (idColumnWidth > MIN_COLUMN_WIDTH) {
            columnModel.getColumn(ToolTreeModel.ID_COLUMN).setMaxWidth(idColumnWidth);
        }
    }

    /**
     * Test if the refresh method is called
     */
    public void refresh() {
        m_toolTreeTable.refresh();
    }


    /**
     * Sets the table.
     *
     * @param toolTreeTable set the table
     */
    protected void setToolTreeTable(ToolTreeTable toolTreeTable) {
        this.m_toolTreeTable = toolTreeTable;
	}
}
