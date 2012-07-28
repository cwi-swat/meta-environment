package nl.cwi.sen1.configapi;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private nl.cwi.sen1.configapi.Factory abstractTypeFactory;

  public AbstractList(nl.cwi.sen1.configapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  public nl.cwi.sen1.configapi.Factory getConfigapiFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortVirtualButton() {
    return false;
  }

  public boolean isSortKeyModifier() {
    return false;
  }

  public boolean isSortVirtualKey() {
    return false;
  }

  public boolean isSortColor() {
    return false;
  }

  public boolean isSortConfiguration() {
    return false;
  }

  public boolean isSortProperty() {
    return false;
  }

  public boolean isSortActionDescription() {
    return false;
  }

  public boolean isSortEvent() {
    return false;
  }

  public boolean isSortItem() {
    return false;
  }

  public boolean isSortTextCategoryName() {
    return false;
  }

  public boolean isSortTextAttribute() {
    return false;
  }

  public boolean isSortShortCut() {
    return false;
  }

  public boolean isSortTextStyle() {
    return false;
  }

  public boolean isSortPropertyList() {
    return false;
  }

  public boolean isSortActionDescriptionList() {
    return false;
  }

  public boolean isSortTextAttributeMap() {
    return false;
  }

  public boolean isSortKeyModifierList() {
    return false;
  }

  public boolean isSortItemLabels() {
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
