package nl.cwi.sen1.ioapi.types;

abstract public class Segment extends nl.cwi.sen1.ioapi.AbstractType {
  public Segment(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Segment peer) {
    return super.isEqual(peer);
  }

  public boolean isSortSegment()  {
    return true;
  }

  public boolean isSegment() {
    return false;
  }

  public boolean hasName() {
    return false;
  }

  public String getName() {
     throw new UnsupportedOperationException("This Segment has no Name");
  }

  public Segment setName(String _name) {
     throw new IllegalArgumentException("Illegal argument: " + _name);
  }

}

