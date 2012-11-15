package nl.cwi.sen1.graph.types.color;

public class Rgb extends nl.cwi.sen1.graph.types.Color {
  public Rgb(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_red = 0;
  private static int index_green = 1;
  private static int index_blue = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Rgb) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeColor_Rgb(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isRgb()
  {
    return true;
  }

  public boolean hasRed() {
    return true;
  }

  public boolean hasGreen() {
    return true;
  }

  public boolean hasBlue() {
    return true;
  }

  public int getRed() {
   return ((aterm.ATermInt) getArgument(index_red)).getInt();
  }

  public nl.cwi.sen1.graph.types.Color setRed(int _red) {
    return (nl.cwi.sen1.graph.types.Color) super.setArgument(getFactory().makeInt(_red), index_red);
  }

  public int getGreen() {
   return ((aterm.ATermInt) getArgument(index_green)).getInt();
  }

  public nl.cwi.sen1.graph.types.Color setGreen(int _green) {
    return (nl.cwi.sen1.graph.types.Color) super.setArgument(getFactory().makeInt(_green), index_green);
  }

  public int getBlue() {
   return ((aterm.ATermInt) getArgument(index_blue)).getInt();
  }

  public nl.cwi.sen1.graph.types.Color setBlue(int _blue) {
    return (nl.cwi.sen1.graph.types.Color) super.setArgument(getFactory().makeInt(_blue), index_blue);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Rgb should have type int");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Rgb should have type int");
        }
        break;
      case 2:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 2 of a Rgb should have type int");
        }
        break;
      default: throw new RuntimeException("Rgb does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
