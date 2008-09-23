package argusviewer.view.msc.visual;

import prefuse.Visualization;
import prefuse.data.Tuple;
import prefuse.visual.VisualItem;

import java.awt.Graphics2D;
import java.awt.Shape;
import java.awt.geom.GeneralPath;
import java.awt.geom.Line2D;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;
import java.util.LinkedList;
import argusviewer.view.msc.data.Entity;
import argusviewer.view.msc.data.MSCData;
import argusviewer.view.msc.data.Statement;

/**
 * Renderer for the vertical swimlanes for processes and tools.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author John Franse
 * @author Tigran Kalaidjan
 * @author Hidde Baggelaar
 * @author Arne Timmerman
 * @author Roberto van der Linden
 */
public class SwimlaneRenderer extends AbstractMSCRenderer {
	private static final String COLLAPSE_TEXT = "...";
	private static final int HALF_SWIMLANE_WIDTH = 5;
	private static final int HALF_SINK_WIDTH = 7;

	private static final float TIMESTAMP_MARGIN = 15.0f;
	private static final int TIMESTAMP_VERTICAL_OFFSET = 5;

	private double m_maxY = 0;
	
	private final MSCData mscData;
	
	public SwimlaneRenderer(MSCData mscData){
		super();
		
		this.mscData = mscData;
		
	}

	/**
	 * {@inheritDoc}
	 */
	protected Shape getRawShape(VisualItem item) {
		m_maxY = getYMaximum(item.getVisualization());
		GeneralPath swimlane;

		double yMaximum = m_maxY + StatementLayout.VERTICAL_STEP;
		Entity.Type entityType = (Entity.Type) item.get(Entity.TYPE_FIELDNAME);
		if (entityType == Entity.Type.SINK) {
			swimlane = getSinkShape(item, yMaximum);
		} else {
			swimlane = getSwimlaneShape(item, yMaximum);
		}

		return swimlane;
	}

	/**
	 * Get the shape of a sink
	 *
	 * @param visualEntity the VisualItem to draw the sink
	 * @param yMaximum the bottom of the sink
	 * @return the shape of the sink
	 */
	private GeneralPath getSinkShape(VisualItem visualEntity, double yMaximum) {
		Point2D startPosRectangle = new Point2D.Double();
		startPosRectangle.setLocation(visualEntity.getX() - HALF_SINK_WIDTH, 0);
		Point2D endPosRectangle = new Point2D.Double();
		endPosRectangle.setLocation(visualEntity.getX() + HALF_SINK_WIDTH, yMaximum);

		Rectangle2D rect = new Rectangle2D.Double();
		rect.setRect(startPosRectangle.getX(), startPosRectangle.getY(), endPosRectangle.getX() - startPosRectangle.getX(), endPosRectangle.getY() - startPosRectangle.getY());

		// Refresh the bounding box values for this visual item so Prefuse knows when to invalidate it
		visualEntity.setBounds(rect.getMinX(), rect.getMinY(), rect.getWidth(), rect.getHeight());

		GeneralPath sinkShape = new GeneralPath();
		sinkShape.append(rect, false);
		return sinkShape;
	}

	/**
	 * Get the shape of a swimlane of a Process or Tool
	 *
	 * @param visualEntity the VisualItem to draw the swimlane
	 * @param yMaximum the bottom of the swimlane
	 * @return the shape of the swimlane
	 */
	private GeneralPath getSwimlaneShape(VisualItem visualEntity, double yMaximum) {
		double startedEntity = getYPosBeginSwimlaneRectangle(visualEntity);
		double endedEntity = getYPosEndSwimlaneRectangle(visualEntity);

		Point2D startPosBeginLine = getShapePosition(visualEntity);
		Point2D endPosBeginLine = new Point2D.Double();
		endPosBeginLine.setLocation(visualEntity.getX(), startedEntity);

		Point2D startPosRectangle = new Point2D.Double();
		startPosRectangle.setLocation(visualEntity.getX() - HALF_SWIMLANE_WIDTH, startedEntity);
		Point2D endPosRectangle = new Point2D.Double();
		endPosRectangle.setLocation(visualEntity.getX() + HALF_SWIMLANE_WIDTH, endedEntity);

		Point2D startPosEndLine = new Point2D.Double();
		startPosEndLine.setLocation(visualEntity.getX(), endedEntity);
		Point2D endPosEndLine = new Point2D.Double();
		endPosEndLine.setLocation(visualEntity.getX(), yMaximum);

		Line2D beginLine = new Line2D.Double();
		beginLine.setLine(startPosBeginLine, endPosBeginLine);
		Line2D endLine = new Line2D.Double();
		endLine.setLine(startPosEndLine, endPosEndLine);
		Rectangle2D rect = new Rectangle2D.Double();
		rect.setRect(startPosRectangle.getX(), startPosRectangle.getY(), endPosRectangle.getX() - startPosRectangle.getX(), endPosRectangle.getY() - startPosRectangle.getY());

		// Refresh the bounding box values for this visual item so Prefuse knows when to invalidate it
		visualEntity.setBounds(visualEntity.getX(), startPosBeginLine.getY(), 1, yMaximum - startPosBeginLine.getY());

		GeneralPath swimlaneShape = new GeneralPath();
		swimlaneShape.append(beginLine, false);
		swimlaneShape.append(rect, false);
		swimlaneShape.append(endLine, false);
		return swimlaneShape;
	}

