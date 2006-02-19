package toolbus.atom;

import java.util.Stack;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessExpression;
import toolbus.process.ProcessInstance;
import aterm.ATermList;

public class EndScope extends Atom {
	private Ref refformals;

	public EndScope(ATermList formals, TBTermFactory tbfactory) {
		super(tbfactory);
		refformals = new Ref(formals);
		setAtomArgs(this.refformals);
	}

	public ProcessExpression copy() {
		Atom a = new EndScope((ATermList) refformals.value, tbfactory);
		 a.copyAtomAttributes(this);
		 return a;
	}
	
	 public void replaceFormals(Environment env) throws ToolBusException{
		 return;
	 }
	 
	 public void compile(ProcessInstance P, Stack<String> calls, Environment env, State follows) throws ToolBusException {
		 env.removeBindings(((ATermList) refformals.value)); 
	 }

	public boolean execute() throws ToolBusException {
		if (isEnabled()) {
			Environment env = getEnv();
			System.err.println("EndScope.execute: " + env);
			env.removeBindings(((ATermList) refformals.value));
			return true;
		} else
			return false;
	}
}