package toolbus.tool.examples;
import toolbus.tool.ToolShield;
import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 30, 2002
 */
public class CounterTool {
  private ToolShield shield;
  private int count = 0;
  private int delay = 5;
  private ATermFactory factory;

  /**
   * Constructor for Example.
   */
  public CounterTool(ToolShield shield) {
    System.out.println("Yep, CounterTool instance created");
    this.shield = shield;
    factory = shield.getFactory();
  }
  
  public void setStartValue(int n){
  	count = n;
  }
  
  public void setDelay(int n){
  	delay = n;
  }
  
  public ATerm getCounter(int incr) {
    try {
      Thread.sleep(delay);
    } catch (InterruptedException e) {
      System.out.println("getCounter: " + e);
    }

    // Increase the counter and return the current value to the ToolBus
    int res = count;
    count += incr;
    return factory.make("count(<int>))", new Integer(res));
  }

  public void terminate(String msg) {
    System.out.println("CounterTool.terminate()");
  }
}
