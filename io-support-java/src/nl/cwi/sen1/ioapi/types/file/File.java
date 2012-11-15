package nl.cwi.sen1.ioapi.types.file;

public class File extends nl.cwi.sen1.ioapi.types.File implements jjtraveler.Visitable {
  public File(nl.cwi.sen1.ioapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_path = 0;
  private static int index_name = 1;
  private static int index_extension = 2;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof File) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getIoapiFactory().makeFile_File(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getIoapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isFile()
  {
    return true;
  }

  public boolean hasPath() {
    return true;
  }

  public boolean hasName() {
    return true;
  }

  public boolean hasExtension() {
    return true;
  }

  public nl.cwi.sen1.ioapi.types.Path getPath() {
    return (nl.cwi.sen1.ioapi.types.Path) getArgument(index_path);
  }

  public nl.cwi.sen1.ioapi.types.File setPath(nl.cwi.sen1.ioapi.types.Path _path) {
    return (nl.cwi.sen1.ioapi.types.File) super.setArgument(_path, index_path);
  }

  public String getName() {
   return ((aterm.ATermAppl) getArgument(index_name)).getAFun().getName();
  }

  public nl.cwi.sen1.ioapi.types.File setName(String _name) {
    return (nl.cwi.sen1.ioapi.types.File) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_name, 0, true)), index_name);
  }

  public String getExtension() {
   return ((aterm.ATermAppl) getArgument(index_extension)).getAFun().getName();
  }

  public nl.cwi.sen1.ioapi.types.File setExtension(String _extension) {
    return (nl.cwi.sen1.ioapi.types.File) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_extension, 0, true)), index_extension);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ioapi.types.Path)) { 
          throw new RuntimeException("Argument 0 of a File should have type Path");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 1 of a File should have type str");
        }
        break;
      case 2:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 2 of a File should have type str");
        }
        break;
      default: throw new RuntimeException("File does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  public nl.cwi.sen1.ioapi.AbstractType accept(nl.cwi.sen1.ioapi.Visitor v) throws jjtraveler.VisitFailure {
    return v.visit_File_File(this);
  }

}
