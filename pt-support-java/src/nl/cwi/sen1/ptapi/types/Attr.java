package nl.cwi.sen1.ptapi.types;

abstract public class Attr extends nl.cwi.sen1.ptapi.AbstractType {
  public Attr(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Attr peer) {
    return super.isEqual(peer);
  }

  public boolean isSortAttr()  {
    return true;
  }

  public boolean isAssoc() {
    return false;
  }

  public boolean isTerm() {
    return false;
  }

  public boolean isId() {
    return false;
  }

  public boolean isBracket() {
    return false;
  }

  public boolean isReject() {
    return false;
  }

  public boolean isPrefer() {
    return false;
  }

  public boolean isAvoid() {
    return false;
  }

  public boolean hasAssoc() {
    return false;
  }

  public boolean hasValue() {
    return false;
  }

  public boolean hasModuleName() {
    return false;
  }

  public nl.cwi.sen1.ptapi.types.Associativity getAssoc() {
     throw new UnsupportedOperationException("This Attr has no Assoc");
  }

  public Attr setAssoc(nl.cwi.sen1.ptapi.types.Associativity _assoc) {
     throw new IllegalArgumentException("Illegal argument: " + _assoc);
  }

  public aterm.ATerm getValue() {
     throw new UnsupportedOperationException("This Attr has no Value");
  }

  public Attr setValue(aterm.ATerm _value) {
     throw new IllegalArgumentException("Illegal argument: " + _value);
  }

  public String getModuleName() {
     throw new UnsupportedOperationException("This Attr has no ModuleName");
  }

  public Attr setModuleName(String _moduleName) {
     throw new IllegalArgumentException("Illegal argument: " + _moduleName);
  }

}

