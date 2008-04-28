package nl.cwi.sen1.moduleapi.types;

public class TableEntryTable extends nl.cwi.sen1.moduleapi.AbstractList implements jjtraveler.Visitable {
  private aterm.ATerm term = null;
  public TableEntryTable(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.ATerm first, aterm.ATermList next) {
     super(factory, annos, first, next);
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof TableEntryTable) {
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
      TableEntryTable reversed = (TableEntryTable)this.reverse();
      aterm.ATermList tmp = atermFactory.makeList();
      for (; !reversed.isEmpty(); reversed = reversed.getTail()) {
        aterm.ATerm elem = reversed.getHead().toTerm();
        tmp = atermFactory.makeList(elem, tmp);
      }
      this.term = tmp;
    }
    return this.term;
  }

  public boolean isSortTableEntryTable()  {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry getHead() {
    return (nl.cwi.sen1.moduleapi.types.TableEntry)getFirst();
  }

  public TableEntryTable getTail() {
    return (TableEntryTable) getNext();
  }

  public aterm.ATermList getEmpty() {
    return getModuleapiFactory().makeTableEntryTable();
  }

  public TableEntryTable insert(nl.cwi.sen1.moduleapi.types.TableEntry head) {
    return getModuleapiFactory().makeTableEntryTable(head, this);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail, aterm.ATermList annos) {
    return getModuleapiFactory().makeTableEntryTable(head, tail, annos);
  }

  public aterm.ATermList make(aterm.ATerm head, aterm.ATermList tail) {
    return make(head, tail, getModuleapiFactory().getPureFactory().getEmpty());
  }

  public aterm.ATermList insert(aterm.ATerm head) {
    return make(head, this);
  }

  public TableEntryTable reverseTableEntryTable() {
    return getModuleapiFactory().reverse(this);
  }

  public aterm.ATermList reverse() {
    return reverseTableEntryTable();
  }

  public TableEntryTable concat(TableEntryTable peer) {
    return getModuleapiFactory().concat(this, peer);
  }

  public aterm.ATermList concat(aterm.ATermList peer) {
    return concat((TableEntryTable) peer);
  }

  public TableEntryTable append(nl.cwi.sen1.moduleapi.types.TableEntry elem) {
    return getModuleapiFactory().append(this, elem);
  }

  public aterm.ATermList append(aterm.ATerm elem) {
    return append((nl.cwi.sen1.moduleapi.types.TableEntry) elem);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry getTableEntryAt(int index) {
    return (nl.cwi.sen1.moduleapi.types.TableEntry) elementAt(index);
  }

  public nl.cwi.sen1.moduleapi.AbstractList accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_TableEntryTable(this);
  }

}
