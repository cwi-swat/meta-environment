package argusviewer.view.architectureview.performance.tree;

import java.awt.Component;

import javax.swing.ImageIcon;
import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;

/**
 * Draws a Performance Tree Cell
 * 
 * @author Jeldert Pol
 */
public class ToolPerformanceRenderer extends DefaultTreeCellRenderer {
	private static final long serialVersionUID = -7191130444201004897L;
	
	private static final ImageIcon ICON_GROUP = new ImageIcon("resources/icons/group.png");
	private static final ImageIcon ICON_TOOL = new ImageIcon("resources/icons/tool.png");
	private static final ImageIcon ICON_THREAD = new ImageIcon("resources/icons/thread.png");

	/**
	 * Creates a {@link ToolPerformanceRenderer}.
	 */
	public ToolPerformanceRenderer() {
		// setLeafIcon(ICON_TOOL);
		// setOpenIcon(ICON_GROUP);
		// setClosedIcon(ICON_GROUP);
	}

	/**
	 * {@inheritDoc}
	 */
	public Component getTreeCellRendererComponent(JTree tree, Object value, boolean selected, boolean expanded, boolean leaf, int row, boolean hasFocus) {
		super.getTreeCellRendererComponent(tree, value, selected, expanded,
				leaf, row, hasFocus);

		if (value instanceof PerformanceTreeNodeThread) {
			setLeafIcon(ICON_THREAD);
		} else if (value instanceof PerformanceTreeNode) {
			PerformanceTreeNode node = (PerformanceTreeNode) value;
			
			if (node.getToolId() == null) {
				setOpenIcon(ICON_GROUP);
				setClosedIcon(ICON_GROUP);
			} else {
				setOpenIcon(ICON_TOOL);
				setClosedIcon(ICON_TOOL);				
			}
			// TODO drawing of icons is not working properly
//			
//			// No child, so must be tool
//			if (node.getChildCount() == 0) {
//				setLeafIcon(ICON_TOOL);				
//				log.debug("leaf tool icon set");
//				// Only threads as childs, so must be tool, but expandable
//			} else if (node.getChildAt(0) instanceof PerformanceTreeNodeThread) {
//				log.debug("open/closed tool icon 2 set");
//				setOpenIcon(ICON_TOOL);
//				setClosedIcon(ICON_TOOL);
//				// Tool as child, so must be a group
//			} else if (node.getChildAt(0) instanceof PerformanceTreeNode) {
//				log.debug("open/closed group icon set");
//				setOpenIcon(ICON_GROUP);
//				setClosedIcon(ICON_GROUP);
//			} else {
//				// Error
//			}
		} else {
			// Error
		}

		return this;
	}
}