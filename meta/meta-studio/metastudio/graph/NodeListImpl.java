package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class NodeListImpl extends MetaGraphConstructor
{
  protected NodeListImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
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

