package metastudio.graph;

abstract public class Shape_HouseImpl
extends Shape
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  public shared.SharedObject duplicate() {
    Shape_House clone = new Shape_House();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeShape_House(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("house");
  }

  static public Shape fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Shape tmp = getStaticMetaGraphFactory().makeShape_House();
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public boolean isHouse()
  {
    return true;
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
      throw new RuntimeException("Shape_House has no arguments");
  }
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);

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
