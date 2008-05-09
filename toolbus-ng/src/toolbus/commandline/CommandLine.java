package toolbus.commandline;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;
import toolbus.ToolBus;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;

public class CommandLine{
	private final ToolBusInputStreamHandler toolBusInputStreamHandler;
	
	private CommandLine(ToolBus toolbus, InputStream is, boolean closeStreamWhenDone){
		super();
		
		toolBusInputStreamHandler = new ToolBusInputStreamHandler(toolbus, is == null ? System.in : is, closeStreamWhenDone);
	}
	
	private void startHandling(){
		Thread toolBusInputStreamHandlerThread = new Thread(toolBusInputStreamHandler);
		toolBusInputStreamHandlerThread.setName("ToolBus inputstream handler");
		toolBusInputStreamHandlerThread.setDaemon(true);
		toolBusInputStreamHandlerThread.start();
	}
	
	public static CommandLine createCommandLine(ToolBus toolbus, InputStream is, boolean closeStreamWhenDone){
		CommandLine commandLine = new CommandLine(toolbus, is, closeStreamWhenDone);
		commandLine.startHandling();
		return commandLine;
	}
	
	public static class ToolBusInputStreamHandler implements Runnable{
		private final ToolBus toolbus;
		private final BufferedReader reader;
		private final boolean closeStreamWhenDone;
		
		public ToolBusInputStreamHandler(ToolBus toolbus, InputStream inputStream, boolean closeStreamWhenDone){
			this.toolbus = toolbus;
			reader = new BufferedReader(new InputStreamReader(inputStream));
			this.closeStreamWhenDone = closeStreamWhenDone;
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
					}else if(line.equals("dump queued messages")){
						toolbus.getToolInstanceManager().printQueueTerms();
					}else if(line.equals("dump toolbus state")){
						toolbus.showStatus();
					}else if(line.equals("shutdown")){
						toolbus.shutdown(toolbus.getTBTermFactory().makeList());
					}else if(line.equals("help")){
						System.err.println("dump unhandled messages: Prints all (currently) unhandled messages and enqueued notes.");
						System.err.println("dump performance stats: Prints some performance statistics related to the execution of the ToolBus.");
						System.err.println("dump tools status: Prints a listing of currently connected tools with their corresponding state.");
						System.err.println("dump queued messages: Prints all (currently) queued values and events.");
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
				if(closeStreamWhenDone){
					try{
						reader.close();
					}catch(IOException ioex){
						LoggerFactory.log("Unable to close the ToolBus's input stream.", ILogger.FATAL, IToolBusLoggerConstants.TOOLINSTANCE);
					}
				}
			}
		}
	}
}
