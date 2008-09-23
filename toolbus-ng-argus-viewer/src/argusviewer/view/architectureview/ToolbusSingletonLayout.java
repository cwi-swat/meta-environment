package argusviewer.view.architectureview;

import java.awt.geom.Rectangle2D;
import java.util.Iterator;

import prefuse.action.layout.Layout;
import prefuse.util.PrefuseLib;
import prefuse.visual.VisualItem;

/**
 * The layout used to align statements under their corresponding tool or tool.
 * Note that statements are set to invisible if the corresponding entity is invisible.
 *
 * @author Riccardo Lippolis
 * @author Johnny Eradus
 * @author Frank Oppedijk
 * @author Ivo Tamboer
 */
public class ToolbusSingletonLayout extends Layout {
	private final ProcessLayout m_processLayout;
	
	/**
	 * Create a new Tool layout for the specified group.
	 *
	 * @param processLayout the ProcessLayout which lays out the processes above the Tools.
	 * @param group The group of visual items on which the layout will be applied
	 */
	public ToolbusSingletonLayout(String group, ProcessLayout processLayout) {
		super(group);
		m_processLayout = processLayout;
	}

	/**
	 * {@inheritDoc}
	 */
	public void run(double frac) {
		Iterator<VisualItem> visualStatements = m_vis.items(m_group);
		while (visualStatements.hasNext()) {
			VisualItem currentTool = visualStatements.next();

				Rectangle2D bounds = m_processLayout.getBounds();
				setX(currentTool, null, bounds.getMinX());
				setY(currentTool, null, bounds.getMinY());
									
				PrefuseLib.updateVisible(currentTool, true);				
		}		
	}
}
