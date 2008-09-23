package argusviewer.view.architectureview;

import java.awt.BasicStroke;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;

import prefuse.visual.VisualItem;

/**
 * Renderer for Processes and Tools.
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 */
public class ProcessRenderer extends AbstractArchitectureRenderer {
	public static final double PROCESS_BASESIZE = BASESIZE * 0.5;
	private static final float LINE_WIDTH = (float) 1.5;
	private static final BasicStroke STROKE = new BasicStroke(LINE_WIDTH);

	protected static final int RECTANGLE_WIDTH_MODIFIER = 2;
	protected static final int RECTANGLE_HEIGHT_MODIFIER = 4;
	protected static final double RECTANGLE_ASPECT_RATIO = 1.5;
	protected static final double TEXT_MARGIN = LINE_WIDTH * 6;
	
	/**
	 * Default Constructor ProcessRenderer
	 */
	public ProcessRenderer() {
		super();
	}

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item) {
		item.setStroke(STROKE);

		Point2D pos = getShapePosition(item);

		double width = PROCESS_BASESIZE * item.getSize();

		return getCircle(pos.getX(), pos.getY(), width);
	}

	/**
	 * Gets a Circle with the given position and height (radius).
	 *
	 * @param x	 The center x-coordinate of the circle
	 * @param y	 The center x-coordinate of the circle
	 * @param width The width (radius) of the rectangle
	 * @return An Ellipse
	 */
	protected Ellipse2D getCircle(double x, double y, double width) {
		Ellipse2D ellipse = new Ellipse2D.Double();

		// Center the circle around the specified x and y
		if (width > 1) {
			x -= width / 2;
			y -= width / 2;
		}

		ellipse.setFrame(x, y, width, width);

		return ellipse;
	}

}
