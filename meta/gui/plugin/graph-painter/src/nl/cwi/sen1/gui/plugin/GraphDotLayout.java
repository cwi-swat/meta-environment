package nl.cwi.sen1.gui.plugin;

import java.util.Iterator;

import edu.berkeley.guir.prefuse.ItemRegistry;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.action.assignment.Layout;
import edu.berkeley.guir.prefuse.graph.Graph;

public class GraphDotLayout extends Layout {
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

	}
}