package nl.cwi.sen1.error.viewer;

import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioPlugin;
import aterm.ATerm;

public class ErrorViewer implements ErrorViewerTif, StudioPlugin {
	private static final String TOOL_NAME = "Error Viewer";

	private Studio studio;

	ErrorViewerBridge bridge;

	private ErrorPanel panel;

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;
		bridge = new ErrorViewerBridge(studio.getATermFactory(), this);
		bridge.setLockObject(this);
		studio.connect(getName(), bridge);
	}

	public ErrorViewer() {
//		final JTree tree = panel.getTree();
//		tree.addTreeSelectionListener(new TreeSelectionListener() {
//			public void valueChanged(TreeSelectionEvent e) {
//				TreePath path = tree.getSelectionPath();
//
//				if (path != null) {
//					ErrorNode node = (ErrorNode) path.getLastPathComponent();
//					if (node != null) {
//						Error error = node.getFirstError();
//						if (!error.getList().isEmpty()) {
//							bridge.postEvent(studio.getATermFactory().make(
//									"error-selected(<term>)", error.toTerm()));
//						}
//					}
//				}
//			}
//
//		});
	}

	public void showFeedbackSummary(ATerm t0) {
	}

	public void removeFeedbackSummary(String s0, String s1) {
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
	}
}
