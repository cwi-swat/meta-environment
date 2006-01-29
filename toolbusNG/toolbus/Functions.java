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
      if (argtypes[i] == TBTerm.BoolType) {
        if (!TBTerm.isBoolean(actual[i]))
          throw new ToolBusException("arg #" + i + " of " + name + " should be boolean");
      } else if (argtypes[i] == TBTerm.IntType) {
        if (!(actual[i] instanceof ATermInt))
          throw new ToolBusException("arg #" + i + " of " + name + " should be integer");
      } else if (argtypes[i] == TBTerm.RealType) {
        if (!(actual[i] instanceof ATermReal))
          throw new ToolBusException("arg #" + i + " of " + name + " should be real");
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
    
    define(new FunctionDescriptor("is-int", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isInt(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("is-real", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isReal(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("is-str", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isStr(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    // is-bstr
    
    define(new FunctionDescriptor("is-appl", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isAppl(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("is-list", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.isList(args[0]) ? TBTerm.True : TBTerm.False;
        }
      });
    
    define(new FunctionDescriptor("is-empty", TBTerm.TermType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return TBTerm.True;
          //}
          if(TBTerm.isList(args[0])){
          	if(((ATermList) args[0]).getLength() == 0)
          		return  TBTerm.True;
          }
          return TBTerm.False;
        }
      });
    
    // is-var, see method eval
    // is-result-var, see method eval
    // TODO: is-formal
    
    define(new FunctionDescriptor("fun", TBTerm.TermType, TBTerm.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	String fname  = ((ATermAppl) args[0]).getName();
          return TBTerm.factory.make("<str>", fname);
        }
      });
    
    define(new FunctionDescriptor("args", TBTerm.TermType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.getArgs(args[0]);
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
        ATerm res = (args[0] == args[1]) ? TBTerm.True : TBTerm.False;
      	//System.err.println("equal: " + args[0] + " == " + args[1] + " ==> " + res);
      	return res;
      }
    });

    define(new FunctionDescriptor("not-equal", TBTerm.TermType, TBTerm.TermType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        ATerm res = (args[0] != args[1]) ? TBTerm.True : TBTerm.False;
    	//System.err.println("not-equal: " + args[0] + " == " + args[1] + " ==> " + res);
      	return res;
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
      
      define(new FunctionDescriptor("abs", TBTerm.IntType, TBTerm.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeInt(Math.abs(((ATermInt) args[0]).getInt()));
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
    
    define(new FunctionDescriptor("radd", TBTerm.RealType, TBTerm.RealType, TBTerm.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(((ATermReal) args[0]).getReal() + ((ATermReal) args[1]).getReal());
        }
      });
    
      define(new FunctionDescriptor("rsub", TBTerm.RealType, TBTerm.RealType, TBTerm.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(((ATermReal) args[0]).getReal() - ((ATermReal) args[1]).getReal());
        }
      });

      define(new FunctionDescriptor("rmul", TBTerm.RealType, TBTerm.RealType, TBTerm.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(((ATermReal) args[0]).getReal() * ((ATermReal) args[1]).getReal());
        }
      });
      define(new FunctionDescriptor("rdiv", TBTerm.RealType, TBTerm.RealType, TBTerm.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
         return factory.makeReal(((ATermReal) args[0]).getReal() / ((ATermReal) args[1]).getReal());
        }
      });
      
      define(new FunctionDescriptor("rless", TBTerm.RealType, TBTerm.RealType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermReal) args[0]).getReal() < ((ATermReal) args[1]).getReal() ? TBTerm.True : TBTerm.False;
        }
      });
      define(new FunctionDescriptor("rless-equal", TBTerm.RealType, TBTerm.RealType, TBTerm.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
            return ((ATermReal) args[0]).getReal() <= ((ATermReal) args[1]).getReal() ? TBTerm.True : TBTerm.False ;
        }
      });
     
    define(new FunctionDescriptor("rgreater", TBTerm.RealType, TBTerm.RealType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermReal) args[0]).getReal() > ((ATermReal) args[1]).getReal() ? TBTerm.True : TBTerm.False ;
      }
    });
    define(new FunctionDescriptor("rgreater-equal", TBTerm.RealType, TBTerm.RealType, TBTerm.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermReal) args[0]).getReal() >= ((ATermReal) args[1]).getReal() ? TBTerm.True : TBTerm.False ;
      }
    });
  
    // sin, cos, atan atan2 exp log log10 sqrt
    
    define(new FunctionDescriptor("rabs", TBTerm.RealType, TBTerm.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return factory.makeReal(Math.abs(((ATermReal) args[0]).getReal()));
        }
      });
    
    define(new FunctionDescriptor("size", TBTerm.ListType, TBTerm.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return factory.makeInt(0);
          //}
          return factory.makeInt(TBTerm.size(args[0]));
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
    define(new FunctionDescriptor("get", TBTerm.ListType,TBTerm.TermType, TBTerm.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.get(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor("put", TBTerm.ListType,TBTerm.TermType, TBTerm.TermType, TBTerm.ListType ) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.put(args[0],args[1], args[2]);
        }
      });
    
    
    define(new FunctionDescriptor("first", TBTerm.ListType, TBTerm.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return null;
         //}
          return TBTerm.first(args[0]);
        }
      });
    define(new FunctionDescriptor("next", TBTerm.ListType, TBTerm.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	//if(args[0] == null){
        	//	return null;
        	//}
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
    
    // functions

    define(new FunctionDescriptor("process-id", TBTerm.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return TBTerm.factory.makeInt(pi.getProcessId());
        }
      });
    
    define(new FunctionDescriptor("process-name", TBTerm.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	AFun afun = factory.makeAFun(pi.getProcessName(),0,true);
        	return factory.makeAppl(afun);
        }
      });
    
    // quote
    // current-time
    define(new FunctionDescriptor("current-time", TBTerm.IntType) {
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

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t))
          return env.getValue(t);
        if (TBTerm.isBoolean(t))
          return t;
        if (TBTerm.isStr(t))
        		return t;
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (fun == "quote"){ // TODO: check # of args
        	//System.err.println("quote: " + t + " ==> " + TBTerm.substitute(args[0], env));
    		return TBTerm.substitute(args[0], env);
        }
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
        return TBTerm.IntType;

      case ATerm.PLACEHOLDER :
		return ((ATermPlaceholder) t).getPlaceholder();

      case ATerm.REAL :
        return TBTerm.RealType;

      case ATerm.APPL :
    	ATermAppl apt = (ATermAppl) t;
        if (TBTerm.isVar(apt)) {
          ATerm res = TBTerm.getVarType(apt);
          return res;
        }
        if (TBTerm.isBoolean(apt)) {
          return TBTerm.BoolType;
        }
        if (apt.isQuoted() && apt.getArity() == 0) {
          return TBTerm.StrType;
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
        ATermList lst = TBTerm.factory.makeList();
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
 	if(TBTerm.isVar(t1) || TBTerm.isResVar(t1))
 		t1 = TBTerm.getVarType(t1);
 	
 	if(t2.getType() == ATerm.PLACEHOLDER)
  		t2 = ((ATermPlaceholder) t2).getPlaceholder();
	if(TBTerm.isVar(t2) || TBTerm.isResVar(t2))
 		t2 = TBTerm.getVarType(t2);
 	
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
    	//System.err.println("compatibleType: ap1.getName() = " + ap1.getName() + ";" + "ap2.getName() = " + ap2.getName());
    	if(t1.equals(TBTerm.StrType) && ap2.getArity() == 0 && ap2.isQuoted())
    		return true;
       	if(t2.equals(TBTerm.StrType) && ap1.getArity() == 0 && ap1.isQuoted())
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
