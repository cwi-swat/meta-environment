package metastudio.components;

import java.awt.BorderLayout;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
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
    private DateFormat dateFormat;

    public HistoryPanel(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.data = new ListModel(new LinkedList());

        this.list = new JList();

        list.setModel(data);
        list.setBackground(Preferences.getColor("messagepane.background"));
        list.setForeground(Preferences.getColor("feedback.info.foreground"));
        list.setFont(Preferences.getFont("feedback.info.font"));

        String format = Preferences.getString("history.dateformat");
        dateFormat = new SimpleDateFormat(format);
        add(new JScrollPane(list), BorderLayout.CENTER);
    }

    public void addMessage(String message) {
        String date = dateFormat.format(Calendar.getInstance().getTime());
        data.add(date + " - " + message);
    }
    

    public void clearHistory() {
        data.setList(new LinkedList());
        repaint();
    }
}
