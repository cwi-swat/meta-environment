package metastudio.data;

import errorapi.types.Feedback;

public class FeedbackItem {
    private Feedback feedback;
    private String producer;
    private String summaryId;
    
    public FeedbackItem(String producer, String summaryId, Feedback feedback) {
        this.producer = producer;
        this.summaryId = summaryId;
        this.feedback = feedback;
    }

    public Feedback getFeedback() {
        return feedback;
    }
    
    public String getProducer() {
        return producer;
    }
    
    public String getSummaryId() {
        return summaryId;
    }
    
    public String toString() {
        return "item[" + producer +"," + summaryId + "," + feedback.toString() +"]";
    }
}
