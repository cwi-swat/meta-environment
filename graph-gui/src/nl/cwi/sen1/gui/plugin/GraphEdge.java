package nl.cwi.sen1.gui.plugin;

import java.awt.geom.Point2D;

import edu.berkeley.guir.prefuse.graph.DefaultEdge;
import edu.berkeley.guir.prefuse.graph.Node;

public class GraphEdge extends DefaultEdge {
	protected Point2D[] dotControlPoints;
	
	public GraphEdge(Node n1, Node n2) {
		super(n1, n2, true);
	}

	public void setDotControlPoints(Point2D[] cp) {
		dotControlPoints = cp;
	}
	
	public Point2D[] getDotControlPoints() {
		return dotControlPoints;
	}
}
