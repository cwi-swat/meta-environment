package toolbus.tool.execution;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.io.PrintStream;

import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;

/**
 * Handles the output and error streams of a tool process.
 * 
 * @author Arnold Lankamp
 */
public class StreamHandler implements Runnable{
	private final Process process;
	private final String toolID;
	
	/**
	 * Constructor.
	 * 
	 * @param process
	 *            The tool process.
	 * @param toolID
	 *            The tool identifier.
	 */
	public StreamHandler(Process process, String toolID){
		this.process = process;
		this.toolID = toolID;
	}
	
	/**
	 * @see java.lang.Runnable#run()
	 */
	public void run(){
		BufferedReader reader = new BufferedReader(new InputStreamReader(process.getInputStream()));
		
		String line = null;
		try{
			while((line = reader.readLine()) != null){
				PrintStream ps = System.out;
				// This is to avoid the silent instantiation and usage of a StringBuffer,
				// without having to obtain and release the monitor to System.out several times.
				synchronized(ps){
					ps.print(toolID);
					ps.print(" >> ");
					ps.print(line);
					ps.println();
				}
			}
		}catch(IOException ioex){
			LoggerFactory.log("An IOException occured while handling the outputstream of tool: " + toolID, ioex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			LoggerFactory.log("Killing tool: " + toolID + ", because it cause an exception.", ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
		}catch(RuntimeException rex){
			LoggerFactory.log("An RuntimeException occured during the execution of tool: " + toolID, rex, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
			LoggerFactory.log("Killing tool: " + toolID + ", because it cause an exception.", ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
		}finally{
			// Kill the subprocess, even if it's already dead. We won't be handling the streams
			// anymore from this point on, it'll probably lock up eventually anyway if it's
			// still running (better kill it ourselfs). It will also close the stream from and
			// to the process, to make sure the associated file descriptor is removed
			// immediately and NOT whenever the JVM feels like it.
			destroy();
			
			// Close the reader.
			try{
				reader.close();
			}catch(IOException ioex){
				LoggerFactory.log("Unable to close the input stream from tool: " + toolID, ILogger.FATAL, IToolBusLoggerConstants.TOOLINSTANCE);
			}
			
			int exitCode = -1;
			do{
				try{
					process.waitFor();
				}catch(InterruptedException irex){
					// Ignore this.
				}
				try{
					exitCode = process.exitValue();
				}catch(IllegalThreadStateException itsex){
					// Ignore this too.
				}
			}while(exitCode == -1);
			
			if(exitCode != 0){
				String error = "Tool "+toolID+" exited unexpectedly with code: "+exitCode;
				LoggerFactory.log(error, ILogger.ERROR, IToolBusLoggerConstants.TOOLINSTANCE);
				throw new RuntimeException(error);
			}
		}
	}
	
	/**
	 * Forcefully terminates the associated tool process.
	 */
	public void destroy(){
		process.destroy();
	}
}