package locationapi.types.slice;

public class Slice extends locationapi.types.Slice {
  public Slice(locationapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_id = 0;
  private static int index_areas = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Slice) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getLocationapiFactory().makeSlice_Slice(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getLocationapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSlice()
  {
    return true;
  }

  public boolean hasId() {
    return true;
  }

  public boolean hasAreas() {
    return true;
  }

  public String getId() {
   return ((aterm.ATermAppl) getArgument(index_id)).getAFun().getName();
  }

  public locationapi.types.Slice setId(String _id) {
    return (locationapi.types.Slice) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_id, 0, true)), index_id);
  }

  public locationapi.types.AreaAreas getAreas() {
    return (locationapi.types.AreaAreas) getArgument(index_areas);
  }

  public locationapi.types.Slice setAreas(locationapi.types.AreaAreas _areas) {
    return (locationapi.types.Slice) super.setArgument(_areas, index_areas);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Slice should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof locationapi.types.AreaAreas)) { 
          throw new RuntimeException("Argument 1 of a Slice should have type Area-areas");
        }
        break;
      default: throw new RuntimeException("Slice does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
