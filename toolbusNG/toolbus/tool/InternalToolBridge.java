package toolbus.tool;
import aterm.*;

import toolbus.*;

/**
 * @author paulk, Aug 1, 2002
 */
public class InternalToolBridge implements ToolBridge {
	private ToolBus toolbus;
	
	public InternalToolBridge(ToolBus TB){
		toolbus = TB;
	}
	public void init(Object toolclass){
	}
	
	public void run(){
	}
	
	public ATermFactory getFactory(){
		return toolbus.getFactory();
	}

	public void sndTerm(ATerm trm){
	}
}
