package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class DirectionImpl extends MetaGraphConstructor
{
  protected DirectionImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
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

