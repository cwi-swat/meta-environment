package nl.cwi.sen1.ptapi.types.parsetree;

public class Top extends nl.cwi.sen1.ptapi.types.ParseTree {
  public Top(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_top = 0;
  private static int index_ambCnt = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Top) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getPtapiFactory().makeParseTree_Top(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getPtapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isTop()
  {
    return true;
  }

  public boolean hasTop() {
    return true;
  }

  public boolean hasAmbCnt() {
    return true;
  }

  public nl.cwi.sen1.ptapi.types.Tree getTop() {
    return (nl.cwi.sen1.ptapi.types.Tree) getArgument(index_top);
  }

  public nl.cwi.sen1.ptapi.types.ParseTree setTop(nl.cwi.sen1.ptapi.types.Tree _top) {
    return (nl.cwi.sen1.ptapi.types.ParseTree) super.setArgument(_top, index_top);
  }

  public int getAmbCnt() {
   return ((aterm.ATermInt) getArgument(index_ambCnt)).getInt();
  }

  public nl.cwi.sen1.ptapi.types.ParseTree setAmbCnt(int _ambCnt) {
    return (nl.cwi.sen1.ptapi.types.ParseTree) super.setArgument(getFactory().makeInt(_ambCnt), index_ambCnt);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.ptapi.types.Tree)) { 
          throw new RuntimeException("Argument 0 of a Top should have type Tree");
        }
        break;
      case 1:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 1 of a Top should have type int");
        }
        break;
      default: throw new RuntimeException("Top does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
