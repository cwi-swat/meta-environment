package metastudio.graph;

abstract public class Attribute_LabelImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_label = 0;
  public shared.SharedObject duplicate() {
    Attribute_Label clone = new Attribute_Label();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Label(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("label(<str>)");
  }

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_Label((String) children.get(0));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public aterm.ATerm toTerm() {
    if(term == null) {
      java.util.List args = new java.util.LinkedList();
      args.add(((aterm.ATermAppl) getArgument(0)).getAFun().getName());
      setTerm(getFactory().make(getPattern(), args));
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
