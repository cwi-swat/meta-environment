package metastudio.graph;

abstract public class Graph_DefaultImpl
extends Graph
{
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  Graph_DefaultImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_nodes = 0;
  private static int index_edges = 1;
  private static int index_attributes = 2;
  public shared.SharedObject duplicate() {
    Graph_Default clone = new Graph_Default(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Graph_Default) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeGraph_Default(fun, i_args, annos);
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

  public boolean hasNodes()
  {
    return true;
  }

  public boolean hasEdges()
  {
    return true;
  }

  public boolean hasAttributes()
  {
    return true;
  }

  public NodeList getNodes()
  {
    return (NodeList) this.getArgument(index_nodes) ;
  }

  public Graph setNodes(NodeList _nodes)
  {
    return (Graph) super.setArgument(_nodes, index_nodes);
  }

  public EdgeList getEdges()
  {
    return (EdgeList) this.getArgument(index_edges) ;
  }

  public Graph setEdges(EdgeList _edges)
  {
    return (Graph) super.setArgument(_edges, index_edges);
  }

  public AttributeList getAttributes()
  {
    return (AttributeList) this.getArgument(index_attributes) ;
  }

  public Graph setAttributes(AttributeList _attributes)
  {
    return (Graph) super.setArgument(_attributes, index_attributes);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof NodeList)) { 
          throw new RuntimeException("Argument 0 of a Graph_Default should have type NodeList");
        }
        break;
      case 1:
        if (! (arg instanceof EdgeList)) { 
          throw new RuntimeException("Argument 1 of a Graph_Default should have type EdgeList");
        }
        break;
      case 2:
        if (! (arg instanceof AttributeList)) { 
          throw new RuntimeException("Argument 2 of a Graph_Default should have type AttributeList");
        }
        break;
      default: throw new RuntimeException("Graph_Default does not have an argument at " + i );
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
