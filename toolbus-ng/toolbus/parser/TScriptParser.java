package toolbus.parser;

import java.io.IOException;
import java.util.Hashtable;

import toolbus.*;
import toolbus.atom.*;
import toolbus.process.*;

import aterm.*;

/*
 *  NodeBuilder: auxiliary class to represent the build function for a particular node.
 */

abstract class NodeBuilder {
  private String name;
  private boolean unEvaluatedArgs;

  /**
   * Method NodeBuilder.
   * @param name: the name of the cons attribute in the SDF definition
   * @param unEvaluatedArgs: should the arguments be evaluated before construction or not?
   */
  public NodeBuilder(String name, boolean unEvaluatedArgs) {
    this.name = name;
    this.unEvaluatedArgs = unEvaluatedArgs;
  }

  public String getName() {
    return name;
  }

  public boolean unEvaluatedArgs() {
    return unEvaluatedArgs;
  }

  /**
   * Method build. Overriddem for each build function.
   * @param args: the (possibly evaluated) arguments of this build function
   * @return Object: the resulting node.
   * @throws ToolBusException
   */
  abstract public Object build(Object args[]) throws ToolBusException;
}

/**
 * Class TScriptNodeBuilders: define the build functions for Tscripts.
 */

class TScriptNodeBuilders {
  private static Hashtable Builders;
  private static ATermFactory factory;

  public static void init(ATermFactory fac) {
    factory = fac;
    Builders = new Hashtable();
    defineBuilders();
  }

  /**
   * Method define: Define one build function.
   * @param b: description of the build function
   */
  private static void define(NodeBuilder b) {
    Builders.put(b.getName(), b);
  }

