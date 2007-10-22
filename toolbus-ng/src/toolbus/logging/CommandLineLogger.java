package toolbus.logging;

import java.io.PrintStream;
import java.text.SimpleDateFormat;
import java.util.Date;

/**
 * Logger implementation that writes to the command line / std-err.
 * 
 * @author Arnold Lankamp
 */
public class CommandLineLogger implements ILogger{
	private final int level;
	private final PrintStream printStream;
	private boolean timestamp = false;

	/**
	 * Default constructor. Inititalizes this logger with the default log level (WARNING).
	 */
	CommandLineLogger(){
		this(ILogger.WARNING);
	}

	/**
	 * Constructor. Initialized this logger with the given log level.
	 * 
	 * @param level
	 *            The log level to initialize this logger with.
	 */
	CommandLineLogger(int level){
		super();

		this.level = level;
		printStream = System.err;
	}

	/**
	 * Method for checking if we should log a message. This depends on the log level and the given
	 * log level.
	 * 
	 * @param loglevel
	 *            The log level of the message.
	 * @return True if we should log the message with the given log level, false otherwise.
	 */
	private boolean shouldLog(int loglevel){
		return (this.level >= loglevel);
	}
	
	/* 
	 * @see toolbus.logging.ILogger#setTimestamp(boolean)
	 */
	public void setTimestamp(boolean on) {
		timestamp = on;
	}

	/**
	 * @see ILogger#log(String, byte)
	 */
	public void log(String message, int loglevel){
		if(shouldLog(loglevel)){
			PrintStream ps = printStream;
			synchronized(ps){
				if(timestamp){
					ps.print("[");
					ps.print(getFormattedDateTime());
					ps.print("] - ");
				}
				ps.print(getLogLevelString(loglevel));
				ps.print(" - ");
				ps.print(message);
				ps.println();
			}
		}
	}

	/**
	 * @see ILogger#log(String, Throwable, byte)
	 */
	public void log(String message, Throwable throwable, int loglevel){
		if(shouldLog(loglevel)){
			PrintStream ps = printStream;
			synchronized(ps){
				if(timestamp){
					ps.print("[");
					ps.print(getFormattedDateTime());
					ps.print("] - ");
				}
				ps.print(getLogLevelString(loglevel));
				ps.print(" - ");
				ps.print(message);
				ps.println();
				
				throwable.printStackTrace(ps);
				ps.println();
			}
		}
	}

	/**
	 * Returns a properly formated string containing the date and time.
	 * 
	 * @return A properly formated string containing the date and time.
	 */
	public static String getFormattedDateTime(){
		return new SimpleDateFormat("yyyy/MM/dd HH:mm:ss z").format(new Date());
	}

	/**
	 * Returns a string containing a string representation of the log level.
	 * 
	 * @param logLevel
	 *            The log level we want the string representation of.
	 * @return The string representation of the given log level.
	 */
	public static String getLogLevelString(int logLevel){
		switch(logLevel){
			case ILogger.ERROR:
				return ILogger.ERRORSTR;
			case ILogger.WARNING:
				return ILogger.WARNINGSTR;
			case ILogger.FATAL:
				return ILogger.FATALSTR;
			case ILogger.INFO:
				return ILogger.INFOSTR;
			case ILogger.DEBUG:
				return ILogger.DEBUGSTR;
			case ILogger.LOG:
				return ILogger.LOGSTR;
			default:
				return ILogger.UNKNOWNSTR;
		}
	}

	
}
