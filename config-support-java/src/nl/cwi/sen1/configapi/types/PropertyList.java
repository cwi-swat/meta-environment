package nl.cwi.sen1.configapi.types;

public class PropertyList extends nl.cwi.sen1.configapi.AbstractList {
  private aterm.ATerm term = null;
  public PropertyList(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof PropertyList) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getConfigapiFactory().getPureFactory();
    if (this.term == null) {
      PropertyList reversed = (PropertyList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortPropertyList()  {
    return true;
  }

  public nl.cwi.sen1.configapi.types.Property getHead() {
    return (nl.cwi.sen1.configapi.types.Property)getFirst();
  }

  public PropertyList getTail() {
    return (PropertyList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getConfigapiFactory().makePropertyList();
  }

  public PropertyList insert(nl.cwi.sen1.configapi.types.Property head) {
    return getConfigapiFactory().makePropertyList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getConfigapiFactory().makePropertyList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getConfigapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public PropertyList reversePropertyList() {
    return getConfigapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reversePropertyList();
  }

  public PropertyList concat(PropertyList peer) {
    return getConfigapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((PropertyList) peer);
  }

  public PropertyList append(nl.cwi.sen1.configapi.types.Property elem) {
    return getConfigapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.configapi.types.Property) elem);
  }

  public nl.cwi.sen1.configapi.types.Property getPropertyAt(int index) {
    return (nl.cwi.sen1.configapi.types.Property) elementAt(index);
  }

}
