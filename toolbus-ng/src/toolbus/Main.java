/**
 * @author paulk
 */

package toolbus;

public class Main{
	
	public static void main(String[] args) throws Exception{
		ToolBus toolbus = new ToolBus(args);
		
		toolbus.parsecup();
		toolbus.prepare();
		toolbus.execute();
	}
}
