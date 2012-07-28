package locationapi.types;

abstract public class StrChar extends locationapi.AbstractType {
  public StrChar(locationapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(StrChar peer) {
    return super.isEqual(peer);
  }

  public boolean isSortStrChar()  {
    return true;
  }

  public boolean isStrChar() {
    return false;
  }

  public boolean hasString() {
    return false;
  }

  public String getString() {
     throw new UnsupportedOperationException("This StrChar has no String");
  }

  public StrChar setString(String _string) {
     throw new IllegalArgumentException("Illegal argument: " + _string);
  }

}

