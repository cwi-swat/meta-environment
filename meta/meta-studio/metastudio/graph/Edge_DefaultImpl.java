package metastudio.graph;

abstract public class Edge_DefaultImpl
extends Edge
{
  Edge_DefaultImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_from = 0;
  private static int index_to = 1;
  private static int index_attributes = 2;
  public shared.SharedObject duplicate() {
    Edge_Default clone = new Edge_Default(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Edge_Default) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeEdge_Default(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDefault()
  {
    return true;
  }

  public boolean hasFrom()
  {
    return true;
  }

  public boolean hasTo()
  {
    return true;
  }

  public boolean hasAttributes()
  {
    return true;
  }

  public NodeId getFrom()
  {
    return (NodeId) this.getArgument(index_from) ;
  }

  public Edge setFrom(NodeId _from)
  {
    return (Edge) super.setArgument(_from, index_from);
  }

  public NodeId getTo()
  {
    return (NodeId) this.getArgument(index_to) ;
  }

  public Edge setTo(NodeId _to)
  {
    return (Edge) super.setArgument(_to, index_to);
  }

  public AttributeList getAttributes()
  {
    return (AttributeList) this.getArgument(index_attributes) ;
  }

  public Edge setAttributes(AttributeList _attributes)
  {
    return (Edge) super.setArgument(_attributes, index_attributes);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof NodeId)) { 
          throw new RuntimeException("Argument 0 of a Edge_Default should have type NodeId");
        }
        break;
      case 1:
        if (! (arg instanceof NodeId)) { 
          throw new RuntimeException("Argument 1 of a Edge_Default should have type NodeId");
        }
        break;
      case 2:
        if (! (arg instanceof AttributeList)) { 
          throw new RuntimeException("Argument 2 of a Edge_Default should have type AttributeList");
        }
        break;
      default: throw new RuntimeException("Edge_Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(2).hashCode() << 16);
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
