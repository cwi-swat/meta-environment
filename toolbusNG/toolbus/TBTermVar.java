package toolbus;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;


public class TBTermVar extends AbstractTBTerm {

	public TBTermVar() {
		super();
	}
	
	 protected void init(int hashCode, ATermList annos) {
		super.init(hashCode, annos);
	}
	 
	public shared.SharedObject duplicate() {
		TBTermVar clone = new TBTermVar();
		clone.init(hashCode(), getAnnotations(), getAFun(), getArgumentArray());
		return clone;
	}

	public boolean equivalent(shared.SharedObject peer) {
		if (peer instanceof TBTermVar) {
			return super.equivalent(peer);
		}
		return false;
	}

	public int getType() {
		return TBTermFactory.VAR;
	}

	public String getVarName() {
		return ((ATermAppl) getArgument(1)).getName();
	}

	public ATerm getVarType() {
		return getArgument(0);
	}

	public TBTermVar setVarType(ATerm tp) {
		TBTermVar v = TBTermFactory.makeTBTermVar(getVarName(), tp, getArgument(2));
		//System.err.println("setVarType(" + tp + "): " + this + " => " + v);
		return v;
	}
	
	public boolean isResultVar(){
		return getArgument(2) == TBTermFactory.True;
	}
}
