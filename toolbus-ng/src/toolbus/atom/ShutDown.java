package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * @author paulk, Jul 26, 2002
 */
public class ShutDown extends Atom{
	private final Ref arg;
	
	public ShutDown(ATerm trm, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		arg = new Ref(trm);
		setAtomArgs(arg);
	}
	
	public ProcessExpression copy(){
		Atom a = new ShutDown(arg.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(isEnabled()){
			getToolBus().shutdown(arg.value);
			return true;
		}
		
		return false;
	}
}
