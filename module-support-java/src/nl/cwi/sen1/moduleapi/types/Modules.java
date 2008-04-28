package nl.cwi.sen1.moduleapi.types;

abstract public class Modules extends nl.cwi.sen1.moduleapi.AbstractType {
  public Modules(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Modules peer) {
    return super.isEqual(peer);
  }

  public boolean isSortModules()  {
    return true;
  }

  public boolean isDefault() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleList getList() {
     throw new UnsupportedOperationException("This Modules has no List");
  }

  public Modules setList(nl.cwi.sen1.moduleapi.types.ModuleList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

