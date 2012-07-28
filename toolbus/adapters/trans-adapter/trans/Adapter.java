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

	private List masqueradeArgsList, delegateArgsList;

	public static void main(String[] args) throws Exception {
		Adapter a = new Adapter(args);
	}

	public Adapter(String[] args) throws Exception {
		parseArguments(args);

		factory = new aterm.pure.PureFactory();

		String[] masqueradeArgs = (String[])masqueradeArgsList.toArray(new String[masqueradeArgsList.size()]);
		String[] delegateArgs = (String[])delegateArgsList.toArray(new String[delegateArgsList.size()]);

		MasqueradeConnection masqueradeConnection = new MasqueradeConnection(masqueradeArgs, factory);
		DelegateConnection delegateConnection = new DelegateConnection(delegateArgs, factory);

		masqueradeConnection.setDelegate(delegateConnection);
		delegateConnection.setMasquerade(masqueradeConnection);
	}

	private void parseArguments(String[] args) {
		masqueradeArgsList = new ArrayList();
		delegateArgsList = new ArrayList();

		for (int i = 0; i < args.length; i++) {
			if (args[i].equals("-TB_MASQUERADE_PORT")) {
				masqueradeArgsList.add(new String("-TB_PORT"));
				masqueradeArgsList.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_MASQUERADE_HOST")) {
				masqueradeArgsList.add(new String("-TB_HOST"));
				masqueradeArgsList.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_MASQUERADE_TOOL")) {
				masqueradeArgsList.add(new String("-TB_TOOL_NAME"));
				masqueradeArgsList.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_DELEGATE_PORT")) {
				delegateArgsList.add(new String("-TB_PORT"));
				delegateArgsList.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_DELEGATE_HOST")) {
				delegateArgsList.add(new String("-TB_HOST_NAME"));
				delegateArgsList.add(new String(args[++i]));
			}
			if (args[i].equals("-TB_DELEGATE_TOOL")) {
				delegateArgsList.add(new String("-TB_TOOL_NAME"));
				delegateArgsList.add(new String(args[++i]));
			}
		}
	}
}
