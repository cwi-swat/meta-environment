/**
 * @author paulk, Jul 19, 2002
 */

package toolbus;
import java.util.Vector;
import aterm.*;
import aterm.pure.*;


public class Environment{
	private int vmax;
	private Vector dvec;
	
	private boolean executing;

	public Environment() {
		vmax = 0;
		dvec = new Vector();
		executing = false;
	}
	
	// compile time methods
	
	public void add(ATermList vars){
		//System.out.println("Environment.add(" + vars + "), vmax = " + vmax);
		for(int i = 0; i < vars.getLength(); i++){
			ATerm var = vars.elementAt(i);
			if(var.getType() != ATerm.APPL ||
			  ((ATermAppl) var).getName() != "var")
				throw new ToolBusInternalError("env.add illegal var: " + var);
			dvec.addElement(TBTerm.setVarIndexAndType(var, vmax, TBTerm.getVarType(var)));
			vmax++;
		}
		//System.out.println(dvec + ", vmax = " + vmax);
	}
	
    public void delete(int delta){
    	//System.out.println("delete " + delta + " from " + this);
		vmax -= delta;
		//System.out.println("after delete: " + this);
	}
	
	public int getVarIndex(ATerm var)
	throws ToolBusException
	{
		if(!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
			throw new ToolBusInternalError("Environment.getVarIndex: illegal var " + var);
		String name = TBTerm.getVarName(var);
		for(int i = vmax - 1; i >= 0; i--)
			if(TBTerm.getVarName((ATerm) dvec.elementAt(i)) == name)
				return i;
		throw new ToolBusException("undeclared variable " + name);
	}
	
	public ATerm getVarType(ATerm var){
		if(!(TBTerm.isVar(var) || TBTerm.isResVar(var)))
			throw new ToolBusInternalError("Environment.getVarType: illegal var " + var);
		String name = TBTerm.getVarName(var);
		for(int i = vmax - 1; i >= 0; i--)
			if(TBTerm.getVarName((ATerm) dvec.elementAt(i)) == name)
				return TBTerm.getVarType((ATerm) dvec.elementAt(i));
		throw new ToolBusInternalError("Environment.getVarIndex: undeclared var " + var);
	}
	
	// run-time methods
	
	public void setExecuting(){
		executing = true;
		dvec.trimToSize();
		for(int i = 0; i < dvec.size(); i++)
			dvec.setElementAt(null, i);
	}
	
	public void putVar(ATerm var, ATerm val) {	
		//System.out.println("putVar(" + var + ", " + val +")");
		dvec.setElementAt(val, TBTerm.getVarIndex(var));
	}
	
	public ATerm getVar(ATerm var)
	throws ToolBusException
	{
		
		ATerm val = (ATerm) dvec.elementAt(TBTerm.getVarIndex(var));
		//System.out.println("getVar(" + var + "): " + val);
		if(val == null)
			throw new ToolBusException(var + " has undefined value");
		return val;
	}

	public String toString() {
	//	String res = "env(";
	//	for(int i = 0; i < vmax; i++){
	//		if(i > 0) res = res + ", ";
	//		res = res + dvec.elementAt(i);
	//	}
	//	return res + ")";
		return dvec.toString();
	}
}
