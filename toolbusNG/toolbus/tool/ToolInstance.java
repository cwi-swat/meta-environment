package toolbus.tool;
import toolbus.*;

import aterm.*;

/**
 * @author paulk, Jul 30, 2002
 */
public interface ToolInstance {
	
  public ATerm getToolId();

  public void sndEvalToTool(ATermAppl call);

  public boolean getValueFromTool(ATerm trm, Environment env) throws ToolBusException;

  public void sndDoToTool(ATermAppl call);

  public boolean getEventFromTool(ATerm trm, Environment environment) throws ToolBusException;

  public void sndAckToTool(ATerm result) throws ToolBusException;

  public void terminate(String msg);

}
