package nl.cwi.sen1.graph.types.attribute;

public class Tooltip extends nl.cwi.sen1.graph.types.Attribute {
  public Tooltip(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_tooltip = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Tooltip) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Tooltip(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isTooltip()
  {
    return true;
  }

  public boolean hasTooltip() {
    return true;
  }

  public String getTooltip() {
   return ((aterm.ATermAppl) getArgument(index_tooltip)).getAFun().getName();
  }

  public nl.cwi.sen1.graph.types.Attribute setTooltip(String _tooltip) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_tooltip, 0, true)), index_tooltip);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Tooltip should have type str");
        }
        break;
      default: throw new RuntimeException("Tooltip does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
