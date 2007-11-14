/**
 * @author paulk
 */

package toolbus;

import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStream;
import java.io.InputStreamReader;

import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;

public class Main{
	
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
					}else{
						System.err.println("Unknown ToolBus command: '"+line+"'");
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

	public static void main(String[] args){
		ToolBus toolbus = new ToolBus(args);
		
		ToolBusInputStreamHandler toolBusInputStreamHandler = new ToolBusInputStreamHandler(toolbus, System.in);
		Thread toolBusInputStreamHandlerThread = new Thread(toolBusInputStreamHandler);
		toolBusInputStreamHandlerThread.setName("ToolBus inputstream handler");
		toolBusInputStreamHandlerThread.setDaemon(true);
		toolBusInputStreamHandlerThread.start();
		
		try{
			if(toolbus.parsecup()){
				toolbus.execute();
				//Atom.statistics();
			}else{
				System.err.println("Failed to parse");// Temp
			}
		}catch(Exception e){
			e.printStackTrace();
			System.exit(0);
		}

		// System.err.println(T.getTBTermFactory().statistics());
	}
}
