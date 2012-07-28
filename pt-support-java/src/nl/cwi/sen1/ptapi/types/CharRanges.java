package nl.cwi.sen1.ptapi.types;

public class CharRanges extends nl.cwi.sen1.ptapi.AbstractList {
  private aterm.ATerm term = null;
  public CharRanges(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof CharRanges) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getPtapiFactory().getPureFactory();
    if (this.term == null) {
      CharRanges reversed = (CharRanges)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortCharRanges()  {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.CharRange getHead() {
    return (nl.cwi.sen1.ptapi.types.CharRange)getFirst();
  }

  public CharRanges getTail() {
    return (CharRanges) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getPtapiFactory().makeCharRanges();
  }

  public CharRanges insert(nl.cwi.sen1.ptapi.types.CharRange head) {
    return getPtapiFactory().makeCharRanges(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getPtapiFactory().makeCharRanges(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getPtapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public CharRanges reverseCharRanges() {
    return getPtapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseCharRanges();
  }

  public CharRanges concat(CharRanges peer) {
    return getPtapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((CharRanges) peer);
  }

  public CharRanges append(nl.cwi.sen1.ptapi.types.CharRange elem) {
    return getPtapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.ptapi.types.CharRange) elem);
  }

  public nl.cwi.sen1.ptapi.types.CharRange getCharRangeAt(int index) {
    return (nl.cwi.sen1.ptapi.types.CharRange) elementAt(index);
  }

}
