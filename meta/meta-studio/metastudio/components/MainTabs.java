package metastudio.components;

import javax.swing.JComponent;
import javax.swing.JTabbedPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import aterm.ATermFactory;

public class MainTabs extends UserInterfacePanel {
    private JTabbedPane tabs;
    
    public MainTabs(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        createMainTabs();
        add(tabs);
    }
    
    private JTabbedPane createMainTabs() {
        tabs = new JTabbedPane();

        addTab(tabs, "Modules", new ModuleBrowser(getFactory(), getBridge()));
        addTab(tabs, "Parse tree", new ParseTreeBrowser(getFactory(), getBridge()));
        
        return tabs;
    }
    
    private void addTab(JTabbedPane tabs, String title, JComponent tool) {
        tabs.insertTab(title, null, tool, null, tabs.getTabCount());
    }

}
