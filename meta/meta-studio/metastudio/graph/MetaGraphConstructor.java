package metastudio.graph;

abstract public class MetaGraphConstructor
extends aterm.pure.ATermApplImpl
implements aterm.ATerm
{
  protected aterm.ATerm term = null;

  abstract protected aterm.ATerm getPattern();

  public aterm.ATerm toTerm() {
    if(term == null) {
      java.util.List args = new java.util.LinkedList();
      for(int i = 0; i<getArity() ; i++) {
        args.add(((MetaGraphConstructor) getArgument(i)).toTerm());
      }
      setTerm(getFactory().make(getPattern(), args));
    }
    return term;
  }

  public String toString() {
    return toTerm().toString();
  }

  protected void setTerm(aterm.ATerm term) {
   this.term = term;
  }

  public MetaGraphFactory getMetaGraphFactory() {
    return (MetaGraphFactory) getFactory();
  }

  static protected MetaGraphFactory getStaticMetaGraphFactory() {
    return (MetaGraphFactory) getStaticFactory();
  }

}
