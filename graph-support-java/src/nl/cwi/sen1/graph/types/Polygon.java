package nl.cwi.sen1.graph.types;

public class Polygon extends nl.cwi.sen1.graph.AbstractList {
  private aterm.ATerm term = null;
  public Polygon(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Polygon) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getGraphFactory().getPureFactory();
    if (this.term == null) {
      Polygon reversed = (Polygon)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortPolygon()  {
    return true;
  }

  public nl.cwi.sen1.graph.types.Point getHead() {
    return (nl.cwi.sen1.graph.types.Point)getFirst();
  }

  public Polygon getTail() {
    return (Polygon) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getGraphFactory().makePolygon();
  }

  public Polygon insert(nl.cwi.sen1.graph.types.Point head) {
    return getGraphFactory().makePolygon(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getGraphFactory().makePolygon(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getGraphFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public Polygon reversePolygon() {
    return getGraphFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reversePolygon();
  }

  public Polygon concat(Polygon peer) {
    return getGraphFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((Polygon) peer);
  }

  public Polygon append(nl.cwi.sen1.graph.types.Point elem) {
    return getGraphFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.graph.types.Point) elem);
  }

  public nl.cwi.sen1.graph.types.Point getPointAt(int index) {
    return (nl.cwi.sen1.graph.types.Point) elementAt(index);
  }

}
