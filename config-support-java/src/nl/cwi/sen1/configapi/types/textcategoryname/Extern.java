package nl.cwi.sen1.configapi.types.textcategoryname;

public class Extern extends nl.cwi.sen1.configapi.types.TextCategoryName {
  public Extern(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_name = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Extern) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeTextCategoryName_Extern(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isExtern()
  {
    return true;
  }

  public boolean hasName() {
    return true;
  }

  public String getName() {
   return ((aterm.ATermAppl) getArgument(index_name)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.TextCategoryName setName(String _name) {
    return (nl.cwi.sen1.configapi.types.TextCategoryName) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_name, 0, true)), index_name);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Extern should have type str");
        }
        break;
      default: throw new RuntimeException("Extern does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
