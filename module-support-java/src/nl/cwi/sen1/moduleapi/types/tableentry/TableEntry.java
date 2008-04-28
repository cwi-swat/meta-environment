package nl.cwi.sen1.moduleapi.types.tableentry;

public class TableEntry extends nl.cwi.sen1.moduleapi.types.TableEntry implements jjtraveler.Visitable {
  public TableEntry(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_key = 0;
  private static int index_value = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof TableEntry) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getModuleapiFactory().makeTableEntry_TableEntry(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getModuleapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isTableEntry()
  {
    return true;
  }

  public boolean hasKey() {
    return true;
  }

  public boolean hasValue() {
    return true;
  }

  public aterm.ATerm getKey() {
   return getArgument(index_key);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry setKey(aterm.ATerm _key) {
    return (nl.cwi.sen1.moduleapi.types.TableEntry) super.setArgument(_key, index_key);
  }

  public aterm.ATerm getValue() {
   return getArgument(index_value);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntry setValue(aterm.ATerm _value) {
    return (nl.cwi.sen1.moduleapi.types.TableEntry) super.setArgument(_value, index_value);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        // arg 0 is always of type aterm.ATerm
        break;
      case 1:
        // arg 1 is always of type aterm.ATerm
        break;
      default: throw new RuntimeException("TableEntry does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  public nl.cwi.sen1.moduleapi.AbstractType accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_TableEntry_TableEntry(this);
  }

}
