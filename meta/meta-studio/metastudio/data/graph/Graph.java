package metastudio.data.graph;

import java.util.ArrayList;
import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.Vector;

import metastudio.components.graphs.NodeSizer;

import aterm.ATerm;
import aterm.ATermList;

public abstract class Graph
extends GraphImpl
{
  Graph(MetaGraphFactory factory) {
    super(factory);
  }

  public static Shape getNodeShape(Node n) {
	  AttributeList list = n.getAttributes();

	  while (!list.isEmpty()) {
		  Attribute head = list.getHead();

		  if (head.isShape()) {
			  return head.getShape();
		  }

		  list = list.getTail();
	  }

	  return null;
  }

  public static ATerm getNodeInfo(String key, Node n) {
	  AttributeList list = n.getAttributes();

	  while (!list.isEmpty()) {
		  Attribute head = list.getHead();

		  if (head.isInfo()) {
			  if (head.getKey().equals(key)) {
				  return head.getValue();
			  }
		  }

		  list = list.getTail();
	  }

	  return null;
  }

  public Node getNode(String id) {
	  NodeList nodes = getNodes();
	  while (!nodes.isEmpty()) {
		  Node node = nodes.getHead();
		  if (node.getId().getId().equals(id)) {
			  return node;
		  }

		  nodes = nodes.getTail();
	  }

	  return null;
  }

  public static NodeList deleteNodeFromNodes(String id, NodeList nodes) {
      MetaGraphFactory factory = nodes.getMetaGraphFactory();
	  Vector nodeVector = new Vector();
	  while (!nodes.isEmpty()) {
		  Node node = nodes.getHead();
		  if (!node.getId().getId().equals(id)) {
			  nodeVector.addElement(node);
		  }

		  nodes = nodes.getTail();
	  }

	  NodeList newNodes = factory.makeNodeList_Empty();
	  //for (int i = nodeVector.size() - 1; i >= 0; i--) {
	  for (int i = 0; i < nodeVector.size(); i++) {
		  Node node = (Node) nodeVector.elementAt(i);
		  newNodes = factory.makeNodeList_Multi(node, newNodes);
	  }

	  return newNodes;
  }

  public Graph sizeNodes(NodeSizer nodeSizer) {
          Graph newGraph;
	  NodeList nodes = getNodes();
	  List nodeList = new ArrayList();

	  while (!nodes.isEmpty()) {
		  Node node = nodes.getHead();

		  node = nodeSizer.sizeNode(node);
		  nodeList.add(node);

		  nodes = nodes.getTail();
	  }

	  NodeList result = factory.makeNodeList_Empty();
	  for (int i = nodeList.size() - 1; i >= 0; i--) {
		  Node node = (Node) nodeList.get(i);
		  result = factory.makeNodeList_Multi(node, result);
	  }
	  newGraph = setNodes(result);
	  return newGraph;
  }

  public static boolean isTopNode(Graph graph, Node node) {
	  EdgeList edges = graph.getEdges();
	  while (!edges.isEmpty()) {
		  Edge edge = edges.getHead();
		  if (edge.getFrom().isEqual(node.getId())) {
			  return false;
		  }
		  edges = edges.getTail();
	  }

	  return true;
  }

  public static Graph fromImportList(MetaGraphFactory factory, ATermList imports) {
	  Set nodeSet = new HashSet();
	  List nodeSequence = new LinkedList();

	  EdgeList edges = factory.makeEdgeList_Empty();

	  while (!imports.isEmpty()) {
		  ATermList pair = (ATermList) imports.getFirst();
		  imports = imports.getNext();

		  ATerm fromTerm = pair.getFirst();
		  if (nodeSet.add(fromTerm)) {
			  nodeSequence.add(fromTerm);
		  }
		  ATermList elems = (ATermList) pair.getNext().getFirst();

		  while (!elems.isEmpty()) {
			  ATerm toTerm = elems.getFirst();
			  elems = elems.getNext();

			  NodeId from = factory.NodeIdFromTerm(fromTerm);
			  NodeId to = factory.NodeIdFromTerm(toTerm);

			  if (nodeSet.add(toTerm)) {
				  nodeSequence.add(toTerm);
			  }

			  AttributeList attrs = factory.makeAttributeList_Empty();
			  Edge edge = factory.makeEdge_Default(from, to, attrs);
			  edges = factory.makeEdgeList_Multi(edge, edges);
		  }
	  }

	  NodeList nodes = factory.makeNodeList_Empty();

	  Iterator iter = nodeSequence.iterator();
	  while (iter.hasNext()) {
		  ATerm name = (ATerm) iter.next();
		  NodeId id = factory.NodeIdFromTerm(name);
		  Shape shape = factory.makeShape_Box();
		  Attribute attr = factory.makeAttribute_Shape(shape);
		  AttributeList attrs = factory.makeAttributeList_Empty();
		  attrs = factory.makeAttributeList_Multi(attr, attrs);
		  Node node = factory.makeNode_Default(id, attrs);
		  nodes = factory.makeNodeList_Multi(node, nodes);
	  }

	  return factory.makeGraph_Default(nodes, edges, factory.makeAttributeList_Empty());
  }

  public Attribute getBoundingBox() {
	  AttributeList attrs = getAttributes();

	  for (; !attrs.isEmpty(); attrs = attrs.getTail()) {
		  Attribute attr = attrs.getHead();
		  if (attr.isBoundingBox()) {
			  return attr;
		  }
	  }

	  return null;
  }
  
  static public Node getRootNode(Graph graph) {
      NodeList nodes = graph.getNodes();
      
      for ( ; !nodes.isEmpty(); nodes = nodes.getTail()) {
          Node node = nodes.getHead();
          List children = getParents(graph, node);
          if (children.size() == 0) {
              return node;
          }
      }
      
      return null;
  }
  
  static public Node findNode(Graph graph, String name) {
      NodeList nodes = graph.getNodes();
      for ( ; !nodes.isEmpty(); nodes = nodes.getTail()) {
          Node node = nodes.getHead();
          String nodeId = node.getId().getId();
          if (nodeId.equals(name)) {
              return node;
              
          }
      }
      
      return null;
  }
  
  static  public List getChildren(Graph graph, Node node) {
      String id = node.getId().getId();
      List children = new LinkedList();
      EdgeList edges = graph.getEdges();

      for ( ; !edges.isEmpty(); edges = edges.getTail()) {
          Edge edge = edges.getHead();
          String toId = edge.getTo().getId();
          String fromId = edge.getFrom().getId();
          if (fromId.equals(id)) {
              children.add(0, findNode(graph, toId));
          }
      }
      
      return children;
  }
  
  static public List getParents(Graph graph, Node node) {
      String id = node.getId().getId();
      List parents = new LinkedList();
      EdgeList edges = graph.getEdges();
      
      for ( ; !edges.isEmpty(); edges = edges.getTail()) {
          Edge edge = edges.getHead();
          String toId = edge.getTo().getId();
          String fromId = edge.getFrom().getId();
          if (toId.equals(id)) {
              parents.add(findNode(graph, fromId));
          }
      }
      
      return parents;
  }
}
