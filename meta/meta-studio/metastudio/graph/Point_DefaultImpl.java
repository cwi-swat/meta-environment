package metastudio.graph;

abstract public class Point_DefaultImpl
extends Point
{
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  Point_DefaultImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_x = 0;
  private static int index_y = 1;
  public shared.SharedObject duplicate() {
    Point_Default clone = new Point_Default(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Point_Default) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makePoint_Default(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

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
}
