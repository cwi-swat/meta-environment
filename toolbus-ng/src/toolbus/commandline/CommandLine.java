package toolbus.commandline;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import toolbus.ToolBus;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;

// TODO More then one ToolBus can run in the same VM; handle this.
public class CommandLine{
	private final ToolBusInputStreamHandler toolBusInputStreamHandler;
	
	private CommandLine(ToolBus toolbus){
		super();
		
		toolBusInputStreamHandler = new ToolBusInputStreamHandler(toolbus, System.in);
	}
	
	public void startHandling(){
		Thread toolBusInputStreamHandlerThread = new Thread(toolBusInputStreamHandler);
		toolBusInputStreamHandlerThread.setName("ToolBus inputstream handler");
		toolBusInputStreamHandlerThread.setDaemon(true);
		toolBusInputStreamHandlerThread.start();
	}
	
	public static CommandLine createCommandLine(ToolBus toolbus){
		CommandLine commandLine = new CommandLine(toolbus);
		commandLine.startHandling();
		return commandLine;
	}
	
	private static class ToolBusInputStreamHandler implements Runnable{
		private final ToolBus toolbus;
		private final BufferedReader reader;
		
		public ToolBusInputStreamHandler(ToolBus toolbus, InputStream inputStream){
			this.toolbus = toolbus;
			reader = new BufferedReader(new InputStreamReader(inputStream));
		}
		
		public void run(){
			String line = null;
			try{
				while((line = reader.readLine()) != null){
					if(line.equals("dump unhandled messages")){
						toolbus.dumpUnhandledMessages();
					}else if(line.equals("dump performance stats")){
						toolbus.dumpPerformanceStats();
					}else if(line.equals("dump tools status")){
						toolbus.getToolInstanceManager().showStatus();
					}else if(line.equals("dump toolbus state")){
						toolbus.showStatus();
					}else if(line.equals("shutdown")){
						toolbus.shutdown(toolbus.getTBTermFactory().makeList());
					}else if(line.equals("help")){
						System.err.println("dump unhandled messages: Prints all (currently) unhandled messages and enqueued notes.");
						System.err.println("dump performance stats: Prints some performance statistics related to the execution of the ToolBus.");
						System.err.println("dump tools status: Prints a listing of currently connected tools with their corresponding state.");
						System.err.println("dump toolbus state: Dumps all available information about the current state of the process logic to the command line.");
						System.err.println("shutdown: Initiates the forcefull termination of the ToolBus.");
					}else if(line.equals("")){
						// Ignore this.
					}else{
						System.err.println("Unknown ToolBus command: '"+line+"'.\nEnter 'help' for a list of available ToolBus commands.");
					}
				}
			}catch(IOException ioex){
				LoggerFactory.log("An IOException occured while reading from the ToolBus's inputstream.", ioex, ILogger.ERROR, IToolBusLoggerConstants.EXECUTE);
			}catch(RuntimeException rex){
				LoggerFactory.log("An RuntimeException occured while reading from the ToolBus's inputstream.", rex, ILogger.ERROR, IToolBusLoggerConstants.EXECUTE);
			}finally{
				try{
					reader.close();
				}catch(IOException ioex){
					LoggerFactory.log("Unable to close the ToolBus's input stream.", ILogger.FATAL, IToolBusLoggerConstants.TOOLINSTANCE);
				}
			}
		}
	}
}
