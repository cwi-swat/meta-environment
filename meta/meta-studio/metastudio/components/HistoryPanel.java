package metastudio.components;

import java.awt.BorderLayout;
import java.util.LinkedList;

import javax.swing.JList;
import javax.swing.JScrollPane;

import metastudio.MultiBridge;
import metastudio.data.ListModel;
import metastudio.utils.Preferences;


// todo: add copy paste facility?
public class HistoryPanel extends ToolComponent {
    private JList list;
    private ListModel data;

    public HistoryPanel(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.data = new ListModel(new LinkedList());

        this.list = new JList();

        list.setModel(data);
        list.setBackground(Preferences.getColor("messagepane.background"));

        add(new JScrollPane(list), BorderLayout.CENTER);
    }
    
    public void addMessage(String message) {
        data.add(message);
    }
    
    public void clearHistory() {
        data.setList(new LinkedList());
    }
}
