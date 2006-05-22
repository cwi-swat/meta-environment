package nl.cwi.bus.client.communication;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;

import nl.cwi.bus.communication.IDataHandler;
import nl.cwi.bus.communication.Multiplexer;
import nl.cwi.bus.communication.SelectorCreator;
import nl.cwi.bus.communication.SocketIOHandler;
import nl.cwi.bus.config.Config;
import nl.cwi.util.logging.Logger;

/**
 * Client which uses a multiplexer for handling connections
 * 
 * @author Arnold Lankamp
 */
public class MultiplexingClient{
	private Selector selector = null;
	private SocketIOHandler ioHandler = null;
	private Multiplexer multiplexer = null;

	/**
	 * Constructor
	 * 
	 * @param dataHandler
	 *            The dataHandler all requests should be forwarded to
	 */
	public MultiplexingClient(IDataHandler dataHandler){
		super();

		init(dataHandler);
	}

	/**
	 * Initializes the socket, multilexer and ioHandler
	 * 
	 * @param dataHandler
	 *            The dataHandler all requests should be forwarded to
	 */
	private void init(IDataHandler dataHandler){
		try{
			SocketChannel socketChannel = SocketChannel.open();
			
			Socket socket = socketChannel.socket();
			//Set the preference to short connection time > bandwidth > latency (only small messages will be send /received here).
			socket.setPerformancePreferences(1, 2, 0);
			
			socketChannel.connect(new InetSocketAddress(Config.getHostName(), Config.getServerPort()));
			socketChannel.configureBlocking(false);

			SelectorCreator selectorContainer = new SelectorCreator();
			ioHandler = new SocketIOHandler(selectorContainer, socketChannel);
			ioHandler.setDataHandler(dataHandler);

			selector = selectorContainer.getSelector();
			socketChannel.register(selector, SelectionKey.OP_READ, ioHandler);
			
			multiplexer = new Multiplexer(selectorContainer, Multiplexer.CLIENTMODE, null);
			multiplexer.setDaemon(true);
			multiplexer.start();
		}catch(IOException ioex){
			Logger.getInstance().log("An IOException occured during initialization of the MultiplexingClient.", Logger.ERROR, ioex);
		}
	}

	/**
	 * Returns the with this client associated ioHandler
	 * 
	 * @return The with this client associated ioHandler
	 */
	public SocketIOHandler getIOHandler(){
		return ioHandler;
	}
	
	/**
	 * Stops the execution of the multiplexer
	 */
	public void stopRunning(){
		multiplexer.stopRunning();
	}
}
