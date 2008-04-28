package nl.cwi.sen1.configapi.types;

abstract public class ActionDescription extends nl.cwi.sen1.configapi.AbstractType {
  public ActionDescription(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(ActionDescription peer) {
    return super.isEqual(peer);
  }

  public boolean isSortActionDescription()  {
    return true;
  }

  public boolean isDescription() {
    return false;
  }

  public boolean hasContext() {
    return false;
  }

  public boolean hasEvent() {
    return false;
  }

  public aterm.ATerm getContext() {
     throw new UnsupportedOperationException("This ActionDescription has no Context");
  }

  public ActionDescription setContext(aterm.ATerm _context) {
     throw new IllegalArgumentException("Illegal argument: " + _context);
  }

  public nl.cwi.sen1.configapi.types.Event getEvent() {
     throw new UnsupportedOperationException("This ActionDescription has no Event");
  }

  public ActionDescription setEvent(nl.cwi.sen1.configapi.types.Event _event) {
     throw new IllegalArgumentException("Illegal argument: " + _event);
  }

}

