/**
 * @author paulk, Jul 18, 2002
 */

package toolbus;

import aterm.*;
import aterm.pure.PureFactory;

/**
 * TBTerm extends ATerms in several ways. This is achieved by staying with the ATerm representation
 * but giving a special meaning to some toolRequestAtoms. The extensions are:
 * - a number of standard terms (e.g., int, bool, str, list) and placeholders (e.g, <int>, <bool>< ...)
 * - the notion of variable (var) and result variable (rvar)
 * - special functions (add, greater, ...) that can be typechecked and evaluated
 *    (see FunctionDescriptors)
 * - matching and substitution
 */

public class TBTerm {

  public static ATermFactory factory;

  private static boolean initDone = false;

  public static ATerm True;
  public static ATerm False;
  public static ATerm BoolType;
  public static ATerm IntType;
  public static ATerm RealType;
  public static ATerm StrType;
  public static ATerm TermType;
  public static ATerm ListType;

  public static ATerm VoidType; // for the benefit of JavaTools
  
  public static ATerm Undefined;

  public static ATerm BoolPlaceholder;
  public static ATerm IntPlaceholder;
  public static ATerm RealPlaceholder;
  public static ATerm StrPlaceholder;
  public static ATerm TermPlaceholder;
  public static ATerm ListPlaceholder;

  public static ATerm TransactionIdVar;
  public static ATerm TransactionIdResVar;

  private static int nTransactions = 0;

  public static void init() {
    if (!initDone) {
      init(new PureFactory());
    }
    initDone = true;
  }

