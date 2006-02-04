package toolbus.tool.java;
import toolbus.TBTermFactory;
import aterm.ATerm;

/**
 * @author paulk, Jul 30, 2002
 */
public class CounterTool {
  private JavaToolShield shield;
  private int count = 0;
  private int delay = 5;
  private TBTermFactory tbfactory;

  /**
   * Constructor for CounterTool.
   */
  public CounterTool(JavaToolShield shield) {
    System.out.println("Yep, CounterTool instance created");
    this.shield = shield;
    tbfactory = shield.getTBTermFactory();
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
    return tbfactory.make("count(<int>))", new Integer(res));
  }

  public void terminate(String msg) {
    System.err.println("CounterTool.terminate()");
  }
}
