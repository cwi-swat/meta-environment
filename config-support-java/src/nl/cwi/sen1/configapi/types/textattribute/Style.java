package nl.cwi.sen1.configapi.types.textattribute;

public class Style extends nl.cwi.sen1.configapi.types.TextAttribute {
  public Style(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_style = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Style) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeTextAttribute_Style(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isStyle()
  {
    return true;
  }

  public boolean hasStyle() {
    return true;
  }

  public nl.cwi.sen1.configapi.types.TextStyle getStyle() {
    return (nl.cwi.sen1.configapi.types.TextStyle) getArgument(index_style);
  }

  public nl.cwi.sen1.configapi.types.TextAttribute setStyle(nl.cwi.sen1.configapi.types.TextStyle _style) {
    return (nl.cwi.sen1.configapi.types.TextAttribute) super.setArgument(_style, index_style);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof nl.cwi.sen1.configapi.types.TextStyle)) { 
          throw new RuntimeException("Argument 0 of a Style should have type TextStyle");
        }
        break;
      default: throw new RuntimeException("Style does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

  protected int hashFunction() {
    int c = 0 + (getAnnotations().hashCode()<<8);
    int a = 0x9e3779b9;
    int b = (getAFun().hashCode()<<8);
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
