package toolbus.tool;
import toolbus.*;

import aterm.*;

/**
 * @author paulk, Jul 30, 2002
 */
public interface ToolInstance {
	
  public ATerm getToolId();

  public void sndEvalToTool(ATerm id, ATermAppl call);

  public boolean getValueFromTool(ATerm id, ATerm trm, Environment env) throws ToolBusException;

  public void sndDoToTool(ATerm id, ATermAppl call);

  public boolean getEventFromTool(ATerm id, ATerm trm, Environment environment) throws ToolBusException;

  public void sndAckToTool(ATerm id, ATerm result) throws ToolBusException;

  public void terminate(ATerm id, String msg);

}
