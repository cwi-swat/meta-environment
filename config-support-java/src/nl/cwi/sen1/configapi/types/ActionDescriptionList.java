package nl.cwi.sen1.configapi.types;

public class ActionDescriptionList extends nl.cwi.sen1.configapi.AbstractList {
  private aterm.ATerm term = null;
  public ActionDescriptionList(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ActionDescriptionList) {
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
      ActionDescriptionList reversed = (ActionDescriptionList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortActionDescriptionList()  {
    return true;
  }

  public nl.cwi.sen1.configapi.types.ActionDescription getHead() {
    return (nl.cwi.sen1.configapi.types.ActionDescription)getFirst();
  }

  public ActionDescriptionList getTail() {
    return (ActionDescriptionList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getConfigapiFactory().makeActionDescriptionList();
  }

  public ActionDescriptionList insert(nl.cwi.sen1.configapi.types.ActionDescription head) {
    return getConfigapiFactory().makeActionDescriptionList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getConfigapiFactory().makeActionDescriptionList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getConfigapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public ActionDescriptionList reverseActionDescriptionList() {
    return getConfigapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseActionDescriptionList();
  }

  public ActionDescriptionList concat(ActionDescriptionList peer) {
    return getConfigapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((ActionDescriptionList) peer);
  }

  public ActionDescriptionList append(nl.cwi.sen1.configapi.types.ActionDescription elem) {
    return getConfigapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.configapi.types.ActionDescription) elem);
  }

  public nl.cwi.sen1.configapi.types.ActionDescription getActionDescriptionAt(int index) {
    return (nl.cwi.sen1.configapi.types.ActionDescription) elementAt(index);
  }

}
