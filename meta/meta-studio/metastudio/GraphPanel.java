package metastudio;

import java.awt.Color;
import java.awt.Component;
import java.awt.Dimension;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.Graphics2D;
import java.awt.Rectangle;
import java.awt.RenderingHints;
import java.awt.event.MouseEvent;
import java.awt.event.MouseMotionAdapter;
import java.awt.event.MouseMotionListener;
import java.awt.geom.AffineTransform;
import java.awt.geom.GeneralPath;
import java.awt.geom.NoninvertibleTransformException;
import java.awt.geom.Point2D;

import javax.swing.JComponent;
import javax.swing.JViewport;
import javax.swing.Scrollable;
import javax.swing.SwingConstants;

import metastudio.graph.Attribute;
import metastudio.graph.Edge;
import metastudio.graph.EdgeList;
import metastudio.graph.Node;
import metastudio.graph.NodeList;
import metastudio.graph.Point;
import metastudio.graph.Polygon;
import metastudio.graph.Shape;

public class GraphPanel extends JComponent implements Scrollable {
	private static final int ARROWHEAD_LENGTH = 15;
	private static final int ARROWHEAD_SHARPNESS = 15;
	public static final String PREF_NODE_FONT = "node.font";
	public static final String PREF_NODE_BG = "node.background";
	public static final String PREF_NODE_FG = "node.foreground";
	public static final String PREF_NODE_BORDER = "node.border";
	public static final String PREF_NODE_HOVERED_BG = "node.hovered.background";
	public static final String PREF_NODE_HOVERED_FG = "node.hovered.foreground";
	public static final String PREF_NODE_HOVERED_BORDER = "node.hovered.border";
	public static final String PREF_NODE_SELECTED_BG = "node.selected.background";
	public static final String PREF_NODE_SELECTED_FG = "node.selected.foreground";
	public static final String PREF_NODE_SELECTED_BORDER = "node.selected.border";

	private String id;
	private int index;

	private GraphWrapper graph;

	private int max_x;
	private int max_y;
	private boolean dragEnabled = true;

	private FontMetrics metrics;
	private AffineTransform transform;

	private Node hoveredNode;
	private Node selectedNode;

	private Color nodeBG;
	private Color nodeFG;
	private Color nodeBorder;

	private Color nodeBGHovered;
	private Color nodeFGHovered;
	private Color nodeBorderHovered;

	private Color nodeBorderSelected;
	private Color nodeBGSelected;
	private Color nodeFGSelected;

	public GraphPanel(String id) {
		this.id = id;
		transform = new AffineTransform();
   
		setAutoscrolls(true);
        
		MouseMotionListener mouseMotionListener = new MouseMotionAdapter() {
			boolean dragging;
			int lastX;
			int lastY;

			public void mouseMoved(MouseEvent event) {
				dragging = false;
				Node node = getNodeAt(event.getX(), event.getY());
				if ((node == null && hoveredNode != null)
					|| (node != null && (hoveredNode == null || !hoveredNode.getId().equals(node.getId())))) {
					hoveredNode = node;
					repaint();
				}
			}
			public void mouseExited(MouseEvent event) {
				hoveredNode = null;
				repaint();
			}
			public void mouseDragged(MouseEvent e) {
				if (dragEnabled) {
					Component parent = getParent();
					while (parent != null && !(parent instanceof JViewport)) {
						parent = parent.getParent();
					}
					JViewport port = (JViewport) parent;
					java.awt.Point pos = port.getViewPosition();
					int absX = e.getX() - (int) pos.getX();
					int absY = e.getY() - (int) pos.getY();
					if (!dragging) {
						dragging = true;
					} else {
						int x = (int) pos.getX() + (lastX - absX);
						int y = (int) pos.getY() + (lastY - absY);
						Dimension portSize = port.getSize();
						Dimension size = getSize();
						if (x + portSize.width > size.width) {
							x = size.width - portSize.width;
						}
						if (y + portSize.height > size.height) {
							y = size.height - portSize.height;
						}
						if (x < 0) {
							x = 0;
						}
						if (y < 0) {
							y = 0;
						}
						/* Rectangle r = new Rectangle(e.getX(), e.getY(), 1, 1);
						((JComponent)e.getSource()).scrollRectToVisible(r);
						*/
						port.setViewPosition(new java.awt.Point(x, y));
					}
					lastX = absX;
					lastY = absY;
				}
			}
		};
		addMouseMotionListener(mouseMotionListener);

	}