  /**
   * Method defineBuilders.
   */
  protected static void defineBuilders() {
    /*
     * Builders for small ATerms in the parse tree
     */
    define(new NodeBuilder("vardecl", true) {
      public Object build(Object args[]) {
        return TBTerm.mkVar((ATerm) args[0], (ATerm) args[1]);
      }
    });

    define(new NodeBuilder("resvardecl", true) {
      public Object build(Object args[]) {
        return TBTerm.mkResVar((ATerm) args[0], (ATerm) args[1]);
      }
    });

    define(new NodeBuilder("var", true) {
      public Object build(Object args[]) {
        return TBTerm.mkVar((ATerm) args[0], factory.make("none"));
      }
    });

    define(new NodeBuilder("resvar", true) {
      public Object build(Object args[]) {
        return TBTerm.mkResVar((ATerm) args[0], factory.make("none"));
      }
    });

    define(new NodeBuilder("apply", true) {
      public Object build(Object args[]) throws ToolBusException {
        if (args.length == 1)
          return args[0];
        if (args.length != 2) {
          throw new ToolBusException("apply: wrong number of args");
        }

        String fname = ((ATermAppl) args[0]).getName();
        ATermList fargs = (ATermList) args[1];

        AFun afun = factory.makeAFun(fname, fargs.getLength(), false);
        ATermList realargs = factory.makeList();

        for (int i = 0; i < fargs.getLength(); i++) {
          realargs = realargs.append((ATerm) TScriptNodeBuilders.build(fargs.elementAt(i)));
        }
        return factory.makeAppl(afun, realargs);
      }
    });

    define(new NodeBuilder("natcon", true) {
      public Object build(Object args[]) {
        return factory.makeInt(Integer.parseInt(((ATermAppl) args[0]).getName()));
      }
    });

    define(new NodeBuilder("realcon", true) {
      public Object build(Object args[]) {
        return null;  // not yet implemented
      }
    });

    define(new NodeBuilder("posint", true) {
      public Object build(Object args[]) {
        return null; // not yet implemented
      }
    });

    define(new NodeBuilder("newint", true) {
      public Object build(Object args[]) {
        return null; // not yet implemented
      }
    });

    define(new NodeBuilder("id", true) {
      public Object build(Object args[]) {
        return args[0];
      }
    });

    define(new NodeBuilder("strcon", true) {
      public Object build(Object args[]) {
        return TBTerm.unquote((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("trueFun", true) {
      public Object build(Object args[]) {
        return TBTerm.True;
      }
    });

    define(new NodeBuilder("falseFun", true) {
      public Object build(Object args[]) {
        return TBTerm.False;
      }
    });

    /*
     *  Process constants
     */

    define(new NodeBuilder("Delta", false) {
      public Object build(Object args[]) {
        return new Delta();
      }
    });

    define(new NodeBuilder("Tau", false) {
      public Object build(Object args[]) {
        return new Tau();
      }
    });

    /*
     *  Builders for process operators
     */

    define(new NodeBuilder("Sequence", false) {
      public Object build(Object args[]) {
        return new Sequence((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Alternative", false) {
      public Object build(Object args[]) {
        return new Alternative((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Iteration", false) {
      public Object build(Object args[]) {
        return new Iteration((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Disrupt", false) {
      public Object build(Object args[]) {
        return new Disrupt((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Merge", false) {
      public Object build(Object args[]) {
        return new Merge((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("IfElse", false) {
      public Object build(Object args[]) {
        return new IfElse((ATerm) args[0], (ProcessExpression) args[1], (ProcessExpression) args[2]);
      }
    });

    define(new NodeBuilder("IfThen", false) {
      public Object build(Object args[]) {
        return new IfThen((ATerm) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("LetDefinition", false) {
      public Object build(Object args[]) {
        return new LetDefinition((ATermList) args[0], (ProcessExpression) args[1]);
      }
    });

    /*
     * Process definition and creation
     */

    define(new NodeBuilder("ProcessCall", false) {
      public Object build(Object args[]) {
        return new ProcessCall(((ATerm) args[0]));
      }
    });

    define(new NodeBuilder("ProcessDefinition0", false) {
      public Object build(Object args[]) {
        return new ProcessDefinition(((ATermAppl) args[0]).getName(), factory.makeList(), (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("ProcessDefinition", false) {
      public Object build(Object args[]) {
        return new ProcessDefinition(((ATermAppl) args[0]).getName(), (ATermList) args[1], (ProcessExpression) args[2]);
      }
    });

    define(new NodeBuilder("Create", false) {
      public Object build(Object args[]) {
        return new Create((ATerm) args[0], (ATerm) args[1]);
      }
    });

    /*
     *  Messages
     */

    define(new NodeBuilder("RecMsg", false) {
      public Object build(Object args[]) {
        if (args.length == 1) {
          return new RecMsg((ATerm) args[0]);
        } else {
          return new RecMsg((ATerm) args[0], (ATerm) args[1]);
        }
      }
    });

    define(new NodeBuilder("SndMsg", false) {
      public Object build(Object args[]) {
        if (args.length == 1) {
          return new SndMsg((ATerm) args[0]);
        } else {
          return new SndMsg((ATerm) args[0], (ATerm) args[1]);
        }
      }
    });

    /*
     *  Tool related atoms
     */

    define(new NodeBuilder("Eval", false) {
      public Object build(Object args[]) {
        return new Eval((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("RecVal", false) {
      public Object build(Object args[]) {
        return new RecVal((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("Do", false) {
      public Object build(Object args[]) {
        return new Do((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("Event", false) {
      public Object build(Object args[]) {
        return new Event((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("AckEvent", false) {
      public Object build(Object args[]) {
        return new AckEvent((ATerm) args[0]);
      }
    });

    /*
     * Miscellaneous atoms
     */

    define(new NodeBuilder("Assign", false) {
      public Object build(Object args[]) {
        return new Assign(TBTerm.mkVar((ATerm) args[0], factory.make("none")), (ATerm) args[1]);
      }
    });

    define(new NodeBuilder("Print", false) {
      public Object build(Object args[]) {
        return new Print((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("ShutDown", false) {
      public Object build(Object args[]) {
        return new ShutDown((ATerm) args[0]);
      }
    });
  }

  /**
   * Method build.
   * @param t: ATerm to be traversed
   * @return Object: the resulting Tree
   * @throws ToolBusException
   */
  public static Object build(ATerm t) throws ToolBusException {

    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.LIST :
        ATermList lst = t.getFactory().makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          Object obj = build(((ATermList) t).elementAt(i));
          if (!(obj instanceof ATerm)) {
            throw new ToolBusException("non-ATerm occurs in ATermList: " + obj);
          }
          lst = lst.append((ATerm) obj);
        }
        return lst;

      case ATerm.APPL :
        return buildAppl((ATermAppl) t);
      default :
        throw new ToolBusException("illegal ATerm");
    }
  }

  public static Object buildAppl(ATermAppl t) throws ToolBusException {
    // System.err.println(t);
    String name = t.getName();
    ATerm args[] = t.getArgumentArray();
    NodeBuilder nd = (NodeBuilder) Builders.get(name);

    if (nd == null) {
      if (args.length == 0)
        return TBTerm.unquote(t);
      else
        throw new ToolBusException("Unkown: " + name);
    }

    Object[] oargs = new Object[args.length];

    for (int i = 0; i < args.length; i++) {
      oargs[i] = nd.unEvaluatedArgs() ? args[i] : build(args[i]);
    }
    return nd.build(oargs);
  }
}

public class TScriptParser {

  private static ATermFactory factory = TBTerm.factory;
  private ExternalParser externalparser;

  public TScriptParser(ExternalParser ep) {
    externalparser = ep;
    factory = TBTerm.factory;
    TScriptNodeBuilders.init(factory);
  }

  public void parse(ToolBus toolbus, String filename) throws ToolBusException {
    ATerm interm;
    try {
      interm = externalparser.parse(filename);
    } catch (IOException e) {
      throw new ToolBusException(e.getMessage());
    }

    if (interm.getType() != ATerm.APPL || ((ATermAppl) interm).getName() != "Tscript" || interm.getChildCount() != 2) {
      throw new ToolBusException("ill-formed tree");
    }

    ATerm args[] = ((ATermAppl) interm).getArgumentArray();

    ATermList decls = (ATermList) args[0];

    for (int i = 0; i < decls.getLength(); i++) {
      ProcessDefinition def = (ProcessDefinition) TScriptNodeBuilders.build(decls.elementAt(i));
      //System.err.println(def);
      toolbus.addProcessDefinition(def);
    }
    ATermList calls = (ATermList) interm.getChildAt(1);

    for (int i = 0; i < calls.getLength(); i++) {
      ProcessCall call = (ProcessCall) TScriptNodeBuilders.build(calls.elementAt(i));
      //System.err.println(call);
      toolbus.addProcess(call);
    }

  }
}
