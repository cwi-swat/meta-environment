package toolbus.adapter;

import java.io.IOException;
import java.net.ConnectException;
import java.net.InetAddress;
import java.net.InetSocketAddress;
import java.net.Socket;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

import jjtraveler.VisitFailure;
import toolbus.communication.AbstractConnectionHandler;
import toolbus.communication.IReadMultiplexer;
import toolbus.communication.IWriteMultiplexer;
import toolbus.communication.SocketIOHandler;
import toolbus.communication.SocketReadWriteMultiplexer;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import aterm.ATerm;
import aterm.ATermInt;
import aterm.pure.PureFactory;
import aterm.pure.binary.BinaryReader;
import aterm.pure.binary.BinaryWriter;

/**
 * This class handles the opening and closing of the tool's connection with the ToolBus and provides
 * access to the multiplexers that are handling network I/O.
 * 
 * @author Arnold Lankamp
 */
public class ToolConnectionHandler extends AbstractConnectionHandler implements Runnable{
	private final static int HANDSHAKEBUFFERSIZE = 4096;

	private final SocketReadWriteMultiplexer socketReadWriteMultiplexer;

	/**
	 * Constructor.
	 * 
	 * @param toolBridge
	 *            The tool bridge that requested the starting of this tool connection.
	 * @param host
	 *            The adress where the ToolBus is running.
	 * @param port
	 *            The port the ToolBus is running on.
	 */
	public ToolConnectionHandler(ToolBridge toolBridge, InetAddress host, int port){
		super();

		SocketChannel socketChannel = null;
		try{
			socketChannel = SocketChannel.open();
			Socket socket = socketChannel.socket();
			// Disable Nagle's algorithm, we don't want the random 500ms delays.
			socket.setTcpNoDelay(true);
			// Set the traffic class to high throughput and low delay.
			socket.setTrafficClass(0x18);

			socketChannel.connect(new InetSocketAddress(host, port));
			socketChannel.configureBlocking(true);

			shakeHands(socketChannel, toolBridge);

			socketChannel.configureBlocking(false);
		}catch(ConnectException cex){
			LoggerFactory.log("Unable to connect with the ToolBus.", cex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(cex);
		}catch(IOException ioex){
			LoggerFactory.log("Unable to establish a connection with the ToolBus.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			closeConnection(socketChannel);
			throw new RuntimeException(ioex);
		}catch(RuntimeException rex){
			LoggerFactory.log("A runtime exception occured while trying to connect with the ToolBus.", rex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			closeConnection(socketChannel);
			throw new RuntimeException(rex);
		}

		socketReadWriteMultiplexer = new SocketReadWriteMultiplexer(this);
		SocketIOHandler socketIOHandler = new SocketIOHandler(toolBridge, this, socketChannel);
		toolBridge.setIOHandler(socketIOHandler);

		socketReadWriteMultiplexer.registerForRead(socketChannel, socketIOHandler);
	}

	/**
	 * Starts the multiplexer.
	 * 
	 * @see Runnable#run()
	 */
	public void run(){
		Thread multiplexerThread = new Thread(socketReadWriteMultiplexer);
		multiplexerThread.setName("Multiplexer");
		multiplexerThread.start();
	}

	/**
	 * @see AbstractConnectionHandler#getReadMultiplexer()
	 */
	public IReadMultiplexer getReadMultiplexer(){
		return socketReadWriteMultiplexer;
	}

	/**
	 * @see AbstractConnectionHandler#getWriteMultiplexer()
	 */
	public IWriteMultiplexer getWriteMultiplexer(){
		return socketReadWriteMultiplexer;
	}

	/**
	 * Negotiates with the ToolBus (about some stuff) and checks if the tool adheres to the expected
	 * interface.
	 * 
	 * @param socketChannel
	 *            The socket channel that we need to use to perform the handshake.
	 * @param toolBridge
	 *            The tool bridge that provides access to the tool.
	 * @throws IOException
	 *             Thrown when something goes wrong with the connection during the handshake.
	 */
	private void shakeHands(SocketChannel socketChannel, ToolBridge toolBridge) throws IOException{
		ByteBuffer handShakeBuffer = ByteBuffer.allocateDirect(HANDSHAKEBUFFERSIZE);

		PureFactory factory = toolBridge.getFactory();
		ATerm toolKey = factory.makeAppl(factory.makeAFun(toolBridge.getToolName(), 1, false), factory.makeInt(toolBridge.getToolID()));

		// Send the tool id.
		writeTermToChannel(toolKey, socketChannel, handShakeBuffer);

		// Receive signature.
		handShakeBuffer.clear();
		ATerm signatures = readTermFromChannel(factory, socketChannel, handShakeBuffer);

		// Check the signature.
		boolean sigOK = toolBridge.checkSignature(signatures);
		byte sigOKByte = 0;
		if(sigOK) sigOKByte = 1;

		// Send signature confirmation.
		handShakeBuffer.clear();
		handShakeBuffer.limit(1);
		handShakeBuffer.put(sigOKByte);
		handShakeBuffer.flip();
		socketChannel.write(handShakeBuffer);

		if(sigOKByte != 1){
			LoggerFactory.log("Signatures didn't match tool interface. Disconnecting ....", ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException("Signatures didn't match tool interface. Disconnecting ....");
		}

		// Receive the (permanent) tool key.
		ATerm newToolKey = readTermFromChannel(factory, socketChannel, handShakeBuffer);

		int toolID = ((ATermInt) newToolKey.getChildAt(0)).getInt();
		toolBridge.setToolID(toolID);
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
			byteBuffer.put(1, (byte) ((chunkSize >>> 8) & 0x000000FF));
			
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
		if(socketReadWriteMultiplexer != null) socketReadWriteMultiplexer.stopRunning();

		Socket socket = socketChannel.socket();
		
		// Close the socket
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
	}
}
