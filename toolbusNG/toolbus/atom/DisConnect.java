/*
 * Created on Oct 6, 2005
 *
 * TODO To change the template for this generated file go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
package toolbus.atom;

import toolbus.TBTermFactory;
import toolbus.ToolBusException;
import toolbus.process.ProcessExpression;
import aterm.ATerm;

/**
 * @author paulk
 *
 * TODO To change the template for this generated type comment go to
 * Window - Preferences - Java - Code Style - Code Templates
 */
public class DisConnect extends Atom {
	private Ref toolId;
	
	public  DisConnect(ATerm toolId, TBTermFactory tbfactory){
	    super(tbfactory);
		this.toolId = new Ref(toolId);
		setAtomArgs(this.toolId);
	  }
	  
	  public ProcessExpression copy(){
	    Atom a = new DisConnect(toolId.value, tbfactory);
	    a.copyAtomAttributes(this);
	    return a;
	  }

	/* (non-Javadoc)
	 * @see toolbus.StateElement#execute()
	 */
	public boolean execute() throws ToolBusException {
		if (!isEnabled())
		      return false;
		//System.err.println("DisConnect.execute called, returns false");
		return false;
	}
}
