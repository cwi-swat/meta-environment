package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class PointImpl extends MetaGraphConstructor
{
  public static Point fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  public static Point fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  public boolean isEqual(Point peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public static Point fromTerm(aterm.ATerm trm)
  {
    Point tmp;
    if ((tmp = Point_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Point: " + trm);
  }

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


}

