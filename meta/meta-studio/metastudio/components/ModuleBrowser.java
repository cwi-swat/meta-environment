package metastudio.components;

import java.awt.Color;

import javax.swing.JSplitPane;

import metastudio.MultiBridge;
import metastudio.components.graphs.ImportGraphPanel;
import metastudio.data.ModuleTreeModel;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.utils.Preferences;
import aterm.ATermFactory;
import aterm.pure.PureFactory;

public class ModuleBrowser extends ToolComponent {
    private ImportGraphPanel importGraphPanel;
    private ModuleInfoPanel moduleStatus;
    private ModuleTreeModel moduleManager;
    private MetaGraphFactory metaGraphFactory;
    
    public ModuleBrowser(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        
        metaGraphFactory = new MetaGraphFactory((PureFactory) factory);
        moduleManager = new ModuleTreeModel();
        
        JSplitPane left = createLeftPane();

        createModuleGraph();

        JSplitPane moduleBrowser =
        new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, left, importGraphPanel);
        moduleBrowser.setDividerLocation(Preferences.getDouble("modulebrowser.info.divider.location"));
        moduleBrowser.setResizeWeight(Preferences.getDouble("modulebrowser.info.divider.resize"));
        moduleBrowser.setOneTouchExpandable(true);
        
        add(moduleBrowser);
    }

    private void createModuleGraph() {
        importGraphPanel = new ImportGraphPanel(metaGraphFactory, getBridge(), moduleManager);
        Color color = Preferences.getColor("graphpane.background");
        importGraphPanel.setBackground(color);
    }
    
    private void createModuleStatusPanel() {
        moduleStatus = new ModuleInfoPanel(getFactory(), getBridge(), moduleManager);
    }

    private JSplitPane createLeftPane() {
        ToolComponent moduleTree = new ModuleTree(getFactory(), getBridge(), moduleManager);

        createModuleStatusPanel();

        JSplitPane leftPanel = new JSplitPane(JSplitPane.VERTICAL_SPLIT,
                moduleTree, moduleStatus);
        leftPanel.setOneTouchExpandable(true);
        leftPanel.setDividerLocation(Preferences.getDouble("modulebrowser.graph.divider.location"));
        leftPanel.setResizeWeight(Preferences.getDouble("modulebrowser.graph.divider.resize"));
        return leftPanel;
    }

    
    
}
