package metastudio.graph;

abstract public class Attribute_SizeImpl
extends Attribute
{
  Attribute_SizeImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_width = 0;
  private static int index_height = 1;
  public shared.SharedObject duplicate() {
    Attribute_Size clone = new Attribute_Size(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Attribute_Size) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Size(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSize()
  {
    return true;
  }

  public boolean hasWidth()
  {
    return true;
  }

  public boolean hasHeight()
  {
    return true;
  }

  public Integer getWidth()
  {
   return new Integer(((aterm.ATermInt) this.getArgument(index_width)).getInt());
  }

  public Attribute setWidth(Integer _width)
  {
    return (Attribute) super.setArgument(getFactory().makeInt(_width.intValue()), index_width);
  }

  public Integer getHeight()
  {
   return new Integer(((aterm.ATermInt) this.getArgument(index_height)).getInt());
  }

  public Attribute setHeight(Integer _height)
  {
    return (Attribute) super.setArgument(getFactory().makeInt(_height.intValue()), index_height);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Attribute_Size should have type int");
        }
        break;
      case 1:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Attribute_Size should have type int");
        }
        break;
      default: throw new RuntimeException("Attribute_Size does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
}
