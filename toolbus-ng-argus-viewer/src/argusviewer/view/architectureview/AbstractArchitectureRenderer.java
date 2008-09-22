package argusviewer.view.architectureview;

import java.awt.geom.Point2D;

import prefuse.render.AbstractShapeRenderer;
import prefuse.visual.VisualItem;

/**
 * 
 * @author John Franse
 * @author Tigran Kalaidjan
 *
 * AbstractRenderer
 * 
 */
public abstract class AbstractArchitectureRenderer extends AbstractShapeRenderer {
	public static final int BASESIZE = 100;

	/**
	 * Get the x and y coordinate where the shape for a VisualItem should be
	 * drawn.
	 * 
	 * @param item
	 *            The VisualItem to be drawn
	 * @return The x and y coordinate
	 */
	protected Point2D getShapePosition(VisualItem item) {
		double xPos = item.getX();
		if (Double.isNaN(xPos) || Double.isInfinite(xPos)) {
			xPos = 0;
		}
		double yPos = item.getY();
		if (Double.isNaN(yPos) || Double.isInfinite(yPos)) {
			yPos = 0;
		}

		return new Point2D.Double(xPos, yPos);
	}
}
