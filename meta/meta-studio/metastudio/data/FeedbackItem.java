package metastudio.data;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import errorapi.types.Feedback;

public class FeedbackItem {
    private Feedback feedback;
    private Set identification;
    
    public FeedbackItem(String producer, String summaryId, Feedback feedback) {
        this.feedback = feedback;
        
        identification = new HashSet();
        addIdentification(producer, summaryId);
    }

    private FeedbackSummaryIdentifier tuple(String producer, String summaryId) {
        return new FeedbackSummaryIdentifier(producer, summaryId);
    }
    
    public Feedback getFeedback() {
        return feedback;
    }

    public void addIdentification(String producer, String summaryId) {
        identification.add(tuple(producer, summaryId));
    }
    
    /**
     * removes a summaryIdentifier from this feedback item. If no
     * identifiers are left, true is returned.
     * 
     * @return true if no producers/summaries are left, false otherwise
     */
    public boolean removeIdentification(String producer, String summaryId) {
        FeedbackSummaryIdentifier peer = 
            new FeedbackSummaryIdentifier(producer, summaryId);
        Iterator iter = identification.iterator();
        
        while (iter.hasNext()) {
            FeedbackSummaryIdentifier id = (FeedbackSummaryIdentifier) iter.next();
            if (id.equals(peer)) {
                iter.remove();
            }
        }
        
        return identification.size() == 0;
    }

    /**
     * @return an iterator over FeedbackIdentifiers elements
     */
    public Iterator getIdentification() {
        return identification.iterator();
    }
}
