package metastudio.components;

import java.awt.BorderLayout;
import java.awt.event.MouseEvent;
import java.awt.event.MouseListener;
import java.util.LinkedList;
import java.util.List;

import javax.swing.JList;
import javax.swing.JScrollPane;
import javax.swing.ListSelectionModel;

import metastudio.MultiBridge;
import metastudio.data.ListModel;
import aterm.ATerm;
import aterm.pure.PureFactory;
import errorapi.Factory;
import errorapi.types.Feedback;
import errorapi.types.Summary;

public class FeedbackList extends ToolComponent implements MouseListener {
    private JList list;
    private List data;

    public FeedbackList(aterm.ATermFactory factory, MultiBridge bridge) {
        super(factory, bridge);

        this.data = new LinkedList();

        this.list = new JList();
        list.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
        list.addMouseListener(this);

        list.setModel(new ListModel(data));
        list.setCellRenderer(new FeedbackListCellRenderer());

        setLayout(new BorderLayout());
        add(new JScrollPane(list), BorderLayout.CENTER);

        // just testing
        setFeedbackList(
            new Factory((PureFactory) factory).SummaryFromString(
                "feedback("
                    + "[info("
                    + "\"1\","
                    + "\"1\","
                    + "\"asf-checker\","
                    + "\"an example info message\","
                    + "[subject(\"subject-id\",location(\"filename\",area(0,0,0,0,0,0)))]),"
                    + "warning("
                    + "\"2\","
                    + "\"1\","
                    + "\"sdf-checker\","
                    + "\"an example warning\","
                    + "[subject(\"subject-id\",location(\"filename\",area(0,0,0,0,0,0)))]),"
                    + "error("
                    + "\"3\","
                    + "\"1\","
                    + "\"toolbus\","
                    + "\"an example error\","
                    + "[subject(\"subject-id\",location(\"filename\",area(0,0,0,0,0,0)))]),"
                    + "fatal-error("
                    + "\"8\","
                    + "\"-1\","
                    + "\"system\","
                    + "\"an example fatal error\","
                    + "[subject(\"subject-id\",location(\"filename\",area(0,0,0,0,0,0)))])])"));
    }

    public void displayFeedbackSummary(ATerm t0) {
        Summary summary = new Factory((PureFactory) getFactory()).SummaryFromTerm(t0);
        setFeedbackList(summary);
    }

    private void setFeedbackList(Summary summary) {
        data.clear();

        errorapi.types.FeedbackList messages = summary.getList();
        for (; !messages.isEmpty(); messages = messages.getTail()) {
            data.add(messages.getHead());
        }

        list.repaint();
    }

    public void mouseClicked(MouseEvent e) {
        Feedback feedback = (Feedback) list.getSelectedValue();
        postEvent(getFactory().make("feedback-selected(<term>)", feedback.toTerm()));
    }

    public void mousePressed(MouseEvent e) {
        // do nothing
    }

    public void mouseReleased(MouseEvent e) {
        // do nothing
    }

    public void mouseEntered(MouseEvent e) {
        // do nothing
    }

    public void mouseExited(MouseEvent e) {
        // do nothing
    }
}
