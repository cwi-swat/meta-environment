package metastudio.graph;

import aterm.*;

public class Edge
{
  private static final String PATTERN_POSITIONED =
    "edge(<str>,<str>,<term>)";
  private static final String PATTERN_UNPOSITIONED =
    "edge(<str>,<str>)";
  private ATerm term;

  //{{{ public Edge(ATerm term)

  public Edge(ATerm term)
  {
    this.term = term;
  }

  //}}}

  //{{{ public static Edge createUnpositionedEdge(ATerm fromTerm, ATerm toTerm)

  public static Edge createUnpositionedEdge(ATerm fromTerm, ATerm toTerm)
  {
    ATermFactory factory = fromTerm.getFactory();

    AFun fun = factory.makeAFun("edge", 2, false);
    return new Edge(factory.makeAppl(fun, fromTerm, toTerm));
  }

  //}}}

  //{{{ public boolean isPositioned()

  public boolean isPositioned()
  {
    return term.match(PATTERN_POSITIONED) != null;
  }

  //}}}
  //{{{ public boolean isUnpositioned()

  public boolean isUnpositioned()
  {
    return term.match(PATTERN_UNPOSITIONED) != null;
  }

  //}}}

  //{{{ public String getFrom()

  public String getFrom()
  {
    return ((ATermAppl)((ATermAppl)term).getArgument(0)).getName();
  }

  //}}}
  //{{{ public String getTo()

  public String getTo()
  {
    return ((ATermAppl)((ATermAppl)term).getArgument(1)).getName();
  }

  //}}}
  //{{{ public Polygon getPolygon()

  public Polygon getPolygon()
  {
    return new Polygon(((ATermAppl)term).getArgument(2));
  }

  //}}}

  //{{{ public boolean connectedTo(Node node)

  public boolean connectedTo(Node node)
  {
    return (node != null
	    && (getFrom().equals(node.getName())
		|| getTo().equals(node.getName())));
  }

  //}}}

  //{{{ public ATerm toTerm()

  public ATerm toTerm()
  {
    return term;
  }

  //}}}
}
