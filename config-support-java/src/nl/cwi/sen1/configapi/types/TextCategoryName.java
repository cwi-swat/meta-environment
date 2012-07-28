package nl.cwi.sen1.configapi.types;

abstract public class TextCategoryName extends nl.cwi.sen1.configapi.AbstractType {
  public TextCategoryName(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
     super(factory, annos, fun, args);
  }

  public boolean isEqual(TextCategoryName peer) {
    return super.isEqual(peer);
  }

  public boolean isSortTextCategoryName()  {
    return true;
  }

  public boolean isFocus() {
    return false;
  }

  public boolean isSelection() {
    return false;
  }

  public boolean isNormal() {
    return false;
  }

  public boolean isExtern() {
    return false;
  }

  public boolean hasName() {
    return false;
  }

  public String getName() {
     throw new UnsupportedOperationException("This TextCategoryName has no Name");
  }

  public TextCategoryName setName(String _name) {
     throw new IllegalArgumentException("Illegal argument: " + _name);
  }

}

