package nl.cwi.sen1.ioapi.types;

abstract public class StrCon extends nl.cwi.sen1.ioapi.AbstractType {
  public StrCon(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(StrCon peer) {
    return super.isEqual(peer);
  }

  public boolean isSortStrCon()  {
    return true;
  }

  public boolean isStrCon() {
    return false;
  }

  public boolean hasString() {
    return false;
  }

  public String getString() {
     throw new UnsupportedOperationException("This StrCon has no String");
  }

  public StrCon setString(String _string) {
     throw new IllegalArgumentException("Illegal argument: " + _string);
  }

}

