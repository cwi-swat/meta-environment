package nl.cwi.sen1.configapi.types;

abstract public class TextAttribute extends nl.cwi.sen1.configapi.AbstractType {
  public TextAttribute(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(TextAttribute peer) {
    return super.isEqual(peer);
  }

  public boolean isSortTextAttribute()  {
    return true;
  }

  public boolean isForegroundColor() {
    return false;
  }

  public boolean isBackgroundColor() {
    return false;
  }

  public boolean isStyle() {
    return false;
  }

  public boolean isFont() {
    return false;
  }

  public boolean isSize() {
    return false;
  }

  public boolean hasColor() {
    return false;
  }

  public boolean hasStyle() {
    return false;
  }

  public boolean hasName() {
    return false;
  }

  public boolean hasPoint() {
    return false;
  }

  public nl.cwi.sen1.configapi.types.Color getColor() {
     throw new UnsupportedOperationException("This TextAttribute has no Color");
  }

  public TextAttribute setColor(nl.cwi.sen1.configapi.types.Color _color) {
     throw new IllegalArgumentException("Illegal argument: " + _color);
  }

  public nl.cwi.sen1.configapi.types.TextStyle getStyle() {
     throw new UnsupportedOperationException("This TextAttribute has no Style");
  }

  public TextAttribute setStyle(nl.cwi.sen1.configapi.types.TextStyle _style) {
     throw new IllegalArgumentException("Illegal argument: " + _style);
  }

  public String getName() {
     throw new UnsupportedOperationException("This TextAttribute has no Name");
  }

  public TextAttribute setName(String _name) {
     throw new IllegalArgumentException("Illegal argument: " + _name);
  }

  public int getPoint() {
     throw new UnsupportedOperationException("This TextAttribute has no Point");
  }

  public TextAttribute setPoint(int _point) {
     throw new IllegalArgumentException("Illegal argument: " + _point);
  }

}

