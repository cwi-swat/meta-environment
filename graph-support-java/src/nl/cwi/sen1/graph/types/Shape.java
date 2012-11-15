package nl.cwi.sen1.graph.types;

abstract public class Shape extends nl.cwi.sen1.graph.AbstractType {
  public Shape(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Shape peer) {
    return super.isEqual(peer);
  }

  public boolean isSortShape()  {
    return true;
  }

  public boolean isBox() {
    return false;
  }

  public boolean isCircle() {
    return false;
  }

  public boolean isDiamond() {
    return false;
  }

  public boolean isEgg() {
    return false;
  }

  public boolean isEllipse() {
    return false;
  }

  public boolean isHexagon() {
    return false;
  }

  public boolean isHouse() {
    return false;
  }

  public boolean isOctagon() {
    return false;
  }

  public boolean isParallelogram() {
    return false;
  }

  public boolean isPlaintext() {
    return false;
  }

  public boolean isTrapezium() {
    return false;
  }

  public boolean isTriangle() {
    return false;
  }

}

