package metastudio.graph;

abstract public class NodeId_DefaultImpl
extends NodeId
{
  static private aterm.ATerm pattern = null;

  protected aterm.ATerm getPattern() {
    return pattern;
  }
  private static int index_id = 0;
  public shared.SharedObject duplicate() {
    NodeId_Default clone = new NodeId_Default();
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeNodeId_Default(fun, i_args, annos);
  }
  static public void initializePattern()
  {
    pattern = getStaticFactory().parse("<str>");
  }

  static public NodeId fromTerm(aterm.ATerm trm)
  {
    java.util.List children = trm.match(pattern);

    if (children != null) {
      NodeId tmp = getStaticMetaGraphFactory().makeNodeId_Default((String) children.get(0));
      tmp.setTerm(trm);
      return tmp;
    }
    else {
      return null;
    }
  }
  public aterm.ATerm toTerm() {
    if(term == null) {
      java.util.List args = new java.util.LinkedList();
      args.add(((aterm.ATermAppl) getArgument(0)).getAFun().getName());
      setTerm(getFactory().make(getPattern(), args));
    }
    return term;
  }

  public boolean isDefault()
  {
    return true;
  }

  public boolean hasId()
  {
    return true;
  }

  public String getId()
  {
   return ((aterm.ATermAppl) this.getArgument(index_id)).getAFun().getName();
  }

  public NodeId setId(String _id)
  {
    return (NodeId) super.setArgument(getFactory().makeAppl(getFactory().makeAFun(_id, 0, true)), index_id);
  }

  public aterm.ATermAppl setArgument(aterm.ATerm arg, int i) {
    switch(i) {
      case 0:
        if (! (arg instanceof aterm.ATermAppl)) { 
          throw new RuntimeException("Argument 0 of a NodeId_Default should have type str");
        }
        break;
      default: throw new RuntimeException("NodeId_Default does not have an argument at " + i );
    }
    return super.setArgument(arg, i);
  }
}
