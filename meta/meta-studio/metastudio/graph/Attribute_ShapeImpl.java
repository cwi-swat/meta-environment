package metastudio.graph;

  //{{{ imports

  //}}}
public class Attribute_ShapeImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  //{{{ field indexes

  private static int index_shape = 0;
  //}}}
  public shared.SharedObject duplicate() {
    Attribute_Shape clone = new Attribute_Shape();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Shape(fun, i_args, annos);
  }
  //{{{ initializePattern()

  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("shape(<term>)");
  }

  //}}}
  //{{{ fromTerm(ATerm trm)

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_Shape(Shape.fromTerm( (aterm.ATerm) children.get(0)));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  //}}}
  //{{{ isXXX and hasXXX properties

  public boolean isShape()
  {
    return true;
  }

  public boolean hasShape()
  {
    return true;
  }

  //}}}
  //{{{ getters and setters

  public Shape getShape()
  {
    return (Shape) this.getArgument(index_shape) ;
  }

  public Attribute setShape(Shape _shape)
  {
    return (Attribute) super.setArgument(_shape, index_shape);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof Shape)) { 
          throw new RuntimeException("Argument 0 of a Attribute_Shape should have type Shape");
        }
        break;
      default: throw new RuntimeException("Attribute_Shape does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  //}}}
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = 0x9e3779b9;
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
