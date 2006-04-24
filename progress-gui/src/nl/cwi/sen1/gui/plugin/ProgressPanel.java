package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import aterm.ATerm;

import nl.cwi.sen1.gui.plugin.data.ProgressTableModel;

public class ProgressPanel extends JPanel {
    private JTable table;

    private ProgressTableModel model;

    public ProgressPanel() {
        super(new BorderLayout());

        model = new ProgressTableModel();
        model.addColumn("Module");
        table = new JTable(model);

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

    public void setStatus(ATerm id, String message, String columnName, String value) {
        model.setStatus(id, message, columnName, value);
    }
}
