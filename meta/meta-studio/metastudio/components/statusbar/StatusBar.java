package metastudio.components.statusbar;

import java.awt.BorderLayout;
import java.awt.Color;
import java.awt.Font;
import java.io.IOException;
import java.util.LinkedList;
import java.util.List;
import java.util.ListIterator;

import javax.swing.JLabel;
import javax.swing.JPanel;

import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;

public class StatusBar extends JPanel implements StatusBarTif, Runnable {
	private StatusBarBridge bridge;
    private JLabel statusBar;
    private List statusMessages;

    public StatusBar(ATermFactory factory, String[] args) {
        statusMessages = new LinkedList();

        Color bgColor =
            Preferences.getColor("statusbar.background");
        Color fgColor =
            Preferences.getColor("statusbar.foreground");
        Font font = Preferences.getFont("statusbar.font");

        setBackground(bgColor);
        setForeground(fgColor);
        setLayout(new BorderLayout());

        statusBar = new JLabel("idle");
        statusBar.setFont(font);
        add(statusBar, BorderLayout.CENTER);
        
        try {
        	bridge = new StatusBarBridge(factory, this);
        	bridge.init(args);
        	bridge.setLockObject(this);
        	bridge.connect("status-bar", null, -1);
		} catch (IOException e) {
			remove(statusBar);
			e.printStackTrace();
		}
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
        statusBar.setText(message);
        String[] pair = { id.toString(), message };
        statusMessages.add(pair);
    }

    public void addStatusf(ATerm id, String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addStatus(id, message);
    }

	public void recTerminate(ATerm t0) {
		// do nothing
	}

	public void run() {
		bridge.run();
	}
}
