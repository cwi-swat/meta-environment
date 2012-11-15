package nl.cwi.sen1.graph.types;

abstract public class Point extends nl.cwi.sen1.graph.AbstractType {
  public Point(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Point peer) {
    return super.isEqual(peer);
  }

  public boolean isSortPoint()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean hasX() {
    return false;
  }

  public boolean hasY() {
    return false;
  }

  public int getX() {
     throw new UnsupportedOperationException("This Point has no X");
  }

  public Point setX(int _x) {
     throw new IllegalArgumentException("Illegal argument: " + _x);
  }

  public int getY() {
     throw new UnsupportedOperationException("This Point has no Y");
  }

  public Point setY(int _y) {
     throw new IllegalArgumentException("Illegal argument: " + _y);
  }

}

