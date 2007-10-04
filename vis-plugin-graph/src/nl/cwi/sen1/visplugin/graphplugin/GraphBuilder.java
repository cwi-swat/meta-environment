package nl.cwi.sen1.visplugin.graphplugin;

import java.util.HashMap;

import nl.cwi.sen1.gui.plugin.prefusedot.DotAdapter;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.Location;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.relationstores.types.RType;
import prefuse.data.Graph;
import prefuse.data.Node;

public class GraphBuilder {

	/**
	 * Cache/registry for created nodes.
	 */
	private HashMap<String, Node> m_nodeCache = new HashMap<String, Node>();

	/**
	 * Cache and register the Locations for created Nodes
	 * 
	 */
	private HashMap<String, Location> m_locCache = new HashMap<String, Location>();

	/**
	 * Factory used to create types.
	 * 
	 */
	private Factory m_factory;

	/**
	 * Supported graph relation.
	 * 
	 * @todo Needs better implementation needs to be resolved reflection,
	 *       dynamic dispatch... in a the base or utility class for all plugins,
	 *       remark by Anton G.
	 */
	private final String m_relationGraph = "relation([str,str])";

	private final String m_relationGraphTuple = "relation([tuple([str,loc]),tuple([str,loc])])";

	private final String m_attributedGraphTuple = "relation([tuple([str,relation([str,str])]),str])";

	/**
	 * @param factory
	 */
	public GraphBuilder(Factory factory) {
		m_factory = factory;
	}

	/**
	 * Convert RTuple into a Graph Dataset.
	 * 
	 * @param fact
	 *            RTuple with the data
	 * @return PieChart dataset
	 */
	public Graph buildGraphFromRTuple(RTuple fact) {
		RElem set = fact.getValue();
		RElemElements elements = set.getElements();

		// If the type is supported, create the dataset
		if (isRelStrStr(fact)) {
			return convertRelStrStrToDataset(elements);
		}

		if (isRelTupleTuple(fact)) {
			return convertRelTupleTupleToDataset(elements);
		}

		if (isAttributedGraphRelation(fact)) {
			return convertAttributedGraphDataset(elements);
		}

		return new Graph();
	}

	private Graph convertAttributedGraphDataset(RElemElements elements) {
		// Setup the new graph.
		m_nodeCache.clear();

		DotAdapter graph = new DotAdapter();

		try {
			while (elements.hasTail()) {
				RElem headElement = elements.getHead();
				// Replace the current looping set with: ( set - head ).
				elements = elements.getTail();

				RElemElements tupleRelation = headElement.getElements();
				RElem tuple1 = tupleRelation.getRElemAt(0);

				// Disassemble the tuple into its parts.
				String from = tuple1.getElements().getRElemAt(0).getStrCon();
				Node fromNode = getOrCreateNode(graph, from);

				String to = tupleRelation.getRElemAt(1).getStrCon();
				Node toNode = getOrCreateNode(graph, to);

				RElem attributes = tuple1.getElements().getRElemAt(1);
				if (attributes.isSet()) {
					RElemElements elems = attributes.getElements();
					boolean labelFound = false;

					for (; !elems.isEmpty(); elems = elems.getTail()) {
						RElem tuple = elems.getHead();
						if (!tuple.isTuple()
								&& tuple.getElements().getLength() == 2) {
							System.err
									.println("warning: attribute is not a tuple:"
											+ tuple);
							break;
						}
						RElem key = tuple.getElements().getRElemAt(0);
						RElem value = tuple.getElements().getRElemAt(1);
						if (value.isStr()) {
							graph.setNodeAttribute(fromNode, key
									.getStrCon(), value.getStrCon());

							if (key.getStrCon()
									.equals(GraphConstants.LABEL)) {
								labelFound = true;
							}
						} else {
							System.err
									.println("warning: attribute value not supported:"
											+ value);
						}
					}

					if (!labelFound) {
						graph.setNodeAttribute(fromNode, GraphConstants.LABEL,
								from);
					}
				} else {
					System.err.println("warning: ignoring graph attributes:"
							+ attributes);
				}

				if (toNode != null) {
					graph.addEdge(fromNode, toNode);
				}
			}
		} catch (UnsupportedOperationException e) {
			System.err.println("warning: " + e);
		}

		graph.doDotLayout();
		return graph;
	}

