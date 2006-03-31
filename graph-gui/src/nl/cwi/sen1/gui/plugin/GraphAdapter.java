package nl.cwi.sen1.gui.plugin;

import java.awt.FontMetrics;
import java.awt.geom.Point2D;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import nl.cwi.sen1.graph.Factory;
import nl.cwi.sen1.graph.types.Attribute;
import nl.cwi.sen1.graph.types.AttributeList;
import nl.cwi.sen1.graph.types.Color;
import nl.cwi.sen1.graph.types.Edge;
import nl.cwi.sen1.graph.types.EdgeList;
import nl.cwi.sen1.graph.types.Graph;
import nl.cwi.sen1.graph.types.Node;
import nl.cwi.sen1.graph.types.NodeId;
import nl.cwi.sen1.graph.types.NodeList;
import nl.cwi.sen1.graph.types.Point;
import nl.cwi.sen1.graph.types.Polygon;
import nl.cwi.sen1.graph.types.Shape;
import nl.cwi.sen1.graph.types.attribute.Location;
import nl.cwi.sen1.graph.types.attribute.Size;
import nl.cwi.sen1.util.Preferences;
import prefuse.util.ColorLib;

public class GraphAdapter extends prefuse.data.Graph {
    public GraphAdapter(nl.cwi.sen1.graph.types.Graph graph) {
        super(true);
        
        Map<NodeId, prefuse.data.Node> nodeMap = new HashMap<NodeId, prefuse.data.Node>();

        addColumn(GraphConstants.ID, String.class);
        addColumn(GraphConstants.LABEL, String.class);
        addColumn(GraphDotLayout.DOT_X, int.class);
        addColumn(GraphDotLayout.DOT_Y, int.class);
        addColumn(GraphDotLayout.DOT_WIDTH, int.class);
        addColumn(GraphDotLayout.DOT_HEIGHT, int.class);
        addColumn(GraphConstants.SHAPE, Shape.class);
        addColumn(GraphDotLayout.CURVE_POINTS, Point2D[].class);
        addColumn(GraphConstants.COLOR, int.class);
        addColumn(GraphConstants.FILLCOLOR, int.class);
        
        for (NodeList nodes = graph.getNodes(); !nodes.isEmpty(); nodes = nodes
                .getTail()) {
            Node node = nodes.getHead();

            prefuse.data.Node pNode = addNode();
            pNode.setString(GraphConstants.ID, node.getId().getId().toString());
            pNode.setString(GraphConstants.LABEL, getNodeLabel(node));
            pNode.setInt(GraphDotLayout.DOT_X, getX(node));
            pNode.setInt(GraphDotLayout.DOT_Y, getY(node));
            pNode.setInt(GraphDotLayout.DOT_WIDTH, getWidth(node));
            pNode.setInt(GraphDotLayout.DOT_HEIGHT, getHeight(node));
            pNode.set(GraphConstants.SHAPE, getShape(node));
            
            Color fillColor = getFillColorAttribute(node);
            
            if (fillColor != null) {
                pNode.setInt(GraphConstants.FILLCOLOR, ColorLib.rgb(fillColor.getRed(),
                        fillColor.getGreen(), fillColor.getBlue()));
            }
            
            Color color = getFillColorAttribute(node);
            
            if (color != null) {
                pNode.setInt(GraphConstants.COLOR, ColorLib.rgb(color.getRed(), color
                        .getGreen(), color.getBlue()));
            }

            nodeMap.put(node.getId(), pNode);
        }

        for (EdgeList edges = graph.getEdges(); !edges.isEmpty(); edges = edges
                .getTail()) {
            Edge edge = edges.getHead();
            prefuse.data.Node fromNode = nodeMap.get(edge.getFrom());
            prefuse.data.Node toNode = nodeMap.get(edge.getTo());
            prefuse.data.Edge pEdge = addEdge(fromNode, toNode);

            pEdge.set(GraphDotLayout.CURVE_POINTS, getControlPoints(edge));
        }
    }

    private Point2D[] getControlPoints(Edge edge) {
        Polygon poly = getPolygon(edge);
        List<Point2D> points = new LinkedList<Point2D>();

        for (; !poly.isEmpty(); poly = poly.getTail()) {
            Point cp1 = poly.getHead();
            points.add(new Point2D.Float(cp1.getX(), cp1.getY()));
        }

        Point2D[] result = new Point2D[points.size()];
        Iterator<Point2D> iter = points.iterator();

        for (int i = 0; iter.hasNext(); i++) {
            result[i] = iter.next();
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
                return attr.getShape();
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

    static private Color getFillColorAttribute(Node node) {
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
        return node.getId().getId().toString();
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
        int borderWidth = prefs.getInt(GraphConstants.NODE_BORDER_WIDTH);
        int borderHeight = prefs.getInt(GraphConstants.NODE_BORDER_HEIGHT);
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
