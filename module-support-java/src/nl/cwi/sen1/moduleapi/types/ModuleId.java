package nl.cwi.sen1.moduleapi.types;

abstract public class ModuleId extends nl.cwi.sen1.moduleapi.AbstractType {
  public ModuleId(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(ModuleId peer) {
    return super.isEqual(peer);
  }

  public boolean isSortModuleId()  {
    return true;
  }

  public boolean isModuleId() {
    return false;
  }

  public boolean hasId() {
    return false;
  }

  public int getId() {
     throw new UnsupportedOperationException("This ModuleId has no Id");
  }

  public ModuleId setId(int _id) {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

}

