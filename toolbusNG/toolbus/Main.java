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
					+ "/toolbusNG/toolbus/tool/examples/pt-dump.tb");
				    //+ "/toolbusNG/toolbus/test/Bind.tb");
					//			+ "/toolbusNG/toolbus/parser/tmp.tb");
			T.execute();
		} catch (ToolBusException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
	}

}