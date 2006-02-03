package toolbus;

import java.util.HashMap;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.pure.PureFactory;

public class TBTermFactory extends PureFactory {

	/**
	 * A term of type VAR
	 */
	public static final int VAR = 8;

	private AFun fun_TBTermVar;

	private TBTermVar proto_TBTermVar;

	public ATerm True;

	public ATerm False;

	public ATerm BoolType;

	public ATerm IntType;

	public ATerm RealType;

	public ATerm StrType;

	public ATerm TermType;

	public ATerm ListType;

	public ATerm VoidType; // for the benefit of JavaTools

	public ATerm Undefined;

	public ATerm BoolPlaceholder;

	public ATerm IntPlaceholder;

	public ATerm RealPlaceholder;

	public ATerm StrPlaceholder;

	public ATerm TermPlaceholder;

	public ATerm ListPlaceholder;
	
	public ATermList EmptyList;

	public TBTermVar TransactionIdVar;

	public TBTermVar TransactionIdResVar;
	
	public ATerm transaction;

	private int nTransactions = 0;
	
	private static TBTermFactory instance = null;
	
	public TBTermFactory() {
		super();
	    initialize();
	  }
	
	public static TBTermFactory getInstance() {
		 if (instance == null) {
		        instance = new TBTermFactory();
		        instance.initialize();
		    }
		 return instance;
	}

	public void initialize() {
		//pattern_TBTermVar = parse("var(<term>,<str>,<term>)");
		fun_TBTermVar = makeAFun("var", 3, false);
		proto_TBTermVar = new TBTermVar(this);

		True = make("true");
		False = make("false");
		BoolType = make("bool");
		IntType = make("int");
		RealType = make("real");
		StrType = make("str");
		TermType = make("term");
		ListType = make("list");

		VoidType = make("void");

		Undefined = make("undefined");

		BoolPlaceholder = makePlaceholder(BoolType);
		IntPlaceholder = makePlaceholder(IntType);
		RealPlaceholder = makePlaceholder(RealType);
		StrPlaceholder = makePlaceholder(StrType);
		TermPlaceholder = makePlaceholder(TermType);
		ListPlaceholder = makePlaceholder(ListType);
		
		EmptyList = makeList();
		
		transaction = make("transaction");

		TransactionIdVar = makeTBTermVar("transactionId", transaction);
		TransactionIdResVar = makeTBTermResVar("transactionId", transaction);

		Functions.init(this);
	}
	
	public String statistics(){
		return toString();
	}

	public TBTermVar makeTBTermVar(String name, ATerm type, ATerm isResult,
			aterm.ATermList annos) {
		synchronized (proto_TBTermVar) {
			ATerm[] args = new ATerm[3];
			args[0] = type;
			args[1] = make(name);
			args[2] = isResult;
			proto_TBTermVar.initHashCode(annos, fun_TBTermVar, args);
			return (TBTermVar) build(proto_TBTermVar);
		}
	}

	public TBTermVar makeTBTermVar(String name, ATerm type) {
		return makeTBTermVar(name, type, False, EmptyList);
	}
	
	public TBTermVar makeTBTermVar(String name, ATerm type, ATerm isResVar) {
		return makeTBTermVar(name, type, isResVar, EmptyList);
	}
	
	public TBTermVar makeTBTermResVar(String name, ATerm type) {
		return makeTBTermVar(name, type, True, EmptyList);
	}
	
	public TBTermVar mkVar(ATerm name, String processName, ATerm type){
		return makeTBTermVar(name.toString() + "$" + processName, type);
	}
	
	public TBTermVar mkResVar(ATerm name, String processName, ATerm type){
		return makeTBTermResVar(name.toString() + "$" + processName, type);
	}
	
	public ATerm newTransactionId() {
		AFun afun = makeAFun("transaction", 1, false);
		ATerm arg = makeInt(nTransactions++);
		return makeAppl(afun, arg);
	}
	
	/*****/

	public boolean isTrue(ATerm t) {
		return t == True;
	}

	public boolean isFalse(ATerm t) {
		return t == False;
	}

	public boolean isBoolean(ATerm t) {
		return t == True || t == False;
	}

	public boolean isInt(ATerm t) {
		return t.getType() == ATerm.INT;
	}

	public boolean isStr(ATerm t) {
		if (isAppl(t)) {
			return (((ATermAppl) t).isQuoted())
					&& ((ATermAppl) t).getArity() == 0;
		} else
			return false;
	}

	public boolean isReal(ATerm t) {
		return (t.getType() == ATerm.REAL);
	}

	public boolean isAppl(ATerm t) {
		return t.getType() == ATerm.APPL;
	}

	public boolean isList(ATerm t) {
		return t.getType() == ATerm.LIST;
	}

	public ATerm getArgs(ATerm t) {
		return ((ATermAppl) t).getArguments();
	}

	public int size(ATerm l) {
		return ((ATermList) l).getLength();
	}

