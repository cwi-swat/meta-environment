package metastudio.components;

import java.awt.Component;

import javax.swing.JList;
import javax.swing.JTextField;
import javax.swing.ListCellRenderer;
import javax.swing.border.EmptyBorder;

import metastudio.utils.Preferences;
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
            setForeground(Preferences.getColor("feedback.info.foreground"));
            setBackground(Preferences.getColor("feedback.info.background"));
            setFont(Preferences.getFont("feedback.info.font"));
        } else if (feedback.isWarning()) {
            setForeground(Preferences.getColor("feedback.warning.foreground"));
            setBackground(Preferences.getColor("feedback.warning.background"));
            setFont(Preferences.getFont("feedback.warning.font"));
        } else if (feedback.isError()) {
            setForeground(Preferences.getColor("feedback.error.foreground"));
            setBackground(Preferences.getColor("feedback.error.background"));
            setFont(Preferences.getFont("feedback.error.font"));
        } else if (feedback.isFatalError()) {
            setForeground(Preferences.getColor("feedback.fatalerror.foreground"));
            setBackground(Preferences.getColor("feedback.fatalerror.background"));
            setFont(Preferences.getFont("feedback.fatalerror.font"));
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
