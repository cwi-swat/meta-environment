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
    private MetaStudio studio;

    public StatusBar(
        ATermFactory factory,
        UserInterfaceBridge bridge,
        MetaStudio studio) {
        super(factory, bridge);

        this.studio = studio;
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
        String ids = id.toString();
        if (statusLog.isSelected()) {
            studio.addMessage(studio.   styleMessage, ids, message);
        }

        statusBar.setText(message);
        String[] pair = { ids, message };
        statusMessages.add(pair);
    }

    public void addStatusf(ATerm id, String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addStatus(id, message);
    }
}
