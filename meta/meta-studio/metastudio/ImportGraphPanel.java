package metastudio;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import metastudio.graph.Node;
import aterm.ATermFactory;

public class ImportGraphPanel extends ZoomableGraphPanel implements ModuleSelectionListener {
    private GraphPanel panel;
    
    public ImportGraphPanel(ATermFactory factory, UserInterfaceBridge bridge, final ModuleTreeModel moduleManager) {
        super(factory, bridge, "import");
        
        panel = getGraphPanel();
        System.err.println(((Object) panel));
       
        moduleManager.addModuleSelectionListener(this);

        MouseListener listener = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                System.err.println("hier is geklikt");
                Node node = panel.getNodeAt(event.getX(), event.getY());
                if (node != panel.getSelectedNode()) {
                    System.err.println("hier niet");
                    Module module;
                    if (node == null) {
                        module = null;
                    } else {
                        module = moduleManager.getModule(node.getName());
                    }
                    moduleManager.selectModule(module);
                }
            }
        };
        panel.addMouseListener(listener);
    }

    public void moduleSelected(Module module) {
        if (module == null) {
            panel.setSelectedNode(null);
        } else {
            panel.setSelectedNode(panel.getNode(module.getName()));
        }
    }
}
