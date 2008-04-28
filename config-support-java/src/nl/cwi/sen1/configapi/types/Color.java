package nl.cwi.sen1.configapi.types;

abstract public class Color extends nl.cwi.sen1.configapi.AbstractType {
  public Color(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Color peer) {
    return super.isEqual(peer);
  }

  public boolean isSortColor()  {
    return true;
  }

  public boolean isRgb() {
    return false;
  }

  public boolean hasRed() {
    return false;
  }

  public boolean hasGreen() {
    return false;
  }

  public boolean hasBlue() {
    return false;
  }

  public int getRed() {
     throw new UnsupportedOperationException("This Color has no Red");
  }

  public Color setRed(int _red) {
     throw new IllegalArgumentException("Illegal argument: " + _red);
  }

  public int getGreen() {
     throw new UnsupportedOperationException("This Color has no Green");
  }

  public Color setGreen(int _green) {
     throw new IllegalArgumentException("Illegal argument: " + _green);
  }

  public int getBlue() {
     throw new UnsupportedOperationException("This Color has no Blue");
  }

  public Color setBlue(int _blue) {
     throw new IllegalArgumentException("Illegal argument: " + _blue);
  }

}

