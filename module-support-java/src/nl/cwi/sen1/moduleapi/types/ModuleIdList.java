package nl.cwi.sen1.moduleapi.types;

public class ModuleIdList extends nl.cwi.sen1.moduleapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public ModuleIdList(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ModuleIdList) {
      return super.equivalent(peer);
    }
    return false;
  }

  public shared.SharedObject duplicate() {
    return this;
  }

  public aterm.ATerm toTerm() {
    aterm.ATermFactory atermFactory = getModuleapiFactory().getPureFactory();
    if (this.term == null) {
      ModuleIdList reversed = (ModuleIdList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortModuleIdList()  {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getHead() {
    return (nl.cwi.sen1.moduleapi.types.ModuleId)getFirst();
  }

  public ModuleIdList getTail() {
    return (ModuleIdList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getModuleapiFactory().makeModuleIdList();
  }

  public ModuleIdList insert(nl.cwi.sen1.moduleapi.types.ModuleId head) {
    return getModuleapiFactory().makeModuleIdList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getModuleapiFactory().makeModuleIdList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getModuleapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public ModuleIdList reverseModuleIdList() {
    return getModuleapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseModuleIdList();
  }

  public ModuleIdList concat(ModuleIdList peer) {
    return getModuleapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((ModuleIdList) peer);
  }

  public ModuleIdList append(nl.cwi.sen1.moduleapi.types.ModuleId elem) {
    return getModuleapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.moduleapi.types.ModuleId) elem);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getModuleIdAt(int index) {
    return (nl.cwi.sen1.moduleapi.types.ModuleId) elementAt(index);
  }

  public nl.cwi.sen1.moduleapi.AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_ModuleIdList(this);
  }

}
