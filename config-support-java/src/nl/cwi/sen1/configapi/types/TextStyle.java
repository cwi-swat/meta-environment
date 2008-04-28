package nl.cwi.sen1.configapi.types;

abstract public class TextStyle extends nl.cwi.sen1.configapi.AbstractType {
  public TextStyle(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(TextStyle peer) {
    return super.isEqual(peer);
  }

  public boolean isSortTextStyle()  {
    return true;
  }

  public boolean isBold() {
    return false;
  }

  public boolean isItalics() {
    return false;
  }

  public boolean isUnderlined() {
    return false;
  }

}

