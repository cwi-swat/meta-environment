package tide.tool.support;

//{{{ imports

import aterm.*;

//}}}

public class Port
{
  public static ATermFactory factory;

  private ATerm term;

  //{{{ public static void initialize(ATermFactory factory)

  public static void initialize(ATermFactory factory)
  {
    Port.factory = factory;
  }

  //}}}
  
  //{{{ public static Port parsePort(String spec)

  public static Port parse(String spec)
  {
    try {
      return fromTerm(factory.parse(spec));
    } catch (Exception e) {
      return null;
    } 
  }

  //}}}

  //{{{ public static Port makeStarted()

  public static Port makeStarted()
  {
    return make("started");
  }

  //}}}
  //{{{ public static Port makeStopped()

  public static Port makeStopped()
  {
    return make("stopped");
  }

  //}}}
  //{{{ public static Port makeStep()

  public static Port makeStep()
  {
    return make("step");
  }

  //}}}
  //{{{ public static Port make(String port)

  public static Port make(String port)
  {
    return new Port(factory.parse(port));
  }

  //}}}
  //{{{ public static Port make(ATerm term)

  public static Port make(ATerm term)
  {
    return new Port(term);
  }

  //}}}
  //{{{ public static Port fromTerm(ATerm term)

  public static Port fromTerm(ATerm term)
  {
    return make(term);
  }

  //}}}

  //{{{ Port(ATerm term)

  Port(ATerm term)
  {
    this.term = term;
  }

  //}}}

  //{{{ public ATerm toTerm()

  public ATerm toTerm()
  {
    return term;
  }

  //}}}
  //{{{ public String toString()

  public String toString()
  {
    return term.toString();
  }

  //}}}
}

