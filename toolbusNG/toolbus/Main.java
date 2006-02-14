/**
 * @author paulk
 */

package toolbus;

import toolbus.atom.Atom;

public class Main {

	public static void main(String[] args) {
		ToolBus T = new ToolBus(args);
		String ws = T.get("workspace.path");
		try {
			T.parse(
			  //"/home/paulk/software/source/asfsdf-meta-asf-sdf-meta_1-5-bundle-1.5.3/toolbus/adapters/java-adapter/toolbus/test.tb");
				//	"/home/paulk/tmp/software/installed//share/meta/start-meta-pt-dumper.tb");
			  //ws + "/toolbusNG/toolbus/tool/java/example1.tb");
 			  //ws + "/toolbusNG/toolbus/tool/classic/pt-dump.tb");
			  //ws + "/toolbusNG/toolbus/test/Notes.tb");
			  ws + "/toolbusNG/toolbus/testerror/MissingProcDef1.tb");
			T.execute();
		} catch (ToolBusException e) {
			System.out.println(e.getMessage());
			e.printStackTrace();
		}
		Atom.statistics();
		
		//System.err.println(T.getTBTermFactory().statistics());
	}

}