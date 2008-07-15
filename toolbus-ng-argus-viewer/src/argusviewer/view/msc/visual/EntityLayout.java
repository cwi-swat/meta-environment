/**
 * 
 */
package argusviewer.view.msc.visual;

import prefuse.action.layout.Layout;
import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualItem;

import java.util.ArrayList;
import java.util.Iterator;
import argusviewer.view.msc.data.Entity;

/**
 * The Layout used to align entities (processes and tools) horizontally, with vertical swimlanes.
 * 
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Arne Timmerman
 * @author Roberto van der Linden
 *
 */
public class EntityLayout extends Layout {

	private static final int HORIZONTAL_MARGIN = 40;
	
	private String m_swimlaneName;

	public static final double INCOMING_SINK_X = 0;
	private static double outgoingSinkX;
	
	/**
	 * Create a new Entity Layout for the specified group.
	 * 
	 * @param group The group of visual items on which the layout will be applied
	 * @param swimlaneName The field name used for the swimlane decorators
	 */
	public EntityLayout(String group, String swimlaneName) {
		super(group);
		m_swimlaneName = swimlaneName;
	}
	
	/**
	 * {@inheritDoc}
	 */
	@SuppressWarnings("unchecked")
	@Override
	public void run(double frac) {
		double currentX = HORIZONTAL_MARGIN + EntityRenderer.ENTITY_BASESIZE;
		double currentY = 0;
		
		// Layout the processes and tools
		Iterator<VisualItem> visualEntities = m_vis.visibleItems(m_group);
		ArrayList<VisualItem> visualSinks = new ArrayList<VisualItem>();

		while (visualEntities.hasNext()) {
			VisualItem currentEntity = visualEntities.next();
			Entity.Type entityType = (Entity.Type) currentEntity.get(Entity.TYPE_FIELDNAME);

			// Store the sinks in a list, they are drawn later
			if (entityType == Entity.Type.SINK) {
				visualSinks.add(currentEntity);
			} else {
				setX(currentEntity, null, currentX);
				setY(currentEntity, null, currentY);
			
				currentX += currentEntity.getBounds().getWidth() + HORIZONTAL_MARGIN;
			}
		}

		// Layout the sink items, there should be two
		if (visualSinks.size() == 2) {
			VisualItem incomingSink = visualSinks.get(0);
			setX(incomingSink, null, INCOMING_SINK_X);
			setY(incomingSink, null, currentY);

			VisualItem outgoingSink = visualSinks.get(1);
			outgoingSinkX = currentX;
			setX(outgoingSink, null, outgoingSinkX);
			setY(outgoingSink, null, currentY);
		}

		// Layout the swimlanes
		Iterator<DecoratorItem> swimlanes = m_vis.items(m_swimlaneName);
		while (swimlanes.hasNext()) {
			DecoratorItem swimlane = swimlanes.next();
			
			VisualItem parentEntity = swimlane.getDecoratedItem();

			// Position the swimlane under the Entity it belongs to
			setX(swimlane, null, parentEntity.getX());
			setY(swimlane, null, parentEntity.getY() + (EntityRenderer.ENTITY_BASESIZE / 2));

			// Set the visibility of a swimlane equal to the visibility of the Entity
			swimlane.setVisible(parentEntity.isVisible());
		}
	}

	/**
	 * Get the X coordinate of the outgoing Sink.
	 * @return X coordinate of the outgoing Sink.
	 */
	public static double getOutgoingSinkX() {
		return outgoingSinkX;
	}
}
