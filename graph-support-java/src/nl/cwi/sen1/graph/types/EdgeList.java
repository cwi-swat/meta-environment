package nl.cwi.sen1.graph.types;

public class EdgeList extends nl.cwi.sen1.graph.AbstractList {
  private aterm.ATerm term = null;
  public EdgeList(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof EdgeList) {
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
      EdgeList reversed = (EdgeList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortEdgeList()  {
    return true;
  }

  public nl.cwi.sen1.graph.types.Edge getHead() {
    return (nl.cwi.sen1.graph.types.Edge)getFirst();
  }

  public EdgeList getTail() {
    return (EdgeList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getGraphFactory().makeEdgeList();
  }

  public EdgeList insert(nl.cwi.sen1.graph.types.Edge head) {
    return getGraphFactory().makeEdgeList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getGraphFactory().makeEdgeList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getGraphFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public EdgeList reverseEdgeList() {
    return getGraphFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseEdgeList();
  }

  public EdgeList concat(EdgeList peer) {
    return getGraphFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((EdgeList) peer);
  }

  public EdgeList append(nl.cwi.sen1.graph.types.Edge elem) {
    return getGraphFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.graph.types.Edge) elem);
  }

  public nl.cwi.sen1.graph.types.Edge getEdgeAt(int index) {
    return (nl.cwi.sen1.graph.types.Edge) elementAt(index);
  }

}
