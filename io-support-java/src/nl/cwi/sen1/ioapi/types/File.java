package nl.cwi.sen1.ioapi.types;

abstract public class File extends nl.cwi.sen1.ioapi.AbstractType {
  public File(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(File peer) {
    return super.isEqual(peer);
  }

  public boolean isSortFile()  {
    return true;
  }

  public boolean isFile() {
    return false;
  }

  public boolean hasPath() {
    return false;
  }

  public boolean hasName() {
    return false;
  }

  public boolean hasExtension() {
    return false;
  }

  public nl.cwi.sen1.ioapi.types.Path getPath() {
     throw new UnsupportedOperationException("This File has no Path");
  }

  public File setPath(nl.cwi.sen1.ioapi.types.Path _path) {
     throw new IllegalArgumentException("Illegal argument: " + _path);
  }

  public String getName() {
     throw new UnsupportedOperationException("This File has no Name");
  }

  public File setName(String _name) {
     throw new IllegalArgumentException("Illegal argument: " + _name);
  }

  public String getExtension() {
     throw new UnsupportedOperationException("This File has no Extension");
  }

  public File setExtension(String _extension) {
     throw new IllegalArgumentException("Illegal argument: " + _extension);
  }

}

