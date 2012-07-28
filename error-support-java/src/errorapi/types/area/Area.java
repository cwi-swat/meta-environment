package errorapi.types.area;

public class Area extends errorapi.types.Area {
  public Area(errorapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_beginLine = 0;
  private static int index_beginColumn = 1;
  private static int index_endLine = 2;
  private static int index_endColumn = 3;
  private static int index_offset = 4;
  private static int index_length = 5;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Area) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getErrorapiFactory().makeArea_Area(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getErrorapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isArea()
  {
    return true;
  }

  public boolean hasBeginLine() {
    return true;
  }

  public boolean hasBeginColumn() {
    return true;
  }

  public boolean hasEndLine() {
    return true;
  }

  public boolean hasEndColumn() {
    return true;
  }

  public boolean hasOffset() {
    return true;
  }

  public boolean hasLength() {
    return true;
  }

  public int getBeginLine() {
   return ((aterm.ATermInt) getArgument(index_beginLine)).getInt();
  }

  public errorapi.types.Area setBeginLine(int _beginLine) {
    return (errorapi.types.Area) super.setArgument(getFactory().makeInt(_beginLine), index_beginLine);
  }

  public int getBeginColumn() {
   return ((aterm.ATermInt) getArgument(index_beginColumn)).getInt();
  }

  public errorapi.types.Area setBeginColumn(int _beginColumn) {
    return (errorapi.types.Area) super.setArgument(getFactory().makeInt(_beginColumn), index_beginColumn);
  }

  public int getEndLine() {
   return ((aterm.ATermInt) getArgument(index_endLine)).getInt();
  }

  public errorapi.types.Area setEndLine(int _endLine) {
    return (errorapi.types.Area) super.setArgument(getFactory().makeInt(_endLine), index_endLine);
  }

  public int getEndColumn() {
   return ((aterm.ATermInt) getArgument(index_endColumn)).getInt();
  }

  public errorapi.types.Area setEndColumn(int _endColumn) {
    return (errorapi.types.Area) super.setArgument(getFactory().makeInt(_endColumn), index_endColumn);
  }

  public int getOffset() {
   return ((aterm.ATermInt) getArgument(index_offset)).getInt();
  }

  public errorapi.types.Area setOffset(int _offset) {
    return (errorapi.types.Area) super.setArgument(getFactory().makeInt(_offset), index_offset);
  }

  public int getLength() {
   return ((aterm.ATermInt) getArgument(index_length)).getInt();
  }

  public errorapi.types.Area setLength(int _length) {
    return (errorapi.types.Area) super.setArgument(getFactory().makeInt(_length), index_length);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Area should have type int");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Area should have type int");
        }
        break;
      case 2:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 2 of a Area should have type int");
        }
        break;
      case 3:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 3 of a Area should have type int");
        }
        break;
      case 4:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 4 of a Area should have type int");
        }
        break;
      case 5:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 5 of a Area should have type int");
        }
        break;
      default: throw new RuntimeException("Area does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
