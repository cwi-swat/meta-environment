package toolbus;

import java.util.Hashtable;

import toolbus.process.ProcessInstance;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.ATermReal;

abstract class FunctionDescriptor {
  private TBTermFactory tbfactory;
  private String name;
  private ATerm argtypes[];
  private ATerm resultType;

  public FunctionDescriptor(TBTermFactory tbfactory, String name, ATerm resultType) {
	this.tbfactory = tbfactory;
    this.name = name;
    this.resultType = resultType;
    argtypes = new ATerm[0];
  }

  public FunctionDescriptor(TBTermFactory tbfactory, String name, ATerm arg0, ATerm resultType) {
	this.tbfactory = tbfactory;
    this.name = name;
    this.resultType = resultType;
    argtypes = new ATerm[1];
    argtypes[0] = arg0;
  }

  public FunctionDescriptor(TBTermFactory tbfactory, String name, ATerm arg0, ATerm arg1, ATerm resultType) {
	this.tbfactory = tbfactory;
    this.name = name;
    this.resultType = resultType;
    argtypes = new ATerm[2];
    argtypes[0] = arg0;
    argtypes[1] = arg1;
  }
  
  public FunctionDescriptor(TBTermFactory tbfactory, String name, ATerm arg0, ATerm arg1, ATerm arg2, ATerm resultType) {
	this.tbfactory = tbfactory;
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
      if (argtypes[i] == tbfactory.BoolType) {
        if (!tbfactory.isBoolean(actual[i]))
          throw new ToolBusException("arg #" + i + " of " + name + " should be boolean");
      } else if (argtypes[i] == tbfactory.IntType) {
        if (!(actual[i] instanceof ATermInt))
          throw new ToolBusException("arg #" + i + " of " + name + " should be integer");
      } else if (argtypes[i] == tbfactory.RealType) {
        if (!(actual[i] instanceof ATermReal))
          throw new ToolBusException("arg #" + i + " of " + name + " should be real");
      } else if (argtypes[i] == tbfactory.StrType){
    	if (!(actual[i] instanceof ATermAppl) || ((ATermAppl)actual[i]).getArity() > 0){
    	   throw new ToolBusException("arg #" + i + " of " + name + " should be string");  
    	  }
      } else if (argtypes[i] == tbfactory.TermType) {
      } else if (argtypes[i] == tbfactory.ListType) {
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
  private static Hashtable<String,FunctionDescriptor> Funs;
  private static TBTermFactory tbfactory;

  public static void init(TBTermFactory tbfac) {
	tbfactory = tbfac;
    Funs = new Hashtable<String,FunctionDescriptor>();
    defineFuns();
  }

  /**
   *  Declaration
   */

  private static void define(FunctionDescriptor fd) {
    Funs.put(fd.getName(), fd);
  }

  protected static void defineFuns() {
  	
    define(new FunctionDescriptor(tbfactory, "is-bool", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.isBoolean(args[0]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "is-int", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.isInt(args[0]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "is-real", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.isReal(args[0]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "is-str", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.isStr(args[0]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    // is-bstr
    
    define(new FunctionDescriptor(tbfactory, "is-appl", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.isAppl(args[0]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "is-list", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.isList(args[0]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "is-empty", tbfactory.TermType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return tbfactory.True;
          //}
          if(tbfactory.isList(args[0])){
          	if(((ATermList) args[0]).getLength() == 0)
          		return  tbfactory.True;
          }
          return tbfactory.False;
        }
      });
    
    // is-var, see method eval
    // is-result-var, see method eval
    // TODO: is-formal
    
    define(new FunctionDescriptor(tbfactory, "fun", tbfactory.TermType, tbfactory.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	String fname  = ((ATermAppl) args[0]).getName();
          return tbfactory.make("<str>", fname);
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "args", tbfactory.TermType, tbfactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.getArgs(args[0]);
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "true", tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.True;
        }
      });

      define(new FunctionDescriptor(tbfactory, "false", tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.False;
        }
      });
      
    define(new FunctionDescriptor(tbfactory, "not", tbfactory.BoolType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return args[0] == tbfactory.True ? tbfactory.False : tbfactory.True;
      }
    });
    
    define(new FunctionDescriptor(tbfactory, "and", tbfactory.BoolType, tbfactory.BoolType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == tbfactory.True) && (args[1] == tbfactory.True) ? tbfactory.True : tbfactory.False;
      }
    });
    
    define(new FunctionDescriptor(tbfactory, "or", tbfactory.BoolType, tbfactory.BoolType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return (args[0] == tbfactory.True) || (args[1] == tbfactory.True) ? tbfactory.True : tbfactory.False;
      }
    });
    
    define(new FunctionDescriptor(tbfactory, "equal", tbfactory.TermType, tbfactory.TermType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        ATerm res = (args[0] == args[1]) ? tbfactory.True : tbfactory.False;
      	//System.err.println("equal: " + args[0] + " == " + args[1] + " ==> " + res);
      	return res;
      }
    });

    define(new FunctionDescriptor(tbfactory, "not-equal", tbfactory.TermType, tbfactory.TermType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        ATerm res = (args[0] != args[1]) ? tbfactory.True : tbfactory.False;
    	//System.err.println("not-equal: " + args[0] + " == " + args[1] + " ==> " + res);
      	return res;
      }
    });
    
    define(new FunctionDescriptor(tbfactory, "add", tbfactory.IntType, tbfactory.IntType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(((ATermInt) args[0]).getInt() + ((ATermInt) args[1]).getInt());
        }
      });
    
      define(new FunctionDescriptor(tbfactory, "sub", tbfactory.IntType, tbfactory.IntType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(((ATermInt) args[0]).getInt() - ((ATermInt) args[1]).getInt());
        }
      });

