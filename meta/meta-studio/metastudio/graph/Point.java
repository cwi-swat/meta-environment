package metastudio.graph;

import aterm.*;

public class Point
{
  private ATerm term;

  //{{{ public Point(ATerm term)

  public Point(ATerm term)
  {
    this.term = term;
  }

  //}}}

  //{{{ public int getX()

  public int getX()
  {
    return ((ATermInt)((ATermAppl)term).getArgument(0)).getInt();
  }

  //}}}
  //{{{ public int getY()

  public int getY()
  {
    return ((ATermInt)((ATermAppl)term).getArgument(1)).getInt();
  }

  //}}}
}
