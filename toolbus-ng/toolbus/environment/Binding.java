package toolbus.environment;

import toolbus.TBTermVar;
import aterm.ATerm;

/**
 * Binding implements one (variable, value) pair.
 */

public class Binding {
	TBTermVar var;                 // The variable in question
	ATerm val;					   // Its value
	String name;                   // Its cached name (for efficiency)

	boolean formal = false;      // Is this a formal parameter or a local variable?
	boolean assignable = false;  // Are there assignments to this variable in the current process expression?
	
	public Binding(TBTermVar var, ATerm val, boolean isFormal) {
		this.var = var;
		this.val = val;
		this.formal = isFormal;
		name = var.getVarName();
	}
	
	public Binding(TBTermVar var, ATerm val) {
		this(var, val, true);
	}
	
	public TBTermVar getVar(){
		return var;
	}
	
	public ATerm getVal(){
		return val;
	}
	
	public boolean isFormal(){
		return formal;
	}
	
	public void setFormal(boolean b){
		formal = b;
	}
	
	public boolean isAssignable(){
		return assignable;
	}
	
	public void setAssignable(boolean b){
		 assignable = b;
	}
	
	public String getName(){
		return name;
	}
	
	public String toString(){
		String op = isFormal() ? ":->":" : ";
		if(assignable)
			op += "@";
		return var + " " + op  + " " + val;
	}
}