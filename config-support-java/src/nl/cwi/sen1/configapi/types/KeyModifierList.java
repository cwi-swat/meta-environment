package nl.cwi.sen1.configapi.types;

public class KeyModifierList extends nl.cwi.sen1.configapi.AbstractList {
  private aterm.ATerm term = null;
  public KeyModifierList(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof KeyModifierList) {
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
      KeyModifierList reversed = (KeyModifierList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortKeyModifierList()  {
    return true;
  }

  public nl.cwi.sen1.configapi.types.KeyModifier getHead() {
    return (nl.cwi.sen1.configapi.types.KeyModifier)getFirst();
  }

  public KeyModifierList getTail() {
    return (KeyModifierList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getConfigapiFactory().makeKeyModifierList();
  }

  public KeyModifierList insert(nl.cwi.sen1.configapi.types.KeyModifier head) {
    return getConfigapiFactory().makeKeyModifierList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getConfigapiFactory().makeKeyModifierList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getConfigapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public KeyModifierList reverseKeyModifierList() {
    return getConfigapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseKeyModifierList();
  }

  public KeyModifierList concat(KeyModifierList peer) {
    return getConfigapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((KeyModifierList) peer);
  }

  public KeyModifierList append(nl.cwi.sen1.configapi.types.KeyModifier elem) {
    return getConfigapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.configapi.types.KeyModifier) elem);
  }

  public nl.cwi.sen1.configapi.types.KeyModifier getKeyModifierAt(int index) {
    return (nl.cwi.sen1.configapi.types.KeyModifier) elementAt(index);
  }

}
