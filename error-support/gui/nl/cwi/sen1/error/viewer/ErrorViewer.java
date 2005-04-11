package nl.cwi.sen1.error.viewer;

import java.io.IOException;

import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.error.model.ErrorNode;
import aterm.ATerm;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Error;
import errorapi.types.Summary;

public class ErrorViewer extends ErrorPanel implements ErrorViewerTif, Runnable {
	private ErrorViewerBridge bridge;

	private Factory factory;

	public ErrorViewer(final PureFactory factory, String[] args) {
		super(new errorapi.Factory(factory));
		this.factory = new Factory((PureFactory) factory);
		try {
			bridge = new ErrorViewerBridge(factory, this);
			bridge.init(args);
			bridge.setLockObject(this);
			bridge.connect("error-viewer", null, -1);
		} catch (IOException e) {
			e.printStackTrace();
		}
		final JTree tree = getTree();
		tree.addTreeSelectionListener(new TreeSelectionListener() {
			public void valueChanged(TreeSelectionEvent e) {
				TreePath path = tree.getSelectionPath();
				ErrorNode node = null;

				if (path != null) {
					node = (ErrorNode) path.getLastPathComponent();
				}

				if (node != null) {
					Error error = node.getFirstError();
					if (!error.getList().isEmpty()) {
						bridge.postEvent(factory.make("error-selected(<term>)",
								error.toTerm()));
					}
				}
			}
		});
	}

	public void showFeedbackSummary(ATerm t0) {
		errorapi.Factory errorFactory = getFactory();
		Summary summary = errorFactory.SummaryFromTerm(t0);
		addError(summary);
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
