package metastudio.data;

public class FeedbackSummaryIdentifier {
    private String producer;
    private String summaryId;
    
    public FeedbackSummaryIdentifier(String producer, String summaryId) {
        this.producer = producer;
        this.summaryId = summaryId;
    }
    
    public String getProducer() {
        return producer;
    }
    
    public String getSummaryId() {
        return summaryId;
    }
    
    public boolean equals(Object o) {
        if (o instanceof FeedbackSummaryIdentifier) {
            FeedbackSummaryIdentifier peer = (FeedbackSummaryIdentifier) o;
            if (peer.getProducer().equals(producer) &&
                    peer.getSummaryId().equals(summaryId)) {
                return true;
            }
        }
        
        return false;
    }
    
    public String toString() {
        return "[" + producer + ", " + summaryId + "]";
    }
}
