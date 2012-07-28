package nl.cwi.bus.client.communication;

import java.io.IOException;
import java.net.ServerSocket;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;

import nl.cwi.bus.client.InterToolDataHandler;
import nl.cwi.bus.communication.MultiThreadedMultiplexer;
import nl.cwi.bus.communication.Multiplexer;
import nl.cwi.bus.communication.SelectorCreator;
import nl.cwi.bus.communication.ToolDataHandlerFactory;
import nl.cwi.bus.config.Config;
import nl.cwi.util.logging.Logger;

/**
 * Server which uses a multiplexer for handling connections
 * 
 * @author Arnold Lankamp
 */
public class MultiplexingClientServer{
	private Selector selector = null;
	private Multiplexer multiplexer = null;

	/**
	 * Constructor.
	 * @param selectorCreator The selector creator that will be used for creating a selector for the multiplexer.
	 */
	public MultiplexingClientServer(SelectorCreator selectorCreator){
		super();

		init(selectorCreator);
	}

	/**
	 * Initializes the serversocket and the multiplexer.
	 * @param selectorCreator The selector creator that will be used for creating a selector for the multiplexer.
	 */
	private void init(SelectorCreator selectorCreator){
		try{
			ServerSocketChannel channel = ServerSocketChannel.open();
			ServerSocket serverSocket = channel.socket();
			
			//Set the preference to bandwidth > short connection time && latency (only large messages will be send / received here).
			serverSocket.setPerformancePreferences(0, 0, 2);
			
			serverSocket.bind(null);
			Config.setUsingPort(serverSocket.getLocalPort());
			
			channel.configureBlocking(false);
			selector = selectorCreator.getSelector();
			channel.register(selector, SelectionKey.OP_ACCEPT);
			
			ToolDataHandlerFactory toolDataHandlerFactory = new ToolDataHandlerFactory(InterToolDataHandler.class);
			multiplexer = new MultiThreadedMultiplexer(selectorCreator, Multiplexer.SERVERMODE, toolDataHandlerFactory);
			multiplexer.setDaemon(true);
			multiplexer.start();
		}catch(IOException ioex){
			Logger.getInstance().log("An IOException occured while initializing the MultiplexingClientServer.", Logger.ERROR, ioex);
		}
	}
	
	/**
	 * Stops the execution of the multiplexer
	 */
	public void stopRunning(){
		multiplexer.stopRunning();
	}
}
