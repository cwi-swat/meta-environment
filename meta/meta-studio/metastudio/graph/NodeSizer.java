package metastudio.graph;

public abstract class NodeSizer
{
  //{{{ public Node sizeNode(Node node)

  public Node sizeNode(Node node)
  {
    int width = getWidth(node);
    int height = getHeight(node);

    return node.setSize(width, height);
  }

  //}}}

  abstract public int getWidth(Node node);
  abstract public int getHeight(Node node);
}
