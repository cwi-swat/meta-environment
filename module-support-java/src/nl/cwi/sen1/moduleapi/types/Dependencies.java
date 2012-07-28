package nl.cwi.sen1.moduleapi.types;

abstract public class Dependencies extends nl.cwi.sen1.moduleapi.AbstractType {
  public Dependencies(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Dependencies peer) {
    return super.isEqual(peer);
  }

  public boolean isSortDependencies()  {
    return true;
  }

  public boolean isDependencies() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public nl.cwi.sen1.moduleapi.types.DependencyList getList() {
     throw new UnsupportedOperationException("This Dependencies has no List");
  }

  public Dependencies setList(nl.cwi.sen1.moduleapi.types.DependencyList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

