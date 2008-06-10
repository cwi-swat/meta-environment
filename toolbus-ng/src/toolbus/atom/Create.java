/**
 * @author paulk, Jul 24, 2002
 */
package toolbus.atom;

import java.util.Stack;
import toolbus.Functions;
import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.TBTermVar;
import toolbus.ToolBus;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessCall;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermList;

public class Create extends Atom{
	private final Ref pcall;
	private final Ref rvar;
	
	public Create(ATerm c, ATerm v, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		pcall = new Ref(c);
		rvar = new Ref(v);
		setAtomArgs(new Ref[]{pcall, rvar});
	}
	
	public ProcessExpression copy(){
		Atom a = new Create(pcall.value, rvar.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public void compile(ProcessInstance P, Stack<String> calls, State follow) throws ToolBusException{
		super.compile(P, calls, follow);
		
		if(pcall.value.getType() != ATerm.APPL) throw new ToolBusException("malformed first argument in create");
		if(!tbfactory.isResultVar(rvar.value)) throw new ToolBusException("second argument of create should be a result variable");
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		String name = ((ATermAppl) pcall.value).getName();
		ATermList cargs = ((ATermAppl) pcall.value).getArguments();
		ATermList evargs = (ATermList) Functions.eval(cargs, getProcess(), getEnv());
		
		ToolBus TB = getToolBus();
		
		ProcessInstance P = TB.addProcess(new ProcessCall(name, evargs, false, TB.getTBTermFactory(), null));
		
		getEnv().assignVar((TBTermVar) rvar.value, tbfactory.makeInt(P.getProcessId()));
		return true;
	}
}
