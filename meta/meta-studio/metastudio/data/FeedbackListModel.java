package metastudio.data;

import java.util.Iterator;
import java.util.LinkedList;

import errorapi.types.Feedback;

public class FeedbackListModel extends ListModel {
    public FeedbackListModel() {
        super(new LinkedList());
    }
    
    /* we will group feedback messages that have the
     * same error but a different producer and/or a different summaryId.
     */
    public void add(String producer, String summary, Feedback feedback) {
       Iterator iter = iterator();
    
       while (iter.hasNext()) {
          FeedbackItem head = (FeedbackItem) iter.next();
          Feedback headFeedback = head.getFeedback();
            
          if (feedback.equals(headFeedback)) {
             head.addIdentification(producer, summary);
             return;
          }
       }
        
       super.add(new FeedbackItem(producer, summary, feedback));
    }
    
    public void removeAll(String producer, String summary) {
        Iterator iter = iterator();
        while (iter.hasNext()) {
            FeedbackItem item = (FeedbackItem) iter.next();
            if (item.removeIdentification(producer, summary)) {
                iter.remove();
            }
        }
    }
    
    public void add(Object o) {
        throw new UnsupportedOperationException("use typed add method");
    }
 }
