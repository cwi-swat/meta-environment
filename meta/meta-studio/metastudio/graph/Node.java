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

  String name;
  String shape;
  int x;
  int y;
  int width;
  int height;

  //{{{ public Node(ATerm term)

  public Node(ATerm term)
  {
    this.term = term;
    init();
  }

  //}}}
  private void init()
  {
    List result;

    result = term.match(PATTERN_POSITIONED);
    if (result != null) {
      name = (String)result.get(0);
      shape = (String)result.get(1);
      x = ((Integer)result.get(2)).intValue();
      y = ((Integer)result.get(3)).intValue();
      width = ((Integer)result.get(4)).intValue();
      height = ((Integer)result.get(5)).intValue();
      return;
    }

    result = term.match(PATTERN_UNPOSITIONED);
    if (result != null) {
      name = (String)result.get(0);
      shape = (String)result.get(1);
      width = ((Integer)result.get(2)).intValue();
      height = ((Integer)result.get(3)).intValue();
      return;
    }

    result = term.match(PATTERN_UNSIZED);
    if (result != null) {
      name = (String)result.get(0);
      shape = (String)result.get(1);
      return;
    }

    throw new RuntimeException("not a node: " + term);
  }
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
    return name;
  }

  //}}}
  //{{{ public String getShape()

  public String getShape()
  {
    return shape;
  }

  //}}}
  //{{{ public int getWidth()

  public int getWidth()
  {
    return width;
  }

  //}}}
  //{{{ public int getHeight()

  public int getHeight()
  {
    return height;
  }

  //}}}
  //{{{ public int getX()

  public int getX()
  {
    return x;
  }

  //}}}
  //{{{ public int getY()

  public int getY()
  {
    return y;
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
