package nl.cwi.sen1.configapi.types.property;

public class Action extends nl.cwi.sen1.configapi.types.Property {
  public Action(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_list = 0;
  private static int index_action = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Action) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeProperty_Action(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isAction()
  {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public boolean hasAction() {
    return true;
  }

  public nl.cwi.sen1.configapi.types.ActionDescriptionList getList() {
    return (nl.cwi.sen1.configapi.types.ActionDescriptionList) getArgument(index_list);
  }

  public nl.cwi.sen1.configapi.types.Property setList(nl.cwi.sen1.configapi.types.ActionDescriptionList _list) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(_list, index_list);
  }

  public String getAction() {
   return ((aterm.ATermAppl) getArgument(index_action)).getAFun().getName();
  }

  public nl.cwi.sen1.configapi.types.Property setAction(String _action) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_action, 0, true)), index_action);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.ActionDescriptionList)) { 
          throw new RuntimeException("Argument 0 of a Action should have type ActionDescription-list");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 1 of a Action should have type str");
        }
        break;
      default: throw new RuntimeException("Action does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
