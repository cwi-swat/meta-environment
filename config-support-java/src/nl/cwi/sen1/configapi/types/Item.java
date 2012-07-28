package nl.cwi.sen1.configapi.types;

abstract public class Item extends nl.cwi.sen1.configapi.AbstractType {
  public Item(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Item peer) {
    return super.isEqual(peer);
  }

  public boolean isSortItem()  {
    return true;
  }

  public boolean isLabel() {
    return false;
  }

  public boolean hasName() {
    return false;
  }

  public String getName() {
     throw new UnsupportedOperationException("This Item has no Name");
  }

  public Item setName(String _name) {
     throw new IllegalArgumentException("Illegal argument: " + _name);
  }

}

