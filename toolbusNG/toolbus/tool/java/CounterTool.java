package toolbus.tool.java;
import java.io.IOException;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author paulk, Jul 30, 2002
 */
public class CounterTool {
  private JavaToolBridge bridge;
  private int count = 0;
  private int delay = 5;
  private ATermFactory factory;

  /**
   * Constructor for CounterTool.
   */
  public CounterTool(JavaToolBridge bridge, String[] args)  throws IOException {
    System.out.println("Yep, CounterTool instance created");
    this.bridge = bridge;
    factory = bridge.getFactory();
    bridge.connect();
    bridge.start();
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
    return factory.make("snd-value(count(<int>)))", new Integer(res));
  }

  public void recTerminate(ATerm msg) {
    System.err.println("CounterTool.terminate()");
  }
}
