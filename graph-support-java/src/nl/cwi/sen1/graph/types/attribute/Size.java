package nl.cwi.sen1.graph.types.attribute;

public class Size extends nl.cwi.sen1.graph.types.Attribute {
  public Size(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_width = 0;
  private static int index_height = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Size) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Size(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSize()
  {
    return true;
  }

  public boolean hasWidth() {
    return true;
  }

  public boolean hasHeight() {
    return true;
  }

  public int getWidth() {
   return ((aterm.ATermInt) getArgument(index_width)).getInt();
  }

  public nl.cwi.sen1.graph.types.Attribute setWidth(int _width) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeInt(_width), index_width);
  }

  public int getHeight() {
   return ((aterm.ATermInt) getArgument(index_height)).getInt();
  }

  public nl.cwi.sen1.graph.types.Attribute setHeight(int _height) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeInt(_height), index_height);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Size should have type int");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Size should have type int");
        }
        break;
      default: throw new RuntimeException("Size does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
