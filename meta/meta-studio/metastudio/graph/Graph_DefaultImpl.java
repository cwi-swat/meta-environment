package metastudio.graph;

  //{{{ imports

  //}}}
public class Graph_DefaultImpl
extends Graph
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  //{{{ field indexes

  private static int index_nodes = 0;
  private static int index_edges = 1;
  //}}}
  public shared.SharedObject duplicate() {
    Graph_Default clone = new Graph_Default();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeGraph_Default(fun, i_args, annos);
  }
  //{{{ initializePattern()

  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("graph(<term>,<term>)");
  }

  //}}}
  //{{{ fromTerm(ATerm trm)

  static public Graph fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      Graph tmp = getStaticMetaGraphFactory().makeGraph_Default(NodeList.fromTerm( (aterm.ATerm) children.get(0)), EdgeList.fromTerm( (aterm.ATerm) children.get(1)));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  //}}}
  //{{{ isXXX and hasXXX properties

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

  //}}}
  //{{{ getters and setters

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
      default: throw new RuntimeException("Graph_Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
  //}}}
  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = 0x9e3779b9;
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
