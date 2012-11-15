package nl.cwi.sen1.graph.types;

abstract public class Style extends nl.cwi.sen1.graph.AbstractType {
  public Style(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Style peer) {
    return super.isEqual(peer);
  }

  public boolean isSortStyle()  {
    return true;
  }

  public boolean isBold() {
    return false;
  }

  public boolean isDashed() {
    return false;
  }

  public boolean isDotted() {
    return false;
  }

  public boolean isFilled() {
    return false;
  }

  public boolean isInvisible() {
    return false;
  }

  public boolean isSolid() {
    return false;
  }

}

