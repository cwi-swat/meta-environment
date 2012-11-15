package nl.cwi.sen1.graph.types;

abstract public class Attribute extends nl.cwi.sen1.graph.AbstractType {
  public Attribute(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Attribute peer) {
    return super.isEqual(peer);
  }

  public boolean isSortAttribute()  {
    return true;
  }

  public boolean isBoundingBox() {
    return false;
  }

  public boolean isColor() {
    return false;
  }

  public boolean isCurvePoints() {
    return false;
  }

  public boolean isDirection() {
    return false;
  }

  public boolean isFillColor() {
    return false;
  }

  public boolean isInfo() {
    return false;
  }

  public boolean isLabel() {
    return false;
  }

  public boolean isTooltip() {
    return false;
  }

  public boolean isLocation() {
    return false;
  }

  public boolean isShape() {
    return false;
  }

  public boolean isSize() {
    return false;
  }

  public boolean isStyle() {
    return false;
  }

  public boolean isLevel() {
    return false;
  }

  public boolean isFile() {
    return false;
  }

  public boolean hasFirst() {
    return false;
  }

  public boolean hasSecond() {
    return false;
  }

  public boolean hasColor() {
    return false;
  }

  public boolean hasPoints() {
    return false;
  }

  public boolean hasDirection() {
    return false;
  }

  public boolean hasKey() {
    return false;
  }

  public boolean hasValue() {
    return false;
  }

  public boolean hasLabel() {
    return false;
  }

  public boolean hasTooltip() {
    return false;
  }

  public boolean hasX() {
    return false;
  }

  public boolean hasY() {
    return false;
  }

  public boolean hasShape() {
    return false;
  }

  public boolean hasWidth() {
    return false;
  }

  public boolean hasHeight() {
    return false;
  }

  public boolean hasStyle() {
    return false;
  }

  public boolean hasLevel() {
    return false;
  }

  public boolean hasFile() {
    return false;
  }

  public nl.cwi.sen1.graph.types.Point getFirst() {
     throw new UnsupportedOperationException("This Attribute has no First");
  }

  public Attribute setFirst(nl.cwi.sen1.graph.types.Point _first) {
     throw new IllegalArgumentException("Illegal argument: " + _first);
  }

  public nl.cwi.sen1.graph.types.Point getSecond() {
     throw new UnsupportedOperationException("This Attribute has no Second");
  }

  public Attribute setSecond(nl.cwi.sen1.graph.types.Point _second) {
     throw new IllegalArgumentException("Illegal argument: " + _second);
  }

  public nl.cwi.sen1.graph.types.Color getColor() {
     throw new UnsupportedOperationException("This Attribute has no Color");
  }

  public Attribute setColor(nl.cwi.sen1.graph.types.Color _color) {
     throw new IllegalArgumentException("Illegal argument: " + _color);
  }

  public nl.cwi.sen1.graph.types.Polygon getPoints() {
     throw new UnsupportedOperationException("This Attribute has no Points");
  }

  public Attribute setPoints(nl.cwi.sen1.graph.types.Polygon _points) {
     throw new IllegalArgumentException("Illegal argument: " + _points);
  }

  public nl.cwi.sen1.graph.types.Direction getDirection() {
     throw new UnsupportedOperationException("This Attribute has no Direction");
  }

  public Attribute setDirection(nl.cwi.sen1.graph.types.Direction _direction) {
     throw new IllegalArgumentException("Illegal argument: " + _direction);
  }

  public String getKey() {
     throw new UnsupportedOperationException("This Attribute has no Key");
  }

  public Attribute setKey(String _key) {
     throw new IllegalArgumentException("Illegal argument: " + _key);
  }

  public aterm.ATerm getValue() {
     throw new UnsupportedOperationException("This Attribute has no Value");
  }

  public Attribute setValue(aterm.ATerm _value) {
     throw new IllegalArgumentException("Illegal argument: " + _value);
  }

  public String getLabel() {
     throw new UnsupportedOperationException("This Attribute has no Label");
  }

  public Attribute setLabel(String _label) {
     throw new IllegalArgumentException("Illegal argument: " + _label);
  }

  public String getTooltip() {
     throw new UnsupportedOperationException("This Attribute has no Tooltip");
  }

  public Attribute setTooltip(String _tooltip) {
     throw new IllegalArgumentException("Illegal argument: " + _tooltip);
  }

  public int getX() {
     throw new UnsupportedOperationException("This Attribute has no X");
  }

  public Attribute setX(int _x) {
     throw new IllegalArgumentException("Illegal argument: " + _x);
  }

  public int getY() {
     throw new UnsupportedOperationException("This Attribute has no Y");
  }

  public Attribute setY(int _y) {
     throw new IllegalArgumentException("Illegal argument: " + _y);
  }

  public nl.cwi.sen1.graph.types.Shape getShape() {
     throw new UnsupportedOperationException("This Attribute has no Shape");
  }

  public Attribute setShape(nl.cwi.sen1.graph.types.Shape _shape) {
     throw new IllegalArgumentException("Illegal argument: " + _shape);
  }

  public int getWidth() {
     throw new UnsupportedOperationException("This Attribute has no Width");
  }

  public Attribute setWidth(int _width) {
     throw new IllegalArgumentException("Illegal argument: " + _width);
  }

  public int getHeight() {
     throw new UnsupportedOperationException("This Attribute has no Height");
  }

  public Attribute setHeight(int _height) {
     throw new IllegalArgumentException("Illegal argument: " + _height);
  }

  public nl.cwi.sen1.graph.types.Style getStyle() {
     throw new UnsupportedOperationException("This Attribute has no Style");
  }

  public Attribute setStyle(nl.cwi.sen1.graph.types.Style _style) {
     throw new IllegalArgumentException("Illegal argument: " + _style);
  }

  public String getLevel() {
     throw new UnsupportedOperationException("This Attribute has no Level");
  }

  public Attribute setLevel(String _level) {
     throw new IllegalArgumentException("Illegal argument: " + _level);
  }

  public nl.cwi.sen1.graph.types.File getFile() {
     throw new UnsupportedOperationException("This Attribute has no File");
  }

  public Attribute setFile(nl.cwi.sen1.graph.types.File _file) {
     throw new IllegalArgumentException("Illegal argument: " + _file);
  }

}

