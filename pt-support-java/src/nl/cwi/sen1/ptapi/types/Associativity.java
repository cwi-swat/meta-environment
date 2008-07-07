package nl.cwi.sen1.ptapi.types;

abstract public class Associativity extends nl.cwi.sen1.ptapi.AbstractType {
  public Associativity(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Associativity peer) {
    return super.isEqual(peer);
  }

  public boolean isSortAssociativity()  {
    return true;
  }

  public boolean isLeft() {
    return false;
  }

  public boolean isRight() {
    return false;
  }

  public boolean isAssoc() {
    return false;
  }

  public boolean isNonAssoc() {
    return false;
  }

}

