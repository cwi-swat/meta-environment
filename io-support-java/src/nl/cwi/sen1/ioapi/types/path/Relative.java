package nl.cwi.sen1.ioapi.types.path;

public class Relative extends nl.cwi.sen1.ioapi.types.Path implements jjtraveler.Visitable {
  public Relative(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_list = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Relative) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getIoapiFactory().makePath_Relative(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getIoapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isRelative()
  {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public nl.cwi.sen1.ioapi.types.SegmentList getList() {
    return (nl.cwi.sen1.ioapi.types.SegmentList) getArgument(index_list);
  }

  public nl.cwi.sen1.ioapi.types.Path setList(nl.cwi.sen1.ioapi.types.SegmentList _list) {
    return (nl.cwi.sen1.ioapi.types.Path) super.setArgument(_list, index_list);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ioapi.types.SegmentList)) { 
          throw new RuntimeException("Argument 0 of a Relative should have type Segment-list");
        }
        break;
      default: throw new RuntimeException("Relative does not have an argument at " + i );
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

  public nl.cwi.sen1.ioapi.AbstractType accept(nl.cwi.sen1.ioapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_Path_Relative(this);
  }

}
