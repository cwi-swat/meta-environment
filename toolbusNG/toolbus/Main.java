/**
 * @author paulk
 */

package toolbus;

import toolbus.atom.Atom;



public class Main {

	public static void main(String[] args) {
		ToolBus T = new ToolBus();
		try {
			//T.parse("/home/paulk/software/source/asfsdf-meta-asf-sdf-meta_1-5-bundle-1.5.3/toolbus/adapters/java-adapter/toolbus/test.tb");
			T.parse(ToolBus.getWorkspace()
					// + "/toolbusNG/toolbus/tool/java/example.tb");
 					+ "/toolbusNG/toolbus/tool/classic/pt-dump.tb");
				    //+ "/toolbusNG/toolbus/test/Msg0.tb");
					//			+ "/toolbusNG/toolbus/parser/tmp.tb");
			T.execute();
		} catch (ToolBusException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		Atom.statistics();
		
		//System.err.println(T.getTBTermFactory().statistics());
	}

}