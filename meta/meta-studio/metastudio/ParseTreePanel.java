package metastudio;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import metastudio.graph.MetaGraphFactory;
import metastudio.graph.Node;

public class ParseTreePanel extends ZoomableGraphPanel {
    private GraphPanel panel;
    
    public ParseTreePanel(MetaGraphFactory factory, final UserInterfaceBridge bridge) {
        super(factory.getPureFactory(),bridge,"parsetree");
        this.panel = getGraphPanel();
        
        MouseListener listener = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                Node node = panel.getNodeAt(event.getX(), event.getY());
                if (node != panel.getSelectedNode()) {
                    if (node != null) {
                        if (node.hasInfo("message")) {
                            bridge.postEvent(node.getInfo("message"));
                        }
                        panel.setSelectedNode(node);
                    }
                }
            }
        };
        panel.addMouseListener(listener);
    }
}
