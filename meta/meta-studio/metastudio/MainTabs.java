package metastudio;

import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JTabbedPane;

import metastudio.components.ModuleBrowser;
import metastudio.components.TideControl;
import metastudio.components.treebrowser.TreeBrowser;
import metastudio.data.graph.MetaGraphFactory;
import tide.tool.support.DebugAdapter;
import tide.tool.support.DebugTool;
import tide.tool.support.DebugToolListener;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class MainTabs extends UserInterfacePanel {
    private static final String PARSE_TREE = "Parse tree";
	private static final String MODULES = "Modules";
	private static final String DEBUGGING = "Debugging";
	private JTabbedPane tabs;
	private Thread tideControlThread;
	private ATermFactory factory;
    
    public MainTabs(ATermFactory factory, MultiBridge bridge, String[] args) {
        super(factory, bridge);
        this.factory = factory;
        createMainTabs(args);
        add(tabs);
    }
    
    private void spawn(Runnable component, String name) {
    	Thread thread = new Thread(component);
    	thread.setName(name);
    	thread.start();
    }
    
    private JTabbedPane createMainTabs(String[] args) {
        tabs = new JTabbedPane();
        ModuleBrowser moduleBrowser = new ModuleBrowser(getFactory(), getBridge(), args);
        TreeBrowser parseTreeBrowser = new TreeBrowser(new MetaGraphFactory((PureFactory) factory), args);
       
        spawn(parseTreeBrowser, "tree-browser");
        
        addTab(tabs, MODULES, moduleBrowser);
        addTab(tabs, PARSE_TREE, parseTreeBrowser);
        
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
