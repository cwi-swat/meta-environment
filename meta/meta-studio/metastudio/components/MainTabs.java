package metastudio.components;

import javax.swing.JComponent;
import javax.swing.JTabbedPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.ValueChangedListener;
import aterm.ATermFactory;

public class MainTabs extends UserInterfacePanel {
    private static final String PARSE_TREE = "Parse tree";
	private static final String MODULES = "Modules";
	private JTabbedPane tabs;
    
    public MainTabs(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        createMainTabs();
        add(tabs);
    }
    
    private JTabbedPane createMainTabs() {
        tabs = new JTabbedPane();
        ModuleBrowser moduleBrowser = new ModuleBrowser(getFactory(), getBridge());
        ParseTreeBrowser parseTreeBrowser = new ParseTreeBrowser(getFactory(), getBridge());

        addTab(tabs, MODULES, moduleBrowser);
        addTab(tabs, PARSE_TREE, parseTreeBrowser);
        
        parseTreeBrowser.addValueChangedListener(new ValueChangedListener() {
			public void valueChanged() {
				tabs.setSelectedIndex(tabs.indexOfTab(PARSE_TREE));
			}
		});
        
        return tabs;
    }
    
    private void addTab(JTabbedPane tabs, String title, JComponent tool) {
        tabs.insertTab(title, null, tool, null, tabs.getTabCount());
    }
}
