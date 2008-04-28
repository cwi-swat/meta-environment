package nl.cwi.sen1.configapi.types;

public class TextAttributeMap extends nl.cwi.sen1.configapi.AbstractList {
  private aterm.ATerm term = null;
  public TextAttributeMap(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof TextAttributeMap) {
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
      TextAttributeMap reversed = (TextAttributeMap)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortTextAttributeMap()  {
    return true;
  }

  public nl.cwi.sen1.configapi.types.TextAttribute getHead() {
    return (nl.cwi.sen1.configapi.types.TextAttribute)getFirst();
  }

  public TextAttributeMap getTail() {
    return (TextAttributeMap) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getConfigapiFactory().makeTextAttributeMap();
  }

  public TextAttributeMap insert(nl.cwi.sen1.configapi.types.TextAttribute head) {
    return getConfigapiFactory().makeTextAttributeMap(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getConfigapiFactory().makeTextAttributeMap(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getConfigapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public TextAttributeMap reverseTextAttributeMap() {
    return getConfigapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseTextAttributeMap();
  }

  public TextAttributeMap concat(TextAttributeMap peer) {
    return getConfigapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((TextAttributeMap) peer);
  }

  public TextAttributeMap append(nl.cwi.sen1.configapi.types.TextAttribute elem) {
    return getConfigapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.configapi.types.TextAttribute) elem);
  }

  public nl.cwi.sen1.configapi.types.TextAttribute getTextAttributeAt(int index) {
    return (nl.cwi.sen1.configapi.types.TextAttribute) elementAt(index);
  }

}
