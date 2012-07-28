package toolbus.logging;

import java.util.HashSet;
import java.util.Set;

//TODO make configurable.

/**
 * Factory for creating a logger. Follows singleton design pattern.
 * 
 * @author Arnold Lankamp
 */
public class LoggerFactory{
	private final static Set<String> registeredTypes = new HashSet<String>();
	private final static Set<String> registeredNames = new HashSet<String>();
	private static int nrOfRegisteredNames = 0;
	private static String filter = "";
	
	/*
	 * All configuration is now done here in line in the code;
	 * This should be moved to the property file and/or commandline.
	 */
	static{
		// Register all the log types that should be logged.
		registerType(IToolBusLoggerConstants.TOOL);
		registerType(IToolBusLoggerConstants.TOOLINSTANCE);
		registerType(IToolBusLoggerConstants.COMMUNICATION);
		//registerType(IToolBusLoggerConstants.PARSING);		
		//registerType(IToolBusLoggerConstants.MESSAGES);
		//registerType(IToolBusLoggerConstants.NOTES);
		//registerType(IToolBusLoggerConstants.CALLS);
		//registerType(IToolBusLoggerConstants.EXECUTE);
		//registerType(IToolBusLoggerConstants.TOOLCOM);
		
		//registerName("EditSyntax");
		//filter = "EditSyntax";
	}
	
	/**
	 * Default constructor. Private to prevent instantiation.
	 */
	private LoggerFactory(){
		super();
	}
	
	/**
	 * Registers the given string as a log type identifier. All registered log types will be logged.
	 * All messages with log types that aren't registered will be ignored.
	 * 
	 * @param type
	 *            The log type identifier.
	 */
	public static void registerType(String type){
		registeredTypes.add(type);
	}
	
	/**
	 * Deregisters the given string as log type identifier, so the messages that are associated with
	 * it will no longer be logged.
	 * 
	 * @param type
	 *            The log type identifier.
	 */
	public static void deregisterType(String type){
		registeredTypes.remove(type);
	}
	
	/**
	 * Registers the given string as a name. Only messages containing name will be logged.
	 * 
	 * @param name
	 *            The name of interest.
	 */
	public static void registerName(String name){
		registeredNames.add(name);
		nrOfRegisteredNames++;
	}
	
	/**
	 * Deregisters the given string as a name, so the messages that are associated with
	 * it will no longer be logged.
	 * 
	 * @param name
	 *            The name of interest.
	 */
	public static void deregisterName(String name){
		registeredNames.remove(name);
		nrOfRegisteredNames--;
	}
	
	/**
	 * Convenience method for debugging.
	 * @param processName TODO
	 * @param message
	 *            The message that needs to be logged.
	 * @param type
	 *            The type of the message.
	 */
	public static void log(String processName, String message, String type){
		if((nrOfRegisteredNames == 0 || registeredNames.contains(processName)) &&
				registeredTypes.contains(type)){
			String msg = "[" + processName + "]: " + message;
			//if(msg.contains(filter)){
				//System.err.println("contains: " + filter + " in " + msg);
				getLogger().log(msg, ILogger.DEBUG);
			//}
		}
	}
	
	/**
	 * Convenience method for logging.
	 * 
	 * @param message
	 *            The message that needs to be logged.
	 * @param loglevel
	 *            The log level of the message.
	 */
	public static void log(String message, int loglevel, String type){
		if(!registeredTypes.contains(type)) return;
		if(message.contains(filter)){
			getLogger().log(message, loglevel);
		}
	}
	
	/**
	 * Convenience method for logging.
	 * 
	 * @param message
	 *            The message that needs to be logged.
	 * @param throwable
	 *            The stacktrace associated with the message.
	 * @param loglevel
	 *            The log level of the message.
	 */
	public static void log(String message, Throwable throwable, int loglevel, String type){
		if(!registeredTypes.contains(type)) return;
		if(message.contains(filter)){
			getLogger().log(message, throwable, loglevel);
		}
	}
	
	/**
	 * Returns a reference to the instantiated logger.
	 * 
	 * @return A reference to the instantiated logger.
	 */
	public static ILogger getLogger(){
		return LoggerKeeper.logger;
	}
	
	/**
	 * Instance keeper; for ensuring thread-safe, lazy intialization of the logger.
	 * 
	 * @author Arnold Lankamp
	 */
	private static class LoggerKeeper{
		public final static ILogger logger;
		
		static{
			// TODO Increase the log level to warning later.
			// TODO make the logger type configurable.
			logger = new CommandLineLogger(ILogger.WARNING); 
			//logger = new FileLogger(ILogger.DEBUG);
		}
	}
}
