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
import metastudio.data.ErrorItem;
import metastudio.data.ErrorListModel;
import metastudio.utils.Preferences;
import metastudio.utils.StringFormatter;
import aterm.ATerm;
import aterm.ATermList;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Error;
import errorapi.types.Summary;

public class ErrorList extends UserInterfacePanel {
    private static final String ANONYMOUS_ORIGIN = "anonymous";
    private JList list;
    private ErrorListModel data;
    private Factory factory;

    public ErrorList(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.factory = new Factory((PureFactory) factory);
        this.data = new metastudio.data.ErrorListModel();

        this.list = new JList();
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.addMouseListener(new MouseAdapter() {
            public void mouseClicked(MouseEvent e) {
                ErrorItem item = (ErrorItem) list.getSelectedValue();

                if (item != null) {
                    Error error = item.getError();
                    if (!error.getList().isEmpty()) {
		      postEvent(getFactory().make("error-selected(<term>)",
						  error.toTerm()));
		    }
                }
            }
        });

        list.setModel(data);
        list.setCellRenderer(new ErrorListCellRenderer());
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
        Summary summary = factory.SummaryFromTerm(t0);
        setFeedbackList(summary);
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

    private Error makeError(String msg) {
        return getErrorFactory().makeError_Error(
                msg,
                getErrorFactory().makeSubjectList());
    }

    private Error makeWarning(String msg) {
        return  getErrorFactory().makeError_Warning(
                msg,
                getErrorFactory().makeSubjectList());
    }
    private Error makeInfo(String msg) {
        return  getErrorFactory().makeError_Info(
                msg,
                getErrorFactory().makeSubjectList());
    }
    
    private void addAnonymousErrorItem(Error error) {
        data.add(ANONYMOUS_ORIGIN, ANONYMOUS_ORIGIN, error);
    }

    public void errorf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addAnonymousErrorItem(makeError(message));
    }

    public void error(String message) {
        addAnonymousErrorItem(makeError(message));
    }

    public void messagef(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addAnonymousErrorItem(makeInfo(message));
    }

    public void message(String message) {
        addAnonymousErrorItem(makeInfo(message));
    }

    public void warningf(String format, ATerm args) {
        String message = StringFormatter.format(format, (ATermList) args);
        addAnonymousErrorItem(makeWarning(message));
    }

    public void warning(String message) {
        addAnonymousErrorItem(makeWarning(message));
    }

    public void removeFeedbackSummary(String producer, String summaryId) {
        data.removeAll(producer, summaryId);

        repaint();
    }
}
