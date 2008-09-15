package argusviewer.view.msc.visual;

import java.awt.Polygon;
import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Rectangle2D;
import java.util.ArrayList;
import java.util.Iterator;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.Message;

import prefuse.data.expression.parser.ExpressionParser;
import prefuse.render.AbstractShapeRenderer;
import prefuse.visual.VisualItem;

/**
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Arne Timmerman
 * @author Roberto van der Linden
 *
 *         Renderer for messages passed between entities.
 *         Note that messages are not drawed if one of the entities is invisible.
 */
public class MessageRenderer extends AbstractShapeRenderer {

	private static final int ARROW_WIDTH = 10;
	private static final int SOURCE_BLOCK_WIDTH = 10;
	private static final int ARROW_HEIGHT = 5;

	private GeneralPath m_messageShapes = new GeneralPath();
	private Rectangle2D m_messageSourceBlock = new Rectangle2D.Double();
	private Polygon m_messageArrowHead = new Polygon();
	private GeneralPath m_messageShape = new GeneralPath();
	private Line2D m_messageLine = new Line2D.Double();

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item) {
		ArrayList<Double> targetXPositions = getTargetXPositions(item);
		if (targetXPositions.size() == 0) {
			return null;
		}

		m_messageShapes.reset();
		for (double targetXPos : targetXPositions) {

			// Only create an edge if source and target positions are
			// not located in the sinks
			if ((item.getX() != EntityLayout.INCOMING_SINK_X)
					|| (targetXPos != EntityLayout.getOutgoingSinkX())) {

				Shape messageShape = createEdge(item.getX(), item.getY(), targetXPos);
				m_messageShapes.append(messageShape, false);
			}
		}

		// Refresh the bounding box values for this visual item so Prefuse knows when to invalidate it
		Rectangle edgesBounds = m_messageShapes.getBounds();
		item.setBounds(edgesBounds.getMinX(), edgesBounds.getMinY(), edgesBounds.getWidth(), edgesBounds.getHeight());

		return m_messageShapes;
	}

	/**
	 * Calculate the horizontal position (x coordinate) of the
	 * target processes or tools for a particular message.
	 *
	 * If a target Entity is invisble, this target position will
	 * not be returned.
	 *
	 * @param item The VisualItem representing the message
	 * @return The horizontal position of the target process or tool
	 */
	private ArrayList<Double> getTargetXPositions(VisualItem item) {

		ArrayList<Double> targetXPositions = new ArrayList<Double>();
		ArrayList<String> targetIds = (ArrayList<String>) item.get(Message.TARGETIDS_FIELDNAME);

		// Determine the x coordinates of all the target processes and tools
		for (String targetId : targetIds) {

			String searchPredicateText = "CONCAT(" + Entity.NAME_FIELDNAME + ","
					+ Entity.ID_FIELDNAME + ")" + " == '" + targetId + "'";

			Iterator<VisualItem> matchingEntities = item.getVisualization().items(
					Entity.TABLE_NAME, ExpressionParser.predicate(searchPredicateText));

			if (matchingEntities.hasNext()) {
				VisualItem matchingEntity = matchingEntities.next();

				// Only add target position if the Entity is visible
				if (matchingEntity.isVisible()) {
					targetXPositions.add(new Double(matchingEntity.getX()));
				} else {
					targetXPositions.add(new Double(EntityLayout.getOutgoingSinkX()));
				}
			}
		}

		return targetXPositions;
	}

	/**
	 * Create a directed straight-line edge from the given starting coordinates to
	 * the given end x coordinate. The y coordinate is the same for the start and end point,
	 * which means the edge is always horizontal.
	 *
	 * @param startX The starting x coordinate of the edge
	 * @param yPos The y coordinate of the edge
	 * @param endX The ending x coordinate of the edge
	 * @return The created edge
	 */
	private Shape createEdge(double startX, double yPos, double endX) {
		double halfBlockWidth = SOURCE_BLOCK_WIDTH / 2.0;
		m_messageLine.setLine(
				(endX > startX ? startX + halfBlockWidth : startX - halfBlockWidth),
				yPos,
				(endX > startX ? endX - ARROW_WIDTH - 1 : endX + ARROW_WIDTH + 1),
				yPos
		);

		Polygon edgeArrowHead = createArrowhead(
				(int) endX,
				(int) yPos,
				(endX > startX)
		);

		Rectangle2D edgeSourceBlock = createSourceBlock(startX, yPos);

		m_messageShape.reset();
		m_messageShape.append(edgeSourceBlock, false);
		m_messageShape.append(m_messageLine, false);
		m_messageShape.append(edgeArrowHead, false);

		return m_messageShape;
	}


	/**
	 * Create a source block to put at the begin of an edge.
	 *
	 * @param centerX the center X coordinate of the rectangle.
	 * @param centerY the center Y coordinate of the rectangle.
	 * @return The created source block.
	 */
	private Rectangle2D createSourceBlock(double centerX, double centerY) {
		double halfBlockWidth = SOURCE_BLOCK_WIDTH / 2.0;
		double startX = centerX - halfBlockWidth;
		double startY = centerY - halfBlockWidth;

		m_messageSourceBlock.setRect(startX, startY, SOURCE_BLOCK_WIDTH, SOURCE_BLOCK_WIDTH);
		return m_messageSourceBlock;
	}

	/**
	 * Create an arrowhead to put at the end of an edge. It can either be
	 * a forward arrowhead (from left to right), or a backward arrowhead
	 * (right to left).
	 *
	 * @param x The x coordinate of the tip of the arrowhead
	 * @param y The y coordinate of the tip of the arrowhead
	 * @param forward Whether or not the arrowhead is aimed forward (left to right)
	 * @return The created arrowhead
	 */
	private Polygon createArrowhead(int x, int y, boolean forward) {
		m_messageArrowHead.reset();
		
		if (forward) {
			m_messageArrowHead.addPoint(x - 1, y);
			m_messageArrowHead.addPoint(x - ARROW_WIDTH, y - ARROW_HEIGHT);
			m_messageArrowHead.addPoint(x - ARROW_WIDTH, y + ARROW_HEIGHT);
			m_messageArrowHead.addPoint(x - 1, y);
		} else {
			m_messageArrowHead.addPoint(x + 1, y);
			m_messageArrowHead.addPoint(x + ARROW_WIDTH, y - ARROW_HEIGHT);
			m_messageArrowHead.addPoint(x + ARROW_WIDTH, y + ARROW_HEIGHT);
			m_messageArrowHead.addPoint(x + 1, y);
		}

		return m_messageArrowHead;
	}
}
