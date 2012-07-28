package nl.cwi.sen1.moduleapi.types.module;

public class Module extends nl.cwi.sen1.moduleapi.types.Module implements jjtraveler.Visitable {
  public Module(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_id = 0;
  private static int index_store = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Module) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getModuleapiFactory().makeModule_Module(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getModuleapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isModule()
  {
    return true;
  }

  public boolean hasId() {
    return true;
  }

  public boolean hasStore() {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getId() {
    return (nl.cwi.sen1.moduleapi.types.ModuleId) getArgument(index_id);
  }

  public nl.cwi.sen1.moduleapi.types.Module setId(nl.cwi.sen1.moduleapi.types.ModuleId _id) {
    return (nl.cwi.sen1.moduleapi.types.Module) super.setArgument(_id, index_id);
  }

  public nl.cwi.sen1.moduleapi.types.AttributeStore getStore() {
    return (nl.cwi.sen1.moduleapi.types.AttributeStore) getArgument(index_store);
  }

  public nl.cwi.sen1.moduleapi.types.Module setStore(nl.cwi.sen1.moduleapi.types.AttributeStore _store) {
    return (nl.cwi.sen1.moduleapi.types.Module) super.setArgument(_store, index_store);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.moduleapi.types.ModuleId)) { 
          throw new RuntimeException("Argument 0 of a Module should have type ModuleId");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.moduleapi.types.AttributeStore)) { 
          throw new RuntimeException("Argument 1 of a Module should have type Attribute-store");
        }
        break;
      default: throw new RuntimeException("Module does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

  public nl.cwi.sen1.moduleapi.AbstractType accept(nl.cwi.sen1.moduleapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_Module_Module(this);
  }

}
