package metastudio.components.statushistory;

import java.awt.BorderLayout;
import java.awt.Rectangle;
import java.io.IOException;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.LinkedList;

import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;

import metastudio.data.ListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.ATermList;

// todo: add copy paste facility?
public class StatusHistory extends JPanel implements StatusHistoryTif, Runnable {
	private StatusHistoryBridge bridge;
	private ATermFactory factory;
	
    private JList list;
    private ListModel data;
    private DateFormat dateFormat;

    public StatusHistory(aterm.ATermFactory factory, String[] args) {
    	this.factory = factory;

        this.data = new ListModel(new LinkedList());

        this.list = new JList();

	setLayout(new BorderLayout());

        list.setModel(data);
        list.setBackground(Preferences.getColor("messagepane.background"));
        list.setForeground(Preferences.getColor("error.info.foreground"));
        list.setFont(Preferences.getFont("error.info.font"));

        String format = Preferences.getString("history.dateformat");
        dateFormat = new SimpleDateFormat(format);
        add(new JScrollPane(list), BorderLayout.CENTER);
        
        try {
        	bridge = new StatusHistoryBridge(factory, this);
        	bridge.init(args);
        	bridge.setLockObject(this);
        	bridge.connect("status-history", null, -1);
        } catch (IOException e) {
        	e.printStackTrace();
        }
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
    
    public void logStatus(ATerm id, String message) {
        addMessage(id.toString(), message);
    }

    public void logStatusf(ATerm id, String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addMessage(id.toString(), message);
    }
    
    public void logEndStatus(ATerm id) {
        String date = dateFormat.format(Calendar.getInstance().getTime());
        data.add(date + " - " + id + " - done");
        scrollToLast();
    }

    public void clearHistory() {
        data.setList(new LinkedList());
        repaint();
    }

	public void recTerminate(ATerm t0) {
		// TODO Auto-generated method stub
		
	}

	public void run() {
		bridge.run();
		
	}

	
}
