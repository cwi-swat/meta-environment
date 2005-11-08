package nl.cwi.sen1.gui.plugin;

import java.awt.Rectangle;
import java.awt.Shape;
import java.awt.geom.AffineTransform;
import java.awt.geom.PathIterator;
import java.awt.geom.Point2D;
import java.awt.geom.Rectangle2D;

public class GraphCompositeShape implements Shape {
	private Shape outer;
	private Shape inner;

	public GraphCompositeShape(Shape inner, Shape outer) {
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
		return inner.contains(x,y);
	}

	public boolean contains(double x, double y, double w, double h) {
		return inner.contains(x,y,w,h);
	}

	public boolean intersects(double x, double y, double w, double h) {
		return inner.intersects(x,y,w,h);
	}

	public Rectangle getBounds() {
		return inner.getBounds();
	}

	public boolean contains(Point2D p) {
		return inner.contains(p);
	}

	public Rectangle2D getBounds2D() {
		return inner.getBounds2D();
	}

	public boolean contains(Rectangle2D r) {
		return inner.contains(r);
	}

	public boolean intersects(Rectangle2D r) {
		return inner.intersects(r);
	}

	public PathIterator getPathIterator(AffineTransform at) {
		return inner.getPathIterator(at);
	}

	public PathIterator getPathIterator(AffineTransform at, double flatness) {
		return inner.getPathIterator(at, flatness);
	}

}
