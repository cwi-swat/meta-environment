package locationapi;

abstract public class AbstractType extends aterm.pure.ATermApplImpl {
  protected aterm.ATerm term;

  private locationapi.Factory abstractTypeFactory;

  public AbstractType(locationapi.Factory abstractTypeFactory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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

  public locationapi.Factory getLocationapiFactory() {
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

}
