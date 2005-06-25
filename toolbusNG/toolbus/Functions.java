package toolbus;

import java.util.Hashtable;

import toolbus.process.ProcessInstance;

import aterm.*;
import aterm.ATerm;

abstract class FunctionDescriptor {
  private String name;
  private ATerm argtypes[];
  private ATerm resultType;

  public FunctionDescriptor(String name, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    argtypes = new ATerm[0];
  }

  public FunctionDescriptor(String name, ATerm arg0, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    argtypes = new ATerm[1];
    argtypes[0] = arg0;
  }

  public FunctionDescriptor(String name, ATerm arg0, ATerm arg1, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
    argtypes = new ATerm[2];
    argtypes[0] = arg0;
    argtypes[1] = arg1;
  }
  
  public FunctionDescriptor(String name, ATerm arg0, ATerm arg1, ATerm arg2, ATerm resultType) {
    this.name = name;
    this.resultType = resultType;
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
/**
 * checkStatic performs a static type check for calls to built-in functions
 * @param actual an array of types of actual parameters
 * @return boolean
 * @throws ToolBusException
 */
  public boolean checkStatic(ATerm actual[]) {
             //System.err.println("checkStatic: " + name);
             //  for(int i = 0; i < actual.length; i++){
             //      System.err.println("actual[" + i + "] = " + actual[i]);
             //     System.err.println("argtypes[" + i + "] = " + argtypes[i]);   
             //  }
    if (argtypes.length != actual.length)
      ToolBus.error("Functions", name + " has wrong number of arguments");
    
    for (int i = 0; i < argtypes.length; i++) {
    	if(!Functions.compatibleTypes(actual[i], argtypes[i]))
    		ToolBus.error("Functions", "arg # " + i + " of " + name + " is " 
    				+ actual[i] + " but should be " + argtypes[i]);
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

public class Functions {
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

  public static ATerm checkStatic(String fun, ATerm args[]) {
    FunctionDescriptor fd = (FunctionDescriptor) Funs.get(fun);
    if (fd == null)
      ToolBus.error("Functions", "getResultType: unknown function: " + fun);

    if (fd.checkStatic(args))
      return fd.getResultType();
    else
      return null;
  }

  private static ATerm apply(String fun, ATerm args[], ProcessInstance process) {
    FunctionDescriptor fd = (FunctionDescriptor) Funs.get(fun);

    if (fd == null) {
      ToolBus.error("Functions", "apply: unknown function: " + fun);
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
      case ATerm.INT :
        return TBTerm.IntType;

      case ATerm.PLACEHOLDER :
		return ((ATermPlaceholder) t).getPlaceholder();

      case ATerm.REAL :
        return TBTerm.RealType;

      case ATerm.APPL :
        if (TBTerm.isVar(t)) {
          ATerm res = TBTerm.getVarType(t);
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
        	return Functions.checkStatic(name, vargs);
      case ATerm.LIST :
        ATermList lst = TBTerm.factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = TBTerm.factory.makeList(checkType(((ATermList) t).elementAt(i), env, quoted), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in checkType: " + t);
  }
  
  /**
   * compatibleTypeList checks that a list of types is compatible with a given
   * element type
   * @param lst the list to be checked
   * @param elmtype the required element type
   * @return boolean
   */
  public static boolean compatibleTypeList(ATermList lst, ATerm elmtype){
	for(int i = 0; i < lst.getLength() -1; i++){
		if(!compatibleTypes(lst.elementAt(i), elmtype))
			return false;
	}
	return true;
  }
  
  /**
   * compatibleTypes checks that two types are compatible
   * @param t1 first type
   * @param t2 second type
   * @return boolean
   */
  public static boolean compatibleTypes(ATerm t1, ATerm t2){
  	//System.err.println("compatibleType(" + t1 + ", " + t2 + ")");
  	
 	if(t1.getType() == ATerm.PLACEHOLDER)
  		t1 = ((ATermPlaceholder) t1).getPlaceholder();
 	if(t2.getType() == ATerm.PLACEHOLDER)
  		t2 = ((ATermPlaceholder) t2).getPlaceholder();
 	
  	if(t1.equals(t2))
  		return true;
  	
  	if(t1.equals(TBTerm.TermType) || t2.equals(TBTerm.TermType))
  		return true;
  	
  	switch(t1.getType()){
    case ATerm.INT :
    	return t2.equals(TBTerm.IntType);
    case ATerm.REAL :
    	return t2.equals(TBTerm.RealType);
    
    case ATerm.PLACEHOLDER:
    	return compatibleTypes(((ATermPlaceholder) t1).getPlaceholder(), t2);
    
    case ATerm.APPL:
       	ATermAppl ap1 = (ATermAppl) t1;
  		if(t2.getType() != ATerm.APPL){   
	    	if(ap1.getName() == "list" && t2.getType() == ATerm.LIST) {
	    		if(ap1.getArity() == 0)
	    			return true;
	    		else
	    			return compatibleTypeList((ATermList) t2, ap1.getArgument(0));
	    	} else if(t2.getType() == ATerm.INT && t1.equals(TBTerm.IntType))
	    		return true;
			else if(t2.getType() == ATerm.REAL && t1.equals(TBTerm.RealType))
					return true;
			else
	    		return false;
	  	}
  
       	ATermAppl ap2 = (ATermAppl) t2;
       	if(ap1.getName() != ap2.getName())
       		return false;
       	if(ap1.getArity() == 0 || ap2.getArity() == 0)
       		return true;
       	if(ap1.getArity() != ap2.getArity())
       		return false;
       	for(int i = 0; i < ap1.getArity() - 1; i++){
       		if(!compatibleTypes(ap1.getArgument(i), ap2.getArgument(i)))
				return false;
       	}
       	return true;
    	
    case ATerm.LIST:
    	if(t2.getType() == ATerm.LIST){
    		ATermList lst1 = (ATermList) t1;
    		ATermList lst2 = (ATermList) t2;
    		if(lst1.getLength() != lst2.getLength())
    			return false;
    		for(int i = 0; i < lst1.getLength() -1; i++){
    			if(!compatibleTypes(lst1.elementAt(i), lst2.elementAt(i)))
    				return false;
    		}
    		return true;
    	}
        if(t2.getType() == ATerm.APPL){
    		ATermAppl ap = (ATermAppl) t2;
    		if(ap.getName() == "list"){
    			if(ap.getArity() == 0)
    				return true;
    			else
    				return compatibleTypeList((ATermList) t1, ap.getArgument(0));
    		} else
    			return false;
    	}
  	}
    throw new ToolBusInternalError("illegal ATerm in compareType: " + t1);
  }
}
