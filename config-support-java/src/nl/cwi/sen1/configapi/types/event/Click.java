package nl.cwi.sen1.configapi.types.event;

public class Click extends nl.cwi.sen1.configapi.types.Event {
  public Click(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_list = 0;
  private static int index_button = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Click) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeEvent_Click(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isClick()
  {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public boolean hasButton() {
    return true;
  }

  public nl.cwi.sen1.configapi.types.KeyModifierList getList() {
    return (nl.cwi.sen1.configapi.types.KeyModifierList) getArgument(index_list);
  }

  public nl.cwi.sen1.configapi.types.Event setList(nl.cwi.sen1.configapi.types.KeyModifierList _list) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(_list, index_list);
  }

  public nl.cwi.sen1.configapi.types.VirtualButton getButton() {
    return (nl.cwi.sen1.configapi.types.VirtualButton) getArgument(index_button);
  }

  public nl.cwi.sen1.configapi.types.Event setButton(nl.cwi.sen1.configapi.types.VirtualButton _button) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(_button, index_button);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.KeyModifierList)) { 
          throw new RuntimeException("Argument 0 of a Click should have type KeyModifier-list");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.VirtualButton)) { 
          throw new RuntimeException("Argument 1 of a Click should have type VirtualButton");
        }
        break;
      default: throw new RuntimeException("Click does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

}
