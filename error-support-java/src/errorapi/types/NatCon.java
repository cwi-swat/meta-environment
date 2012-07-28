package errorapi.types;

abstract public class NatCon extends errorapi.AbstractType {
  public NatCon(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(NatCon peer) {
    return super.isEqual(peer);
  }

  public boolean isSortNatCon()  {
    return true;
  }

  public boolean isNatCon() {
    return false;
  }

  public boolean hasString() {
    return false;
  }

  public String getString() {
     throw new UnsupportedOperationException("This NatCon has no String");
  }

  public NatCon setString(String _string) {
     throw new IllegalArgumentException("Illegal argument: " + _string);
  }

}

