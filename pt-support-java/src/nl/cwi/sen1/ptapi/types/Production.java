package nl.cwi.sen1.ptapi.types;

abstract public class Production extends nl.cwi.sen1.ptapi.AbstractType {
  public Production(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Production peer) {
    return super.isEqual(peer);
  }

  public boolean isSortProduction()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean isList() {
    return false;
  }

  public boolean hasLhs() {
    return false;
  }

  public boolean hasRhs() {
    return false;
  }

  public boolean hasAttributes() {
    return false;
  }

  public nl.cwi.sen1.ptapi.types.Symbols getLhs() {
     throw new UnsupportedOperationException("This Production has no Lhs");
  }

  public Production setLhs(nl.cwi.sen1.ptapi.types.Symbols _lhs) {
     throw new IllegalArgumentException("Illegal argument: " + _lhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getRhs() {
     throw new UnsupportedOperationException("This Production has no Rhs");
  }

  public Production setRhs(nl.cwi.sen1.ptapi.types.Symbol _rhs) {
     throw new IllegalArgumentException("Illegal argument: " + _rhs);
  }

  public nl.cwi.sen1.ptapi.types.Attributes getAttributes() {
     throw new UnsupportedOperationException("This Production has no Attributes");
  }

  public Production setAttributes(nl.cwi.sen1.ptapi.types.Attributes _attributes) {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

}

