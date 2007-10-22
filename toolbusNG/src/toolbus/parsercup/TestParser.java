package toolbus.parsercup;

import java_cup.runtime.Symbol;
import toolbus.ToolBus;

public class TestParser {

	/**
	 * @param args
	 */
	public static void main(String[] args) {
		try {
			//String src = "/home/paulk/software/installed2/sdf-meta/share/sdf-meta/start-def-dump.tb";
			//String src = "/home/paulk/.eclipse/toolbusNG/toolbus/test/Notes.tb";
			String src = "/home/paulk/.eclipse/toolbusNG/toolbus/parsercup/tmp";
			
			parser parser_obj = new parser(src, new ToolBus(new String[0]));
		
			Symbol parse_tree = parser_obj.debug_parse();
			System.err.println("parse tree is:\n" + parse_tree.value);
		} catch (Exception e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}

	}

}
