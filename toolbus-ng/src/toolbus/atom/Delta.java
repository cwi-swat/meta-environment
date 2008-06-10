package toolbus.atom;

import toolbus.State;
import toolbus.TBTermFactory;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;

/**
 * @author paulk, Jul 24, 2002
 */

public class Delta extends Atom{
	private final static State empty = new State();
	
	public Delta(TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
	}
	
	public ProcessExpression copy(){
		Atom a = new Delta(tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public State getFirst(){
		return empty;
	}
	
	public boolean execute(){
		return false;
	}
	
}
