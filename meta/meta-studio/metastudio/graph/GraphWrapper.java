package metastudio.graph;

import java.util.*;
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

  //{{{ public Node getNode(String id)

  public Node getNode(String id)
  {
    NodeList nodes = graph.getNodes();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      if (node.getId().getId().equals(id)) {
	return node;
      }
    }

    return null;
  }

  //}}}
  //{{{ public void deleteNode(String id)

  public void deleteNode(String id)
  {
    NodeList nodes = getNodes();
    NodeList newNodes = factory.makeNodeList_Empty();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      if (!node.getId().getId().equals(id)) {
	newNodes = factory.makeNodeList_Multi(node, newNodes);
      }

      nodes = nodes.getTail();
    }
    graph = graph.setNodes(newNodes);

    EdgeList edges = getEdges();
    EdgeList newEdges = factory.makeEdgeList_Empty();
    while (!edges.isEmpty()) {
      Edge edge = edges.getHead();
      if (!edge.getFrom().getId().equals(id) && !edge.getTo().getId().equals(id)) {
	newEdges = factory.makeEdgeList_Multi(edge, newEdges);
      }

      edges = edges.getTail();
    }
    graph = graph.setEdges(newEdges);
  }

  //}}}
  //{{{ public void sizeNodes(NodeSizer nodeSizer)

  public void sizeNodes(NodeSizer nodeSizer)
  {
    NodeList nodes = graph.getNodes();
    NodeList result = factory.makeNodeList_Empty();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();

      node = nodeSizer.sizeNode(node);
      result = factory.makeNodeList_Multi(node, result);

      nodes = nodes.getTail();
    }

    graph = graph.setNodes(result);
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
