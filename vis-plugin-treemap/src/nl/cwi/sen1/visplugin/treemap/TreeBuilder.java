package nl.cwi.sen1.visplugin.treemap;

import java.util.Iterator;
import nl.cwi.sen1.relationstores.Factory;
import nl.cwi.sen1.relationstores.types.RElem;
import nl.cwi.sen1.relationstores.types.RElemElements;
import nl.cwi.sen1.relationstores.types.RTuple;
import nl.cwi.sen1.visplugin.VisualizationFactorySingleton;
import prefuse.data.Node;
import prefuse.data.Tree;
import java.util.HashMap;


/**
 * class TreeBuilder creates a tree from a given rstore file with a specific structure
 * relation([Loc,set(Loc),relation([str,int,relation([Loc,int])])]). The first Loc represents
 * a file, set(Loc) is set of files related to the first file.
 * relation([str,int,relation([Loc,int])]) is set of metric with its value related to the
 * first file with a set of same metric distributed over parts of the file.
 * the first Loc is required while the rest of the relation is optional.
 * For each first Loc is a node created, the rest of the relation become attributes of this node
 *
 * @author Qais
 *
 */
public class TreeBuilder {

	static Tree m_dataTree = null;
	static Tree tempTree = null;
	static HashMap<String, Integer> metricsMaxValue = new HashMap<String, Integer>();

	/**
	 * empty constructor
	 */
	public TreeBuilder(){}


	/**
	 *  The main method of the class. After creating an instance of this class
	 *  this method has to be called.
	 * @param rstoreFile
	 * @return
	 */
	public Tree buildTreeFromRStore(RTuple fact){
		try {
			RElem set = fact.getValue();
			RElemElements elements = set.getElements();
	    	makeNewTree();
	    	setTreeNodes(elements);
			removeNodesUpToSystem(); // remove the nodes up to root-node dir of the system
			//setTreemapWeights(); // set weights
	    	setOptionalNodeAttributes(elements);
		} catch (Exception e){
			e.printStackTrace();
		}
		return m_dataTree;
	}

	/**
	 * makes a new tree by creating a new root
	 */
	private void makeNewTree(){
		m_dataTree = new Tree();
		setRoot(m_dataTree, "root", "", 0, "in");
	}

	/**
	 * reads the the rstore relation and creates tree node for each file.
	 * It sets the set of links as node attributes for each node (file).
	 * @param elements the rstore main tuple relation
	 */
	private void setTreeNodes(RElemElements elements){
		while(elements.hasHead()){  // each rstore tuple
			RElem tuple = elements.getHead();
			RElemElements tupleElements = tuple.getElements();
			if(tupleElements.getHead().hasLocation()){  // here we get the fist element of relation([Loc,set(Loc),relation([Loc,int]),relation([str,int])] namely Loc
				String filePath = tupleElements.getHead().getLocation().getFilename();
				int countLinesCode = tupleElements.getHead().getLocation().getArea().getEndLine();
				addPathNodesToTree(m_dataTree, filePath, countLinesCode);
			}
			elements = elements.getTail();
		}
	}

	/**
	 * sets the optional attributes for each tree node "relation([str,int,relation([Loc,int])])"
	 * @param elements the rest of the rstore relation
	 */
	private void setOptionalNodeAttributes(RElemElements elements){
		String filePath ="";
		while(elements.hasHead()){  // each rstore tuple
			RElemElements tupleElements = elements.getHead().getElements();
			if(tupleElements.getHead().hasLocation()){
				filePath = tupleElements.getHead().getLocation().getFilename();
			}
			Node nextNode = getLastPathNode(m_dataTree, filePath);
			tupleElements = tupleElements.getTail();
			if(isSetLocations(tupleElements)){
				RElemElements  optionalElements = tupleElements.getHead().getElements();
				String setLinks = "";
				while(optionalElements.hasHead()){
					String pathName = optionalElements.getHead().getLocation().getFilename();
					setLinks += pathName+";";
					optionalElements = optionalElements.getTail();
				}
				setColumnValue(nextNode, "setLinks", setLinks);
				tupleElements = tupleElements.getTail();
			}
			parseOptionalMetrics(tupleElements ,nextNode);
			elements = elements.getTail();
		}
	}

	/**
	 * checks of the given element is a set of metrics
	 * @param elements
	 * @return
	 */
	private boolean isSetLocations(RElemElements elements){
		if(!elements.hasHead())return false;
		RElem relem = elements.getHead();
		if(!relem.hasElements())return false;
		RElemElements relements = relem.getElements();
		if(!relements.hasHead())return false;
		relem = relements.getHead();
		if(!relem.hasLocation())return false;
		return true;
	}

