package nl.cwi.sen1.ioapi;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private nl.cwi.sen1.ioapi.Factory abstractTypeFactory;

  public AbstractList(nl.cwi.sen1.ioapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
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

  abstract public AbstractList accept(nl.cwi.sen1.ioapi.Visitor v) throws jjtraveler.VisitFailure;

}
