package metastudio.graph;

import java.util.*;
import java.util.List;
import java.awt.*;
import java.awt.event.*;
import java.awt.geom.*;
import javax.swing.*;

import metastudio.Preferences;

public class GraphPanel
  extends JComponent
{
  //{{{ Preference names

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


  //}}}

  private Graph graph;

  private int max_x;
  private int max_y;

  private FontMetrics metrics;
  private AffineTransform transform;

  private Node hoveredNode;
  private Node selectedNode;

  //{{{ public GraphPanel()

  public GraphPanel()
  {
    transform = new AffineTransform();
    setAutoscrolls(true);

    MouseMotionListener mouseMotionListener
      = new MouseMotionAdapter() {
	public void mouseMoved(MouseEvent event)
	{
	  Node node = getNodeAt(event.getX(), event.getY());
	  if ((node == null && hoveredNode != null)
	      || (node != null
		  && (hoveredNode == null
		      || !hoveredNode.getName().equals(node.getName())))) {
	    hoveredNode = node;
	    repaint();
	  }
	}
	public void mouseDragged(MouseEvent e) {
	  Rectangle r = new Rectangle(e.getX(), e.getY(), 1, 1);
	  ((JComponent)e.getSource()).scrollRectToVisible(r);
	}
	public void mouseExited(MouseEvent event)
	{
	  hoveredNode = null;
	  repaint();
	}
      };
    addMouseMotionListener(mouseMotionListener);

  }

  //}}}

  //{{{ public void setGraph(Graph graph)

  public void setGraph(Graph graph)
  {
    this.graph = graph;
    updateGeometry();
  }

  //}}}

  //{{{ private void updateGeometry()

  private void updateGeometry()
  {
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

  //}}}
  //{{{ private void calcBoundingBox()

  private void calcBoundingBox()
  {
    int max_x = 0;
    int max_y = 0;

    Graphics g = getGraphics();
    g.setFont(Preferences.getFont(PREF_NODE_FONT));
    metrics = g.getFontMetrics();

    NodeList nodes = graph.getNodes();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      nodes = nodes.getTail();

      int right_x = node.getX()+node.getWidth()/2;
      int bottom_y = node.getY()+node.getHeight()/2;

      max_x = Math.max(right_x, max_x);
      max_y = Math.max(bottom_y, max_y);
    }

    Point2D point
      = transform.transform(new Point2D.Float((float)max_x, (float)max_y),
			    null);

    this.max_x = (int)point.getX();
    this.max_y = (int)point.getY();
  }

  //}}}

  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
    g.setColor(getBackground());
    g.fillRect(0, 0, getSize().width, getSize().height);

    if (graph != null) {
      Graphics2D g2d = (Graphics2D)g;
      g2d.setRenderingHint(RenderingHints.KEY_ANTIALIASING,
			   RenderingHints.VALUE_ANTIALIAS_ON);
      g2d.transform(transform);
      Stroke stroke = g2d.getStroke();
      //g2d.setStroke(new BasicStroke((float)1.5));
      paintNodes(g2d);
      paintEdges(g2d);
    }
  }

  //}}}

  //{{{ public Dimension getPreferredSize()

  public Dimension getPreferredSize()
  {
    return new Dimension(max_x+5, max_y+5);
  }

  //}}}
  //{{{ public Dimension getMinimumSize()

  public Dimension getMinimumSize()
  {
    return getPreferredSize();
  }

  //}}}

  //{{{ private void paintNodes(Graphics2D g)

  private void paintNodes(Graphics2D g)
  {
    g.setFont(Preferences.getFont(PREF_NODE_FONT));
    metrics = g.getFontMetrics();

    NodeList nodes = graph.getNodes();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      nodes = nodes.getTail();

      paintNode(g, node);
    }
  }

  //}}}
  //{{{ private void paintNode(Graphics2D g, Node node)

  private void paintNode(Graphics2D g, Node node)
  {
    if (!node.isPositioned()) {
      return;
    }

    int x = node.getX();
    int y = node.getY();
    int w = node.getWidth();
    int h = node.getHeight();

    x -= w/2;
    y -= h/2;

    Color node_bg = Preferences.getColor(PREF_NODE_BG);
    Color node_fg = Preferences.getColor(PREF_NODE_FG);
    Color node_border = Preferences.getColor(PREF_NODE_BORDER);
    if (selectedNode != null
	&& selectedNode.getName().equals(node.getName())) {
      node_bg = Preferences.getColor(PREF_NODE_SELECTED_BG);
      node_fg = Preferences.getColor(PREF_NODE_SELECTED_FG);
      node_border = Preferences.getColor(PREF_NODE_SELECTED_BORDER);
    } else if (hoveredNode != null
	&& hoveredNode.getName().equals(node.getName())) {
      node_bg = Preferences.getColor(PREF_NODE_HOVERED_BG);
      node_fg = Preferences.getColor(PREF_NODE_HOVERED_FG);
      node_border = Preferences.getColor(PREF_NODE_HOVERED_BORDER);
    }
    g.setColor(node_bg);
    g.fillRect(x, y, w, h);

    g.setColor(node_border);
    g.drawRect(x, y, w, h);

    String name = node.getName();
    int tw = metrics.stringWidth(name);
    int th = metrics.getAscent();

    g.setColor(node_fg);
    g.drawString(name, x+(w-tw)/2, y+(h+th)/2-1);

    //g.setColor(Color.black);
    //g.drawString("(" + x + "," + y + ")", x, y);
  }

  //}}}

  //{{{ private void paintEdges(Graphics2D g)

  private void paintEdges(Graphics2D g)
  {
    EdgeList edges = graph.getEdges();

    while (!edges.isEmpty()) {
      Edge edge = edges.getHead();
      edges = edges.getTail();

      paintEdge(g, edge);
    }
  }

  //}}}
  //{{{ private void paintEdge(Graphics2D g, Edge edge)

  private void paintEdge(Graphics2D g, Edge edge)
  {
    if (!edge.isPositioned()) {
      return;
    }

    Polygon poly = edge.getPolygon();
    Point from = poly.getHead();
    poly = poly.getTail();

    float fromx = (float)from.getX();
    float fromy = (float)from.getY();

    GeneralPath gp = new GeneralPath(GeneralPath.WIND_NON_ZERO);
    gp.moveTo(fromx, fromy);

    while (!poly.getTail().isEmpty()) {
      Point cp1 = poly.getHead();
      poly = poly.getTail();
      Point cp2 = poly.getHead();
      poly = poly.getTail();
      Point cur = poly.getHead();
      poly = poly.getTail();

      gp.curveTo((float)cp1.getX(), (float)cp1.getY(),
		 (float)cp2.getX(), (float)cp2.getY(),
		 (float)cur.getX(), (float)cur.getY());
    }
    Point to = poly.getHead();
    poly = poly.getTail();
    //assert poly.isEmpty();

    gp.lineTo((float)to.getX(), (float)to.getY());

    Graphics2D g2d = (Graphics2D)g;
    if (edge.connectedTo(hoveredNode)) {
      g2d.setColor(Preferences.getColor(PREF_NODE_HOVERED_BORDER));
    } else if (edge.connectedTo(selectedNode)) {
      g2d.setColor(Preferences.getColor(PREF_NODE_SELECTED_BORDER));
    } else {
      g2d.setColor(Preferences.getColor(PREF_NODE_BORDER));
    }
    g2d.draw(gp);
  }

  //}}}

  //{{{ public Node getNodeAt(int x, int y)

  public Node getNodeAt(int mouse_x, int mouse_y)
  {
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

    int x = (int)coords.getX();
    int y = (int)coords.getY();

    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      nodes = nodes.getTail();

      if (node.isPositioned()) {
	int width = node.getWidth();
	int height = node.getHeight();

	if (x >= node.getX() - width/2 && x < node.getX() + width/2
	    && y >= node.getY() - height/2 && y < node.getY() + height/2) {
	  return node;
	}
      }
    }

    return null;
  }

  //}}}
  //{{{ public Node getNode(String name)

  public Node getNode(String name)
  {
    if (graph == null) {
      return null;
    }

    return graph.getNode(name);
  }

  //}}}
  //{{{ public Node getSelectedNode()

  public Node getSelectedNode()
  {
    return selectedNode;
  }

  //}}}
  //{{{ public void setSelectedNode(Node node)

  public void setSelectedNode(Node node)
  {
    selectedNode = node;

    if (node != null) {
      Rectangle rect = getNodeRectangle(node);
      scrollRectToVisible(rect);
    }
    repaint();
  }

  //}}}

  //{{{ public Rectangle getNodeRectangle(Node node)

  public Rectangle getNodeRectangle(Node node)
  {
    float[] coords = {
      (float)node.getX() - node.getWidth()/2,
      (float)node.getY() - node.getHeight()/2,
      (float)node.getX() + node.getWidth()/2,
      (float)node.getY() + node.getHeight()/2
    };

    float[] result = new float[4];

    transform.transform(coords, 0, result, 0, 2);

    return new Rectangle((int)result[0],
			 (int)result[1],
			 (int)(result[2]-result[0]),
			 (int)(result[3]-result[1]));
  }

  //}}}

  //{{{ public void setScale(int scale)

  public void setScale(int scale)
  {
    transform = new AffineTransform();
    float rscale = ((float)scale)/100;
    transform.scale(rscale, rscale);

    updateGeometry();
  }

  //}}}
}
