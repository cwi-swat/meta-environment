package argusviewer.view.msc.visual;

import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.GeneralPath;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.awt.geom.RoundRectangle2D;
import java.util.ArrayList;
import java.util.logging.Logger;

import prefuse.render.AbstractShapeRenderer;
import prefuse.render.LabelRenderer;
import prefuse.visual.VisualItem;
import toolbus.StateElement;
import argusviewer.view.msc.data.Statement;

/**
 * Renderer for Statements in the Message Sequence Chart.
 * The renderer draws different shapes for different kind
 * of statements, i.e. asynchronous communication.
 *
 * @author Johnny Eradus
 * @author Riccardo Lippolis
 * @author Roberto van der Linden
 * @author Arne Timmerman
 */
public class StatementRenderer extends AbstractMSCRenderer {
	private static final int ROUND_RECTANGLE_ARC = 10;

	private static final int PARALLELOGRAM_MARGIN = 4;
	private static final int TEXT_MARGIN = 10;
	private static final int TEXT_SIZE = 1;

	private static final int RECTANGLE_HEIGHT = 20;
	private static final int RECTANGLE_WIDTH = 100;

	/**
	 * Default Constructor
	 */
	public StatementRenderer() {
		super();
	}

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item) {
		if (item.canGet(Statement.STATEMENT_FIELDNAME, Statement.STATEMENT_FIELDTYPE)) {
			double width;

			String statement = (String) item.get(Statement.STATEMENT_FIELDNAME);

			Point2D position = getShapePosition(item);
			try {
				width = BASESIZE * item.getSize();
			} catch (ArrayIndexOutOfBoundsException e) {
				Logger.getLogger("StatementRenderer").fine("Prefuse nonfatal ArrayIndexOutOfBoundsException");
				Logger.getLogger("StatementRenderer").fine(e.toString());
				return null;
			}

			if (isASyncCommunication(statement)) {
				return getParallelogram(position.getX(), position.getY(), width);
			} else if (isSyncCommunication(statement)) {
				return getSixCorneredShape(position.getX(), position.getY(), width);
			} else if (isToolCommunication(statement)) {
				return getRoundRectangle(position.getX(), position.getY());
			} else {
				return getRectangle(position.getX(), position.getY());
			}
		}
		return null;
	}

	/**
	 * Return a shape for a Rectangle at the given coordinates.
	 * @param x the center horizontal coordinate to draw the shape
	 * @param y the center vertical coordinate to draw the shape
	 * @return a shape object at the given coordinates
	 */
	private Shape getRectangle(double x, double y) {
		double xPos = x - RECTANGLE_WIDTH / 2;
		double yPos = y - RECTANGLE_HEIGHT / 2;

		Rectangle2D rectangleShape = new Rectangle2D.Double();
		rectangleShape.setFrame(xPos, yPos, RECTANGLE_WIDTH, RECTANGLE_HEIGHT);
		return rectangleShape;
	}

	/**
	 * Return a shape for a rounded Rectangle at the given coordinates.
	 * @param x the center horizontal coordinate to draw the shape
	 * @param y the center vertical coordinate to draw the shape
	 * @return a shape object at the given coordinates
	 */
	private Shape getRoundRectangle(double x, double y) {
		double xPos = x - RECTANGLE_WIDTH / 2;
		double yPos = y - RECTANGLE_HEIGHT / 2;

		RoundRectangle2D roundRectangleShape = new RoundRectangle2D.Double();
		roundRectangleShape.setRoundRect(xPos, yPos, RECTANGLE_WIDTH, RECTANGLE_HEIGHT, ROUND_RECTANGLE_ARC, ROUND_RECTANGLE_ARC);
		return roundRectangleShape;
	}

	/**
	 * Return a shape for a Parallelogram with the specified width at the given coordinates.
	 * @param x the center horizontal coordinate to draw the shape
	 * @param y the center vertical coordinate to draw the shape
	 * @param width the width of the shape
	 * @return a shape object at the given coordinates
	 */
	private Shape getParallelogram(double x, double y, double width) {
		float fx = (float) x;
		float fy = (float) y;
		float fwidth = (float) width;

		// Calculate starting X Y
		float fStartingX = fx - (fwidth / 2);
		float fStartingY = fy - (RECTANGLE_HEIGHT / 2);

		GeneralPath parallelogramShape = new GeneralPath();
		parallelogramShape.moveTo(fStartingX, fStartingY);
		parallelogramShape.lineTo(fStartingX + fwidth + PARALLELOGRAM_MARGIN, fStartingY);
		parallelogramShape.lineTo(fStartingX + fwidth, fStartingY + RECTANGLE_HEIGHT);
		parallelogramShape.lineTo(fStartingX - PARALLELOGRAM_MARGIN, fStartingY + RECTANGLE_HEIGHT);
		parallelogramShape.lineTo(fStartingX, fStartingY);

		return parallelogramShape;
	}

	/**
	 * Return a shape with six surfaces with the specified width at the given coordinates.
	 * @param x the center horizontal coordinate to draw the shape
	 * @param y the center vertical coordinate to draw the shape
	 * @param width the width of the shape
	 * @return a shape object at the given coordinates
	 */
	private Shape getSixCorneredShape(double x, double y, double width) {
		float fx = (float) x;
		float fy = (float) y;
		float fwidth = (float) width;

		// Calculate starting X Y
		float fStartingX = fx - (fwidth / 2);
		float fStartingY = fy - (RECTANGLE_HEIGHT / 2);
		float fHalfHeigth = RECTANGLE_HEIGHT / 2;

		GeneralPath sixCorneredShape = new GeneralPath();
		sixCorneredShape.moveTo(fStartingX, fStartingY);
		sixCorneredShape.lineTo(fStartingX + fwidth, fStartingY);
		sixCorneredShape.lineTo(fStartingX + fwidth + PARALLELOGRAM_MARGIN, fStartingY
				+ fHalfHeigth);
		sixCorneredShape.lineTo(fStartingX + fwidth, fStartingY + RECTANGLE_HEIGHT);
		sixCorneredShape.lineTo(fStartingX, fStartingY + RECTANGLE_HEIGHT);
		sixCorneredShape.lineTo(fStartingX - PARALLELOGRAM_MARGIN, fStartingY
				+ fHalfHeigth);
		sixCorneredShape.lineTo(fStartingX, fStartingY);

		return sixCorneredShape;
	}

	/**
	 * @param statement the statement to question if it belongs to tool communication
	 * @return true if the statement belongs to tool communication, else false
	 */
	private boolean isToolCommunication(String statement) {
		return isStatementOfType(statement, Statement.TOOL_COMMUNICATION);
	}

	/**
	 * @param statement the statement to question if it belongs to synchronized communication
	 * @return true if the statement belongs to synchronized communication, else false
	 */
	private boolean isSyncCommunication(String statement) {
		return isStatementOfType(statement, Statement.SYNC_COMMUNICATION);
	}

	/**
	 * @param statement the statement to question if it belongs to asynchronuous communication
	 * @return true if the statement belongs to asynchronuous communication, else false
	 */
	private boolean isASyncCommunication(String statement) {
		return isStatementOfType(statement, Statement.ASYNC_COMMUNICATION);
	}

	/**
	 * Compares the given statement to the list of statement types
	 * to find out if the statement is of the type asked for.
	 *
	 * @param statement	  the name of the statement
	 * @param statementTypes the list of statement types
	 * @return true if the statement belongs to the given type, else false
	 */
	private boolean isStatementOfType(String statement, ArrayList<Class< ? extends StateElement>> statementTypes) {
		for (Class< ? extends StateElement> statementType : statementTypes) {
			if (statement.toLowerCase().startsWith(statementType.getSimpleName().toLowerCase())) {
				return true;
			}
		}
		return false;
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
	 * @param g	 Graphics2D used to draw the entity and thus the entity text
	 * @param item  Item being drawn
	 * @param shape Shape
	 */
	private void drawText(Graphics2D g, VisualItem item, Shape shape) {
		int shapeWidth = (int) shape.getBounds().getWidth();

		// Statement Text
		LabelRenderer labelRenderer = new LabelRenderer(Statement.STATEMENT_FIELDNAME);
		labelRenderer.setMaxTextWidth(shapeWidth - TEXT_MARGIN);
		labelRenderer.setRenderType(AbstractShapeRenderer.RENDER_TYPE_NONE);

		// Set different size for text
		double oldSize = item.getSize();
		item.setSize(TEXT_SIZE);

		labelRenderer.render(g, item);

		item.setSize(oldSize);
	}
}
