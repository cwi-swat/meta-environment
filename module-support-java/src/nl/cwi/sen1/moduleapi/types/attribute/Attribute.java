package nl.cwi.sen1.moduleapi.types.attribute;

public class Attribute extends nl.cwi.sen1.moduleapi.types.Attribute implements jjtraveler.Visitable {
  public Attribute(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_namespace = 0;
  private static int index_table = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Attribute) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getModuleapiFactory().makeAttribute_Attribute(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getModuleapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isAttribute()
  {
    return true;
  }

  public boolean hasNamespace() {
    return true;
  }

  public boolean hasTable() {
    return true;
  }

  public aterm.ATerm getNamespace() {
   return getArgument(index_namespace);
  }

  public nl.cwi.sen1.moduleapi.types.Attribute setNamespace(aterm.ATerm _namespace) {
    return (nl.cwi.sen1.moduleapi.types.Attribute) super.setArgument(_namespace, index_namespace);
  }

  public nl.cwi.sen1.moduleapi.types.TableEntryTable getTable() {
    return (nl.cwi.sen1.moduleapi.types.TableEntryTable) getArgument(index_table);
  }

  public nl.cwi.sen1.moduleapi.types.Attribute setTable(nl.cwi.sen1.moduleapi.types.TableEntryTable _table) {
    return (nl.cwi.sen1.moduleapi.types.Attribute) super.setArgument(_table, index_table);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        // arg 0 is always of type aterm.ATerm
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.moduleapi.types.TableEntryTable)) { 
          throw new RuntimeException("Argument 1 of a Attribute should have type TableEntry-table");
        }
        break;
      default: throw new RuntimeException("Attribute does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  public nl.cwi.sen1.moduleapi.AbstractType accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_Attribute_Attribute(this);
  }

}
