package toolbus.communication;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SocketChannel;

import jjtraveler.VisitFailure;
import toolbus.TBTermFactory;
import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.util.NativeTypeConverter;
import toolbus.util.collections.RotatingQueue;
import aterm.ATerm;
import aterm.pure.binary.BinaryReader;
import aterm.pure.binary.BinaryWriter;

/**
 * This class handles all communication with remote applications through sockets. It uses NIO /
 * asynchroneous I/O. It will use 64k of staticly allocated native memory for I/O buffers.
 * 
 * @author Arnold Lankamp
 */
public class SocketIOHandler implements IIOHandler{
	public final static byte END_OPC = 127;

	private final static byte OPERATIONBYTES = 1;
	private final static byte BLOCKLENGTHBYTES = 2;

	private final static int BUFFERSIZE = 32768;

	private final ByteBuffer operationReadBuffer;
	private final ByteBuffer lengthReadBuffer;
	private final ByteBuffer readBuffer;
	private final ByteBuffer lengthWriteBuffer;
	private final ByteBuffer writeBuffer;

	private final SocketChannel socketChannel;
	private final AbstractConnectionHandler connectionHandler;
	private final IDataHandler dataHandler;

	private boolean expectingDisconnect = false;

	private BinaryReader binaryReader = null;
	private byte operation = -1;
	private int blockLength = -1;

	private final RotatingQueue<OperationTermPair> writeQueue;

	private BinaryWriter binaryWriter = null;
	private boolean doneWithBlock = false;

	/**
	 * Constructor.
	 * 
	 * @param dataHandler
	 *            The data handler that is associated with this socket I/O handler.
	 * @param connectionHandler
	 *            The connection handler that created this socket I/O handler.
	 * @param socketChannel
	 *            The socket channel that will be used by this socket I/O handler.
	 */
	public SocketIOHandler(IDataHandler dataHandler, AbstractConnectionHandler connectionHandler, SocketChannel socketChannel){
		super();

		this.dataHandler = dataHandler;
		this.connectionHandler = connectionHandler;
		this.socketChannel = socketChannel;

		writeQueue = new RotatingQueue<OperationTermPair>();

		operationReadBuffer = ByteBuffer.allocateDirect(OPERATIONBYTES);
		lengthReadBuffer = ByteBuffer.allocateDirect(BLOCKLENGTHBYTES);
		readBuffer = ByteBuffer.allocateDirect(BUFFERSIZE);
		lengthWriteBuffer = ByteBuffer.allocateDirect(BLOCKLENGTHBYTES);
		writeBuffer = ByteBuffer.allocateDirect(BUFFERSIZE);
	}

	/**
	 * Adds the term to the list of terms that needs to be send. The terms will be send in the same
	 * order as they arrived at this method.
	 * 
	 * @see IIOHandler#send(byte, ATerm)
	 */
	public void send(byte op, ATerm aTerm){
/* TEMP */
//String term = aTerm.toString();
//if(((ToolInstance) dataHandler).getToolKey().getAFun().getName().toLowerCase().indexOf("debug") != -1) System.out.println("Send. Operation: "+op+", tool: "+((ToolInstance) dataHandler).getToolKey()+" Term: "+term);
//if(((ATermAppl) aTerm).getName().equals("asfc-progress")) System.out.println("Send. Operation: "+op+" Term: "+term);
//if(term.length() < 200) System.out.println("Send. Operation: "+op+" Term: "+term);
//else System.out.println("Send. Operation: "+op+" Term: BIG, name: "+((ATermAppl) aTerm).getName());
/* END TEMP */
		OperationTermPair otp = new OperationTermPair();
		otp.operation = op;
		otp.term = aTerm;
		synchronized(writeQueue){
			writeQueue.put(otp);
		}
		IWriteMultiplexer writeMultiplexer = connectionHandler.getWriteMultiplexer();
		writeMultiplexer.registerForWrite(socketChannel, this);
	}

	/**
	 * @see IIOHandler#receive(byte, ATerm)
	 */
	public void receive(byte op, ATerm aTerm){
/* TEMP */
//String term = aTerm.toString();
//if(((ToolInstance) dataHandler).getToolKey().getAFun().getName().toLowerCase().indexOf("debug") != -1) System.out.println("Receive. Operation: "+op+", tool: "+((ToolInstance) dataHandler).getToolKey()+" Term: "+term);
//if(aTerm instanceof ATermAppl && ((ATermAppl) aTerm).getName().equals("asfc-progress")) System.out.println("Recieved. Operation: "+op+" Term: "+term);
//if(term.length() < 200) System.out.println("Received. Operation: "+op+" Term: "+term);
//else System.out.println("Received. Operation: "+op+" Term: BIG, name: "+((ATermAppl) aTerm).getName());
/* END TEMP */
		dataHandler.receive(op, aTerm);
	}

