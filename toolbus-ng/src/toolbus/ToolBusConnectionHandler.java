package toolbus;

import java.io.IOException;
import java.net.InetSocketAddress;
import java.net.ServerSocket;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.ServerSocketChannel;
import java.nio.channels.SocketChannel;
import jjtraveler.VisitFailure;
import toolbus.communication.AbstractConnectionHandler;
import toolbus.communication.SocketIOHandler;
import toolbus.communication.SocketReadMultiplexer;
import toolbus.communication.SocketWriteMultiplexer;
import toolbus.exceptions.ToolBusException;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.tool.ToolDefinition;
import toolbus.tool.ToolInstance;
import aterm.ATerm;
import aterm.ATermAppl;
import aterm.pure.PureFactory;
import aterm.pure.binary.BinaryReader;
import aterm.pure.binary.BinaryWriter;

/**
 * This class handles the establishing and closing of all TCP/IP connections.
 * 
 * @author Arnold Lankamp
 */
public class ToolBusConnectionHandler extends AbstractConnectionHandler implements Runnable{
	private final static int HANDSHAKEBUFFERSIZE = 4096;
	
	private final ToolBus toolBus;

	private final SocketReadMultiplexer readMultiplexer;
	private final SocketWriteMultiplexer writeMultiplexer;

	private final ServerSocketChannel serverSocketChannel;
	private final ByteBuffer handShakeBuffer;
	private volatile boolean running = false;

