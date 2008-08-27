package toolbus;

import java.util.ArrayList;
import java.util.Iterator;
import java.util.List;
import toolbus.environment.Binding;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusInternalError;
import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;
import aterm.ATermPlaceholder;
import aterm.pure.PureFactory;

public class TBTermFactory extends PureFactory{
	/**
	 * A term of type VAR
	 */
	public static final int VAR = 80;
	
	private final AFun fun_TBTermVar;
	
	public final ATerm True;
	public final ATerm False;
	
	public final ATerm BoolType;
	public final ATerm IntType;
	public final ATerm RealType;
	public final ATerm StrType;
	public final ATerm TermType;
	public final ATerm ListType;
	public final ATerm BlobType;
	
	public final ATerm Undefined;
	
	public final ATerm BoolPlaceholder;
	public final ATerm IntPlaceholder;
	public final ATerm RealPlaceholder;
	public final ATerm StrPlaceholder;
	public final ATerm TermPlaceholder;
	public final ATerm ListPlaceholder;
	public final ATerm BlobPlaceholder;
	
	public final ATermList EmptyList;
	
	protected TBTermFactory(){
		super();
		
		fun_TBTermVar = makeAFun("var", 3, false);
		
		True = make("true");
		False = make("false");
		
		BoolType = make("bool");
		IntType = make("int");
		RealType = make("real");
		StrType = make("str");
		TermType = make("term");
		ListType = make("list");
		BlobType = make("blob");
		
		Undefined = make("undefined");
		
		BoolPlaceholder = makePlaceholder(BoolType);
		IntPlaceholder = makePlaceholder(IntType);
		RealPlaceholder = makePlaceholder(RealType);
		StrPlaceholder = makePlaceholder(StrType);
		TermPlaceholder = makePlaceholder(TermType);
		ListPlaceholder = makePlaceholder(ListType);
		BlobPlaceholder = makePlaceholder(BlobType);
		
		EmptyList = makeList();
		
		Functions.init(this);
	}
	
	private static class InstanceKeeper{
		public final static TBTermFactory instance = new TBTermFactory();
	}
	
	public static TBTermFactory getInstance(){
		return InstanceKeeper.instance;
	}
	
	public String statistics(){
		return toString();
	}
	
	public TBTermVar makeTBTermVar(String name, ATerm type, ATerm isResult, ATermList annos){
		ATerm[] args = new ATerm[3];
		args[0] = type;
		args[1] = make(name);
		args[2] = isResult;
		return (TBTermVar) build(new TBTermVar(this, annos, fun_TBTermVar, args));
	}
	
	public TBTermVar makeTBTermVar(String name, ATerm type){
		return makeTBTermVar(name, type, False, EmptyList);
	}
	
	public TBTermVar makeTBTermVar(String name, ATerm type, ATerm isResVar){
		return makeTBTermVar(name, type, isResVar, EmptyList);
	}
	
	public TBTermVar makeTBTermResVar(String name, ATerm type){
		return makeTBTermVar(name, type, True, EmptyList);
	}
	
	public TBTermVar mkVar(ATerm name, String processName, ATerm type){
		return makeTBTermVar(name.toString() + "$" + processName, type);
	}
	
	public TBTermVar mkResVar(ATerm name, String processName, ATerm type){
		return makeTBTermResVar(name.toString() + "$" + processName, type);
	}
	
	/*****/
	
	public boolean isTrue(ATerm t){
		return t == True;
	}
	
	public boolean isFalse(ATerm t){
		return t == False;
	}
	
	public boolean isBoolean(ATerm t){
		return t == True || t == False;
	}
	
	public boolean isInt(ATerm t){
		return t.getType() == ATerm.INT;
	}
	
	public boolean isStr(ATerm t){
		if(isAppl(t)){
			return (((ATermAppl) t).isQuoted()) && ((ATermAppl) t).getArity() == 0;
		}
		return false;
	}
	
	public boolean isReal(ATerm t){
		return (t.getType() == ATerm.REAL);
	}
	
	public boolean isAppl(ATerm t){
		return t.getType() == ATerm.APPL;
	}
	
	public boolean isList(ATerm t){
		return t.getType() == ATerm.LIST;
	}
	
	public boolean isBlob(ATerm t){
		return t.getType() == ATerm.BLOB;
	}
	
