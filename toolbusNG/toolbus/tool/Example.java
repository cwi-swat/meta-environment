package toolbus.tool;
import aterm.*;

/**
 * @author paulk, Jul 30, 2002
 */
public class Example {
	ToolBridge bridge;

	/**
	 * Constructor for Example.
	 */
	public Example(ToolBridge bridge) {
		System.out.println("Yep, Example instance created");
		this.bridge = bridge;
		bridge.init(this);
		bridge.run();

	}
	
	public Example(int n){
	}
	
	public int funa(String s){
		
	return 0;
  }
  
   public ATerm aap(int n){
   	try {
			Thread.sleep(1);
		} catch (InterruptedException e) {
			System.out.println("aap: " + e);
		}
   	return bridge.getFactory().makeInt(2 * n);
   }

}
