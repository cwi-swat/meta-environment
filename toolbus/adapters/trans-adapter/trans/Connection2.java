/*
 * Created on Jun 27, 2003
 *
 * To change the template for this generated file go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
package trans;

import java.io.IOException;
import java.util.List;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author kooiker
 *
 * To change the template for this generated type comment go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
public class Connection2 implements Tb2Tif {
	private ATermFactory factory;
	private Tb2Bridge bridge2;
	private Connection1 con1;

	public Connection2(ATermFactory factory) throws IOException {
		this.factory = factory;
		bridge2 = new Tb2Bridge(factory, this);

		String[] args = new String[6];
		args[0] = "-TB_HOST_NAME";
		args[1] = "localhost";
		args[2] = "-TB_PORT";
		args[3] = "9000";
		args[4] = "-TB_TOOL_NAME";
		args[5] = "tb2";

		bridge2.init(args);
		bridge2.connect();
		
		Thread t2 = new Thread(bridge2, "Tb2");
		t2.start();
	}
	
	public void Connection1(Connection1 con1) {
		this.con1 = con1;
	}
	
	public void postEvent(ATerm term) {
		ATerm fun;
		List result;
		
		fun = factory.parse("rec-eval(<term>)");
		result = term.match(fun);
		
		if (result == null) {
			fun = factory.parse("rec-do(<term>)");
			result = term.match(fun);
		}
		
		if (result != null) {
			bridge2.postEvent((ATerm)result.get(0));
		} else {
			throw new RuntimeException("term not in input signature: " + term);
		}
	}
	
	public void postEventCon1(ATerm term) {
		System.out.println(term);
		ATerm fun;
		List result;
		
		fun = factory.parse("rec-do(<term>)");
		result = term.match(fun);
		
		if (result != null) {
			con1.sendTerm(factory.make("snd-value(" + (ATerm)result.get(0) + ")"));
		}
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}
}
