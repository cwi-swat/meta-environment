package nl.cwi.sen1.gui.plugin.prefusedot;

import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.awt.geom.PathIterator;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

public class DotShape implements Shape {
	private Shape outer;
	private Shape inner;

	public DotShape(Shape inner, Shape outer) {
		this.inner = inner;
		this.outer = outer;
	}
	
	public Shape getInnerShape() {
		return inner;
	}
	
	public Shape getOuterShape() {
		return outer;
	}
	
	public boolean contains(double x, double y) {
		return outer.contains(x,y);
	}

	public boolean contains(double x, double y, double w, double h) {
		return outer.contains(x,y,w,h);
	}

	public boolean intersects(double x, double y, double w, double h) {
		return outer.intersects(x,y,w,h);
	}

	public Rectangle getBounds() {
		return outer.getBounds();
	}

	public boolean contains(Point2D p) {
		return outer.contains(p);
	}

	public Rectangle2D getBounds2D() {
		return outer.getBounds2D();
	}

	public boolean contains(Rectangle2D r) {
		return outer.contains(r);
	}

	public boolean intersects(Rectangle2D r) {
		return outer.intersects(r);
	}

	public PathIterator getPathIterator(AffineTransform at) {
		return outer.getPathIterator(at);
	}

	public PathIterator getPathIterator(AffineTransform at, double flatness) {
		return outer.getPathIterator(at, flatness);
	}

}
