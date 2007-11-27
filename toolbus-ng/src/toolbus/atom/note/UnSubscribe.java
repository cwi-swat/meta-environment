/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * The unsubscribe atom
 */
public class UnSubscribe extends Atom{
	private final Ref msgpat;
	
	public UnSubscribe(ATerm msgpat, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.msgpat = new Ref(msgpat);
		setAtomArgs(this.msgpat);
	}
	
	public ProcessExpression copy(){
		Atom a = new UnSubscribe(msgpat.value, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm unsubscribePattern = tbfactory.fullSubstitute(msgpat.value, getEnv());
		if(unsubscribePattern == null) throw new ToolBusException("Illegal subscription pattern: "+msgpat.value+".");
		
		getProcess().unsubscribe(unsubscribePattern);
		
		return true;
	}
}
