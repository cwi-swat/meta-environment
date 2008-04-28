package nl.cwi.sen1.configapi.types.event;

public class MenuShortcut extends nl.cwi.sen1.configapi.types.Event {
  public MenuShortcut(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_labels = 0;
  private static int index_shortcut = 1;
  private static int index_info = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof MenuShortcut) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeEvent_MenuShortcut(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isMenuShortcut()
  {
    return true;
  }

  public boolean hasLabels() {
    return true;
  }

  public boolean hasShortcut() {
    return true;
  }

  public boolean hasInfo() {
    return true;
  }

  public nl.cwi.sen1.configapi.types.ItemLabels getLabels() {
    return (nl.cwi.sen1.configapi.types.ItemLabels) getArgument(index_labels);
  }

  public nl.cwi.sen1.configapi.types.Event setLabels(nl.cwi.sen1.configapi.types.ItemLabels _labels) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(_labels, index_labels);
  }

  public nl.cwi.sen1.configapi.types.ShortCut getShortcut() {
    return (nl.cwi.sen1.configapi.types.ShortCut) getArgument(index_shortcut);
  }

  public nl.cwi.sen1.configapi.types.Event setShortcut(nl.cwi.sen1.configapi.types.ShortCut _shortcut) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(_shortcut, index_shortcut);
  }

  public String getInfo() {
   return ((aterm.ATermAppl) getArgument(index_info)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Event setInfo(String _info) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_info, 0, true)), index_info);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.ItemLabels)) { 
          throw new RuntimeException("Argument 0 of a MenuShortcut should have type Item-labels");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.ShortCut)) { 
          throw new RuntimeException("Argument 1 of a MenuShortcut should have type ShortCut");
        }
        break;
      case 2:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 2 of a MenuShortcut should have type str");
        }
        break;
      default: throw new RuntimeException("MenuShortcut does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
