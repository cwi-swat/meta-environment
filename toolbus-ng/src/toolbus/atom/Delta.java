package toolbus.atom;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */
public class Delta extends Atom{
	
	public Delta(TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
	}

	public ProcessExpression copy(){
		Atom a = new Delta(tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public State getFirst(){
		State deltaState = new State();
		deltaState.addElement(this);
		return deltaState;
	}
	
	public boolean execute(){
		return false;
	}
	
}
