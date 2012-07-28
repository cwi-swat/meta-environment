package nl.cwi.sen1.moduleapi.types;

public class ModuleAttributeList extends nl.cwi.sen1.moduleapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public ModuleAttributeList(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ModuleAttributeList) {
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
      ModuleAttributeList reversed = (ModuleAttributeList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortModuleAttributeList()  {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute getHead() {
    return (nl.cwi.sen1.moduleapi.types.ModuleAttribute)getFirst();
  }

  public ModuleAttributeList getTail() {
    return (ModuleAttributeList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getModuleapiFactory().makeModuleAttributeList();
  }

  public ModuleAttributeList insert(nl.cwi.sen1.moduleapi.types.ModuleAttribute head) {
    return getModuleapiFactory().makeModuleAttributeList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getModuleapiFactory().makeModuleAttributeList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getModuleapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public ModuleAttributeList reverseModuleAttributeList() {
    return getModuleapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseModuleAttributeList();
  }

  public ModuleAttributeList concat(ModuleAttributeList peer) {
    return getModuleapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((ModuleAttributeList) peer);
  }

  public ModuleAttributeList append(nl.cwi.sen1.moduleapi.types.ModuleAttribute elem) {
    return getModuleapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.moduleapi.types.ModuleAttribute) elem);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute getModuleAttributeAt(int index) {
    return (nl.cwi.sen1.moduleapi.types.ModuleAttribute) elementAt(index);
  }

  public nl.cwi.sen1.moduleapi.AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_ModuleAttributeList(this);
  }

}
