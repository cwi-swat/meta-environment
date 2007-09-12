package nl.cwi.sen.util;

import java.util.HashMap;

import javax.swing.tree.DefaultMutableTreeNode;

public class TreeNode extends DefaultMutableTreeNode {
	private String iconName;
	private HashMap<String, OverlayPosition> overlays;
	
	public TreeNode() {
	}
	
	public void setIconName(String name) {
		iconName = name;
	}
	
	public String getIconName() {
		return iconName;
	}
	
	public void addOverlay(String name, OverlayPosition position) {
		overlays.put(name, position);
	}
	
	public void removeOverlay(String name) {
		overlays.remove(name);
	}
	
	public HashMap<String, OverlayPosition> getOverlays() {
		return overlays;
	}
}	
