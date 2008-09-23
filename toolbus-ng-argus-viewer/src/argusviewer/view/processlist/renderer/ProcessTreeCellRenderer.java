package argusviewer.view.processlist.renderer;

import java.awt.Component;

import javax.swing.ImageIcon;
import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;
import argusviewer.view.processlist.data.ProcessTreeNode;


/**
 * Draws a Process Tree Cell
 * @author Hidde Baggelaar
 *
 */
public class ProcessTreeCellRenderer extends DefaultTreeCellRenderer  {
	private static final long serialVersionUID = -2763392586708582562L;
	
	private static final ImageIcon ICON_GROUP = new ImageIcon("resources/icons/group.png");
	private static final ImageIcon ICON_PROCESS = new ImageIcon("resources/icons/process.png");
	
	/**
	 * Creates a ProcessTreeCellRenderer
	 */
	public ProcessTreeCellRenderer(){
		super();
		
		setLeafIcon(ICON_PROCESS);
		setOpenIcon(ICON_GROUP);
		setClosedIcon(ICON_GROUP);
	}
	
	/**
	 * {@inheritDoc}
	 */
	public Component getTreeCellRendererComponent(JTree tree, Object value, boolean selected, boolean expanded, boolean leaf, int row, boolean hasFocus) {
		Component temp =  super.getTreeCellRendererComponent(tree, value, selected, expanded, leaf, row, hasFocus);
		
		ProcessTreeNode node = (ProcessTreeNode) value;
		
		if (node.isRemoved()) { 
			temp.setEnabled(false);
		} else {
			temp.setEnabled(true);
		}
			
		return temp;
	}
}