	/**
	 * Constructor.
	 * 
	 * @param toolBus
	 *            A reference to the main class of the ToolBus.
	 */
	public ToolBusConnectionHandler(ToolBus toolBus){
		super();
		
		this.toolBus = toolBus;
		
		try{
			serverSocketChannel = ServerSocketChannel.open();
		}catch(IOException ioex){
			LoggerFactory.log("Unable open a server socket.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(ioex);
		}
		
		readMultiplexer = new SocketReadMultiplexer(this);
		writeMultiplexer = new SocketWriteMultiplexer(this);

		handShakeBuffer = ByteBuffer.allocateDirect(HANDSHAKEBUFFERSIZE);
		
		running = true; // This is placed here, instead of at the start of the run loop because of a potential concurrency problem.
	}

	/**
	 * Initializes the connection handler. Initialization MUST occur before executing the run method.
	 * 
	 * @throws IOException
	 */
	public void initialize() throws IOException{
		ServerSocket serverSocket = serverSocketChannel.socket();
		serverSocket.bind(null);
		serverSocketChannel.configureBlocking(true);
		
		Thread readThread = new Thread(readMultiplexer);
		readThread.setName("Read multiplexer");
		readThread.start();

		Thread writeThread = new Thread(writeMultiplexer);
		writeThread.setName("Write multiplexer");
		writeThread.start();
	}
	
	/**
	 * Initializes the connection handler on a user specified port. Initialization MUST occur before
	 * executing the run method.
	 * 
	 * @throws IOException
	 */
	public void initialize(int port) throws IOException{
		ServerSocket serverSocket = serverSocketChannel.socket();
		serverSocket.bind(new InetSocketAddress(port));
		serverSocketChannel.configureBlocking(true);
		
		Thread readThread = new Thread(readMultiplexer);
		readThread.setName("Read multiplexer");
		readThread.start();

		Thread writeThread = new Thread(writeMultiplexer);
		writeThread.setName("Write multiplexer");
		writeThread.start();
	}
	
	/**
	 * Returns the port number the ToolBus is currently running on.
	 * 
	 * @return The port number the ToolBus is currently running on.
	 */
	public int getPort(){
		return serverSocketChannel.socket().getLocalPort();
	}

	/**
	 * @see AbstractConnectionHandler#getReadMultiplexer()
	 */
	public SocketReadMultiplexer getReadMultiplexer(){
		return readMultiplexer;
	}

	/**
	 * @see AbstractConnectionHandler#getWriteMultiplexer()
	 */
	public SocketWriteMultiplexer getWriteMultiplexer(){
		return writeMultiplexer;
	}

	/**
	 * Checks if this handler is running or not.
	 * 
	 * @return True if this handler is running, false otherwise.
	 */
	public boolean isRunning(){
		return running;
	}

	/**
	 * Stops the execution of this handler. The running state will be set to false and the server
	 * socket will be closed.
	 */
	public void stopRunning(){
		running = false;

		try{
			ServerSocket serverSocket = serverSocketChannel.socket();
			serverSocket.close();
		}catch(IOException ioex){
			LoggerFactory.log("An error occured while shutting down the connection handler.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		}
		
		readMultiplexer.stopRunning();
		writeMultiplexer.stopRunning();
	}

	/**
	 * Main loop of this handler. It tries to accept any incoming connection attempt.
	 */
	public void run(){
		while(running){
			try{
				acceptConnection();
			}catch(IOException ioex){
				if(running) LoggerFactory.log("An error occured while accepting a connection.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
				running = false; // temporary fix to avoid a loop
			}
		}
	}

	/**
	 * Accepts a connection with a remote application.
	 * 
	 * @throws IOException
	 *             Thrown when something goes wrong while accepting the connection, registering it
	 *             or instantiating the associated I/O handlers.
	 */
	private void acceptConnection() throws IOException{
		SocketChannel socketChannel = serverSocketChannel.accept();

		Socket socket = socketChannel.socket();
		// Disable Nagle's algorithm, we don't want the random 500ms delays.
		socket.setTcpNoDelay(true);
		// Set the traffic class to high throughput and low delay.
		socket.setTrafficClass(0x18);

		ToolInstance toolInstance = null;
		try{
			toolInstance = shakeHands(socketChannel);
		}catch(IOException ioex){
			LoggerFactory.log("Unable to shake hands with a tool at: " + socket.getInetAddress().getHostName() + ":" + socket.getPort(), ILogger.WARNING, IToolBusLoggerConstants.COMMUNICATION);
			closeConnection(socketChannel);
			return;
		}catch(ToolBusException tbex){
			LoggerFactory.log("Unable to shake hands with a tool at: " + socket.getInetAddress().getHostName() + ":" + socket.getPort(), ILogger.WARNING, IToolBusLoggerConstants.COMMUNICATION);
			closeConnection(socketChannel);
			return;
		}catch(RuntimeException rex){
			LoggerFactory.log("An runtime exception occured while executing a handshake with a tool at: " + socket.getInetAddress().getHostName() + ":" + socket.getPort(), rex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			closeConnection(socketChannel);
			return;
		}

		if(toolInstance == null){
			LoggerFactory.log("Tool at: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ", didn't supply the the expected interface.", ILogger.WARNING, IToolBusLoggerConstants.COMMUNICATION);
			closeConnection(socketChannel);
			return;
		}

		socketChannel.configureBlocking(false);

		// Set up handlers
		SocketIOHandler ioHandler = new SocketIOHandler(toolInstance, this, socketChannel);
		toolInstance.setIOHandler(ioHandler);

		readMultiplexer.registerForRead(socketChannel, ioHandler);
	}

	private ToolInstance shakeHands(SocketChannel socketChannel) throws IOException, ToolBusException{
		socketChannel.configureBlocking(true);
		
		// Receive tool id.
		ATermAppl toolKey = (ATermAppl) readTermFromChannel(toolBus.getTBTermFactory(), socketChannel, handShakeBuffer);
		String toolName = toolKey.getAFun().getName();
		
		ToolDefinition toolDef = toolBus.getToolDefinition(toolName);
		if(toolDef == null){
			String error = "No toolDef found for tool with name: " + toolName;
			LoggerFactory.log(error, ILogger.WARNING, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(error);
		}

		ToolInstanceManager toolInstanceManager = toolBus.getToolInstanceManager();

		ToolInstance toolInstance = toolInstanceManager.getPendingTool(toolKey);
		
		// If we didn't request the tool with the given id to execute, it's connecting on it's own
		// initiative.
		if(toolInstance == null){
			toolInstance = new ToolInstance(toolDef, toolBus);
			toolInstanceManager.addDynamiclyConnectedTool(toolInstance);

			LoggerFactory.log("Tool: " + toolInstance.getToolKey() + ", connected at its own initiative.", ILogger.INFO, IToolBusLoggerConstants.COMMUNICATION);
		}

		// Send the signature.
		writeTermToChannel(toolDef.getSignature(), socketChannel, handShakeBuffer);

		// Receive signature confirmation.
		handShakeBuffer.clear();
		handShakeBuffer.limit(1);
		socketChannel.read(handShakeBuffer);
		handShakeBuffer.flip();
		byte signatureConfirmation = handShakeBuffer.get();
		if(signatureConfirmation != 1){// Not OK
			toolInstance.kill();
			toolInstance = null;
		}else{
			// Send the (permanent) tool key back to the tool.
			writeTermToChannel(toolInstance.getToolKey(), socketChannel, handShakeBuffer);
		}
		
		return toolInstance;
	}

	/**
	 * Transmits the term to the given socket channel, using the given buffer.
	 * 
	 * @param aTerm
	 *            The term to write.
	 * @param socketChannel
	 *            The channel to write to.
	 * @param byteBuffer
	 *            The buffer to use.
	 * @throws IOException
	 *             Thrown when something goes wrong while writing to the channel.
	 */
	private void writeTermToChannel(ATerm aTerm, SocketChannel socketChannel, ByteBuffer byteBuffer) throws IOException{
		BinaryWriter binaryWriter = new BinaryWriter(aTerm);
		while(!binaryWriter.isFinished()){
			byteBuffer.clear();
			byteBuffer.position(2);
			try{
				binaryWriter.serialize(byteBuffer);
			}catch(VisitFailure vf){
				// Bogus catch block, this can't happen.
			}
			// Insert chunk size data.
			int chunkSize = byteBuffer.limit() - 2;
			byteBuffer.put(0, (byte) (chunkSize & 0x000000FF));
			byteBuffer.put(1, (byte) ((chunkSize & 0x0000FF00) >> 8));
			
			// Write chunk
			socketChannel.write(byteBuffer);
		}
	}

	/**
	 * Reads a term from the given channel, using the given buffer.
	 * 
	 * @param factory
	 *            The factory to use for parsing the term.
	 * @param socketChannel
	 *            The channel to read from.
	 * @param byteBuffer
	 *            The buffer to use.
	 * @return The term that was read.
	 * @throws IOException
	 *             Thrown when something goes wrong while reading the term from the channel.
	 */
	private ATerm readTermFromChannel(PureFactory factory, SocketChannel socketChannel, ByteBuffer byteBuffer) throws IOException{
		BinaryReader binaryReader = new BinaryReader(factory);
		while(!binaryReader.isDone()){
			byteBuffer.clear();
			byteBuffer.limit(2);
			socketChannel.read(byteBuffer);
			byteBuffer.flip();
			
			int chunkSize = (byteBuffer.get(0) & 0x000000FF) + ((byteBuffer.get(1) & 0x000000FF) << 8);
			byteBuffer.clear();
			byteBuffer.limit(chunkSize);
			socketChannel.read(byteBuffer);
			byteBuffer.flip();
			
			binaryReader.deserialize(byteBuffer);
		}

		return binaryReader.getRoot();
	}

	/**
	 * @see AbstractConnectionHandler#closeConnection(SocketChannel)
	 */
	public void closeConnection(SocketChannel socketChannel){
		readMultiplexer.deregisterForRead(socketChannel);
		writeMultiplexer.deregisterForWrite(socketChannel);
		
		Socket socket = socketChannel.socket();
		LoggerFactory.log("Closing connection with: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ".", ILogger.INFO, IToolBusLoggerConstants.COMMUNICATION);

		// Close the in- output stream of the socket to ensure that the file descriptors are closed
		// immidiately and NOT whenever the JVM feels like it.
		try{
			if(!socket.isInputShutdown()) socket.shutdownInput();
		}catch(IOException ioex){
			// Ignore
		}
		try{
			if(!socket.isOutputShutdown()) socket.shutdownOutput();
		}catch(IOException ioex){
			// Ignore
		}

		try{
			if(!socket.isClosed()) socket.close();
		}catch(IOException ioex){
			LoggerFactory.log("Failed to close the socket with: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ".", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
		}
		
		try{
			if(socketChannel.isOpen()) socketChannel.close();
		}catch(IOException ioex){
			LoggerFactory.log("Failed to close the socket channel with: " + socket.getInetAddress().getHostName() + ":" + socket.getPort() + ".", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
		}
	}
}
