package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class NodeListImpl extends MetaGraphConstructor
{
  NodeListImpl(MetaGraphFactory factory) {
     super(factory);
  }
  public boolean isEqual(NodeList peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortNodeList()  {
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

  public Node getHead()
  {
     throw new RuntimeException("This NodeList has no Head");
  }

  public NodeList setHead(Node _head)
  {
     throw new RuntimeException("This NodeList has no Head");
  }

  public NodeList getTail()
  {
     throw new RuntimeException("This NodeList has no Tail");
  }

  public NodeList setTail(NodeList _tail)
  {
     throw new RuntimeException("This NodeList has no Tail");
  }

}

