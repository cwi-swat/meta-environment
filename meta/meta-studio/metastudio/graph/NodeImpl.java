package metastudio.graph;

import aterm.*;

abstract public class NodeImpl extends MetaGraphConstructor
{
  protected NodeImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Node peer)
  {
    return super.isEqual(peer);
  }
  public boolean isSortNode()  {
    return true;
  }

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasId()
  {
    return false;
  }

  public boolean hasAttributes()
  {
    return false;
  }

  public NodeId getId()
  {
     throw new UnsupportedOperationException("This Node has no Id");
  }

  public Node setId(NodeId _id)
  {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

  public AttributeList getAttributes()
  {
     throw new UnsupportedOperationException("This Node has no Attributes");
  }

  public Node setAttributes(AttributeList _attributes)
  {
     throw new IllegalArgumentException("Illegal argument: " + _attributes);
  }

}

