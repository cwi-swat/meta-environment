package metastudio.data.graph;


abstract public class EdgeImpl extends MetaGraphConstructor
{
  protected EdgeImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Edge peer)
  {
    return super.isEqual(peer);
  }
  public boolean isSortEdge()  {
    return true;
  }

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasFrom()
  {
    return false;
  }

  public boolean hasTo()
  {
    return false;
  }

  public boolean hasAttributes()
  {
    return false;
  }

  public NodeId getFrom()
  {
     throw new UnsupportedOperationException("This Edge has no From");
  }

  public Edge setFrom(NodeId _from)
  {
     throw new IllegalArgumentException("Illegal argument: " + _from);
  }

  public NodeId getTo()
  {
     throw new UnsupportedOperationException("This Edge has no To");
  }

  public Edge setTo(NodeId _to)
  {
     throw new IllegalArgumentException("Illegal argument: " + _to);
  }

  public AttributeList getAttributes()
  {
     throw new UnsupportedOperationException("This Edge has no Attributes");
  }

  public Edge setAttributes(AttributeList _attributes)
  {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

}

