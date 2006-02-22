/**
 * @author paulk
 */

package toolbus;

import toolbus.atom.Atom;

public class Main {

	public static void main(String[] args) {
		try {
			ToolBus T = new ToolBus(args);
			String ws = T.get("workspace.path");
			if(T.parse(
				  //"/home/paulk/software/source/asfsdf-meta-asf-sdf-meta_1-5-bundle-1.5.3/toolbus/adapters/java-adapter/toolbus/test.tb");
					//	"/home/paulk/tmp/software/installed//share/meta/start-meta-pt-dumper.tb")){
					//"/home/paulk/tmp/software/installed//share/meta/start-meta-eqs-dumper.tb");
					//"/home/paulk/tmp/software/installed//share/meta/meta.tb");
				  //ws + "/toolbusNG/toolbus/tool/java/example1.tb");
	 			  ws + "/toolbusNG/toolbus/tool/classic/pt-dump.tb")){
				  //ws + "/toolbusNG/toolbus/test/Let1.tb")){
				  //ws + "/toolbusNG/toolbus/testerror/ToolDef5.tb")){
			T.execute();
			Atom.statistics();
				  }
		} catch(Exception e){
			e.printStackTrace();
		}
		
		//System.err.println(T.getTBTermFactory().statistics());
	}

}