	/**
	 * This method triggers the reading of data from the socket. Partial reads are possible, it will
	 * continue where it left off. IMPORTANT: Do not call this method concurrently; it will lead to
	 * undefined behaviour.
	 */
	protected void read(){
		boolean connected = true;

		if(operation == -1) connected = receiveOperation();
		if(connected && operation != -1 && blockLength == -1) connected = receiveBlockLength();
		if(connected && blockLength != -1) connected = receiveDataBlock();
		
		if(!connected){
			handleDisconnect();
		}else if(binaryReader.isDone()){
			ATerm term = binaryReader.getRoot();
			if(operation == END_OPC){
/* TEMP */
//System.out.println("Received END_OPC for: "+((ToolInstance) dataHandler).getToolKey());
/* END TEMP */
				shutDown();
				connectionHandler.closeConnection(socketChannel);
			}else{
				receive(operation, term);
			}

			binaryReader = null;
			operation = -1;
		}
	}

	/**
	 * Reads the operation byte from the socket channel.
	 * 
	 * @return False if we received a disconnect, true otherwise.
	 */
	private boolean receiveOperation(){
		boolean connected = readFromChannel(operationReadBuffer);

		if(!operationReadBuffer.hasRemaining() && connected){
			operationReadBuffer.flip();
			operation = operationReadBuffer.get();
			operationReadBuffer.clear();
		}

		// Initialize a new reader for this operation
		binaryReader = new BinaryReader(TBTermFactory.getInstance());

		return connected;
	}

	/**
	 * Reads the data block length from the socket channel (2 bytes, little endian encoded).
	 * 
	 * @return False if we received a disconnect, true otherwise.
	 */
	private boolean receiveBlockLength(){
		boolean connected = readFromChannel(lengthReadBuffer);

		if(!lengthReadBuffer.hasRemaining() && connected){
			lengthReadBuffer.flip();
			byte[] blockLengthBytes = new byte[lengthReadBuffer.limit()];
			lengthReadBuffer.get(blockLengthBytes);

			blockLength = NativeTypeConverter.makeUnsignedShort(blockLengthBytes);

			lengthReadBuffer.clear();

			readBuffer.clear();
			readBuffer.limit(blockLength);
		}

		return connected;
	}

	/**
	 * Reads the data from the current data block from the socket channel.
	 * 
	 * @return False if we received a disconnect, true otherwise.
	 */
	private boolean receiveDataBlock(){
		boolean connected = readFromChannel(readBuffer);

		if(!readBuffer.hasRemaining()){
			readBuffer.flip();

			binaryReader.deserialize(readBuffer);

			blockLength = -1;
		}

		return connected;
	}

