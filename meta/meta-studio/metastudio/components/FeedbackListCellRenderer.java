package metastudio.components;

import java.awt.Color;
import java.awt.Component;

import javax.swing.JList;
import javax.swing.JTextField;
import javax.swing.ListCellRenderer;
import javax.swing.border.EmptyBorder;

import errorapi.types.Feedback;
import errorapi.types.Location;
import errorapi.types.SubjectList;

public class FeedbackListCellRenderer extends JTextField implements ListCellRenderer {

    public FeedbackListCellRenderer() {
        setOpaque(true);
    }

    public Component getListCellRendererComponent(
        JList list,
        Object value,
        int index,
        boolean isSelected,
        boolean cellHasFocus) {

        Feedback feedback = (Feedback) value;

        if (feedback.isInfo()) {
            setForeground(Color.black);
        } else if (feedback.isWarning()) {
            setForeground(Color.blue);
        } else if (feedback.isError()) {
            setForeground(Color.red);
        } else if (feedback.isFatalError()) {
            setForeground(Color.black);
            setBackground(Color.red);
        }

        setText(feedback.getDescription());
        setBorder(new EmptyBorder(0, 0, 0, 0));
        setEditable(false);
        setToolTipText(getTooltip(feedback));
        
        return this;
    }

    private String getTooltip(Feedback feedback) {
        SubjectList subjects = feedback.getList();
        String tip = "no source location available";

        while (subjects.hasHead()) {
            Location loc = subjects.getHead().getLocation();

            if (!loc.isNoLocation()) {
                tip = "click to go to source location (" + loc.getFilename() + ")";
            }

            subjects = subjects.getTail();
        }

        return tip;
    }

    
}
