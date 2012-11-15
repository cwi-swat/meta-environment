package nl.cwi.sen1.graph.types.file;

public class External extends nl.cwi.sen1.graph.types.File {
  public External(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_file = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof External) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeFile_External(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isExternal()
  {
    return true;
  }

  public boolean hasFile() {
    return true;
  }

  public aterm.ATerm getFile() {
   return getArgument(index_file);
  }

  public nl.cwi.sen1.graph.types.File setFile(aterm.ATerm _file) {
    return (nl.cwi.sen1.graph.types.File) super.setArgument(_file, index_file);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        // arg 0 is always of type aterm.ATerm
        break;
      default: throw new RuntimeException("External does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
