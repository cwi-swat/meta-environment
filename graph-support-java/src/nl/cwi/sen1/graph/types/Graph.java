package nl.cwi.sen1.graph.types;

abstract public class Graph extends nl.cwi.sen1.graph.AbstractType {
  public Graph(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Graph peer) {
    return super.isEqual(peer);
  }

  public boolean isSortGraph()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean hasNodes() {
    return false;
  }

  public boolean hasEdges() {
    return false;
  }

  public boolean hasAttributes() {
    return false;
  }

  public nl.cwi.sen1.graph.types.NodeList getNodes() {
     throw new UnsupportedOperationException("This Graph has no Nodes");
  }

  public Graph setNodes(nl.cwi.sen1.graph.types.NodeList _nodes) {
     throw new IllegalArgumentException("Illegal argument: " + _nodes);
  }

  public nl.cwi.sen1.graph.types.EdgeList getEdges() {
     throw new UnsupportedOperationException("This Graph has no Edges");
  }

  public Graph setEdges(nl.cwi.sen1.graph.types.EdgeList _edges) {
     throw new IllegalArgumentException("Illegal argument: " + _edges);
  }

  public nl.cwi.sen1.graph.types.AttributeList getAttributes() {
     throw new UnsupportedOperationException("This Graph has no Attributes");
  }

  public Graph setAttributes(nl.cwi.sen1.graph.types.AttributeList _attributes) {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

}