	public ATerm first(ATerm l) {
		ATermList lst = (ATermList) l;
		if (!lst.isEmpty()) {
			return lst.elementAt(0);
		} else {
			System.err.println("**** first on empty list ****");
			return Undefined;
		}
	}

	public ATerm next(ATerm l) {
		ATermList lst = (ATermList) l;
		if (lst.isEmpty()) {
			return lst;
		} else {
			return lst.getNext();
		}
	}

	public boolean member(ATerm e, ATerm l) {
		ATermList lst = (ATermList) l;
		int length = lst.getLength();
		for (int i = 0; i < length ; i++) {
			if (e.isEqual(lst.elementAt(i)))
				return true;
		}
		return false;
	}

	public boolean subset(ATerm l1, ATerm l2) {
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

	public ATermList delete(ATerm l, ATerm e) {
		ATermList lst = (ATermList) l;
		ATermList res = EmptyList;
		boolean found = false;
		for (int i = lst.getLength() - 1; i >= 0; i--) {
			ATerm e2 = lst.elementAt(i);
			if (e2.isEqual(e) && !found)
				found = true;
			else
				res = makeList(e2, res);
		}
		return res;
	}

	public ATerm diff(ATerm l1, ATerm l2) {
		ATermList lst1 = (ATermList) l1;
		ATermList res = EmptyList;
		for (int i = lst1.getLength() - 1; i >= 0; i--) {
			ATerm e = lst1.elementAt(i);
			if (!member(e, l2))
				res = makeList(e, res);
		}
		//System.err.println("diff(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}

	public ATerm inter(ATerm l1, ATerm l2) {
		ATermList lst1 = (ATermList) l1;
		ATermList res = EmptyList;
		for (int i = lst1.getLength() - 1; i >= 0; i--) {
			ATerm e = lst1.elementAt(i);
			if (member(e, l2))
				res = makeList(e, res);
		}
		//System.err.println("inter(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}

	public ATerm join(ATerm l1, ATerm l2) {
		//if(l1 == null)
		//	return l2;
		//if(l2 == null)
		//	return l1;
		ATermList lst1 = isList(l1) ? (ATermList) l1 : makeList(l1);
		ATermList res = isList(l2) ? (ATermList) l2 : makeList(l2);
		for (int i = lst1.getLength() - 1; i >= 0; i--) {
			ATerm e = lst1.elementAt(i);
			res = makeList(e, res);
		}
		//System.err.println("join(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}

	public ATerm index(ATerm l, int i) {
		ATerm res = ((ATermList) l).elementAt(i - 1);
		//System.err.println("index(" + l + ", " + i + ")==> " + res);
		return res;
	}

	public ATerm replace(ATerm l, int n, ATerm e) {
		ATermList lst = (ATermList) l;
		ATermList res = EmptyList;
		for (int i = lst.getLength() - 1; i >= 0; i--) {
			ATerm elem = (i == n - 1) ? e : lst.elementAt(i);
			res = makeList(elem, res);
		}
		return res;
	}

	public ATerm put(ATerm l, ATerm k, ATerm v) {
		ATermList pair = makeList(k, makeList(v));
		return makeList(pair, (ATermList) l);
	}

	public ATerm get(ATerm l, ATerm k) {
		ATermList lst = (ATermList) l;
		for (ATermList pair = (ATermList) lst.getFirst(); !lst.isEmpty(); lst = lst
				.getNext()) {
			if (k.isEqual(pair.getFirst()))
				return pair.getLast();
		}
		return Undefined;
	}
	
	public boolean isVar(ATerm t) {
	    return t.getType() == VAR && !((TBTermVar) t).isResultVar();
	  }
	
	public boolean isResVar(ATerm t) {
	    return t.getType() == VAR && ((TBTermVar) t).isResultVar();
	}
	
	public boolean isAnyVar(ATerm t) {
	    return t.getType() == VAR;
	}
	
	public TBTermVar changeResVarIntoVar(TBTermVar rvar){
		return makeTBTermVar(rvar.getVarName(), rvar.getVarType());
	}
	
	 /**
	   * Resolve the variables in ATerm t using Environment env.
	   * The declaration information in env is used to include type information in 
	   * every variable occurence
	   * @param t Aterm to be resolved.
	   * @param env environment to be used.
	   */

	  public ATerm resolveVars(ATerm t, Environment env) throws ToolBusException {
	  	//System.err.println("resolveVars: " + t + ": " + env);
	  	if(t == Undefined){
	  		return t;
	  	}
	    switch (t.getType()) {
	      case ATerm.BLOB :
	      case ATerm.INT :
	      case ATerm.PLACEHOLDER :
	      case ATerm.REAL :
	        return t;
	        
	      case VAR:
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
	        return makeAppl(afun, cargs);

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
	  
	  public TBTermVar replaceAssignableVar(TBTermVar v, Environment env) throws ToolBusException {
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

	  public ATerm replaceFormals(ATerm t, Environment env) throws ToolBusException {

	    switch (t.getType()) {
	      case ATerm.BLOB :
	      case ATerm.INT :
	      case ATerm.PLACEHOLDER :
	      case ATerm.REAL :
	        return t;
	        
	      case VAR:
	    	  
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
	        return makeAppl(afun, cargs);

	      case ATerm.LIST :
	        
	        ATermList lst = EmptyList;
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

	  public ATerm makePattern(ATerm t, Environment env, boolean recurring) throws ToolBusException {
	  	if(t == Undefined){
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
	        
	      case VAR:
	    	  TBTermVar var = (TBTermVar) t;
	    	  ATerm type = var.getVarType();
	    	  return makePlaceholder(type);

	      case ATerm.APPL :
	    	ATermAppl apt = (ATermAppl) t;
	        if(isBoolean(apt)) {
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
	          return makePlaceholder(apt);
	        ATerm vargs[] = new ATerm[args.length];
	        for (int i = 0; i < args.length; i++) {
	          vargs[i] = makePattern(args[i], env, false);
	        }
	        return makeAppl(fun, vargs);

	      case ATerm.LIST :
	      	
	        ATermList lst = EmptyList;
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

	  public ATerm substitute(ATerm t, Environment env) throws ToolBusException {
	  	if(t == Undefined){
	  		return t;
	  	}
	    switch (t.getType()) {
	      case ATerm.BLOB :
	      case ATerm.INT :
	      case ATerm.PLACEHOLDER :
	      case ATerm.REAL :
	        return t;
	        
	      case VAR:
	    	  TBTermVar var = (TBTermVar) t;
	    	  if(var.isResultVar()){
	    		  return var;
	    	  }
	    	  return env.getValue(var);
	        
	      case ATerm.APPL :
	    	ATermAppl apt = (ATermAppl) t;
	        if (isBoolean(apt)) {
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
	        return makeAppl(afun, vargs);
	        
	      case ATerm.LIST :
	 
	        ATermList lst = EmptyList;
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
	  private MatchResult mr = new MatchResult(this);
	  
	  private static HashMap<ATerm, HashMap<ATerm,Boolean>> matchCache = new HashMap<ATerm, HashMap<ATerm,Boolean>>(10000);

	  public boolean match(ATerm ta, Environment enva, ATerm tb, Environment envb) throws ToolBusException {
	  	//System.err.println("match: ta = " + ta + "  ; " + "enva = " + enva);
	 	//System.err.println("       tb = " + ta + "  ; " + "envb = " + envb);

	  //  if(!mightMatch(ta, tb)){
	  //  	return false;
	  //  }
	   
	    mr.reset(enva, envb);
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
	  

	  public boolean mightMatch(ATerm ta, ATerm tb) {
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

	  private boolean performMatch(ATerm ta, ATerm tb) throws ToolBusException {
	  	//System.err.println("performMatch: " + ta + " " + tb);

	    switch (ta.getType()) {

		case VAR:
			TBTermVar varta = (TBTermVar) ta;
			if (!fullMatch) {
				return true;
			}

			if (varta.isResultVar()) {
				if (isResVar(tb)) {
					return false;
				}
				if (isVar(tb)) {
					tb = envb.getValue((TBTermVar) tb);
				}
				mr.assignLeft(varta, substitute(tb, envb)); // TODO check var type!
				return true;
			}

			ta = enva.getValue(varta);
			return performMatch(ta, tb);

		case ATerm.BLOB:
			if (isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			return ta.isEqual(tb) || (tb == StrPlaceholder);

		case ATerm.INT:
			if (isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			return ta.equals(tb) || (tb == IntPlaceholder);

		case ATerm.REAL:
			if (isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			return ta.equals(tb) || (tb == RealPlaceholder);

		case ATerm.PLACEHOLDER:
			if (isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, substitute(ta, enva)); // TODO check var type!
					return true;
				}
				tb = envb.getValue(vartb);
			}
			if (ta == IntPlaceholder && tb.getType() == ATerm.INT)
				return true;
			else if (ta == RealPlaceholder
					&& tb.getType() == ATerm.REAL)
				return true;
			else if (ta == StrPlaceholder
					&& ((tb.getType() == ATerm.APPL && ((ATermAppl) tb)
							.getArity() == 0)) || tb.getType() == ATerm.BLOB)
				return true;
			else if (ta == ListPlaceholder
					&& tb.getType() == ATerm.LIST)
				return true;
			else if (ta == TermPlaceholder)
				return true;
			else
				return false;

		case ATerm.APPL:
			if (isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, substitute(ta, enva)); // TODO check var type!
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
			if (isAnyVar(tb)) {
				TBTermVar vartb = (TBTermVar) tb;
				if (!fullMatch) {
					return true;
				}
				if (vartb.isResultVar()) {
					mr.assignRight(vartb, substitute(ta, enva)); // TODO check var type!
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
