package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import prefuse.render.AbstractShapeRenderer;
import prefuse.visual.VisualItem;

public class DotNodeRenderer extends AbstractShapeRenderer {
	private Rectangle2D box = new Rectangle2D.Double();

	private Ellipse2D ellipse = new Ellipse2D.Double();

	private Point2D intersection[] = new Point2D[2];

	public DotNodeRenderer() {
		super();
		intersection[0] = new Point2D.Float();
		intersection[1] = new Point2D.Float();
		System.err.println("Init DotNodeRenderer");
	}

	

	public Shape getRawShape(VisualItem item) {
		Rectangle2D bounds = ((Rectangle2D) item.get(VisualItem.BOUNDS))
				.getFrame();
		double x = item.getX();
		double y = item.getY();
		double w = bounds.getWidth();
		double h = bounds.getHeight();
		String shapeName = item.getString(DotAdapter.DOT_SHAPE);
		Shape result;

		// TODO: implement diamond and other shapes
		if (shapeName != null) {
			if (shapeName.equals("box")) {
				result = getBoxShape(x, y, w, h);
			} else if (shapeName.equals("circle")) {
				result = getCircleShape(x, y, w, h);
			} else if (shapeName.equals("ellipse")) {
				result = getEllipseShape(x, y, w, h);
			} else {
				result = getBoxShape(x, y, w, h);
			}
		} else {
			result = getBoxShape(x, y, w, h);
		}

		return result;
	}

	private Shape getBoxShape(double x, double y, double width, double height) {
		box.setFrame(x, y, width, height);
		return box;
	}

	private Shape getCircleShape(double x, double y, double width, double height) {
		double radius = Math.max(width, height);
		ellipse.setFrame(x, y, radius, radius);
		return ellipse;
	}

	private Shape getEllipseShape(double x, double y, double width,
			double height) {
		ellipse.setFrame(x, y, width, height);
		return ellipse;
	}

}