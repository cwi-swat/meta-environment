package nl.cwi.bus.server.communication;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;

import nl.cwi.bus.communication.MultiThreadedMultiplexer;
import nl.cwi.bus.communication.Multiplexer;
import nl.cwi.bus.communication.SelectorCreator;
import nl.cwi.bus.communication.SocketIOHandler;
import nl.cwi.bus.communication.ToolDataHandlerFactory;
import nl.cwi.bus.config.Config;
import nl.cwi.bus.server.ToolInstance;
import nl.cwi.util.logging.Logger;

/**
 * Server which uses a multiplexer for handling connections
 * 
 * @author Arnold Lankamp
 */
public class MultiplexingServer{
	private Selector selector = null;
	private Multiplexer multiplexer = null;

	/**
	 * Default constructor
	 */
	public MultiplexingServer(){
		super();

		init();
	}

	/**
	 * Initializes the serversocket and the multiplexer
	 */
	private void init(){
		try{
			ServerSocketChannel channel = ServerSocketChannel.open();
			ServerSocket serverSocket = channel.socket();
			
			//Set the preference to short connection time > bandwidth > latency (only small messages will be send / received here).
			serverSocket.setPerformancePreferences(1, 2, 0);
			
			serverSocket.bind(new InetSocketAddress(Config.getServerPort()));
			Config.setUsingPort(serverSocket.getLocalPort());
			channel.configureBlocking(false);
			
			SelectorCreator selectorContainer = new SelectorCreator();
			selector = selectorContainer.getSelector();
			channel.register(selector, SelectionKey.OP_ACCEPT);
			
			ToolDataHandlerFactory toolDataHandlerFactory = new ToolDataHandlerFactory(ToolInstance.class);
			multiplexer = new MultiThreadedMultiplexer(selectorContainer, Multiplexer.SERVERMODE, toolDataHandlerFactory);
			multiplexer.setDaemon(true);
			multiplexer.start();
		}catch(IOException ioex){
			Logger.getInstance().log("An IOException occured while initializing the MultiplexingServer.", Logger.ERROR, ioex);
		}
	}
	
	/**
	 * Associates a ioHandler with the given channel. The existing ioHandler that was associated with this channel will be terminated.
	 * @param socketChannel The socketchannel the io handler should be associated with.
	 * @param socketIOHandler The io handler that will be associted with the given socket channel.
	 */
	public void installHandler(SocketChannel socketChannel, SocketIOHandler socketIOHandler){
		SelectionKey key = socketChannel.keyFor(selector);
		SocketIOHandler oldIOHandler = (SocketIOHandler)key.attachment();
		oldIOHandler.terminate();
		
		try{
			socketChannel.register(selector, SelectionKey.OP_READ | SelectionKey.OP_WRITE, socketIOHandler);
		}catch(IOException ioex){
			Logger.getInstance().log("An IOException occured while installing a handler on a socketChannel.", Logger.ERROR, ioex);
		}
	}
	
	/**
	 * Stops the execution of the multiplexer
	 */
	public void stopRunning(){
		multiplexer.stopRunning();
	}
}
