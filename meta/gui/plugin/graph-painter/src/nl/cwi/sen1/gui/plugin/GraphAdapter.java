package nl.cwi.sen1.gui.plugin;

import java.awt.FontMetrics;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.sen.api.graph.graph.Factory;
import nl.cwi.sen.api.graph.graph.types.Attribute;
import nl.cwi.sen.api.graph.graph.types.AttributeList;
import nl.cwi.sen.api.graph.graph.types.Edge;
import nl.cwi.sen.api.graph.graph.types.EdgeList;
import nl.cwi.sen.api.graph.graph.types.Graph;
import nl.cwi.sen.api.graph.graph.types.Node;
import nl.cwi.sen.api.graph.graph.types.NodeList;
import nl.cwi.sen.api.graph.graph.types.attribute.Location;
import nl.cwi.sen.api.graph.graph.types.attribute.Size;
import nl.cwi.sen1.util.Preferences;
import edu.berkeley.guir.prefuse.graph.DefaultEdge;
import edu.berkeley.guir.prefuse.graph.DefaultGraph;
import edu.berkeley.guir.prefuse.graph.DefaultNode;

public class GraphAdapter extends DefaultGraph {
	public GraphAdapter(Graph graph) {
		super(true);
		Map nodeMap = new HashMap();

		for (NodeList nodes = graph.getNodes(); !nodes.isEmpty(); nodes = nodes
				.getTail()) {
			Node node = nodes.getHead();
			DefaultNode pNode = new DefaultNode();

			pNode.setAttribute("id", node.getId().getId());
			pNode.setAttribute("label", getNodeLabel(node));
			pNode.setAttribute("dot.x", new Integer(getX(node)).toString());
			pNode.setAttribute("dot.y", new Integer(getY(node)).toString());
			pNode.setAttribute("dot.width", new Integer(getWidth(node))
					.toString());
			pNode.setAttribute("dot.height", new Integer(getHeight(node))
					.toString());

			nodeMap.put(node.getId(), pNode);
			addNode(pNode);
		}

		for (EdgeList edges = graph.getEdges(); !edges.isEmpty(); edges = edges
				.getTail()) {
			Edge edge = edges.getHead();
			DefaultNode fromNode = (DefaultNode) nodeMap.get(edge.getFrom());
			DefaultNode toNode = (DefaultNode) nodeMap.get(edge.getTo());
			DefaultEdge pEdge = new DefaultEdge(fromNode, toNode, true);

			addEdge(pEdge);
		}
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

	static private Node setSizeAttribute(Node node, Size sizeAttr) {
		Factory factory = node.getGraphFactory();
		AttributeList result = factory.makeAttributeList_Empty();
		AttributeList attrs = node.getAttributes();
		while (!attrs.isEmpty()) {
			Attribute attr = attrs.getHead();
			if (!attr.isSize()) {
				result = factory.makeAttributeList_Multi(attr, result);
			}
			attrs = attrs.getTail();
		}

		result = factory.makeAttributeList_Multi(sizeAttr, result);
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
		NodeList result = factory.makeNodeList_Empty();

		for (; !nodes.isEmpty(); nodes = nodes.getTail()) {
			Node node = nodes.getHead();
			node = setNodeSize(metrics, prefs, node);
			result = factory.makeNodeList_Multi(node, result);
		}

		return graph.setNodes(result);
	}
}