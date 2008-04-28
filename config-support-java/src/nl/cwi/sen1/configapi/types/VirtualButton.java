package nl.cwi.sen1.configapi.types;

abstract public class VirtualButton extends nl.cwi.sen1.configapi.AbstractType {
  public VirtualButton(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(VirtualButton peer) {
    return super.isEqual(peer);
  }

  public boolean isSortVirtualButton()  {
    return true;
  }

  public boolean isNOBUTTON() {
    return false;
  }

  public boolean isBUTTON1() {
    return false;
  }

  public boolean isBUTTON2() {
    return false;
  }

  public boolean isBUTTON3() {
    return false;
  }

}

