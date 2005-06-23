package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Paint;

import nl.cwi.sen1.util.Preferences;
import edu.berkeley.guir.prefuse.EdgeItem;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.VisualItem;
import edu.berkeley.guir.prefuse.action.assignment.ColorFunction;

public class GraphColoring extends ColorFunction {
	private Color edgeFillColor;

	public GraphColoring(Preferences prefs) {
		super();
		setDefaultFillColor(prefs.getColor("graph.node.background"));
		setDefaultColor(prefs.getColor("graph.node.foreground"));
		setFocusColor(prefs.getColor("graph.node.selected.foreground"));
		setFocusFillColor(prefs.getColor("graph.node.selected.background"));
		setHighlightFillColor(prefs.getColor("graph.node.hovered.background"));
		setHighlightColor(prefs.getColor("graph.node.hovered.foreground"));
		setEdgeFillColor(prefs.getColor("graph.node.foreground"));
	}

	public void setEdgeFillColor(Color color) {
		edgeFillColor = color;
	}

	public Paint getColor(VisualItem item) {
		if (item instanceof NodeItem) {
			if (item.isFocus()) {
				return focusColor;
			}
			else if (item.isHighlighted()) {
				return highlightColor;
			}
		}
		
		return defaultColor;
	}

	public Paint getFillColor(VisualItem item) {
		Color color;
		if (item instanceof NodeItem) {
			if (item.isFocus()) {
				return focusFillColor;
			}
			else if (item.isHighlighted()) {
				return highlightFillColor;
			}
			else {
				GraphNode node = (GraphNode) item.getEntity();
				color = node.getFillColor();
				if (color != null) {
					return color;
				}
			}
		} 
		else if (item instanceof EdgeItem) {
			return edgeFillColor;
		}

		return defaultFillColor;
	}
}