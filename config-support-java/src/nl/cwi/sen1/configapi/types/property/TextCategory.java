package nl.cwi.sen1.configapi.types.property;

public class TextCategory extends nl.cwi.sen1.configapi.types.Property {
  public TextCategory(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_category = 0;
  private static int index_map = 1;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof TextCategory) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeProperty_TextCategory(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isTextCategory()
  {
    return true;
  }

  public boolean hasCategory() {
    return true;
  }

  public boolean hasMap() {
    return true;
  }

  public nl.cwi.sen1.configapi.types.TextCategoryName getCategory() {
    return (nl.cwi.sen1.configapi.types.TextCategoryName) getArgument(index_category);
  }

  public nl.cwi.sen1.configapi.types.Property setCategory(nl.cwi.sen1.configapi.types.TextCategoryName _category) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(_category, index_category);
  }

  public nl.cwi.sen1.configapi.types.TextAttributeMap getMap() {
    return (nl.cwi.sen1.configapi.types.TextAttributeMap) getArgument(index_map);
  }

  public nl.cwi.sen1.configapi.types.Property setMap(nl.cwi.sen1.configapi.types.TextAttributeMap _map) {
    return (nl.cwi.sen1.configapi.types.Property) super.setArgument(_map, index_map);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.TextCategoryName)) { 
          throw new RuntimeException("Argument 0 of a TextCategory should have type TextCategoryName");
        }
        break;
      case 1:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.TextAttributeMap)) { 
          throw new RuntimeException("Argument 1 of a TextCategory should have type TextAttribute-map");
        }
        break;
      default: throw new RuntimeException("TextCategory does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
    a += (getArgument(1).hashCode() << 8);
    a += (getArgument(0).hashCode() << 0);

    a -= b; a -= c; a ^= (c >> 13);
    b -= c; b -= a; b ^= (a << 8);
    c -= a; c -= b; c ^= (b >> 13);
    a -= b; a -= c; a ^= (c >> 12);
    b -= c; b -= a; b ^= (a << 16);
    c -= a; c -= b; c ^= (b >> 5);
    a -= b; a -= c; a ^= (c >> 3);
    b -= c; b -= a; b ^= (a << 10);
    c -= a; c -= b; c ^= (b >> 15);

    return c;
  }

}
