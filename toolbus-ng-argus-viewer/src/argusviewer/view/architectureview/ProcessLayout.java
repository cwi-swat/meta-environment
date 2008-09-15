package argusviewer.view.architectureview;

import java.awt.geom.Rectangle2D;
import java.util.Iterator;

import org.apache.log4j.Logger;

import prefuse.action.layout.Layout;
import prefuse.util.PrefuseLib;
import prefuse.util.display.DisplayLib;
import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualItem;

/**
 * The layout used to align statements under their corresponding process or tool.
 * Note that statements are set to invisible if the corresponding entity is invisble.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 *
 */
public class ProcessLayout extends Layout {
	private static final int MARGIN = 30;
	private static final int HORIZONTAL_STEP = 90;
	private static final int VERTICAL_STEP = 90;
	private static final int PROCESSES_PER_LINE = 8;
	
	private static final double PROCESS_LABEL_BASE = ProcessRenderer.PROCESS_BASESIZE * 0.7;

	private int m_processesLines = 1;
	
	private static Logger log = Logger.getLogger(ProcessLayout.class);
		
	/**
	 * Create a new Process layout for the specified group.
	 *
	 * @param group The group of visual items on which the layout will be applied
	 */
	public ProcessLayout(String group) {
		super(group);
		log.debug("ProcessLayout constructer called.");
	}



	/**
	 * @return the bounds of the rectangle around all processes
	 */
	public Rectangle2D getBounds() {
		return DisplayLib.getBounds(m_vis.items(m_group), MARGIN);
	}

	/**
	 * {@inheritDoc}
	 */
	public void run(double frac) {
		int xSlotsUsed = 0;
		m_processesLines = 1;
		
		double xPos = MARGIN;
		double yPos = MARGIN;
		
		log.debug("run called");		

		Iterator<VisualItem> visualStatements = m_vis.items(m_group);
		log.debug("start while loop");
		while (visualStatements.hasNext()) {
			VisualItem currentProcess = visualStatements.next();

				xSlotsUsed += 1;
				if (xSlotsUsed > PROCESSES_PER_LINE) {
					log.debug("adding a new line.");
					yPos += VERTICAL_STEP;
					xPos = MARGIN;
					xSlotsUsed = 1;
					m_processesLines += 1;
				}
				xPos += HORIZONTAL_STEP;

				log.debug("Now working on " + currentProcess);
				setX(currentProcess, null, xPos);
				setY(currentProcess, null, yPos);
					
				PrefuseLib.updateVisible(currentProcess, true);				
		}
		log.debug("end while loop");
		// Layout the labels
		Iterator<DecoratorItem> labels = m_vis.items(ArchitectureView.PROCESS_LABEL);
		while (labels.hasNext()) {
			log.debug("processing some label");	
			DecoratorItem label = labels.next();
			log.debug(label);
			VisualItem parentEntity = label.getDecoratedItem();

			// Position the label above the Entity it belongs to
			setX(label, null, parentEntity.getX());
			setY(label, null, parentEntity.getY() - PROCESS_LABEL_BASE);

			// Set the visibility of a label equal to the visibility of the Entity
			label.setVisible(parentEntity.isVisible());
		}
	}

	/**
	 * lazy script giving the width of the process table. Could be way better.
	 * @return width of the processes.
	 */
	public int getWidth() {
		return PROCESSES_PER_LINE * HORIZONTAL_STEP;
	}
}
