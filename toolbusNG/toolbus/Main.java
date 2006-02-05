/**
 * @author paulk
 */

package toolbus;


public class Main {

	public static void main(String[] args) {
		ToolBus T = new ToolBus();
	
		try {
			T.parse(ToolBus.getWorkspace()
					 + "/toolbusNG/toolbus/tool/java/example.tb");
			
				    //+ "/toolbusNG/toolbus/test/Assign6.tb");
					//			+ "/toolbusNG/toolbus/parser/tmp.tb");
			T.execute();
		} catch (ToolBusException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		
		//System.err.println(T.getTBTermFactory().statistics());
	}

}