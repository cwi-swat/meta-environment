package metastudio.data;

import java.util.Iterator;
import java.util.LinkedList;

import errorapi.types.Error;

public class ErrorListModel extends ListModel {
    public ErrorListModel() {
        super(new LinkedList());
    }
    
    /* we will group feedback messages that have the
     * same error but a different producer and/or a different summaryId.
     */
    public void add(String producer, String summary, Error error) {
       Iterator iter = iterator();
    
       while (iter.hasNext()) {
          ErrorItem head = (ErrorItem) iter.next();
          Error headError = head.getError();
            
          if (error.equals(headError)) {
             head.addIdentification(producer, summary);
             return;
          }
       }
        
       super.add(new ErrorItem(producer, summary, error));
    }
    
    public void removeAll(String producer, String summary) {
        Iterator iter = iterator();
        while (iter.hasNext()) {
            ErrorItem item = (ErrorItem) iter.next();
            if (item.removeIdentification(producer, summary)) {
                iter.remove();
            }
        }
    }
    
    public void add(Object o) {
        throw new UnsupportedOperationException("use typed add method");
    }
 }
