package metastudio.graph;

import java.io.InputStream;
import java.io.IOException;

abstract public class NodeListImpl extends MetaGraphConstructor
{
  static NodeList fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  static NodeList fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  public boolean isEqual(NodeList peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public static NodeList fromTerm(aterm.ATerm trm)
  {
    NodeList tmp;
    if ((tmp = NodeList_Empty.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = NodeList_Multi.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a NodeList: " + trm);
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

