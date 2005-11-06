/**
 * @author paulk
 */

package toolbus;


public class Main {

	public static void main(String[] args) {
		TBTerm.init();
	
		ToolBus T = new ToolBus();
	
		try {
			T.setVerbose(true);
			T.parse(ToolBus.getWorkspace()
					+ "/toolbusNG/toolbus/tool/examples/wave.tb");
					//+ "/toolbusNG/toolbus/test/B1.tb");
			T.execute();
		} catch (ToolBusException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}

}