      define(new FunctionDescriptor(tbfactory, "mul", tbfactory.IntType, tbfactory.IntType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(((ATermInt) args[0]).getInt() * ((ATermInt) args[1]).getInt());
        }
      });
      define(new FunctionDescriptor(tbfactory, "div", tbfactory.IntType, tbfactory.IntType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(((ATermInt) args[0]).getInt() / ((ATermInt) args[1]).getInt());
        }
      });
      
      define(new FunctionDescriptor(tbfactory, "mod", tbfactory.IntType, tbfactory.IntType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(((ATermInt) args[0]).getInt() % ((ATermInt) args[1]).getInt());
        }
      });
      
      define(new FunctionDescriptor(tbfactory, "abs", tbfactory.IntType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(Math.abs(((ATermInt) args[0]).getInt()));
        }
      });
      
      define(new FunctionDescriptor(tbfactory, "less", tbfactory.IntType, tbfactory.IntType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermInt) args[0]).getInt() < ((ATermInt) args[1]).getInt() ? tbfactory.True : tbfactory.False;
        }
      });
      define(new FunctionDescriptor(tbfactory, "less-equal", tbfactory.IntType, tbfactory.IntType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermInt) args[0]).getInt() <= ((ATermInt) args[1]).getInt() ? tbfactory.True : tbfactory.False;
        }
      });
     
    define(new FunctionDescriptor(tbfactory, "greater", tbfactory.IntType, tbfactory.IntType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? tbfactory.True : tbfactory.False;
      }
    });
    define(new FunctionDescriptor(tbfactory, "greater-equal", tbfactory.IntType, tbfactory.IntType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermInt) args[0]).getInt() >= ((ATermInt) args[1]).getInt() ? tbfactory.True : tbfactory.False;
      }
    });
    
    define(new FunctionDescriptor(tbfactory, "radd", tbfactory.RealType, tbfactory.RealType, tbfactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeReal(((ATermReal) args[0]).getReal() + ((ATermReal) args[1]).getReal());
        }
      });
    
      define(new FunctionDescriptor(tbfactory, "rsub", tbfactory.RealType, tbfactory.RealType, tbfactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeReal(((ATermReal) args[0]).getReal() - ((ATermReal) args[1]).getReal());
        }
      });

      define(new FunctionDescriptor(tbfactory, "rmul", tbfactory.RealType, tbfactory.RealType, tbfactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeReal(((ATermReal) args[0]).getReal() * ((ATermReal) args[1]).getReal());
        }
      });
      define(new FunctionDescriptor(tbfactory, "rdiv", tbfactory.RealType, tbfactory.RealType, tbfactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
         return tbfactory.makeReal(((ATermReal) args[0]).getReal() / ((ATermReal) args[1]).getReal());
        }
      });
      
      define(new FunctionDescriptor(tbfactory, "rless", tbfactory.RealType, tbfactory.RealType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return ((ATermReal) args[0]).getReal() < ((ATermReal) args[1]).getReal() ? tbfactory.True : tbfactory.False;
        }
      });
      define(new FunctionDescriptor(tbfactory, "rless-equal", tbfactory.RealType, tbfactory.RealType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
            return ((ATermReal) args[0]).getReal() <= ((ATermReal) args[1]).getReal() ? tbfactory.True : tbfactory.False ;
        }
      });
     
    define(new FunctionDescriptor(tbfactory, "rgreater", tbfactory.RealType, tbfactory.RealType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermReal) args[0]).getReal() > ((ATermReal) args[1]).getReal() ? tbfactory.True : tbfactory.False ;
      }
    });
    define(new FunctionDescriptor(tbfactory, "rgreater-equal", tbfactory.RealType, tbfactory.RealType, tbfactory.BoolType) {
      public ATerm apply(ATerm args[], ProcessInstance pi) {
        return ((ATermReal) args[0]).getReal() >= ((ATermReal) args[1]).getReal() ? tbfactory.True : tbfactory.False ;
      }
    });
  
    // sin, cos, atan atan2 exp log log10 sqrt
    
    define(new FunctionDescriptor(tbfactory, "rabs", tbfactory.RealType, tbfactory.RealType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeReal(Math.abs(((ATermReal) args[0]).getReal()));
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "size", tbfactory.ListType, tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return factory.makeInt(0);
          //}
          return tbfactory.makeInt(tbfactory.size(args[0]));
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "index",tbfactory.ListType, tbfactory.IntType, tbfactory.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.index(args[0],((ATermInt) args[1]).getInt());
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "replace",tbfactory.ListType, tbfactory.IntType,tbfactory.TermType, tbfactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.replace(args[0],((ATermInt) args[1]).getInt(), args[2]);
        }
      });
    define(new FunctionDescriptor(tbfactory, "get",tbfactory.ListType, tbfactory.TermType, tbfactory.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.get(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "put",tbfactory.ListType, tbfactory.TermType, tbfactory.TermType, tbfactory.ListType ) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.put(args[0],args[1], args[2]);
        }
      });
    
    
    define(new FunctionDescriptor(tbfactory, "first", tbfactory.ListType, tbfactory.TermType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          //if(args[0] == null){
          //	return null;
         //}
          return tbfactory.first(args[0]);
        }
      });
    define(new FunctionDescriptor(tbfactory, "next", tbfactory.ListType, tbfactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	//if(args[0] == null){
        	//	return null;
        	//}
          return tbfactory.next(args[0]);
        }
      });
    define(new FunctionDescriptor(tbfactory, "member", tbfactory.TermType, tbfactory.ListType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.member(args[0], args[1]) ? tbfactory.True : tbfactory.False;
        }
      });
    define(new FunctionDescriptor(tbfactory, "subset",tbfactory.ListType, tbfactory.ListType, tbfactory.BoolType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.subset(args[0],args[1]) ? tbfactory.True : tbfactory.False;
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "diff",tbfactory.ListType, tbfactory.ListType, tbfactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.diff(args[0],args[1]);
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "inter",tbfactory.ListType, tbfactory.ListType, tbfactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.inter(args[0],args[1]);
        }
      });
    define(new FunctionDescriptor(tbfactory, "join",tbfactory.TermType, tbfactory.TermType, tbfactory.ListType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.join(args[0],args[1]);
        }
      });
    
    // functions

    define(new FunctionDescriptor(tbfactory, "process-id", tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
          return tbfactory.makeInt(pi.getProcessId());
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "process-name", tbfactory.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	AFun afun = tbfactory.makeAFun(pi.getProcessName(),0,true);
        	return tbfactory.makeAppl(afun);
        }
      });
    
    define(new FunctionDescriptor(tbfactory, "get-property", tbfactory.StrType, tbfactory.StrType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	ToolBus tb = pi.getToolBus();
        	String arg = ((ATermAppl) args[0]).getName();
        	String val = tb.get(arg);
        	if(val == null){
        		val ="";
        	}
        	AFun afun = tbfactory.makeAFun(val,0,true);
        	return tbfactory.makeAppl(afun);
        }
      });
    
    // quote
    // current-time
    define(new FunctionDescriptor(tbfactory, "current-time", tbfactory.IntType) {
        public ATerm apply(ATerm args[], ProcessInstance pi) {
        	int n = (int) pi.getRunTime();
        	return tbfactory.makeInt(n);
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
        if (tbfactory.isBoolean(t))
          return t;
        if (tbfactory.isStr(t))
        		return t;
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (fun == "quote"){ // TODO: check # of args
        	//System.err.println("quote: " + t + " ==> " + tbfactory.substitute(args[0], env));
    		return tbfactory.substitute(args[0], env);
        }
        if(fun == "is-var")
        	return tbfactory.isVar(args[0]) ? tbfactory.True : tbfactory.False;
        if(fun == "is-result-var")
        	return tbfactory.isResVar(args[0]) ? tbfactory.True : tbfactory.False; 
        if(args.length == 0 && !((fun == "process-id") || fun == "process-name"))
        		return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = eval(args[i], pi, env);
        }
        return apply(fun, vargs, pi);

      case ATerm.LIST :
        ATermList lst = tbfactory.makeList();
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
        return tbfactory.IntType;

      case ATerm.PLACEHOLDER :
		return ((ATermPlaceholder) t).getPlaceholder();

      case ATerm.REAL :
        return tbfactory.RealType;
        
      case TBTermFactory.VAR:
    	  return ((TBTermVar) t).getVarType();

      case ATerm.APPL :
    	ATermAppl apt = (ATermAppl) t;
     
        if (tbfactory.isBoolean(apt)) {
          return tbfactory.BoolType;
        }
        if (apt.isQuoted() && apt.getArity() == 0) {
          return tbfactory.StrType;
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
        	return tbfactory.makeAppl(afun,vargs);
        } else
        	return Functions.checkStatic(name, vargs);
        
      case ATerm.LIST :
        ATermList lst = tbfactory.makeList();
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
 	if(tbfactory.isVar(t1))
 		t1 = ((TBTermVar)t1).getVarType();
 	
 	if(t2.getType() == ATerm.PLACEHOLDER)
  		t2 = ((ATermPlaceholder) t2).getPlaceholder();
	if(tbfactory.isVar(t2) || tbfactory.isResVar(t2))
 		t2 = ((TBTermVar)t2).getVarType();
 	
  	if(t1.equals(t2))
  		return true;
  	
  	if(t1.equals(tbfactory.TermType) || t2.equals(tbfactory.TermType))
  		return true;
  	
  	switch(t1.getType()){
    case ATerm.INT :
    	return t2.equals(tbfactory.IntType);
    case ATerm.REAL :
    	return t2.equals(tbfactory.RealType);
    
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
	    	} else if(t2.getType() == ATerm.INT && t1.equals(tbfactory.IntType))
	    		return true;
			else if(t2.getType() == ATerm.REAL && t1.equals(tbfactory.RealType))
					return true;
			else
	    		return false;
	  	}
  
       	ATermAppl ap2 = (ATermAppl) t2;
    	//System.err.println("compatibleType: ap1.getName() = " + ap1.getName() + ";" + "ap2.getName() = " + ap2.getName());
    	if(t1.equals(tbfactory.StrType) && ap2.getArity() == 0 && ap2.isQuoted())
    		return true;
       	if(t2.equals(tbfactory.StrType) && ap1.getArity() == 0 && ap1.isQuoted())
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
