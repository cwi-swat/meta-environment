package metastudio.components;

import java.awt.BorderLayout;
import java.awt.event.MouseAdapter;
import java.awt.event.MouseEvent;
import java.util.LinkedList;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

import metastudio.MultiBridge;
import metastudio.data.ListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Feedback;
import errorapi.types.Summary;

// TODO: add copy/paste facility
public class FeedbackList extends ToolComponent {
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
                Feedback feedback = (Feedback) list.getSelectedValue();

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
        errorapi.types.FeedbackList messages = summary.getList();
        for (; !messages.isEmpty(); messages = messages.getTail()) {
            data.add(messages.getHead());
        }
        list.repaint();
    }

    private void addFeedback(Feedback feedback) {
        data.add(feedback);
        list.repaint();
    }

    private Feedback makeAnonymousError(String msg) {
        return getErrorFactory().makeFeedback_Error(
            "unknown",
            msg,
            getErrorFactory().makeSubjectList());
    }

    private Feedback makeAnonymousWarning(String msg) {
        return getErrorFactory().makeFeedback_Warning(
            "unknown",
            msg,
            getErrorFactory().makeSubjectList());
    }
    private Feedback makeAnonymousInfo(String msg) {
        return getErrorFactory().makeFeedback_Info(
            "unknown",
            msg,
            getErrorFactory().makeSubjectList());
    }

    public void errorf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addFeedback(makeAnonymousError(message));
    }

    public void error(String message) {
        addFeedback(makeAnonymousError(message));
    }

    public void messagef(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addFeedback(makeAnonymousInfo(message));
    }

    public void message(String message) {
        addFeedback(makeAnonymousInfo(message));
    }

    public void warningf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addFeedback(makeAnonymousWarning(message));
    }

    public void warning(String message) {
        addFeedback(makeAnonymousWarning(message));
    }
    
  
}
