package toolbus.tool;
import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 31, 2002
 */
public interface ToolBridge {
	
	public ATermFactory getFactory();
	
	public void sndValueToToolBus(ATerm trm);
	
	public void sndEventToToolBus(ATerm trm);
	
	public void terminate(String msg);

}
