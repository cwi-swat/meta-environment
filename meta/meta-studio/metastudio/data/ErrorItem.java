package metastudio.data;

import java.util.HashSet;
import java.util.Iterator;
import java.util.Set;

import errorapi.types.Error;

public class ErrorItem {
    private Error error;
    private Set identification;
    
    public ErrorItem(String producer, String summaryId, Error error) {
        this.error = error;
        
        identification = new HashSet();
        addIdentification(producer, summaryId);
    }

    private ErrorSummaryIdentifier tuple(String producer, String summaryId) {
        return new ErrorSummaryIdentifier(producer, summaryId);
    }
    
    public Error getError() {
        return error;
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
        ErrorSummaryIdentifier peer = 
            new ErrorSummaryIdentifier(producer, summaryId);
        Iterator iter = identification.iterator();
        
        while (iter.hasNext()) {
            ErrorSummaryIdentifier id = (ErrorSummaryIdentifier) iter.next();
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