	public ATerm getArgs(ATerm t){
		return ((ATermAppl) t).getArguments();
	}
	
	public int size(ATerm l){
		return ((ATermList) l).getLength();
	}
	
	public ATerm first(ATerm l){
		ATermList lst = (ATermList) l;
		if(!lst.isEmpty()){
			return lst.elementAt(0);
		}
		return Undefined;
		// throw new ToolBusError("function first cannot be applied to empty list");
	}
	
	public ATerm next(ATerm l){
		ATermList lst = (ATermList) l;
		if(lst.isEmpty()){
			return lst;
		}
		return lst.getNext();
	}
	
	public boolean member(ATerm e, ATerm l){
		ATermList lst = (ATermList) l;
		int length = lst.getLength();
		for(int i = 0; i < length; i++){
			if(e.isEqual(lst.elementAt(i))) return true;
		}
		return false;
	}
	
	public boolean subset(ATerm l1, ATerm l2){
		ATerm terml2 = l2;
		
		ATermList lst1 = (ATermList) l1;
		int length1 = lst1.getLength();
		for(int i = 0; i < length1; i++){
			ATerm e = lst1.elementAt(i);
			if(!member(e, terml2)){
				return false;
			}
			terml2 = delete(terml2, e);
		}
		return true;
	}
	
	public ATermList delete(ATerm l, ATerm e){
		ATermList lst = (ATermList) l;
		ATermList res = EmptyList;
		boolean found = false;
		for(int i = lst.getLength() - 1; i >= 0; i--){
			ATerm e2 = lst.elementAt(i);
			if(e2.isEqual(e) && !found)
				found = true;
			else res = makeList(e2, res);
		}
		return res;
	}
	
	public ATerm diff(ATerm l1, ATerm l2){
		ATermList lst1 = (ATermList) l1;
		ATermList res = EmptyList;
		for(int i = lst1.getLength() - 1; i >= 0; i--){
			ATerm e = lst1.elementAt(i);
			if(!member(e, l2)) res = makeList(e, res);
		}
		return res;
	}
	
