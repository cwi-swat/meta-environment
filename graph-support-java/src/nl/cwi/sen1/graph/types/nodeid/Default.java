package nl.cwi.sen1.graph.types.nodeid;

public class Default extends nl.cwi.sen1.graph.types.NodeId {
  public Default(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_id = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Default) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeNodeId_Default(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isDefault()
  {
    return true;
  }

  public boolean hasId() {
    return true;
  }

  public aterm.ATerm getId() {
   return getArgument(index_id);
  }

  public nl.cwi.sen1.graph.types.NodeId setId(aterm.ATerm _id) {
    return (nl.cwi.sen1.graph.types.NodeId) super.setArgument(_id, index_id);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        // arg 0 is always of type aterm.ATerm
        break;
      default: throw new RuntimeException("Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
