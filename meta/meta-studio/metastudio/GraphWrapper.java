package metastudio;

import java.util.*;

import metastudio.graph.Attribute;
import metastudio.graph.AttributeList;
import metastudio.graph.Edge;
import metastudio.graph.EdgeList;
import metastudio.graph.Graph;
import metastudio.graph.MetaGraphFactory;
import metastudio.graph.Node;
import metastudio.graph.NodeId;
import metastudio.graph.NodeList;
import metastudio.graph.Shape;
import aterm.*;

public class GraphWrapper
{
  private Graph graph;
  private MetaGraphFactory factory;

  //{{{ private GraphWrapper(Graph graph)

  private GraphWrapper(Graph graph)
  {
    this.graph = graph;
    this.factory = graph.getMetaGraphFactory();
  }

  //}}}

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
    
  //{{{ public Node getNode(String id)

  public Node getNode(String id)
  {
    NodeList nodes = graph.getNodes();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      if (node.getId().getId().equals(id)) {
	return node;
      }

      nodes = nodes.getTail();
    }

    return null;
  }

  //}}}

  //{{{ private void deleteNodeFromNodes(String id)

  private NodeList deleteNodeFromNodes(String id, NodeList nodes)
  {
    Vector nodeVector = new Vector();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      if (!node.getId().getId().equals(id)) {
	nodeVector.addElement(node);
      }

      nodes = nodes.getTail();
    }

    NodeList newNodes = factory.makeNodeList_Empty();
    for (int i=nodeVector.size()-1; i>=0; i--) {
      Node node = (Node)nodeVector.elementAt(i);
      newNodes = factory.makeNodeList_Multi(node, newNodes);
    }

    return newNodes;
  }

  //}}}
  //{{{ private void deleteNodeFromEdges(String id)

  private EdgeList deleteNodeFromEdges(String id, EdgeList edges)
  {
    EdgeList newEdges = factory.makeEdgeList_Empty();
    while (!edges.isEmpty()) {
      Edge edge = edges.getHead();
      if (!edge.getFrom().getId().equals(id) && !edge.getTo().getId().equals(id)) {
	newEdges = factory.makeEdgeList_Multi(edge, newEdges);
      }

      edges = edges.getTail();
    }

    return newEdges;
  }

  //}}}

  //{{{ public void deleteNode(String id)

  public void deleteNode(String id)
  {
    graph = graph.setNodes(deleteNodeFromNodes(id, graph.getNodes()));
    graph = graph.setEdges(deleteNodeFromEdges(id, graph.getEdges()));
  }

  //}}}
  //{{{ public void sizeNodes(NodeSizer nodeSizer)

  public void sizeNodes(NodeSizer nodeSizer)
  {
    NodeList nodes = graph.getNodes();
    List nodeList = new ArrayList();

    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();

      node = nodeSizer.sizeNode(node);
      nodeList.add(node);

      nodes = nodes.getTail();
    }

    NodeList result = factory.makeNodeList_Empty();
    for (int i=nodeList.size()-1; i>=0; i--) {
      Node node = (Node)nodeList.get(i);
      result = factory.makeNodeList_Multi(node, result);
    }
    graph = graph.setNodes(result);
  }

  //}}}

  //{{{ public void orderNodes()

  /**
    * This function makes sure the top nodes (those nodes which are
    * not imported by any other nodes) are listed first.
    **/

  public void orderNodes()
  {
    NodeList nodes = graph.getNodes();
    NodeList topNodes = factory.makeNodeList_Empty();

    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      if (!isTopNode(node)) {
	topNodes = factory.makeNodeList_Multi(node, topNodes);
      }

      nodes = nodes.getTail();
    }

    nodes = graph.getNodes();
    while (!topNodes.isEmpty()) {
      Node node = topNodes.getHead();
      nodes = deleteNodeFromNodes(node.getId().getId(), nodes);
      nodes = factory.makeNodeList_Multi(node, nodes);
      topNodes = topNodes.getTail();
    }

    graph = graph.setNodes(nodes);
  }

  //}}}

  //{{{ private boolean isTopNode(Node node)

  private boolean isTopNode(Node node)
  {
    EdgeList edges = graph.getEdges();
    while (!edges.isEmpty()) {
      Edge edge = edges.getHead();
      if (edge.getTo().isEqual(node.getId())) {
	return false;
      }
      edges = edges.getTail();
    }

    return true;
  }

  //}}}

  //{{{ public static GraphWrapper fromImportList(MetaGraphFactory factory, ATermList nodeList, ATermList imports)

  public static GraphWrapper fromImportList(MetaGraphFactory factory, ATermList nodeList, ATermList imports)
  {
    Set nodeSet = new HashSet();
    List nodeSequence = new LinkedList();

    EdgeList edges = factory.makeEdgeList_Empty();

    while (!nodeList.isEmpty()) {
      ATerm nodeTerm = nodeList.getFirst();
      nodeList = nodeList.getNext();
      if (nodeSet.add(nodeTerm)) {
	nodeSequence.add(nodeTerm);
      }
    }

    while (!imports.isEmpty()) {
      ATermList pair = (ATermList)imports.getFirst();
      imports = imports.getNext();

      ATerm fromTerm = pair.getFirst();
      ATerm toTerm = pair.getNext().getFirst();
      NodeId from = NodeId.fromTerm(fromTerm);
      NodeId to = NodeId.fromTerm(toTerm);

      if (nodeSet.add(fromTerm)) {
	nodeSequence.add(fromTerm);
      }
      if (nodeSet.add(toTerm)) {
	nodeSequence.add(toTerm);
      }

      AttributeList attrs = factory.makeAttributeList_Empty();
      Edge edge = factory.makeEdge_Default(from, to, attrs);
      edges = factory.makeEdgeList_Multi(edge, edges);
    }

    NodeList nodes = factory.makeNodeList_Empty();

    Iterator iter = nodeSequence.iterator();
    while (iter.hasNext()) {
      ATerm name = (ATerm)iter.next();
      NodeId id = NodeId.fromTerm(name);
      Shape shape = factory.makeShape_Box();
      Attribute attr = factory.makeAttribute_Shape(shape);
      AttributeList attrs = factory.makeAttributeList_Empty();
      attrs = factory.makeAttributeList_Multi(attr, attrs);
      Node node = factory.makeNode_Default(id, attrs);
      nodes = factory.makeNodeList_Multi(node, nodes);
    }

    return new GraphWrapper(factory.makeGraph_Default(nodes, edges));
  }

  //}}}
  //{{{ public static GraphWrapper fromTerm(ATerm term)

  public static GraphWrapper fromTerm(ATerm term)
  {
    Graph graph = Graph.fromTerm(term);
    return new GraphWrapper(graph);
  }

  //}}}
  //{{{ public static GraphWrapper emptyGraph(MetaGraphFactory factory)

  public static GraphWrapper emptyGraph(MetaGraphFactory factory)
  {
    NodeList nodes = factory.makeNodeList_Empty();
    EdgeList edges = factory.makeEdgeList_Empty();
    return new GraphWrapper(factory.makeGraph_Default(nodes, edges));
  }

  //}}}

  //{{{ public ATerm toTerm()

  public ATerm toTerm()
  {
    return graph.toTerm();
  }

  //}}}

  //{{{ public NodeList getNodes()

  public NodeList getNodes()
  {
    return graph.getNodes();
  }

  //}}}
  //{{{ public EdgeList getEdges()

  public EdgeList getEdges()
  {
    return graph.getEdges();
  }

  //}}}

  //{{{ public void reset()

  public void reset()
  {
    NodeList nodes = factory.makeNodeList_Empty();
    EdgeList edges = factory.makeEdgeList_Empty();
    graph = factory.makeGraph_Default(nodes, edges);
  }

  //}}}
}
