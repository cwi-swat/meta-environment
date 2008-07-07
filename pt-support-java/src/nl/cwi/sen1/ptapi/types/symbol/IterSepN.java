package nl.cwi.sen1.ptapi.types.symbol;

public class IterSepN extends nl.cwi.sen1.ptapi.types.Symbol {
  public IterSepN(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_symbol = 0;
  private static int index_separator = 1;
  private static int index_number = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof IterSepN) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeSymbol_IterSepN(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isIterSepN()
  {
    return true;
  }

  public boolean hasSymbol() {
    return true;
  }

  public boolean hasSeparator() {
    return true;
  }

  public boolean hasNumber() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSymbol() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_symbol);
  }

  public nl.cwi.sen1.ptapi.types.Symbol setSymbol(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(_symbol, index_symbol);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSeparator() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_separator);
  }

  public nl.cwi.sen1.ptapi.types.Symbol setSeparator(nl.cwi.sen1.ptapi.types.Symbol _separator) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(_separator, index_separator);
  }

  public int getNumber() {
   return ((aterm.ATermInt) getArgument(index_number)).getInt();
  }

  public nl.cwi.sen1.ptapi.types.Symbol setNumber(int _number) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(getFactory().makeInt(_number), index_number);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 0 of a IterSepN should have type Symbol");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 1 of a IterSepN should have type Symbol");
        }
        break;
      case 2:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 2 of a IterSepN should have type int");
        }
        break;
      default: throw new RuntimeException("IterSepN does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
