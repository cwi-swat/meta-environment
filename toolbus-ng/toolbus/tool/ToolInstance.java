package toolbus.tool;
import aterm.*;
import toolbus.*;

/**
 * @author paulk, Jul 30, 2002
 */
public interface  ToolInstance {
  	
  	public ATerm getToolId();
  	
  	public void sndEvalToTool(ATermAppl call);
 	
 	public MatchResult getValue(ATerm trm, Environment env);

	public MatchResult getEvent(ATerm aTerm, Environment environment);

}
