package metastudio.data.graph;

abstract public class Color_RgbImpl
extends Color
{
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  protected Color_RgbImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_red = 0;
  private static int index_green = 1;
  private static int index_blue = 2;
  public shared.SharedObject duplicate() {
    Color_Rgb clone = new Color_Rgb(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Color_Rgb) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeColor_Rgb(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isRgb()
  {
    return true;
  }

  public boolean hasRed()
  {
    return true;
  }

  public boolean hasGreen()
  {
    return true;
  }

  public boolean hasBlue()
  {
    return true;
  }

  public int getRed()
  {
   return ((aterm.ATermInt) this.getArgument(index_red)).getInt();
  }

  public Color setRed(int _red)
  {
    return (Color) super.setArgument(getFactory().makeInt(_red), index_red);
  }

  public int getGreen()
  {
   return ((aterm.ATermInt) this.getArgument(index_green)).getInt();
  }

  public Color setGreen(int _green)
  {
    return (Color) super.setArgument(getFactory().makeInt(_green), index_green);
  }

  public int getBlue()
  {
   return ((aterm.ATermInt) this.getArgument(index_blue)).getInt();
  }

  public Color setBlue(int _blue)
  {
    return (Color) super.setArgument(getFactory().makeInt(_blue), index_blue);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Color_Rgb should have type int");
        }
        break;
      case 1:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Color_Rgb should have type int");
        }
        break;
      case 2:
        if (! (arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 2 of a Color_Rgb should have type int");
        }
        break;
      default: throw new RuntimeException("Color_Rgb does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
}
