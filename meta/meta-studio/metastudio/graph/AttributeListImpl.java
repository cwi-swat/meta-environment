package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class AttributeListImpl extends MetaGraphConstructor
{
  AttributeListImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
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

