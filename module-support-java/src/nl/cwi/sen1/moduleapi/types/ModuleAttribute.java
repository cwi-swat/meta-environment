package nl.cwi.sen1.moduleapi.types;

abstract public class ModuleAttribute extends nl.cwi.sen1.moduleapi.AbstractType {
  public ModuleAttribute(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(ModuleAttribute peer) {
    return super.isEqual(peer);
  }

  public boolean isSortModuleAttribute()  {
    return true;
  }

  public boolean isModuleAttribute() {
    return false;
  }

  public boolean hasId() {
    return false;
  }

  public boolean hasAttribute() {
    return false;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getId() {
     throw new UnsupportedOperationException("This ModuleAttribute has no Id");
  }

  public ModuleAttribute setId(nl.cwi.sen1.moduleapi.types.ModuleId _id) {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

  public aterm.ATerm getAttribute() {
     throw new UnsupportedOperationException("This ModuleAttribute has no Attribute");
  }

  public ModuleAttribute setAttribute(aterm.ATerm _attribute) {
     throw new IllegalArgumentException("Illegal argument: " + _attribute);
  }

}

