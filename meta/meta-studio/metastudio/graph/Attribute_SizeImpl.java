package metastudio.graph;

  //{{{ imports

  //}}}
public class Attribute_SizeImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  //{{{ field indexes

  private static int index_width = 0;
  private static int index_height = 1;
  //}}}
  public shared.SharedObject duplicate() {
    Attribute_Size clone = new Attribute_Size();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Size(fun, i_args, annos);
  }
  //{{{ initializePattern()

  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("size(<int>,<int>)");
  }

  //}}}
  //{{{ fromTerm(ATerm trm)

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_Size((Integer) children.get(0), (Integer) children.get(1));
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

  //}}}
  //{{{ getters and setters

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
  //}}}
}
