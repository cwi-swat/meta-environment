package nl.cwi.sen1.moduleapi.types;

public class AttributeStore extends nl.cwi.sen1.moduleapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public AttributeStore(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof AttributeStore) {
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
      AttributeStore reversed = (AttributeStore)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortAttributeStore()  {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.Attribute getHead() {
    return (nl.cwi.sen1.moduleapi.types.Attribute)getFirst();
  }

  public AttributeStore getTail() {
    return (AttributeStore) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getModuleapiFactory().makeAttributeStore();
  }

  public AttributeStore insert(nl.cwi.sen1.moduleapi.types.Attribute head) {
    return getModuleapiFactory().makeAttributeStore(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getModuleapiFactory().makeAttributeStore(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getModuleapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public AttributeStore reverseAttributeStore() {
    return getModuleapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseAttributeStore();
  }

  public AttributeStore concat(AttributeStore peer) {
    return getModuleapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((AttributeStore) peer);
  }

  public AttributeStore append(nl.cwi.sen1.moduleapi.types.Attribute elem) {
    return getModuleapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.moduleapi.types.Attribute) elem);
  }

  public nl.cwi.sen1.moduleapi.types.Attribute getAttributeAt(int index) {
    return (nl.cwi.sen1.moduleapi.types.Attribute) elementAt(index);
  }

  public nl.cwi.sen1.moduleapi.AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_AttributeStore(this);
  }

}
