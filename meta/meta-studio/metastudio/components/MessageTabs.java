package metastudio.components;

import javax.swing.JTabbedPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import aterm.ATermFactory;

public class MessageTabs extends UserInterfacePanel {
    private JTabbedPane messageTabs;
    
    public MessageTabs(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        createMessageTabs();
        add(messageTabs);
    }
    
    private void createMessageTabs() {
        messageTabs = new JTabbedPane();

        HistoryPanel historyPanel = new HistoryPanel(getFactory(), getBridge());
        
        UserInterfacePanel errorList = new ErrorList(getFactory(), getBridge());
        UserInterfacePanel systemInfo = new SystemInfoPanel(getFactory(), getBridge());
        
        messageTabs.insertTab("Errors", null, errorList, "Errors and warnings", 0);
        messageTabs.insertTab("Info",null, systemInfo,"System information", 1);
        messageTabs.insertTab("Log", null, historyPanel, "Status log", 2);
    }
}
