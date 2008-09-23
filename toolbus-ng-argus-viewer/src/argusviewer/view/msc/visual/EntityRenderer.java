/**
 *
 */
package argusviewer.view.msc.visual;

import java.awt.BasicStroke;
import java.awt.FontMetrics;
import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.Ellipse2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

import prefuse.Constants;
import prefuse.render.AbstractShapeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.visual.VisualItem;
import argusviewer.view.msc.data.Entity;

/**
 * Renderer for Entities in the Message Sequence Chart.
 * The renderer draws different shapes for the different
 * kind of Entites: Processes and Tools.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Arne Timmerman
 * @author Roberto van der Linden
 */
public class EntityRenderer extends AbstractMSCRenderer {
	public static final double ENTITY_BASESIZE = BASESIZE * 0.7;
	private static final double TEXT_SIZE = 1.1;
	private static final float LINE_WIDTH = (float) 1.5;
	private static final BasicStroke STROKE = new BasicStroke(LINE_WIDTH);

	protected static final int RECTANGLE_WIDTH_MODIFIER = 2;
	protected static final int RECTANGLE_HEIGHT_MODIFIER = 4;
	protected static final double RECTANGLE_ASPECT_RATIO = 1.5;
	protected static final double TEXT_MARGIN = LINE_WIDTH * 6;

	/**
	 * Default Constructor EntityRenderer
	 */
	public EntityRenderer() {
		super();
	}

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item){
		item.setStroke(STROKE);

		Point2D pos = getShapePosition(item);

		double width = ENTITY_BASESIZE * item.getSize();

		if(item.canGet(Entity.TYPE_FIELDNAME, Entity.TYPE_FIELDTYPE)){
			Entity.Type itemType = (Entity.Type) item.get(Entity.TYPE_FIELDNAME);

			switch(itemType){
				case TOOL:
					return getRectangle(pos.getX(), pos.getY(), width);
				case PROCESS:
					return getCircle(pos.getX(), pos.getY(), width);
				case SINK:
					return null;
				default:
					throw new UnsupportedOperationException("Unknown entity type");
			}
		}
		return null;
	}

	/**
	 * {@inheritDoc}
	 */
	protected void drawShape(Graphics2D g, VisualItem item, Shape shape) {
		super.drawShape(g, item, shape);

		drawText(g, item, shape);
	}

	/**
	 * Draws the text on the entity
	 *
	 * @param g Graphics2D used to draw the entity and thus the entity text
	 * @param item Item behind drawn
	 * @param shape Shape
	 */
	private void drawText(Graphics2D g, VisualItem item, Shape shape) {

		int shapeWidth = (int) shape.getBounds().getWidth();

		FontMetrics fm = DEFAULT_GRAPHICS.getFontMetrics(item.getFont());
		int verticalPadding = fm.getHeight();

		// Process Id Text
		LabelRenderer labelRendererProcessId = new LabelRenderer(Entity.ID_FIELDNAME);
		labelRendererProcessId.setMaxTextWidth(shapeWidth - (int) TEXT_MARGIN);
		labelRendererProcessId.setRenderType(AbstractShapeRenderer.RENDER_TYPE_NONE);
		labelRendererProcessId.setVerticalAlignment(Constants.TOP);
		labelRendererProcessId.setVerticalPadding(verticalPadding);

		// Set different size for text
		double oldSize = item.getSize();
		item.setSize(TEXT_SIZE);

		labelRendererProcessId.render(g, item);

		// Process Name Text
		LabelRenderer labelRendererProcessName = new LabelRenderer(Entity.NAME_FIELDNAME);
		labelRendererProcessName.setMaxTextWidth(shapeWidth - (int) TEXT_MARGIN);
		labelRendererProcessName.setRenderType(AbstractShapeRenderer.RENDER_TYPE_NONE);
		labelRendererProcessName.setVerticalAlignment(Constants.CENTER);

		labelRendererProcessName.setVerticalPadding(verticalPadding);
		labelRendererProcessName.render(g, item);

		item.setSize(oldSize);
	}

	/**
	 * Gets a Rectangle with the given position and height. The width will be
	 * calculated using the RECTANGLE_ASPECT_RATIO constant.
	 *
	 * @param x The center x-coordinate of the rectangle
	 * @param y The center y-coordinate of the rectangle
	 * @param width The height of the rectangle
	 * @return A Rectangle shape rounded around a certain x , y
	 */
	protected Rectangle2D getRectangle(double x, double y, double width) {
		double height = width / RECTANGLE_ASPECT_RATIO;

		// Center the rectangle around the specified x and y
		if (height > 1) {
			x -= width / RECTANGLE_WIDTH_MODIFIER;
			y -= height / RECTANGLE_HEIGHT_MODIFIER;
		}

		Rectangle2D rectangleShape = new Rectangle2D.Double();
		rectangleShape.setFrame(x, y, width, height);
		return rectangleShape;
	}

	/**
	 * Gets a Circle with the given position and height (radius).
	 *
	 * @param x The center x-coordinate of the circle
	 * @param y The center x-coordinate of the circle
	 * @param width The width (radius) of the rectangle
	 * @return An Ellipse
	 */
	protected Ellipse2D getCircle(double x, double y, double width) {
		// Center the circle around the specified x and y
		if (width > 1) {
			x -= width / 2;
			y -= width / 2;
		}

		Ellipse2D ellipseShape = new Ellipse2D.Double();
		ellipseShape.setFrame(x, y, width, width);
		return ellipseShape;
	}

}
