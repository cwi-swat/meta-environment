package metastudio.graph;

abstract public class NodeId_DefaultImpl
extends NodeId
{
  NodeId_DefaultImpl(MetaGraphFactory factory) {
    super(factory);
  }
  private static int index_id = 0;
  public shared.SharedObject duplicate() {
    NodeId_Default clone = new NodeId_Default(factory);
     clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
    return clone;
  }

  public boolean equivalent(shared.SharedObject peer) {
    if (peer instanceof NodeId_Default) {
      return super.equivalent(peer);
    }
    return false;
  }
  protected aterm.ATermAppl make(aterm.AFun fun, aterm.ATerm[] i_args, aterm.ATermList annos) {
    return getMetaGraphFactory().makeNodeId_Default(fun, i_args, annos);
  }
  public aterm.ATerm toTerm() {
    if (term == null) {
      term = getMetaGraphFactory().toTerm(this);
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
