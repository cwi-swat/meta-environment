package metastudio;

import java.awt.BorderLayout;
import java.io.IOException;

import javax.swing.JComponent;
import javax.swing.JPanel;
import javax.swing.JTabbedPane;

import metastudio.components.TideControl;
import metastudio.components.modulebrowser.ModuleBrowser;
import metastudio.components.treebrowser.TreeBrowser;
import metastudio.data.graph.MetaGraphFactory;
import tide.tool.support.DebugAdapter;
import tide.tool.support.DebugTool;
import tide.tool.support.DebugToolListener;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class MainTabs extends JPanel {
    private static final String PARSE_TREE = "Parse tree";
	private static final String MODULES = "Modules";
	private static final String DEBUGGING = "Debugging";
	private JTabbedPane tabs;
	private Thread tideControlThread;
	private ATermFactory factory;
    
    public MainTabs(ATermFactory factory, String[] args) {
        this.factory = factory;
        setLayout(new BorderLayout());
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
        ModuleBrowser moduleBrowser = new ModuleBrowser(factory, args);
        spawn(moduleBrowser, "module-browser");
        addTab(tabs, MODULES, moduleBrowser);
        
        TreeBrowser parseTreeBrowser = new TreeBrowser(new MetaGraphFactory((PureFactory) factory), args);
        spawn(parseTreeBrowser, "tree-browser");
        addTab(tabs, PARSE_TREE, parseTreeBrowser);
        
		try {
			TideControl tide = new TideControl(factory, args);
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