  private static void init(ATermFactory fact) {
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
    
    Undefined = factory.make("undefined");

    BoolPlaceholder = factory.makePlaceholder(BoolType);
    IntPlaceholder = factory.makePlaceholder(IntType);
    RealPlaceholder = factory.makePlaceholder(RealType);

    StrPlaceholder = factory.makePlaceholder(StrType);
    TermPlaceholder = factory.makePlaceholder(TermType);
    ListPlaceholder = factory.makePlaceholder(ListType);

    TransactionIdVar = factory.make("var(transaction,TransactionId))");
    TransactionIdResVar = factory.make("rvar(transaction,TransactionId))");

    Functions.init(factory);
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
  
  public static boolean isInt(ATerm t) {
  	return t.getType() == ATerm.INT;
  }
  
  public static boolean isStr(ATerm t) {
  	if(isAppl(t)){	
  	 return (((ATermAppl) t).isQuoted()) && ((ATermAppl) t).getArity() == 0;
  	} else
  		return false;
  }
  
  public static boolean isReal(ATerm t) {
 	 return (t.getType() == ATerm.REAL);
  }
  
  public static boolean isAppl(ATerm t) {
  	return t.getType() == ATerm.APPL;
  }
  
  public static boolean isList(ATerm t) {
  	return  t.getType() == ATerm.LIST;
  }
  
  public static ATerm getArgs(ATerm t) {
  	return ((ATermAppl) t).getArguments();
  }
  
  public static int size(ATerm l){
  	return ((ATermList) l).getLength();
  }
  
  public static ATerm first(ATerm l){
 	ATermList lst = (ATermList) l;
 	if(!lst.isEmpty()){
 		return lst.elementAt(0);
 	} else {
 		System.err.println("**** first on empty list ****");
 		return TBTerm.Undefined;
 	}
  }
  
  public static ATerm next(ATerm l){
  	ATermList lst = (ATermList) l;
  	if(lst.isEmpty()) {
  		return lst;
  	} else {
  		return lst.getNext();
  	}
  }
  
  public static boolean member(ATerm e, ATerm l){
  	ATermList lst = (ATermList) l;
    for (int i = 0; i < lst.getLength(); i++) {
      if(e.isEqual(lst.elementAt(i)))
      	return true;
    }
    return false;
  }
  
  public static boolean subset(ATerm l1, ATerm l2) {
  	ATermList lst1 = (ATermList) l1;
    for (int i = 0; i < lst1.getLength(); i++) {
    	ATerm e = lst1.elementAt(i);
    	if(!member(e, l2))
    	  return false;
    	else
    		l2 = delete(l2, e);
    }
    return true;
  }
  
  public static ATerm delete(ATerm l, ATerm e) {
 	ATermList lst = (ATermList) l;	
	ATermList res = factory.makeList();
	boolean found = false;
	for (int i = lst.getLength() - 1; i >= 0; i--) {
		ATerm e2 = lst.elementAt(i);
		if (e2.isEqual(e) && !found)
			found = true;
		else
			res = factory.makeList(e2, res);
	}
	return res;
	}
  
  public static ATerm diff(ATerm l1, ATerm l2) {
 	ATermList lst1 = (ATermList) l1;
 	ATermList res = factory.makeList();
    for (int i = lst1.getLength() - 1; i >= 0; i--) {
       	ATerm e = lst1.elementAt(i);
    	if(!member(e, l2))
    			res = factory.makeList(e, res);
    }
    //System.err.println("diff(" + l1 + ", " + l2 + ") ==> " + res);
    return res;
  }
  
  public static ATerm inter(ATerm l1, ATerm l2) {
 	ATermList lst1 = (ATermList) l1;
 	ATermList res = factory.makeList();
    for (int i = lst1.getLength() - 1; i >= 0; i--) {
       	ATerm e = lst1.elementAt(i);
    	if(member(e, l2))
    			res = factory.makeList(e, res);
    }
    //System.err.println("inter(" + l1 + ", " + l2 + ") ==> " + res);
    return res;
  }
  
  public static ATerm join(ATerm l1, ATerm l2) {
  	//if(l1 == null)
  	//	return l2;
  	//if(l2 == null)
  	//	return l1;
 	ATermList lst1 = isList(l1) ? (ATermList) l1 : factory.makeList(l1);
 	ATermList res = isList(l2) ? (ATermList) l2 : factory.makeList(l2);
    for (int i = lst1.getLength() - 1; i >= 0; i--) {
       	ATerm e = lst1.elementAt(i);
    	res = factory.makeList(e, res);
    }
    System.err.println("join(" + l1 + ", " + l2 + ") ==> " + res);
    return res;
  }
  
  public static ATerm index(ATerm l, int i) {
  	ATerm res = ((ATermList) l).elementAt(i - 1);
  	//System.err.println("index(" + l + ", " + i + ")==> " + res);
  	return res;
  }
  
  public static ATerm replace(ATerm l, int n, ATerm e) {
	ATermList lst = (ATermList) l;
	ATermList res = factory.makeList();
	for (int i = lst.getLength() - 1; i >= 0; i--) {
		ATerm elem = (i == n - 1) ? e : lst.elementAt(i);
		res = factory.makeList(elem, res);
    }
	return res;
  }
  
  public static ATerm put(ATerm l, ATerm k, ATerm v){
  	ATermList pair = factory.makeList(k, factory.makeList(v));
  	return factory.makeList(pair, (ATermList) l);
  }
  
  public static ATerm get(ATerm l, ATerm k){
  	ATermList lst = (ATermList) l;
  	for(ATermList pair = (ATermList) lst.getFirst(); !lst.isEmpty(); lst = lst.getNext()){
  		if(k.isEqual(pair.getFirst()))
  				return pair.getLast();
  	}
  	return TBTerm.Undefined;
  }

  public static ATerm mkAnyVar(String varKind, ATerm name, String processName, ATerm type) {
    AFun afun = factory.makeAFun(varKind, 2, false);
    String qname = name.toString() + "$" + processName;
    name = factory.make(qname);
    ATerm cargs[] = new ATerm[] { type, name };
    return factory.makeAppl(afun, cargs);
  }

  public static ATerm mkVar(ATerm name, String processName, ATerm type) {
    return mkAnyVar("var", name, processName, type);
  }

  public static ATerm mkResVar(ATerm name, String processName, ATerm type) {
    return mkAnyVar("rvar", name, processName, type);
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
        return appl.getArguments(); // TODO: check length?
      }
    }
    throw new ToolBusInternalError("illegal var in getVarArgs(" + t + ")");
  }

  public static ATerm getVarType(ATerm t) {
    return getVarArgs(t).elementAt(0);
  }

  public static String getVarName(ATerm t) {
    return ((ATermAppl) getVarArgs(t).elementAt(1)).getName();
  }

  public static ATerm setVarType(ATerm t, ATerm type) {
    //System.out.println("setVarType(" + t + ", " + type + ")");
    ATermList args = ((ATermAppl) t).getArguments();
      ATerm varname = args.getLast();
      if (isVar(t))
        return TBTerm.factory.make("var(<term>,<term>)", type, varname);
      else
        return TBTerm.factory.make("rvar(<term>,<term>)", type, varname);
  }

  public static ATerm changeResVarIntoVar(ATerm t) {
    if (!isResVar(t)) {
      throw new ToolBusInternalError("wrong arg in makeVar(" + t + ")");
    }
    ATerm args[] = ((ATermAppl) t).getArgumentArray();
    AFun afun = t.getFactory().makeAFun("var", args.length, false);
    return TBTerm.factory.makeAppl(afun, args);
  }

  public static ATerm newTransactionId() {
    AFun afun = factory.makeAFun("transaction", 1, false);
    ATerm arg = factory.makeInt(nTransactions++);
    return factory.makeAppl(afun, arg);
  }

  /**
   * Resolve the variables in ATerm t using Environment env.
   * The declaration information in env is used to include type information in 
   * every variable occurence
   * @param t Aterm to be resolved.
   * @param env environment to be used.
   */

  public static ATerm resolveVars(ATerm t, Environment env) throws ToolBusException {
  	//System.err.println("resolveVars: " + t + ": " + env);
  	if(t == TBTerm.Undefined){
  		return t;
  	}
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        if (TBTerm.isVar(t)) {
        	ATerm res = setVarType(t, env.getVarType(t));
            return res;
        }
        if(TBTerm.isResVar(t)){
        	ATerm res = setVarType(t, env.getVarType(t));
        	return res;
        }

        AFun afun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        ATerm cargs[] = new ATerm[args.length];
        if (args.length == 0)
          return t;
        for (int i = 0; i < args.length; i++) {
          cargs[i] = resolveVars(args[i], env);
        }
        return TBTerm.factory.makeAppl(afun, cargs);

      case ATerm.LIST :
        ATermList lst = TBTerm.factory.makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          lst = lst.append(resolveVars(((ATermList) t).elementAt(i), env));
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in resolveVars: " + t);
  }
  
  public static ATerm replaceAssignableVar(ATerm t, Environment env) throws ToolBusException {
  	//System.err.println("replaceAssignableVar: " + t + "; " + env);
  	 if (TBTerm.isVar(t) || TBTerm.isResVar(t)){
    	Binding b = env.getBinding(t);
    	//System.err.println("Binding = " + b.var + ";" + b.val);
    	if(b == null || (b.val == Undefined)){
    		return t;
    	}
    	if(b.isFormal() && isResVar(b.val)){
    			return replaceAssignableVar(b.val, env);
    	} 
    	return b.var;
    } 
  	throw new ToolBusInternalError("illegal ATerm in replaceAssignableVar: " + t);
  }
  
  /**
   * Replace the formals in ATerm t by their values using Environment env.
   * @param t Aterm containing formals
   * @param env environment to be used.
   */

  public static ATerm replaceFormals(ATerm t, Environment env) throws ToolBusException {

    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t)) {
           	t = setVarType(t, env.getVarType(t)); 	
        	Binding b = env.getBinding(t);
        	if(b == null || (b.val == Undefined)){
        		return t;
        	}
        	//} else if(b.isFormal() && isResVar(b.val)){
        	//	return replaceFormals(b.val, env);
        	//} else {
        	//	return b.var;
        	return t;
        	
        }

        AFun afun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        ATerm cargs[] = new ATerm[args.length];
        if (args.length == 0)
          return t;
        for (int i = 0; i < args.length; i++) {
          cargs[i] = replaceFormals(args[i], env);
        }
        return TBTerm.factory.makeAppl(afun, cargs);

      case ATerm.LIST :
        ATermList lst = TBTerm.factory.makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          lst = lst.append(replaceFormals(((ATermList) t).elementAt(i), env));
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in replaceFormals: " + t);
  }

  /**
   * Transform a term into a pattern that can be used by tool interfaces.
   */

  public static ATerm makePattern(ATerm t, Environment env, boolean recurring) throws ToolBusException {
  	if(t == TBTerm.Undefined){
  		return t;
  	}
    switch (t.getType()) {
      case ATerm.BLOB :
      	throw new ToolBusInternalError("makePattern for BLOB not implemented");

      case ATerm.INT :
        return IntPlaceholder;

      case ATerm.PLACEHOLDER :
        return t;

      case ATerm.REAL :
        return RealPlaceholder;

      case ATerm.APPL :
        if (TBTerm.isVar(t) || TBTerm.isResVar(t)) {
          ATerm type = TBTerm.getVarType(t);
          return factory.makePlaceholder(type);
        }
        if (TBTerm.isBoolean(t)) {
          return BoolPlaceholder;
        }
        AFun fun = ((ATermAppl) t).getAFun();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        if (args.length == 0) {
          if (fun.isQuoted())
            return StrPlaceholder;
          else
            return t;
        }
        if (!recurring)
          return factory.makePlaceholder(t);
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

  /**
   * Replace all variables in an ATerm by their value.
   * 
   */

  public static ATerm substitute(ATerm t, Environment env) throws ToolBusException {
  	if(t == TBTerm.Undefined){
  		return t;
  	}
    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;
      case ATerm.APPL :
        if (TBTerm.isVar(t)) {
          return env.getValue(t);
        }
        if (TBTerm.isResVar(t) || TBTerm.isBoolean(t)) {
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

  /**
   * Matching of two terms. Both terms use a different environment. There are two flavours of matching:
   * match      -- complete match with full treatment of variabeles
   * mightMatch -- a partial match that ignores variables.
   * 
   */

  private static Environment enva;
  private static Environment envb;
  private static boolean fullMatch = true;
  private static MatchResult mr;

  public static boolean match(ATerm ta, Environment enva, ATerm tb, Environment envb) throws ToolBusException {
  	//System.err.println("match: ta = " + ta + "  ; " + "enva = " + enva);
 	//System.err.println("       tb = " + ta + "  ; " + "envb = " + envb);
    mr = new MatchResult(enva, envb);

    TBTerm.enva = enva;
    TBTerm.envb = envb;

    fullMatch = true;
    boolean res = performMatch(ta, tb);
    if (res) {
      mr.updateEnvs();
      //System.err.println("match: " + mr);
      return true;
    } else
      return false;
  }

  public static boolean mightMatch(ATerm ta, ATerm tb) {
    fullMatch = false;
    try {
      return performMatch(ta, tb);
    } catch (ToolBusException e) {
      throw new ToolBusInternalError(e.getMessage());
    }
  }

  private static boolean performMatch(ATerm ta, ATerm tb) throws ToolBusException {
  	//System.err.println("performMatch: " + ta + " " + tb);
    if (TBTerm.isVar(ta))
      if (fullMatch) {
        ta = enva.getValue(ta);
      } else {
        return true;
      }

    if (TBTerm.isVar(tb))
      if (fullMatch) {
        tb = envb.getValue(tb);
      } else {
        return true;
      }

    if (TBTerm.isResVar(ta)) {
      if (TBTerm.isResVar(tb)) {
        return false;
      }
      if (fullMatch) {
        mr.assignLeft(ta, TBTerm.substitute(tb, envb)); // TODO check var type!
      }
      return true;
    }

    if (TBTerm.isResVar(tb)) {
      if (fullMatch) {
        mr.assignRight(tb, TBTerm.substitute(ta, enva)); // TODO check var type!
      }
      return true;
    }

    switch (ta.getType()) {
      case ATerm.BLOB :
        return ta.isEqual(tb) || (tb == TBTerm.StrPlaceholder);
      case ATerm.INT :
        return ta.equals(tb) || (tb == TBTerm.IntPlaceholder);
      case ATerm.REAL :
        return ta.equals(tb) || (tb == TBTerm.RealPlaceholder);
      case ATerm.PLACEHOLDER :
        if (ta.equals(IntPlaceholder) && tb.getType() == ATerm.INT)
          return true;
        else if (ta == RealPlaceholder && tb.getType() == ATerm.REAL)
          return true;
        else if (ta == StrPlaceholder && 
        		((tb.getType() == ATerm.APPL && ((ATermAppl) tb).getArity() == 0)) || 
				  tb.getType() == ATerm.BLOB)
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
        throw new ToolBusInternalError("illegal ATerm in performMatch: " + ta);
    }
  }

}
