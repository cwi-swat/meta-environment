package metastudio.graph;

import aterm.*;

public class Polygon
{
  private ATermList list;

  //{{{ public Polygon(ATerm term)

  public Polygon(ATerm term)
  {
    list = (ATermList)term;
  }

  //}}}

  //{{{ public boolean isEmpty()

  public boolean isEmpty()
  {
    return list.isEmpty();
  }

  //}}}
  //{{{ public boolean isMulti()

  public boolean isMulti()
  {
    return !list.isEmpty();
  }

  //}}}
  //{{{ public Point getHead()

  public Point getHead()
  {
    return new Point(list.getFirst());
  }

  //}}}
  //{{{ public Polygon getTail()

  public Polygon getTail()
  {
    return new Polygon(list.getNext());
  }

  //}}}
}
