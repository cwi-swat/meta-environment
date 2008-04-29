package nl.cwi.sen1.ioapi.types;

abstract public class StrChar extends nl.cwi.sen1.ioapi.AbstractType {
  public StrChar(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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

