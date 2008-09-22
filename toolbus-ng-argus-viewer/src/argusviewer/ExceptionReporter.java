package argusviewer;

import org.apache.log4j.Logger;

/**
 * This class handles all the exceptions of the ArgusViewer.
 * 
 * @author J. Wulffers
 * @author J. van den Bos
 * @author M. van Beest
 */
public final class ExceptionReporter {
	private final static Logger log = Logger.getLogger(ExceptionReporter.class);
	
	/**
	 * The state of the exception
	 */
	public static enum ExceptionState {
		IGNORED,
		CONSUMED,
		TRIED,
		UNRECOVERABLE
	}
	
	/**
	 * Reports the provided exception on the standard error stream.
	 * 
	 * @param exception the exception that was handled and must be reported.
	 * @param exceptionState how the exception was handled.
	 * @see argusviewer.ExceptionReporter#ExceptionState
	 */
	public static void process(Exception exception, ExceptionState exceptionState){		
		log.error("Exception caught: " + exception.toString());
		if (exception.getCause() != null) {
			log.error("Exception cause type: " + exception.getCause().toString());
		}
		log.error("Exception handled state: " + exceptionState.toString());
		log.error("Exception message: " + exception.getMessage());
	}
	
	/**
	 * Outputs a custom error message on the standard error stream.
	 * @param errorMessage The message to be displayed
	 */
	public static void report(String errorMessage) {
		log.error(errorMessage);
	}
}
