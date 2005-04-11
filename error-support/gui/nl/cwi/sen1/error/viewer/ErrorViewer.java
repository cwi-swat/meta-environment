package nl.cwi.sen1.error.viewer;

import java.io.IOException;

import aterm.ATerm;
import aterm.ATermFactory;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Summary;

public class ErrorViewer implements ErrorViewerTif, Runnable {
	private ErrorViewerBridge bridge;
	private ErrorPanel errorpanel;
	private Factory factory;
	
	public ErrorViewer(final ATermFactory factory, String[] args) {
		this.factory = new Factory((PureFactory) factory);
		try {
			bridge = new ErrorViewerBridge(factory, this);
			bridge.init(args);
			bridge.setLockObject(this);
			bridge.connect("error-viewer", null, -1);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}
	
	public void showFeedbackSummary(ATerm t0) {
		Summary summary = errorpanel.getFactory().SummaryFromTerm(t0);
		errorpanel.addError(summary);
	}

	public void removeFeedbackSummary(String s0, String s1) {
		// TODO Auto-generated method stub
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}

	public void run() {
		bridge.run();
	}

}
