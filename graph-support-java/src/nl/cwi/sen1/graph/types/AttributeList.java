package nl.cwi.sen1.graph.types;

public class AttributeList extends nl.cwi.sen1.graph.AbstractList {
  private aterm.ATerm term = null;
  public AttributeList(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof AttributeList) {
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
      AttributeList reversed = (AttributeList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortAttributeList()  {
    return true;
  }

  public nl.cwi.sen1.graph.types.Attribute getHead() {
    return (nl.cwi.sen1.graph.types.Attribute)getFirst();
  }

  public AttributeList getTail() {
    return (AttributeList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getGraphFactory().makeAttributeList();
  }

  public AttributeList insert(nl.cwi.sen1.graph.types.Attribute head) {
    return getGraphFactory().makeAttributeList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getGraphFactory().makeAttributeList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getGraphFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public AttributeList reverseAttributeList() {
    return getGraphFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseAttributeList();
  }

  public AttributeList concat(AttributeList peer) {
    return getGraphFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((AttributeList) peer);
  }

  public AttributeList append(nl.cwi.sen1.graph.types.Attribute elem) {
    return getGraphFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.graph.types.Attribute) elem);
  }

  public nl.cwi.sen1.graph.types.Attribute getAttributeAt(int index) {
    return (nl.cwi.sen1.graph.types.Attribute) elementAt(index);
  }

}
