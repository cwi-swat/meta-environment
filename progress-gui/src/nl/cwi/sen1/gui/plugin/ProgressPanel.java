package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import nl.cwi.sen1.gui.plugin.data.ProgressTableModel;
import nl.cwi.sen1.gui.plugin.data.TableSorter;
import aterm.ATerm;

public class ProgressPanel extends JPanel {
    private JTable table;

    private ProgressTableModel model;

    public ProgressPanel() {
        super(new BorderLayout());

        model = new ProgressTableModel();
        model.addColumn("Module");
        TableSorter sorter = new TableSorter(model);
        table = new JTable(sorter);
        sorter.setTableHeader(table.getTableHeader());
        
        // JToolBar toolBar = new JToolBar("Error ToolBar",
        // SwingConstants.VERTICAL);
        // addButtons(toolBar);

        JScrollPane scrollPane = new JScrollPane(table);
        // add(toolBar, BorderLayout.WEST);
        add(scrollPane, BorderLayout.CENTER);
    }

    public void removeStatus(ATerm id) {
      model.removeStatus(id);
      repaint();
    }

    public void setStatus(ATerm id, String columnName, String value) {
        model.setStatus(id, columnName, value);
    }
    
    public void setMessage(ATerm id, String message) {
    	model.setMessage(id, message);
    }
}
