package metastudio.components.graphs;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import metastudio.MultiBridge;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import aterm.pure.PureFactory;

public class ParseTreePanel extends ZoomableGraphPanel {
    private GraphPanel panel;
    
    public ParseTreePanel(PureFactory factory, final MultiBridge bridge) {
        super(new MetaGraphFactory(factory), bridge, "parsetree");
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
