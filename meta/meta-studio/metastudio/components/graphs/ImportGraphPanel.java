package metastudio.components.graphs;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import javax.swing.JComponent;
import javax.swing.SwingUtilities;

import metastudio.UserInterfaceBridge;
import metastudio.components.ModulePopupMenu;
import metastudio.components.ModuleSelectionListener;
import metastudio.data.Module;
import metastudio.data.ModuleTreeModel;
import metastudio.data.graph.Node;
import aterm.ATermFactory;

public class ImportGraphPanel
    extends ZoomableGraphPanel
    implements ModuleSelectionListener {
    private GraphPanel panel;

    public ImportGraphPanel(
        ATermFactory factory,
        UserInterfaceBridge bridge,
        final ModuleTreeModel moduleManager) {
        super(factory, bridge, "import");

        panel = getGraphPanel();

        moduleManager.addModuleSelectionListener(this);

        panel.addMouseListener(makeMouseListener(moduleManager));
    }

    private MouseListener makeMouseListener(final ModuleTreeModel moduleManager) {
        MouseListener listener = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                Node node = panel.getNodeAt(event.getX(), event.getY());
                ModulePopupMenu.setPopupLocation(
                    (JComponent) event.getSource(),
                    event.getX(),
                    event.getY());

                Module module;

                if (node == null) {
                    module = null;
                } else {
                    module = moduleManager.getModule(node.getLabel());
                    if (event.isPopupTrigger()
                        || SwingUtilities.isRightMouseButton(event)) {
                        postEvent(
                            getFactory().make(
                                "get-buttons(module-popup,<str>)",
                                node.getLabel()));
                    }

                }
                moduleManager.selectModule(module);
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
