/*
 * Created on Jun 26, 2003
 *
 * To change the template for this generated file go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
package trans;

import java.util.ArrayList;
import java.util.List;

import aterm.ATermFactory;

/**
 * @author kooiker
 *
 * To change the template for this generated type comment go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
public class Adapter {
	private ATermFactory factory;

	private List list1, list2;

	public static void main(String[] args) throws Exception {
		Adapter a = new Adapter(args);
	}

	public Adapter(String[] args) throws Exception {
		parseArguments(args);

		factory = new aterm.pure.PureFactory();
		String[] args1 = (String[])list1.toArray(new String[list1.size()]);
		String[] args2 = (String[])list2.toArray(new String[list2.size()]);
		Connection1 con1 = new Connection1(args1, factory);
		Connection2 con2 = new Connection2(args2, factory);
		con1.Connection2(con2);
		con2.Connection1(con1);
	}

	private void parseArguments(String[] args) {
		list1 = new ArrayList();
		list2 = new ArrayList();

		args = new String[6];
		args[0] = "-TB_HOST_NAME1";
		args[1] = "80.0.0.2";
		args[2] = "-TB_PORT1";
		args[3] = "3302";
		args[4] = "-TB_TOOL_NAME1";
		args[5] = "testtool";

		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-TB_PORT1")) {
				list1.add(new String("-TB_PORT"));
				list1.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_HOST_NAME1")) {
				list1.add(new String("-TB_HOST"));
				list1.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_TOOL_NAME1")) {
				list1.add(new String("-TB_TOOL_NAME"));
				list1.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_PORT2")) {
				list2.add(new String("-TB_PORT"));
				list2.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_HOST2")) {
				list2.add(new String("-TB_HOST_NAME"));
				list2.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_TOOL_NAME2")) {
				list2.add(new String("-TB_TOOL_NAME"));
				list2.add(new String(args[++i]));
			}
		}
	}
}
