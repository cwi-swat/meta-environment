package metastudio.graph;

import aterm.*;

public class NodeList
{
  private ATermList list;

  //{{{ public NodeList(ATerm term)

  public NodeList(ATerm term)
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
  //{{{ public Node getHead()

  public Node getHead()
  {
    return new Node(list.getFirst());
  }

  //}}}
  //{{{ public NodeList getTail()

  public NodeList getTail()
  {
    return new NodeList(list.getNext());
  }

  //}}}
}
