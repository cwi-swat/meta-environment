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
       
        moduleManager.addModuleSelectionListener(this);

        panel.addMouseListener(makeMouseListener(moduleManager));
    }

    private MouseListener makeMouseListener(final ModuleTreeModel moduleManager) {
        MouseListener listener = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                Node node = panel.getNodeAt(event.getX(), event.getY());
                if (node != panel.getSelectedNode()) {
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
        return listener;
    }

    public void moduleSelected(Module module) {
        if (module == null) {
            panel.setSelectedNode(null);
        } else {
            panel.setSelectedNode(panel.getNode(module.getName()));
        }
    }
}
