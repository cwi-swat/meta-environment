package toolbus.tool;
import toolbus.*;

import aterm.*;

/**
 * @author paulk, Jul 30, 2002
 */
public interface ToolInstance {

  public ATerm getToolId();

  public void sndEvalToTool(ATermAppl call, ATerm id);

  public void sndDoToTool(ATermAppl call, ATerm id);

  public void terminate(String msg);

  public boolean getValueFromTool(ATerm trm, Environment env);

  public boolean getEventFromTool(ATerm trm, Environment environment);

}
