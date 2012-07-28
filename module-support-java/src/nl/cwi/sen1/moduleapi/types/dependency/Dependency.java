package nl.cwi.sen1.moduleapi.types.dependency;

public class Dependency extends nl.cwi.sen1.moduleapi.types.Dependency implements jjtraveler.Visitable {
  public Dependency(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_from = 0;
  private static int index_list = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Dependency) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getModuleapiFactory().makeDependency_Dependency(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getModuleapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDependency()
  {
    return true;
  }

  public boolean hasFrom() {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public nl.cwi.sen1.moduleapi.types.ModuleId getFrom() {
    return (nl.cwi.sen1.moduleapi.types.ModuleId) getArgument(index_from);
  }

  public nl.cwi.sen1.moduleapi.types.Dependency setFrom(nl.cwi.sen1.moduleapi.types.ModuleId _from) {
    return (nl.cwi.sen1.moduleapi.types.Dependency) super.setArgument(_from, index_from);
  }

  public nl.cwi.sen1.moduleapi.types.ModuleIdList getList() {
    return (nl.cwi.sen1.moduleapi.types.ModuleIdList) getArgument(index_list);
  }

  public nl.cwi.sen1.moduleapi.types.Dependency setList(nl.cwi.sen1.moduleapi.types.ModuleIdList _list) {
    return (nl.cwi.sen1.moduleapi.types.Dependency) super.setArgument(_list, index_list);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.moduleapi.types.ModuleId)) { 
          throw new RuntimeException("Argument 0 of a Dependency should have type ModuleId");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.moduleapi.types.ModuleIdList)) { 
          throw new RuntimeException("Argument 1 of a Dependency should have type ModuleId-list");
        }
        break;
      default: throw new RuntimeException("Dependency does not have an argument at " + i );
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
    return v.visit_Dependency_Dependency(this);
  }

}
