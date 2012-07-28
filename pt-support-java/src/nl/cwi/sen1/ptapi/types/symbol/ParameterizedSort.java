package nl.cwi.sen1.ptapi.types.symbol;

public class ParameterizedSort extends nl.cwi.sen1.ptapi.types.Symbol {
  public ParameterizedSort(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_sort = 0;
  private static int index_parameters = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ParameterizedSort) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeSymbol_ParameterizedSort(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isParameterizedSort()
  {
    return true;
  }

  public boolean hasSort() {
    return true;
  }

  public boolean hasParameters() {
    return true;
  }

  public String getSort() {
   return ((aterm.ATermAppl) getArgument(index_sort)).getAFun().getName();
  }

  public nl.cwi.sen1.ptapi.types.Symbol setSort(String _sort) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_sort, 0, true)), index_sort);
  }

  public nl.cwi.sen1.ptapi.types.Symbols getParameters() {
    return (nl.cwi.sen1.ptapi.types.Symbols) getArgument(index_parameters);
  }

  public nl.cwi.sen1.ptapi.types.Symbol setParameters(nl.cwi.sen1.ptapi.types.Symbols _parameters) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(_parameters, index_parameters);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a ParameterizedSort should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbols)) { 
          throw new RuntimeException("Argument 1 of a ParameterizedSort should have type Symbols");
        }
        break;
      default: throw new RuntimeException("ParameterizedSort does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
