package metastudio.components.treebrowser;

import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.io.IOException;

import metastudio.components.graphs.ZoomableGraphPanel;
import metastudio.data.graph.Graph;
import metastudio.data.graph.MetaGraphFactory;
import metastudio.data.graph.Node;
import aterm.ATerm;

public class TreeBrowser extends ZoomableGraphPanel implements TreeBrowserTif, Runnable {
	private TreeBrowserBridge bridge;
	
    public TreeBrowser(final MetaGraphFactory factory, String[] args) {
    	super(factory, "parsetree");

        MouseListener listener = new MouseAdapter() {
        	public void mouseClicked(MouseEvent event) {
        		Node node = getNodeAt(event.getX(), event.getY());
        		if (node != null && bridge != null) {
        			bridge.postEvent(
        					factory.getPureFactory().make(
        							"node-selected(<str>,<term>)",
									getId(),
									node.toTerm()));
        		   setSelectedNode(node);
        		}
        	}
        };
       
        addMouseListener(listener);
        
        try {
        	bridge = new TreeBrowserBridge(factory.getPureFactory(), this);
        	bridge.init(args);
        	bridge.setLockObject(this);
        	bridge.connect("tree-browser", null, -1);
        } catch (IOException e) {
        	e.printStackTrace();
        }
    }

	public void displayTree(ATerm graphTerm) {
	  	Graph graph = factory.GraphFromTerm(graphTerm);
	  	setGraph(graph);
	  	setVisible(true);
	  	getGraphPanel().repaint();
  }
	
	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}

	public void run() {
		bridge.run();
	}
    
    
}
