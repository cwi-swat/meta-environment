package metastudio.graph;


abstract public class PointImpl extends MetaGraphConstructor
{
  protected PointImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Point peer)
  {
    return super.isEqual(peer);
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

  public int getX()
  {
     throw new UnsupportedOperationException("This Point has no X");
  }

  public Point setX(int _x)
  {
     throw new IllegalArgumentException("Illegal argument: " + _x);
  }

  public int getY()
  {
     throw new UnsupportedOperationException("This Point has no Y");
  }

  public Point setY(int _y)
  {
     throw new IllegalArgumentException("Illegal argument: " + _y);
  }

}

