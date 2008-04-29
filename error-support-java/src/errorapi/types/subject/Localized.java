package errorapi.types.subject;

public class Localized extends errorapi.types.Subject {
  public Localized(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_description = 0;
  private static int index_Location = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Localized) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getErrorapiFactory().makeSubject_Localized(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getErrorapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLocalized()
  {
    return true;
  }

  public boolean hasDescription() {
    return true;
  }

  public boolean hasLocation() {
    return true;
  }

  public String getDescription() {
   return ((aterm.ATermAppl) getArgument(index_description)).getAFun().getName();
  }

  public errorapi.types.Subject setDescription(String _description) {
    return (errorapi.types.Subject) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_description, 0, true)), index_description);
  }

  public errorapi.types.Location getLocation() {
    return (errorapi.types.Location) getArgument(index_Location);
  }

  public errorapi.types.Subject setLocation(errorapi.types.Location _Location) {
    return (errorapi.types.Subject) super.setArgument(_Location, index_Location);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Localized should have type str");
        }
        break;
      case 1:
        if (!(arg instanceof errorapi.types.Location)) { 
          throw new RuntimeException("Argument 1 of a Localized should have type Location");
        }
        break;
      default: throw new RuntimeException("Localized does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
