package metastudio;

import metastudio.graph.Shape;
import metastudio.graph.Node;

public abstract class NodeSizer
{
  //{{{ public Node sizeNode(Node node)

  public Node sizeNode(Node node)
  {
      double factor = shapeFactor(GraphWrapper.getNodeShape(node));
      int width = (int) (((double) getWidth(node)) * factor);
      int height = (int) (((double) getHeight(node)) * factor);

      return node.setSize(width, height);
  }

  //}}}
  
  public double shapeFactor(Shape shape) {
      if (shape.isBox()) {
          return 1;
      }
      else if (shape.isDiamond()) {
          return 1.5;
      }
      else if (shape.isEllipse()) {
          return 1.2;
      }
      else {
          return 1;
      }
  }
  

  abstract public int getWidth(Node node);
  abstract public int getHeight(Node node);
}
