package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class EdgeImpl extends MetaGraphConstructor
{
  EdgeImpl(MetaGraphFactory factory) {
     super(factory);
  }
  public boolean isEqual(Edge peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortEdge()  {
    return true;
  }

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

}

