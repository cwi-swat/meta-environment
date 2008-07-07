package nl.cwi.sen1.ptapi.types.tree;

public class Appl extends nl.cwi.sen1.ptapi.types.Tree {
  public Appl(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_prod = 0;
  private static int index_args = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Appl) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeTree_Appl(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isAppl()
  {
    return true;
  }

  public boolean hasProd() {
    return true;
  }

  public boolean hasArgs() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Production getProd() {
    return (nl.cwi.sen1.ptapi.types.Production) getArgument(index_prod);
  }

  public nl.cwi.sen1.ptapi.types.Tree setProd(nl.cwi.sen1.ptapi.types.Production _prod) {
    return (nl.cwi.sen1.ptapi.types.Tree) super.setArgument(_prod, index_prod);
  }

  public nl.cwi.sen1.ptapi.types.Args getArgs() {
    return (nl.cwi.sen1.ptapi.types.Args) getArgument(index_args);
  }

  public nl.cwi.sen1.ptapi.types.Tree setArgs(nl.cwi.sen1.ptapi.types.Args _args) {
    return (nl.cwi.sen1.ptapi.types.Tree) super.setArgument(_args, index_args);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Production)) { 
          throw new RuntimeException("Argument 0 of a Appl should have type Production");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Args)) { 
          throw new RuntimeException("Argument 1 of a Appl should have type Args");
        }
        break;
      default: throw new RuntimeException("Appl does not have an argument at " + i );
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
