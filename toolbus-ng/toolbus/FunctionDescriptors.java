package toolbus;

import java.util.Hashtable;

import toolbus.process.ProcessInstance;

import aterm.*;
import aterm.ATerm;

abstract class FunctionDescriptor {
  private String name;
  private int nargs;
  private ATerm argtypes[];
  private ATerm resultType;

  public FunctionDescriptor(String name, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    nargs = 0;
    argtypes = new ATerm[0];
  }

  public FunctionDescriptor(String name, ATerm arg0, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    nargs = 1;
    argtypes = new ATerm[1];
    argtypes[0] = arg0;
  }

  public FunctionDescriptor(String name, ATerm arg0, ATerm arg1, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    nargs = 2;
    argtypes = new ATerm[2];
    argtypes[0] = arg0;
    argtypes[1] = arg1;
  }

  public String getName() {
    return name;
  }

  public ATerm getResultType() {
    return resultType;
  }

  public boolean checkStatic(ATerm actual[]) throws ToolBusException {
    //          System.err.println("checkStatic: " + name);
    //           for(int i = 0; i < actual.length; i++){
    //               System.err.println("actual[" + i + "] = " + actual[i]);
    //               System.err.println("argtypes[" + i + "] = " + argtypes[i]);   
    //           }
    if (argtypes.length != actual.length)
      throw new ToolBusException(name + " has wrong number of arguments");
    for (int i = 0; i < argtypes.length; i++) {
      if (actual[i] == TBTerm.TermType) {
        System.err.println("arg # " + i + " of " + name + " is term (requires dynamic check)");
      } else {
        if (argtypes[i] == TBTerm.BoolType) {
          if (actual[i] != TBTerm.BoolType)
            throw new ToolBusException("arg #" + i + " of " + name + " is " + actual[i] + " but should be boolean");
        } else if (argtypes[i] == TBTerm.IntType) {
          if (actual[i] != TBTerm.IntType)
            throw new ToolBusException("arg #" + i + " of " + name + " is " + actual[i] + " but should be integer");
        } else if (argtypes[i] == TBTerm.TermType) {
        } else if (argtypes[i] == TBTerm.ListType) {
          if (actual[i] != TBTerm.ListType)
            throw new ToolBusException("arg #" + i + " of " + name + " is " + actual[i] + " but should be list");
        } else
          throw new ToolBusInternalError("check: wrong type " + argtypes[i]);
      }
    }
    return true;
  }

  public boolean checkRunTime(ATerm actual[]) throws ToolBusException {
    if (argtypes.length != actual.length)
      throw new ToolBusException(name + " has wrong number of arguments");
    for (int i = 0; i < argtypes.length; i++) {
      if (argtypes[i] == TBTerm.BoolType) {
        if (!TBTerm.isBoolean(actual[i]))
          throw new ToolBusException("arg #" + i + " of " + name + " should be boolean");
      } else if (argtypes[i] == TBTerm.IntType) {
        if (!(actual[i] instanceof ATermInt))
          throw new ToolBusException("arg #" + i + " of " + name + " should be integer");
      } else if (argtypes[i] == TBTerm.TermType) {
      } else if (argtypes[i] == TBTerm.ListType) {
        if (!(actual[i] instanceof ATermList))
          throw new ToolBusException("arg #" + i + " of " + name + " should be list");
      } else
        throw new ToolBusInternalError("check: wrong type " + argtypes[i]);
    }
    return true;
  }

  abstract public ATerm apply(ATerm args[]);

}

public class FunctionDescriptors {
  private static Hashtable Funs;
  private static ATermFactory factory;
  
  public static void init(ATermFactory fac){
    factory = fac;
    Funs = new Hashtable();
    defineFuns();
  }

  /**
   *  Declaration
   */

  private static void define(FunctionDescriptor fd) {
    Funs.put(fd.getName(), fd);
  }

