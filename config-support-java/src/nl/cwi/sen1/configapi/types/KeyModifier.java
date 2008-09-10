package nl.cwi.sen1.configapi.types;

abstract public class KeyModifier extends nl.cwi.sen1.configapi.AbstractType {
  public KeyModifier(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(KeyModifier peer) {
    return super.isEqual(peer);
  }

  public boolean isSortKeyModifier()  {
    return true;
  }

  public boolean isM_ALT() {
    return false;
  }

  public boolean isM_CTRL() {
    return false;
  }

  public boolean isM_SHIFT() {
    return false;
  }

}

