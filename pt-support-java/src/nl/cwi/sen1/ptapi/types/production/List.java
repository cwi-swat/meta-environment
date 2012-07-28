package nl.cwi.sen1.ptapi.types.production;

public class List extends nl.cwi.sen1.ptapi.types.Production {
  public List(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_rhs = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof List) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeProduction_List(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isList()
  {
    return true;
  }

  public boolean hasRhs() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Symbol getRhs() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_rhs);
  }

  public nl.cwi.sen1.ptapi.types.Production setRhs(nl.cwi.sen1.ptapi.types.Symbol _rhs) {
    return (nl.cwi.sen1.ptapi.types.Production) super.setArgument(_rhs, index_rhs);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 0 of a List should have type Symbol");
        }
        break;
      default: throw new RuntimeException("List does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
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
