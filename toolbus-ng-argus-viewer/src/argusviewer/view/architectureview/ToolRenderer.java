package argusviewer.view.architectureview;

import java.awt.BasicStroke;
import java.awt.Shape;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.Iterator;

import prefuse.Visualization;
import prefuse.data.Tuple;
import prefuse.data.tuple.TupleSet;
import prefuse.visual.VisualItem;

/**
 * Renderer for Tools.
 * 
 * @author Ivo Tamboer
 * @author Frank Oppedijk
 * 
 * 
 */
public class ToolRenderer extends AbstractArchitectureRenderer {

	public static final double TOOL_BASESIZE = BASESIZE * 0.5;
	private static final float LINE_WIDTH = (float) 1.5;
	private static final BasicStroke STROKE = new BasicStroke(LINE_WIDTH);
	//private LabelRenderer m_labelRendererToolName;

	protected static final int RECTANGLE_WIDTH_MODIFIER = 2;
	protected static final int RECTANGLE_HEIGHT_MODIFIER = 4;
	protected static final double RECTANGLE_ASPECT_RATIO = 1.5;
	protected static final double TEXT_MARGIN = LINE_WIDTH * 6;

	/**
	 * Default Constructor ToolRenderer
	 */
	public ToolRenderer() {
		super();
	}

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item) {

		item.setStroke(STROKE);

		Point2D pos = getShapePosition(item);

		double width = TOOL_BASESIZE * item.getSize();

		GeneralPath shape = new GeneralPath();
		shape.append(getRectangle(pos.getX(), pos.getY(), width), false);
		shape.append(getLine(item), false);
		return shape;
	}

	/**
	 * Gets a Circle with the given position and height (radius).
	 *
	 * @param x	 The center x-coordinate of the circle
	 * @param y	 The center x-coordinate of the circle
	 * @param width The width (radius) of the rectangle
	 * @return An Ellipse
	 */
	protected Rectangle2D getRectangle(double x, double y, double width) {

		Rectangle2D rectangle = new Rectangle2D.Double();

		// Center the circle around the specified x and y
		if (width > 1) {
			x -= width / 2;
			y -= width / 2;
		}

		rectangle.setFrame(x, y, width, width);

		return rectangle;
	}
	
	private Line2D getLine(VisualItem item) {
		
		Line2D line = new Line2D.Double();
		Visualization vis = item.getVisualization();
		
		TupleSet toolbusSingleton = vis.getVisualGroup(ToolbusSingleton.TABLE_NAME);
		Iterator<Tuple> toolbusSingletonIterator = toolbusSingleton.tuples();
		if (toolbusSingletonIterator.hasNext()) {
			VisualItem singleton = vis.getVisualItem(ToolbusSingleton.TABLE_NAME, toolbusSingletonIterator.next());
			
			double halfItemWidth = TOOL_BASESIZE * item.getSize() / 2;
			double x = item.getX();
			double topY = singleton.getBounds().getMaxY();
			double bottomY = item.getY() - halfItemWidth;
			line.setLine(x, topY, x, bottomY);
		}
		return line;
	}
}
