package metastudio.components;

import java.awt.Color;

import javax.swing.BoxLayout;
import javax.swing.JPanel;
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
    private ModuleStatusPanel moduleStatus;
    private ModuleTreeModel moduleManager;
    private MetaGraphFactory metaGraphFactory;
    
    public ModuleBrowser(ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);
        
        metaGraphFactory = new MetaGraphFactory((PureFactory) factory);
        moduleManager = new ModuleTreeModel();
        
        JPanel left = createLeftPane();

        createModuleGraph();

        JSplitPane moduleBrowser =
        new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, left, importGraphPanel);
        moduleBrowser.setDividerLocation(-1);
        
        add(moduleBrowser);
    }

    private void createModuleGraph() {
        importGraphPanel = new ImportGraphPanel(metaGraphFactory, getBridge(), moduleManager);
        Color color = Preferences.getColor(Preferences.PREF_GRAPHPANE_BACKGROUND);
        importGraphPanel.setBackground(color);
    }
    
    private void createModuleStatusPanel() {
        moduleStatus = new ModuleStatusPanel(getFactory(), getBridge(), moduleManager);
    }

    private JPanel createLeftPane() {
        JPanel leftPanel = new JPanel();
        leftPanel.setLayout(new BoxLayout(leftPanel, BoxLayout.Y_AXIS));

        ToolComponent moduleTree = new ModuleTree(getFactory(), getBridge(), moduleManager);
        leftPanel.add(moduleTree);

        createModuleStatusPanel();
        leftPanel.add(moduleStatus);
        
        return leftPanel;
    }

    
    
}
