package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class NodeIdImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static NodeId fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static NodeId fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(NodeId)

  public boolean isEqual(NodeId peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static NodeId fromTerm(aterm.ATerm trm)
  {
    NodeId tmp;
    if ((tmp = NodeId_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a NodeId: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasId()
  {
    return false;
  }

  //}}}
  //{{{ default getters and setters

  public String getId()
  {
     throw new RuntimeException("This NodeId has no Id");
  }

  public NodeId setId(String _id)
  {
     throw new RuntimeException("This NodeId has no Id");
  }

  //}}}

}

