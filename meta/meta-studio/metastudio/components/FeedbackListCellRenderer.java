package metastudio.components;

import java.awt.Component;

import javax.swing.DefaultListCellRenderer;
import javax.swing.JLabel;
import javax.swing.JList;

import metastudio.utils.Preferences;
import errorapi.types.Feedback;
import errorapi.types.Location;
import errorapi.types.SubjectList;

public class FeedbackListCellRenderer extends DefaultListCellRenderer {

    public Component getListCellRendererComponent(
        JList list,
        Object value,
        int index,
        boolean isSelected,
        boolean cellHasFocus) {
        JLabel cell = (JLabel) super.getListCellRendererComponent(list,value, index, isSelected, cellHasFocus);
        Feedback feedback = (Feedback) value;

        if (feedback.isInfo()) {
            cell.setForeground(Preferences.getColor("feedback.info.foreground"));
            cell.setBackground(Preferences.getColor("feedback.info.background"));
            cell.setFont(Preferences.getFont("feedback.info.font"));
        } else if (feedback.isWarning()) {
            cell.setForeground(Preferences.getColor("feedback.warning.foreground"));
            cell.setBackground(Preferences.getColor("feedback.warning.background"));
            cell.setFont(Preferences.getFont("feedback.warning.font"));
        } else if (feedback.isError()) {
            cell.setForeground(Preferences.getColor("feedback.error.foreground"));
            cell.setBackground(Preferences.getColor("feedback.error.background"));
            cell.setFont(Preferences.getFont("feedback.error.font"));
        } else if (feedback.isFatalError()) {
            cell.setForeground(Preferences.getColor("feedback.fatalerror.foreground"));
            cell.setBackground(Preferences.getColor("feedback.fatalerror.background"));
            cell.setFont(Preferences.getFont("feedback.fatalerror.font"));
        }

        cell.setText(feedback.getDescription());
        cell.setToolTipText(getTooltip(feedback));
        
        if (isSelected) {
            cell.setBackground(list.getSelectionBackground());
            cell.setForeground(list.getSelectionForeground());
        }
       
        return cell;
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
