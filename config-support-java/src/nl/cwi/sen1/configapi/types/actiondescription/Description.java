package nl.cwi.sen1.configapi.types.actiondescription;

public class Description extends nl.cwi.sen1.configapi.types.ActionDescription {
  public Description(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_context = 0;
  private static int index_event = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Description) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeActionDescription_Description(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDescription()
  {
    return true;
  }

  public boolean hasContext() {
    return true;
  }

  public boolean hasEvent() {
    return true;
  }

  public aterm.ATerm getContext() {
   return getArgument(index_context);
  }

  public nl.cwi.sen1.configapi.types.ActionDescription setContext(aterm.ATerm _context) {
    return (nl.cwi.sen1.configapi.types.ActionDescription) super.setArgument(_context, index_context);
  }

  public nl.cwi.sen1.configapi.types.Event getEvent() {
    return (nl.cwi.sen1.configapi.types.Event) getArgument(index_event);
  }

  public nl.cwi.sen1.configapi.types.ActionDescription setEvent(nl.cwi.sen1.configapi.types.Event _event) {
    return (nl.cwi.sen1.configapi.types.ActionDescription) super.setArgument(_event, index_event);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        // arg 0 is always of type aterm.ATerm
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.Event)) { 
          throw new RuntimeException("Argument 1 of a Description should have type Event");
        }
        break;
      default: throw new RuntimeException("Description does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
