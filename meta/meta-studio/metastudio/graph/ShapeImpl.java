package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class ShapeImpl extends MetaGraphConstructor
{
  ShapeImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Shape peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortShape()  {
    return true;
  }

  public boolean isPlaintext()
  {
    return false;
  }

  public boolean isEllipse()
  {
    return false;
  }

  public boolean isCircle()
  {
    return false;
  }

  public boolean isEgg()
  {
    return false;
  }

  public boolean isTriangle()
  {
    return false;
  }

  public boolean isBox()
  {
    return false;
  }

  public boolean isDiamond()
  {
    return false;
  }

  public boolean isTrapezium()
  {
    return false;
  }

  public boolean isParallelogram()
  {
    return false;
  }

  public boolean isHouse()
  {
    return false;
  }

  public boolean isHexagon()
  {
    return false;
  }

  public boolean isOctagon()
  {
    return false;
  }

}

