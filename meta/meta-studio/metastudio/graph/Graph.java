package metastudio.graph;

import aterm.*;

import java.util.*;

public class Graph
{
  private ATerm term;

  //{{{ public Graph(ATerm graph)

  public Graph(ATerm graph)
  {
    term = graph;
  }

  //}}}

  //{{{ public static Graph createGraph(ATermList nodes, ATermList edges)

  public static Graph createGraph(ATermList nodes, ATermList edges)
  {
    ATermFactory factory = nodes.getFactory();

    AFun fun = factory.makeAFun("graph", 2, false);
    return new Graph(factory.makeAppl(fun, nodes, edges));
  }

  //}}}

  //{{{ public static Graph fromImportList(ATermList modules, ATermList imports)

  public static Graph fromImportList(ATermList nodeList, ATermList imports)
  {
    Set nodeSet = new HashSet();
    List nodeSequence = new LinkedList();

    ATermList edges = imports.getFactory().makeList();

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

      if (nodeSet.add(fromTerm)) {
	nodeSequence.add(fromTerm);
      }
      if (nodeSet.add(toTerm)) {
	nodeSequence.add(toTerm);
      }

      Edge edge = Edge.createUnpositionedEdge(fromTerm, toTerm);
      edges = edges.insert(edge.toTerm());
    }

    ATermList nodes = imports.getFactory().makeList();

    Iterator iter = nodeSequence.iterator();
    while (iter.hasNext()) {
      ATerm name = (ATerm)iter.next();
      Node node = Node.createUnsized(name);
      nodes = nodes.insert(node.toTerm());
    }

    return createGraph(nodes, edges);
  }

  //}}}
  //{{{ public void sizeNodes(NodeSizer nodeSizer)

  public void sizeNodes(NodeSizer nodeSizer)
  {
    ATermAppl appl = (ATermAppl)term;
    ATermList nodes = (ATermList)appl.getArgument(0);

    ATermList result = term.getFactory().makeList();

    while (!nodes.isEmpty()) {
      Node node = new Node(nodes.getFirst());
      nodes = nodes.getNext();
      node = nodeSizer.sizeNode(node);
      result = result.insert(node.toTerm());
    }

    result.reverse();

    term = appl.setArgument(result, 0);
  }

  //}}}
  //{{{ public void deleteNode(String name)

  public void deleteNode(String name)
  {
    ATermFactory factory = term.getFactory();

    NodeList nodes = getNodes();
    ATermList resultNodes = factory.makeList();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      nodes = nodes.getTail();

      if (!node.getName().equals(name)) {
	resultNodes = resultNodes.insert(node.toTerm());
      }
    }
    resultNodes = resultNodes.reverse();

    EdgeList edges = getEdges();
    ATermList resultEdges = factory.makeList();
    while (!edges.isEmpty()) {
      Edge edge = edges.getHead();
      edges = edges.getTail();

      if (!edge.getFrom().equals(name) && !edge.getTo().equals(name)) {
	resultEdges = resultEdges.insert(edge.toTerm());
      }
    }
    resultEdges = resultEdges.reverse();

    AFun fun = factory.makeAFun("graph", 2, false);
    term = factory.makeAppl(fun, resultNodes, resultEdges);
  }

  //}}}
  
  //{{{ public NodeList getNodes()

  public NodeList getNodes()
  {
    List result;

    result = term.match("graph(<term>,<term>)");
    if (result != null) {
      return new NodeList((ATerm)result.get(0));
    }

    throw new RuntimeException("not a graph: " + term);
  }

  //}}}
  //{{{ public EdgeList getEdges()

  public EdgeList getEdges()
  {
    List result;

    result = term.match("graph(<term>,<term>)");
    if (result != null) {
      return new EdgeList((ATerm)result.get(1));
    }

    throw new RuntimeException("not a graph: " + term);
  }

  //}}}

  //{{{ public Node getNode(String name)

  public Node getNode(String name)
  {
    NodeList nodes = getNodes();
    while (!nodes.isEmpty()) {
      Node node = nodes.getHead();
      nodes = nodes.getTail();

      if (node.getName().equals(name)) {
	return node;
      }
    }

    return null;
  }

  //}}}

  //{{{ public ATerm toTerm()

  public ATerm toTerm()
  {
    return term;
  }

  //}}}
}