	public void setGraph(GraphWrapper graph) {
		this.graph = graph;
		updateGeometry();
	}

	public void setDragEnabled(boolean on) {
		dragEnabled = on;
	}

	private void updateGeometry() {
		if (graph == null) {
			max_x = 0;
			max_y = 0;
		} else {
			calcBoundingBox();
			invalidate();
			getParent().validate();
		}
		repaint();
	}

	private void calcBoundingBox() {
		int max_x = 0;
		int max_y = 0;

		Graphics g = getGraphics();
		g.setFont(Preferences.getFont(PREF_NODE_FONT));
		metrics = g.getFontMetrics();

		Attribute bbox = graph.getBoundingBox();
		Point max = bbox.getSecond();
    
		max_x = max.getX().intValue();
		max_y = max.getY().intValue();

		Point2D point = transform.transform(new Point2D.Float((float) max_x, (float) max_y), null);

		this.max_x = (int) point.getX();
		this.max_y = (int) point.getY();   
	}

	public void paint(Graphics g) {
		g.setColor(getBackground());
		//System.out.println("size = " + getSize());
		if (graph != null) {
			Graphics2D g2d = (Graphics2D) g;
			g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING, 
                           RenderingHints.VALUE_ANTIALIAS_ON);      
			g2d.transform(transform);
            

			// Hack around 32k limit bug:
			// Originally, this fillrect came before the transform (in screen coordinates),
			// but calling fillRect with arguments above 32k triggers a bug.
			// by calling fillRect after transform we can use user coordinates.
			// As we don't have a suitable limit handy, we just use an arbitrary
			// large number below 32k so the whole background will be filled.
			g.fillRect(0, 0, 32000, 32000);

			//Stroke stroke = g2d.getStroke();
			//g2d.setStroke(new BasicStroke((float)1.5));
			setupColors();
			paintEdges(g2d);
			paintNodes(g2d);
		}
	}

	private void setupColors() {
		nodeBG = Preferences.getColor(PREF_NODE_BG);
		nodeFG = Preferences.getColor(PREF_NODE_FG);
		nodeBorder = Preferences.getColor(PREF_NODE_BORDER);

		nodeBGHovered = Preferences.getColor(PREF_NODE_HOVERED_BG);
		nodeFGHovered = Preferences.getColor(PREF_NODE_HOVERED_FG);
		nodeBorderHovered = Preferences.getColor(PREF_NODE_HOVERED_BORDER);

		nodeBGSelected = Preferences.getColor(PREF_NODE_SELECTED_BG);
		nodeFGSelected = Preferences.getColor(PREF_NODE_SELECTED_FG);
		nodeBorderSelected = Preferences.getColor(PREF_NODE_SELECTED_BORDER);
	}

	public Dimension getPreferredSize() {
		return new Dimension(max_x + 5, max_y + 5);
	}

	public Dimension getMinimumSize() {
		return getPreferredSize();
	}

	private void paintNodes(Graphics2D g) {
		g.setFont(Preferences.getFont(PREF_NODE_FONT));
		metrics = g.getFontMetrics();

		NodeList nodes = graph.getNodes();
		while (!nodes.isEmpty()) {
			Node node = nodes.getHead();
			nodes = nodes.getTail();

			paintNode(g, node);
		}
	}

	private void paintNode(Graphics2D g, Node node) {
		if (!node.isPositioned()) {
			return;
		}

    System.err.println(node.getLabel());
		int x = node.getX(); System.err.println("  x: " + x);
		int y = node.getY(); System.err.println("  y: " + y);
		int w = node.getWidth();
		int h = node.getHeight();

		x -= w / 2;
		y -= h / 2;

		if (!g.hitClip(x, y, w, h)) {
			return;
		}

		Color node_bg, node_fg, node_border;

		if (selectedNode != null && selectedNode.getId().equals(node.getId())) {
			node_bg = nodeBGSelected;
			node_fg = nodeFGSelected;
			node_border = nodeBorderSelected;
		} else if (hoveredNode != null && hoveredNode.getId().equals(node.getId())) {
			node_bg = nodeBGHovered;
			node_fg = nodeFGHovered;
			node_border = nodeBorderHovered;
		} else {
			node_bg = nodeBG;
			node_fg = nodeFG;
			node_border = nodeBorder;
		}

		Shape shape = GraphWrapper.getNodeShape(node);

		if (shape.isBox()) {
			paintBox(g, x, y, w, h, node_bg, node_border);
		} else if (shape.isEllipse()) {
			paintEllipse(g, x, y, w, h, node_bg, node_border);
		} else if (shape.isDiamond()) {
			paintDiamond(g, x, y, w, h, node_bg, node_border);
		} else {
			// defautl case, we draw a rectangle
			paintBox(g, x, y, w, h, node_bg, node_border);
		}

		String name = node.getLabel();
		int tw = metrics.stringWidth(name);
		int th = metrics.getAscent();

		g.setColor(node_fg);
		g.drawString(name, x + (w - tw) / 2, y + (h + th) / 2 - 1);
	}

	private void paintDiamond(Graphics2D g, int x, int y, int w, int h, Color node_bg, Color node_border) {
		g.setColor(node_bg);
		int[] xs = new int[] { x, x + w / 2, x + w, x + w / 2 };
		int[] ys = new int[] { y + h / 2, y, y + h / 2, y + h };

		g.fillPolygon(xs, ys, 4);
		g.setColor(node_border);
		g.drawPolygon(xs, ys, 4);
	}

	private void paintEllipse(Graphics2D g, int x, int y, int w, int h, Color node_bg, Color node_border) {
		g.setColor(node_bg);
		g.fillOval(x, y, w, h);
		g.setColor(node_border);
		g.drawOval(x, y, w, h);
	}

	private void paintBox(Graphics2D g, int x, int y, int w, int h, Color node_bg, Color node_border) {
		g.setColor(node_bg);
		g.fillRect(x, y, w, h);
		g.setColor(node_border);
		g.drawRect(x, y, w, h);
	}

	private void paintEdges(Graphics2D g) {
		EdgeList edges = graph.getEdges();

		while (!edges.isEmpty()) {
			Edge edge = edges.getHead();
			edges = edges.getTail();

			paintEdge(g, edge);
		}
	}

	private void paintEdge(Graphics2D g, Edge edge) {
		if (!edge.isPositioned()) {
			return;
		}

		Polygon poly = edge.getPolygon();

		Point from = poly.getHead();
		Point to = from;
		poly = poly.getTail();

		float fromx = (float) from.getX().intValue();
		float fromy = (float) from.getY().intValue();

		GeneralPath gp = new GeneralPath(GeneralPath.WIND_NON_ZERO);
		gp.moveTo(fromx, fromy);

		while (poly.hasTail() && !poly.getTail().isEmpty()) {
			Point cp1 = poly.getHead();
			poly = poly.getTail();
			Point cp2 = poly.getHead();
			poly = poly.getTail();
			Point cur = poly.getHead();
			poly = poly.getTail();

			from = cp1;
			to = cur;

			gp.curveTo(
				(float) cp1.getX().intValue(),
				(float) cp1.getY().intValue(),
				(float) cp2.getX().intValue(),
				(float) cp2.getY().intValue(),
				(float) cur.getX().intValue(),
				(float) cur.getY().intValue());
		}

		if (poly.hasHead()) {
			from = to;
			to = poly.getHead();
			poly = poly.getTail();
			gp.lineTo((float) to.getX().intValue(), (float) to.getY().intValue());
		}

		Graphics2D g2d = (Graphics2D) g;
		if (edge.connectedTo(hoveredNode)) {
			g2d.setColor(nodeBorderHovered);
		} else if (edge.connectedTo(selectedNode)) {
			g2d.setColor(nodeBorderSelected);
		} else {
			g2d.setColor(nodeBorder);
		}

		g2d.draw(gp);
    arrowHead(from, to, g2d);
	}

	private void arrowHead(Point from, Point to, Graphics2D g) {
		int x1 = from.getX().intValue();
		int y1 = from.getY().intValue();
		int x2 = to.getX().intValue();
		int y2 = to.getY().intValue();

    
		// calculate points for arrowhead
		double angle = Math.atan2(y2 - y1, x2 - x1) + Math.PI;
		double theta = Math.toRadians(ARROWHEAD_SHARPNESS); 
		double size = ARROWHEAD_LENGTH;

		int x3 = (int) (x2 + Math.cos(angle - theta) * size);
		int y3 = (int) (y2 + Math.sin(angle - theta) * size);

		int x4 = (int) (x2 + Math.cos(angle + theta) * size);
		int y4 = (int) (y2 + Math.sin(angle + theta) * size);

    int[] xs = new int[] {x2, x3, x4, x2};
    int[] ys = new int[] {y2, y3, y4, y2};

    g.fillPolygon(xs, ys, xs.length);
    g.drawPolygon(xs, ys, xs.length);
	}

	public Node getNodeAt(int mouse_x, int mouse_y) {
		if (graph == null) {
			return null;
		}

		NodeList nodes = graph.getNodes();

		Point2D mouse_coords = new Point2D.Float(mouse_x, mouse_y);
		Point2D coords;

		try {
			coords = transform.inverseTransform(mouse_coords, null);
		} catch (NoninvertibleTransformException e) {
			throw new RuntimeException("transform cannot be inverted?");
		}

		int x = (int) coords.getX();
		int y = (int) coords.getY();

		while (!nodes.isEmpty()) {
			Node node = nodes.getHead();
			nodes = nodes.getTail();

			if (node.isPositioned()) {
				int width = node.getWidth();
				int height = node.getHeight();

				if (x >= node.getX() - width / 2
					&& x < node.getX() + width / 2
					&& y >= node.getY() - height / 2
					&& y < node.getY() + height / 2) {
					return node;
				}
			}
		}

		return null;
	}

	public Node getNode(String name) {
		if (graph == null) {
			return null;
		}

		return graph.getNode(name);
	}

	public Node getSelectedNode() {
		return selectedNode;
	}

	public void setSelectedNode(Node node) {
		selectedNode = node;

		if (node != null) {
			Rectangle rect = getNodeRectangle(node);
			scrollRectToVisible(rect);
		}
		repaint();
	}

	public Rectangle getNodeRectangle(Node node) {
		float[] coords =
			{
				(float) node.getX() - node.getWidth() / 2,
				(float) node.getY() - node.getHeight() / 2,
				(float) node.getX() + node.getWidth() / 2,
				(float) node.getY() + node.getHeight() / 2 };

		float[] result = new float[4];

		transform.transform(coords, 0, result, 0, 2);

		return new Rectangle(
			(int) result[0],
			(int) result[1],
			(int) (result[2] - result[0]),
			(int) (result[3] - result[1]));
	}

	public void setScale(int scale) {
		transform = new AffineTransform();
		float rscale = ((float) scale) / 100;
		transform.scale(rscale, rscale);

		updateGeometry();
	}

	public Dimension getPreferredScrollableViewportSize() {
		return getPreferredSize();
	}

	public int getScrollableBlockIncrement(Rectangle visibleRect, int orientation, int direction) {
		switch (orientation) {
			case SwingConstants.VERTICAL :
				return visibleRect.width / 2;
			case SwingConstants.HORIZONTAL :
				return visibleRect.height / 2;
		}

		throw new RuntimeException("illegal orientation: " + orientation);
	}

	public int getScrollableUnitIncrement(Rectangle visibleRect, int orientation, int direction) {
		switch (orientation) {
			case SwingConstants.VERTICAL :
				return visibleRect.width / 8;
			case SwingConstants.HORIZONTAL :
				return visibleRect.height / 16;
		}

		throw new RuntimeException("illegal orientation: " + orientation);
	}

	public boolean getScrollableTracksViewportWidth() {
		return false;
	}

	public boolean getScrollableTracksViewportHeight() {
		return false;
	}

	public String getId() {
		return id;
	}

	public int getIndex() {
		return index;
	}

	public void setIndex(int index) {
		this.index = index;
	}

}
