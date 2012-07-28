package nl.cwi.sen1.ptapi.types.attr;

public class Term extends nl.cwi.sen1.ptapi.types.Attr {
  public Term(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_value = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Term) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeAttr_Term(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isTerm()
  {
    return true;
  }

  public boolean hasValue() {
    return true;
  }

  public aterm.ATerm getValue() {
   return getArgument(index_value);
  }

  public nl.cwi.sen1.ptapi.types.Attr setValue(aterm.ATerm _value) {
    return (nl.cwi.sen1.ptapi.types.Attr) super.setArgument(_value, index_value);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        // arg 0 is always of type aterm.ATerm
        break;
      default: throw new RuntimeException("Term does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
