package nl.cwi.sen1.ioapi.types.segment;

public class Segment extends nl.cwi.sen1.ioapi.types.Segment implements jjtraveler.Visitable {
  public Segment(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_name = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Segment) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getIoapiFactory().makeSegment_Segment(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getIoapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSegment()
  {
    return true;
  }

  public boolean hasName() {
    return true;
  }

  public String getName() {
   return ((aterm.ATermAppl) getArgument(index_name)).getAFun().getName();
  }

  public nl.cwi.sen1.ioapi.types.Segment setName(String _name) {
    return (nl.cwi.sen1.ioapi.types.Segment) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_name, 0, true)), index_name);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Segment should have type str");
        }
        break;
      default: throw new RuntimeException("Segment does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  public nl.cwi.sen1.ioapi.AbstractType accept(nl.cwi.sen1.ioapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_Segment_Segment(this);
  }

}
