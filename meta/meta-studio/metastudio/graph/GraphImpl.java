package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class GraphImpl extends MetaGraphConstructor
{
  static Graph fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  static Graph fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  public boolean isEqual(Graph peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public static Graph fromTerm(aterm.ATerm trm)
  {
    Graph tmp;
    if ((tmp = Graph_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Graph: " + trm);
  }

  public boolean isDefault()
  {
    return false;
  }

  public boolean hasNodes()
  {
    return false;
  }

  public boolean hasEdges()
  {
    return false;
  }

  public boolean hasAttributes()
  {
    return false;
  }

  public NodeList getNodes()
  {
     throw new RuntimeException("This Graph has no Nodes");
  }

  public Graph setNodes(NodeList _nodes)
  {
     throw new RuntimeException("This Graph has no Nodes");
  }

  public EdgeList getEdges()
  {
     throw new RuntimeException("This Graph has no Edges");
  }

  public Graph setEdges(EdgeList _edges)
  {
     throw new RuntimeException("This Graph has no Edges");
  }

  public AttributeList getAttributes()
  {
     throw new RuntimeException("This Graph has no Attributes");
  }

  public Graph setAttributes(AttributeList _attributes)
  {
     throw new RuntimeException("This Graph has no Attributes");
  }


}

