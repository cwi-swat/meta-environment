package locationapi.types;

abstract public class Location extends locationapi.AbstractType {
  public Location(locationapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Location peer) {
    return super.isEqual(peer);
  }

  public boolean isSortLocation()  {
    return true;
  }

  public boolean isFile() {
    return false;
  }

  public boolean isArea() {
    return false;
  }

  public boolean isAreaInFile() {
    return false;
  }

  public boolean hasFilename() {
    return false;
  }

  public boolean hasArea() {
    return false;
  }

  public String getFilename() {
     throw new UnsupportedOperationException("This Location has no Filename");
  }

  public Location setFilename(String _filename) {
     throw new IllegalArgumentException("Illegal argument: " + _filename);
  }

  public locationapi.types.Area getArea() {
     throw new UnsupportedOperationException("This Location has no Area");
  }

  public Location setArea(locationapi.types.Area _Area) {
     throw new IllegalArgumentException("Illegal argument: " + _Area);
  }

}

