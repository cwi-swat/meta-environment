package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.util.Iterator;

import edu.berkeley.guir.prefuse.EdgeItem;
import edu.berkeley.guir.prefuse.ItemRegistry;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.action.assignment.Layout;
import edu.berkeley.guir.prefuse.graph.Graph;

public class GraphDotLayout extends Layout {
	public static final String CURVE_POINTS = "curve-points";
	
	public void run(ItemRegistry registry, double frac) {
		Graph g = registry.getFilteredGraph();
		Iterator nodeIter = g.getNodes();
		while (nodeIter.hasNext()) {
			NodeItem item = (NodeItem) nodeIter.next();
			GraphNode node = (GraphNode) item.getEntity();
			double x = node.getDotX();
			double y = node.getDotY();

			item.setFillColor(node.getFillColor());
			this.setLocation(item, null, x, y);
		}
		
		Iterator edgeIter = g.getEdges();
		while  (edgeIter.hasNext()) {
			EdgeItem item = (EdgeItem) edgeIter.next();
			GraphEdge edge = (GraphEdge) item.getEntity();
			
			item.setFillColor(Color.BLACK);
			item.setVizAttribute(CURVE_POINTS, edge.getDotControlPoints());
		} 
	}
}