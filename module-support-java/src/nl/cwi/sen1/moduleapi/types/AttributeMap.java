package nl.cwi.sen1.moduleapi.types;

abstract public class AttributeMap extends nl.cwi.sen1.moduleapi.AbstractType {
  public AttributeMap(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(AttributeMap peer) {
    return super.isEqual(peer);
  }

  public boolean isSortAttributeMap()  {
    return true;
  }

  public boolean isAttributeMap() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttributeList getList() {
     throw new UnsupportedOperationException("This AttributeMap has no List");
  }

  public AttributeMap setList(nl.cwi.sen1.moduleapi.types.ModuleAttributeList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

