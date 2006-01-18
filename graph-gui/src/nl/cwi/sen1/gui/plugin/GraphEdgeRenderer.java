package nl.cwi.sen1.gui.plugin;

import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import edu.berkeley.guir.prefuse.EdgeItem;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.VisualItem;
import edu.berkeley.guir.prefuse.render.DefaultEdgeRenderer;
import edu.berkeley.guir.prefuse.render.Renderer;
import edu.berkeley.guir.prefuse.util.GeometryLib;

public class GraphEdgeRenderer extends DefaultEdgeRenderer {
	private static Point2D start = new Point2D.Float();
	private static Point2D end = new Point2D.Float();
	
	private boolean onDotLocation(NodeItem item) {
		GraphNode node = (GraphNode) item.getEntity();
		return item.getX() == node.getDotX() && item.getY() == node.getDotY(); 
	}
	
	private Shape makeCurvedEdge(Point2D start, Point2D end, Point2D[] points) {
		Point2D from = start;
		Point2D to = from;
		
		GeneralPath gp = new GeneralPath(GeneralPath.WIND_NON_ZERO);
		gp.moveTo((float) from.getX(), (float) from.getY());

		int i;
		for (i = 1; i + 2 < points.length; i += 3) {
			Point2D cp1 = points[i];
			Point2D cp2 = points[i+1];
			Point2D cur = points[i+2];

			from = cp1;
			to = cur;

			gp.curveTo((float) cp1.getX(), (float) cp1.getY(), (float) cp2.getX(), 
					(float) cp2.getY(), (float) cur.getX(), (float) cur.getY());
		}

		if (i < points.length) {
			from = to;
			to = points[points.length - 1];
			gp.lineTo((float) to.getX(), (float) to.getY());
		}
		
		gp.lineTo((float) end.getX(), (float) end.getY());
		
		// TODO: remove this hack that is used to retrieve the last direction of the edge
		start.setLocation(from);
		return gp;
	} 
	
	protected Shape getArrowShape(Point2D start, Point2D end, VisualItem item) {
		Rectangle2D r = item.getBounds();
		int i = GeometryLib.intersectLineRectangle(start, end, r, m_isctPoints);
		if ( i > 0 ) {
			end = m_isctPoints[0];
		}
		AffineTransform at = getArrowTrans(start, end, 1);
        return at.createTransformedShape(m_arrowHead);
	}
	
	public void render(Graphics2D g, VisualItem item) {
		EdgeItem   edge = (EdgeItem)item;
		VisualItem fromItem = (VisualItem)edge.getFirstNode();
		VisualItem toItem = (VisualItem)edge.getSecondNode();
		Renderer nodeRenderer = fromItem.getRenderer();
		
		// If the nodes are not on their original dot positions, the curved
		// edge degenerates to a straight edge.
		if (!onDotLocation((NodeItem) fromItem) || !onDotLocation((NodeItem) toItem)) {
			super.render(g, item);
			return;
		}
		
		
		// Find the middle of the start and end nodes
		getAlignedPoint(start,
				nodeRenderer.getBoundsRef(fromItem),ALIGNMENT_CENTER,ALIGNMENT_CENTER);
		
		getAlignedPoint(end, 
				nodeRenderer.getBoundsRef(toItem),ALIGNMENT_CENTER,ALIGNMENT_CENTER);

		// Retrieve the dot curve points data
		Point2D[] points = (Point2D[]) item.getVizAttribute(GraphDotLayout.CURVE_POINTS);
		if (points == null) {
			super.render(g, item);
			return;
		}
		
		// now construct the curved edge
		Shape shape = makeCurvedEdge(start, end, points);
		AffineTransform at = getTransform(item);
		shape = (at == null) ? shape : at.createTransformedShape(shape);
		
		setRenderType(RENDER_TYPE_DRAW);
		drawShape(g, item, shape);
		
		Shape arrow = getArrowShape(start, end, toItem);
		setRenderType(RENDER_TYPE_DRAW_AND_FILL);
		drawShape(g, item, arrow);
	}
}
