package metastudio.graph;

abstract public class Attribute_DirectionImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_direction = 0;
  public shared.SharedObject duplicate() {
    Attribute_Direction clone = new Attribute_Direction();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Direction(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("direction(<term>)");
  }

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_Direction(Direction.fromTerm( (aterm.ATerm) children.get(0)));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public boolean isDirection()
  {
    return true;
  }

  public boolean hasDirection()
  {
    return true;
  }

  public Direction getDirection()
  {
    return (Direction) this.getArgument(index_direction) ;
  }

  public Attribute setDirection(Direction _direction)
  {
    return (Attribute) super.setArgument(_direction, index_direction);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof Direction)) { 
          throw new RuntimeException("Argument 0 of a Attribute_Direction should have type Direction");
        }
        break;
      default: throw new RuntimeException("Attribute_Direction does not have an argument at " + i );
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
