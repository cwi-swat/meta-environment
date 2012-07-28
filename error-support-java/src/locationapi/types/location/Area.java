package locationapi.types.location;

public class Area extends locationapi.types.Location {
  public Area(locationapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_Area = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Area) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getLocationapiFactory().makeLocation_Area(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getLocationapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isArea()
  {
    return true;
  }

  public boolean hasArea() {
    return true;
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
        if (!(arg instanceof locationapi.types.Area)) { 
          throw new RuntimeException("Argument 0 of a Area should have type Area");
        }
        break;
      default: throw new RuntimeException("Area does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

}