	public ATerm inter(ATerm l1, ATerm l2){
		ATermList lst1 = (ATermList) l1;
		ATermList res = EmptyList;
		for(int i = lst1.getLength() - 1; i >= 0; i--){
			ATerm e = lst1.elementAt(i);
			if(member(e, l2)) res = makeList(e, res);
		}
		// System.err.println("inter(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}
	
	public ATerm join(ATerm l1, ATerm l2){
		// if(l1 == null)
		// return l2;
		// if(l2 == null)
		// return l1;
		ATermList lst1 = isList(l1) ? (ATermList) l1 : makeList(l1);
		ATermList res = isList(l2) ? (ATermList) l2 : makeList(l2);
		for(int i = lst1.getLength() - 1; i >= 0; i--){
			ATerm e = lst1.elementAt(i);
			res = makeList(e, res);
		}
		// System.err.println("join(" + l1 + ", " + l2 + ") ==> " + res);
		return res;
	}
	
	public ATerm concat(ATerm s1, ATerm s2){
		String str1 = isStr(s1) ? ((ATermAppl) s1).getName() : s1.toString();
		String str2 = isStr(s1) ? ((ATermAppl) s2).getName() : s2.toString();
		String res = str1 + str2;
		AFun af = makeAFun(res, 0, true);
		return makeAppl(af);
	}
	
	public ATerm index(ATerm l, int i){
		ATerm res;
		try{
			res = ((ATermList) l).elementAt(i - 1);
		}catch(IllegalArgumentException iaex){
			throw new IllegalArgumentException("An index out of bounds exception occured while retrieving the term at index: "+i+", from the following list: "+l);
		}
		return res;
	}
	
	public ATerm replace(ATerm l, int n, ATerm e){
		ATermList lst = (ATermList) l;
		ATermList res = EmptyList;
		for(int i = lst.getLength() - 1; i >= 0; i--){
			ATerm elem = (i == n - 1) ? e : lst.elementAt(i);
			res = makeList(elem, res);
		}
		return res;
	}
	
	public ATerm put(ATerm l, ATerm k, ATerm v){
		ATermList pair = makeList(k, makeList(v));
		return makeList(pair, (ATermList) l);
	}
	
	public ATerm get(ATerm l, ATerm k){
		ATermList lst = (ATermList) l;
		for(ATermList pair = (ATermList) lst.getFirst(); !lst.isEmpty(); lst = lst.getNext()){
			if(k.isEqual(pair.getFirst())) return pair.getLast();
		}
		return Undefined;
	}
	
	public boolean isVar(ATerm t){
		return t.getType() == VAR && !((TBTermVar) t).isResultVar();
	}
	
	public boolean isResultVar(ATerm t){
		return t.getType() == VAR && ((TBTermVar) t).isResultVar();
	}
	
	public boolean isAnyVar(ATerm t){
		return t.getType() == VAR;
	}
	
	public TBTermVar replaceAssignableVar(TBTermVar v, Environment env) throws ToolBusException{
		// System.err.println("replaceAssignableVar: " + v + "; " + env);
		
		Binding b = env.getBinding(v);
		// System.err.println("Binding = " + b.var + ";" + b.val);
		if(b == null || (b.getVal() == Undefined)){
			return v;
		}
		if(b.isFormal() && isResultVar(b.getVal())){
			return replaceAssignableVar((TBTermVar) b.getVal(), env);
		}
		return b.getVar();
	}
	
	/**
	 * Replace the formals in ATerm t by their values using Environment env.
	 * 
	 * @param t
	 *            Aterm containing formals
	 * @param env
	 *            environment to be used.
	 */
	public ATerm replaceFormals(ATerm t, Environment env) throws ToolBusException{
		if(env.size() == 0) return t;
		
		switch(t.getType()){
			case ATerm.BLOB:
			case ATerm.INT:
			case ATerm.PLACEHOLDER:
			case ATerm.REAL:
				return t;
				
			case VAR:
				return env.replaceFormal((TBTermVar) t);
				
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) t;
				
				AFun afun = apt.getAFun();
				ATerm args[] = apt.getArgumentArray();
				ATerm cargs[] = new ATerm[args.length];
				int nargs = args.length;
				if(nargs == 0) return t;
				for(int i = 0; i < nargs; i++){
					cargs[i] = replaceFormals(args[i], env);
				}
				return makeAppl(afun, cargs);
				
			case ATerm.LIST:
				ATermList lst = EmptyList;
				ATermList tlst = (ATermList) t;
				for(int i = tlst.getLength() - 1; i >= 0; i--){
					lst = lst.insert(replaceFormals(tlst.elementAt(i), env));
				}
				return lst;
		}
		throw new ToolBusInternalError("illegal ATerm in replaceFormals: " + t);
	}
	
