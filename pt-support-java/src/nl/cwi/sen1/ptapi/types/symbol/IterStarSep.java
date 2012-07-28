package nl.cwi.sen1.ptapi.types.symbol;

public class IterStarSep extends nl.cwi.sen1.ptapi.types.Symbol {
  public IterStarSep(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_symbol = 0;
  private static int index_separator = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof IterStarSep) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeSymbol_IterStarSep(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isIterStarSep()
  {
    return true;
  }

  public boolean hasSymbol() {
    return true;
  }

  public boolean hasSeparator() {
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

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 0 of a IterStarSep should have type Symbol");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 1 of a IterStarSep should have type Symbol");
        }
        break;
      default: throw new RuntimeException("IterStarSep does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

}
