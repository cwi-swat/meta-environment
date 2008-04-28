package nl.cwi.sen1.moduleapi.types;

public class DependencyList extends nl.cwi.sen1.moduleapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public DependencyList(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof DependencyList) {
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
      DependencyList reversed = (DependencyList)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortDependencyList()  {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.Dependency getHead() {
    return (nl.cwi.sen1.moduleapi.types.Dependency)getFirst();
  }

  public DependencyList getTail() {
    return (DependencyList) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getModuleapiFactory().makeDependencyList();
  }

  public DependencyList insert(nl.cwi.sen1.moduleapi.types.Dependency head) {
    return getModuleapiFactory().makeDependencyList(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getModuleapiFactory().makeDependencyList(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getModuleapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public DependencyList reverseDependencyList() {
    return getModuleapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseDependencyList();
  }

  public DependencyList concat(DependencyList peer) {
    return getModuleapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((DependencyList) peer);
  }

  public DependencyList append(nl.cwi.sen1.moduleapi.types.Dependency elem) {
    return getModuleapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.moduleapi.types.Dependency) elem);
  }

  public nl.cwi.sen1.moduleapi.types.Dependency getDependencyAt(int index) {
    return (nl.cwi.sen1.moduleapi.types.Dependency) elementAt(index);
  }

  public nl.cwi.sen1.moduleapi.AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_DependencyList(this);
  }

}
