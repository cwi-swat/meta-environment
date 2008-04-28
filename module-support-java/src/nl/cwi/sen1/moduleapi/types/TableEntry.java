package nl.cwi.sen1.moduleapi.types;

abstract public class TableEntry extends nl.cwi.sen1.moduleapi.AbstractType {
  public TableEntry(nl.cwi.sen1.moduleapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(TableEntry peer) {
    return super.isEqual(peer);
  }

  public boolean isSortTableEntry()  {
    return true;
  }

  public boolean isTableEntry() {
    return false;
  }

  public boolean hasKey() {
    return false;
  }

  public boolean hasValue() {
    return false;
  }

  public aterm.ATerm getKey() {
     throw new UnsupportedOperationException("This TableEntry has no Key");
  }

  public TableEntry setKey(aterm.ATerm _key) {
     throw new IllegalArgumentException("Illegal argument: " + _key);
  }

  public aterm.ATerm getValue() {
     throw new UnsupportedOperationException("This TableEntry has no Value");
  }

  public TableEntry setValue(aterm.ATerm _value) {
     throw new IllegalArgumentException("Illegal argument: " + _value);
  }

}

