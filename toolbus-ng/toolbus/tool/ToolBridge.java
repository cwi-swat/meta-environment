package toolbus.tool;
import aterm.*;

/**
 * @author paulk, Jul 31, 2002
 */
public interface ToolBridge {
	
	public ATermFactory getFactory();
	
	public void sndValue(ATerm trm);
	
	public void sndEvent(ATerm trm);

}