	/**
	 * Transform a term into a pattern that can be used by tool interfaces.
	 */
	public ATerm makePattern(ATerm t){
		if(t == Undefined) return t;
		
		switch(t.getType()){
			case ATerm.BLOB:
				return BlobPlaceholder;
				
			case ATerm.INT:
				return IntPlaceholder;
				
			case ATerm.PLACEHOLDER:
				return t;
				
			case ATerm.REAL:
				return RealPlaceholder;
				
			case VAR:
				TBTermVar var = (TBTermVar) t;
				ATerm type = var.getVarType();
				return makePlaceholder(type);
				
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) t;
				if(isBoolean(apt)){
					return BoolPlaceholder;
				}
				AFun fun = apt.getAFun();
				ATerm args[] = apt.getArgumentArray();
				int nargs = args.length;
				if(nargs == 0){
					if(fun.isQuoted()){
						return StrPlaceholder;
					}
					return apt;
				}
				
				ATerm vargs[] = new ATerm[nargs];
				for(int i = 0; i < nargs; i++){
					vargs[i] = makePattern(args[i]);
				}
				return makeAppl(fun, vargs);
				
			case ATerm.LIST:
				ATermList lst = EmptyList;
				ATermList tlst = (ATermList) t;
				for(int i = tlst.getLength() - 1; i >= 0; i--){
					lst = lst.insert(makePattern(tlst.elementAt(i)));
				}
				return lst;
				
		}
		throw new ToolBusInternalError("illegal ATerm in getType: " + t);
	}
	
	/**
	 * Replace all variables in an ATerm by their value.
	 */
	public ATerm substitute(ATerm t, Environment env){
		if(t == Undefined) return t;
		
		switch(t.getType()){
			case ATerm.BLOB:
			case ATerm.INT:
			case ATerm.PLACEHOLDER:
			case ATerm.REAL:
				return t;
				
			case VAR:
				TBTermVar var = (TBTermVar) t;
				if(var.isResultVar()) return var;
					
				return env.getValue(var);
				
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) t;
				if(apt.getArity() == 0) return t;
				
				AFun afun = apt.getAFun();
				ATerm args[] = apt.getArgumentArray();
				ATermList applAnnos = apt.getAnnotations();
				
				int nargs = args.length;
				ATerm vargs[] = new ATerm[nargs];
				for(int i = 0; i < nargs; i++){
					vargs[i] = substitute(args[i], env);
				}
				return makeAppl(afun, vargs, applAnnos);
				
			case ATerm.LIST:
				ATermList tlst = (ATermList) t;
				ATermList listAnnos = t.getAnnotations();
				
				if(tlst == EmptyList) return t;
				
				int len = tlst.getLength();
				ATerm[] listContent = new ATerm[len];
				for(int i = len - 1; i >= 0; i--){
					listContent[i] = tlst.getFirst();
					tlst = tlst.getNext();
				}
				
				ATermList lst = EmptyList;
				for(int i = 0; i < len; i++){
					lst = lst.insert((substitute(listContent[i], env)));
				}
				
				lst = (ATermList) lst.setAnnotations(listAnnos);
				
				return lst;
		}
		throw new ToolBusInternalError("Illegal ATerm in substitute: " + t);
	}
	
	/**
	 * Replaces all variables in an ATerm by their value. If a variable result variable is present
	 * the full substitue can not be completed and null will be returned instead.
	 * @param t
	 *            The term in which variables need to be substituted.
	 * @param env
	 *            The environment from which the variable values can be retrieved.
	 * @return A complete ATerm tree that doesn't contain any variables; null if the substitute could
	 * not be completed.
	 */
	public ATerm fullSubstitute(ATerm t, Environment env){
		if(t == Undefined) return t;
		
		switch(t.getType()){
			case ATerm.BLOB:
			case ATerm.INT:
			case ATerm.PLACEHOLDER:
			case ATerm.REAL:
				return t;
				
			case VAR:
				TBTermVar var = (TBTermVar) t;
				if(var.isResultVar()) return null;
					
				return env.getValue(var);
				
			case ATerm.APPL:
				ATermAppl apt = (ATermAppl) t;
				if(apt.getArity() == 0) return t;
				
				AFun afun = apt.getAFun();
				ATerm args[] = apt.getArgumentArray();
				ATermList applAnnos = apt.getAnnotations();
				
				int nargs = args.length;
				ATerm vargs[] = new ATerm[nargs];
				for(int i = 0; i < nargs; i++){
					ATerm result = fullSubstitute(args[i], env);
					if(result == null) return null;
					vargs[i] = result;
				}
				return makeAppl(afun, vargs, applAnnos);
				
			case ATerm.LIST:
				ATermList tlst = (ATermList) t;
				ATermList listAnnos = t.getAnnotations();
				
				if(tlst == EmptyList) return t;
				
				int len = tlst.getLength();
				ATerm[] listContent = new ATerm[len];
				for(int i = len - 1; i >= 0; i--){
					listContent[i] = tlst.getFirst();
					tlst = tlst.getNext();
				}
				
				ATermList lst = EmptyList;
				for(int i = 0; i < len; i++){
					ATerm result = fullSubstitute(listContent[i], env);
					if(result == null) return null;
					lst = lst.insert(result);
				}

				lst = (ATermList) lst.setAnnotations(listAnnos);
				
				return lst;
		}
		throw new ToolBusInternalError("Illegal ATerm in substitute: " + t);
	}
	
	public boolean match(ATerm left, Environment leftEnv, ATerm right, Environment rightEnv){
		List<Binding> leftDeltaEnv = new ArrayList<Binding>();
		List<Binding> rightDeltaEnv = new ArrayList<Binding>();
		
		boolean matches = performMatch(left, leftEnv, leftDeltaEnv, right, rightEnv, rightDeltaEnv);
		if(matches){
			Iterator<Binding> leftDeltaEnvIterator = leftDeltaEnv.iterator();
			while(leftDeltaEnvIterator.hasNext()){
				Binding deltaBinding = leftDeltaEnvIterator.next();
				leftEnv.assignVar(deltaBinding.getVar(), deltaBinding.getVal());
			}
			
			Iterator<Binding> rightDeltaEnvIterator = rightDeltaEnv.iterator();
			while(rightDeltaEnvIterator.hasNext()){
				Binding deltaBinding = rightDeltaEnvIterator.next();
				rightEnv.assignVar(deltaBinding.getVar(), deltaBinding.getVal());
			}
		}
		
		return matches;
	}
	
	public boolean matchPatternToValue(ATerm left, Environment leftEnv, ATerm right){
		List<Binding> leftDeltaEnv = new ArrayList<Binding>();
		
		boolean matches = performPatternMatch(left, leftEnv, right, leftDeltaEnv);
		if(matches){
			Iterator<Binding> deltaEnvIterator = leftDeltaEnv.iterator();
			while(deltaEnvIterator.hasNext()){
				Binding deltaBinding = deltaEnvIterator.next();
				leftEnv.assignVar(deltaBinding.getVar(), deltaBinding.getVal());
			}
		}
		
		return matches;
	}
	
	public boolean patternMatchesToValue(ATerm pattern, Environment patternEnv, ATerm value){
		List<Binding> deltaEnv = new ArrayList<Binding>();
		
		return performPatternMatch(pattern, patternEnv, value, deltaEnv);
	}
	
	private boolean performPatternMatch(ATerm pattern, Environment patternEnv, ATerm value, List<Binding> deltaEnv){
		switch(pattern.getType()){
			case VAR:
				TBTermVar pVar = (TBTermVar) pattern;
				if(pVar.isResultVar()){
					if(Functions.compatibleTypes(pVar.getVarType(), value)){
						Binding deltaBinding = new Binding(pVar, value);
						deltaEnv.add(deltaBinding);
						return true;
					}
					return false;
				}
				return performPatternMatch(patternEnv.getValue(pVar), patternEnv, value, deltaEnv);
				
			case ATerm.APPL:
				if(value.getType() != ATerm.APPL) return false;
				
				ATermAppl pa = (ATermAppl) pattern;
				ATermAppl va = (ATermAppl) value;
				if(pa.getAFun() != va.getAFun()) return false;
				
				ATerm[] patternChildren = pa.getArgumentArray();
				ATerm[] valueChildren = va.getArgumentArray();
				for(int i = patternChildren.length - 1; i >= 0; i--){
					if(!performPatternMatch(patternChildren[i], patternEnv, valueChildren[i], deltaEnv)) return false;
				}
				
				return true;
			case ATerm.LIST:
				if(value.getType() != ATerm.LIST) return false;
				
				ATermList pl = (ATermList) pattern;
				ATermList vl = (ATermList) value;
				int plLength = pl.getLength();
				if(plLength != vl.getLength()) return false;
				while(pl != EmptyList){
					if(!performPatternMatch(pl.getFirst(), patternEnv, vl.getFirst(), deltaEnv)) return false;
					pl = pl.getNext();
					vl = vl.getNext();
				}
				
				return true;
			case ATerm.PLACEHOLDER:
			case ATerm.INT:
			case ATerm.REAL:
			case ATerm.BLOB:
				return ((pattern.hasAnnotations() ? pattern.removeAnnotations() : pattern) == (value.hasAnnotations() ? value.removeAnnotations() : value));
			default:
				throw new ToolBusInternalError("Illegal ATerm pattern in matchPatternToValue: " + pattern);
		}
	}
	
	private boolean performMatch(ATerm left, Environment leftEnv, List<Binding> leftDeltaEnv, ATerm right, Environment rightEnv, List<Binding> rightDeltaEnv){
		ATerm rightTerm = right;
		if(rightTerm.getType() == VAR){
			TBTermVar rightVar = (TBTermVar) rightTerm;
			if(rightVar.isResultVar()){
				if(left.getType() == VAR){
					TBTermVar leftVar = (TBTermVar) left;
					if(!leftVar.isResultVar()){
						ATerm leftValue = leftEnv.getValue(leftVar);
						
						if(Functions.compatibleTypes(rightVar.getVarType(), leftValue)){
							ATerm fullySubstitutedLeftValue = fullSubstitute(leftValue, leftEnv);
							if(fullySubstitutedLeftValue != null){
								Binding deltaBinding = new Binding(rightVar, fullySubstitutedLeftValue);
								rightDeltaEnv.add(deltaBinding);
								return true;
							}
							return false;
						}
					}else{
						return false;
					}
				}else{
					if(Functions.compatibleTypes(rightVar.getVarType(), left)){
						ATerm fullySubstitutedLeft = fullSubstitute(left, leftEnv);
						if(fullySubstitutedLeft != null){
							Binding deltaBinding = new Binding(rightVar, fullySubstitutedLeft);
							rightDeltaEnv.add(deltaBinding);
							return true;
						}
						return false;
					}
				}
				return false;
			}
			
			rightTerm = rightEnv.getValue(rightVar);
		}
		
		switch(left.getType()){
			case VAR:
				TBTermVar pVar = (TBTermVar) left;
				if(pVar.isResultVar()){
					if(Functions.compatibleTypes(pVar.getVarType(), rightTerm)){
						ATerm fullySubstitutedRightValue = fullSubstitute(rightTerm, rightEnv);
						if(fullySubstitutedRightValue != null){
							Binding deltaBinding = new Binding(pVar, fullySubstitutedRightValue);
							leftDeltaEnv.add(deltaBinding);
							return true;
						}
						return false;
					}
					return false;
				}
				return performMatch(leftEnv.getValue(pVar), leftEnv, leftDeltaEnv, rightTerm, rightEnv, rightDeltaEnv);
				
			case ATerm.APPL:
				if(rightTerm.getType() != ATerm.APPL) return false;
				
				ATermAppl pa = (ATermAppl) left;
				ATermAppl va = (ATermAppl) rightTerm;
				if(pa.getAFun() != va.getAFun()) return false;
				
				ATerm[] patternChildren = pa.getArgumentArray();
				ATerm[] valueChildren = va.getArgumentArray();
				for(int i = patternChildren.length - 1; i >= 0; i--){
					if(!performMatch(patternChildren[i], leftEnv, leftDeltaEnv, valueChildren[i], rightEnv, rightDeltaEnv)) return false;
				}
				
				return true;
			case ATerm.LIST:
				if(rightTerm.getType() != ATerm.LIST) return false;
				
				ATermList pl = (ATermList) left;
				ATermList vl = (ATermList) rightTerm;
				int plLength = pl.getLength();
				if(plLength != vl.getLength()) return false;
				while(pl != EmptyList){
					if(!performMatch(pl.getFirst(), leftEnv, leftDeltaEnv, vl.getFirst(), rightEnv, rightDeltaEnv)) return false;
					pl = pl.getNext();
					vl = vl.getNext();
				}
				
				return true;
			case ATerm.PLACEHOLDER:
			case ATerm.INT:
			case ATerm.REAL:
			case ATerm.BLOB:
				return ((left.hasAnnotations() ? left.removeAnnotations() : left) == (rightTerm.hasAnnotations() ? rightTerm.removeAnnotations() : rightTerm));
			default:
				throw new ToolBusInternalError("Illegal ATerm pattern in matchPatternToValue: " + left);
		}
	}
	
	public boolean mightMatch(ATerm terma, ATerm termb){
		switch(terma.getType()){
			case VAR:
				return Functions.compatibleTypes(((TBTermVar) terma).getVarType(), termb);
			case ATerm.BLOB:
				if(isAnyVar(termb)) return true;
				return terma.isEqual(termb) || (termb == StrPlaceholder) || (termb == TermPlaceholder);
				
			case ATerm.INT:
				if(isAnyVar(termb)) return true;
				return terma.isEqual(termb) || (termb == IntPlaceholder) || (termb == TermPlaceholder);
				
			case ATerm.REAL:
				if(isAnyVar(termb)) return true;
				return terma.isEqual(termb) || (termb == RealPlaceholder) || (termb == TermPlaceholder);
				
			case ATerm.PLACEHOLDER:
				if(isAnyVar(termb)) return true;
				
				if(terma == TermPlaceholder) return true;
				
				switch(termb.getType()){
					case ATerm.INT:
						return (terma == IntPlaceholder);
					case ATerm.REAL:
						return (terma == RealPlaceholder);
					case ATerm.APPL:
						return matchPlaceholder((ATermAppl) termb, (ATermPlaceholder) terma, true);
					case ATerm.BLOB:
						return (terma == StrPlaceholder);
					case ATerm.LIST:
						return matchListPlaceholder((ATermList) termb, (ATermPlaceholder) terma, true);
				}
				return false;
				
			case ATerm.APPL:
				if(isAnyVar(termb)) return true;
				ATermAppl apta = (ATermAppl) terma;
				
				switch(termb.getType()){
					case ATerm.PLACEHOLDER:
						return matchPlaceholder(apta, (ATermPlaceholder) termb, false);
						
					case ATerm.APPL:
						ATermAppl aptb = (ATermAppl) termb;
						if(apta.getAFun() != aptb.getAFun()) return false;
							
						ATerm a_args[] = apta.getArgumentArray();
						ATerm b_args[] = aptb.getArgumentArray();
						for(int i = a_args.length - 1; i >= 0; i--){
							if(!mightMatch(a_args[i], b_args[i])) return false;
						}
						return true;
					default:
						return false;
				}
				
			case ATerm.LIST:
				if(isAnyVar(termb)) return true;
				
				ATermList lsta = (ATermList) terma;
				switch(termb.getType()){
					case ATerm.PLACEHOLDER:
						return matchListPlaceholder(lsta, (ATermPlaceholder) termb, false);
						
					case ATerm.LIST:
						ATermList lstb = (ATermList) termb;
						if(lsta.getLength() != lstb.getLength()) return false;
						
						while(!lsta.isEmpty()){
							if(!mightMatch(lsta.getFirst(), lstb.getFirst())) return false;
							lsta = lsta.getNext();
							lstb = lstb.getNext();
						}
						return true;
					default:
						return false;
				}
				
			default:
				throw new ToolBusInternalError("illegal ATerm in performMatch: " + terma);
		}
	}
	
	private boolean matchListPlaceholder(ATermList terma, ATermPlaceholder tb, boolean swapargs){
		ATermList ta = terma;
		
		if(tb == ListPlaceholder) return true;
		
		ATerm placeholder = tb.getPlaceholder();
		if(placeholder.getType() == ATerm.APPL){
			ATermAppl aplPlaceholder = (ATermAppl) placeholder;
			if(aplPlaceholder.getName() != "list") return false;
			
			int arity = aplPlaceholder.getArity();
			
			if(arity == 1){
				ATerm elemtype = aplPlaceholder.getArgument(0);
				ATermPlaceholder elm = makePlaceholder(elemtype);
				
				while(!ta.isEmpty()){
					if(!swapMatch(elm, ta.getFirst(), swapargs)) return false;
					
					ta = ta.getNext();
				}
				return true;
			}
			
			if(arity != ta.getLength()) return false;
			
			for(int i = 0; i < arity; i++){
				ATerm elemtype = aplPlaceholder.getArgument(i);
				ATermPlaceholder elemPlaceholder = makePlaceholder(elemtype);
				
				if(!swapMatch(elemPlaceholder, ta.getFirst(), swapargs)) return false;
				
				ta = ta.getNext();
			}
			return true;
		}
		return swapMatch(ta, placeholder, swapargs);
	}
	
	private boolean matchPlaceholder(ATermAppl ta, ATermPlaceholder tb, boolean swapargs){
		if(tb == StrPlaceholder && ta.getArity() == 0) return true;
		else if(tb == TermPlaceholder) return true;
		
		ATerm placeholder = tb.getPlaceholder();
		if(placeholder.getType() == ATerm.APPL){
			ATermAppl aplPlaceholder = (ATermAppl) placeholder;
			int arity = aplPlaceholder.getArity();
			
			if(arity == 0) return (ta.getName() == aplPlaceholder.getName());
			
			if(arity != ta.getArity()) return false;
			
			for(int i = arity - 1; i >= 0; i--){
				ATerm elemtype = aplPlaceholder.getArgument(i);
				ATermPlaceholder elemPlaceholder = makePlaceholder(elemtype);
				
				if(!swapMatch(elemPlaceholder, ta.getArgument(i), swapargs)) return false;
			}
			return true;
			
		}
		return swapMatch(ta, placeholder, swapargs);
	}
	
	private boolean swapMatch(ATerm ta, ATerm tb, boolean swapargs){
		return swapargs ? mightMatch(tb, ta) : mightMatch(ta, tb);
	}
}
