package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class PointImpl extends MetaGraphConstructor
{
  PointImpl(MetaGraphFactory factory) {
     super(factory);
  }
  public boolean isEqual(Point peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortPoint()  {
    return true;
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

