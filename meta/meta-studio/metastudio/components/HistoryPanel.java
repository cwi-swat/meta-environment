package metastudio.components;

import java.awt.BorderLayout;
import java.awt.Rectangle;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.LinkedList;

import javax.swing.JList;
import javax.swing.JScrollPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.data.ListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;

// todo: add copy paste facility?
public class HistoryPanel extends UserInterfacePanel {
    private JList list;
    private ListModel data;
    private DateFormat dateFormat;

    public HistoryPanel(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.data = new ListModel(new LinkedList());

        this.list = new JList();

        list.setModel(data);
        list.setBackground(Preferences.getColor("messagepane.background"));
        list.setForeground(Preferences.getColor("error.info.foreground"));
        list.setFont(Preferences.getFont("error.info.font"));

        String format = Preferences.getString("history.dateformat");
        dateFormat = new SimpleDateFormat(format);
        add(new JScrollPane(list), BorderLayout.CENTER);
    }
    
    private void scrollToLast() {
        Rectangle last = list.getCellBounds(data.getSize() - 1, data.getSize() - 1);
        if (last != null) {
            list.scrollRectToVisible(last);
        }
        repaint();
    }
    
    private void addMessage(String id, String message) {
        String date = dateFormat.format(Calendar.getInstance().getTime());
        data.add(date + " - " + id + " - " + message);
        scrollToLast();
    }
    
    public void addStatus(ATerm id, String message) {
        addMessage(id.toString(), message);
    }

    public void addStatusf(ATerm id, String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addMessage(id.toString(), message);
    }
    
    public void endStatus(ATerm id) {
        String date = dateFormat.format(Calendar.getInstance().getTime());
        data.add(date + " - " + id + " - done");
        scrollToLast();
    }

    public void clearHistory() {
        data.setList(new LinkedList());
        repaint();
    }
}
