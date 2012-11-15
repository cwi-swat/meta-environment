package nl.cwi.sen1.ioapi.types;

abstract public class Path extends nl.cwi.sen1.ioapi.AbstractType {
  public Path(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Path peer) {
    return super.isEqual(peer);
  }

  public boolean isSortPath()  {
    return true;
  }

  public boolean isAbsolute() {
    return false;
  }

  public boolean isRelative() {
    return false;
  }

  public boolean hasList() {
    return false;
  }

  public nl.cwi.sen1.ioapi.types.SegmentList getList() {
     throw new UnsupportedOperationException("This Path has no List");
  }

  public Path setList(nl.cwi.sen1.ioapi.types.SegmentList _list) {
     throw new IllegalArgumentException("Illegal argument: " + _list);
  }

}

