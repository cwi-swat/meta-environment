package nl.cwi.sen1.graph.types;

abstract public class File extends nl.cwi.sen1.graph.AbstractType {
  public File(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(File peer) {
    return super.isEqual(peer);
  }

  public boolean isSortFile()  {
    return true;
  }

  public boolean isExternal() {
    return false;
  }

  public boolean hasFile() {
    return false;
  }

  public aterm.ATerm getFile() {
     throw new UnsupportedOperationException("This File has no File");
  }

  public File setFile(aterm.ATerm _file) {
     throw new IllegalArgumentException("Illegal argument: " + _file);
  }

}

