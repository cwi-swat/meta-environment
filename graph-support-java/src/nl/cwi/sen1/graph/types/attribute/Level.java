package nl.cwi.sen1.graph.types.attribute;

public class Level extends nl.cwi.sen1.graph.types.Attribute {
  public Level(nl.cwi.sen1.graph.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_level = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Level) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getGraphFactory().makeAttribute_Level(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getGraphFactory().toTerm(this);
    }
    return term;
  }

  public boolean isLevel()
  {
    return true;
  }

  public boolean hasLevel() {
    return true;
  }

  public String getLevel() {
   return ((aterm.ATermAppl) getArgument(index_level)).getAFun().getName();
  }

  public nl.cwi.sen1.graph.types.Attribute setLevel(String _level) {
    return (nl.cwi.sen1.graph.types.Attribute) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_level, 0, true)), index_level);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a Level should have type str");
        }
        break;
      default: throw new RuntimeException("Level does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
