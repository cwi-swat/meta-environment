package metastudio.components;

import java.awt.Component;
import java.util.Iterator;

import javax.swing.DefaultListCellRenderer;
import javax.swing.JLabel;
import javax.swing.JList;

import metastudio.data.ErrorItem;
import metastudio.data.ErrorSummaryIdentifier;
import metastudio.utils.Preferences;
import errorapi.types.Error;
import errorapi.types.SubjectList;

public class ErrorListCellRenderer extends DefaultListCellRenderer {

    public Component getListCellRendererComponent(
        JList list,
        Object value,
        int index,
        boolean isSelected,
        boolean cellHasFocus) {
        JLabel cell = (JLabel) super.getListCellRendererComponent(list,value, index, isSelected, cellHasFocus);
        ErrorItem item = (ErrorItem) value;
        Error error = item.getError();

        if (error.isInfo()) {
            cell.setForeground(Preferences.getColor("error.info.foreground"));
            cell.setBackground(Preferences.getColor("error.info.background"));
            cell.setFont(Preferences.getFont("error.info.font"));
        } else if (error.isWarning()) {
            cell.setForeground(Preferences.getColor("error.warning.foreground"));
            cell.setBackground(Preferences.getColor("error.warning.background"));
            cell.setFont(Preferences.getFont("error.warning.font"));
        } else if (error.isError()) {
            cell.setForeground(Preferences.getColor("error.error.foreground"));
            cell.setBackground(Preferences.getColor("error.error.background"));
            cell.setFont(Preferences.getFont("error.error.font"));
        } else if (error.isFatal()) {
            cell.setForeground(Preferences.getColor("error.fatalerror.foreground"));
            cell.setBackground(Preferences.getColor("error.fatalerror.background"));
            cell.setFont(Preferences.getFont("error.fatalerror.font"));
        }

        cell.setText(getErrorMessage(error));
        cell.setToolTipText(getTooltip(item));
        
        if (isSelected) {
            cell.setBackground(list.getSelectionBackground());
            cell.setForeground(list.getSelectionForeground());
        }
       
        return cell;
    }
    
    private String getErrorMessage(Error error) {
        StringBuffer buf = new StringBuffer();
        buf.append(error.getDescription());
        SubjectList subjects = error.getList();
        
        if (!subjects.isEmpty()) {
          buf.append(": ");
          
          for ( ; !subjects.isEmpty(); subjects = subjects.getTail()) {
              buf.append(subjects.getHead().getDescription());
          }
        }
        
        return buf.toString();
    }

    private String getTooltip(ErrorItem item) {
        Iterator ids = item.getIdentification();
        StringBuffer buf = new StringBuffer();
        
        while (ids.hasNext()) {
            ErrorSummaryIdentifier id = (ErrorSummaryIdentifier) ids.next();
            
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
