package toolbus.tool;
import aterm.*;

/**
 * @author paulk, Jul 31, 2002
 */
public interface ToolBridge {

  public ATermFactory getFactory();

 // public void sndValueToToolBus(ATerm trm);

  public ATerm sndEventToToolBus(ATerm trm);

  public void terminate(String msg);

}