	/**
	 * Convert RTuple relation([tuple([str,loc]),tuple([str,loc])]) into a graph
	 * dataset. and register the Location attributes to allow click through.
	 * 
	 * @param elements
	 *            RTuple with the data
	 * @return Graph dataset for graph
	 * 
	 */
	private Graph convertRelTupleTupleToDataset(RElemElements elements) {
		// Setup the new graph.
		m_nodeCache.clear();

		DotAdapter graph = new DotAdapter();

		try {
			while (elements.hasTail()) {
				RElem headElement = elements.getHead();
				// Replace the current looping set with: ( set - head ).
				elements = elements.getTail();

				// HeadElement itselfs is a tuple <str,int>.
				RElemElements tupleRelation = headElement.getElements();
				RElem tuple1 = tupleRelation.getRElemAt(0);
				RElem tuple2 = tupleRelation.getRElemAt(1);

				// Disassemble the tuple into its parts.
				String nameId1 = tuple1.getElements().getRElemAt(0).getStrCon();
				Location loc1 = tuple1.getElements().getRElemAt(1)
						.getLocation();

				String nameId2 = tuple2.getElements().getRElemAt(0).getStrCon();
				Location loc2 = tuple2.getElements().getRElemAt(1)
						.getLocation();

				// Get or create nodes.
				Node nodeId1 = getOrCreateNode(graph, nameId1);
				Node nodeId2 = getOrCreateNode(graph, nameId2);

				// register the locations in the cache
				getOrCreateLocation(nameId1, loc1);

				if (nodeId2 != null) {
					getOrCreateLocation(nameId2, loc2);
					graph.addEdge(nodeId1, nodeId2);
				}
			}
		} catch (UnsupportedOperationException e) {
			System.err.println("warning: " + e);
		}

		graph.doDotLayout();
		return graph;
	}

	/**
	 * Convert RTuple relation([str,str]) into a graph dataset.
	 * 
	 * @param fact
	 *            RTuple with the data
	 * @return Graph dataset for graph
	 */
	private Graph convertRelStrStrToDataset(RElemElements elements) {
		// Setup the new graph.
		m_nodeCache.clear();
		boolean directedGraph = true;
		DotAdapter graph = new DotAdapter();

		while (elements.hasTail()) {
			RElem headElement = elements.getHead();
			// Replace the current looping set with: ( set - head ).
			elements = elements.getTail();

			// HeadElement itselfs is a tuple <str,int>.
			RElemElements tuple = headElement.getElements();

			// Disassemble the tuple into its parts.
			String nameId = tuple.getRElemAt(0).getStrCon();
			String nameLabel = tuple.getRElemAt(1).getStrCon();

			// Get or create nodes.
			Node nodeId = getOrCreateNode(graph, nameId);
			Node nodeLabel = getOrCreateNode(graph, nameLabel);

			if (nodeLabel != null) {
			  graph.addEdge(nodeId, nodeLabel);
			}
		}

		graph.doDotLayout();
		return graph;
	}

	/**
	 * Create (if it does not exist) or return the node identified by the
	 * nodeName
	 * 
	 * @param graph
	 * @param nodeName
	 * @return The node identified by the nodeName or a new node if no node
	 *         existed with this name.
	 */
	public Node getOrCreateNode(Graph graph, String nodeName) {
		Node node;

		if (nodeName.length() == 0) {
			return null;
		}

		// Check to see if node already exists.
		if (m_nodeCache.containsKey(nodeName)) {
			// If the node is already created, return node from cache.
			node = m_nodeCache.get(nodeName);
		} else {
			// Create a new node since it didnt exist.
			node = graph.addNode();
			node.setString(DotAdapter.DOT_ID, nodeName);
			node.setString(DotAdapter.DOT_LABEL, nodeName);
			m_nodeCache.put(nodeName, node);
		}

		return node;
	}

	/**
	 * Create (if it does not exist) or return the Location identified by the
	 * nodeName. When searching for a location giving a nodeId the nodeLocation
	 * must be zero. Then it returns null when nothing is found.
	 * 
	 * @param nodeName
	 *            The name of the location we are looking for or creating a
	 *            Location for
	 * @return The Location identified by the nodeName
	 * 
	 */
	public Location getOrCreateLocation(String nodeName, Location nodeLocation) {
		Location loc;

		// Check to see if node already exists.
		if (m_locCache.containsKey(nodeName)) {
			// If the node is already created, return node from cache.
			loc = m_locCache.get(nodeName);
		} else if (nodeLocation != null) {
			// Create a new node since it didnt exist.
			m_locCache.put(nodeName, nodeLocation);
			loc = nodeLocation;
		} else {
			loc = null;
		}

		return loc;
	}

	/**
	 * @param fact
	 * @return true if the RTuple contains a fact of the expected type
	 */
	private boolean isAttributedGraphRelation(RTuple fact) {
		RType rType = m_factory.RTypeFromString(m_attributedGraphTuple);
		return rType.equals(fact.getRtype());
	}

	/**
	 * Check to see if the RTuple is indeed a str,str relation.
	 * 
	 * @param fact
	 *            RTuple to test.
	 * @return True if it is the correct str,str type.
	 * 
	 * @todo Needs better implementation needs to be resolved reflection,
	 *       dynamic dispatch... in a the base or utility class for all plugins,
	 *       remark by Anton G.
	 */
	public boolean isRelStrStr(RTuple fact) {
		RType rType = m_factory.RTypeFromString(m_relationGraph);
		return rType.equals(fact.getRtype());
	}

	/**
	 * Check to see if the RTuple is indeed a tuple([str,loc]),tuple([str,loc])
	 * relation.
	 * 
	 * @param fact
	 *            RTuple to test.
	 * @return True if it is the correct str,str type.
	 */
	public boolean isRelTupleTuple(RTuple fact) {
		RType rType = m_factory.RTypeFromString(m_relationGraphTuple);
		return rType.equals(fact.getRtype());
	}

}
