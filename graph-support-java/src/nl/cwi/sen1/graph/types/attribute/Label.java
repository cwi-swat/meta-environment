package nl.cwi.sen1.graph.types.attribute;

public class Label extends nl.cwi.sen1.graph.types.Attribute {
  public Label(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_label = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Label) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Label(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLabel()
  {
    return true;
  }

  public boolean hasLabel() {
    return true;
  }

  public String getLabel() {
   return ((aterm.ATermAppl) getArgument(index_label)).getAFun().getName();
  }

  public nl.cwi.sen1.graph.types.Attribute setLabel(String _label) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_label, 0, true)), index_label);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Label should have type str");
        }
        break;
      default: throw new RuntimeException("Label does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