	/**
	 * parse the optional metrics (if exist)
	 * @param tupleElements
	 * @param nextNode
	 */
	private void parseOptionalMetrics(RElemElements tupleElements ,Node nextNode){
		if(isRelationMetrics(tupleElements)){
			RElemElements  optionalElements = tupleElements.getHead().getElements();
			String optionalMetric = "";
			while(optionalElements.hasHead()){
				RElemElements metrics = optionalElements.getHead().getElements();
				String metricName = metrics.getHead().getStrCon();
				int metricValue = metrics.getRElemAt(1).getInteger().getNatCon();
				setTotalMetricValue(nextNode, metricName, metricValue);
				try{
					int value = Integer.valueOf(metricValue);
					if(metricsMaxValue.containsKey(metricName)){
						int max = metricsMaxValue.get(metricName);
						if (value > max){
							metricsMaxValue.put(metricName, value);
						}
					} else {
						metricsMaxValue.put(metricName, value);
					}

				} catch(Exception e){
					e.printStackTrace();
				}
				optionalMetric += metricName+","+metricValue+";";
				if(metrics.getRElemAt(2).hasElements()){
					RElemElements parts = metrics.getRElemAt(2).getElements();
					String setMetricName = "set" + metricName;
					String setMetric = "";
					while(parts.hasHead()){ //  rel([Loc,int])
						RElemElements  optionalSet = parts.getHead().getElements();
						int beginLine = optionalSet.getHead().getLocation().getArea().getBeginLine();
						int endLine = optionalSet.getHead().getLocation().getArea().getEndLine();
						int cyclomaticComplexity = optionalSet.getRElemAt(1).getInteger().getNatCon();
						setMetric += beginLine +","+endLine+","+cyclomaticComplexity+";";
						parts = parts.getTail();
					}
					setColumnValue(nextNode, setMetricName, setMetric);
				}
				optionalElements = optionalElements.getTail();
			}
			if(optionalMetric != ""){
				setColumnValue(nextNode, "optionalMetrics", optionalMetric);
			}
		}
	}

	public HashMap<String, Integer> getMetricsMaxValues(){
		return metricsMaxValue;
	}

	/**
	 * checks of the given element is a set of metrics
	 * @param elements
	 * @return
	 */
	private boolean isRelationMetrics(RElemElements elements){
		if(!elements.hasHead())return false;
		RElem relem = elements.getHead();
		if(!relem.hasElements())return false;
		RElemElements relements = relem.getElements();
		if(!relements.hasHead())return false;
		relem = relements.getHead();
		if(!relem.hasElements())return false;
		relements = relem.getElements();
		if(!relements.hasHead()) return false;
		relem = relements.getHead();
		if(!relem.hasStrCon())return false;
		return true;
	}


	private void setTotalMetricValue(Node nextNode, String metricName, int value){
		if(!nextNode.canGet(metricName, Integer.TYPE)){
			nextNode.getTable().addColumn(metricName, Integer.TYPE);
		}
		nextNode.setInt(metricName, value);
	}


	/**
	 * fills the node attribute (node column) or creates a new column if it does not exist
	 * @param nextNode the node that gets the new attribute columnMName
	 * @param columnName name of the attribute type
	 * @param value the value of the attribute
	 */
	private void setColumnValue(Node nextNode, String columnName, String value){
		if(!nextNode.canGet(columnName, String.class)){
			nextNode.getTable().addColumn(columnName, String.class);
		}
		nextNode.setString(columnName, value);
	}

	/**
	 * @param tree
	 * @param filePath
	 * @param countLinesCode
	 * @return
	 */
	private Node addPathNodesToTree(Tree tree, String filePath , int countLinesCode){
		Node node = tree.getRoot();
		filePath = filePath.substring(1, filePath.length()); //remove the first char "/"
		String[] pathParts = filePath.split("/");
		int pathNameSize = pathParts.length;
		int index = 0;
		String path = "";
		String type = "in";
		for(String nodeName : pathParts){
			path += "/"+nodeName;
			if(index == pathNameSize-1 ){
				type = "leaf";
			}
			if(node.getChildCount() == 0){
				node = addChildToNode(m_dataTree, node,nodeName, path, countLinesCode, type);
			}else{
				boolean childExist = false;
				Iterator<Node> iter = node.children();
				while(iter.hasNext()){
					Node n = iter.next();
					if(n.getString("name").equals(nodeName)){
						node = n;
						node.setInt("Loc", countLinesCode + node.getInt("Loc"));
						childExist = true;
					}
				}
				if(!childExist){
					node = addChildToNode(m_dataTree, node,nodeName, path, countLinesCode, type);
				}
			}
			index++;
		}
		return node;
	}

