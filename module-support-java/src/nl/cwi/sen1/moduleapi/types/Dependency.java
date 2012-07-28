package nl.cwi.sen1.moduleapi.types;

abstract public class Dependency extends nl.cwi.sen1.moduleapi.AbstractType {
  public Dependency(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Dependency peer) {
    return super.isEqual(peer);
  }

  public boolean isSortDependency()  {
    return true;
  }

  public boolean isDependency() {
    return false;
  }

  public boolean hasFrom() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getFrom() {
     throw new UnsupportedOperationException("This Dependency has no From");
  }

  public Dependency setFrom(nl.cwi.sen1.moduleapi.types.ModuleId _from) {
     throw new IllegalArgumentException("Illegal argument: " + _from);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList getList() {
     throw new UnsupportedOperationException("This Dependency has no List");
  }

  public Dependency setList(nl.cwi.sen1.moduleapi.types.ModuleIdList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

