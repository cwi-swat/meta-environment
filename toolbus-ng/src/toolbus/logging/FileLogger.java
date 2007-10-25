package toolbus.logging;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.PrintWriter;

/**
 * Logger implementation that writes to a file.
 * 
 * @author Arnold Lankamp
 */
public class FileLogger implements ILogger{
	private final static String endLineCharacter = System.getProperty("line.separator");

	private final int level;

	private final PrintWriter writer;
	
	private boolean timestamp = false;

	/**
	 * Default constructor. Inititalizes this logger with the default log level (WARNING).
	 */
	FileLogger(){
		this(ILogger.WARNING);
	}

	/**
	 * Constructor. Initialized this logger with the given log level.
	 * 
	 * @param level
	 *            The log level to initialize this logger with.
	 */
	FileLogger(int level){
		super();

		this.level = level;

		try{
			// TODO make configurable.
			writer = new PrintWriter(new FileOutputStream(new File("./toolbus.log"), true));
		}catch(IOException ioex){
			throw new RuntimeException(ioex);
		}
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
	 * @see ILogger#log(String, int)
	 */
	public void log(String message, int loglevel){
		if(shouldLog(loglevel)){
			synchronized(writer){
				if(timestamp){
					writer.print("[");
					writer.print(CommandLineLogger.getFormattedDateTime());
					writer.print("] - ");
				}
				writer.print(CommandLineLogger.getLogLevelString(loglevel));
				writer.print(" - ");
				writer.print(message);
				writer.print(endLineCharacter);

				writer.flush();
			}
		}
	}

	/**
	 * @see ILogger#log(String, Throwable, int)
	 */
	public void log(String message, Throwable throwable, int loglevel){
		if(shouldLog(loglevel)){
			synchronized(writer){
				if(timestamp){
					writer.print("[");
					writer.print(CommandLineLogger.getFormattedDateTime());
					writer.print("] - ");
				}
				writer.print(CommandLineLogger.getLogLevelString(loglevel));
				writer.print(" - ");
				writer.print(message);
				writer.print(endLineCharacter);

				throwable.printStackTrace(writer);
				writer.print(endLineCharacter);

				writer.flush();
			}
		}
	}

	/**
	 * Closes this logger.
	 */
	public void finalize(){
		writer.close();
	}
}
