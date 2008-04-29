package nl.cwi.sen1.graph.types;

abstract public class Edge extends nl.cwi.sen1.graph.AbstractType {
  public Edge(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Edge peer) {
    return super.isEqual(peer);
  }

  public boolean isSortEdge()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean hasFrom() {
    return false;
  }

  public boolean hasTo() {
    return false;
  }

  public boolean hasAttributes() {
    return false;
  }

  public nl.cwi.sen1.graph.types.NodeId getFrom() {
     throw new UnsupportedOperationException("This Edge has no From");
  }

  public Edge setFrom(nl.cwi.sen1.graph.types.NodeId _from) {
     throw new IllegalArgumentException("Illegal argument: " + _from);
  }

  public nl.cwi.sen1.graph.types.NodeId getTo() {
     throw new UnsupportedOperationException("This Edge has no To");
  }

  public Edge setTo(nl.cwi.sen1.graph.types.NodeId _to) {
     throw new IllegalArgumentException("Illegal argument: " + _to);
  }

  public nl.cwi.sen1.graph.types.AttributeList getAttributes() {
     throw new UnsupportedOperationException("This Edge has no Attributes");
  }

  public Edge setAttributes(nl.cwi.sen1.graph.types.AttributeList _attributes) {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

}

