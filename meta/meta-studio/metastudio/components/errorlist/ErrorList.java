package metastudio.components.errorlist;

import java.awt.BorderLayout;
import java.awt.Rectangle;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.io.IOException;

import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.ListSelectionModel;

import metastudio.data.ErrorItem;
import metastudio.data.ErrorListModel;
import metastudio.utils.Preferences;
import aterm.ATerm;
import aterm.ATermFactory;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Error;
import errorapi.types.Summary;

public class ErrorList extends JPanel implements ErrorListTif, Runnable {
	private static final String ANONYMOUS_ORIGIN = "anonymous";
	private JList list;
	private ErrorListModel data;
	private Factory factory;
	private ErrorListBridge bridge;

	public ErrorList(final ATermFactory factory, String[] args) {
		this.factory = new Factory((PureFactory) factory);
		this.data = new metastudio.data.ErrorListModel();
		this.list = new JList();
		
		setLayout(new BorderLayout());
		
		list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		list.addMouseListener(new MouseAdapter() {
			public void mouseClicked(MouseEvent e) {
				ErrorItem item = (ErrorItem) list.getSelectedValue();

				if (item != null) {
					Error error = item.getError();
					if (!error.getList().isEmpty()) {
						bridge.postEvent(
							factory.make(
								"error-selected(<term>)",
								error.toTerm()));
					}
				}
			}
		});

		list.setModel(data);
		list.setCellRenderer(new ErrorListCellRenderer());
		list.setBackground(Preferences.getColor("messagepane.background"));

		add(new JScrollPane(list), BorderLayout.CENTER);

		try {
			bridge = new ErrorListBridge(factory, this);
			bridge.init(args);
			bridge.setLockObject(this);
			bridge.connect("error-list", null, -1);
		} catch (IOException e) {
			e.printStackTrace();
		}
	}

	private Factory getErrorFactory() {
		return factory;
	}

	public void clearHistory() {
		removeFeedbackList(ANONYMOUS_ORIGIN, ANONYMOUS_ORIGIN);
	}

	private void setFeedbackList(Summary summary) {
		String producer = summary.getProducer();
		String summaryId = summary.getId();

		errorapi.types.ErrorList messages = summary.getList();

		if (!messages.isEmpty()) {
			for (; !messages.isEmpty(); messages = messages.getTail()) {
				data.add(producer, summaryId, messages.getHead());
			}

			scrollToLast();
		}
	}

	private void removeFeedbackList(String producer, String id) {
		data.removeAll(producer, id);
		repaint();
	}

	private void scrollToLast() {
		Rectangle last =
			list.getCellBounds(data.getSize() - 1, data.getSize() - 1);
		if (last != null) {
			list.scrollRectToVisible(last);
		}
		setVisible(true);

		// TODO: find a better solution for this, we don't want this component
		// to know what type of parent it has!
		JTabbedPane parent = (JTabbedPane) getParent();
		parent.setSelectedComponent(this);
	}

	private void addAnonymousErrorItem(Error error) {
		data.add(ANONYMOUS_ORIGIN, ANONYMOUS_ORIGIN, error);
	}

	public void showFeedbackSummary(ATerm t0) {
		Summary summary = factory.SummaryFromTerm(t0);
		setFeedbackList(summary);
	}

	public void removeFeedbackSummary(String producer, String summaryId) {
		removeFeedbackList(producer, summaryId);
	}

	public void recTerminate(ATerm t0) {

	}

	public void run() {
		bridge.run();
	}

	public void recAckEvent(ATerm t0) {
		
	}
}
