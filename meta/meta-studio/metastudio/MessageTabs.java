package metastudio;

import java.awt.BorderLayout;

import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import metastudio.components.errorlist.ErrorList;
import metastudio.components.infolist.InfoList;
import metastudio.components.statushistory.StatusHistory;
import aterm.ATermFactory;

public class MessageTabs extends JPanel {
    private JTabbedPane messageTabs;
    private ATermFactory factory;
    
    public MessageTabs(ATermFactory factory, String[] args) {
    	this.factory = factory;
    	setLayout(new BorderLayout());
        createMessageTabs(args);
        add(messageTabs);
    }
    
    private void spawn(Runnable component, String name) {
    	Thread thread = new Thread(component);
    	thread.setName(name);
    	thread.start();
    }
    
    private void createMessageTabs(String[] args) {
        messageTabs = new JTabbedPane();

        StatusHistory historyPanel = new StatusHistory(factory, args);
        spawn(historyPanel, "history-list");
        
        ErrorList errorList = new ErrorList(factory, args);
        spawn(errorList, "error-list");
        
        InfoList systemInfo = new InfoList(factory, args);
        spawn(systemInfo, "info-list");
        
        messageTabs.insertTab("Errors", null, errorList, "Errors and warnings", 0);
        messageTabs.insertTab("Info",null, systemInfo,"System information", 1);
        messageTabs.insertTab("Log", null, historyPanel, "Status log", 2);
    }
}
