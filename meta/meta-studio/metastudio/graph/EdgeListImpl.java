package metastudio.graph;

import aterm.*;

abstract public class EdgeListImpl extends MetaGraphConstructor
{
  protected EdgeListImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(EdgeList peer)
  {
    return super.isEqual(peer);
  }
  public boolean isSortEdgeList()  {
    return true;
  }

  public boolean isEmpty()
  {
    return false;
  }

  public boolean isMulti()
  {
    return false;
  }

  public boolean hasHead()
  {
    return false;
  }

  public boolean hasTail()
  {
    return false;
  }

  public Edge getHead()
  {
     throw new UnsupportedOperationException("This EdgeList has no Head");
  }

  public EdgeList setHead(Edge _head)
  {
     throw new IllegalArgumentException("Illegal argument: " + _head);
  }

  public EdgeList getTail()
  {
     throw new UnsupportedOperationException("This EdgeList has no Tail");
  }

  public EdgeList setTail(EdgeList _tail)
  {
     throw new IllegalArgumentException("Illegal argument: " + _tail);
  }

}

