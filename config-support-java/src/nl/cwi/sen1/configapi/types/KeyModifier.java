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

  public boolean isMUnderscoreALT() {
    return false;
  }

  public boolean isMUnderscoreCTRL() {
    return false;
  }

  public boolean isMUnderscoreSHIFT() {
    return false;
  }

}

