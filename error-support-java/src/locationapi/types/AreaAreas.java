package locationapi.types;

public class AreaAreas extends locationapi.AbstractList {
  private aterm.ATerm term = null;
  public AreaAreas(locationapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
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
    aterm.ATermFactory atermFactory = getLocationapiFactory().getPureFactory();
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

  public locationapi.types.Area getHead() {
    return (locationapi.types.Area)getFirst();
  }

  public AreaAreas getTail() {
    return (AreaAreas) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getLocationapiFactory().makeAreaAreas();
  }

  public AreaAreas insert(locationapi.types.Area head) {
    return getLocationapiFactory().makeAreaAreas(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getLocationapiFactory().makeAreaAreas(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getLocationapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public AreaAreas reverseAreaAreas() {
    return getLocationapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseAreaAreas();
  }

  public AreaAreas concat(AreaAreas peer) {
    return getLocationapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((AreaAreas) peer);
  }

  public AreaAreas append(locationapi.types.Area elem) {
    return getLocationapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((locationapi.types.Area) elem);
  }

  public locationapi.types.Area getAreaAt(int index) {
    return (locationapi.types.Area) elementAt(index);
  }

}