package errorapi.types;

public class AreaAreas extends errorapi.AbstractList {
  private aterm.ATerm term = null;
  public AreaAreas(errorapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof AreaAreas) {
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
      AreaAreas reversed = (AreaAreas)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortAreaAreas()  {
    return true;
  }

  public errorapi.types.Area getHead() {
    return (errorapi.types.Area)getFirst();
  }

  public AreaAreas getTail() {
    return (AreaAreas) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getErrorapiFactory().makeAreaAreas();
  }

  public AreaAreas insert(errorapi.types.Area head) {
    return getErrorapiFactory().makeAreaAreas(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getErrorapiFactory().makeAreaAreas(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getErrorapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public AreaAreas reverseAreaAreas() {
    return getErrorapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseAreaAreas();
  }

  public AreaAreas concat(AreaAreas peer) {
    return getErrorapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((AreaAreas) peer);
  }

  public AreaAreas append(errorapi.types.Area elem) {
    return getErrorapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((errorapi.types.Area) elem);
  }

  public errorapi.types.Area getAreaAt(int index) {
    return (errorapi.types.Area) elementAt(index);
  }

}
