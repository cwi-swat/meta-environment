package nl.cwi.sen1.configapi.types.property;

public class ModulePath extends nl.cwi.sen1.configapi.types.Property {
  public ModulePath(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_label = 0;
  private static int index_path = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ModulePath) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeProperty_ModulePath(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isModulePath()
  {
    return true;
  }

  public boolean hasLabel() {
    return true;
  }

  public boolean hasPath() {
    return true;
  }

  public String getLabel() {
   return ((aterm.ATermAppl) getArgument(index_label)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Property setLabel(String _label) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_label, 0, true)), index_label);
  }

  public String getPath() {
   return ((aterm.ATermAppl) getArgument(index_path)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Property setPath(String _path) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_path, 0, true)), index_path);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a ModulePath should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 1 of a ModulePath should have type str");
        }
        break;
      default: throw new RuntimeException("ModulePath does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
