package metastudio.graph;

abstract public class Attribute_LocationImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_x = 0;
  private static int index_y = 1;
  public shared.SharedObject duplicate() {
    Attribute_Location clone = new Attribute_Location();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Location(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("location(<int>,<int>)");
  }

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_Location((Integer) children.get(0), (Integer) children.get(1));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public aterm.ATerm toTerm() {
    if(term == null) {
      java.util.List args = new java.util.LinkedList();
      args.add(new Integer(((aterm.ATermInt) getArgument(0)).getInt()));
      args.add(new Integer(((aterm.ATermInt) getArgument(1)).getInt()));
      setTerm(getFactory().make(getPattern(), args));
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
