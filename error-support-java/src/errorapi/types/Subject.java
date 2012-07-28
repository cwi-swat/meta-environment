package errorapi.types;

abstract public class Subject extends errorapi.AbstractType {
  public Subject(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Subject peer) {
    return super.isEqual(peer);
  }

  public boolean isSortSubject()  {
    return true;
  }

  public boolean isSubject() {
    return false;
  }

  public boolean isLocalized() {
    return false;
  }

  public boolean hasDescription() {
    return false;
  }

  public boolean hasLocation() {
    return false;
  }

  public String getDescription() {
     throw new UnsupportedOperationException("This Subject has no Description");
  }

  public Subject setDescription(String _description) {
     throw new IllegalArgumentException("Illegal argument: " + _description);
  }

  public errorapi.types.Location getLocation() {
     throw new UnsupportedOperationException("This Subject has no Location");
  }

  public Subject setLocation(errorapi.types.Location _Location) {
     throw new IllegalArgumentException("Illegal argument: " + _Location);
  }

}

