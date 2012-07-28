package nl.cwi.sen1.ptapi.types.symbol;

public class Lit extends nl.cwi.sen1.ptapi.types.Symbol {
  public Lit(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_string = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Lit) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeSymbol_Lit(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLit()
  {
    return true;
  }

  public boolean hasString() {
    return true;
  }

  public String getString() {
   return ((aterm.ATermAppl) getArgument(index_string)).getAFun().getName();
  }

  public nl.cwi.sen1.ptapi.types.Symbol setString(String _string) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_string, 0, true)), index_string);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Lit should have type str");
        }
        break;
      default: throw new RuntimeException("Lit does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
