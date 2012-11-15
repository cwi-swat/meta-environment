package nl.cwi.sen1.graph.types.attribute;

public class Info extends nl.cwi.sen1.graph.types.Attribute {
  public Info(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_key = 0;
  private static int index_value = 1;
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
    return getGraphFactory().makeAttribute_Info(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isInfo()
  {
    return true;
  }

  public boolean hasKey() {
    return true;
  }

  public boolean hasValue() {
    return true;
  }

  public String getKey() {
   return ((aterm.ATermAppl) getArgument(index_key)).getAFun().getName();
  }

  public nl.cwi.sen1.graph.types.Attribute setKey(String _key) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_key, 0, true)), index_key);
  }

  public aterm.ATerm getValue() {
   return getArgument(index_value);
  }

  public nl.cwi.sen1.graph.types.Attribute setValue(aterm.ATerm _value) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(_value, index_value);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Info should have type str");
        }
        break;
      case 1:
        // arg 1 is always of type aterm.ATerm
        break;
      default: throw new RuntimeException("Info does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
