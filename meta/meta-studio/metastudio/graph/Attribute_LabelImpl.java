package metastudio.graph;

abstract public class Attribute_LabelImpl
extends Attribute
{
  Attribute_LabelImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_label = 0;
  public shared.SharedObject duplicate() {
    Attribute_Label clone = new Attribute_Label(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Attribute_Label) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Label(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLabel()
  {
    return true;
  }

  public boolean hasLabel()
  {
    return true;
  }

  public String getLabel()
  {
   return ((aterm.ATermAppl) this.getArgument(index_label)).getAFun().getName();
  }

  public Attribute setLabel(String _label)
  {
    return (Attribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_label, 0, true)), index_label);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Attribute_Label should have type str");
        }
        break;
      default: throw new RuntimeException("Attribute_Label does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
}
