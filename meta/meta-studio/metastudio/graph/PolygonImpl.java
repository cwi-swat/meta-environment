package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class PolygonImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Polygon fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Polygon fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Polygon)

  public boolean isEqual(Polygon peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Polygon fromTerm(aterm.ATerm trm)
  {
    Polygon tmp;
    if ((tmp = Polygon_Empty.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Polygon_Multi.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Polygon: " + trm);
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

  public Point getHead()
  {
     throw new RuntimeException("This Polygon has no Head");
  }

  public Polygon setHead(Point _head)
  {
     throw new RuntimeException("This Polygon has no Head");
  }

  public Polygon getTail()
  {
     throw new RuntimeException("This Polygon has no Tail");
  }

  public Polygon setTail(Polygon _tail)
  {
     throw new RuntimeException("This Polygon has no Tail");
  }

  //}}}

}

