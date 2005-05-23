package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Paint;

import nl.cwi.sen1.util.Preferences;

import edu.berkeley.guir.prefuse.EdgeItem;
import edu.berkeley.guir.prefuse.NodeItem;
import edu.berkeley.guir.prefuse.VisualItem;
import edu.berkeley.guir.prefuse.action.assignment.ColorFunction;

public class GraphColoring extends ColorFunction {
	private final Color defaultBg = Color.WHITE;
	private final Color defaultFg = Color.BLACK;
	
	private Color nodeBg;
	private Color nodeFg;
	private Color nodeSelectedBg;
	private Color nodeSelectedFg;
	private Color nodeHoveredBg;
	private Color nodeHoveredFg;

	public GraphColoring(Preferences prefs) {
		nodeBg = prefs.getColor("graph.node.background");
		nodeFg = prefs.getColor("graph.node.foreground");
		nodeSelectedBg = prefs.getColor("graph.node.selected.background");
		nodeSelectedFg = prefs.getColor("graph.node.selected.foreground");
		nodeHoveredBg = prefs.getColor("graph.node.hovered.background");
		nodeHoveredFg = prefs.getColor("graph.node.hovered.foreground");
	}
	
	public Paint getColor(VisualItem item) {
		if (item instanceof NodeItem) {
			if (item.isFocus()) {
				return nodeSelectedFg;
			}
			else if (item.isHighlighted()) {
				return nodeHoveredFg;
			}
			else {
				return nodeFg;
			}
		} 
		else {
		   return defaultFg;
		}
	}

	public Paint getFillColor(VisualItem item) {
		if (item instanceof NodeItem) {
			if (item.isFocus()) {
				return nodeSelectedBg;
			}
			else if (item.isHighlighted()) {
				return nodeHoveredBg;
			}
			else {
				return nodeBg;
			}
		} 
		else if (item instanceof EdgeItem) {
			// arrow head needs to be filled with foreground color
			return defaultFg;
		}
		else {
		   return defaultBg;
		}
	}
}