package metastudio.components;

import java.awt.BorderLayout;
import java.awt.Rectangle;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.JTabbedPane;
import javax.swing.ListSelectionModel;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.data.FeedbackItem;
import metastudio.data.FeedbackListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Feedback;
import errorapi.types.Summary;

public class FeedbackList extends UserInterfacePanel {
    private static final String ANONYMOUS_ORIGIN = "anonymous";
    private JList list;
    private FeedbackListModel data;
    private Factory factory;

    public FeedbackList(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.factory = new Factory((PureFactory) factory);
        this.data = new metastudio.data.FeedbackListModel();

        this.list = new JList();
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                FeedbackItem item = (FeedbackItem) list.getSelectedValue();

                if (item != null) {
                    Feedback feedback = item.getFeedback();
                    if (!feedback.getList().isEmpty())
                    postEvent(
                        getFactory().make(
                            "feedback-selected(<term>)",
                            feedback.toTerm()));
                }
            }
        });

        list.setModel(data);
        list.setCellRenderer(new FeedbackListCellRenderer());
        list.setBackground(Preferences.getColor("messagepane.background"));

        add(new JScrollPane(list), BorderLayout.CENTER);
    }

    private Factory getErrorFactory() {
        return factory;
    }

    public void clearHistory() {
        removeFeedbackSummary(ANONYMOUS_ORIGIN, ANONYMOUS_ORIGIN);
    }

    public void showFeedbackSummary(ATerm t0) {
        Summary summary = new Factory((PureFactory) getFactory()).SummaryFromTerm(t0);
        setFeedbackList(summary);
    }

    private void setFeedbackList(Summary summary) {
        String producer = summary.getProducer();
        String summaryId = summary.getId();

        errorapi.types.FeedbackList messages = summary.getList();
        
        if (!messages.isEmpty()) {
          for (; !messages.isEmpty(); messages = messages.getTail()) {
              data.add(producer, summaryId, messages.getHead());
          }
        
          scrollToLast();
        }
    }

    private void scrollToLast() {
        Rectangle last = list.getCellBounds(data.getSize() - 1, data.getSize() - 1);
        if (last != null) {
            list.scrollRectToVisible(last);
        }
        setVisible(true);

        // TODO: find a better solution for this, we don't want this component
        // to know what type of parent it has!
        JTabbedPane parent = (JTabbedPane) getParent();
        parent.setSelectedComponent(this);
    }

    private Feedback makeError(String msg) {
        return getErrorFactory().makeFeedback_Error(
                msg,
                getErrorFactory().makeSubjectList());
    }

    private Feedback makeWarning(String msg) {
        return  getErrorFactory().makeFeedback_Warning(
                msg,
                getErrorFactory().makeSubjectList());
    }
    private Feedback makeInfo(String msg) {
        return  getErrorFactory().makeFeedback_Info(
                msg,
                getErrorFactory().makeSubjectList());
    }
    
    private void addAnonymousFeedbackItem(Feedback feedback) {
        data.add(ANONYMOUS_ORIGIN, ANONYMOUS_ORIGIN, feedback);
    }

    public void errorf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addAnonymousFeedbackItem(makeError(message));
    }

    public void error(String message) {
        addAnonymousFeedbackItem(makeError(message));
    }

    public void messagef(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addAnonymousFeedbackItem(makeInfo(message));
    }

    public void message(String message) {
        addAnonymousFeedbackItem(makeInfo(message));
    }

    public void warningf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addAnonymousFeedbackItem(makeWarning(message));
    }

    public void warning(String message) {
        addAnonymousFeedbackItem(makeWarning(message));
    }

    public void removeFeedbackSummary(String producer, String summaryId) {
        data.removeAll(producer, summaryId);

        repaint();
    }
}
