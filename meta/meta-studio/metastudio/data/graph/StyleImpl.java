package metastudio.data.graph;


abstract public class StyleImpl extends MetaGraphConstructor
{
  protected StyleImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Style peer)
  {
    return super.isEqual(peer);
  }
  public boolean isSortStyle()  {
    return true;
  }

  public boolean isBold()
  {
    return false;
  }

  public boolean isDashed()
  {
    return false;
  }

  public boolean isDotted()
  {
    return false;
  }

  public boolean isFilled()
  {
    return false;
  }

  public boolean isInvisible()
  {
    return false;
  }

  public boolean isSolid()
  {
    return false;
  }

}

