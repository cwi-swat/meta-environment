package metastudio.components;

import java.awt.BorderLayout;
import java.awt.Rectangle;
import java.text.DateFormat;
import java.text.SimpleDateFormat;
import java.util.Calendar;
import java.util.LinkedList;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.data.ListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;

public class SystemInfoPanel extends UserInterfacePanel {
    private static final String ERROR = "error";
	private JList list;
    private ListModel data;
    private DateFormat dateFormat;

    public SystemInfoPanel(aterm.ATermFactory factory, MultiBridge bridge) {
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
    
    private void setErrorColor() {
    	list.setForeground(Preferences.getColor("error.info.foreground"));
    }
    
    private void setWarningColor() {
    	list.setForeground(Preferences.getColor("error.warning.foreground"));
    }
    
    private void setInfoColor() {
    	list.setForeground(Preferences.getColor("error.info.foreground"));
    }
    
    private void scrollToLast() {
        Rectangle last = list.getCellBounds(data.getSize() - 1, data.getSize() - 1);
        if (last != null) {
            list.scrollRectToVisible(last);
        }
        repaint();
    }
    
    private void addMessage(String message) {
    	String date = dateFormat.format(Calendar.getInstance().getTime());
        data.add(date + ": " + message);
        scrollToLast();
    }
    
    public void clearHistory() {
        data.setList(new LinkedList());
        repaint();
    }
    
    private void toFront() {
    	// TODO: find a better solution for this, we don't want this component
    	// to know what type of parent it has!
    	JTabbedPane parent = (JTabbedPane) getParent();
    	parent.setSelectedComponent(this);
    }
    
    public void addMessageAndToFront(String message) {
    	addMessage(message);
    	toFront();
    }
    
    public void errorf(String format, ATerm args) {
    	setErrorColor();
    	String message = StringFormatter.format(format, (ATermList) args);
    	addMessageAndToFront(message);
    }

    public void error(String message) {
    	setErrorColor();
    	addMessageAndToFront(message);
    }

    public void messagef(String format, ATerm args) {
    	setInfoColor();
    	String message = StringFormatter.format(format, (ATermList) args);
    	addMessageAndToFront(message);
    }

    public void message(String message) {
    	setInfoColor();
    	addMessageAndToFront(message);
    }

    public void warningf(String format, ATerm args) {
    	setWarningColor();
    	String message = StringFormatter.format(format, (ATermList) args);
    	addMessageAndToFront(message);
    }

    public void warning(String message) {
    	setWarningColor();
    	addMessageAndToFront(message);
    }
}
