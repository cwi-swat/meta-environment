package nl.cwi.sen1.ptapi.types;

public class Attrs extends nl.cwi.sen1.ptapi.AbstractList {
  private aterm.ATerm term = null;
  public Attrs(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Attrs) {
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
      Attrs reversed = (Attrs)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortAttrs()  {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Attr getHead() {
    return (nl.cwi.sen1.ptapi.types.Attr)getFirst();
  }

  public Attrs getTail() {
    return (Attrs) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getPtapiFactory().makeAttrs();
  }

  public Attrs insert(nl.cwi.sen1.ptapi.types.Attr head) {
    return getPtapiFactory().makeAttrs(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getPtapiFactory().makeAttrs(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getPtapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public Attrs reverseAttrs() {
    return getPtapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseAttrs();
  }

  public Attrs concat(Attrs peer) {
    return getPtapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((Attrs) peer);
  }

  public Attrs append(nl.cwi.sen1.ptapi.types.Attr elem) {
    return getPtapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.ptapi.types.Attr) elem);
  }

  public nl.cwi.sen1.ptapi.types.Attr getAttrAt(int index) {
    return (nl.cwi.sen1.ptapi.types.Attr) elementAt(index);
  }

}
