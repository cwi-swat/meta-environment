package errorapi.types;

abstract public class Error extends errorapi.AbstractType {
  public Error(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Error peer) {
    return super.isEqual(peer);
  }

  public boolean isSortError()  {
    return true;
  }

  public boolean isInfo() {
    return false;
  }

  public boolean isWarning() {
    return false;
  }

  public boolean isError() {
    return false;
  }

  public boolean isFatal() {
    return false;
  }

  public boolean hasDescription() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public String getDescription() {
     throw new UnsupportedOperationException("This Error has no Description");
  }

  public Error setDescription(String _description) {
     throw new IllegalArgumentException("Illegal argument: " + _description);
  }

  public errorapi.types.SubjectList getList() {
     throw new UnsupportedOperationException("This Error has no List");
  }

  public Error setList(errorapi.types.SubjectList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

