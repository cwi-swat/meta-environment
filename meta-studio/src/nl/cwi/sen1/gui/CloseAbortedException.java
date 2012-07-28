package nl.cwi.sen1.gui;

public class CloseAbortedException extends Exception {
    public CloseAbortedException() {
    }

    public CloseAbortedException(String message) {
        super(message);
    }

    public CloseAbortedException(Throwable cause) {
        super(cause);
    }

    public CloseAbortedException(String message, Throwable cause) {
        super(message, cause);
    }
}
