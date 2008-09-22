package argusviewer.view.architectureview;

import java.awt.Shape;
import java.awt.geom.Rectangle2D;


import org.apache.log4j.Logger;
import argusviewer.view.msc.visual.AbstractMSCRenderer;

import prefuse.visual.VisualItem;

/**
 * Renders the square representing the toolbus around the processes.
 */
public class ToolbusSingletonRenderer extends AbstractMSCRenderer {
	private final static Logger log = Logger.getLogger(ToolbusSingletonRenderer.class);
	
	private final ProcessLayout m_processLayout;
	
	/**
	 * Constructor accepting a ProcessLayout to use to receive dimension
	 * information.
	 * @param processes ProcessLayout for information extraction.
	 */
	public ToolbusSingletonRenderer(ProcessLayout processes) {
		log.debug("ToolbusSingletonRenderer constructed");
		m_processLayout = processes;
	}
	
	/**
	 * returns the square.
	 * @param item not used.
	 * @return the square to be drawn.
	 */
	protected Shape getRawShape(VisualItem item) {
		log.debug("getRawShape called");
		
		Rectangle2D bounds = m_processLayout.getBounds();
		Rectangle2D rectangle = new Rectangle2D.Double();
		rectangle.setFrame(bounds.getMinX(), bounds.getMinY(), bounds.getWidth(), bounds.getHeight());
		
		// Also update the item bounds, so it knows when it has been invalidated
		item.setBounds(bounds.getMinX(), bounds.getMinY(), bounds.getWidth(), bounds.getHeight());
		return rectangle;
	}
}
