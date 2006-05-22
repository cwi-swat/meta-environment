package nl.cwi.util.logging;

import java.io.File;
import java.io.FileOutputStream;
import java.io.IOException;
import java.io.OutputStream;
import java.io.PrintWriter;

import nl.cwi.bus.config.Config;

/**
 * Logs messages to a file. Follows singleton design pattern.
 * 
 * @author Arnold Lankamp
 */
public class Logger{
	public final static byte DEBUG = 1;
	public final static byte INFO = 2;
	public final static byte WARNING = 3;
	public final static byte ERROR = 4;
	public final static byte FATAL = 5;
	public final static byte LOG = 127;
	private final static String DEBUGPREFIX = "DEBUG : ";
	private final static String INFOPREFIX = "INFO : ";
	private final static String WARNINGPREFIX = "WARNING : ";
	private final static String ERRORPREFIX = "ERROR : ";
	private final static String FATALPREFIX = "FATAL : ";
	private final static String LOGPREFIX = "LOG : ";

	private final static byte DEFAULTLOGLEVEL = 2;

	private final static String ENDLINECHAR = System.getProperty("line.separator");

	private File file = null;

	private byte loglevel = -1;

	private OutputStream os = null;

	private Logger(){
		super();

		file = Config.getLogFile();

		loglevel = DEFAULTLOGLEVEL;

		init();
	}

	/**
	 * Initialized the outputstream
	 */
	private void init(){
		try{
			os = new FileOutputStream(file, true);
		}catch(IOException ioex){
			ioex.printStackTrace();
		}
	}

	/**
	 * Sets the loglevel
	 * 
	 * @param level
	 *            The loglevel that should be used from now on
	 */
	public void setLogLevel(byte level){
		this.loglevel = level;
	}

	/**
	 * Logs the given message with the default loglevel
	 * 
	 * @param message
	 *            The message to log
	 */
	public void log(String message){
		log(message, DEFAULTLOGLEVEL);
	}

	/**
	 * Logs the given message with the default loglevel
	 * 
	 * @param message
	 *            The message to log
	 * @param throwable
	 *            The throwable that contains the stacktrace of the exception
	 */
	public void log(String message, Throwable throwable){
		log(message, DEFAULTLOGLEVEL, throwable);
	}

	/**
	 * Logs the given message if the loglevel acceeds the set loglevel
	 * 
	 * @param message
	 *            The message to log
	 * @param level
	 *            The loglevel of the message
	 */
	public void log(String message, byte level){
		if(level >= this.loglevel){
			logMessage(message, level, null);
		}
	}

	/**
	 * Logs the given message if the loglevel acceeds the set loglevel
	 * 
	 * @param message
	 *            The message to log
	 * @param level
	 *            The loglevel of the message
	 * @param throwable
	 *            The throwable that contains the stacktrace of the exception
	 */
	public void log(String message, byte level, Throwable throwable){
		if(level >= this.loglevel){
			logMessage(message, level, throwable);
		}
	}

	/**
	 * Writes the given message to a file
	 * 
	 * @param message
	 *            The message to write
	 */
	private void persist(String message){
		byte[] stringBytes = message.getBytes();
		try{
			os.write(stringBytes);
			os.flush();
		}catch(IOException ioex){
			ioex.printStackTrace();
		}
	}

	/**
	 * Destroys this logger. Do not call any methods on this logger after
	 * destroying it as it will lead to a NullPointerException
	 */
	public void destroy(){
		if(os != null){
			try{
				os.close();
			}catch(IOException ioex){
				ioex.printStackTrace();
			}
			os = null;
		}
	}

	/**
	 * Logs the stacktrace of the given throwable
	 * 
	 * @param throwable
	 *            The throwable of which the stacktrace will be logged
	 */
	private void logStackTrace(Throwable throwable){
		PrintWriter pw = new PrintWriter(os);
		throwable.printStackTrace(pw);
		pw.flush();
	}

	/**
	 * Logs the message and appends the loglevel as a prefix
	 * 
	 * @param message
	 *            The message that will be logged
	 * @param level
	 *            The loglevel of the given message
	 * @param throwable
	 *            The throwable that contains the stacktrace, in case an
	 *            exception is logged (optional, set to null if unavailable)
	 */
	private synchronized void logMessage(String message, byte level, Throwable throwable){
		if(level == DEBUG){
			persist(DEBUGPREFIX);
		}else if(level == INFO){
			persist(INFOPREFIX);
		}else if(level == WARNING){
			persist(WARNINGPREFIX);
		}else if(level == ERROR){
			persist(ERRORPREFIX);
		}else if(level == FATAL){
			persist(FATALPREFIX);
		}else if(level == LOG){
			persist(LOGPREFIX);
		}

		persist(message);
		if(throwable != null){
			persist(ENDLINECHAR);
			logStackTrace(throwable);
		}
		persist(ENDLINECHAR);
	}

	/**
	 * Instancekeeper to ensure lazy initialization of this singleton
	 * 
	 * @author Arnold Lankamp
	 */
	private static class InstanceKeeper{
		private final static Logger instance = new Logger();
	}

	/**
	 * Returns a reference to the instance of this logger
	 * 
	 * @return A reference to the instance of this logger
	 */
	public static Logger getInstance(){
		return InstanceKeeper.instance;
	}
}
