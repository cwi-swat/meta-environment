package nl.cwi.sen1.graph.types.attribute;

public class Direction extends nl.cwi.sen1.graph.types.Attribute {
  public Direction(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_direction = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Direction) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Direction(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDirection()
  {
    return true;
  }

  public boolean hasDirection() {
    return true;
  }

  public nl.cwi.sen1.graph.types.Direction getDirection() {
    return (nl.cwi.sen1.graph.types.Direction) getArgument(index_direction);
  }

  public nl.cwi.sen1.graph.types.Attribute setDirection(nl.cwi.sen1.graph.types.Direction _direction) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(_direction, index_direction);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.graph.types.Direction)) { 
          throw new RuntimeException("Argument 0 of a Direction should have type Direction");
        }
        break;
      default: throw new RuntimeException("Direction does not have an argument at " + i );
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
