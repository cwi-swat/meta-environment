package nl.cwi.sen.gui;

import java.awt.Component;
import java.awt.Graphics2D;
import java.awt.Image;
import java.awt.image.BufferedImage;
import java.util.HashMap;
import java.util.Iterator;

import javax.swing.ImageIcon;
import javax.swing.tree.DefaultTreeCellRenderer;

public class TreeCellRenderer extends DefaultTreeCellRenderer {
	public TreeCellRenderer() {
	}

	public Component getTreeCellRendererComponent(Tree tree, Object value,
			boolean sel, boolean expanded, boolean leaf, int row,
			boolean hasFocus) {

		super.getTreeCellRendererComponent(tree, value, sel, expanded, leaf,
				row, hasFocus);

		HashMap<String, ImageIcon> icons = tree.getIcons();
		HashMap<String, ImageIcon> overlayIcons = tree.getOverlayIcons();

		TreeNode treeNode = (TreeNode) value;

		ImageIcon icon = icons.get(treeNode.getIconName());
		HashMap<String, OverlayPosition> overlays = treeNode.getOverlays();
		for (Iterator<String> iter = overlays.keySet().iterator(); iter
				.hasNext();) {
			String overlayName = iter.next();
			icon = overlayIcon(icon, overlayIcons.get(overlayName), overlays
					.get(overlayName));
		}

		setIcon(icon);

		return this;
	}

	private ImageIcon overlayIcon(ImageIcon icon, ImageIcon overlayIcon,
			OverlayPosition position) {
		int x, y;
		Image image = icon.getImage();
		BufferedImage bufferedImage = new BufferedImage(image.getWidth(null),
				image.getHeight(null), BufferedImage.TYPE_INT_ARGB);

		Graphics2D g = bufferedImage.createGraphics();
		// Warning: drawImage returns immediately, even when the image is not
		// completely drawn! When errors occur use an image observer to check
		// when it is ready.
		g.drawImage(image, null, null);

		Image overlay = overlayIcon.getImage();
		switch (position) {
		case TOP_LEFT:
			x = 0;
			y = 0;
			break;
		case TOP_RIGHT:
			x = image.getWidth(null) - overlay.getWidth(null);
			y = 0;
			break;
		case BOTTOM_LEFT:
			x = 0;
			y = image.getHeight(null) - overlay.getHeight(null);
			break;
		case BOTTOM_RIGHT:
			x = image.getWidth(null) - overlay.getWidth(null);
			y = image.getHeight(null) - overlay.getHeight(null);
			break;
		default:
			x = 0;
			y = 0;
			break;
		}
		if (x < 0) {
			x = 0;
		}
		if (y < 0) {
			y = 0;
		}
		g.drawImage(overlay, x, y, null);
		g.dispose();

		return new ImageIcon(bufferedImage);
	}
}