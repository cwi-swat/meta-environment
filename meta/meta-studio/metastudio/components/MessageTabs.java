package metastudio.components;

import javax.swing.JTabbedPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.components.errorlist.ErrorList;
import metastudio.components.infolist.*;
import metastudio.components.statushistory.*;
import aterm.ATermFactory;

public class MessageTabs extends UserInterfacePanel {
    private JTabbedPane messageTabs;
    
    public MessageTabs(ATermFactory factory, MultiBridge bridge, String[] args) {
        super(factory, bridge);
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

        StatusHistory historyPanel = new StatusHistory(getFactory(), args);
        spawn(historyPanel, "history-list");
        
        ErrorList errorList = new ErrorList(getFactory(), args);
        spawn(errorList, "error-list");
        
        InfoList systemInfo = new InfoList(getFactory(), args);
        spawn(systemInfo, "info-list");
        
        messageTabs.insertTab("Errors", null, errorList, "Errors and warnings", 0);
        messageTabs.insertTab("Info",null, systemInfo,"System information", 1);
        messageTabs.insertTab("Log", null, historyPanel, "Status log", 2);
    }
}
