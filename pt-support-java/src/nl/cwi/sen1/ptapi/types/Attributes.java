package nl.cwi.sen1.ptapi.types;

abstract public class Attributes extends nl.cwi.sen1.ptapi.AbstractType {
  public Attributes(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Attributes peer) {
    return super.isEqual(peer);
  }

  public boolean isSortAttributes()  {
    return true;
  }

  public boolean isNoAttrs() {
    return false;
  }

  public boolean isAttrs() {
    return false;
  }

  public boolean hasAttrs() {
    return false;
  }

  public nl.cwi.sen1.ptapi.types.Attrs getAttrs() {
     throw new UnsupportedOperationException("This Attributes has no Attrs");
  }

  public Attributes setAttrs(nl.cwi.sen1.ptapi.types.Attrs _attrs) {
     throw new IllegalArgumentException("Illegal argument: " + _attrs);
  }

}

