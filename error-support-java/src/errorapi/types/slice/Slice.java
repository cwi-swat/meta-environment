package errorapi.types.slice;

public class Slice extends errorapi.types.Slice {
  public Slice(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
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
    return getErrorapiFactory().makeSlice_Slice(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getErrorapiFactory().toTerm(this);
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

  public errorapi.types.Slice setId(String _id) {
    return (errorapi.types.Slice) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_id, 0, true)), index_id);
  }

  public errorapi.types.AreaAreas getAreas() {
    return (errorapi.types.AreaAreas) getArgument(index_areas);
  }

  public errorapi.types.Slice setAreas(errorapi.types.AreaAreas _areas) {
    return (errorapi.types.Slice) super.setArgument(_areas, index_areas);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Slice should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof errorapi.types.AreaAreas)) { 
          throw new RuntimeException("Argument 1 of a Slice should have type Area-areas");
        }
        break;
      default: throw new RuntimeException("Slice does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