	/**
	 * Reads bytes from the socket channel and inserts them into the given byte buffer.
	 * 
	 * @param buffer
	 *            The buffer to insert the received data into.
	 * @return False if we received a disconnect, true otherwise.
	 */
	private boolean readFromChannel(ByteBuffer buffer){
		boolean connected = true;
		try{
			int bytesRead = socketChannel.read(buffer);
			if(bytesRead == -1) connected = false;
		}catch(IOException ioex){
			LoggerFactory.log("An IOException occured while reading from a socket channel.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			connectionHandler.closeDueToException(socketChannel, this);
			throw new RuntimeException(ioex);
		}

		return connected;
	}

	/**
	 * This method triggers the writing of data from the socket. Partial writes are possible, it
	 * will continue where it left off. IMPORTANT: Do not call this method concurrently; it will
	 * lead to undefined behaviour.
	 */
	protected void write(){
		if(binaryWriter == null){
			OperationTermPair otp;
			synchronized(writeQueue){
				if(writeQueue.isEmpty()) return; // Nothing to write.
				otp = writeQueue.get();
			}
			sendOperation(otp.operation);

			binaryWriter = new BinaryWriter(otp.term);
			doneWithBlock = true;
		}

		if(doneWithBlock){
			try{
				writeBuffer.clear();
				binaryWriter.serialize(writeBuffer);
			}catch(VisitFailure vf){
				// Bogus catch block, this never happens.
			}
			sendBlockLength(writeBuffer.limit());
		}

		doneWithBlock = sendDataBlock();

		if(doneWithBlock && binaryWriter.isFinished()) binaryWriter = null;
	}

	/**
	 * Writes the operation byte to the stream.
	 * 
	 * @param op
	 *            The operation byte that indicates what the upcoming data package represents.
	 */
	private void sendOperation(byte op){
		writeBuffer.clear();
		writeBuffer.put(op);
		writeBuffer.flip();

		forcedWrite(writeBuffer);
	}

	/**
	 * Writes the block length to the socket channel.
	 * 
	 * @param length
	 *            The length of the block of data that will be written.
	 */
	private void sendBlockLength(int length){
		lengthWriteBuffer.clear();
		lengthWriteBuffer.put(NativeTypeConverter.makeBytesFromUnsignedShort(length));
		lengthWriteBuffer.flip();

		forcedWrite(lengthWriteBuffer);
	}

	/**
	 * Writes a block of data to the socket channel.
	 * 
	 * @return True if the entire block of data has been written to the socket channel, false
	 *         otherwise.
	 */
	private boolean sendDataBlock(){
		try{
			socketChannel.write(writeBuffer);
		}catch(IOException ioex){
			LoggerFactory.log("An error occured while writing the end of stream byte to a socket channel.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			connectionHandler.closeDueToException(socketChannel, this);
			throw new RuntimeException(ioex);
		}

		return !writeBuffer.hasRemaining();
	}

	/**
	 * Forces the writing of the content of the given buffer to the socket channel. Use this method
	 * for writing small amounts of data (no more then a few bytes) that need to be send in one
	 * piece.
	 * 
	 * @param buffer
	 *            The buffer to write to.
	 */
	private void forcedWrite(ByteBuffer buffer){
		while(buffer.hasRemaining()){
			try{
				socketChannel.write(buffer);
			}catch(IOException ioex){
				LoggerFactory.log("An error occured while writing to a socket channel.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
				connectionHandler.closeDueToException(socketChannel, this);
				throw new RuntimeException(ioex);
			}

			// Yield when needed.
			if(buffer.hasRemaining()) Thread.yield();
		}
	}

	/**
	 * Checks if there is data left that needs to be written.
	 * 
	 * @return True if there is data left that needs to be written; false otherwise.
	 */
	public boolean hasMoreToWrite(){
		boolean hasMoreToWrite = (binaryWriter != null);
		if(!hasMoreToWrite){
			synchronized(writeQueue){
				hasMoreToWrite = !writeQueue.isEmpty();
			}
		}

		return hasMoreToWrite;
	}

	/**
	 * Terminates the connection with the in this socket I/O handler contained socket channel in an
	 * orderly manner. All data that was queued for writing will be written to the socket before the
	 * end message will be send.
	 * 
	 * @see IIOHandler#terminate(ATerm)
	 */
	public void terminate(){
		OperationTermPair otp = new OperationTermPair();
		otp.operation = END_OPC;
		otp.term = TBTermFactory.getInstance().makeList();

		synchronized(writeQueue){
			writeQueue.put(otp);
		}

		IWriteMultiplexer writeMultiplexer = connectionHandler.getWriteMultiplexer();
		writeMultiplexer.registerForWrite(socketChannel, this);

		expectingDisconnect = true;
	}

	/**
	 * @see IIOHandler#shutDown()
	 */
	public void shutDown(){
		dataHandler.shutDown();
	}
	
	/**
	 * @see IIOHandler#exceptionOccured()
	 */
	public void exceptionOccured(){
		dataHandler.exceptionOccured();
	}

	/**
	 * Handles the received disconnect. The proper close method on the connection handler will be
	 * called depending on whether or not we anticipated the disconnect.
	 */
	private void handleDisconnect(){
/* TEMP */
//System.out.println("Disconnected: "+((ToolInstance) dataHandler).getToolKey()+", expected: "+expectingDisconnect);
/* END TEMP */
		if(expectingDisconnect) connectionHandler.closeConnection(socketChannel);
		else connectionHandler.closeDueToDisconnect(socketChannel, this);
	}

	/**
	 * A structure that links a term with an operation.
	 * 
	 * @author Arnold Lankamp
	 */
	protected static class OperationTermPair{
		public byte operation = -1;
		public ATerm term = null;
	}
}
