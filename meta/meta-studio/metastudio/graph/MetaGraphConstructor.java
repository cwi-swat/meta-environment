package metastudio.graph;

abstract public class MetaGraphConstructor
extends aterm.pure.ATermApplImpl
implements aterm.ATerm
{
  protected aterm.ATerm term = null;

  MetaGraphFactory factory = null;

  public MetaGraphConstructor(MetaGraphFactory factory) {
    super(factory.getPureFactory());
    this.factory = factory;
  }

  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  abstract public aterm.ATerm toTerm();
  public String toString() {
    return toTerm().toString();
  }
  protected void setTerm(aterm.ATerm term) {
   this.term = term;
  }
  public MetaGraphFactory getMetaGraphFactory() {
    return factory;
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
