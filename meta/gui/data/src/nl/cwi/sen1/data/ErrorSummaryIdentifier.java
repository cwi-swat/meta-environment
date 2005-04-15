package nl.cwi.sen1.data;

public class ErrorSummaryIdentifier {
    private String producer;
    private String summaryId;
    
    public ErrorSummaryIdentifier(String producer, String summaryId) {
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
        if (o instanceof ErrorSummaryIdentifier) {
            ErrorSummaryIdentifier peer = (ErrorSummaryIdentifier) o;
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
