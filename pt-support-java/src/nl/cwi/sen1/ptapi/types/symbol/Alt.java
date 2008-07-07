package nl.cwi.sen1.ptapi.types.symbol;

public class Alt extends nl.cwi.sen1.ptapi.types.Symbol {
  public Alt(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_lhs = 0;
  private static int index_rhs = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Alt) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeSymbol_Alt(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isAlt()
  {
    return true;
  }

  public boolean hasLhs() {
    return true;
  }

  public boolean hasRhs() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Symbol getLhs() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_lhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol setLhs(nl.cwi.sen1.ptapi.types.Symbol _lhs) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(_lhs, index_lhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getRhs() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_rhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol setRhs(nl.cwi.sen1.ptapi.types.Symbol _rhs) {
    return (nl.cwi.sen1.ptapi.types.Symbol) super.setArgument(_rhs, index_rhs);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 0 of a Alt should have type Symbol");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 1 of a Alt should have type Symbol");
        }
        break;
      default: throw new RuntimeException("Alt does not have an argument at " + i );
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
