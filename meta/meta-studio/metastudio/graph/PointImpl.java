package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class PointImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Point fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Point fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Point)

  public boolean isEqual(Point peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Point fromTerm(aterm.ATerm trm)
  {
    Point tmp;
    if ((tmp = Point_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Point: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasX()
  {
    return false;
  }

  public boolean hasY()
  {
    return false;
  }

  //}}}
  //{{{ default getters and setters

  public Integer getX()
  {
     throw new RuntimeException("This Point has no X");
  }

  public Point setX(Integer _x)
  {
     throw new RuntimeException("This Point has no X");
  }

  public Integer getY()
  {
     throw new RuntimeException("This Point has no Y");
  }

  public Point setY(Integer _y)
  {
     throw new RuntimeException("This Point has no Y");
  }

  //}}}

}

