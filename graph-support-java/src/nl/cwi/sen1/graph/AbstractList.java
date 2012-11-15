package nl.cwi.sen1.graph;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private nl.cwi.sen1.graph.Factory abstractTypeFactory;

  public AbstractList(nl.cwi.sen1.graph.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  public nl.cwi.sen1.graph.Factory getGraphFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortGraph() {
    return false;
  }

  public boolean isSortNodeList() {
    return false;
  }

  public boolean isSortNode() {
    return false;
  }

  public boolean isSortNodeId() {
    return false;
  }

  public boolean isSortAttributeList() {
    return false;
  }

  public boolean isSortAttribute() {
    return false;
  }

  public boolean isSortFile() {
    return false;
  }

  public boolean isSortColor() {
    return false;
  }

  public boolean isSortStyle() {
    return false;
  }

  public boolean isSortShape() {
    return false;
  }

  public boolean isSortDirection() {
    return false;
  }

  public boolean isSortEdgeList() {
    return false;
  }

  public boolean isSortEdge() {
    return false;
  }

  public boolean isSortPolygon() {
    return false;
  }

  public boolean isSortPoint() {
    return false;
  }

  public boolean isEmpty() {
    return getFirst()==getEmpty().getFirst() && getNext()==getEmpty().getNext();
  }

  public boolean isMany() {
    return !isEmpty();
  }

  public boolean isSingle() {
    return !isEmpty() && getNext().isEmpty();
  }

  public boolean hasHead() {
    return !isEmpty();
  }

  public boolean hasTail() {
    return !isEmpty();
  }

}
