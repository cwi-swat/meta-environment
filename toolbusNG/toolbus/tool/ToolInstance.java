package toolbus.tool;
import aterm.*;
import toolbus.*;

/**
 * @author paulk, Jul 30, 2002
 */
public interface  ToolInstance {
	
	//public void  checkInputSignature(ATermList sig) throws ToolBusException;
	
  	//public ATerm handler(ATermAppl call);
  	
  	public ATerm getToolId();
  	
  	public void sndTermToTool(ATermAppl call);
  	
 
 //	public MatchResult hasValue(ATerm trm, Environment env);
 	
 	public MatchResult getValue(ATerm trm, Environment env);

}
