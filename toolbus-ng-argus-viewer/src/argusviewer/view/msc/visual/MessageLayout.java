package argusviewer.view.msc.visual;

import java.awt.geom.Point2D;
import java.util.Iterator;
import argusviewer.view.msc.data.Message;

import prefuse.action.layout.Layout;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;

/**
 * @author Arne Timmerman
 * @author Roberto van der Linden
 *
 */
public class MessageLayout extends Layout {

	/**
	 * Create a new Message layout for the specified group.
	 * 
	 * @param group The group of visual items on which the layout will be applied
	 */
	public MessageLayout(String group) {
		super(group);
	}
	
	/**
	 * {@inheritDoc}
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void run(double frac) {
		Iterator<VisualItem> visualMessages = m_vis.items(m_group);
		while (visualMessages.hasNext()) {
			VisualItem currentMessage = visualMessages.next();

			Point2D sourcePos = getMessageSourcePosition(currentMessage);
			
			if (sourcePos != null) {
				PrefuseLib.updateVisible(currentMessage, true);
				setX(currentMessage, null, sourcePos.getX());
				setY(currentMessage, null, sourcePos.getY());
			} else {
				PrefuseLib.updateVisible(currentMessage, false);
			}
		}
	}
	
	/**
	 * Calculate the position of the source statement for a particular message.
	 *
	 * This method returns null if no statement can be found that was
	 * executed on the Timestamp of the given VisualItem. If the statement where
	 * this message belongs to is invisible, this method will also return null.
	 *
	 * @param item The VisualItem representing the message
	 * @return The coordinates of the source statement
	 */
	private Point2D getMessageSourcePosition(VisualItem item) {

		Point2D sourcePos = null;

		int sourceId = (Integer) item.get(Message.SOURCEID_FIELDNAME);

		VisualItem matchingStatement = MSCVisualizationUtil.getStatement(m_vis, sourceId);
		
		if (matchingStatement != null) {
			sourcePos = new Point2D.Double();

			// Only create Source position if source statement is visible
			if (matchingStatement.isVisible()) {
				sourcePos.setLocation(matchingStatement.getX(), matchingStatement.getY());

				// If garbage swimlanes are enabled, this message should come from there
			} else {
				sourcePos.setLocation(EntityLayout.INCOMING_SINK_X, matchingStatement.getY());
			}
		}

		return sourcePos;
	}

}
