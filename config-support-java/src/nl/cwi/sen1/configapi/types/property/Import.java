package nl.cwi.sen1.configapi.types.property;

public class Import extends nl.cwi.sen1.configapi.types.Property {
  public Import(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_path = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Import) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeProperty_Import(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isImport()
  {
    return true;
  }

  public boolean hasPath() {
    return true;
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
          throw new RuntimeException("Argument 0 of a Import should have type str");
        }
        break;
      default: throw new RuntimeException("Import does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
