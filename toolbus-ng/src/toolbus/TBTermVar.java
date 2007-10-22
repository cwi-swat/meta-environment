package toolbus;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class TBTermVar extends AbstractTBTerm{
	
	public TBTermVar(TBTermFactory tbfactory, ATermList annos, AFun fun, ATerm[] args){
		super(tbfactory, annos, fun, args);
	}
	
	public shared.SharedObject duplicate(){
		return this;
	}
	
	public boolean equivalent(shared.SharedObject peer){
		if(peer instanceof TBTermVar){
			return super.equivalent(peer);
		}
		return false;
	}
	
	public int getType(){
		return TBTermFactory.VAR;
	}
	
	public String getVarName(){
		return ((ATermAppl) getArgument(1)).getName();
	}
	
	public String getExternalVarName(){
		String name = getVarName();
		int i = name.indexOf('$');
		if(i > 0) return name.substring(0, i);
		
		return name;
	}
	
	public ATerm getVarType(){
		return getArgument(0);
	}
	
	public TBTermVar setVarType(ATerm tp){
		TBTermVar v = tbfactory.makeTBTermVar(getVarName(), tp, getArgument(2));
		// System.err.println("setVarType(" + tp + "): " + this + " => " + v);
		return v;
	}
	
	public boolean isResultVar(){
		return getArgument(2) == tbfactory.True;
	}
}
