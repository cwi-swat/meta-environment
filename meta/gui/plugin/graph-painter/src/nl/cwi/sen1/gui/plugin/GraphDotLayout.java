package nl.cwi.sen1.gui.plugin;

import java.awt.geom.Rectangle2D;
import java.util.Iterator;

import edu.berkeley.guir.prefuse.ItemRegistry;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.action.assignment.Layout;
import edu.berkeley.guir.prefuse.graph.Graph;

public class GraphDotLayout extends Layout {

	public void run(ItemRegistry registry, double frac) {
		Graph g = registry.getFilteredGraph();

		int nn = g.getNodeCount();

		Rectangle2D r = super.getLayoutBounds(registry);
		double height = r.getHeight();
		double width = r.getWidth();
		double cx = r.getCenterX();
		double cy = r.getCenterY();

		Iterator nodeIter = g.getNodes();
		while (nodeIter.hasNext()) {
			NodeItem n = (NodeItem) nodeIter.next();
			double x = new Double(n.getAttribute("dot.x")).doubleValue();
			double y = new Double(n.getAttribute("dot.y")).doubleValue();
			this.setLocation(n, null, x, y);
		}
		
	}

}