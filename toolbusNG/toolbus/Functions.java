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
      if (argtypes[i] == TBTermFactory.BoolType) {
        if (!TBTermFactory.isBoolean(actual[i]))
          throw new ToolBusException("arg #" + i + " of " + name + " should be boolean");
      } else if (argtypes[i] == TBTermFactory.IntType) {
        if (!(actual[i] instanceof ATermInt))
          throw new ToolBusException("arg #" + i + " of " + name + " should be integer");
      } else if (argtypes[i] == TBTermFactory.RealType) {
        if (!(actual[i] instanceof ATermReal))
          throw new ToolBusException("arg #" + i + " of " + name + " should be real");
      } else if (argtypes[i] == TBTermFactory.TermType) {
      } else if (argtypes[i] == TBTermFactory.ListType) {
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
  	
    define(new FunctionDescriptor("is-bool", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.isBoolean(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    define(new FunctionDescriptor("is-int", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.isInt(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    define(new FunctionDescriptor("is-real", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.isReal(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    define(new FunctionDescriptor("is-str", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.isStr(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    // is-bstr
    
    define(new FunctionDescriptor("is-appl", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.isAppl(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    define(new FunctionDescriptor("is-list", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.isList(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    define(new FunctionDescriptor("is-empty", TBTermFactory.TermType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return TBTermFactory.True;
          //}
          if(TBTermFactory.isList(args[0])){
          	if(((ATermList) args[0]).getLength() == 0)
          		return  TBTermFactory.True;
          }
          return TBTermFactory.False;
        }
      });
    
    // is-var, see method eval
    // is-result-var, see method eval
    // TODO: is-formal
    
    define(new FunctionDescriptor("fun", TBTermFactory.TermType, TBTermFactory.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	String fname  = ((ATermAppl) args[0]).getName();
          return TBTermFactory.getPureFactory().make("<str>", fname);
        }
      });
    
    define(new FunctionDescriptor("args", TBTermFactory.TermType, TBTermFactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.getArgs(args[0]);
        }
      });
    
    define(new FunctionDescriptor("true", TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.True;
        }
      });

      define(new FunctionDescriptor("false", TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.False;
        }
      });
      
    define(new FunctionDescriptor("not", TBTermFactory.BoolType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return args[0] == TBTermFactory.True ? TBTermFactory.False : TBTermFactory.True;
      }
    });
    
    define(new FunctionDescriptor("and", TBTermFactory.BoolType, TBTermFactory.BoolType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == TBTermFactory.True) && (args[1] == TBTermFactory.True) ? TBTermFactory.True : TBTermFactory.False;
      }
    });
    
    define(new FunctionDescriptor("or", TBTermFactory.BoolType, TBTermFactory.BoolType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == TBTermFactory.True) || (args[1] == TBTermFactory.True) ? TBTermFactory.True : TBTermFactory.False;
      }
    });
    
    define(new FunctionDescriptor("equal", TBTermFactory.TermType, TBTermFactory.TermType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        ATerm res = (args[0] == args[1]) ? TBTermFactory.True : TBTermFactory.False;
      	//System.err.println("equal: " + args[0] + " == " + args[1] + " ==> " + res);
      	return res;
      }
    });

    define(new FunctionDescriptor("not-equal", TBTermFactory.TermType, TBTermFactory.TermType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        ATerm res = (args[0] != args[1]) ? TBTermFactory.True : TBTermFactory.False;
    	//System.err.println("not-equal: " + args[0] + " == " + args[1] + " ==> " + res);
      	return res;
      }
    });
    
    define(new FunctionDescriptor("add", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(((ATermInt) args[0]).getInt() + ((ATermInt) args[1]).getInt());
        }
      });
    
      define(new FunctionDescriptor("sub", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(((ATermInt) args[0]).getInt() - ((ATermInt) args[1]).getInt());
        }
      });

      define(new FunctionDescriptor("mul", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(((ATermInt) args[0]).getInt() * ((ATermInt) args[1]).getInt());
        }
      });
      define(new FunctionDescriptor("div", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(((ATermInt) args[0]).getInt() / ((ATermInt) args[1]).getInt());
        }
      });
      
      define(new FunctionDescriptor("mod", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(((ATermInt) args[0]).getInt() % ((ATermInt) args[1]).getInt());
        }
      });
      
      define(new FunctionDescriptor("abs", TBTermFactory.IntType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(Math.abs(((ATermInt) args[0]).getInt()));
        }
      });
      
      define(new FunctionDescriptor("less", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermInt) args[0]).getInt() < ((ATermInt) args[1]).getInt() ? TBTermFactory.True : TBTermFactory.False;
        }
      });
      define(new FunctionDescriptor("less-equal", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermInt) args[0]).getInt() <= ((ATermInt) args[1]).getInt() ? TBTermFactory.True : TBTermFactory.False;
        }
      });
     
    define(new FunctionDescriptor("greater", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? TBTermFactory.True : TBTermFactory.False;
      }
    });
    define(new FunctionDescriptor("greater-equal", TBTermFactory.IntType, TBTermFactory.IntType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() >= ((ATermInt) args[1]).getInt() ? TBTermFactory.True : TBTermFactory.False;
      }
    });
    
    define(new FunctionDescriptor("radd", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(((ATermReal) args[0]).getReal() + ((ATermReal) args[1]).getReal());
        }
      });
    
      define(new FunctionDescriptor("rsub", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(((ATermReal) args[0]).getReal() - ((ATermReal) args[1]).getReal());
        }
      });

      define(new FunctionDescriptor("rmul", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(((ATermReal) args[0]).getReal() * ((ATermReal) args[1]).getReal());
        }
      });
      define(new FunctionDescriptor("rdiv", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
         return factory.makeReal(((ATermReal) args[0]).getReal() / ((ATermReal) args[1]).getReal());
        }
      });
      
      define(new FunctionDescriptor("rless", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermReal) args[0]).getReal() < ((ATermReal) args[1]).getReal() ? TBTermFactory.True : TBTermFactory.False;
        }
      });
      define(new FunctionDescriptor("rless-equal", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
            return ((ATermReal) args[0]).getReal() <= ((ATermReal) args[1]).getReal() ? TBTermFactory.True : TBTermFactory.False ;
        }
      });
     
    define(new FunctionDescriptor("rgreater", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermReal) args[0]).getReal() > ((ATermReal) args[1]).getReal() ? TBTermFactory.True : TBTermFactory.False ;
      }
    });
    define(new FunctionDescriptor("rgreater-equal", TBTermFactory.RealType, TBTermFactory.RealType, TBTermFactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermReal) args[0]).getReal() >= ((ATermReal) args[1]).getReal() ? TBTermFactory.True : TBTermFactory.False ;
      }
    });
  
    // sin, cos, atan atan2 exp log log10 sqrt
    
    define(new FunctionDescriptor("rabs", TBTermFactory.RealType, TBTermFactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(Math.abs(((ATermReal) args[0]).getReal()));
        }
      });
    
    define(new FunctionDescriptor("size", TBTermFactory.ListType, TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return factory.makeInt(0);
          //}
          return factory.makeInt(TBTermFactory.size(args[0]));
        }
      });
    
    define(new FunctionDescriptor("index", TBTermFactory.ListType,TBTermFactory.IntType, TBTermFactory.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.index(args[0],((ATermInt) args[1]).getInt());
        }
      });
    
    define(new FunctionDescriptor("replace", TBTermFactory.ListType,TBTermFactory.IntType, TBTermFactory.TermType,TBTermFactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.replace(args[0],((ATermInt) args[1]).getInt(), args[2]);
        }
      });
    define(new FunctionDescriptor("get", TBTermFactory.ListType,TBTermFactory.TermType, TBTermFactory.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.get(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor("put", TBTermFactory.ListType,TBTermFactory.TermType, TBTermFactory.TermType, TBTermFactory.ListType ) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.put(args[0],args[1], args[2]);
        }
      });
    
    
    define(new FunctionDescriptor("first", TBTermFactory.ListType, TBTermFactory.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return null;
         //}
          return TBTermFactory.first(args[0]);
        }
      });
    define(new FunctionDescriptor("next", TBTermFactory.ListType, TBTermFactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	//if(args[0] == null){
        	//	return null;
        	//}
          return TBTermFactory.next(args[0]);
        }
      });
    define(new FunctionDescriptor("member", TBTermFactory.TermType, TBTermFactory.ListType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.member(args[0], args[1]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    define(new FunctionDescriptor("subset", TBTermFactory.ListType,TBTermFactory.ListType, TBTermFactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.subset(args[0],args[1]) ? TBTermFactory.True : TBTermFactory.False;
        }
      });
    
    define(new FunctionDescriptor("diff", TBTermFactory.ListType,TBTermFactory.ListType, TBTermFactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.diff(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor("inter", TBTermFactory.ListType,TBTermFactory.ListType, TBTermFactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.inter(args[0],args[1]);
        }
      });
    define(new FunctionDescriptor("join", TBTermFactory.TermType,TBTermFactory.TermType, TBTermFactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.join(args[0],args[1]);
        }
      });
    
    // functions

    define(new FunctionDescriptor("process-id", TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTermFactory.getPureFactory().makeInt(pi.getProcessId());
        }
      });
    
    define(new FunctionDescriptor("process-name", TBTermFactory.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	AFun afun = factory.makeAFun(pi.getProcessName(),0,true);
        	return factory.makeAppl(afun);
        }
      });
    
    // quote
    // current-time
    define(new FunctionDescriptor("current-time", TBTermFactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	int n = (int) pi.getRunTime();
        	return factory.makeInt(n);
        }
      });
    
    // sec
    // msec

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
        
      case TBTermFactory.VAR:
    	  return env.getValue((TBTermVar) t);

      case ATerm.APPL :
        if (TBTermFactory.isBoolean(t))
          return t;
        if (TBTermFactory.isStr(t))
        		return t;
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (fun == "quote"){ // TODO: check # of args
        	//System.err.println("quote: " + t + " ==> " + TBTermFactory.substitute(args[0], env));
    		return TBTermFactory.substitute(args[0], env);
        }
        if(fun == "is-var")
        	return TBTermFactory.isVar(args[0]) ? TBTermFactory.True : TBTermFactory.False;
        if(fun == "is-result-var")
        	return TBTermFactory.isResVar(args[0]) ? TBTermFactory.True : TBTermFactory.False; 
        if(args.length == 0 && !((fun == "process-id") || fun == "process-name"))
        		return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = eval(args[i], pi, env);
        }
        return apply(fun, vargs, pi);

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        ATermList tlst = (ATermList) t;
        for (int i = tlst.getLength() - 1; i >= 0; i--) {
          lst = lst.insert(eval(tlst.elementAt(i), pi, env));
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in eval: " + t);
  }

  public static ATerm checkType(ATerm t, Environment env, boolean quoted) throws ToolBusException {
    //System.err.println("checkType(" + t + ")");
    switch (t.getType()) {
      case ATerm.INT :
        return TBTermFactory.IntType;

      case ATerm.PLACEHOLDER :
		return ((ATermPlaceholder) t).getPlaceholder();

      case ATerm.REAL :
        return TBTermFactory.RealType;
        
      case TBTermFactory.VAR:
    	  return ((TBTermVar) t).getVarType();

      case ATerm.APPL :
    	ATermAppl apt = (ATermAppl) t;
     
        if (TBTermFactory.isBoolean(apt)) {
          return TBTermFactory.BoolType;
        }
        if (apt.isQuoted() && apt.getArity() == 0) {
          return TBTermFactory.StrType;
        }
        String name = apt.getName();
        ATerm args[] = apt.getArgumentArray();
        if (args.length == 0 && Funs.get(name) == null)
            return t;
        if(name == "quote")
        	return checkType(args[0], env, true);
 
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = checkType(args[i], env, quoted);
        }
        if(quoted){
        	AFun afun = apt.getAFun();
        	return factory.makeAppl(afun,vargs);
        } else
        	return Functions.checkStatic(name, vargs);
        
      case ATerm.LIST :
        ATermList lst = TBTermFactory.makeList();
        ATermList tlst = (ATermList) t;
        for (int i = tlst.getLength() - 1; i >= 0; i--) {
          lst = lst.insert(checkType(tlst.elementAt(i), env, quoted));
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
	for( ; !lst.isEmpty(); lst = lst.getNext()){
		if(!compatibleTypes(lst.getFirst(), elmtype))
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
 	if(TBTermFactory.isVar(t1))
 		t1 = ((TBTermVar)t1).getVarType();
 	
 	if(t2.getType() == ATerm.PLACEHOLDER)
  		t2 = ((ATermPlaceholder) t2).getPlaceholder();
	if(TBTermFactory.isVar(t2) || TBTermFactory.isResVar(t2))
 		t2 = ((TBTermVar)t2).getVarType();
 	
  	if(t1.equals(t2))
  		return true;
  	
  	if(t1.equals(TBTermFactory.TermType) || t2.equals(TBTermFactory.TermType))
  		return true;
  	
  	switch(t1.getType()){
    case ATerm.INT :
    	return t2.equals(TBTermFactory.IntType);
    case ATerm.REAL :
    	return t2.equals(TBTermFactory.RealType);
    
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
	    	} else if(t2.getType() == ATerm.INT && t1.equals(TBTermFactory.IntType))
	    		return true;
			else if(t2.getType() == ATerm.REAL && t1.equals(TBTermFactory.RealType))
					return true;
			else
	    		return false;
	  	}
  
       	ATermAppl ap2 = (ATermAppl) t2;
    	//System.err.println("compatibleType: ap1.getName() = " + ap1.getName() + ";" + "ap2.getName() = " + ap2.getName());
    	if(t1.equals(TBTermFactory.StrType) && ap2.getArity() == 0 && ap2.isQuoted())
    		return true;
       	if(t2.equals(TBTermFactory.StrType) && ap1.getArity() == 0 && ap1.isQuoted())
    		return true;
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
    		for( ; !lst1.isEmpty(); lst1 = lst1.getNext(), lst2 = lst2.getNext()){
    			if(!compatibleTypes(lst1.getFirst(), lst2.getFirst()))
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
