package nl.cwi.sen1.graph.types.attribute;

public class BoundingBox extends nl.cwi.sen1.graph.types.Attribute {
  public BoundingBox(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_first = 0;
  private static int index_second = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof BoundingBox) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_BoundingBox(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isBoundingBox()
  {
    return true;
  }

  public boolean hasFirst() {
    return true;
  }

  public boolean hasSecond() {
    return true;
  }

  public nl.cwi.sen1.graph.types.Point getFirst() {
    return (nl.cwi.sen1.graph.types.Point) getArgument(index_first);
  }

  public nl.cwi.sen1.graph.types.Attribute setFirst(nl.cwi.sen1.graph.types.Point _first) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(_first, index_first);
  }

  public nl.cwi.sen1.graph.types.Point getSecond() {
    return (nl.cwi.sen1.graph.types.Point) getArgument(index_second);
  }

  public nl.cwi.sen1.graph.types.Attribute setSecond(nl.cwi.sen1.graph.types.Point _second) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(_second, index_second);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.graph.types.Point)) { 
          throw new RuntimeException("Argument 0 of a BoundingBox should have type Point");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.graph.types.Point)) { 
          throw new RuntimeException("Argument 1 of a BoundingBox should have type Point");
        }
        break;
      default: throw new RuntimeException("BoundingBox does not have an argument at " + i );
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