  protected static void defineFuns() {

    define(new FunctionDescriptor("not", TBTerm.BoolType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return args[0] == TBTerm.True ? TBTerm.False : TBTerm.True;
      }
    });
    define(new FunctionDescriptor("and", TBTerm.BoolType, TBTerm.BoolType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return (args[0] == TBTerm.True) && (args[1] == TBTerm.True) ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("or", TBTerm.BoolType, TBTerm.BoolType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return (args[0] == TBTerm.True) || (args[1] == TBTerm.True) ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("equal", TBTerm.TermType, TBTerm.TermType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return (args[0] == args[1]) ? TBTerm.True : TBTerm.False;
      }
    });

    define(new FunctionDescriptor("not-equal", TBTerm.TermType, TBTerm.TermType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return (args[0] != args[1]) ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("greater", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("greater-equal", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return ((ATermInt) args[0]).getInt() >= ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("less", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return ((ATermInt) args[0]).getInt() < ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("less-equal", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("abs", TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[]) {
        return factory.makeInt(Math.abs(((ATermInt) args[0]).getInt()));
      }
    });
    define(new FunctionDescriptor("add", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[]) {
        return factory.makeInt(((ATermInt) args[0]).getInt() + ((ATermInt) args[1]).getInt());
      }
    });
    define(new FunctionDescriptor("sub", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[]) {
        return factory.makeInt(((ATermInt) args[0]).getInt() - ((ATermInt) args[1]).getInt());
      }
    });

    define(new FunctionDescriptor("mul", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[]) {
        return factory.makeInt(((ATermInt) args[0]).getInt() * ((ATermInt) args[1]).getInt());
      }
    });
    define(new FunctionDescriptor("div", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[]) {
        return factory.makeInt(((ATermInt) args[0]).getInt() / ((ATermInt) args[1]).getInt());
      }
    });

    define(new FunctionDescriptor("mod", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[]) {
        return factory.makeInt(((ATermInt) args[0]).getInt() % ((ATermInt) args[1]).getInt());
      }
    });

    //    define(new FunctionDescriptor("processId", TermType){
    //      public ATerm apply(ATerm args[]) {
    //        return process.getProcessId();
    //      }
    //    });
    define(new FunctionDescriptor("true", TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return TBTerm.True;
      }
    });

    define(new FunctionDescriptor("false", TBTerm.BoolType) {
      public ATerm apply(ATerm args[]) {
        return TBTerm.False;
      }
    });
  }

  public static ATerm checkStatic(String fun, ATerm vargs[]) throws ToolBusException {
    FunctionDescriptor fd = (FunctionDescriptor) Funs.get(fun);
    if (fd == null)
      throw new ToolBusException("getResultType: unknown function: " + fun);

    if (fd.checkStatic(vargs))
      return fd.getResultType();
    else
      return null;
  }

  private static ATerm apply(String fun, ATerm args[], ProcessInstance process) {
    FunctionDescriptor fd = (FunctionDescriptor) Funs.get(fun);

    if (fd == null) {
      throw new ToolBusInternalError("apply: unknown function: " + fun);
    }
    try {
      fd.checkRunTime(args); // redundant after typecheck!
    } catch (ToolBusException e) {
    }
    return fd.apply(args);
  }

  public static ATerm eval(ATerm t, ProcessInstance process) throws ToolBusException {
    Environment env = process.getEnv();
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        if (TBTerm.isVar(t))
          return env.getValue(t);
        if (TBTerm.isBoolean(t))
          return t;
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = eval(args[i], process);
        }
        return apply(fun, vargs, process);

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(eval(((ATermList) t).elementAt(i), process), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in eval: " + t);
  }

  public static ATerm checkType(ATerm t, Environment env) throws ToolBusException {
    //System.err.println("checkType(" + t + ")");
    switch (t.getType()) {
      case ATerm.BLOB :
        throw new ToolBusInternalError("checkType: BLOB");

      case ATerm.INT :
        return TBTerm.IntType;

      case ATerm.PLACEHOLDER : // ??
        throw new ToolBusInternalError("checkType: PLACEHOLDER");

      case ATerm.REAL :
        return TBTerm.RealType;

      case ATerm.APPL :
        if (TBTerm.isVar(t)) {
          ATerm res = TBTerm.getVarType(t);
          //System.out.println("getType(" + t + ") => " + res);
          return res;
        }
        if (TBTerm.isBoolean(t)) {
          return TBTerm.BoolType;
        }
        if (((ATermAppl) t).isQuoted() && ((ATermAppl) t).getArity() == 0) {
          return TBTerm.StrType;
        }
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        //        if (args.length == 0)
        //          return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = checkType(args[i], env);
        }
        return FunctionDescriptors.checkStatic(fun, vargs);
      case ATerm.LIST :
        ATermList lst = TBTerm.factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = TBTerm.factory.makeList(checkType(((ATermList) t).elementAt(i), env), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in checkType: " + t);
  }



}
