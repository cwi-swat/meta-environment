package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class EdgeImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Edge fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Edge fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Edge)

  public boolean isEqual(Edge peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Edge fromTerm(aterm.ATerm trm)
  {
    Edge tmp;
    if ((tmp = Edge_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Edge: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasFrom()
  {
    return false;
  }

  public boolean hasTo()
  {
    return false;
  }

  public boolean hasAttributes()
  {
    return false;
  }

  //}}}
  //{{{ default getters and setters

  public NodeId getFrom()
  {
     throw new RuntimeException("This Edge has no From");
  }

  public Edge setFrom(NodeId _from)
  {
     throw new RuntimeException("This Edge has no From");
  }

  public NodeId getTo()
  {
     throw new RuntimeException("This Edge has no To");
  }

  public Edge setTo(NodeId _to)
  {
     throw new RuntimeException("This Edge has no To");
  }

  public AttributeList getAttributes()
  {
     throw new RuntimeException("This Edge has no Attributes");
  }

  public Edge setAttributes(AttributeList _attributes)
  {
     throw new RuntimeException("This Edge has no Attributes");
  }

  //}}}

}

