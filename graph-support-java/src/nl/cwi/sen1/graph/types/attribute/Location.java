package nl.cwi.sen1.graph.types.attribute;

public class Location extends nl.cwi.sen1.graph.types.Attribute {
  public Location(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_x = 0;
  private static int index_y = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Location) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Location(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLocation()
  {
    return true;
  }

  public boolean hasX() {
    return true;
  }

  public boolean hasY() {
    return true;
  }

  public int getX() {
   return ((aterm.ATermInt) getArgument(index_x)).getInt();
  }

  public nl.cwi.sen1.graph.types.Attribute setX(int _x) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeInt(_x), index_x);
  }

  public int getY() {
   return ((aterm.ATermInt) getArgument(index_y)).getInt();
  }

  public nl.cwi.sen1.graph.types.Attribute setY(int _y) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeInt(_y), index_y);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Location should have type int");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Location should have type int");
        }
        break;
      default: throw new RuntimeException("Location does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
