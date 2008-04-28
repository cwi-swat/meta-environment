package nl.cwi.sen1.configapi.types.event;

public class Icon extends nl.cwi.sen1.configapi.types.Event {
  public Icon(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_title = 0;
  private static int index_path = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Icon) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeEvent_Icon(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isIcon()
  {
    return true;
  }

  public boolean hasTitle() {
    return true;
  }

  public boolean hasPath() {
    return true;
  }

  public String getTitle() {
   return ((aterm.ATermAppl) getArgument(index_title)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Event setTitle(String _title) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_title, 0, true)), index_title);
  }

  public String getPath() {
   return ((aterm.ATermAppl) getArgument(index_path)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Event setPath(String _path) {
    return (nl.cwi.sen1.configapi.types.Event) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_path, 0, true)), index_path);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Icon should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 1 of a Icon should have type str");
        }
        break;
      default: throw new RuntimeException("Icon does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
