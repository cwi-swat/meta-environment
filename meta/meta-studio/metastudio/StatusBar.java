package metastudio;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

import javax.swing.JCheckBox;
import javax.swing.JLabel;

import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;

public class StatusBar extends JPanelTool {
    private JLabel statusBar;
    private JCheckBox statusLog;
    private List statusMessages;
    private HistoryPanel history;

    public StatusBar(
        ATermFactory factory,
        UserInterfaceBridge bridge,
        HistoryPanel history) {
        super(factory, bridge);

        this.history = history;
        statusMessages = new LinkedList();

        Color bgColor =
            Preferences.getColor(Preferences.PREF_MSGPANE_STATUS + ".background");
        Color fgColor =
            Preferences.getColor(Preferences.PREF_MSGPANE_STATUS + ".foreground");
        Font font = Preferences.getFont(Preferences.PREF_MSGPANE_STATUS + ".font");

        setBackground(bgColor);
        setForeground(fgColor);
        setLayout(new BorderLayout());

        statusLog = new JCheckBox("Log Status");
        statusLog.setSelected(
            Preferences.getBoolean(Preferences.PREF_MSGPANE_STATUS + ".log"));
        statusLog.setBackground(bgColor);
        statusLog.setForeground(fgColor);
        statusLog.setFont(font);
        add(statusLog, BorderLayout.EAST);

        statusBar = new JLabel("idle");
        statusBar.setFont(font);
        add(statusBar, BorderLayout.CENTER);
    }

    public void endStatus(ATerm id) {
        clearStatus(id.toString());
    }

    private void clearStatus(String id) {
        ListIterator iter = statusMessages.listIterator();
        while (iter.hasNext()) {
            String[] pair = (String[]) iter.next();
            if (pair[0].equals(id)) {
                iter.remove();
            }
        }

        if (statusMessages.size() == 0) {
            statusBar.setText("idle");
        } else {
            statusBar.setText(((String[]) statusMessages.get(0))[1]);
        }
    }

    public void addStatus(ATerm id, String message) {
        if (statusLog.isSelected()) {
            history.message(message);
        }

        statusBar.setText(message);
        String[] pair = { id.toString(), message };
        statusMessages.add(pair);
    }

    public void addStatusf(ATerm id, String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addStatus(id, message);
    }
}
