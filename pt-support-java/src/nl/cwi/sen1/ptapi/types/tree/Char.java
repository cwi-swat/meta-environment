package nl.cwi.sen1.ptapi.types.tree;

public class Char extends nl.cwi.sen1.ptapi.types.Tree {
  public Char(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_character = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Char) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeTree_Char(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isChar()
  {
    return true;
  }

  public boolean hasCharacter() {
    return true;
  }

  public int getCharacter() {
   return ((aterm.ATermInt) getArgument(index_character)).getInt();
  }

  public nl.cwi.sen1.ptapi.types.Tree setCharacter(int _character) {
    return (nl.cwi.sen1.ptapi.types.Tree) super.setArgument(getFactory().makeInt(_character), index_character);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Char should have type int");
        }
        break;
      default: throw new RuntimeException("Char does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
