package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class AttributeImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Attribute fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Attribute fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Attribute)

  public boolean isEqual(Attribute peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Attribute fromTerm(aterm.ATerm trm)
  {
    Attribute tmp;
    if ((tmp = Attribute_Label.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Attribute_Shape.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Attribute_Location.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Attribute_Size.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Attribute_CurvePoints.fromTerm(trm)) != null) {
      return tmp;
    }

    if ((tmp = Attribute_Direction.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Attribute: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

  public boolean isLabel()
  {
    return false;
  }

  public boolean isShape()
  {
    return false;
  }

  public boolean isLocation()
  {
    return false;
  }

  public boolean isSize()
  {
    return false;
  }

  public boolean isCurvePoints()
  {
    return false;
  }

  public boolean isDirection()
  {
    return false;
  }

  public boolean hasLabel()
  {
    return false;
  }

  public boolean hasShape()
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

  public boolean hasWidth()
  {
    return false;
  }

  public boolean hasHeight()
  {
    return false;
  }

  public boolean hasPoints()
  {
    return false;
  }

  public boolean hasDirection()
  {
    return false;
  }

  //}}}
  //{{{ default getters and setters

  public String getLabel()
  {
     throw new RuntimeException("This Attribute has no Label");
  }

  public Attribute setLabel(String _label)
  {
     throw new RuntimeException("This Attribute has no Label");
  }

  public Shape getShape()
  {
     throw new RuntimeException("This Attribute has no Shape");
  }

  public Attribute setShape(Shape _shape)
  {
     throw new RuntimeException("This Attribute has no Shape");
  }

  public Integer getX()
  {
     throw new RuntimeException("This Attribute has no X");
  }

  public Attribute setX(Integer _x)
  {
     throw new RuntimeException("This Attribute has no X");
  }

  public Integer getY()
  {
     throw new RuntimeException("This Attribute has no Y");
  }

  public Attribute setY(Integer _y)
  {
     throw new RuntimeException("This Attribute has no Y");
  }

  public Integer getWidth()
  {
     throw new RuntimeException("This Attribute has no Width");
  }

  public Attribute setWidth(Integer _width)
  {
     throw new RuntimeException("This Attribute has no Width");
  }

  public Integer getHeight()
  {
     throw new RuntimeException("This Attribute has no Height");
  }

  public Attribute setHeight(Integer _height)
  {
     throw new RuntimeException("This Attribute has no Height");
  }

  public Polygon getPoints()
  {
     throw new RuntimeException("This Attribute has no Points");
  }

  public Attribute setPoints(Polygon _points)
  {
     throw new RuntimeException("This Attribute has no Points");
  }

  public Direction getDirection()
  {
     throw new RuntimeException("This Attribute has no Direction");
  }

  public Attribute setDirection(Direction _direction)
  {
     throw new RuntimeException("This Attribute has no Direction");
  }

  //}}}

}

