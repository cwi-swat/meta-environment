package metastudio.graph;

import java.io.InputStream;
import java.io.IOException;

abstract public class NodeIdImpl extends MetaGraphConstructor
{
  static NodeId fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  static NodeId fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  public boolean isEqual(NodeId peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public static NodeId fromTerm(aterm.ATerm trm)
  {
    NodeId tmp;
    if ((tmp = NodeId_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a NodeId: " + trm);
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

