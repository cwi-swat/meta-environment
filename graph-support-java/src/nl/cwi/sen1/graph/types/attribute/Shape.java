package nl.cwi.sen1.graph.types.attribute;

public class Shape extends nl.cwi.sen1.graph.types.Attribute {
  public Shape(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_shape = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Shape) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Shape(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isShape()
  {
    return true;
  }

  public boolean hasShape() {
    return true;
  }

  public nl.cwi.sen1.graph.types.Shape getShape() {
    return (nl.cwi.sen1.graph.types.Shape) getArgument(index_shape);
  }

  public nl.cwi.sen1.graph.types.Attribute setShape(nl.cwi.sen1.graph.types.Shape _shape) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(_shape, index_shape);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.graph.types.Shape)) { 
          throw new RuntimeException("Argument 0 of a Shape should have type Shape");
        }
        break;
      default: throw new RuntimeException("Shape does not have an argument at " + i );
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
