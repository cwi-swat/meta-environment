package metastudio.components;

import java.awt.BorderLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.LinkedList;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

import metastudio.MultiBridge;
import metastudio.UserInterfacePanel;
import metastudio.data.FeedbackItem;
import metastudio.data.ListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Feedback;
import errorapi.types.Summary;

public class FeedbackList extends UserInterfacePanel {
    private JList list;
    private ListModel data;
    private Factory factory;

    public FeedbackList(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.factory = new Factory((PureFactory) factory);
        this.data = new metastudio.data.ListModel(new LinkedList());

        this.list = new JList();
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                FeedbackItem item = (FeedbackItem) list.getSelectedValue();
                Feedback feedback = item.getFeedback();

                if (feedback != null && !feedback.getList().isEmpty()) {
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
        data.setList(new LinkedList());
        repaint();
    }

    public void displayFeedbackSummary(ATerm t0) {
        Summary summary = new Factory((PureFactory) getFactory()).SummaryFromTerm(t0);
        setFeedbackList(summary);
    }

    private void setFeedbackList(Summary summary) {
        String producer = summary.getProducer();
        String summaryId = summary.getId();

        errorapi.types.FeedbackList messages = summary.getList();
        for (; !messages.isEmpty(); messages = messages.getTail()) {
            data.add(new FeedbackItem(producer, summaryId, messages.getHead()));
        }
        list.repaint();
    }

    private FeedbackItem makeAnonymousError(String msg) {
        return new FeedbackItem(
            "meta",
            "anonymous",
            getErrorFactory().makeFeedback_Error(
                msg,
                getErrorFactory().makeSubjectList()));
    }

    private Feedback makeAnonymousWarning(String msg) {
        return getErrorFactory().makeFeedback_Warning(
            msg,
            getErrorFactory().makeSubjectList());
    }
    private Feedback makeAnonymousInfo(String msg) {
        return getErrorFactory().makeFeedback_Info(
            msg,
            getErrorFactory().makeSubjectList());
    }

    public void errorf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        data.add(makeAnonymousError(message));
    }

    public void error(String message) {
        data.add(makeAnonymousError(message));
    }

    public void messagef(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        data.add(makeAnonymousInfo(message));
    }

    public void message(String message) {
        data.add(makeAnonymousInfo(message));
    }

    public void warningf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        data.add(makeAnonymousWarning(message));
    }

    public void warning(String message) {
        data.add(makeAnonymousWarning(message));
    }

    public void removeFeedbackSummary(String producer, String summaryId) {
        for (int i = 0; i < data.getSize(); i++) {
            FeedbackItem item = (FeedbackItem) data.getElementAt(i);

            if (item.getProducer().equals(producer)
                && item.getSummaryId().equals(summaryId)) {
                data.remove(item);
            }
        }
    }
}
