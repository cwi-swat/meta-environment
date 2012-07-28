package locationapi.types.natcon;

public class NatCon extends locationapi.types.NatCon {
  public NatCon(locationapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_string = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof NatCon) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getLocationapiFactory().makeNatCon_NatCon(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getLocationapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isNatCon()
  {
    return true;
  }

  public boolean hasString() {
    return true;
  }

  public String getString() {
   return ((aterm.ATermAppl) getArgument(index_string)).getAFun().getName();
  }

  public locationapi.types.NatCon setString(String _string) {
    return (locationapi.types.NatCon) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_string, 0, true)), index_string);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a NatCon should have type str");
        }
        break;
      default: throw new RuntimeException("NatCon does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
