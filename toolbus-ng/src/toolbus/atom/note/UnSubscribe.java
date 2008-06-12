/*
 * Created on Jun 25, 2005 @author paulk
 */
package toolbus.atom.note;

import toolbus.TBTermFactory;
import toolbus.atom.Atom;
import toolbus.atom.Ref;
import toolbus.exceptions.ToolBusException;
import toolbus.exceptions.ToolBusExecutionException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * The unsubscribe atom
 */
public class UnSubscribe extends Atom{
	private final ATerm msgpat;
	
	public UnSubscribe(ATerm msgpat, TBTermFactory tbfactory, PositionInformation posInfo){
		super(tbfactory, posInfo);
		this.msgpat = msgpat;
		setAtomArgs(new Ref[]{new Ref(msgpat)});
	}
	
	public ProcessExpression copy(){
		Atom a = new UnSubscribe(msgpat, tbfactory, getPosInfo());
		a.copyAtomAttributes(this);
		return a;
	}
	
	public boolean execute() throws ToolBusException{
		if(!isEnabled()) return false;
		
		ATerm unsubscribePattern = tbfactory.fullSubstitute(msgpat, getEnv());
		if(unsubscribePattern == null) throw new ToolBusExecutionException("Illegal subscription pattern: "+msgpat+".", getPosInfo());
		
		getProcess().unsubscribe(unsubscribePattern);
		
		return true;
	}
}
