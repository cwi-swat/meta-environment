package nl.cwi.sen1.error.viewer;

import java.util.HashMap;

import javax.swing.JTree;
import javax.swing.event.TreeSelectionEvent;
import javax.swing.event.TreeSelectionListener;
import javax.swing.tree.TreePath;

import nl.cwi.sen1.error.model.SelectableNode;
import nl.cwi.sen1.gui.CloseAbortedException;
import nl.cwi.sen1.gui.Studio;
import nl.cwi.sen1.gui.StudioImplWithPredefinedLayout;
import nl.cwi.sen1.gui.StudioWithPredefinedLayout;
import nl.cwi.sen1.gui.component.StudioComponent;
import nl.cwi.sen1.gui.component.StudioComponentImpl;
import nl.cwi.sen1.gui.plugin.DefaultStudioPlugin;
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

	private HashMap<String, ErrorPanel> panels = new HashMap<String, ErrorPanel>();

	public String getName() {
		return TOOL_NAME;
	}

	public void initStudioPlugin(Studio studio) {
		this.studio = studio;

		ATermFactory factory = studio.getATermFactory();
		errorFactory = Factory.getInstance((PureFactory) factory);

		bridge = new ErrorViewerBridge(factory, this);
		bridge.setLockObject(this);

		studio.connect(getName(), bridge);
	}

	public ErrorViewer() {
	}

	private void addListener(ErrorPanel panel) {
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

	private ErrorPanel createPanel(String panelId) {
		ErrorPanel panel = new ErrorPanel();
		addListener(panel);

		StudioComponent comp = new StudioComponentImpl(panelId, panel) {
			public void requestClose() throws CloseAbortedException {
				throw new CloseAbortedException();
			}
		};

		((StudioWithPredefinedLayout) studio).addComponent(comp,
				StudioImplWithPredefinedLayout.BOTTOM_RIGHT);

		return panel;
	}

	private ErrorPanel getPanel(String panelId) {
		ErrorPanel panel = panels.get(panelId);

		if (panel != null) {
			return panel;
		}
		panel = createPanel(panelId);
		panels.put(panelId, panel);
		return panel;
	}

	public void showFeedbackSummary(String panelId, ATerm summaryTerm) {
		try {
			Summary summary = errorFactory.SummaryFromTerm(summaryTerm);
			getPanel(panelId).addError(summary);
		} catch (aterm.ParseError ex) {
			System.err.println("Summary is not a valid ATerm");
		} catch (IllegalArgumentException ex) {
			System.err.println("Summary is not valid");
		}
	}

	public void refreshFeedbackSummary(String panelId, ATerm summaryTerm) {
		try {
			Summary summary = errorFactory.SummaryFromTerm(summaryTerm);
			String producer = summary.getProducer();
			String id = summary.getId();

			getPanel(panelId).removeAllMatchingErrors(producer, id);
			getPanel(panelId).addError(summary);
		} catch (aterm.ParseError ex) {
			System.err.println("Summary is not a valid ATerm");
		} catch (IllegalArgumentException ex) {
			System.err.println("Summary is not valid");
		}
	}

	public void removeFeedbackSummary(String panelId, String producer, String id) {
		getPanel(panelId).removeAllMatchingErrors(producer, id);
	}

	public void removeFeedbackSummary(String panelId, String path) {
		getPanel(panelId).removeAllMatchingErrors(path);
	}

	public void recAckEvent(ATerm t0) {
	}

	public void recTerminate(ATerm t0) {
		fireStudioPluginClosed();
	}
}
