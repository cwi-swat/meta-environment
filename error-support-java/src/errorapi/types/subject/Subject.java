package errorapi.types.subject;

public class Subject extends errorapi.types.Subject {
  public Subject(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_description = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Subject) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getErrorapiFactory().makeSubject_Subject(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getErrorapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSubject()
  {
    return true;
  }

  public boolean hasDescription() {
    return true;
  }

  public String getDescription() {
   return ((aterm.ATermAppl) getArgument(index_description)).getAFun().getName();
  }

  public errorapi.types.Subject setDescription(String _description) {
    return (errorapi.types.Subject) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_description, 0, true)), index_description);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Subject should have type str");
        }
        break;
      default: throw new RuntimeException("Subject does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
