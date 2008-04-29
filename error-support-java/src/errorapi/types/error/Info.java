package errorapi.types.error;

public class Info extends errorapi.types.Error {
  public Info(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_description = 0;
  private static int index_list = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Info) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getErrorapiFactory().makeError_Info(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getErrorapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isInfo()
  {
    return true;
  }

  public boolean hasDescription() {
    return true;
  }

  public boolean hasList() {
    return true;
  }

  public String getDescription() {
   return ((aterm.ATermAppl) getArgument(index_description)).getAFun().getName();
  }

  public errorapi.types.Error setDescription(String _description) {
    return (errorapi.types.Error) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_description, 0, true)), index_description);
  }

  public errorapi.types.SubjectList getList() {
    return (errorapi.types.SubjectList) getArgument(index_list);
  }

  public errorapi.types.Error setList(errorapi.types.SubjectList _list) {
    return (errorapi.types.Error) super.setArgument(_list, index_list);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Info should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof errorapi.types.SubjectList)) { 
          throw new RuntimeException("Argument 1 of a Info should have type Subject-list");
        }
        break;
      default: throw new RuntimeException("Info does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
