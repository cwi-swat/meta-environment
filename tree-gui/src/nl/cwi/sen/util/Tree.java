package nl.cwi.sen.util;

import java.util.HashMap;

import javax.swing.ImageIcon;
import javax.swing.JTree;

public class Tree extends JTree {
	private HashMap<String, ImageIcon> icons;
	private HashMap<String, ImageIcon> overlays;
	
	public Tree(TreeNode root) {
		super(root);
		icons = new HashMap<String, ImageIcon>();
		overlays = new HashMap<String, ImageIcon>();
	}

	public HashMap<String, ImageIcon> getIcons() {
		return icons;
	}
	
	public HashMap<String, ImageIcon> getOverlayIcons() {
		return overlays;
	}

	public void addTreeIcon(String name, String path) {
		ImageIcon icon = new ImageIcon(path);
		icons.put(name, icon);
	}

	public void addTreeOverlay(String name, String path) {
		ImageIcon icon = new ImageIcon(path);
		overlays.put(name, icon);
	}
}
