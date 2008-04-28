package nl.cwi.sen1.moduleapi.types.moduleid;

public class ModuleId extends nl.cwi.sen1.moduleapi.types.ModuleId implements jjtraveler.Visitable {
  public ModuleId(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_id = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof ModuleId) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getModuleapiFactory().makeModuleId_ModuleId(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getModuleapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isModuleId()
  {
    return true;
  }

  public boolean hasId() {
    return true;
  }

  public int getId() {
   return ((aterm.ATermInt) getArgument(index_id)).getInt();
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId setId(int _id) {
    return (nl.cwi.sen1.moduleapi.types.ModuleId) super.setArgument(getFactory().makeInt(_id), index_id);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a ModuleId should have type int");
        }
        break;
      default: throw new RuntimeException("ModuleId does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  public nl.cwi.sen1.moduleapi.AbstractType accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_ModuleId_ModuleId(this);
  }

}
