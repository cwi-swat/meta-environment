package nl.cwi.sen1.ptapi.types;

abstract public class Symbol extends nl.cwi.sen1.ptapi.AbstractType {
  public Symbol(nl.cwi.sen1.ptapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(Symbol peer) {
    return super.isEqual(peer);
  }

  public boolean isSortSymbol()  {
    return true;
  }

  public boolean isLit() {
    return false;
  }

  public boolean isCilit() {
    return false;
  }

  public boolean isCf() {
    return false;
  }

  public boolean isLex() {
    return false;
  }

  public boolean isEmpty() {
    return false;
  }

  public boolean isSeq() {
    return false;
  }

  public boolean isOpt() {
    return false;
  }

  public boolean isAlt() {
    return false;
  }

  public boolean isTuple() {
    return false;
  }

  public boolean isSort() {
    return false;
  }

  public boolean isIterPlus() {
    return false;
  }

  public boolean isIterStar() {
    return false;
  }

  public boolean isIterPlusSep() {
    return false;
  }

  public boolean isIterStarSep() {
    return false;
  }

  public boolean isIterN() {
    return false;
  }

  public boolean isIterSepN() {
    return false;
  }

  public boolean isFunc() {
    return false;
  }

  public boolean isParameterizedSort() {
    return false;
  }

  public boolean isStrategy() {
    return false;
  }

  public boolean isVarSym() {
    return false;
  }

  public boolean isLayout() {
    return false;
  }

  public boolean isCharClass() {
    return false;
  }

  public boolean hasString() {
    return false;
  }

  public boolean hasSymbol() {
    return false;
  }

  public boolean hasSymbols() {
    return false;
  }

  public boolean hasLhs() {
    return false;
  }

  public boolean hasRhs() {
    return false;
  }

  public boolean hasHead() {
    return false;
  }

  public boolean hasRest() {
    return false;
  }

  public boolean hasSeparator() {
    return false;
  }

  public boolean hasNumber() {
    return false;
  }

  public boolean hasSort() {
    return false;
  }

  public boolean hasParameters() {
    return false;
  }

  public boolean hasRanges() {
    return false;
  }

  public String getString() {
     throw new UnsupportedOperationException("This Symbol has no String");
  }

  public Symbol setString(String _string) {
     throw new IllegalArgumentException("Illegal argument: " + _string);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSymbol() {
     throw new UnsupportedOperationException("This Symbol has no Symbol");
  }

  public Symbol setSymbol(nl.cwi.sen1.ptapi.types.Symbol _symbol) {
     throw new IllegalArgumentException("Illegal argument: " + _symbol);
  }

  public nl.cwi.sen1.ptapi.types.Symbols getSymbols() {
     throw new UnsupportedOperationException("This Symbol has no Symbols");
  }

  public Symbol setSymbols(nl.cwi.sen1.ptapi.types.Symbols _symbols) {
     throw new IllegalArgumentException("Illegal argument: " + _symbols);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getLhs() {
     throw new UnsupportedOperationException("This Symbol has no Lhs");
  }

  public Symbol setLhs(nl.cwi.sen1.ptapi.types.Symbol _lhs) {
     throw new IllegalArgumentException("Illegal argument: " + _lhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getRhs() {
     throw new UnsupportedOperationException("This Symbol has no Rhs");
  }

  public Symbol setRhs(nl.cwi.sen1.ptapi.types.Symbol _rhs) {
     throw new IllegalArgumentException("Illegal argument: " + _rhs);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getHead() {
     throw new UnsupportedOperationException("This Symbol has no Head");
  }

  public Symbol setHead(nl.cwi.sen1.ptapi.types.Symbol _head) {
     throw new IllegalArgumentException("Illegal argument: " + _head);
  }

  public nl.cwi.sen1.ptapi.types.Symbols getRest() {
     throw new UnsupportedOperationException("This Symbol has no Rest");
  }

  public Symbol setRest(nl.cwi.sen1.ptapi.types.Symbols _rest) {
     throw new IllegalArgumentException("Illegal argument: " + _rest);
  }

  public nl.cwi.sen1.ptapi.types.Symbol getSeparator() {
     throw new UnsupportedOperationException("This Symbol has no Separator");
  }

  public Symbol setSeparator(nl.cwi.sen1.ptapi.types.Symbol _separator) {
     throw new IllegalArgumentException("Illegal argument: " + _separator);
  }

  public int getNumber() {
     throw new UnsupportedOperationException("This Symbol has no Number");
  }

  public Symbol setNumber(int _number) {
     throw new IllegalArgumentException("Illegal argument: " + _number);
  }

  public String getSort() {
     throw new UnsupportedOperationException("This Symbol has no Sort");
  }

  public Symbol setSort(String _sort) {
     throw new IllegalArgumentException("Illegal argument: " + _sort);
  }

  public nl.cwi.sen1.ptapi.types.Symbols getParameters() {
     throw new UnsupportedOperationException("This Symbol has no Parameters");
  }

  public Symbol setParameters(nl.cwi.sen1.ptapi.types.Symbols _parameters) {
     throw new IllegalArgumentException("Illegal argument: " + _parameters);
  }

  public nl.cwi.sen1.ptapi.types.CharRanges getRanges() {
     throw new UnsupportedOperationException("This Symbol has no Ranges");
  }

  public Symbol setRanges(nl.cwi.sen1.ptapi.types.CharRanges _ranges) {
     throw new IllegalArgumentException("Illegal argument: " + _ranges);
  }

}

