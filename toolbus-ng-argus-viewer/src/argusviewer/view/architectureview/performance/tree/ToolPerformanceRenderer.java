package argusviewer.view.architectureview.performance.tree;

import java.awt.Component;

import javax.swing.ImageIcon;
import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;

import argusviewer.util.IconLoader;

/**
 * Draws a Performance Tree Cell
 * 
 * @author Jeldert Pol
 */
public class ToolPerformanceRenderer extends DefaultTreeCellRenderer {
	private static final long serialVersionUID = -7191130444201004897L;
	
	private static final ImageIcon ICON_GROUP = IconLoader.loadIcon("group.png");
	private static final ImageIcon ICON_TOOL = IconLoader.loadIcon("tool.png");
	private static final ImageIcon ICON_THREAD = IconLoader.loadIcon("thread.png");

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
		super.getTreeCellRendererComponent(tree, value, selected, expanded, leaf, row, hasFocus);

		if(value instanceof PerformanceTreeNodeThread){
			setLeafIcon(ICON_THREAD);
		}else if (value instanceof PerformanceTreeNode){
			PerformanceTreeNode node = (PerformanceTreeNode) value;
			
			if(node.getToolId() == null){
				setOpenIcon(ICON_GROUP);
				setClosedIcon(ICON_GROUP);
			}else{
				setOpenIcon(ICON_TOOL);
				setClosedIcon(ICON_TOOL);				
			}
			// TODO drawing of icons is not working properly
//			
//			// No child, so must be tool
//			if (node.getChildCount() == 0) {
//				setLeafIcon(ICON_TOOL);				
//				// Only threads as childs, so must be tool, but expandable
//			} else if (node.getChildAt(0) instanceof PerformanceTreeNodeThread) {
//				setOpenIcon(ICON_TOOL);
//				setClosedIcon(ICON_TOOL);
//				// Tool as child, so must be a group
//			} else if (node.getChildAt(0) instanceof PerformanceTreeNode) {
//				setOpenIcon(ICON_GROUP);
//				setClosedIcon(ICON_GROUP);
//			} else {
//				// Error
//			}
		}else{
			// Error
		}

		return this;
	}
}