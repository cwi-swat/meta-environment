package nl.cwi.sen1.ptapi.types;

public class Symbols extends nl.cwi.sen1.ptapi.AbstractList {
  private aterm.ATerm term = null;
  public Symbols(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Symbols) {
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
      Symbols reversed = (Symbols)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortSymbols()  {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Symbol getHead() {
    return (nl.cwi.sen1.ptapi.types.Symbol)getFirst();
  }

  public Symbols getTail() {
    return (Symbols) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getPtapiFactory().makeSymbols();
  }

  public Symbols insert(nl.cwi.sen1.ptapi.types.Symbol head) {
    return getPtapiFactory().makeSymbols(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getPtapiFactory().makeSymbols(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getPtapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public Symbols reverseSymbols() {
    return getPtapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseSymbols();
  }

  public Symbols concat(Symbols peer) {
    return getPtapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((Symbols) peer);
  }

  public Symbols append(nl.cwi.sen1.ptapi.types.Symbol elem) {
    return getPtapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.ptapi.types.Symbol) elem);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSymbolAt(int index) {
    return (nl.cwi.sen1.ptapi.types.Symbol) elementAt(index);
  }

}
