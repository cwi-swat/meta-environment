package nl.dancingbear.visplugin.graphplugin;

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

/**
 * 
 * @author A. Belgraver
 * @author Anton Gerdessen (reviewer)
 * @date 07-3-2007
 */
public class GraphBuilder {

	/**
	 * Cache/registry for created nodes.
	 * 
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
	 */
	private HashMap<String, Node> m_nodeCache = new HashMap<String, Node>();

	/**
	 * Cache and register the Locations for created Nodes
	 * 
	 * @author Renze de Vries
	 * @date 14-03-2007
	 */
	private HashMap<String, Location> m_locCache = new HashMap<String, Location>();

	/**
	 * Factory used to create types.
	 * 
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
	 */
	private Factory m_factory;

	/**
	 * Supported graph relation.
	 * 
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
	 * @todo Needs better implementation needs to be resolved reflection,
	 *       dynamic dispatch... in a the base or utility class for all plugins,
	 *       remark by Anton G.
	 */
	private final String m_relationGraph = "relation([str,str])";

	private final String m_relationGraphTuple = "relation([tuple([str,loc]),tuple([str,loc])])";

	/**
	 * @param factory
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
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
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
	 */
	public Graph buildGraphFromRTuple(RTuple fact) {
		RElem set = fact.getValue();
		RElemElements elements = set.getElements();

		System.out.println("[GRAPH] building graph");

		// If the type is supported, create the dataset
		if (isRelStrStr(fact)) {
			return convertRelStrStrToDataset(elements);
		}

		if (isRelTupleTuple(fact)) {
			System.out.println("[GRAPH] it was a tuple,tuple");
			return convertRelTupleTupleToDataset(elements);
		}

		return new Graph();
	}

	/**
	 * Convert RTuple relation([tuple([str,loc]),tuple([str,loc])]) into a graph
	 * dataset. and register the Location attributes to allow click through.
	 * 
	 * @param elements
	 *            RTuple with the data
	 * @return Graph dataset for graph
	 * 
	 * @author Renze de Vries
	 * @date 14-03-2007
	 */
	private Graph convertRelTupleTupleToDataset(RElemElements elements) {
		// Setup the new graph.
		m_nodeCache.clear();
//		boolean directedGraph = true;
//		Graph graph = new Graph(directedGraph);

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
				getOrCreateLocation(nameId2, loc2);

				// Create edges between nodes.
				graph.addEdge(nodeId1, nodeId2);
			}
		} catch (UnsupportedOperationException e) {
			System.err.println("warning: " + e);
		}

		graph.doDotLayout();
		return graph;
	}

	/**
	 * Convert RTuple relation([str,int]) into a graph dataset.
	 * 
	 * @param fact
	 *            RTuple with the data
	 * @return Graph dataset for graph
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
	 */
	private Graph convertRelStrStrToDataset(RElemElements elements) {
		// Setup the new graph.
		m_nodeCache.clear();
		boolean directedGraph = true;
		Graph graph = new Graph(directedGraph);

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

			// Create edges between nodes.
			graph.addEdge(nodeId, nodeLabel);
		}

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
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
	 */
	public Node getOrCreateNode(Graph graph, String nodeName) {
		Node node;

		// Check to see if node already exists.
		if (m_nodeCache.containsKey(nodeName)) {
			// If the node is already created, return node from cache.
			node = (Node) m_nodeCache.get(nodeName);
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
	 * @author Renze de Vries
	 * @date 14-3-2007
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
	 * Check to see if the RTuple is indeed a str,str relation.
	 * 
	 * @param fact
	 *            RTuple to test.
	 * @return True if it is the correct str,str type.
	 * @author A. Belgraver
	 * @author Anton Gerdessen (reviewer)
	 * @date 07-3-2007
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
	 * @author Renze de Vries
	 * @date 13-3-2007
	 */
	public boolean isRelTupleTuple(RTuple fact) {
		RType rType = m_factory.RTypeFromString(m_relationGraphTuple);
		return rType.equals(fact.getRtype());
	}

}
