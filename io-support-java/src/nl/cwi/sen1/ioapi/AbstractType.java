package nl.cwi.sen1.ioapi;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private nl.cwi.sen1.ioapi.Factory abstractTypeFactory;

  public AbstractType(nl.cwi.sen1.ioapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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

  public nl.cwi.sen1.ioapi.Factory getIoapiFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortFile() {
    return false;
  }

  public boolean isSortPath() {
    return false;
  }

  public boolean isSortSegment() {
    return false;
  }

  public boolean isSortSegmentList() {
    return false;
  }

  public boolean isSortStrChar() {
    return false;
  }

  public boolean isSortStrCon() {
    return false;
  }

  abstract public AbstractType accept(nl.cwi.sen1.ioapi.Visitor v) throws jjtraveler.VisitFailure;

}
