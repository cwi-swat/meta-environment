package trans;

import java.io.IOException;
import java.util.List;

import aterm.ATerm;
import aterm.ATermFactory;

public class DelegateConnection implements DelegateTif {
	private ATermFactory factory;
	private DelegateBridge bridge;
	private MaskeradeConnection maskeradeConnection;

	public DelegateConnection(String[] args, ATermFactory factory)
		throws IOException {
		this.factory = factory;
		bridge = new DelegateBridge(factory, this);

		bridge.init(args);
		bridge.connect();

		Thread t2 = new Thread(bridge, "Delegate");
		t2.start();
	}

	public void setMaskerade(MaskeradeConnection maskeradeConnection) {
		this.maskeradeConnection = maskeradeConnection;
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

	public void postMaskeradeEvent(ATerm term) {
		maskeradeConnection.sendTerm(factory.make("snd-event(" + term + ")"));
	}

	public void postMaskeradeValue(ATerm term) {
		maskeradeConnection.sendTerm(factory.make("snd-value(" + term + ")"));
	}

	public void postMaskeradeTerminate(ATerm term) {
		System.exit(1);
//		maskeradeConnection.sendTerm(factory.make("snd-terminate(" + term + ")"));
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}
}
