package nl.cwi.sen1.configapi.types;

public class ItemLabels extends nl.cwi.sen1.configapi.AbstractList {
  private aterm.ATerm term = null;
  public ItemLabels(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ItemLabels) {
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
      ItemLabels reversed = (ItemLabels)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortItemLabels()  {
    return true;
  }

  public nl.cwi.sen1.configapi.types.Item getHead() {
    return (nl.cwi.sen1.configapi.types.Item)getFirst();
  }

  public ItemLabels getTail() {
    return (ItemLabels) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getConfigapiFactory().makeItemLabels();
  }

  public ItemLabels insert(nl.cwi.sen1.configapi.types.Item head) {
    return getConfigapiFactory().makeItemLabels(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getConfigapiFactory().makeItemLabels(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getConfigapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public ItemLabels reverseItemLabels() {
    return getConfigapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseItemLabels();
  }

  public ItemLabels concat(ItemLabels peer) {
    return getConfigapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((ItemLabels) peer);
  }

  public ItemLabels append(nl.cwi.sen1.configapi.types.Item elem) {
    return getConfigapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.configapi.types.Item) elem);
  }

  public nl.cwi.sen1.configapi.types.Item getItemAt(int index) {
    return (nl.cwi.sen1.configapi.types.Item) elementAt(index);
  }

}
