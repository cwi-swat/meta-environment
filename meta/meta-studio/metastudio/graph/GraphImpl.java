package metastudio.graph;

  //{{{ imports

import java.io.InputStream;
import java.io.IOException;
  //}}}

abstract public class GraphImpl extends MetaGraphConstructor
{
  //{{{ fromString()

  static Graph fromString(String str)
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().parse(str);
    return fromTerm(trm);
  }
  //}}}
  //{{{ fromTextFile()

  static Graph fromTextFile(InputStream stream) throws aterm.ParseError, IOException
  {
    aterm.ATerm trm = getStaticMetaGraphFactory().readFromTextFile(stream);
    return fromTerm(trm);
  }
  //}}}
  //{{{ isEqual(Graph)

  public boolean isEqual(Graph peer)
  {
    return term.isEqual(peer.toTerm());
  }
  //}}}
  //{{{ fromTerm(aterm.ATerm trm)

  public static Graph fromTerm(aterm.ATerm trm)
  {
    Graph tmp;
    if ((tmp = Graph_Default.fromTerm(trm)) != null) {
      return tmp;
    }


    throw new RuntimeException("This is not a Graph: " + trm);
  }
  //}}}

  //{{{ default isX and hasX properties

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

  //}}}
  //{{{ default getters and setters

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

  //}}}

}

