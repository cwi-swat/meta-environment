package nl.cwi.sen1.configapi.types;

abstract public class Configuration extends nl.cwi.sen1.configapi.AbstractType {
  public Configuration(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Configuration peer) {
    return super.isEqual(peer);
  }

  public boolean isSortConfiguration()  {
    return true;
  }

  public boolean isConfiguration() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public nl.cwi.sen1.configapi.types.PropertyList getList() {
     throw new UnsupportedOperationException("This Configuration has no List");
  }

  public Configuration setList(nl.cwi.sen1.configapi.types.PropertyList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

