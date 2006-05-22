package nl.cwi.bus.config;

import java.io.File;
import java.lang.management.ManagementFactory;

/**
 * Class containing configuration properties
 * 
 * @author Arnold Lankamp
 */
public class Config{
	private final static String HOSTNAME = "127.0.0.1";
	private final static int SERVERPORT = 4000;
	// This relies on Sun JDK 1.5 functionality (one of its few usefull
	// features; that should really have been added years ago)
	private final static int NROFCONCURRENTTHREADS = ManagementFactory.getOperatingSystemMXBean().getAvailableProcessors() * 3;

	private static int port = -1;
	
	private final static File LOGFILE = new File("bus.log");
	
	private final static int THRESHOLD = 0;//Integer.MAX_VALUE;

	/**
	 * Default constructor. Private to prevent needless instantiation of this
	 * class.
	 */
	private Config(){
		super();
	}

	/**
	 * Returns the hostname of the server
	 * 
	 * @return The hostname of the server
	 */
	public static String getHostName(){
		return HOSTNAME;
	}

	/**
	 * Returns the Portnumber the server is / should be running on
	 * 
	 * @return The port number
	 */
	public static int getServerPort(){
		return SERVERPORT;
	}

	/**
	 * Sets the port the application is currently using.
	 * 
	 * @param port
	 *            The port the application is useing.
	 */
	public static void setUsingPort(int port){
		Config.port = port;
	}

	/**
	 * Returns the port the application is currently using (returns -1 if it has
	 * not been set yet).
	 * 
	 * @return The port the application is currently using.
	 */
	public static int getUsingPort(){
		return port;
	}

	/**
	 * Returns the optimal number of concurrently running threads for this
	 * machine.
	 * 
	 * @return The optimal number of concurrent threads.
	 */
	public static int getNrOfConcurrentThreads(){
		return NROFCONCURRENTTHREADS;
	}
	
	/**
	 * Returns the file that will be used for logging.
	 * @return The file that will be used for logging.
	 */
	public static File getLogFile(){
		return LOGFILE;
	}
	
	/**
	 * Returns the threshold which is used to determain how to send data between tools.
	 * @return The threshold value.
	 */
	public static int getThreshold(){
		return THRESHOLD;
	}
}
