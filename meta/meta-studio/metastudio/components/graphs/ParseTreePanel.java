package metastudio.components.graphs;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;

import metastudio.MultiBridge;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import aterm.pure.PureFactory;

public class ParseTreePanel extends ZoomableGraphPanel {
    private static final String PARSETREE = "parsetree";
    private GraphPanel panel;
    
    public ParseTreePanel(final PureFactory factory, final MultiBridge bridge) {
        super(new MetaGraphFactory(factory), bridge, PARSETREE);
        this.panel = getGraphPanel();
        
        MouseListener listener = new MouseAdapter() {
            public void mouseClicked(MouseEvent event) {
                Node node = panel.getNodeAt(event.getX(), event.getY());
		if (node != null) {
		    bridge.postEvent(factory.make("node-selected(<str>,<term>)", getId(), node.toTerm()));
		    panel.setSelectedNode(node);
		}
	    }
	};
        panel.addMouseListener(listener);
    }
}
