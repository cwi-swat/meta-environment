package nl.cwi.sen1.moduleapi;

abstract public class AbstractList extends aterm.pure.ATermListImpl {
  private nl.cwi.sen1.moduleapi.Factory abstractTypeFactory;

  public AbstractList(nl.cwi.sen1.moduleapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
    super(abstractTypeFactory.getPureFactory(), annos, first, next);
    this.abstractTypeFactory = abstractTypeFactory;
  }

  abstract public aterm.ATerm toTerm();

  public String toString() {
    return toTerm().toString();
  }

  public nl.cwi.sen1.moduleapi.Factory getModuleapiFactory() {
    return abstractTypeFactory;
  }

  public boolean isSortModules() {
    return false;
  }

  public boolean isSortModule() {
    return false;
  }

  public boolean isSortModuleId() {
    return false;
  }

  public boolean isSortAttribute() {
    return false;
  }

  public boolean isSortTableEntry() {
    return false;
  }

  public boolean isSortDependencies() {
    return false;
  }

  public boolean isSortDependency() {
    return false;
  }

  public boolean isSortAttributeMap() {
    return false;
  }

  public boolean isSortModuleAttribute() {
    return false;
  }

  public boolean isSortModuleList() {
    return false;
  }

  public boolean isSortAttributeStore() {
    return false;
  }

  public boolean isSortTableEntryTable() {
    return false;
  }

  public boolean isSortDependencyList() {
    return false;
  }

  public boolean isSortModuleIdList() {
    return false;
  }

  public boolean isSortModuleAttributeList() {
    return false;
  }

  public boolean isSortNatCon() {
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

  abstract public AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure;

}
