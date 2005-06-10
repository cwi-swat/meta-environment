package nl.cwi.sen1.gui.plugin;

import java.awt.Color;
import java.awt.Paint;

import nl.cwi.sen1.util.Preferences;
import edu.berkeley.guir.prefuse.EdgeItem;
import edu.berkeley.guir.prefuse.VisualItem;
import edu.berkeley.guir.prefuse.action.assignment.ColorFunction;

public class GraphColoring extends ColorFunction {
	private Color edgeFillColor;
	
	public GraphColoring(Preferences prefs) {
		super();
		setDefaultFillColor(prefs.getColor("graph.node.background"));
		setDefaultColor(prefs.getColor("graph.node.foreground"));
		setFocusColor(prefs.getColor("graph.node.selected.background"));
		setFocusFillColor(prefs.getColor("graph.node.selected.foreground"));
		setHighlightFillColor(prefs.getColor("graph.node.hovered.background"));
		setHighlightColor(prefs.getColor("graph.node.hovered.foreground"));
		setEdgeFillColor(prefs.getColor("graph.node.foreground"));
	}
	
	public void setEdgeFillColor(Color color) {
		edgeFillColor = color;
	}
	
	public Paint getColor(VisualItem item) {
		Color color = (Color) item.getVizAttribute("color");
		if (color != null) {
			setDefaultColor(color);
		}
		return super.getColor(item);
	}
	
	public Paint getFillColor(VisualItem item) {
		Color color;
		
		if (item instanceof EdgeItem) {
			return edgeFillColor;
		}
	    
		color = (Color) item.getFillColor();
		
		if (color != null) {
			setDefaultFillColor(color);
		}
		
		return super.getFillColor(item);
	}
}