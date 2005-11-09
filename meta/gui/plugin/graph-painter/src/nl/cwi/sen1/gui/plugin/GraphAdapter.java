package nl.cwi.sen1.gui.plugin;

import java.awt.FontMetrics;
import java.awt.geom.Point2D;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import aterm.ATermList;

import nl.cwi.sen.api.graph.graph.Factory;
import nl.cwi.sen.api.graph.graph.types.Attribute;
import nl.cwi.sen.api.graph.graph.types.AttributeList;
import nl.cwi.sen.api.graph.graph.types.Color;
import nl.cwi.sen.api.graph.graph.types.Edge;
import nl.cwi.sen.api.graph.graph.types.EdgeList;
import nl.cwi.sen.api.graph.graph.types.Graph;
import nl.cwi.sen.api.graph.graph.types.Node;
import nl.cwi.sen.api.graph.graph.types.NodeList;
import nl.cwi.sen.api.graph.graph.types.Point;
import nl.cwi.sen.api.graph.graph.types.Polygon;
import nl.cwi.sen.api.graph.graph.types.Shape;
import nl.cwi.sen.api.graph.graph.types.attribute.Location;
import nl.cwi.sen.api.graph.graph.types.attribute.Size;
import nl.cwi.sen1.util.Preferences;
import edu.berkeley.guir.prefuse.graph.DefaultGraph;
import edu.berkeley.guir.prefuse.graph.DefaultNode;

public class GraphAdapter extends DefaultGraph {
	public GraphAdapter(Graph graph) {
		super(true);
		Map nodeMap = new HashMap();

		for (NodeList nodes = graph.getNodes(); !nodes.isEmpty(); nodes = nodes
				.getTail()) {
			Node node = nodes.getHead();
			GraphNode pNode = new GraphNode();

			pNode.setId(node.getId().getId());
			pNode.setLabel(getNodeLabel(node));
			pNode.setDotX(getX(node));
			pNode.setDotY(getY(node));
			pNode.setDotWidth(getWidth(node));
			pNode.setDotHeight(getHeight(node));
			pNode.setShape(getShape(node));

			Color fillColor = getFillColorAttribute(node);

			if (fillColor != null) {
				pNode.setFillColor(new java.awt.Color(fillColor.getRed(),
						fillColor.getGreen(), fillColor.getBlue()));
			}
			
			Color color = getFillColorAttribute(node);

			if (color != null) {
				pNode.setColor(new java.awt.Color(color.getRed(),
						color.getGreen(), color.getBlue()));
			}

			nodeMap.put(node.getId(), pNode);
			addNode(pNode);
		}

		for (EdgeList edges = graph.getEdges(); !edges.isEmpty(); edges = edges
				.getTail()) {
			Edge edge = edges.getHead();
			DefaultNode fromNode = (DefaultNode) nodeMap.get(edge.getFrom());
			DefaultNode toNode = (DefaultNode) nodeMap.get(edge.getTo());
			GraphEdge pEdge = new GraphEdge(fromNode, toNode);
			
			pEdge.setDotControlPoints(getControlPoints(edge));

			addEdge(pEdge);
		}
	}

	private Point2D[] getControlPoints(Edge edge) {
		Polygon poly = getPolygon(edge);
		List points = new LinkedList();

        for ( ; !poly.isEmpty(); poly = poly.getTail()) {
            Point cp1 = poly.getHead();
            points.add(new Point2D.Float(cp1.getX(), cp1.getY()));
        }
        
        Point2D[] result = new Point2D[points.size()];
        Iterator iter = points.iterator();
        
        for (int i = 0; iter.hasNext(); i++) {
        	result[i] = (Point2D) iter.next();
        }
        
        return result;
	}

	private Polygon getPolygon(Edge edge) {
		AttributeList attrs = edge.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (attr.isCurvePoints()) {
				return attr.getPoints();
			}
			attrs = attrs.getTail();
		}

		return null;
	}
	
	private Shape getShape(Node node) {
		AttributeList attrs = node.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (attr.isShape()) {
				return (Shape) attr.getShape();
			}
			attrs = attrs.getTail();
		}

		return null;
	}

	static private Location getLocationAttribute(Node node) {
		AttributeList attrs = node.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (attr.isLocation()) {
				return (Location) attr;
			}
			attrs = attrs.getTail();
		}

		return null;
	}

	static public int getX(Node node) {
		Location location = getLocationAttribute(node);
		return location.getX();
	}

	static public int getY(Node node) {
		Location location = getLocationAttribute(node);
		return location.getY();
	}

	static public int getWidth(Node node) {
		Size size = getSizeAttribute(node);
		return size.getWidth();
	}

	static public int getHeight(Node node) {
		Size size = getSizeAttribute(node);
		return size.getHeight();
	}

	static private String getNodeLabel(Node node) {
		AttributeList attrs = node.getAttributes();

		for (; !attrs.isEmpty(); attrs = attrs.getTail()) {
			Attribute attr = attrs.getHead();
			if (attr.isLabel()) {
				return attr.getLabel();
			}
		}
		return node.getId().getId();
	}

	static private Size getSizeAttribute(Node node) {
		AttributeList attrs = node.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (attr.isSize()) {
				return (Size) attr;
			}
			attrs = attrs.getTail();
		}

		return null;
	}

	static private nl.cwi.sen.api.graph.graph.types.Color getFillColorAttribute(
			Node node) {
		AttributeList attrs = node.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (attr.isFillColor()) {
				return attr.getColor();
			}
			attrs = attrs.getTail();
		}

		return null;
	}

	static private Node setSizeAttribute(Node node, Size sizeAttr) {
		Factory factory = node.getGraphFactory();
		AttributeList result = factory.makeAttributeList();
		AttributeList attrs = node.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (!attr.isSize()) {
				result = factory.makeAttributeList(attr, result);
			}
			attrs = attrs.getTail();
		}

		result = factory.makeAttributeList(sizeAttr, result);
		return node.setAttributes(result);
	}

	static private Node setNodeSize(FontMetrics metrics, Preferences prefs,
			Node node) {
		Factory factory = node.getGraphFactory();
		int borderWidth = prefs.getInt("graph.node.border.width");
		int borderHeight = prefs.getInt("graph.node.border.height");
		String label = getNodeLabel(node);
		int width = metrics.stringWidth(label) + borderWidth * 2;
		int height = metrics.getHeight() + borderHeight * 2;

		return setSizeAttribute(node, factory.makeAttribute_Size(width, height));
	}

	static public Graph sizeGraph(FontMetrics metrics, Preferences prefs,
			Graph graph) {
		Factory factory = graph.getGraphFactory();
		NodeList nodes = graph.getNodes();
		NodeList result = factory.makeNodeList();

		for (; !nodes.isEmpty(); nodes = nodes.getTail()) {
			Node node = nodes.getHead();
			node = setNodeSize(metrics, prefs, node);
			result = factory.makeNodeList(node, result);
		}

		return graph.setNodes(result.reverseNodeList());
	}
}