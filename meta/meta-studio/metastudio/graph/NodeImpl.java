package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class NodeImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Node fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Node fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Node)

  public boolean isEqual(Node peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Node fromTerm(aterm.ATerm trm)
  {
    Node tmp;
    if ((tmp = Node_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Node: " + trm);
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

  public boolean hasAttributes()
  {
    return false;
  }

  //}}}
  //{{{ default getters and setters

  public NodeId getId()
  {
     throw new RuntimeException("This Node has no Id");
  }

  public Node setId(NodeId _id)
  {
     throw new RuntimeException("This Node has no Id");
  }

  public AttributeList getAttributes()
  {
     throw new RuntimeException("This Node has no Attributes");
  }

  public Node setAttributes(AttributeList _attributes)
  {
     throw new RuntimeException("This Node has no Attributes");
  }

  //}}}

}

