package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class ShapeImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Shape fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Shape fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Shape)

  public boolean isEqual(Shape peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Shape fromTerm(aterm.ATerm trm)
  {
    Shape tmp;
    if ((tmp = Shape_Plaintext.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Ellipse.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Circle.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Egg.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Triangle.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Box.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Diamond.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Trapezium.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Parallelogram.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_House.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Hexagon.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Shape_Octagon.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Shape: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

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

  //}}}
  //{{{ default getters and setters

  //}}}

}

