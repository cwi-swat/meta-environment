package metastudio.components;

import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JTabbedPane;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.ValueChangedListener;
import tide.tool.support.DebugAdapter;
import tide.tool.support.DebugTool;
import tide.tool.support.DebugToolListener;
import aterm.ATermFactory;

public class MainTabs extends UserInterfacePanel {
    private static final String PARSE_TREE = "Parse tree";
	private static final String MODULES = "Modules";
	private static final String DEBUGGING = "Debugging";
	private JTabbedPane tabs;
	private Thread tideControlThread;
    
    public MainTabs(ATermFactory factory, MultiBridge bridge, String[] args) {
        super(factory, bridge);
        createMainTabs(args);
        add(tabs);
    }
    
    private JTabbedPane createMainTabs(String[] args) {
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
        
		try {
			TideControl tide = new TideControl(getFactory(), args);
			addTab(tabs, DEBUGGING, tide);
			
			tide.addDebugToolListener(new DebugToolListener() {
				public void adapterConnected(DebugTool tool, DebugAdapter adapter) {
                  tabs.setSelectedIndex(tabs.indexOfTab(DEBUGGING));
				}

				public void adapterDisconnected(
					DebugTool tool,
					DebugAdapter adapter) {
					tabs.setSelectedIndex(tabs.indexOfTab(MODULES));
				}
			});
		} catch (IOException e) {
			// TODO: 
			System.err.println("TODO: deal with this error properly");
		}
		
        return tabs;
    }
    
    private void addTab(JTabbedPane tabs, String title, JComponent tool) {
        tabs.insertTab(title, null, tool, null, tabs.getTabCount());
    }
}
