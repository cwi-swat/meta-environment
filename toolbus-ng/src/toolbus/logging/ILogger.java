package toolbus.logging;

public interface ILogger{
	public final static String LOGSTR = 	   "LOG";
	public final static String FATALSTR =   "FATAL";
	public final static String ERRORSTR =   "ERROR";
	public final static String WARNINGSTR = "WARNING";
	public final static String INFOSTR = 	   "INFO";
	public final static String DEBUGSTR =   "DEBUG";
	public final static String UNKNOWNSTR = "UNKNOWN";

	public final static int OFF = 		0x00000000;
	
	public final static int LOG = 		0x00000003;
	public final static int FATAL = 	0x00000007;
	public final static int ERROR = 	0x0000000f;
	public final static int WARNING = 	0x0000001f;
	public final static int INFO = 		0x0000003f;
	public final static int DEBUG = 	0x0000007f;
	
	public final static int ALL = 		0x000000ff;
	
	/**
	 * Toggle timestamp printing in messages
	 * 
	 * @param on
	 * 			Sets timestamp on or off.
	 */
	void setTimestamp(boolean on);

	/**
	 * Logs the given message (but only if the message is 'important' enough).
	 * 
	 * @param message
	 *            The message that needs to be logged.
	 * @param loglevel
	 *            The log level of the message.
	 */
	void log(String message, int loglevel);

	/**
	 * Logs the given message, including the given stacktrace (but only if the message is
	 * 'important' enough).
	 * 
	 * @param message
	 *            The message that needs to be logged.
	 * @param throwable
	 *            The stacktrace associated with the message.
	 * @param loglevel
	 *            The log level of the message.
	 */
	void log(String message, Throwable throwable, int loglevel);
}
