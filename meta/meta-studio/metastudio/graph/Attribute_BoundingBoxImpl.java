package metastudio.graph;

abstract public class Attribute_BoundingBoxImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_first = 0;
  private static int index_second = 1;
  public shared.SharedObject duplicate() {
    Attribute_BoundingBox clone = new Attribute_BoundingBox();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_BoundingBox(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("bounding-box(<term>,<term>)");
  }

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_BoundingBox(Point.fromTerm( (aterm.ATerm) children.get(0)), Point.fromTerm( (aterm.ATerm) children.get(1)));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public boolean isBoundingBox()
  {
    return true;
  }

  public boolean hasFirst()
  {
    return true;
  }

  public boolean hasSecond()
  {
    return true;
  }

  public Point getFirst()
  {
    return (Point) this.getArgument(index_first) ;
  }

  public Attribute setFirst(Point _first)
  {
    return (Attribute) super.setArgument(_first, index_first);
  }

  public Point getSecond()
  {
    return (Point) this.getArgument(index_second) ;
  }

  public Attribute setSecond(Point _second)
  {
    return (Attribute) super.setArgument(_second, index_second);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof Point)) { 
          throw new RuntimeException("Argument 0 of a Attribute_BoundingBox should have type Point");
        }
        break;
      case 1:
        if (! (arg instanceof Point)) { 
          throw new RuntimeException("Argument 1 of a Attribute_BoundingBox should have type Point");
        }
        break;
      default: throw new RuntimeException("Attribute_BoundingBox does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = 0x9e3779b9;
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
