package toolbus.communication;

import java.net.Socket;
import java.nio.channels.SocketChannel;

import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;

/**
 * Interface that defines all methods that are required for connection handlers. They need to
 * facilitate in obtaining a reference to read and write multiplexers and supply methods for closing
 * a connection.
 * 
 * @author Arnold Lankamp
 */
public abstract class AbstractConnectionHandler{
	
	/**
	 * Returns a reference to the read multiplexer.
	 * 
	 * @return A reference to the read multiplexer.
	 */
	public abstract IReadMultiplexer getReadMultiplexer();
	
	/**
	 * Returns a reference to the write multiplexer.
	 * 
	 * @return A reference to the write multiplexer.
	 */
	public abstract IWriteMultiplexer getWriteMultiplexer();
	
	/**
	 * Closes the connection associated with the given socket channel. This method executes a
	 * controlled shutdown of the connection. The socket channel will be deregistered (if needed)
	 * and will be closed.
	 * 
	 * @param socketChannel
	 *            The socket channel, who's associated socket should be closed.
	 */
	public abstract void closeConnection(SocketChannel socketChannel);
	
	/**
	 * Closes the connection associated with the given socket channel. This method should be invoked
	 * after an error occurs during the usage of a socket / socket channel.
	 * 
	 * @param socketChannel
	 *            The socket channel, who's associated socket should be closed.
	 * @param socketIOHandler
	 *            The socket I/O handler associated with the connection that was disconnected.
	 */
	public void closeDueToException(SocketChannel socketChannel, SocketIOHandler socketIOHandler){
		socketIOHandler.exceptionOccured();
		
		Socket socket = socketChannel.socket();
		LoggerFactory.log("The connection with the application running on: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + " will be closed, because it caused an exception.", ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		
		closeConnection(socketChannel);
	}
	
	/**
	 * Closes the connection associated with the given socket channel. This method should be invoked
	 * when an unexpected disconnect occurred on the given socket / socket channel.
	 * 
	 * @param socketChannel
	 *            The socket channel, who's associated socket should be closed.
	 * @param socketIOHandler
	 *            The socket I/O handler associated with the connection that was disconnected.
	 */
	public void closeDueToDisconnect(SocketChannel socketChannel, SocketIOHandler socketIOHandler){
		socketIOHandler.exceptionOccured();
		
		Socket socket = socketChannel.socket();
		LoggerFactory.log("The application running on: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ", was disconnected. The connection will now be closed.", ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		
		closeConnection(socketChannel);
	}
}
