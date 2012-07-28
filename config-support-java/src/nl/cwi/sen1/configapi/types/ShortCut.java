package nl.cwi.sen1.configapi.types;

abstract public class ShortCut extends nl.cwi.sen1.configapi.AbstractType {
  public ShortCut(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(ShortCut peer) {
    return super.isEqual(peer);
  }

  public boolean isSortShortCut()  {
    return true;
  }

  public boolean isShortcut() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public boolean hasKey() {
    return false;
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList getList() {
     throw new UnsupportedOperationException("This ShortCut has no List");
  }

  public ShortCut setList(nl.cwi.sen1.configapi.types.KeyModifierList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

  public nl.cwi.sen1.configapi.types.VirtualKey getKey() {
     throw new UnsupportedOperationException("This ShortCut has no Key");
  }

  public ShortCut setKey(nl.cwi.sen1.configapi.types.VirtualKey _key) {
     throw new IllegalArgumentException("Illegal argument: " + _key);
  }

}

