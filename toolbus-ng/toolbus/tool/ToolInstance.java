package toolbus.tool;
import toolbus.*;

import aterm.*;

/**
 * @author paulk, Jul 30, 2002
 */
public interface ToolInstance {

  public ATerm getToolId();

  public void sndEvalToTool(ATermAppl call);

  public void sndDoToTool(ATermAppl call);

  public void terminate(String msg);

  public boolean getValueFromTool(ATerm trm, Environment env);

  public boolean getEventFromTool(ATerm aTerm, Environment environment);

}
