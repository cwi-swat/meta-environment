/**
 * @author paulk, Jul 18, 2002
 */

package toolbus;
import java.util.Hashtable;

import toolbus.process.ProcessInstance;

import aterm.*;
import aterm.pure.PureFactory;

class FunctionDescriptor {
  private String name;
  private int index;
  private int nargs;
  private ATerm argtypes[];
  private ATerm resultType;

  public FunctionDescriptor(String name, int index, ATerm resultType) {
    this.name = name;
    this.index = index;
    this.resultType = resultType;
    nargs = 0;
    argtypes = new ATerm[0];
  }

  public FunctionDescriptor(String name, int index, ATerm arg0, ATerm resultType) {
    this.name = name;
    this.index = index;
    this.resultType = resultType;
    nargs = 1;
    argtypes = new ATerm[1];
    argtypes[0] = arg0;
  }

  public FunctionDescriptor(String name, int index, ATerm arg0, ATerm arg1, ATerm resultType) {
    this.name = name;
    this.index = index;
    this.resultType = resultType;
    nargs = 2;
    argtypes = new ATerm[2];
    argtypes[0] = arg0;
    argtypes[1] = arg1;
  }

  public int getIndex() {
    return index;
  }

  public ATerm getResultType() {
    return resultType;
  }

  public boolean checkStatic(ATerm actual[]) throws ToolBusException {
    //    System.err.println("checkStatic: " + name);
    //    for(int i = 0; i < actual.length; i++){
    //        System.err.println("actual[" + i + "] = " + actual[i]);
    //        System.err.println("argtypes[" + i + "] = " + argtypes[i]);   
    //    }
    if (argtypes.length != actual.length)
      throw new ToolBusException(name + " has wrong number of arguments");
    for (int i = 0; i < argtypes.length; i++) {
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
}

public class TBTerm {

  public static ATermFactory factory;
  public static ATerm True;
  public static ATerm False;
  public static ATerm BoolType;
  public static ATerm IntType;
  public static ATerm RealType;
  public static ATerm StrType;
  public static ATerm TermType;
  public static ATerm ListType;

  public static ATerm VoidType; // for the benefit of JavaTools

  public static ATerm BoolPlaceholder;
  public static ATerm IntPlaceholder;
  public static ATerm RealPlaceholder;
  public static ATerm StrPlaceholder;
  public static ATerm TermPlaceholder;
  public static ATerm ListPlaceholder;

  private static Hashtable Funs = new Hashtable();

  public static final int Not = 0;
  public static final int And = 1;
  public static final int Or = 2;
  public static final int Equal = 3;
  public static final int NotEqual = 4;
  public static final int Greater = 5;
  public static final int GreaterEqual = 6;
  public static final int Less = 7;
  public static final int LessEqual = 8;
  public static final int Abs = 9;
  public static final int Add = 10;
  public static final int Sub = 11;
  public static final int Mul = 13;
  public static final int Div = 14;
  public static final int Mod = 15;

  public static final int processId = 16;
  
  public static void init(){
    factory = new PureFactory();
  }

  public static void init(ATermFactory fact) {
    factory = fact;
    True = factory.make("true");
    False = factory.make("false");
    BoolType = factory.make("bool");
    IntType = factory.make("int");
    RealType = factory.make("real");
    StrType = factory.make("str");
    TermType = factory.make("term");
    ListType = factory.make("list");

    VoidType = factory.make("void");

    BoolPlaceholder = factory.makePlaceholder(BoolType);
    IntPlaceholder = factory.makePlaceholder(IntType);
    RealPlaceholder = factory.makePlaceholder(RealType);

    StrPlaceholder = factory.makePlaceholder(StrType);
    TermPlaceholder = factory.makePlaceholder(TermType);
    ListPlaceholder = factory.makePlaceholder(ListType);

    Funs.put("not", new FunctionDescriptor("not", Not, BoolType, BoolType));
    Funs.put("and", new FunctionDescriptor("and", And, BoolType, BoolType, BoolType));
    Funs.put("or", new FunctionDescriptor("or", Or, BoolType, BoolType, BoolType));
    Funs.put("equal", new FunctionDescriptor("equal", Equal, TermType, TermType, BoolType));
    Funs.put("not-equal", new FunctionDescriptor("not-equal", NotEqual, TermType, TermType, BoolType));
    Funs.put("greater", new FunctionDescriptor("greater", Greater, IntType, IntType, BoolType));
    Funs.put("greater-equal", new FunctionDescriptor("greater-equal", GreaterEqual, IntType, IntType, BoolType));
    Funs.put("less", new FunctionDescriptor("less", Less, IntType, IntType, BoolType));
    Funs.put("less-equal", new FunctionDescriptor("less-equal", LessEqual, IntType, IntType, BoolType));

    Funs.put("abs", new FunctionDescriptor("abs", Abs, IntType, IntType));
    Funs.put("add", new FunctionDescriptor("add", Add, IntType, IntType, IntType));
    Funs.put("sub", new FunctionDescriptor("sub", Sub, IntType, IntType, IntType));
    Funs.put("mul", new FunctionDescriptor("mul", Mul, IntType, IntType, IntType));
    Funs.put("div", new FunctionDescriptor("div", Div, IntType, IntType, IntType));
    Funs.put("mod", new FunctionDescriptor("mod", Mod, IntType, IntType, IntType));

    Funs.put("processId", new FunctionDescriptor("processId", processId, TermType));
  }

  public static boolean isTrue(ATerm t) {
    return t == True;
  }

  public static boolean isFalse(ATerm t) {
    return t == False;
  }

  public static boolean isBoolean(ATerm t) {
    return t == True || t == False;
  }

  public static boolean isResVar(ATerm t) {
    return t.getType() == ATerm.APPL && ((ATermAppl) t).getName() == "rvar";
  }

  public static boolean isVar(ATerm t) {
    return t.getType() == ATerm.APPL && ((ATermAppl) t).getName() == "var";
  }

  private static ATermList getVarArgs(ATerm t) {
    if (t.getType() == ATerm.APPL) {
      ATermAppl appl = (ATermAppl) t;
      if (appl.getName() == "var" || appl.getName() == "rvar") {
        return appl.getArguments(); // check length?
      }
    }
    throw new ToolBusInternalError("illegal var in getVarIndex(" + t + ")");
  }

  public static int getVarIndex(ATerm t) {
    return ((ATermInt) getVarArgs(t).getFirst()).getInt();
  }

  public static ATerm getVarType(ATerm t) {
    return getVarArgs(t).elementAt(1);
  }

  public static String getVarName(ATerm t) {
    return ((ATermAppl) getVarArgs(t).elementAt(2)).getName();
  }

  public static ATerm setVarIndexAndType(ATerm t, int n, ATerm type) {
    //System.out.println("setVarIndex(" + t + ", " + n + ")");
    ATermList args = ((ATermAppl) t).getArguments();
    if (((ATermInt) args.getFirst()).getInt() < 0) {
      ATerm varname = args.getLast();
      if (isVar(t))
        return TBTerm.factory.make("var(<int>,<term>,<term>)", new Integer(n), type, varname);
      else
        return TBTerm.factory.make("rvar(<int>,<term>,<term>)", new Integer(n), type, varname);
    } else
      return t;
  }

  public static ATerm changeResVarIntoVar(ATerm t) {
    if (!isResVar(t)) {
      throw new ToolBusInternalError("wrong arg in makeVar(" + t + ")");
    }
    ATermList args = ((ATermAppl) t).getArguments();
    AFun afun = t.getFactory().makeAFun("var", args.getLength(), false);
    return t.getFactory().makeAppl(afun, args);
  }

  public static ATerm compileVars(ATerm t, Environment env) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t))
          return setVarIndexAndType(t, env.getVarIndex(t), env.getVarType(t));

