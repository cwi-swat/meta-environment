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
    
    private void createMessageTabs(String[] args) {
        messageTabs = new JTabbedPane();

        StatusHistory historyPanel = new StatusHistory(getFactory(), args);
        Thread historyThread = new Thread(historyPanel);
        historyThread.setName("history-list");
        historyThread.start();
        
        ErrorList errorList = new ErrorList(getFactory(), args);
        Thread errorListThread = new Thread(errorList);
        errorListThread.setName("error-list");
        errorListThread.start();
        
        InfoList systemInfo = new InfoList(getFactory(), args);
        Thread systemInfoThread = new Thread(systemInfo);
        systemInfoThread.setName("info-list");
        systemInfoThread.start();
        
        messageTabs.insertTab("Errors", null, errorList, "Errors and warnings", 0);
        messageTabs.insertTab("Info",null, systemInfo,"System information", 1);
        messageTabs.insertTab("Log", null, historyPanel, "Status log", 2);
    }
}
