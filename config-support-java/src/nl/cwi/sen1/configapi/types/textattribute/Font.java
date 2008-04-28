package nl.cwi.sen1.configapi.types.textattribute;

public class Font extends nl.cwi.sen1.configapi.types.TextAttribute {
  public Font(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_name = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Font) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeTextAttribute_Font(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isFont()
  {
    return true;
  }

  public boolean hasName() {
    return true;
  }

  public String getName() {
   return ((aterm.ATermAppl) getArgument(index_name)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.TextAttribute setName(String _name) {
    return (nl.cwi.sen1.configapi.types.TextAttribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_name, 0, true)), index_name);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Font should have type str");
        }
        break;
      default: throw new RuntimeException("Font does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
