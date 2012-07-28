package nl.cwi.sen1.ptapi.types.attr;

public class Id extends nl.cwi.sen1.ptapi.types.Attr {
  public Id(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_moduleName = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Id) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeAttr_Id(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isId()
  {
    return true;
  }

  public boolean hasModuleName() {
    return true;
  }

  public String getModuleName() {
   return ((aterm.ATermAppl) getArgument(index_moduleName)).getAFun().getName();
  }

  public nl.cwi.sen1.ptapi.types.Attr setModuleName(String _moduleName) {
    return (nl.cwi.sen1.ptapi.types.Attr) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_moduleName, 0, true)), index_moduleName);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Id should have type str");
        }
        break;
      default: throw new RuntimeException("Id does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
