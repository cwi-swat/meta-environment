package nl.cwi.sen.util;

import java.util.HashMap;

import javax.swing.tree.DefaultMutableTreeNode;

public class TreeNode extends DefaultMutableTreeNode {
	private String iconName;
	private HashMap<OverlayPosition, String> overlayPositions;
	private HashMap<String, OverlayPosition> overlayNames;
	
	public TreeNode() {
	}
	
	public void setIconName(String name) {
		iconName = name;
	}
	
	public String getIconName() {
		return iconName;
	}
	
	public void addOverlay(String name, OverlayPosition position) {
		overlayPositions.put(position, name);
		overlayNames.put(name, position);
	}
	
	public void removeOverlay(String name) {
		overlayPositions.remove(overlayNames.get(name));
		overlayNames.remove(name);
	}
	
	public HashMap<OverlayPosition, String> getOverlays() {
		return overlayPositions;
	}
}	
