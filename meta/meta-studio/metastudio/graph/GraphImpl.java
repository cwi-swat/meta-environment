package metastudio.graph;

import aterm.*;
import java.io.InputStream;
import java.io.IOException;

abstract public class GraphImpl extends MetaGraphConstructor
{
  GraphImpl(MetaGraphFactory factory) {
     super(factory);
  }
  protected void init(int hashCode, aterm.ATermList annos, aterm.AFun fun,	aterm.ATerm[] args) {
    super.init(hashCode, annos, fun, args);
  }
  protected void initHashCode(aterm.ATermList annos, aterm.AFun fun, aterm.ATerm[] i_args) {
  	super.initHashCode(annos, fun, i_args);
  }
  public boolean isEqual(Graph peer)
  {
    return term.isEqual(peer.toTerm());
  }
  public boolean isSortGraph()  {
    return true;
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

