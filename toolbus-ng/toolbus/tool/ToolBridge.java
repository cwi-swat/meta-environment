package toolbus.tool;
import aterm.*;

/**
 * @author paulk, Jul 31, 2002
 */
public interface ToolBridge {
	public ATermFactory getFactory();
	
	public void sndTerm(ATerm trm);
	/**
	 * Method init.
	 * @param example
	 */
	void init(Object toolinstance);
	
	void run();

}
