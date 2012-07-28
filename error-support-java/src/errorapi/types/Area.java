package errorapi.types;

abstract public class Area extends errorapi.AbstractType {
  public Area(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Area peer) {
    return super.isEqual(peer);
  }

  public boolean isSortArea()  {
    return true;
  }

  public boolean isArea() {
    return false;
  }

  public boolean hasBeginLine() {
    return false;
  }

  public boolean hasBeginColumn() {
    return false;
  }

  public boolean hasEndLine() {
    return false;
  }

  public boolean hasEndColumn() {
    return false;
  }

  public boolean hasOffset() {
    return false;
  }

  public boolean hasLength() {
    return false;
  }

  public int getBeginLine() {
     throw new UnsupportedOperationException("This Area has no BeginLine");
  }

  public Area setBeginLine(int _beginLine) {
     throw new IllegalArgumentException("Illegal argument: " + _beginLine);
  }

  public int getBeginColumn() {
     throw new UnsupportedOperationException("This Area has no BeginColumn");
  }

  public Area setBeginColumn(int _beginColumn) {
     throw new IllegalArgumentException("Illegal argument: " + _beginColumn);
  }

  public int getEndLine() {
     throw new UnsupportedOperationException("This Area has no EndLine");
  }

  public Area setEndLine(int _endLine) {
     throw new IllegalArgumentException("Illegal argument: " + _endLine);
  }

  public int getEndColumn() {
     throw new UnsupportedOperationException("This Area has no EndColumn");
  }

  public Area setEndColumn(int _endColumn) {
     throw new IllegalArgumentException("Illegal argument: " + _endColumn);
  }

  public int getOffset() {
     throw new UnsupportedOperationException("This Area has no Offset");
  }

  public Area setOffset(int _offset) {
     throw new IllegalArgumentException("Illegal argument: " + _offset);
  }

  public int getLength() {
     throw new UnsupportedOperationException("This Area has no Length");
  }

  public Area setLength(int _length) {
     throw new IllegalArgumentException("Illegal argument: " + _length);
  }

}

