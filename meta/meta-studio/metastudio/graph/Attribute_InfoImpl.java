package metastudio.graph;
import aterm.*;

abstract public class Attribute_InfoImpl
extends Attribute
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_key = 0;
  private static int index_value = 1;
  public shared.SharedObject duplicate() {
    Attribute_Info clone = new Attribute_Info();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttribute_Info(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("info(<str>,<term>)");
  }

  static public Attribute fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Attribute tmp = getStaticMetaGraphFactory().makeAttribute_Info((String) children.get(0), (aterm.ATerm) children.get(1));
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
      args.add((aterm.ATerm) getArgument(1));
      setTerm(getFactory().make(getPattern(), args));
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
