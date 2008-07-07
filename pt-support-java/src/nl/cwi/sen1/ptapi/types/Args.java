package nl.cwi.sen1.ptapi.types;

public class Args extends nl.cwi.sen1.ptapi.AbstractList {
  private aterm.ATerm term = null;
  public Args(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Args) {
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
      Args reversed = (Args)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortArgs()  {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Tree getHead() {
    return (nl.cwi.sen1.ptapi.types.Tree)getFirst();
  }

  public Args getTail() {
    return (Args) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getPtapiFactory().makeArgs();
  }

  public Args insert(nl.cwi.sen1.ptapi.types.Tree head) {
    return getPtapiFactory().makeArgs(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getPtapiFactory().makeArgs(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getPtapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public Args reverseArgs() {
    return getPtapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseArgs();
  }

  public Args concat(Args peer) {
    return getPtapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((Args) peer);
  }

  public Args append(nl.cwi.sen1.ptapi.types.Tree elem) {
    return getPtapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.ptapi.types.Tree) elem);
  }

  public nl.cwi.sen1.ptapi.types.Tree getTreeAt(int index) {
    return (nl.cwi.sen1.ptapi.types.Tree) elementAt(index);
  }

}
