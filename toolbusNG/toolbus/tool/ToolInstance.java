package toolbus.tool;
import toolbus.Environment;
import toolbus.MatchResult;

import aterm.ATerm;
import aterm.ATermAppl;

/**
 * @author paulk, Jul 30, 2002
 */
public interface  ToolInstance {
  	
  	public ATerm getToolId();
  	
  	public void sndEvalToTool(ATermAppl call);
  	
  	public void sndDoToTool(ATermAppl call);
  	
  	public void terminate(String msg);
 	
 	public MatchResult getValueFromTool(ATerm trm, Environment env);

	public MatchResult getEventFromTool(ATerm aTerm, Environment environment);

}
