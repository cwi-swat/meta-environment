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
        messageTabs.insertTab("error", null, errorList, "error messages", 0);
        
        UserInterfacePanel messageList = new MessageList(getFactory(), getBridge());
        messageTabs.insertTab("messages", null, messageList, "old-style messages", 1);
        
        messageTabs.insertTab("history", null, historyPanel, "Execution history", 2);
    }
}
