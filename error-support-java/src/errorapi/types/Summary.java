package errorapi.types;

abstract public class Summary extends errorapi.AbstractType {
  public Summary(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Summary peer) {
    return super.isEqual(peer);
  }

  public boolean isSortSummary()  {
    return true;
  }

  public boolean isSummary() {
    return false;
  }

  public boolean hasProducer() {
    return false;
  }

  public boolean hasId() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public String getProducer() {
     throw new UnsupportedOperationException("This Summary has no Producer");
  }

  public Summary setProducer(String _producer) {
     throw new IllegalArgumentException("Illegal argument: " + _producer);
  }

  public String getId() {
     throw new UnsupportedOperationException("This Summary has no Id");
  }

  public Summary setId(String _id) {
     throw new IllegalArgumentException("Illegal argument: " + _id);
  }

  public errorapi.types.ErrorList getList() {
     throw new UnsupportedOperationException("This Summary has no List");
  }

  public Summary setList(errorapi.types.ErrorList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

