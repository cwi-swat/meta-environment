package nl.cwi.sen1.moduleapi.types;

abstract public class Module extends nl.cwi.sen1.moduleapi.AbstractType {
  public Module(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Module peer) {
    return super.isEqual(peer);
  }

  public boolean isSortModule()  {
    return true;
  }

  public boolean isModule() {
    return false;
  }

  public boolean hasId() {
    return false;
  }

  public boolean hasStore() {
    return false;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getId() {
     throw new UnsupportedOperationException("This Module has no Id");
  }

  public Module setId(nl.cwi.sen1.moduleapi.types.ModuleId _id) {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore getStore() {
     throw new UnsupportedOperationException("This Module has no Store");
  }

  public Module setStore(nl.cwi.sen1.moduleapi.types.AttributeStore _store) {
     throw new IllegalArgumentException("Illegal argument: " + _store);
  }

}

