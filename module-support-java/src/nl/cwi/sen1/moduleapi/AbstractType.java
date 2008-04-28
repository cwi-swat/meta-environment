package nl.cwi.sen1.moduleapi;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private nl.cwi.sen1.moduleapi.Factory abstractTypeFactory;

  public AbstractType(nl.cwi.sen1.moduleapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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

  abstract public AbstractType accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure;

}
