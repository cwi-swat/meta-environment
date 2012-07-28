package nl.cwi.sen1.ptapi.types.tree;

public class Cycle extends nl.cwi.sen1.ptapi.types.Tree {
  public Cycle(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_symbol = 0;
  private static int index_cycleLength = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Cycle) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeTree_Cycle(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isCycle()
  {
    return true;
  }

  public boolean hasSymbol() {
    return true;
  }

  public boolean hasCycleLength() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSymbol() {
    return (nl.cwi.sen1.ptapi.types.Symbol) getArgument(index_symbol);
  }

  public nl.cwi.sen1.ptapi.types.Tree setSymbol(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
    return (nl.cwi.sen1.ptapi.types.Tree) super.setArgument(_symbol, index_symbol);
  }

  public int getCycleLength() {
   return ((aterm.ATermInt) getArgument(index_cycleLength)).getInt();
  }

  public nl.cwi.sen1.ptapi.types.Tree setCycleLength(int _cycleLength) {
    return (nl.cwi.sen1.ptapi.types.Tree) super.setArgument(getFactory().makeInt(_cycleLength), index_cycleLength);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Symbol)) { 
          throw new RuntimeException("Argument 0 of a Cycle should have type Symbol");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Cycle should have type int");
        }
        break;
      default: throw new RuntimeException("Cycle does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
