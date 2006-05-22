package nl.cwi.bus.communication;

import java.io.IOException;
import java.net.Socket;
import java.nio.channels.ClosedChannelException;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;

import nl.cwi.util.logging.Logger;

/**
 * This class 'watches' all socketchannels. If there is data ready for reading
 * or writing the with the socketchannel associated ioHandler will be notified.
 * 
 * @author Arnold Lankamp
 */
public class Multiplexer extends Thread{
	public final static byte SERVERMODE = 1;
	public final static byte CLIENTMODE = 2;

	private SelectorCreator selectorCreator = null;
	private int mode = -1;
	private ToolDataHandlerFactory toolDataHandlerFactory = null;

	private boolean running = false;

	/**
	 * Constructor
	 * 
	 * @param selectorCreator
	 *            The selectorContainer that contains the selector is used for
	 *            activity notifications.
	 * @param mode
	 *            The 'mode' this multiplexer is running in (server/client mode,
	 *            servers are also capable of accepting incoming connections).
	 * @param toolDataHandlerFactory
	 *            A factory for creating tooldataHandlers (only needed when
	 *            running in server mode).
	 */
	public Multiplexer(SelectorCreator selectorCreator, byte mode, ToolDataHandlerFactory toolDataHandlerFactory){
		super();

		this.selectorCreator = selectorCreator;
		this.mode = mode;
		this.toolDataHandlerFactory = toolDataHandlerFactory;
	}

	/**
	 * Method for checking is the multiplexer is running
	 * 
	 * @return true if the multiplexer is running, false otherwise
	 */
	public boolean isRunning(){
		return running;
	}

	/**
	 * Stops the execution of this multiplexer at the next iteration
	 */
	public void stopRunning(){
		setRunning(false);
		// Let the selector return imidiately
		selectorCreator.getSelector().wakeup();
	}

	/**
	 * Sets this multiplexers 'running' flag. If the flag is set to false during
	 * operation, it will terminate at the next iteration.
	 * 
	 * @param running
	 *            The 'running' flag
	 */
	protected void setRunning(boolean running){
		this.running = running;
	}

	/**
	 * Returns the 'mode' this multiplexer is running in.
	 * 
	 * @return The mode (Server / Client)
	 */
	protected int getMode(){
		return mode;
	}

	/**
	 * Returns the selector
	 * 
	 * @return The selector
	 */
	protected Selector getSelector(){
		return selectorCreator.getSelector();
	}

	/**
	 * The main loop of this multiplexer. It waits for something to happen, then
	 * notifies the associated ioHandler
	 */
	public void run(){
		setRunning(true);

		while(running){
			try{
				getSelector().select();
			}catch(IOException ioex){
				Logger.getInstance().log("An exception occured during the exection of the multiplexer (select())", Logger.ERROR, ioex);
			}

			Set readyKeys = selectorCreator.getSelector().selectedKeys();
			Iterator iterator = readyKeys.iterator();
			while(iterator.hasNext()){
				SelectionKey key = (SelectionKey) iterator.next();
				iterator.remove();

				try{
					if(getMode() == SERVERMODE && key.isAcceptable()){
						accept(key);
					}
					if(key.isWritable()){
						write(key);
					}
					if(key.isReadable()){
						read(key);
					}
				}catch(IOException ioex){
					Logger.getInstance().log("An IOException occured during the exection of the multiplexer,. The connection might be lost.", Logger.ERROR, ioex);

					// Close the connection if an ioexception occurs
					closeDueToDisconnect(key);
				}catch(RuntimeException rex){
					Logger.getInstance().log("A RuntimeException occured during the exection of the multiplexer.", Logger.ERROR, rex);
				}
			}

			synchronized(selectorCreator.getSelectionPreventionLock()){
				// This is just a barrier
			}
			
			Thread.yield();
		}
	}

	/**
	 * Accepts an incoming connection
	 * 
	 * @param key
	 *            The selectionkey
	 * @throws IOException
	 */
	protected void accept(SelectionKey key) throws IOException{
		// Accept the connection
		ServerSocketChannel server = (ServerSocketChannel) key.channel();
		SocketChannel socketChannel = server.accept();
		socketChannel.configureBlocking(false);

		// Disable Nagle's algorithm, we don't want the random 500ms delays.
		Socket socket = socketChannel.socket();
		socket.setTcpNoDelay(true);

		// Initialize the handlers and register it for readin incoming data.
		// However the datahandler may register this channel for different
		// operations and thus should be created last.
		SocketIOHandler ioHandler = new SocketIOHandler(selectorCreator, socketChannel);
		socketChannel.register(selectorCreator.getSelector(), SelectionKey.OP_READ, ioHandler);
		IDataHandler dataHandler = toolDataHandlerFactory.createToolDataHandler(ioHandler);
		ioHandler.setDataHandler(dataHandler);
	}

	/**
	 * Writes to a channel
	 * 
	 * @param key
	 *            The selectionkey
	 * @throws ClosedChannelException
	 */
	protected void write(SelectionKey key) throws ClosedChannelException{
		SocketIOHandler ioHandler = (SocketIOHandler) key.attachment();
		ioHandler.write();
	}

	/**
	 * Reads from a channel
	 * 
	 * @param key
	 *            The selectionkey
	 */
	protected void read(SelectionKey key){
		SocketIOHandler ioHandler = (SocketIOHandler) key.attachment();
		ioHandler.receive(key);
	}

	/**
	 * This method will take appropriate measures when a connection is lost.
	 * 
	 * @param key
	 *            The key associated with the by disconnect closed channel.
	 */
	public static void closeDueToDisconnect(SelectionKey key){
		SocketChannel socketChannel = (SocketChannel) key.channel();
		Socket socket = socketChannel.socket();
		Logger.getInstance().log("The application running on: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ", was disconnected. The connection will now be closed.", Logger.WARNING);

		closeConnection(key);
	}

	/**
	 * Closes the with the key assiciated socket and channel and cancels the
	 * key.
	 * 
	 * @param key
	 */
	public static void closeConnection(SelectionKey key){
		key.cancel();
		
		// Remove the attachment
		key.attach(null);

		SocketChannel socketChannel = (SocketChannel) key.channel();
		Socket socket = socketChannel.socket();
		Logger.getInstance().log("Closing connection for: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ".", Logger.INFO);

		try{
			socketChannel.close();
		}catch(IOException ioex){
			Logger.getInstance().log("Failed to close the channel for: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ".", Logger.ERROR, ioex);
		}

		try{
			socket.close();
		}catch(IOException ioex){
			Logger.getInstance().log("Failed to close the socket for: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ".", Logger.ERROR, ioex);
		}
	}

}
