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
public class MaskeradeConnection implements MaskeradeTif {
	private ATermFactory factory;
	private MaskeradeBridge bridge;
	private DelegateConnection delegateConnection;

	public MaskeradeConnection(String[] args, ATermFactory factory) throws IOException {
		this.factory = factory;
		bridge = new MaskeradeBridge(factory, this);

		bridge.init(args);
		bridge.connect();

		Thread t1 = new Thread(bridge, "Maskerade");
		t1.start();
	}

	public void setDelegate(DelegateConnection delegateConnection) {
		this.delegateConnection = delegateConnection;
	}

	public void sendTerm(ATerm term) {
		try {
			bridge.sendTerm(term);
		} catch (Exception e) {
		}
	}

	public void postDelegateEvent(ATerm term) {
		delegateConnection.postEvent(term);
	}

	public void recTerminate(ATerm t0) {
	}
}
