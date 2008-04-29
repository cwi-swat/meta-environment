package errorapi.types;

public class ErrorList extends errorapi.AbstractList {
  private aterm.ATerm term = null;
  public ErrorList(errorapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ErrorList) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getErrorapiFactory().getPureFactory();
    if (this.term == null) {
      ErrorList reversed = (ErrorList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortErrorList()  {
    return true;
  }

  public errorapi.types.Error getHead() {
    return (errorapi.types.Error)getFirst();
  }

  public ErrorList getTail() {
    return (ErrorList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getErrorapiFactory().makeErrorList();
  }

  public ErrorList insert(errorapi.types.Error head) {
    return getErrorapiFactory().makeErrorList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getErrorapiFactory().makeErrorList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getErrorapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public ErrorList reverseErrorList() {
    return getErrorapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseErrorList();
  }

  public ErrorList concat(ErrorList peer) {
    return getErrorapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((ErrorList) peer);
  }

  public ErrorList append(errorapi.types.Error elem) {
    return getErrorapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((errorapi.types.Error) elem);
  }

  public errorapi.types.Error getErrorAt(int index) {
    return (errorapi.types.Error) elementAt(index);
  }

}
