package errorapi;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private errorapi.Factory abstractTypeFactory;

  public AbstractList(errorapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  public errorapi.Factory getErrorapiFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortStrChar() {
    return false;
  }

  public boolean isSortStrCon() {
    return false;
  }

  public boolean isSortNatCon() {
    return false;
  }

  public boolean isSortSubject() {
    return false;
  }

  public boolean isSortError() {
    return false;
  }

  public boolean isSortSummary() {
    return false;
  }

  public boolean isSortSubjectList() {
    return false;
  }

  public boolean isSortErrorList() {
    return false;
  }

  public boolean isSortLocation() {
    return false;
  }

  public boolean isSortArea() {
    return false;
  }

  public boolean isSortSlice() {
    return false;
  }

  public boolean isSortAreaAreas() {
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
