package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class AttributeListImpl extends MetaGraphConstructor
{
  AttributeListImpl(MetaGraphFactory factory) {
     super(factory);
  }
  public boolean isEqual(AttributeList peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortAttributeList()  {
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

  public Attribute getHead()
  {
     throw new RuntimeException("This AttributeList has no Head");
  }

  public AttributeList setHead(Attribute _head)
  {
     throw new RuntimeException("This AttributeList has no Head");
  }

  public AttributeList getTail()
  {
     throw new RuntimeException("This AttributeList has no Tail");
  }

  public AttributeList setTail(AttributeList _tail)
  {
     throw new RuntimeException("This AttributeList has no Tail");
  }

}

