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
  
  public FunctionDescriptor(String name, ATerm arg0, ATerm arg1, ATerm arg2, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    nargs = 3;
    argtypes = new ATerm[3];
    argtypes[0] = arg0;
    argtypes[1] = arg1;
    argtypes[2] = arg2;
  }

  public String getName() {
    return name;
  }

  public ATerm getResultType() {
    return resultType;
  }

  public boolean checkStatic(ATerm actual[]) throws ToolBusException {
             System.err.println("checkStatic: " + name);
               for(int i = 0; i < actual.length; i++){
                   System.err.println("actual[" + i + "] = " + actual[i]);
                  System.err.println("argtypes[" + i + "] = " + argtypes[i]);   
               }
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
          if (actual[i] != TBTerm.ListType && actual[i].getType() != ATerm.LIST)
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

  abstract public ATerm apply(ATerm args[], ProcessInstance pi);

}

public class FunctionDescriptors {
  private static Hashtable Funs;
  private static ATermFactory factory;

  public static void init(ATermFactory fac) {
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
  	
    define(new FunctionDescriptor("is-bool", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isBoolean(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("true", TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.True;
        }
      });

      define(new FunctionDescriptor("false", TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.False;
        }
      });
      
    define(new FunctionDescriptor("not", TBTerm.BoolType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return args[0] == TBTerm.True ? TBTerm.False : TBTerm.True;
      }
    });
    define(new FunctionDescriptor("and", TBTerm.BoolType, TBTerm.BoolType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == TBTerm.True) && (args[1] == TBTerm.True) ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("or", TBTerm.BoolType, TBTerm.BoolType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == TBTerm.True) || (args[1] == TBTerm.True) ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("equal", TBTerm.TermType, TBTerm.TermType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == args[1]) ? TBTerm.True : TBTerm.False;
      }
    });

    define(new FunctionDescriptor("not-equal", TBTerm.TermType, TBTerm.TermType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] != args[1]) ? TBTerm.True : TBTerm.False;
      }
    });
    
    define(new FunctionDescriptor("is-int", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isInt(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("greater", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("greater-equal", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() >= ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("less", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() < ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("less-equal", TBTerm.IntType, TBTerm.IntType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() <= ((ATermInt) args[1]).getInt() ? TBTerm.True : TBTerm.False;
      }
    });
    define(new FunctionDescriptor("abs", TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return factory.makeInt(Math.abs(((ATermInt) args[0]).getInt()));
      }
    });
    define(new FunctionDescriptor("add", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return factory.makeInt(((ATermInt) args[0]).getInt() + ((ATermInt) args[1]).getInt());
      }
    });
    define(new FunctionDescriptor("sub", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return factory.makeInt(((ATermInt) args[0]).getInt() - ((ATermInt) args[1]).getInt());
      }
    });

    define(new FunctionDescriptor("mul", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return factory.makeInt(((ATermInt) args[0]).getInt() * ((ATermInt) args[1]).getInt());
      }
    });
    define(new FunctionDescriptor("div", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return factory.makeInt(((ATermInt) args[0]).getInt() / ((ATermInt) args[1]).getInt());
      }
    });

    define(new FunctionDescriptor("mod", TBTerm.IntType, TBTerm.IntType, TBTerm.IntType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return factory.makeInt(((ATermInt) args[0]).getInt() % ((ATermInt) args[1]).getInt());
      }
    });
    
    define(new FunctionDescriptor("is-str", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isStr(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    define(new FunctionDescriptor("is-real", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isReal(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("is-appl", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isAppl(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    define(new FunctionDescriptor("args", TBTerm.TermType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.getArgs(args[0]);
        }
      });
    
    define(new FunctionDescriptor("is-list", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isList(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("size", TBTerm.ListType, TBTerm.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(TBTerm.size(args[0]));
        }
      });
    define(new FunctionDescriptor("first", TBTerm.ListType, TBTerm.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.first(args[0]);
        }
      });
    define(new FunctionDescriptor("next", TBTerm.ListType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.next(args[0]);
        }
      });
    define(new FunctionDescriptor("member", TBTerm.TermType, TBTerm.ListType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.member(args[0], args[1]) ? TBTerm.True : TBTerm.False;
        }
      });
    define(new FunctionDescriptor("subset", TBTerm.ListType,TBTerm.ListType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.subset(args[0],args[1]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("diff", TBTerm.ListType,TBTerm.ListType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.diff(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor("inter", TBTerm.ListType,TBTerm.ListType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.inter(args[0],args[1]);
        }
      });
    define(new FunctionDescriptor("join", TBTerm.TermType,TBTerm.TermType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.join(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor("index", TBTerm.ListType,TBTerm.IntType, TBTerm.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.index(args[0],((ATermInt) args[1]).getInt());
        }
      });
    
    define(new FunctionDescriptor("replace", TBTerm.ListType,TBTerm.IntType, TBTerm.TermType,TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.replace(args[0],((ATermInt) args[1]).getInt(), args[2]);
        }
      });
    
    define(new FunctionDescriptor("put", TBTerm.ListType,TBTerm.TermType, TBTerm.TermType, TBTerm.ListType ) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.put(args[0],args[1], args[2]);
        }
      });
    
    define(new FunctionDescriptor("get", TBTerm.ListType,TBTerm.TermType, TBTerm.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.get(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor("process-name", TBTerm.StrType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
      	AFun afun = factory.makeAFun(pi.getProcessName(),0,true);
      	return factory.makeAppl(afun);
      }
    });

    define(new FunctionDescriptor("process-id", TBTerm.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return pi.getProcessId();
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
    return fd.apply(args, process);
  }

  public static ATerm eval(ATerm t, ProcessInstance pi, Environment env) throws ToolBusException {
	//System.err.println("eval: " + t + "; env = " + env);
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
        if (TBTerm.isStr(t))
        		return t;
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (fun == "quote")  // check # of args
    		return args[0];
        if(fun == "is-var")
        	return TBTerm.isVar(args[0]) ? TBTerm.True : TBTerm.False;
        if(fun == "is-result-var")
        	return TBTerm.isResVar(args[0]) ? TBTerm.True : TBTerm.False; 
        if(args.length == 0 && !((fun == "process-id") || fun == "process-name"))
        		return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = eval(args[i], pi, env);
        }
        return apply(fun, vargs, pi);

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(eval(((ATermList) t).elementAt(i), pi, env), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in eval: " + t);
  }

  public static ATerm checkType(ATerm t, Environment env, boolean quoted) throws ToolBusException {
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
        String name = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (args.length == 0)
            return t;
        if(name == "quote")
        	return checkType(args[0], env, true);
 
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = checkType(args[i], env, quoted);
        }
        if(quoted){
        	AFun afun = ((ATermAppl) t).getAFun();
        	return factory.makeAppl(afun,vargs);
        } else
        	return FunctionDescriptors.checkStatic(name, vargs);
      case ATerm.LIST :
        ATermList lst = TBTerm.factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = TBTerm.factory.makeList(checkType(((ATermList) t).elementAt(i), env, quoted), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in checkType: " + t);
  }

}
