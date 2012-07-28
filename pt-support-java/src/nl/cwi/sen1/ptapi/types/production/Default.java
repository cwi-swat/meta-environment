package nl.cwi.sen1.ptapi.types.production;

public class Default extends nl.cwi.sen1.ptapi.types.Production {
  public Default(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_lhs = 0;
  private static int index_rhs = 1;
  private static int index_attributes = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Default) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeProduction_Default(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDefault()
  {
    return true;
  }

  public boolean hasLhs() {
    return true;
  }

  public boolean hasRhs() {
    return true;
  }

  public boolean hasAttributes() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Symbols getLhs() {
    return (nl.cwi.sen1.ptapi.types.Symbols) getArgument(index_lhs);
  }

  public nl.cwi.sen1.ptapi.types.Production setLhs(nl.cwi.sen1.ptapi.types.Symbols _lhs) {
    return (nl.cwi.sen1.ptapi.types.Production) super.setArgument(_lhs, index_lhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getRhs() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_rhs);
  }

  public nl.cwi.sen1.ptapi.types.Production setRhs(nl.cwi.sen1.ptapi.types.Symbol _rhs) {
    return (nl.cwi.sen1.ptapi.types.Production) super.setArgument(_rhs, index_rhs);
  }

  public nl.cwi.sen1.ptapi.types.Attributes getAttributes() {
    return (nl.cwi.sen1.ptapi.types.Attributes) getArgument(index_attributes);
  }

  public nl.cwi.sen1.ptapi.types.Production setAttributes(nl.cwi.sen1.ptapi.types.Attributes _attributes) {
    return (nl.cwi.sen1.ptapi.types.Production) super.setArgument(_attributes, index_attributes);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbols)) { 
          throw new RuntimeException("Argument 0 of a Default should have type Symbols");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 1 of a Default should have type Symbol");
        }
        break;
      case 2:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Attributes)) { 
          throw new RuntimeException("Argument 2 of a Default should have type Attributes");
        }
        break;
      default: throw new RuntimeException("Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(2).hashCode() << 16);
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
