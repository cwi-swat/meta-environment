package nl.cwi.sen1.ptapi.types.charrange;

public class Character extends nl.cwi.sen1.ptapi.types.CharRange {
  public Character(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_start = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Character) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeCharRange_Character(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isCharacter()
  {
    return true;
  }

  public boolean hasStart() {
    return true;
  }

  public int getStart() {
   return ((aterm.ATermInt) getArgument(index_start)).getInt();
  }

  public nl.cwi.sen1.ptapi.types.CharRange setStart(int _start) {
    return (nl.cwi.sen1.ptapi.types.CharRange) super.setArgument(getFactory().makeInt(_start), index_start);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Character should have type int");
        }
        break;
      default: throw new RuntimeException("Character does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
