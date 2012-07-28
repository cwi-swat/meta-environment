package argusviewer.view.architectureview;

import java.util.Iterator;

import prefuse.action.layout.Layout;
import prefuse.util.PrefuseLib;
import prefuse.visual.DecoratorItem;
import prefuse.visual.VisualItem;

/**
 * The layout used to align statements under their corresponding tool or tool.
 * Note that statements are set to invisible if the corresponding entity is invisble.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 */
public class ToolLayout extends Layout{
	private final static int HORIZONTAL_STEP = 100;
	
	private final static int HORIZONTAL_MARGIN = 50;
	private final static int VERTICAL_MARGIN = 50;
	
	public final static double TOOL_LABEL_BASE = ToolRenderer.TOOL_BASESIZE * 0.7;
	
	private final ProcessLayout m_processLayout;
	
	/**
	 * Create a new Tool layout for the specified group.
	 *
	 * @param processLayout the ProcessLayout which lays out the processes above the Tools.
	 * @param group The group of visual items on which the layout will be applied
	 */
	public ToolLayout(String group, ProcessLayout processLayout){
		super(group);
		
		m_processLayout = processLayout;
	}

	/**
	 * {@inheritDoc}
	 */
	public void run(double frac){
		// Coordinates of bottom left edge of rectangle around all processes
		double xPos =  m_processLayout.getBounds().getMinX();
		double yPos = m_processLayout.getBounds().getMaxY();

		// Coordinates of first tool
		xPos += HORIZONTAL_MARGIN;
		yPos += VERTICAL_MARGIN;
		
		Iterator<VisualItem> visualStatements = m_vis.items(m_group);
		while(visualStatements.hasNext()){
			VisualItem currentTool = visualStatements.next();
			
			setX(currentTool, null, xPos);
			setY(currentTool, null, yPos);					
			PrefuseLib.updateVisible(currentTool, true);				
			
			xPos += HORIZONTAL_STEP;
		}
		
		// Layout the labels
		Iterator<DecoratorItem> labels = m_vis.items(ArchitectureView.TOOL_LABEL);
		while(labels.hasNext()){
			DecoratorItem label = labels.next();
			VisualItem parentEntity = label.getDecoratedItem();

			// Position the label under the Entity it belongs to
			setX(label, null, parentEntity.getX());
			setY(label, null, parentEntity.getY() + TOOL_LABEL_BASE);

			// Set the visibility of a label equal to the visibility of the Entity
			label.setVisible(parentEntity.isVisible());
		}
	}
}
