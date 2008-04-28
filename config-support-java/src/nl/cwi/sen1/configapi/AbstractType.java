package nl.cwi.sen1.configapi;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private nl.cwi.sen1.configapi.Factory abstractTypeFactory;

  public AbstractType(nl.cwi.sen1.configapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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

}
