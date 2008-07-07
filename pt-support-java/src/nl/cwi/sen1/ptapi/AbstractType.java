package nl.cwi.sen1.ptapi;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private nl.cwi.sen1.ptapi.Factory abstractTypeFactory;

  public AbstractType(nl.cwi.sen1.ptapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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

}
