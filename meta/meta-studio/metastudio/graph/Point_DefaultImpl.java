package metastudio.graph;

  //{{{ imports

  //}}}
public class Point_DefaultImpl
extends Point
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  //{{{ field indexes

  private static int index_x = 0;
  private static int index_y = 1;
  //}}}
  public shared.SharedObject duplicate() {
    Point_Default clone = new Point_Default();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makePoint_Default(fun, i_args, annos);
  }
  //{{{ initializePattern()

  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("point(<int>,<int>)");
  }

  //}}}
  //{{{ fromTerm(ATerm trm)

  static public Point fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Point tmp = getStaticMetaGraphFactory().makePoint_Default((Integer) children.get(0), (Integer) children.get(1));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  //}}}
  public aterm.ATerm toTerm() {
    if(term == null) {
      java.util.List args = new java.util.LinkedList();
      args.add(new Integer(((aterm.ATermInt) getArgument(0)).getInt()));
      args.add(new Integer(((aterm.ATermInt) getArgument(1)).getInt()));
      setTerm(getFactory().make(getPattern(), args));
    }
    return term;
  }

  //{{{ isXXX and hasXXX properties

  public boolean isDefault()
  {
    return true;
  }

  public boolean hasX()
  {
    return true;
  }

  public boolean hasY()
  {
    return true;
  }

  //}}}
  //{{{ getters and setters

  public Integer getX()
  {
   return new Integer(((aterm.ATermInt) this.getArgument(index_x)).getInt());
  }

  public Point setX(Integer _x)
  {
    return (Point) super.setArgument(getFactory().makeInt(_x.intValue()), index_x);
  }

  public Integer getY()
  {
   return new Integer(((aterm.ATermInt) this.getArgument(index_y)).getInt());
  }

  public Point setY(Integer _y)
  {
    return (Point) super.setArgument(getFactory().makeInt(_y.intValue()), index_y);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Point_Default should have type int");
        }
        break;
      case 1:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Point_Default should have type int");
        }
        break;
      default: throw new RuntimeException("Point_Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  //}}}
}