        AFun afun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        ATerm cargs[] = new ATerm[args.length];
        if (args.length == 0)
          return t;
        for (int i = 0; i < args.length; i++) {
          cargs[i] = compileVars(args[i], env);
        }
        return t.getFactory().makeAppl(afun, cargs);

      case ATerm.LIST :
        ATermList lst = t.getFactory().makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          lst = lst.append(compileVars(((ATermList) t).elementAt(i), env));
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in compileVars: " + t);
  }

  public static ATerm checkType(ATerm t, Environment env) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB : // ??
      case ATerm.INT :
        return IntType;
      case ATerm.PLACEHOLDER : // ??
      case ATerm.REAL :
        return RealType;

      case ATerm.APPL :
        if (TBTerm.isVar(t)) {
          ATerm res = TBTerm.getVarType(t);
          //System.out.println("getType(" + t + ") => " + res);
          return res;
        }
        if (TBTerm.isBoolean(t))
          return BoolType;
        String fun = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        //        if (args.length == 0)
        //          return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = checkType(args[i], env);
        }

        FunctionDescriptor fd = (FunctionDescriptor) Funs.get(fun);
        if (fd == null)
          throw new ToolBusException("unknown function " + fun);

        if (fd.checkStatic(vargs))
          return fd.getResultType();

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(checkType(((ATermList) t).elementAt(i), env), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in getType: " + t);
  }

  public static boolean checkCompatible(ATerm req, ATerm given) {
    //System.out.println("checkCompatible(" + req + ", " + given + ")");
    if (req.getType() != given.getType()) {
      return false;
    }
    switch (req.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return true;

      case ATerm.APPL :
        if (given == TermType) {
          return true;
        }
        if (!((ATermAppl) req).getName().equals(((ATermAppl) given).getName())) {
          return false;
        }
        ATerm reqargs[] = ((ATermAppl) req).getArgumentArray();
        ATerm givenargs[] = ((ATermAppl) given).getArgumentArray();

        if (reqargs.length != givenargs.length) {
          return false;
        }
        for (int i = 0; i < reqargs.length; i++) {
          if (!checkCompatible(reqargs[i], givenargs[i])) {
            return false;
          }
        }
        return true;

      case ATerm.LIST :
        if (((ATermList) req).getLength() != ((ATermList) given).getLength()) {
          return false;
        }
        for (int i = 0; i < ((ATermList) req).getLength(); i++) {
          if (!checkCompatible(((ATermList) req).elementAt(i), ((ATermList) given).elementAt(i))) {
            return false;
          }
        }
        return true;
    }
    return false;
  }

  private static ATerm makePlaceholder(ATerm t) {
    return factory.makePlaceholder(t);
  }

  public static ATerm makePattern(ATerm t, Environment env, boolean recurring) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB : // ??
      case ATerm.INT :
        return IntPlaceholder;
      case ATerm.PLACEHOLDER :
        return t;
      case ATerm.REAL :
        return RealPlaceholder;

      case ATerm.APPL :
        if (TBTerm.isVar(t)) {
          ATerm type = TBTerm.getVarType(t);
          return makePlaceholder(type);
        }
        if (TBTerm.isBoolean(t))
          return BoolPlaceholder;

        AFun fun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (args.length == 0) {
          if (fun.isQuoted())
            return StrPlaceholder;
          else
            return t;
        }
        if (!recurring)
          return makePlaceholder(t);
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = makePattern(args[i], env, false);
        }
        return factory.makeAppl(fun, vargs);

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(makePattern(((ATermList) t).elementAt(i), env, true), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in getType: " + t);
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
          return env.getVar(t);
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

  public static ATerm substitute(ATerm t, Environment env) throws ToolBusException {
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t)) {
          return env.getVar(t);
        }
        if (TBTerm.isBoolean(t)) {
          return t;
        }
        AFun afun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (args.length == 0)
          return t;
        ATerm vargs[] = new ATerm[args.length];
        for (int i = 0; i < args.length; i++) {
          vargs[i] = substitute(args[i], env);
        }
        return factory.makeAppl(afun, vargs);

      case ATerm.LIST :
        ATermList lst = factory.makeList();
        for (int i = ((ATermList) t).getLength() - 1; i >= 0; i--) {
          lst = factory.makeList(substitute(((ATermList) t).elementAt(i), env), lst);
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in substitute: " + t);
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

    switch (fd.getIndex()) {

      case Not :
        return args[0] == True ? False : True;
      case And :
        return (args[0] == True) && (args[1] == True) ? True : False;
      case Or :
        return (args[0] == True) || (args[1] == True) ? True : False;
      case Equal :
        return (args[0] == args[1]) ? True : False;
      case NotEqual :
        return (args[0] != args[1]) ? True : False;
      case Greater :
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? True : False;
      case GreaterEqual :
        return ((ATermInt) args[0]).getInt() >= ((ATermInt) args[1]).getInt() ? True : False;
      case Less :
        return ((ATermInt) args[0]).getInt() < ((ATermInt) args[1]).getInt() ? True : False;
      case LessEqual :
        return ((ATermInt) args[0]).getInt() > ((ATermInt) args[1]).getInt() ? True : False;
      case Add :
        return factory.makeInt(((ATermInt) args[0]).getInt() + ((ATermInt) args[1]).getInt());
      case Sub :
        return factory.makeInt(((ATermInt) args[0]).getInt() - ((ATermInt) args[1]).getInt());
      case Mul :
        return factory.makeInt(((ATermInt) args[0]).getInt() * ((ATermInt) args[1]).getInt());
      case Div :
        return factory.makeInt(((ATermInt) args[0]).getInt() / ((ATermInt) args[1]).getInt());
      case Mod :
        return factory.makeInt(((ATermInt) args[0]).getInt() % ((ATermInt) args[1]).getInt());
      case Abs :
        return factory.makeInt(Math.abs(((ATermInt) args[0]).getInt()));

      case processId :
        return process.getProcessId();
    }
    throw new ToolBusInternalError("unknown function : " + fun);
  }

  private static Environment enva;
  private static Environment envb;
  private static MatchEnvironment menva;
  private static MatchEnvironment menvb;
  private static boolean fullMatch = true;

  public static MatchResult match(ATerm ta, Environment enva, ATerm tb, Environment envb) throws ToolBusException {
    TBTerm.enva = enva;
    TBTerm.envb = envb;
    menva = new MatchEnvironment();
    menvb = new MatchEnvironment();
    fullMatch = true;
    boolean res = performMatch(ta, tb);
    return new MatchResult(res, menva, menvb);
  }

  public static boolean mightMatch(ATerm ta, ATerm tb) {
    //System.out.println("mightMatch(" + ta +", " + tb + ")");
    fullMatch = false;
    try {
      return performMatch(ta, tb);
    } catch (ToolBusException e) {
      throw new ToolBusInternalError(e.getMessage());
    }
  }

  private static boolean performMatch(ATerm ta, ATerm tb) throws ToolBusException {
    if (TBTerm.isVar(ta))
      if (fullMatch) {
        ta = enva.getVar(ta);
      } else {
        return true;
      }

    if (TBTerm.isResVar(tb))
      if (fullMatch) {
        tb = envb.getVar(tb);
      } else {
        return true;
      }

    if (TBTerm.isResVar(ta)) {
      if (fullMatch) {
        menva.putResVar(ta, tb);
      }
      return true;
    }

    if (TBTerm.isResVar(tb)) {
      if (fullMatch) {
        menvb.putResVar(tb, ta);
      }
      return true;
    }

    switch (ta.getType()) {
      case ATerm.BLOB :
        return ta.equals(tb); // || (tb == TBTerm.BlobPlaceholder);

      case ATerm.INT :
        return ta.equals(tb) || (tb == TBTerm.IntPlaceholder);

      case ATerm.REAL :
        return ta.equals(tb) || (tb == TBTerm.RealPlaceholder);

      case ATerm.PLACEHOLDER :
        if (ta == IntPlaceholder && tb.getType() == ATerm.INT)
          return true;
        else if (ta == RealPlaceholder && tb.getType() == ATerm.REAL)
          return true;
        else if (ta == StrPlaceholder && tb.getType() == ATerm.APPL && ((ATermAppl) tb).getArity() == 0)
          return true;
        else if (ta == ListPlaceholder && tb.getType() == ATerm.LIST)
          return true;
        else if (ta == TBTerm.TermPlaceholder)
          return true;
        else
          return false;

      case ATerm.APPL :
        if (tb.getType() == ATerm.PLACEHOLDER) {
          if (tb == StrPlaceholder && ((ATermAppl) ta).getArity() == 0)
            return true;
          else if (tb == TermPlaceholder)
            return true;
          else
            return false;
        }
        if (tb.getType() != ATerm.APPL
          || ((ATermAppl) ta).getName() != ((ATermAppl) tb).getName()
          || ((ATermAppl) ta).getArity() != ((ATermAppl) tb).getArity())
          return false;
        else {
          ATerm a_args[] = ((ATermAppl) ta).getArgumentArray();
          ATerm b_args[] = ((ATermAppl) tb).getArgumentArray();
          for (int i = 0; i < a_args.length; i++) {
            if (!performMatch(a_args[i], b_args[i]))
              return false;
          }
          return true;
        }

      case ATerm.LIST :
        if (tb == ListPlaceholder) {
          return true;
        }
        if (((ATermList) ta).getLength() != ((ATermList) tb).getLength())
          return false;
        else {
          for (int i = 0; i < ((ATermList) ta).getLength(); i++) {
            if (!performMatch(((ATermList) ta).elementAt(i), ((ATermList) tb).elementAt(i)))
              return false;
          }
          return true;
        }
      default :
        throw new ToolBusInternalError("illegal ATerm in match1: " + ta);
    }
  }

}
