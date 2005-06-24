package toolbus.parser;

import java.io.IOException;
import java.util.Hashtable;

import toolbus.*;
import toolbus.atom.*;
import toolbus.process.*;

import aterm.*;

/*
 *  NodeBuilder: auxiliary class to represent the build function for a particular node type.
 */

abstract class NodeBuilder {
  private String name;

  /**
   * Method NodeBuilder.
 * @param name: the name of the cons attribute in the SDF definition
   */
  public NodeBuilder(String name) {
    this.name = name;
  }

  public String getName() {
    return name;
  }

  /**
   * Method build. Overridden for each build function for a particular node type.
   * @param args: the already built arguments of this build function
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
    define(new NodeBuilder("vardecl") {
      public Object build(Object args[]) {
        return TBTerm.mkVar((ATerm) args[0], (ATerm) args[1]);
      }
    });

    define(new NodeBuilder("resvardecl") {
      public Object build(Object args[]) {
        return TBTerm.mkResVar((ATerm) args[0], (ATerm) args[1]);
      }
    });

    define(new NodeBuilder("var") {
      public Object build(Object args[]) {
        return TBTerm.mkVar((ATerm) args[0], factory.make("none"));
      }
    });

    define(new NodeBuilder("resvar") {
      public Object build(Object args[]) {
        return TBTerm.mkResVar((ATerm) args[0], factory.make("none"));
      }
    });
    
    define(new NodeBuilder("placeholder") {
        public Object build(Object args[]) {
          return factory.makePlaceholder((ATerm) args[0]);
        }
      });

    define(new NodeBuilder("apply") {
		public Object build(Object args[]) throws ToolBusException {
			if (args.length == 0 || args.length > 2)
				throw new ToolBusException("apply: wrong number of args");

			ATermList argList = (args.length == 2) ? (ATermList) args[1] : factory.makeList();
			AFun afun = factory.makeAFun(((ATermAppl) args[0]).getName(),
					argList.getLength(), false);

			ATerm vargs[] = new ATerm[argList.getLength()];
			for (int i = 0; i < vargs.length; i++) {
				vargs[i] = argList.elementAt(i);
			}
			return factory.makeAppl(afun, vargs);
		}
    });

    define(new NodeBuilder("natcon") {
      public Object build(Object args[]) {
        return factory.makeInt(Integer.parseInt(((ATermAppl) args[0]).getName()));
      }
    });

    define(new NodeBuilder("realcon") {
      public Object build(Object args[]) {
      	String sreal = args[0].toString() + "." + args[1].toString();
    	System.err.println("sreal = " + sreal);
      	return factory.makeReal(new Double(sreal).doubleValue());
      }
    });

    define(new NodeBuilder("strcon") {
      public Object build(Object args[]) {
      	return args[0];
      }
    });

    /*
     *  Process constants
     */

    define(new NodeBuilder("Delta") {
      public Object build(Object args[]) {
        return new Delta();
      }
    });

    define(new NodeBuilder("Tau") {
      public Object build(Object args[]) {
        return new Tau();
      }
    });

    /*
     *  Builders for process operators
     */

    define(new NodeBuilder("Sequence") {
      public Object build(Object args[]) {
        return new Sequence((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Alternative") {
      public Object build(Object args[]) {
        return new Alternative((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Iteration") {
      public Object build(Object args[]) {
        return new Iteration((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Disrupt") {
      public Object build(Object args[]) {
        return new Disrupt((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("Merge") {
      public Object build(Object args[]) {
        return new Merge((ProcessExpression) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("IfElse") {
      public Object build(Object args[]) {
        return new IfElse((ATerm) args[0], (ProcessExpression) args[1], (ProcessExpression) args[2]);
      }
    });

    define(new NodeBuilder("IfThen") {
      public Object build(Object args[]) {
        return new IfThen((ATerm) args[0], (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("LetDefinition") {
      public Object build(Object args[]) {
        return new LetDefinition((ATermList) args[0], (ProcessExpression) args[1]);
      }
    });

    /*
     * Process definition and creation
     */

    define(new NodeBuilder("ProcessCall") {
      public Object build(Object args[]) {
        return new ProcessCall(((ATerm) args[0]));
      }
    });

    define(new NodeBuilder("ProcessDefinition0") {
      public Object build(Object args[]) {
        return new ProcessDefinition(((ATermAppl) args[0]).getName(), factory.makeList(), (ProcessExpression) args[1]);
      }
    });

    define(new NodeBuilder("ProcessDefinition") {
      public Object build(Object args[]) {
        return new ProcessDefinition(((ATermAppl) args[0]).getName(), (ATermList) args[1], (ProcessExpression) args[2]);
      }
    });

    define(new NodeBuilder("Create") {
      public Object build(Object args[]) {
        return new Create((ATerm) args[0], (ATerm) args[1]);
      }
    });

    /*
     *  Messages
     */

    define(new NodeBuilder("RecMsg") {
      public Object build(Object args[]) {
        if (args.length == 1) {
          return new RecMsg((ATerm) args[0]);
        } else {
          return new RecMsg((ATerm) args[0], (ATerm) args[1]);
        }
      }
    });

    define(new NodeBuilder("SndMsg") {
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

    define(new NodeBuilder("Eval") {
      public Object build(Object args[]) {
        return new Eval((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("RecVal") {
      public Object build(Object args[]) {
        return new RecVal((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("Do") {
      public Object build(Object args[]) {
        return new Do((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("Event") {
      public Object build(Object args[]) {
        return new Event((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("AckEvent") {
      public Object build(Object args[]) {
        return new AckEvent((ATerm) args[0]);
      }
    });

    /*
     * Miscellaneous atoms
     */

    define(new NodeBuilder("Assign") {
      public Object build(Object args[]) {
        return new Assign(TBTerm.mkVar((ATerm) args[0], factory.make("none")), (ATerm) args[1]);
      }
    });

    define(new NodeBuilder("Print") {
      public Object build(Object args[]) {
        return new Print((ATerm) args[0]);
      }
    });

    define(new NodeBuilder("ShutDown") {
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
		case ATerm.APPL:
			System.err.println("build: " + t);
			ATermAppl ap = (ATermAppl) t;
			String name = ap.getName();
			ATerm args[] = ap.getArgumentArray();
			NodeBuilder nd = (NodeBuilder) Builders.get(name);
			if (nd == null) {
				if (args.length == 0) {
					boolean isquoted = false;
					if (name.length() > 0 && name.charAt(0) == '"') {
						name = name.substring(1, name.length() - 1);
						isquoted = true;
					}
					AFun afun = factory.makeAFun(name, 0, isquoted);
					return factory.makeAppl(afun);
				} else { 
					AFun afun = factory.makeAFun(name, args.length, false);
					ATerm vargs[] = new ATerm[args.length];
					for (int i = 0; i < args.length; i++) {
						vargs[i] = (ATerm) build(args[i]);
					}
					return factory.makeAppl(afun, vargs);
				}
			} else {
				Object[] oargs = new Object[args.length];

				for (int i = 0; i < args.length; i++)
					oargs[i] = build(args[i]);
				return nd.build(oargs);
			}

		case ATerm.LIST:
			ATermList lst1 = (ATermList) t;
			ATermList lst2 = factory.makeList();
			for (int i = lst1.getLength() - 1; i >= 0; i--) {
				lst2 = factory.makeList((ATerm) build(lst1.elementAt(i)), lst2);
			}
			return lst2;
		default:
			return t;
		}
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
