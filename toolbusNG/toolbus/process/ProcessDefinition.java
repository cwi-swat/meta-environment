/**
 * @author paulk, Jul 21, 2002
 */

package toolbus.process;
import toolbus.Environment;
import toolbus.TBTerm;
import toolbus.ToolBusException;
import toolbus.atom.Assign;
import toolbus.atom.AtomSet;

import aterm.ATerm;
import aterm.ATermList;

public class ProcessDefinition {
	private String name;
	private ATermList formals;
	private ProcessExpression PE;
	private ATermList actuals;

	public ProcessDefinition(
		String name,
		ATermList formals,
		ProcessExpression PE) {
		this.name = name;
		this.formals = formals;
		this.PE = PE;
		
		//System.out.println("procdef " + name + " " + formals + " " + PE);
	}

	public String getName() {
		return name;
	}

	public ATermList getFormals() {
		return formals;
	}
	
	public void setActuals(ATermList actuals){
		this.actuals = actuals;
	}

	public ProcessExpression compile(ProcessInstance P, AtomSet follows) 
	throws ToolBusException
	{
		
		if (actuals.getLength() != formals.getLength())
			System.out.println(
				"*** " + name + ": mismatch " + formals + " and " + actuals);
				
		//System.out.println("formals = " + formals);
		//System.out.println("actuals = " + actuals);
				
		int nargs = actuals.getLength();
		Environment env = P.getEnv();
		ATermList actuals1 = (ATermList) TBTerm.compileVars(actuals, env);
		//System.out.println("actuals1 = " + actuals1);

		ProcessExpression assigns = null;
		
		ATermList formals1 = formals.getFactory().makeList();
		
		for (int i = 0; i < nargs; i++) {
			ATerm formal = formals.elementAt(i);
			if(TBTerm.isResVar(formal))
				formal = TBTerm.compileVars(TBTerm.changeResVarIntoVar(formal), env);
			else
				formals1 = formals1.append(formal);
			
			ProcessExpression asg =
				new Assign(formal, actuals1.elementAt(i));
			if (i == 0)
				assigns = asg;
			else
				assigns = new Sequence(asg, assigns);
		}
		//System.out.println("formals1 = " + formals1);
		//System.out.println("assigns = " + assigns);
		ProcessExpression PE1 = (assigns == null) ? PE.copy() : new Sequence(assigns, PE.copy());// to copy or not?
		//System.out.println("PE1 = " + PE1);
		env.add(formals1);
		PE1.compile(P, follows);
		env.delete(formals1.getLength());
		return PE1;
	}
	
	
	public String toString(){
		return "ProcessDefinition(" + name + ", " + formals + ", " + PE +")";
	}
}
