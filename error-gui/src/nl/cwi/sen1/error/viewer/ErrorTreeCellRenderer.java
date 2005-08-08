package nl.cwi.sen1.error.viewer;

import java.awt.Color;
import java.awt.Component;

import javax.swing.Icon;
import javax.swing.JTree;
import javax.swing.tree.DefaultTreeCellRenderer;

import nl.cwi.sen1.error.model.ErrorNode;

public class ErrorTreeCellRenderer extends DefaultTreeCellRenderer {
	
	public ErrorTreeCellRenderer() {
		Icon personIcon = null;
        setLeafIcon(personIcon);
        setClosedIcon(personIcon);
        setOpenIcon(personIcon);
	}
	
	public Component getTreeCellRendererComponent(JTree tree, Object value,
			boolean sel, boolean expanded, boolean leaf, int row,
			boolean hasFocus) {
		Color textNonSelectionColor = getTextNonSelectionColor();
		Color backgroundNonSelectionColor = getBackgroundNonSelectionColor();

		if (value instanceof ErrorNode) {
			ErrorNode node = (ErrorNode) value;

			if (node.isWarning()) {
				setTextNonSelectionColor(new Color(0, 0, 255));
			} else if (node.isError()) {
				setTextNonSelectionColor(new Color(255, 0, 0));
			} else if (node.isFatal()) {
				setBackgroundNonSelectionColor(new Color(255, 0, 0));
			}
		}

		Component comp = super.getTreeCellRendererComponent(tree, value, sel,
				expanded, leaf, row, hasFocus);

		setTextNonSelectionColor(textNonSelectionColor);
		setBackgroundNonSelectionColor(backgroundNonSelectionColor);

		return comp;
	}
}