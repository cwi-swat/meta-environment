package nl.cwi.sen1.graph.types;

abstract public class Node extends nl.cwi.sen1.graph.AbstractType {
  public Node(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Node peer) {
    return super.isEqual(peer);
  }

  public boolean isSortNode()  {
    return true;
  }

  public boolean isNode() {
    return false;
  }

  public boolean isSubgraph() {
    return false;
  }

  public boolean hasId() {
    return false;
  }

  public boolean hasAttributes() {
    return false;
  }

  public boolean hasNodes() {
    return false;
  }

  public boolean hasEdges() {
    return false;
  }

  public nl.cwi.sen1.graph.types.NodeId getId() {
     throw new UnsupportedOperationException("This Node has no Id");
  }

  public Node setId(nl.cwi.sen1.graph.types.NodeId _id) {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

  public nl.cwi.sen1.graph.types.AttributeList getAttributes() {
     throw new UnsupportedOperationException("This Node has no Attributes");
  }

  public Node setAttributes(nl.cwi.sen1.graph.types.AttributeList _attributes) {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

  public nl.cwi.sen1.graph.types.NodeList getNodes() {
     throw new UnsupportedOperationException("This Node has no Nodes");
  }

  public Node setNodes(nl.cwi.sen1.graph.types.NodeList _nodes) {
     throw new IllegalArgumentException("Illegal argument: " + _nodes);
  }

  public nl.cwi.sen1.graph.types.EdgeList getEdges() {
     throw new UnsupportedOperationException("This Node has no Edges");
  }

  public Node setEdges(nl.cwi.sen1.graph.types.EdgeList _edges) {
     throw new IllegalArgumentException("Illegal argument: " + _edges);
  }

}

