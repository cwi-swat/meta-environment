package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class DirectionImpl extends MetaGraphConstructor
{
  DirectionImpl(MetaGraphFactory factory) {
     super(factory);
  }
  public boolean isEqual(Direction peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortDirection()  {
    return true;
  }

  public boolean isForward()
  {
    return false;
  }

  public boolean isBack()
  {
    return false;
  }

  public boolean isBoth()
  {
    return false;
  }

  public boolean isNone()
  {
    return false;
  }

}

