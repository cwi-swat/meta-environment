package metastudio.graph;

abstract public class AttributeList_MultiImpl
extends AttributeList
{
  AttributeList_MultiImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_head = 0;
  private static int index_tail = 1;
  public shared.SharedObject duplicate() {
    AttributeList_Multi clone = new AttributeList_Multi(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof AttributeList_Multi) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeAttributeList_Multi(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isMulti()
  {
    return true;
  }

  public boolean hasHead()
  {
    return true;
  }

  public boolean hasTail()
  {
    return true;
  }

  public Attribute getHead()
  {
    return (Attribute) this.getArgument(index_head) ;
  }

  public AttributeList setHead(Attribute _head)
  {
    return (AttributeList) super.setArgument(_head, index_head);
  }

  public AttributeList getTail()
  {
    return (AttributeList) this.getArgument(index_tail) ;
  }

  public AttributeList setTail(AttributeList _tail)
  {
    return (AttributeList) super.setArgument(_tail, index_tail);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof Attribute)) { 
          throw new RuntimeException("Argument 0 of a AttributeList_Multi should have type Attribute");
        }
        break;
      case 1:
        if (! (arg instanceof AttributeList)) { 
          throw new RuntimeException("Argument 1 of a AttributeList_Multi should have type AttributeList");
        }
        break;
      default: throw new RuntimeException("AttributeList_Multi does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  protected int hashFunction() {
    int c = getArgument(1).hashCode() + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }
}
