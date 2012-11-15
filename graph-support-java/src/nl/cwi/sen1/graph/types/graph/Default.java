package nl.cwi.sen1.graph.types.graph;

public class Default extends nl.cwi.sen1.graph.types.Graph {
  public Default(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_nodes = 0;
  private static int index_edges = 1;
  private static int index_attributes = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Default) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeGraph_Default(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDefault()
  {
    return true;
  }

  public boolean hasNodes() {
    return true;
  }

  public boolean hasEdges() {
    return true;
  }

  public boolean hasAttributes() {
    return true;
  }

  public nl.cwi.sen1.graph.types.NodeList getNodes() {
    return (nl.cwi.sen1.graph.types.NodeList) getArgument(index_nodes);
  }

  public nl.cwi.sen1.graph.types.Graph setNodes(nl.cwi.sen1.graph.types.NodeList _nodes) {
    return (nl.cwi.sen1.graph.types.Graph) super.setArgument(_nodes, index_nodes);
  }

  public nl.cwi.sen1.graph.types.EdgeList getEdges() {
    return (nl.cwi.sen1.graph.types.EdgeList) getArgument(index_edges);
  }

  public nl.cwi.sen1.graph.types.Graph setEdges(nl.cwi.sen1.graph.types.EdgeList _edges) {
    return (nl.cwi.sen1.graph.types.Graph) super.setArgument(_edges, index_edges);
  }

  public nl.cwi.sen1.graph.types.AttributeList getAttributes() {
    return (nl.cwi.sen1.graph.types.AttributeList) getArgument(index_attributes);
  }

  public nl.cwi.sen1.graph.types.Graph setAttributes(nl.cwi.sen1.graph.types.AttributeList _attributes) {
    return (nl.cwi.sen1.graph.types.Graph) super.setArgument(_attributes, index_attributes);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.graph.types.NodeList)) { 
          throw new RuntimeException("Argument 0 of a Default should have type NodeList");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.graph.types.EdgeList)) { 
          throw new RuntimeException("Argument 1 of a Default should have type EdgeList");
        }
        break;
      case 2:
        if (!(arg instanceof nl.cwi.sen1.graph.types.AttributeList)) { 
          throw new RuntimeException("Argument 2 of a Default should have type AttributeList");
        }
        break;
      default: throw new RuntimeException("Default does not have an argument at " + i );
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
