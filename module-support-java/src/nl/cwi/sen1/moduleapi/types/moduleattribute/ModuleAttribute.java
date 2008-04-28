package nl.cwi.sen1.moduleapi.types.moduleattribute;

public class ModuleAttribute extends nl.cwi.sen1.moduleapi.types.ModuleAttribute implements jjtraveler.Visitable {
  public ModuleAttribute(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_id = 0;
  private static int index_attribute = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ModuleAttribute) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getModuleapiFactory().makeModuleAttribute_ModuleAttribute(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getModuleapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isModuleAttribute()
  {
    return true;
  }

  public boolean hasId() {
    return true;
  }

  public boolean hasAttribute() {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getId() {
    return (nl.cwi.sen1.moduleapi.types.ModuleId) getArgument(index_id);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute setId(nl.cwi.sen1.moduleapi.types.ModuleId _id) {
    return (nl.cwi.sen1.moduleapi.types.ModuleAttribute) super.setArgument(_id, index_id);
  }

  public aterm.ATerm getAttribute() {
   return getArgument(index_attribute);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleAttribute setAttribute(aterm.ATerm _attribute) {
    return (nl.cwi.sen1.moduleapi.types.ModuleAttribute) super.setArgument(_attribute, index_attribute);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.moduleapi.types.ModuleId)) { 
          throw new RuntimeException("Argument 0 of a ModuleAttribute should have type ModuleId");
        }
        break;
      case 1:
        // arg 1 is always of type aterm.ATerm
        break;
      default: throw new RuntimeException("ModuleAttribute does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  public nl.cwi.sen1.moduleapi.AbstractType accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_ModuleAttribute_ModuleAttribute(this);
  }

}
