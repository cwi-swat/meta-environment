package toolbus.adapter.eclipse;

import java.net.InetAddress;

import toolbus.adapter.AbstractTool;
import toolbus.adapter.java.JavaToolBridge;
import toolbus.communication.IDataHandler;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.pure.PureFactory;

public class EclipseToolBridge extends JavaToolBridge{
	
	public EclipseToolBridge(PureFactory termFactory, AbstractTool tool, String toolName, int toolID, InetAddress host, int port){
		super(termFactory, tool, toolName, toolID, host, port);
	}
	
	/**
	 * @see IDataHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		LoggerFactory.log("Lost connection with the ToolBus. Initiating ungraceful shutdown ....", ILogger.FATAL, IToolBusLoggerConstants.TOOL);
		
		// TODO What to do now?
	}
}
