package nl.cwi.sen1.ioapi.types;

public class SegmentList extends nl.cwi.sen1.ioapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public SegmentList(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof SegmentList) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getIoapiFactory().getPureFactory();
    if (this.term == null) {
      SegmentList reversed = (SegmentList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortSegmentList()  {
    return true;
  }

  public nl.cwi.sen1.ioapi.types.Segment getHead() {
    return (nl.cwi.sen1.ioapi.types.Segment)getFirst();
  }

  public SegmentList getTail() {
    return (SegmentList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getIoapiFactory().makeSegmentList();
  }

  public SegmentList insert(nl.cwi.sen1.ioapi.types.Segment head) {
    return getIoapiFactory().makeSegmentList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getIoapiFactory().makeSegmentList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getIoapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public SegmentList reverseSegmentList() {
    return getIoapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseSegmentList();
  }

  public SegmentList concat(SegmentList peer) {
    return getIoapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((SegmentList) peer);
  }

  public SegmentList append(nl.cwi.sen1.ioapi.types.Segment elem) {
    return getIoapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.ioapi.types.Segment) elem);
  }

  public nl.cwi.sen1.ioapi.types.Segment getSegmentAt(int index) {
    return (nl.cwi.sen1.ioapi.types.Segment) elementAt(index);
  }

  public nl.cwi.sen1.ioapi.AbstractList accept(nl.cwi.sen1.ioapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_SegmentList(this);
  }

}
