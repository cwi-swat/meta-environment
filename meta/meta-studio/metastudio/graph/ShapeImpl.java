package metastudio.graph;

import aterm.*;

abstract public class ShapeImpl extends MetaGraphConstructor
{
  protected ShapeImpl(MetaGraphFactory factory) {
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
    return super.isEqual(peer);
  }
  public boolean isSortShape()  {
    return true;
  }

  public boolean isBox()
  {
    return false;
  }

  public boolean isCircle()
  {
    return false;
  }

  public boolean isDiamond()
  {
    return false;
  }

  public boolean isEgg()
  {
    return false;
  }

  public boolean isEllipse()
  {
    return false;
  }

  public boolean isHexagon()
  {
    return false;
  }

  public boolean isHouse()
  {
    return false;
  }

  public boolean isOctagon()
  {
    return false;
  }

  public boolean isParallelogram()
  {
    return false;
  }

  public boolean isPlaintext()
  {
    return false;
  }

  public boolean isTrapezium()
  {
    return false;
  }

  public boolean isTriangle()
  {
    return false;
  }

}

