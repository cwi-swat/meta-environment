/**
 * @author paulk
 */

package toolbus;
import java.util.Vector;
import java.util.Hashtable;
import java.util.ListIterator;
import aterm.*;

import toolbus.atom.*;
import toolbus.process.*;
import toolbus.tool.*;

public class ToolBus {
	private ATermFactory factory;
	private Vector processes;
	private Vector procdefs;
	private Vector tooldefs;
	private Hashtable toolinstances;
	
	public ToolBus(){
		this.factory = TBTerm.factory;
		AtomSet empty = new AtomSet();
		processes = new Vector();
		procdefs = new Vector();
		tooldefs = new Vector();
		toolinstances = new Hashtable();
	}

	public ToolBus(ProcessExpression Ps[])
	throws ToolBusException
	 {
		this(); 
		for (int i = 0; i < Ps.length; i++) {
			addProcess(Ps[i]);
		}
	}
	
	public ATermFactory getFactory(){
		return factory;
	}
	
	public Vector getProcesses(){
		return processes;
	}
	
	public void addProcessDefinition(ProcessDefinition PD)
	throws ToolBusException
	{
		String name = PD.getName();
		for(int i = 0; i < procdefs.size(); i++){
			ProcessDefinition PD2 = (ProcessDefinition) procdefs.elementAt(i);
			if(name == PD2.getName())
				throw new ToolBusException("duplicate definition of process " + name);
		}
		procdefs.add(PD);
	}
	
	public ProcessInstance addProcess(ProcessExpression PE)
	throws ToolBusException
	{
		ProcessInstance P = new ProcessInstance(this, PE);
		processes.add(P);
		return P;
	}
	
	public ProcessDefinition getProcessDefinition(String name)
	throws ToolBusException	
	{
		for(int i = 0; i < procdefs.size(); i++){
			ProcessDefinition PD = (ProcessDefinition) procdefs.elementAt(i);
			if(name == PD.getName())
				return PD;
		}
		throw new ToolBusException("no definition for process "  + name);
	}
	
	public void addTooldefinition(ToolDefinition TD)
	throws ToolBusException	
	{
		String name = TD.getName();
		for(int i = 0; i < tooldefs.size(); i++){
			ToolDefinition TD2 = (ToolDefinition) tooldefs.elementAt(i);
			if(name == TD2.getName())
				throw new ToolBusException("duplicate definition of tool " + name);
		}
		tooldefs.add(TD);
	}
	
	public ToolDefinition getToolDefinition(String name)
	throws ToolBusException	
	{
		for(int i = 0; i < tooldefs.size(); i++){
			ToolDefinition TD = (ToolDefinition) tooldefs.elementAt(i);
			if(name == TD.getName())
				return TD;
		}
		throw new ToolBusException("no definition for tool " + name);
	}
	
	public void addTool(ToolInstance TI){
		toolinstances.put(TI.getToolId(), TI);
	}
	
	public ToolInstance getTool(ATerm toolId){
		return (ToolInstance) toolinstances.get(toolId);
	}

	public void execute() {
		boolean work = true;
		int n = 200;
		
		try {
			while (work) {
				n--;
				work = n > 0;
				for (int i = 0; i < processes.size(); i ++){
					ProcessInstance P = (ProcessInstance) processes.elementAt(i);
					//System.out.println("ToolBus -- " + P);
				    P.step();
					//if (P.isTerminated()) {
					//	processes.remove(P);
					//}
				}
			}
		}
		catch (ToolBusException e) {
			System.out.println(e.getMessage());
		}
		System.out.println("ToolBus halted");
	}
}
