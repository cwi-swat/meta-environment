package nl.cwi.sen1.ptapi.types;

abstract public class CharRange extends nl.cwi.sen1.ptapi.AbstractType {
  public CharRange(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(CharRange peer) {
    return super.isEqual(peer);
  }

  public boolean isSortCharRange()  {
    return true;
  }

  public boolean isCharacter() {
    return false;
  }

  public boolean isRange() {
    return false;
  }

  public boolean hasStart() {
    return false;
  }

  public boolean hasEnd() {
    return false;
  }

  public int getStart() {
     throw new UnsupportedOperationException("This CharRange has no Start");
  }

  public CharRange setStart(int _start) {
     throw new IllegalArgumentException("Illegal argument: " + _start);
  }

  public int getEnd() {
     throw new UnsupportedOperationException("This CharRange has no End");
  }

  public CharRange setEnd(int _end) {
     throw new IllegalArgumentException("Illegal argument: " + _end);
  }

}

