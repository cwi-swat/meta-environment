package metastudio.graph;

import aterm.*;

public class EdgeList
{
  private ATermList list;

  //{{{ public EdgeList(ATerm term)

  public EdgeList(ATerm term)
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
  //{{{ public Edge getHead()

  public Edge getHead()
  {
    return new Edge(list.getFirst());
  }

  //}}}
  //{{{ public EdgeList getTail()

  public EdgeList getTail()
  {
    return new EdgeList(list.getNext());
  }

  //}}}
}
