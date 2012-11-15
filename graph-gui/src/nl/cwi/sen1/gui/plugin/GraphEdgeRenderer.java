package nl.cwi.sen1.gui.plugin;

import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import prefuse.Constants;
import prefuse.render.EdgeRenderer;
import prefuse.util.GraphicsLib;
import prefuse.visual.EdgeItem;
import prefuse.visual.VisualItem;

public class GraphEdgeRenderer extends EdgeRenderer {
    private static Point2D start = new Point2D.Float();

    private static Point2D end = new Point2D.Float();

    public GraphEdgeRenderer(int edgeType, int arrowType) {
        super(edgeType, arrowType);
    }

    private boolean onDotLocation(VisualItem item) {
        return item.getX() == item.getInt(GraphDotLayout.DOT_X)
                && item.getY() == item.getInt(GraphDotLayout.DOT_Y);
    }

    private Shape makeCurvedEdge(Point2D start, Point2D end, Point2D[] points) {
        Point2D from = start;
        Point2D to = from;

        GeneralPath gp = new GeneralPath(GeneralPath.WIND_NON_ZERO);
        gp.moveTo((float) from.getX(), (float) from.getY());

        int i;
        for (i = 1; i + 2 < points.length; i += 3) {
            Point2D cp1 = points[i];
            Point2D cp2 = points[i + 1];
            Point2D cur = points[i + 2];

            from = cp1;
            to = cur;

            gp.curveTo((float) cp1.getX(), (float) cp1.getY(), (float) cp2
                    .getX(), (float) cp2.getY(), (float) cur.getX(),
                    (float) cur.getY());
        }

        if (i < points.length) {
            from = to;
            to = points[points.length - 1];
            gp.lineTo((float) to.getX(), (float) to.getY());
        }

        gp.lineTo((float) end.getX(), (float) end.getY());

        // TODO: remove this hack that is used to retrieve the last direction of
        // the edge
        start.setLocation(from);
        return gp;
    }

    protected Shape getArrowShape(Point2D start, Point2D end, VisualItem item) {
        Rectangle2D r = item.getBounds();
        int i = GraphicsLib.intersectLineRectangle(start, end, r, m_isctPoints);
        if (i > 0) {
            end = m_isctPoints[0];
        }
        AffineTransform at = getArrowTrans(start, end, 1);
        return at.createTransformedShape(m_arrowHead);
    }

    protected Shape getRawShape(VisualItem item) {
        EdgeItem edge = (EdgeItem) item;
        VisualItem item1 = edge.getSourceItem();
        VisualItem item2 = edge.getTargetItem();

        // If the nodes are not on their original dot positions, the curved
        // edge degenerates to a straight edge.
        if (!onDotLocation(item1) || !onDotLocation(item2)) {
            return super.getRawShape(item);
        }

        // Find the middle of the start and end nodes
        getAlignedPoint(start, item1.getBounds(), Constants.CENTER, Constants.CENTER);
        getAlignedPoint(end, item2.getBounds(), Constants.CENTER, Constants.CENTER);

        // Retrieve the dot curve points data
        Point2D[] points = (Point2D[]) item.get(GraphDotLayout.CURVE_POINTS);
        if (points == null) {
            return super.getRawShape(item);
        }

        
        // now construct the curved edge
        Shape shape = makeCurvedEdge(start, end, points);
        AffineTransform at = getTransform(item);
        shape = (at == null) ? shape : at.createTransformedShape(shape);

        // create the arrow head, if needed
        Shape arrow = getArrowShape(start, end, item2);
        setRenderType(RENDER_TYPE_DRAW_AND_FILL);
        m_curArrow = arrow;

        setRenderType(RENDER_TYPE_DRAW);
        return shape;
    }
}