package metastudio.graph;

import aterm.*;

import java.util.List;

public class Node
{
  private static final String PATTERN_POSITIONED =
    "node(<str>,<fun>,<int>,<int>,<int>,<int>)";
  private static final String PATTERN_UNPOSITIONED =
    "node(<str>,<fun>,<int>,<int>)";
  private static final String PATTERN_UNSIZED =
    "node(<str>,<fun>)";
  private ATerm term;

  //{{{ public Node(ATerm term)

  public Node(ATerm term)
  {
    this.term = term;
  }

  //}}}
  //{{{ public static Node createUnsized(ATerm name)

  public static Node createUnsized(ATerm name)
  {
    ATermFactory factory = name.getFactory();

    ATerm shape_term = factory.makeAppl(factory.makeAFun("box", 0, false));

    AFun fun = factory.makeAFun("node", 2, false);

    return new Node(factory.makeAppl(fun, name, shape_term));
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
  //{{{ public boolean isUnsized()

  public boolean isUnsized()
  {
    return term.match(PATTERN_UNSIZED) != null;
  }

  //}}}

  //{{{ public String getName()

  public String getName()
  {
    return ((ATermAppl)((ATermAppl)term).getArgument(0)).getName();
  }

  //}}}
  //{{{ public String getShape()

  public String getShape()
  {
    return ((ATermAppl)((ATermAppl)term).getArgument(1)).getName();
  }

  //}}}
  //{{{ public int getWidth()

  public int getWidth()
  {
    List result;

    result = term.match(PATTERN_POSITIONED);
    if (result != null) {
      return ((Integer)result.get(4)).intValue();
    }

    result = term.match(PATTERN_UNPOSITIONED);
    if (result != null) {
      return ((Integer)result.get(2)).intValue();
    }

    throw new RuntimeException("not a node: " + term);
  }

  //}}}
  //{{{ public int getHeight()

  public int getHeight()
  {
    List result;

    result = term.match(PATTERN_POSITIONED);
    if (result != null) {
      return ((Integer)result.get(5)).intValue();
    }

    result = term.match(PATTERN_UNPOSITIONED);
    if (result != null) {
      return ((Integer)result.get(3)).intValue();
    }

    throw new RuntimeException("not a node: " + term);
  }

  //}}}
  //{{{ public int getX()

  public int getX()
  {
    List result;

    result = term.match(PATTERN_POSITIONED);
    if (result != null) {
      return ((Integer)result.get(2)).intValue();
    }

    throw new RuntimeException("not a positioned node: " + term);
  }

  //}}}
  //{{{ public int getY()

  public int getY()
  {
    List result;

    result = term.match(PATTERN_POSITIONED);
    if (result != null) {
      return ((Integer)result.get(3)).intValue();
    }

    throw new RuntimeException("not a positioned node: " + term);
  }

  //}}}

  //{{{ public Node setSize(int width, int height)

  public Node setSize(int width, int height)
  {
    ATermFactory factory = term.getFactory();

    return new Node(factory.make(PATTERN_UNPOSITIONED, getName(), 
				 getShape(),
				 new Integer(width), new Integer(height)));
  }

  //}}}
  //{{{ public Node setShape(String shape)

  public Node setShape(String shape)
  {
    ATermFactory factory = term.getFactory();

    if (isUnsized()) {
      return new Node(factory.make(PATTERN_UNSIZED, getName(), shape));
    } else {
      return new Node(factory.make(PATTERN_UNPOSITIONED, getName(), shape,
				   new Integer(getWidth()),
				   new Integer(getHeight())));
    }
  }

  //}}}

  //{{{ public ATerm toTerm()

  public ATerm toTerm()
  {
    return term;
  }

  //}}}
}
