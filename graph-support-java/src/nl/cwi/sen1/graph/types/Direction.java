package nl.cwi.sen1.graph.types;

abstract public class Direction extends nl.cwi.sen1.graph.AbstractType {
  public Direction(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Direction peer) {
    return super.isEqual(peer);
  }

  public boolean isSortDirection()  {
    return true;
  }

  public boolean isForward() {
    return false;
  }

  public boolean isBack() {
    return false;
  }

  public boolean isBoth() {
    return false;
  }

  public boolean isNone() {
    return false;
  }

}

