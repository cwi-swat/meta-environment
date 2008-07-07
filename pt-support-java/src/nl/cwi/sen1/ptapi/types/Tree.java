package nl.cwi.sen1.ptapi.types;

abstract public class Tree extends nl.cwi.sen1.ptapi.AbstractType {
  public Tree(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Tree peer) {
    return super.isEqual(peer);
  }

  public boolean isSortTree()  {
    return true;
  }

  public boolean isAppl() {
    return false;
  }

  public boolean isCycle() {
    return false;
  }

  public boolean isAmb() {
    return false;
  }

  public boolean isChar() {
    return false;
  }

  public boolean hasProd() {
    return false;
  }

  public boolean hasArgs() {
    return false;
  }

  public boolean hasSymbol() {
    return false;
  }

  public boolean hasCycleLength() {
    return false;
  }

  public boolean hasCharacter() {
    return false;
  }

  public nl.cwi.sen1.ptapi.types.Production getProd() {
     throw new UnsupportedOperationException("This Tree has no Prod");
  }

  public Tree setProd(nl.cwi.sen1.ptapi.types.Production _prod) {
     throw new IllegalArgumentException("Illegal argument: " + _prod);
  }

  public nl.cwi.sen1.ptapi.types.Args getArgs() {
     throw new UnsupportedOperationException("This Tree has no Args");
  }

  public Tree setArgs(nl.cwi.sen1.ptapi.types.Args _args) {
     throw new IllegalArgumentException("Illegal argument: " + _args);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSymbol() {
     throw new UnsupportedOperationException("This Tree has no Symbol");
  }

  public Tree setSymbol(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
     throw new IllegalArgumentException("Illegal argument: " + _symbol);
  }

  public int getCycleLength() {
     throw new UnsupportedOperationException("This Tree has no CycleLength");
  }

  public Tree setCycleLength(int _cycleLength) {
     throw new IllegalArgumentException("Illegal argument: " + _cycleLength);
  }

  public int getCharacter() {
     throw new UnsupportedOperationException("This Tree has no Character");
  }

  public Tree setCharacter(int _character) {
     throw new IllegalArgumentException("Illegal argument: " + _character);
  }

}

