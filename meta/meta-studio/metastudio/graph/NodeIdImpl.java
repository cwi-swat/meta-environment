package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class NodeIdImpl extends MetaGraphConstructor
{
  NodeIdImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(NodeId peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortNodeId()  {
    return true;
  }

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasId()
  {
    return false;
  }

  public String getId()
  {
     throw new RuntimeException("This NodeId has no Id");
  }

  public NodeId setId(String _id)
  {
     throw new RuntimeException("This NodeId has no Id");
  }

}

