package trans;

import java.io.IOException;
import java.util.List;

import aterm.ATerm;
import aterm.ATermFactory;

public class DelegateConnection implements DelegateTif {
	private ATermFactory factory;
	private DelegateBridge bridge;
	private MasqueradeConnection masqueradeConnection;

	public DelegateConnection(String[] args, ATermFactory factory)
		throws IOException {
		this.factory = factory;
		bridge = new DelegateBridge(factory, this);

		bridge.init(args);
		bridge.connect();

		Thread t2 = new Thread(bridge, "Delegate");
		t2.start();
	}

	public void setMasquerade(MasqueradeConnection masqueradeConnection) {
		this.masqueradeConnection = masqueradeConnection;
	}

	public void postEvent(ATerm term) {
		ATerm fun;
		List result;

		fun = factory.parse("rec-eval(<term>)");
		result = term.match(fun);
		if (result != null) {
			bridge.postEvent((ATerm) result.get(0));
			return;
		}

		fun = factory.parse("rec-do(<term>)");
		result = term.match(fun);
		if (result != null) {
			bridge.postEvent((ATerm) result.get(0));
			return;
		}

		fun = factory.parse("rec-ack-event(<term>)");
		result = term.match(fun);
		if (result != null) {
			return;
		}

		fun = factory.parse("rec-terminate(<term>)");
		result = term.match(fun);
		if (result != null) {
			System.exit(1);
		}

		throw new RuntimeException("term not in input signature: " + term);
	}

	public void postMasqueradeEvent(ATerm term) {
		masqueradeConnection.sendTerm(factory.make("snd-event(" + term + ")"));
	}

	public void postMasqueradeValue(ATerm term) {
		masqueradeConnection.sendTerm(factory.make("snd-value(" + term + ")"));
	}

	public void postMasqueradeTerminate(ATerm term) {
		System.exit(1);
//		masqueradeConnection.sendTerm(factory.make("snd-terminate(" + term + ")"));
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}
}
