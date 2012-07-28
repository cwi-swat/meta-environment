package locationapi.types.location;

public class AreaInFile extends locationapi.types.Location {
  public AreaInFile(locationapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_filename = 0;
  private static int index_Area = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof AreaInFile) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getLocationapiFactory().makeLocation_AreaInFile(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getLocationapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isAreaInFile()
  {
    return true;
  }

  public boolean hasFilename() {
    return true;
  }

  public boolean hasArea() {
    return true;
  }

  public String getFilename() {
   return ((aterm.ATermAppl) getArgument(index_filename)).getAFun().getName();
  }

  public locationapi.types.Location setFilename(String _filename) {
    return (locationapi.types.Location) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_filename, 0, true)), index_filename);
  }

  public locationapi.types.Area getArea() {
    return (locationapi.types.Area) getArgument(index_Area);
  }

  public locationapi.types.Location setArea(locationapi.types.Area _Area) {
    return (locationapi.types.Location) super.setArgument(_Area, index_Area);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a AreaInFile should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof locationapi.types.Area)) { 
          throw new RuntimeException("Argument 1 of a AreaInFile should have type Area");
        }
        break;
      default: throw new RuntimeException("AreaInFile does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
