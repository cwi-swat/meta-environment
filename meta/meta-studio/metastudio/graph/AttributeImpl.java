package metastudio.graph;

import aterm.*;

abstract public class AttributeImpl extends MetaGraphConstructor
{
  protected AttributeImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Attribute peer)
  {
    return super.isEqual(peer);
  }
  public boolean isSortAttribute()  {
    return true;
  }

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

  public boolean isBoundingBox()
  {
    return false;
  }

  public boolean isDirection()
  {
    return false;
  }

  public boolean isInfo()
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

  public boolean hasFirst()
  {
    return false;
  }

  public boolean hasSecond()
  {
    return false;
  }

  public boolean hasDirection()
  {
    return false;
  }

  public boolean hasKey()
  {
    return false;
  }

  public boolean hasValue()
  {
    return false;
  }

  public String getLabel()
  {
     throw new UnsupportedOperationException("This Attribute has no Label");
  }

  public Attribute setLabel(String _label)
  {
     throw new IllegalArgumentException("Illegal argument: " + _label);
  }

  public Shape getShape()
  {
     throw new UnsupportedOperationException("This Attribute has no Shape");
  }

  public Attribute setShape(Shape _shape)
  {
     throw new IllegalArgumentException("Illegal argument: " + _shape);
  }

  public int getX()
  {
     throw new UnsupportedOperationException("This Attribute has no X");
  }

  public Attribute setX(int _x)
  {
     throw new IllegalArgumentException("Illegal argument: " + _x);
  }

  public int getY()
  {
     throw new UnsupportedOperationException("This Attribute has no Y");
  }

  public Attribute setY(int _y)
  {
     throw new IllegalArgumentException("Illegal argument: " + _y);
  }

  public int getWidth()
  {
     throw new UnsupportedOperationException("This Attribute has no Width");
  }

  public Attribute setWidth(int _width)
  {
     throw new IllegalArgumentException("Illegal argument: " + _width);
  }

  public int getHeight()
  {
     throw new UnsupportedOperationException("This Attribute has no Height");
  }

  public Attribute setHeight(int _height)
  {
     throw new IllegalArgumentException("Illegal argument: " + _height);
  }

  public Polygon getPoints()
  {
     throw new UnsupportedOperationException("This Attribute has no Points");
  }

  public Attribute setPoints(Polygon _points)
  {
     throw new IllegalArgumentException("Illegal argument: " + _points);
  }

  public Point getFirst()
  {
     throw new UnsupportedOperationException("This Attribute has no First");
  }

  public Attribute setFirst(Point _first)
  {
     throw new IllegalArgumentException("Illegal argument: " + _first);
  }

  public Point getSecond()
  {
     throw new UnsupportedOperationException("This Attribute has no Second");
  }

  public Attribute setSecond(Point _second)
  {
     throw new IllegalArgumentException("Illegal argument: " + _second);
  }

  public Direction getDirection()
  {
     throw new UnsupportedOperationException("This Attribute has no Direction");
  }

  public Attribute setDirection(Direction _direction)
  {
     throw new IllegalArgumentException("Illegal argument: " + _direction);
  }

  public String getKey()
  {
     throw new UnsupportedOperationException("This Attribute has no Key");
  }

  public Attribute setKey(String _key)
  {
     throw new IllegalArgumentException("Illegal argument: " + _key);
  }

  public aterm.ATerm getValue()
  {
     throw new UnsupportedOperationException("This Attribute has no Value");
  }

  public Attribute setValue(aterm.ATerm _value)
  {
     throw new IllegalArgumentException("Illegal argument: " + _value);
  }

}

