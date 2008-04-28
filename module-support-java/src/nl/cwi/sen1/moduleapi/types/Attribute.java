package nl.cwi.sen1.moduleapi.types;

abstract public class Attribute extends nl.cwi.sen1.moduleapi.AbstractType {
  public Attribute(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Attribute peer) {
    return super.isEqual(peer);
  }

  public boolean isSortAttribute()  {
    return true;
  }

  public boolean isAttribute() {
    return false;
  }

  public boolean hasNamespace() {
    return false;
  }

  public boolean hasTable() {
    return false;
  }

  public aterm.ATerm getNamespace() {
     throw new UnsupportedOperationException("This Attribute has no Namespace");
  }

  public Attribute setNamespace(aterm.ATerm _namespace) {
     throw new IllegalArgumentException("Illegal argument: " + _namespace);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable getTable() {
     throw new UnsupportedOperationException("This Attribute has no Table");
  }

  public Attribute setTable(nl.cwi.sen1.moduleapi.types.TableEntryTable _table) {
     throw new IllegalArgumentException("Illegal argument: " + _table);
  }

}

