package metastudio.graph;

abstract public class Attribute_InfoImpl
extends Attribute
{
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  protected Attribute_InfoImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_key = 0;
  private static int index_value = 1;
  public shared.SharedObject duplicate() {
    Attribute_Info clone = new Attribute_Info(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Attribute_Info) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Info(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isInfo()
  {
    return true;
  }

  public boolean hasKey()
  {
    return true;
  }

  public boolean hasValue()
  {
    return true;
  }

  public String getKey()
  {
   return ((aterm.ATermAppl) this.getArgument(index_key)).getAFun().getName();
  }

  public Attribute setKey(String _key)
  {
    return (Attribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_key, 0, true)), index_key);
  }

  public aterm.ATerm getValue()
  {
   return this.getArgument(index_value);
  }

  public Attribute setValue(aterm.ATerm _value)
  {
    return (Attribute) super.setArgument(_value, index_value);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Attribute_Info should have type str");
        }
        break;
      case 1:
        if (! (arg instanceof aterm.ATerm)) { 
          throw new RuntimeException("Argument 1 of a Attribute_Info should have type term");
        }
        break;
      default: throw new RuntimeException("Attribute_Info does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
}
