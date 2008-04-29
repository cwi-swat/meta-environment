package nl.cwi.sen1.graph.types;

abstract public class NodeId extends nl.cwi.sen1.graph.AbstractType {
  public NodeId(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(NodeId peer) {
    return super.isEqual(peer);
  }

  public boolean isSortNodeId()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean hasId() {
    return false;
  }

  public aterm.ATerm getId() {
     throw new UnsupportedOperationException("This NodeId has no Id");
  }

  public NodeId setId(aterm.ATerm _id) {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

}

