package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class AttributeListImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static AttributeList fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static AttributeList fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(AttributeList)

  public boolean isEqual(AttributeList peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static AttributeList fromTerm(aterm.ATerm trm)
  {
    AttributeList tmp;
    if ((tmp = AttributeList_Empty.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = AttributeList_Multi.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a AttributeList: " + trm);
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

  //}}}

}

