
/**
 * @author paulk, Jul 22, 2002
 */

package toolbus.process;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.atom.AtomSet;

import aterm.ATermList;

public class ProcessCall implements ProcessExpression {
	private String name;
	private ATermList args;
	private ProcessExpression PE;
	
	public ProcessCall(String name, ATermList args){
		this.name = name;
		this.args = args;
		//System.out.println("ProcessCall(\"" + name + "\", " + args + ")");
	}

 	public ProcessExpression copy(){
 		return new ProcessCall(name, args);
	}

	public void compile(ProcessInstance P, AtomSet follows)
	throws ToolBusException
	 {
		ToolBus TB = P.getToolBus();
		ProcessDefinition PD = TB.getProcessDefinition(name);
		//System.out.println("formals = " + PD.getFormals());
		PD.setActuals(args);
		PE = PD.compile(P, follows);
		//System.out.println(PE);
	}

	public AtomSet getFirst() {
		return PE.getFirst();
	}

	public AtomSet getFollow() {
		return PE.getFollow();
	}
	
	public void extendFollow(AtomSet f){
		PE.extendFollow(f);
	}

	public AtomSet getAtoms() {
		return PE.getAtoms();
	}
	
	public String toString(){
		return "ProcessCall(" + name + ", " + args + ")";
	}
}
