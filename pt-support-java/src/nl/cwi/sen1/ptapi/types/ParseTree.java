package nl.cwi.sen1.ptapi.types;

abstract public class ParseTree extends nl.cwi.sen1.ptapi.AbstractType {
  public ParseTree(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(ParseTree peer) {
    return super.isEqual(peer);
  }

  public boolean isSortParseTree()  {
    return true;
  }

  public boolean isTop() {
    return false;
  }

  public boolean hasTop() {
    return false;
  }

  public boolean hasAmbCnt() {
    return false;
  }

  public nl.cwi.sen1.ptapi.types.Tree getTop() {
     throw new UnsupportedOperationException("This ParseTree has no Top");
  }

  public ParseTree setTop(nl.cwi.sen1.ptapi.types.Tree _top) {
     throw new IllegalArgumentException("Illegal argument: " + _top);
  }

  public int getAmbCnt() {
     throw new UnsupportedOperationException("This ParseTree has no AmbCnt");
  }

  public ParseTree setAmbCnt(int _ambCnt) {
     throw new IllegalArgumentException("Illegal argument: " + _ambCnt);
  }

}

