package nl.cwi.sen1.configapi.types.textattribute;

public class Size extends nl.cwi.sen1.configapi.types.TextAttribute {
  public Size(nl.cwi.sen1.configapi.Factory factory, aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] args) {
    super(factory, annos, fun, args);
  }

  private static int index_point = 0;
  public shared.SharedObject duplicate() {
    return this;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof Size) {
      return super.equivalent(peer);
    }
    return false;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] args, aterm.ATermList annos) {
    return getConfigapiFactory().makeTextAttribute_Size(fun, args, annos);
  }

  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getConfigapiFactory().toTerm(this);
    }
    return term;
  }

  public boolean isSize()
  {
    return true;
  }

  public boolean hasPoint() {
    return true;
  }

  public int getPoint() {
   return ((aterm.ATermInt) getArgument(index_point)).getInt();
  }

  public nl.cwi.sen1.configapi.types.TextAttribute setPoint(int _point) {
    return (nl.cwi.sen1.configapi.types.TextAttribute) super.setArgument(getFactory().makeInt(_point), index_point);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (!(arg instanceof aterm.ATermInt)) { 
          throw new RuntimeException("Argument 0 of a Size should have type int");
        }
        break;
      default: throw new RuntimeException("Size does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }

}
