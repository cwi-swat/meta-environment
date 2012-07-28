package nl.cwi.sen1.gui.plugin;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTable;

import nl.cwi.sen1.gui.plugin.data.ModuledetailsTableModel;

public class ModuledetailsPanel extends JPanel {
    private JTable table;

    private ModuledetailsTableModel model;

    public ModuledetailsPanel() {
        super(new BorderLayout());
        String[] columnNames = { "Namespace", "Key", "Value" };

        model = new ModuledetailsTableModel(columnNames);
        table = new JTable(model);

        JScrollPane scrollPane = new JScrollPane(table);
        add(scrollPane, BorderLayout.CENTER);
    }

    public void setDetails(String namespace, String key, String value) {
        model.setDetails(namespace, key, value);
    }
}