package errorapi.types;

public class SubjectList extends errorapi.AbstractList {
  private aterm.ATerm term = null;
  public SubjectList(errorapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof SubjectList) {
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
      SubjectList reversed = (SubjectList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortSubjectList()  {
    return true;
  }

  public errorapi.types.Subject getHead() {
    return (errorapi.types.Subject)getFirst();
  }

  public SubjectList getTail() {
    return (SubjectList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getErrorapiFactory().makeSubjectList();
  }

  public SubjectList insert(errorapi.types.Subject head) {
    return getErrorapiFactory().makeSubjectList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getErrorapiFactory().makeSubjectList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getErrorapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public SubjectList reverseSubjectList() {
    return getErrorapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseSubjectList();
  }

  public SubjectList concat(SubjectList peer) {
    return getErrorapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((SubjectList) peer);
  }

  public SubjectList append(errorapi.types.Subject elem) {
    return getErrorapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((errorapi.types.Subject) elem);
  }

  public errorapi.types.Subject getSubjectAt(int index) {
    return (errorapi.types.Subject) elementAt(index);
  }

}
