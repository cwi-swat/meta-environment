package metastudio.components;

import java.awt.Component;
import java.util.Iterator;

import javax.swing.DefaultListCellRenderer;
import javax.swing.JLabel;
import javax.swing.JList;

import metastudio.data.FeedbackItem;
import metastudio.data.FeedbackSummaryIdentifier;
import metastudio.utils.Preferences;
import errorapi.types.Feedback;
import errorapi.types.SubjectList;

public class FeedbackListCellRenderer extends DefaultListCellRenderer {

    public Component getListCellRendererComponent(
        JList list,
        Object value,
        int index,
        boolean isSelected,
        boolean cellHasFocus) {
        JLabel cell = (JLabel) super.getListCellRendererComponent(list,value, index, isSelected, cellHasFocus);
        FeedbackItem item = (FeedbackItem) value;
        Feedback feedback = item.getFeedback();

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

        cell.setText(getErrorMessage(feedback));
        cell.setToolTipText(getTooltip(item));
        
        if (isSelected) {
            cell.setBackground(list.getSelectionBackground());
            cell.setForeground(list.getSelectionForeground());
        }
       
        return cell;
    }
    
    private String getErrorMessage(Feedback feedback) {
        StringBuffer buf = new StringBuffer();
        buf.append(feedback.getDescription());
        SubjectList subjects = feedback.getList();
        
        if (!subjects.isEmpty()) {
          buf.append(": ");
          
          for ( ; !subjects.isEmpty(); subjects = subjects.getTail()) {
              buf.append(subjects.getHead().getDescription());
          }
        }
        
        return buf.toString();
    }

    private String getTooltip(FeedbackItem item) {
        Iterator ids = item.getIdentification();
        StringBuffer buf = new StringBuffer();
        
        while (ids.hasNext()) {
            FeedbackSummaryIdentifier id = (FeedbackSummaryIdentifier) ids.next();
            
            buf.append(id.getProducer());
            buf.append(" - ");
            buf.append(id.getSummaryId());
            if (ids.hasNext()) {
                buf.append(", ");
            }
        }
        
        return buf.toString();
    }

    
}
