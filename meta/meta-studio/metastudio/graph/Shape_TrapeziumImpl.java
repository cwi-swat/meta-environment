package metastudio.graph;

  //{{{ imports

  //}}}
public class Shape_TrapeziumImpl
extends Shape
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  //{{{ field indexes

  //}}}
  public shared.SharedObject duplicate() {
    Shape_Trapezium clone = new Shape_Trapezium();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeShape_Trapezium(fun, i_args, annos);
  }
  //{{{ initializePattern()

  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("trapezium");
  }

  //}}}
  //{{{ fromTerm(ATerm trm)

  static public Shape fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Shape tmp = getStaticMetaGraphFactory().makeShape_Trapezium();
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  //}}}
  //{{{ isXXX and hasXXX properties

  public boolean isTrapezium()
  {
    return true;
  }

  //}}}
  //{{{ getters and setters

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
      throw new RuntimeException("Shape_Trapezium has no arguments");
  }
  //}}}
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = 0x9e3779b9;

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
