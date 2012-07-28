package nl.cwi.sen1.moduleapi.types;

public class ModuleList extends nl.cwi.sen1.moduleapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public ModuleList(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ModuleList) {
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
      ModuleList reversed = (ModuleList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortModuleList()  {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.Module getHead() {
    return (nl.cwi.sen1.moduleapi.types.Module)getFirst();
  }

  public ModuleList getTail() {
    return (ModuleList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getModuleapiFactory().makeModuleList();
  }

  public ModuleList insert(nl.cwi.sen1.moduleapi.types.Module head) {
    return getModuleapiFactory().makeModuleList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getModuleapiFactory().makeModuleList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getModuleapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public ModuleList reverseModuleList() {
    return getModuleapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseModuleList();
  }

  public ModuleList concat(ModuleList peer) {
    return getModuleapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((ModuleList) peer);
  }

  public ModuleList append(nl.cwi.sen1.moduleapi.types.Module elem) {
    return getModuleapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.moduleapi.types.Module) elem);
  }

  public nl.cwi.sen1.moduleapi.types.Module getModuleAt(int index) {
    return (nl.cwi.sen1.moduleapi.types.Module) elementAt(index);
  }

  public nl.cwi.sen1.moduleapi.AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_ModuleList(this);
  }

}
