package metastudio.data.graph;


abstract public class GraphImpl extends MetaGraphConstructor
{
  protected GraphImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Graph peer)
  {
    return super.isEqual(peer);
  }
  public boolean isSortGraph()  {
    return true;
  }

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasNodes()
  {
    return false;
  }

  public boolean hasEdges()
  {
    return false;
  }

  public boolean hasAttributes()
  {
    return false;
  }

  public NodeList getNodes()
  {
     throw new UnsupportedOperationException("This Graph has no Nodes");
  }

  public Graph setNodes(NodeList _nodes)
  {
     throw new IllegalArgumentException("Illegal argument: " + _nodes);
  }

  public EdgeList getEdges()
  {
     throw new UnsupportedOperationException("This Graph has no Edges");
  }

  public Graph setEdges(EdgeList _edges)
  {
     throw new IllegalArgumentException("Illegal argument: " + _edges);
  }

  public AttributeList getAttributes()
  {
     throw new UnsupportedOperationException("This Graph has no Attributes");
  }

  public Graph setAttributes(AttributeList _attributes)
  {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

}

