package nl.cwi.sen1.graph.types;

public class NodeList extends nl.cwi.sen1.graph.AbstractList {
  private aterm.ATerm term = null;
  public NodeList(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof NodeList) {
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
      NodeList reversed = (NodeList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortNodeList()  {
    return true;
  }

  public nl.cwi.sen1.graph.types.Node getHead() {
    return (nl.cwi.sen1.graph.types.Node)getFirst();
  }

  public NodeList getTail() {
    return (NodeList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getGraphFactory().makeNodeList();
  }

  public NodeList insert(nl.cwi.sen1.graph.types.Node head) {
    return getGraphFactory().makeNodeList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getGraphFactory().makeNodeList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getGraphFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public NodeList reverseNodeList() {
    return getGraphFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseNodeList();
  }

  public NodeList concat(NodeList peer) {
    return getGraphFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((NodeList) peer);
  }

  public NodeList append(nl.cwi.sen1.graph.types.Node elem) {
    return getGraphFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.graph.types.Node) elem);
  }

  public nl.cwi.sen1.graph.types.Node getNodeAt(int index) {
    return (nl.cwi.sen1.graph.types.Node) elementAt(index);
  }

}
