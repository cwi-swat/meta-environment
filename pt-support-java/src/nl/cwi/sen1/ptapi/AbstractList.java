package nl.cwi.sen1.ptapi;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private nl.cwi.sen1.ptapi.Factory abstractTypeFactory;

  public AbstractList(nl.cwi.sen1.ptapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  public nl.cwi.sen1.ptapi.Factory getPtapiFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortParseTree() {
    return false;
  }

  public boolean isSortTree() {
    return false;
  }

  public boolean isSortArgs() {
    return false;
  }

  public boolean isSortProduction() {
    return false;
  }

  public boolean isSortAttributes() {
    return false;
  }

  public boolean isSortAttrs() {
    return false;
  }

  public boolean isSortAttr() {
    return false;
  }

  public boolean isSortAssociativity() {
    return false;
  }

  public boolean isSortSymbol() {
    return false;
  }

  public boolean isSortSymbols() {
    return false;
  }

  public boolean isSortCharRange() {
    return false;
  }

  public boolean isSortCharRanges() {
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
