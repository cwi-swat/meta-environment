package metastudio.graph;

abstract public class Attribute_LocationImpl
extends Attribute
{
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  Attribute_LocationImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_x = 0;
  private static int index_y = 1;
  public shared.SharedObject duplicate() {
    Attribute_Location clone = new Attribute_Location(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Attribute_Location) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Location(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLocation()
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

  public Attribute setX(Integer _x)
  {
    return (Attribute) super.setArgument(getFactory().makeInt(_x.intValue()), index_x);
  }

  public Integer getY()
  {
   return new Integer(((aterm.ATermInt) this.getArgument(index_y)).getInt());
  }

  public Attribute setY(Integer _y)
  {
    return (Attribute) super.setArgument(getFactory().makeInt(_y.intValue()), index_y);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Attribute_Location should have type int");
        }
        break;
      case 1:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Attribute_Location should have type int");
        }
        break;
      default: throw new RuntimeException("Attribute_Location does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
}