	/**
	 * Adds a new node with given attributes to the tree
	 * @param tree the default tree
	 * @param parent the node that be the parent of the new node
	 * @param nodeName the name of the node
	 * @param path the path to the new node
	 * @param countLinesCode the Loc attribute of the node
	 * @param type the type of the node (file or directory)
	 * @return the new added node
	 */
	private Node addChildToNode(Tree tree, Node parent, String nodeName, String path, int countLinesCode, String type){
		Node nextNode = tree.addChild(parent);
		nextNode.setString("name", nodeName);
		nextNode.setString("path", path);
		nextNode.setString("type", type);
		nextNode.setInt("Loc", countLinesCode);
		if(metricsMaxValue.containsKey("Loc")){
			int max = metricsMaxValue.get("Loc");
			if (countLinesCode > max){
				metricsMaxValue.put("Loc", countLinesCode);
			}
		} else {
			metricsMaxValue.put("Loc", countLinesCode);
		}
		return nextNode;
	}

	/**
	 * sets the root of a new tree
	 * @param tree the new tree
	 * @param name name of the root node , represents the main directory of the software system
	 * @param path path to the file the node represents
	 * @param Loc Loc attribute of the file the node represents
	 * @param type the type of the node (file of directory)
	 */
	private void setRoot(Tree tree, String name, String path, int Loc, String type){
		tree.addRoot();
		tree.getRoot().getTable().addColumn("name", String.class);
		tree.getRoot().getTable().addColumn("path", String.class);
		tree.getRoot().getTable().addColumn("type", String.class);
		tree.getRoot().getTable().addColumn("Loc", Integer.TYPE);
		tree.getRoot().setString("name", name);
		tree.getRoot().setString("path", path);
		tree.getRoot().setString("type", type);
		tree.getRoot().setInt("Loc", Loc);
	}

	/**
	 * removes the insignificant number of start nodes of the tree, because they form no part
	 * of the software system. The absolute-path begins always from the root directory of the operating system.
	 */
	private void removeNodesUpToSystem(){
		// find the systemRoot-node
		Node nextNode = m_dataTree.getRoot();
		while(nextNode.getChildCount() == 1){
			nextNode = nextNode.getFirstChild();
		}
		// replace the tree with the subtree
		tempTree = new Tree();
		setRoot(tempTree, nextNode.getString("name"), nextNode.getString("path"), nextNode.getInt("Loc"),nextNode.getString("type"));
		copySubtree(nextNode,tempTree.getRoot());
		m_dataTree = tempTree;
	}

	/**
	 * Its not possible to change the root of a Prefuse tree. Therefore we make a new tree by
	 * coping a part of the tree to a new tree
	 * @param currentTreeNode the current tree
	 * @param newTreeNode the new tree
	 */
	@SuppressWarnings("unchecked")
	private void copySubtree(Node currentTreeNode, Node newTreeNode){
		Iterator<Node> iter = currentTreeNode.children();
		while(iter.hasNext()){
			Node nextChild = iter.next();
			Node n = tempTree.addChild(newTreeNode);
			n.setString("name", nextChild.getString("name"));
			n.setString("path", nextChild.getString("path"));
			n.setString("type", nextChild.getString("type"));
			n.setInt("Loc", nextChild.getInt("Loc"));
			if(!n.canGet("linked", Integer.TYPE)){
				n.getTable().addColumn("linked", Integer.TYPE);
			}
			n.setInt("linked", 0);
			copySubtree(nextChild, n);
		}
	}

	/**
	 * returns the node represented with the last file of an absolute path
	 * it gets the node from the tree. ( A file path represents a tree path
	 * from the node to a leaf node represented with the last file path )
	 * @param tree the tree
	 * @param filePath the file path.
	 * @return
	 */
	private Node getLastPathNode(Tree tree, String filePath){
		Node nextNode = tree.getRoot();
		filePath = filePath.substring(1, filePath.length());
		String[] pathParts = filePath.split("/");
		for(String  nextPart : pathParts){
			Iterator<Node> iter = nextNode.children();
			while(iter.hasNext()){
				Node node = iter.next();
				if(node.getString("name").equals(nextPart)){
					nextNode = node;
				}
			}
		}
		return nextNode;
	}

}
