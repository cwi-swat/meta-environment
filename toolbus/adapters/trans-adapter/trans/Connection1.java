/*
 * Created on Jun 27, 2003
 *
 * To change the template for this generated file go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
package trans;

import java.io.IOException;

import aterm.ATerm;
import aterm.ATermFactory;

/**
 * @author kooiker
 *
 * To change the template for this generated type comment go to
 * Window>Preferences>Java>Code Generation>Code and Comments
 */
public class Connection1 implements Tb1Tif {
	private ATermFactory factory;
	private Tb1Bridge bridge1;
	private Connection2 con2;

	public Connection1(String[] args, ATermFactory factory) throws IOException {
		this.factory = factory;
		bridge1 = new Tb1Bridge(factory, this);

//		args = new String[6];
//		args[0] = "-TB_HOST_NAME";
//		args[1] = "localhost";
//		args[2] = "-TB_PORT";
//		args[3] = "8999";
//		args[4] = "-TB_TOOL_NAME";
//		args[5] = "tb1";

		bridge1.init(args);
		bridge1.connect();

		Thread t1 = new Thread(bridge1, "Tb1");
		t1.start();
	}

	public void Connection2(Connection2 con2) {
		this.con2 = con2;
	}

	public void sendTerm(ATerm term) {
		try {
			bridge1.sendTerm(term);
		} catch (Exception e) {
		}
	}

	public void postEventCon2(ATerm term) {
		con2.postEvent(term);
	}

	public void recTerminate(ATerm t0) {
	}
}
