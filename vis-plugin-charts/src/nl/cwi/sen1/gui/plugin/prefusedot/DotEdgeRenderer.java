package nl.cwi.sen1.gui.plugin.prefusedot;

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

public class DotEdgeRenderer extends EdgeRenderer {
	protected static Point2D start = new Point2D.Float();
	protected static Point2D end = new Point2D.Float();

	public DotEdgeRenderer(int edgeType, int arrowType) {
		super(edgeType, arrowType);
	}

	protected boolean onDotLocation(VisualItem item) {
		return item.getX() == item.getInt(DotAdapter.DOT_X)
				&& item.getY() == item.getInt(DotAdapter.DOT_Y);
	}

	protected Shape makeCurvedEdge(Point2D start, Point2D end, Point2D[] points) {
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

		// TODO: remove this hack that is used to retrieve the last
		// direction of
		// the edge
		start.setLocation(from);
		

		return gp;
	}

	protected Shape getArrowShape(Point2D start, Point2D end, VisualItem item) {
		int i = getIntersectionPoint(item, start, end, m_isctPoints);
		Point2D e = end;
		if (i > 0) {
			e = m_isctPoints[0];
		}
		AffineTransform at = getArrowTrans(start, e, 1);
		return at.createTransformedShape(m_arrowHead);
	}

	protected static void getAlignedPoint(Point2D p, Rectangle2D r, int xAlign,
			int yAlign) {
		double x = r.getX(), y = r.getY(), w = r.getWidth(), h = r.getHeight();
		if (xAlign == Constants.CENTER) {
			x = x + (w / 2);
		} else if (xAlign == Constants.RIGHT) {
			x = x + w;
		}
		if (yAlign == Constants.CENTER) {
			y = y + (h / 2);
		} else if (yAlign == Constants.BOTTOM) {
			y = y + h;
		}
		p.setLocation(x, y);
	}

	/**
	 * @copy super.getRawShape() but with support for arrows to different shapes than boxes,
	 * and without support for prefuse's curved edges.
	 */
	protected Shape getStraightEdge(VisualItem item) {
		EdgeItem edge = (EdgeItem) item;
		VisualItem item1 = edge.getSourceItem();
		VisualItem item2 = edge.getTargetItem();

		getAlignedPoint(m_tmpPoints[0], item1.getBounds(), m_xAlign1, m_yAlign1);
		getAlignedPoint(m_tmpPoints[1], item2.getBounds(), m_xAlign2, m_yAlign2);
		m_curWidth = (float) (m_width * getLineWidth(item));

		// create the arrow head, if needed
		EdgeItem e = (EdgeItem) item;
		if (e.isDirected() && m_edgeArrow != Constants.EDGE_ARROW_NONE) {
			Shape arrow = getArrowShape(m_tmpPoints[0], m_tmpPoints[1], item2);
			setRenderType(RENDER_TYPE_DRAW_AND_FILL);
			m_curArrow = arrow;
		} else {
			m_curArrow = null;
		}

		// create the edge shape
		Shape shape = null;
		double n1x = m_tmpPoints[0].getX();
		double n1y = m_tmpPoints[0].getY();
		double n2x = m_tmpPoints[1].getX();
		double n2y = m_tmpPoints[1].getY();
		m_line.setLine(n1x, n1y, n2x, n2y);
		shape = m_line;

		// return the edge shape
		return shape;
	}

	protected Shape getRawShape(VisualItem item) {
		EdgeItem edge = (EdgeItem) item;
		VisualItem item1 = edge.getSourceItem();
		VisualItem item2 = edge.getTargetItem();

		// If the nodes are not on their original dot positions, the curved
		// edge degenerates to a straight edge.
		if (!onDotLocation(item1) || !onDotLocation(item2)) {
			return getStraightEdge(item);
		}

		// Find the middle of the start and end nodes
		getAlignedPoint(start, item1.getBounds(), Constants.CENTER,
				Constants.CENTER);
		getAlignedPoint(end, item2.getBounds(), Constants.CENTER,
				Constants.CENTER);

		// Retrieve the dot curve points data
		Point2D[] points = (Point2D[]) item.get(DotAdapter.DOT_CURVE_POINTS);
		if (points == null) {
			return getStraightEdge(item);
		}

		// now construct the curved edge
		Shape shape = makeCurvedEdge(start, end, points);
		AffineTransform at = getTransform(item);
		shape = (at == null) ? shape : at.createTransformedShape(shape);

		// create the arrow head, if needed
		// TODO: fix this hack that takes care of arrow size offsets
		end.setLocation(end.getX(), end.getY() - m_arrowHeight);
		Shape arrow = getArrowShape(start, end, item2);
		setRenderType(RENDER_TYPE_DRAW_AND_FILL);
		m_curArrow = arrow;

		setRenderType(RENDER_TYPE_DRAW);
		return shape;
	}

	protected int getIntersectionPoint(VisualItem item, Point2D from, Point2D to,
			Point2D[] intersection) {
		String shapeName = item.getString(DotAdapter.DOT_SHAPE);
		int i;

		if (shapeName != null) {
			if (shapeName.equals("box")) {
				i = computeBoxIntersectionPoint(item, from, to, intersection);
			} else if (shapeName.equals("circle")) {
				i = computeCircleIntersectionPoint(item, from, to, intersection);
			} else if (shapeName.equals("ellipse")) {
				i = computeEllipseIntersectionPoint(item, from, to,
						intersection);
			} else {
				i = computeBoxIntersectionPoint(item, from, to, intersection);
			}
		} else {
			i = computeBoxIntersectionPoint(item, from, to, intersection);
		}

		return i;
	}

	protected int computeEllipseIntersectionPoint(VisualItem item, Point2D from,
			Point2D to, Point2D[] intersection) {
		int i = computeBoxIntersectionPoint(item, from, to, intersection);
		Rectangle2D bounds = item.getBounds();
		float x = (float) (intersection[0].getX() - bounds.getCenterX());
		float y = (float) (intersection[0].getY() - bounds.getCenterY());
		float xrad = (float) (bounds.getWidth() / 2);
		float yrad = (float) (bounds.getHeight() / 2);
		float phi = x != 0 ? (float) Math.atan(Math
				.abs((y / yrad) / (x / xrad))) : 0;
		x = (float) Math.cos(phi) * xrad * (x < 0 ? -1 : 1);
		y = (float) Math.sin(phi) * yrad * (y < 0 ? -1 : 1);
		intersection[0].setLocation(x + bounds.getCenterX(), y
				+ bounds.getCenterY());
		return i;
	}

	protected int computeCircleIntersectionPoint(VisualItem item, Point2D from,
			Point2D to, Point2D[] intersection) {
		return computeEllipseIntersectionPoint(item, from, to, intersection);
	}

	protected int computeBoxIntersectionPoint(VisualItem item, Point2D from,
			Point2D to, Point2D[] intersection) {
		int i = GraphicsLib.intersectLineRectangle(from, to, item.getBounds(),
				intersection);
		return i;
	}
}