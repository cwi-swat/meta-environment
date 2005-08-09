package nl.cwi.sen1.error.viewer;

import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.error.model.SelectableNode;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.DefaultStudioPlugin;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioComponent;
import nl.cwi.sen1.gui.StudioComponentImpl;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Summary;

public class ErrorViewer extends DefaultStudioPlugin implements ErrorViewerTif {
	private static final String TOOL_NAME = "error-viewer";

	private Studio studio;

	ErrorViewerBridge bridge;

	errorapi.Factory errorFactory;

	private ErrorPanel panel;

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;

		ATermFactory factory = studio.getATermFactory();
		errorFactory = Factory.getInstance((PureFactory) factory);

		panel = new ErrorPanel();
		addListener();

		bridge = new ErrorViewerBridge(factory, this);
		bridge.setLockObject(this);

		StudioComponent comp = new StudioComponentImpl("Error Viewer", panel) {
			public void requestClose() throws CloseAbortedException {
				throw new CloseAbortedException();
			}
		};
		studio.connect(getName(), bridge);
		((StudioWithPredefinedLayout) studio).addComponent(comp,
				StudioImplWithPredefinedLayout.BOTTOM_RIGHT);
	}

	public ErrorViewer() {
	}

	private void addListener() {
		final JTree tree = panel.getTree();
		
		
		tree.addTreeSelectionListener(new TreeSelectionListener() {
			public void valueChanged(TreeSelectionEvent e) {
				TreePath path = tree.getSelectionPath();
				if (path != null) {
					Object node = path.getLastPathComponent();
					if (node != null && node instanceof SelectableNode) {
						((SelectableNode) node).selected(studio, bridge);
						tree.clearSelection();
					}
				}
			}
		});
	}

	public void showFeedbackSummary(ATerm summaryTerm) {
		Summary summary = errorFactory.SummaryFromTerm(summaryTerm);
		panel.addError(summary);
	}

	public void removeFeedbackSummary(String producer, String id) {
		panel.removeAllMatchingErrors(producer, id);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}
}
