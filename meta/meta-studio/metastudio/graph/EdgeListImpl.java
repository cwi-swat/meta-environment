package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class EdgeListImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static EdgeList fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static EdgeList fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(EdgeList)

  public boolean isEqual(EdgeList peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static EdgeList fromTerm(aterm.ATerm trm)
  {
    EdgeList tmp;
    if ((tmp = EdgeList_Empty.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = EdgeList_Multi.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a EdgeList: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

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

  //}}}
  //{{{ default getters and setters

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

  //}}}

}

