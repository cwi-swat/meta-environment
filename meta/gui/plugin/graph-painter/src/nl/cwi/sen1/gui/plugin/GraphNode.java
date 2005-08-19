package nl.cwi.sen1.gui.plugin;

import java.awt.Color;

import edu.berkeley.guir.prefuse.graph.DefaultNode;

public class GraphNode extends DefaultNode {
	private int dotX;
	private int dotY;
	private int dotWidth;
	private int dotHeight;
	private Color color;
	private Color fillColor;
	
	public void setId(String id) {
		setAttribute("id", id);
	}
	
	public void setLabel(String label) {
		setAttribute("label", label);
	}
	
	public void setDotX(int x) {
		dotX = x;
	}
	
	public int getDotX() {
		return dotX;
	}
	
	public void setDotY(int y) {
		dotY = y;
	}
	
	public int getDotY() {
		return dotY;
	}
	
	public void setDotWidth(int width) {
		dotWidth = width;
	}
	
	public int getDotWidth() {
		return dotWidth;
	}
	
	public void setDotHeight(int height) {
		dotHeight = height;
	}
	
	public int getDotHeight() {
		return dotHeight;
	}
	
	public void setFillColor(Color color) {
		fillColor = color;
	}
	
	public Color getFillColor() {
		return fillColor;
	}
	
	public void setColor(Color color) {
		this.color = color;
	}
	
	public Color getColor() {
		return color;
	}
}
