package toolbus;

import java.util.HashMap;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class TBTermFactory {

	/**
	 * A term of type VAR
	 */
	public static final int VAR = 8;

	private static aterm.pure.PureFactory factory;

	private static AFun fun_TBTermVar;

	private static TBTermVar proto_TBTermVar;

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
	
	public static ATermList EmptyList;

	public static TBTermVar TransactionIdVar;

	public static TBTermVar TransactionIdResVar;
	
	public static ATerm transaction;

	private static int nTransactions = 0;
	
	 public static void init() {
		 if(factory == null){
			 init(new PureFactory());
		 }
	}

	public static PureFactory getPureFactory() {
		return factory;
	}

	public static void init(PureFactory fact) {
		factory = fact;
		
		//pattern_TBTermVar = factory.parse("var(<term>,<str>,<term>)");
		fun_TBTermVar = factory.makeAFun("var", 3, false);
		proto_TBTermVar = new TBTermVar();

//		pattern_TBTermResVar = factory.parse("rvar(<term>,<str>)");
//		fun_TBTermResVar = factory.makeAFun("rvar", 2, false);
//		proto_TBTermResVar = new TBTermResVar();

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
		
		EmptyList = factory.makeList();
		
		transaction = factory.make("transaction");

		TransactionIdVar = makeTBTermVar("transactionId", transaction);
		TransactionIdResVar = makeTBTermResVar("transactionId", transaction);

		Functions.init(factory);
	}
	
	public static String statistics(){
		return factory.toString();
	}

	public static TBTermVar makeTBTermVar(String name, ATerm type, ATerm isResult,
			aterm.ATermList annos) {
		synchronized (proto_TBTermVar) {
			ATerm[] args = new ATerm[3];
			args[0] = type;
			args[1] = factory.make(name);
			args[2] = isResult;
			proto_TBTermVar.initHashCode(annos, fun_TBTermVar, args);
			return (TBTermVar) factory.build(proto_TBTermVar);
		}
	}

	public static TBTermVar makeTBTermVar(String name, ATerm type) {
		return makeTBTermVar(name, type, False, EmptyList);
	}
	
	public static TBTermVar makeTBTermVar(String name, ATerm type, ATerm isResVar) {
		return makeTBTermVar(name, type, isResVar, EmptyList);
	}
	
	public static TBTermVar makeTBTermResVar(String name, ATerm type) {
		return makeTBTermVar(name, type, True, EmptyList);
	}
	
	public static TBTermVar mkVar(ATerm name, String processName, ATerm type){
		return makeTBTermVar(name.toString() + "$" + processName, type);
	}
	
	public static TBTermVar mkResVar(ATerm name, String processName, ATerm type){
		return makeTBTermResVar(name.toString() + "$" + processName, type);
	}
	
	public static ATerm newTransactionId() {
		AFun afun = factory.makeAFun("transaction", 1, false);
		ATerm arg = factory.makeInt(nTransactions++);
		return factory.makeAppl(afun, arg);
	}

	public static ATerm make(String pat) {
		return factory.parse(pat);
	}
	public static ATerm make(String pat, ATerm a1) {
		return factory.make(pat, a1);
	}
	public static ATerm make(String pat, ATerm a1, ATerm a2) {
		return factory.make(pat, a1, a2);
	}
	public static ATerm make(String pat, ATerm a1, ATerm a2, ATerm a3) {
		return factory.make(pat, a1, a2, a3);
	}
	public static AFun makeAFun(String name, int arity, boolean quoted){
		return factory.makeAFun(name, arity, quoted);
	}
	public static ATermAppl makeAppl(AFun afun, ATerm a1){
		return factory.makeAppl(afun, a1);
	}
	
	public static ATerm makePlaceholder(ATerm t){
		return factory.makePlaceholder(t);
	}
	
	public static ATermList makeList(){
		return EmptyList;
	}
	
	public static ATermList makeList(ATerm t){
		return factory.makeList(t);
	}
	
	public static ATermList makeList(ATerm t, ATermList l){
		return factory.makeList(t, l);
	}
	
	public static ATerm makeInt(int n){
		return factory.makeInt(n);
	}
	
	/*****/

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
		if (isAppl(t)) {
			return (((ATermAppl) t).isQuoted())
					&& ((ATermAppl) t).getArity() == 0;
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
		return t.getType() == ATerm.LIST;
	}

	public static ATerm getArgs(ATerm t) {
		return ((ATermAppl) t).getArguments();
	}

	public static int size(ATerm l) {
		return ((ATermList) l).getLength();
	}

	public static ATerm first(ATerm l) {
		ATermList lst = (ATermList) l;
		if (!lst.isEmpty()) {
			return lst.elementAt(0);
		} else {
			System.err.println("**** first on empty list ****");
			return TBTermFactory.Undefined;
		}
	}

	public static ATerm next(ATerm l) {
		ATermList lst = (ATermList) l;
		if (lst.isEmpty()) {
			return lst;
		} else {
			return lst.getNext();
		}
	}

	public static boolean member(ATerm e, ATerm l) {
		ATermList lst = (ATermList) l;
		int length = lst.getLength();
		for (int i = 0; i < length ; i++) {
			if (e.isEqual(lst.elementAt(i)))
				return true;
		}
		return false;
	}

	public static boolean subset(ATerm l1, ATerm l2) {
		ATermList lst1 = (ATermList) l1;
		int length1 = lst1.getLength();
		for (int i = 0; i < length1; i++) {
			ATerm e = lst1.elementAt(i);
			if (!member(e, l2))
				return false;
			else
				l2 = delete(l2, e);
		}
		return true;
	}

	public static ATerm delete(ATerm l, ATerm e) {
		ATermList lst = (ATermList) l;
		ATermList res = EmptyList;
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
		ATermList res = EmptyList;
		for (int i = lst1.getLength() - 1; i >= 0; i--) {
			ATerm e = lst1.elementAt(i);
			if (!member(e, l2))
				res = factory.makeList(e, res);
		}
		//System.err.println("diff(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}

	public static ATerm inter(ATerm l1, ATerm l2) {
		ATermList lst1 = (ATermList) l1;
		ATermList res = EmptyList;
		for (int i = lst1.getLength() - 1; i >= 0; i--) {
			ATerm e = lst1.elementAt(i);
			if (member(e, l2))
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
		//System.err.println("join(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}

	public static ATerm index(ATerm l, int i) {
		ATerm res = ((ATermList) l).elementAt(i - 1);
		//System.err.println("index(" + l + ", " + i + ")==> " + res);
		return res;
	}

	public static ATerm replace(ATerm l, int n, ATerm e) {
		ATermList lst = (ATermList) l;
		ATermList res = EmptyList;
		for (int i = lst.getLength() - 1; i >= 0; i--) {
			ATerm elem = (i == n - 1) ? e : lst.elementAt(i);
			res = factory.makeList(elem, res);
		}
		return res;
	}

	public static ATerm put(ATerm l, ATerm k, ATerm v) {
		ATermList pair = factory.makeList(k, factory.makeList(v));
		return factory.makeList(pair, (ATermList) l);
	}

	public static ATerm get(ATerm l, ATerm k) {
		ATermList lst = (ATermList) l;
		for (ATermList pair = (ATermList) lst.getFirst(); !lst.isEmpty(); lst = lst
				.getNext()) {
			if (k.isEqual(pair.getFirst()))
				return pair.getLast();
		}
		return Undefined;
	}
	
	public static boolean isVar(ATerm t) {
	    return t.getType() == VAR && !((TBTermVar) t).isResultVar();
	  }
	
	public static boolean isResVar(ATerm t) {
	    return t.getType() == VAR && ((TBTermVar) t).isResultVar();
	}
	
	public static boolean isAnyVar(ATerm t) {
	    return t.getType() == VAR;
	}
	
	public static TBTermVar changeResVarIntoVar(TBTermVar rvar){
		return makeTBTermVar(rvar.getVarName(), rvar.getVarType());
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
	  	if(t == TBTermFactory.Undefined){
	  		return t;
	  	}
	    switch (t.getType()) {
	      case ATerm.BLOB :
	      case ATerm.INT :
	      case ATerm.PLACEHOLDER :
	      case ATerm.REAL :
	        return t;
	        
	      case TBTermFactory.VAR:
	    	  TBTermVar v = (TBTermVar) t;
	    	  v = v.setVarType(env.getVarType(v));
	    	  //System.err.println("resolveVar returns: " + v + "; " + env);
	    	  return v;
	    	  
	      case ATerm.APPL :
	    	ATermAppl apt = (ATermAppl) t;

	        AFun afun = apt.getAFun();
	        ATerm args[] = apt.getArgumentArray();
	        ATerm cargs[] = new ATerm[args.length];
	        int nargs = args.length;
	        if (nargs == 0)
	          return t;
	        for (int i = 0; i < nargs; i++) {
	          cargs[i] = resolveVars(args[i], env);
	        }
	        return TBTermFactory.factory.makeAppl(afun, cargs);

	      case ATerm.LIST :
	        ATermList lst = EmptyList;
	        ATermList tlst = (ATermList) t;
	        for (int i = tlst.getLength() - 1; i >= 0; i--) {
	          lst = lst.insert(resolveVars(tlst.elementAt(i), env));
	        }
	 
	        return lst;
	    }
	    throw new ToolBusInternalError("illegal ATerm in resolveVars: " + t);
	  }
	  
	  public static TBTermVar replaceAssignableVar(TBTermVar v, Environment env) throws ToolBusException {
	  	//System.err.println("replaceAssignableVar: " + v + "; " + env);

    	Binding b = env.getBinding(v);
    	//System.err.println("Binding = " + b.var + ";" + b.val);
    	if(b == null || (b.val == Undefined)){
    		return v;
    	}
    	if(b.isFormal() && isResVar(b.val)){
    			return replaceAssignableVar((TBTermVar)b.val, env);
    	} 
    	return b.var;
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
	        
	      case TBTermFactory.VAR:
	    	  
	    	TBTermVar v = (TBTermVar) t;
			v = v.setVarType(env.getVarType(v));
			Binding b = env.getBinding(v);
			if (b == null || (b.val == Undefined)) {
				return v;
			}
			//} else if(b.isFormal() && isResVar(b.val)){ //TODO: OK?
			//	return replaceFormals(b.val, env);
			//} else {
			//	return b.val;
		//	}
				return v;

	      case ATerm.APPL :
	    	ATermAppl apt = (ATermAppl) t;

	        AFun afun = apt.getAFun();
	        ATerm args[] = apt.getArgumentArray();
	        ATerm cargs[] = new ATerm[args.length];
	        int nargs = args.length;
	        if (nargs == 0)
	          return t;
	        for (int i = 0; i < nargs; i++) {
	          cargs[i] = replaceFormals(args[i], env);
	        }
	        return TBTermFactory.factory.makeAppl(afun, cargs);

	      case ATerm.LIST :
	        
	        ATermList lst = TBTermFactory.EmptyList;
	        ATermList tlst = (ATermList) t;
	        for (int i = tlst.getLength() - 1; i >= 0; i--) {
	          lst = lst.insert(replaceFormals(tlst.elementAt(i), env));
	        }
	        return lst;
	    }
	    throw new ToolBusInternalError("illegal ATerm in replaceFormals: " + t);
	  }

	  /**
	   * Transform a term into a pattern that can be used by tool interfaces.
	   */

	  public static ATerm makePattern(ATerm t, Environment env, boolean recurring) throws ToolBusException {
	  	if(t == TBTermFactory.Undefined){
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
	        
	      case TBTermFactory.VAR:
	    	  TBTermVar var = (TBTermVar) t;
	    	  ATerm type = var.getVarType();
	    	  return factory.makePlaceholder(type);

	      case ATerm.APPL :
	    	ATermAppl apt = (ATermAppl) t;
	        if (TBTermFactory.isBoolean(apt)) {
	          return BoolPlaceholder;
	        }
	        AFun fun = apt.getAFun();
	        ATerm args[] = apt.getArgumentArray();
	        if (args.length == 0) {
	          if (fun.isQuoted())
	            return StrPlaceholder;
	          else
	            return apt;
	        }
	        if (!recurring)
	          return factory.makePlaceholder(apt);
	        ATerm vargs[] = new ATerm[args.length];
	        for (int i = 0; i < args.length; i++) {
	          vargs[i] = makePattern(args[i], env, false);
	        }
	        return factory.makeAppl(fun, vargs);

	      case ATerm.LIST :
	      	
	        ATermList lst = TBTermFactory.EmptyList;
	        ATermList tlst = (ATermList) t;
	        for (int i = tlst.getLength() - 1; i >= 0; i--) {
	          lst = lst.insert(makePattern(tlst.elementAt(i), env, true));
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
	  	if(t == TBTermFactory.Undefined){
	  		return t;
	  	}
	    switch (t.getType()) {
	      case ATerm.BLOB :
	      case ATerm.INT :
	      case ATerm.PLACEHOLDER :
	      case ATerm.REAL :
	        return t;
	        
	      case TBTermFactory.VAR:
	    	  TBTermVar var = (TBTermVar) t;
	    	  if(var.isResultVar()){
	    		  return var;
	    	  }
	    	  return env.getValue(var);
	        
	      case ATerm.APPL :
	    	ATermAppl apt = (ATermAppl) t;
	        if (TBTermFactory.isBoolean(apt)) {
	          return t;
	        }
	        AFun afun = apt.getAFun();
	        ATerm args[] = apt.getArgumentArray();
	        int nargs = args.length;
	        if (nargs == 0)
	          return t;
	        ATerm vargs[] = new ATerm[nargs];
	        for (int i = 0; i < nargs; i++) {
	          vargs[i] = substitute(args[i], env);
	        }
	        return factory.makeAppl(afun, vargs);
	        
	      case ATerm.LIST :
	 
	        ATermList lst = TBTermFactory.EmptyList;
	        ATermList tlst = (ATermList) t;
	        for (int i = tlst.getLength() - 1; i >= 0; i--) {
	          lst = lst.insert(substitute(tlst.elementAt(i), env));
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
	  
	  private static HashMap<ATerm, HashMap<ATerm,Boolean>> matchCache = new HashMap<ATerm, HashMap<ATerm,Boolean>>(10000);

	  public static boolean match(ATerm ta, Environment enva, ATerm tb, Environment envb) throws ToolBusException {
	  	//System.err.println("match: ta = " + ta + "  ; " + "enva = " + enva);
	 	//System.err.println("       tb = " + ta + "  ; " + "envb = " + envb);

	  //  if(!mightMatch(ta, tb)){
	  //  	return false;
	  //  }
	   
	    mr = new MatchResult(enva, envb);
	    TBTermFactory.enva = enva;
	    TBTermFactory.envb = envb;
	    
	    fullMatch = true;
	    boolean res = performMatch(ta, tb);
	    if (res) {
	      mr.updateEnvs();
	      //System.err.println("match: " + mr);
	      return true;
	    } else
	      return false;
	  }
	  
	 // private static int mightMatchCnt = 0;
	 // private static int cachedMatches = 0;
	  

	  public static boolean mightMatch(ATerm ta, ATerm tb) {
	    fullMatch = false;
	 
	 //   mightMatchCnt += 1;
	    try {
	    	/*
	    }
	      HashMap<ATerm,Boolean> taCache = matchCache.get(ta);
	      if(taCache != null){
	    	  Boolean occurstb = taCache.get(tb);
	    	  if(occurstb != null){
	 //   		  cachedMatches += 1;
	    		  return occurstb.booleanValue();
	    	  }
	      } else {
	    	  taCache = new HashMap<ATerm,Boolean>(100);
	    	  matchCache.put(ta, taCache);
	      }
	 //     if(mightMatchCnt % 100 == 0){
	 //   	  System.err.println("mightMatchCnt = " + mightMatchCnt + "; cachedMatches = " + cachedMatches + "(" +
	 //   			  (cachedMatches * 100 /  mightMatchCnt) + "%)");
	 //     }
	  * */
	      boolean res =  performMatch(ta, tb);
	      /* taCache.put(tb, res ? Boolean.TRUE : Boolean.FALSE); */
	      return res;
	      
	    } catch (ToolBusException e) {
	      throw new ToolBusInternalError(e.getMessage());
	    }
	  }

	  private static boolean performMatch(ATerm ta, ATerm tb) throws ToolBusException {
	  	//System.err.println("performMatch: " + ta + " " + tb);

	    switch (ta.getType()) {

		case TBTermFactory.VAR:
			TBTermVar varta = (TBTermVar) ta;
			if (!fullMatch) {
				return true;
			}

			if (varta.isResultVar()) {
				if (TBTermFactory.isResVar(tb)) {
					return false;
				}
				if (TBTermFactory.isVar(tb)) {
					tb = envb.getValue((TBTermVar) tb);
				}
				mr.assignLeft(varta, TBTermFactory.substitute(tb, envb)); // TODO check var type!
				return true;
			}

			ta = enva.getValue(varta);
			return performMatch(ta, tb);

		case ATerm.BLOB:
			if (TBTermFactory.isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, TBTermFactory.substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			return ta.isEqual(tb) || (tb == TBTermFactory.StrPlaceholder);

		case ATerm.INT:
			if (TBTermFactory.isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, TBTermFactory.substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			return ta.equals(tb) || (tb == TBTermFactory.IntPlaceholder);

		case ATerm.REAL:
			if (TBTermFactory.isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, TBTermFactory.substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			return ta.equals(tb) || (tb == TBTermFactory.RealPlaceholder);

		case ATerm.PLACEHOLDER:
			if (TBTermFactory.isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, TBTermFactory.substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			if (ta == TBTermFactory.IntPlaceholder && tb.getType() == ATerm.INT)
				return true;
			else if (ta == TBTermFactory.RealPlaceholder
					&& tb.getType() == ATerm.REAL)
				return true;
			else if (ta == TBTermFactory.StrPlaceholder
					&& ((tb.getType() == ATerm.APPL && ((ATermAppl) tb)
							.getArity() == 0)) || tb.getType() == ATerm.BLOB)
				return true;
			else if (ta == TBTermFactory.ListPlaceholder
					&& tb.getType() == ATerm.LIST)
				return true;
			else if (ta == TBTermFactory.TermPlaceholder)
				return true;
			else
				return false;

		case ATerm.APPL:
			if (TBTermFactory.isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, TBTermFactory.substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			ATermAppl apta = (ATermAppl) ta;

			if (tb.getType() == ATerm.PLACEHOLDER) {
				if (tb == StrPlaceholder && apta.getArity() == 0)
					return true;
				else if (tb == TermPlaceholder)
					return true;
				else
					return false;
			}
			if (tb.getType() != ATerm.APPL)
				return false;
			ATermAppl aptb = (ATermAppl) tb;
			if (apta.getArity() != aptb.getArity()
					|| apta.getName() != aptb.getName())
				return false;
			else {
				ATerm a_args[] = apta.getArgumentArray();
				ATerm b_args[] = ((ATermAppl) tb).getArgumentArray();
				for (int i = 0; i < a_args.length; i++) {
					if (!performMatch(a_args[i], b_args[i]))
						return false;
				}
				return true;
			}

		case ATerm.LIST:
			if (TBTermFactory.isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, TBTermFactory.substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			if (tb == ListPlaceholder) {
				return true;
			}
			if (((ATermList) ta).getLength() != ((ATermList) tb).getLength())
				return false;
			else {
				ATermList lsta = (ATermList) ta;
				ATermList lstb = (ATermList) tb;
				while (!lsta.isEmpty()) {
					if (!performMatch(lsta.getFirst(), lstb.getFirst()))
						return false;
					lsta = lsta.getNext();
					lstb = lstb.getNext();
				}
				return true;
			}
		default:
			throw new ToolBusInternalError("illegal ATerm in performMatch: "
					+ ta);
		}
	}

	
}
