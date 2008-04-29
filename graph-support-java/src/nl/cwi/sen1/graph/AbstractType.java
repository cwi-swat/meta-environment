package nl.cwi.sen1.graph;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private nl.cwi.sen1.graph.Factory abstractTypeFactory;

  public AbstractType(nl.cwi.sen1.graph.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(abstractTypeFactory.getPureFactory(), annos, fun, args);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  protected void setTerm(aterm.ATerm term) {
    this.term = term;
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

}