	/**
	 * Return the vertical position of the start of the rectangle on
	 * the swimlane of the given entity. This position represents that
	 * creation of the Entity.
	 *
	 * @param visualEntity the entity of the swimlane
	 * @return the vertical coordinate of the creation of the entity
	 */
	private double getYPosBeginSwimlaneRectangle(VisualItem visualEntity) {
		int beginTick = ((Integer) visualEntity.get(Entity.STARTTICK_FIELDNAME)).intValue();

		// Process are created one tick later than the executed statement
		int actualBeginTick = beginTick + 1;

		double beginY = getYTimeTick(visualEntity.getVisualization(), actualBeginTick);
		if (beginY < StatementLayout.VERTICAL_OFFSET - StatementLayout.VERTICAL_STEP) {
			return StatementLayout.VERTICAL_OFFSET - StatementLayout.VERTICAL_STEP;
		}
		return beginY;
	}

	/**
	 * Return the vertical position of the end of the rectangle on
	 * the swimlane of the given entity. This position represents that
	 * destroyement of the Entity.
	 *
	 * @param visualEntity the entity of the swimlane
	 * @return the vertical coordinate of the destroyement of the entity
	 */
	private double getYPosEndSwimlaneRectangle(VisualItem visualEntity) {
		int endTick = ((Integer) visualEntity.get(Entity.ENDTICK_FIELDNAME)).intValue();

		double endY;
		if (endTick > -1) {
			// Process are ended one tick later than the executed statement
			int actualEndTick = endTick + 1;
			endY = getYTimeTick(visualEntity.getVisualization(), actualEndTick);
		} else {
			endY = m_maxY;
		}

		if (endY < 0) {
			return 0;
		}

		return endY;
	}

	/**
	 * Get the Y value of the latest statement that is in the visualization.
	 *
	 * @param visualization the prefuse visualization
	 * @return the Y value of the latest statement
	 */
	private double getYMaximum(Visualization visualization) {
		double maxY = 0;

		if (mscData.getStatementList().size() != 0) {
			Tuple latestStatementTuple = mscData.getStatementList().getLast();
			VisualItem latestStatement = visualization.getVisualItem(Statement.TABLE_NAME, latestStatementTuple);
			maxY = latestStatement.getY();
		}

		return maxY;
	}

	/**
	 * Get the Y value of the statement that is executed on the given
	 * time tick.
	 *
	 * @param visualization the prefuse visualization
	 * @param timetick the timetick to question the y coordinate of
	 * @return the Y coordinate of the statement executed on the given timetick
	 */
	private double getYTimeTick(Visualization visualization, int timetick) {
		VisualItem statement = MSCVisualizationUtil.getStatement(visualization, timetick);
		return (statement != null ? statement.getY() : 0);
	}

	/**
	 * {@inheritDoc}
	 */
	public void render(Graphics2D g, VisualItem item) {
		super.render(g, item);

		if ((item.get(Entity.NAME_FIELDNAME)).equals("Sink")) {
			drawSinkTimestamps(g, item);
		}
	}

	/**
	 * Draw timestamps next to the Sink swinmlanes.
	 *
	 * @param g the graphics object to draw the timestamp text on
	 * @param visualSink the visual item of the sink
	 */
	private void drawSinkTimestamps(Graphics2D g, VisualItem visualSink) {
		boolean statementCollapseEnabled = MSCVisualizationUtil.isStatementCollapseEnabled();
		Visualization visualization = visualSink.getVisualization();

		// This should be cloned, because the list can be modified during executing of this action.
		LinkedList<Tuple> statements = (LinkedList<Tuple>) mscData.getStatementList().clone();

		int lastTimestamp = -1;
		for (Tuple statementTuple : statements) {
			VisualItem statement = visualization.getVisualItem(Statement.TABLE_NAME, statementTuple);
			if (statementCollapseEnabled) {
				if (statement.isVisible() || MSCVisualizationUtil.isTargetEntityVisible(visualization, statement)) {
					lastTimestamp = drawTimestamp(g, visualSink, statement, lastTimestamp);
				}
			} else {
				lastTimestamp = drawTimestamp(g, visualSink, statement, lastTimestamp);
			}
		}
	}

	/**
	 * Draw the timestamp of the given statement on the Graphics object.
	 *
	 * @param g the graphics object to draw the timestamp text on
	 * @param visualSink the visual item of the sink
	 * @param statement the executed statement
	 * @param lastTimestamp the timestamp of the previous executed statement
	 * @return the timestamp that is drawed
	 */
	private int drawTimestamp(Graphics2D g, VisualItem visualSink, VisualItem statement, int lastTimestamp) {
		int timestamp = ((Integer) statement.get(Statement.TIMESTAMP_FIELDNAME)).intValue();
		String timestampText = String.valueOf(timestamp);

		float sinkX = (float) visualSink.getX();
		float xPos;
		if (sinkX == EntityLayout.INCOMING_SINK_X) {
			xPos = sinkX - (TIMESTAMP_MARGIN + g.getFontMetrics().stringWidth(timestampText));
		} else {
			xPos = sinkX + TIMESTAMP_MARGIN;
		}

		float yPos = (float) (statement.getY() + TIMESTAMP_VERTICAL_OFFSET);
		g.drawString(timestampText, xPos, yPos);

		if (timestamp - lastTimestamp != 1) {
			if (sinkX == EntityLayout.INCOMING_SINK_X) {
				xPos = sinkX - (TIMESTAMP_MARGIN + g.getFontMetrics().stringWidth(COLLAPSE_TEXT));
			} else {
				xPos = sinkX + TIMESTAMP_MARGIN;
			}
			g.drawString(COLLAPSE_TEXT, xPos, yPos - (StatementLayout.VERTICAL_STEP / 2));
		}

		return timestamp;
	}


}
