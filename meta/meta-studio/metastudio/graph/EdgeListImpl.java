package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class EdgeListImpl extends MetaGraphConstructor
{
  EdgeListImpl(MetaGraphFactory factory) {
     super(factory);
  }
  public boolean isEqual(EdgeList peer)
  {
    return term.isEqual(peer.toTerm());
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
     throw new RuntimeException("This EdgeList has no Head");
  }

  public EdgeList setHead(Edge _head)
  {
     throw new RuntimeException("This EdgeList has no Head");
  }

  public EdgeList getTail()
  {
     throw new RuntimeException("This EdgeList has no Tail");
  }

  public EdgeList setTail(EdgeList _tail)
  {
     throw new RuntimeException("This EdgeList has no Tail");
  }

}

