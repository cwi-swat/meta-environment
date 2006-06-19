package nl.cwi.bus.communication;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;

import nl.cwi.bus.communication.operations.AbstractOperation;
import nl.cwi.bus.config.Config;
import nl.cwi.util.BlockingThreadPool;
import nl.cwi.util.NativeTypeBuilder;
import nl.cwi.util.logging.Logger;

/**
 * Handles the sending and receiving of messages across a socket.
 * 
 * @see nl.cwi.bus.communication.IIOHandler
 * @author Arnold Lankamp
 */
public class SocketIOHandler implements IIOHandler{
	private final static int READBUFFERSIZE = 7500;
	private final static int WRITEBUFFERSIZE = 7500;
	
	private final static BlockingThreadPool writeThreadPool = new BlockingThreadPool(Config.getNrOfConcurrentThreads(), true);

	private final Object WRITELOCK = new Object();
	private final Object READLOCK = new Object();
	
	private Selector selector = null;
	private SocketChannel socketChannel = null;

	private IDataHandler dataHandler = null;

	private ByteBuffer lengthReadBuffer = null;
	private int messageLength = -1;
	private int bytesLeftToRead = -1;

	private ByteBuffer opReadBuffer = null;
	private String operationID = null;
	private AbstractOperation operationBeingReceived = null;

	private ByteBuffer dataReadBuffer = null;

	private ByteBuffer writeBuffer = null;

	// Will be set to true when we send an END message. This way we can
	// anticipate the incoming disconnect.
	private boolean expectingDisconnect = false;

	/**
	 * Constructor
	 * 
	 * @param selector
	 *            The selector the multiplexer is using
	 * @param socketChannel
	 *            The channel to read and write to/from
	 */
	public SocketIOHandler(Selector selector, SocketChannel socketChannel){
		super();

		this.selector = selector;
		this.socketChannel = socketChannel;

		// Allocate the buffers.
		// All large buffers that will be reused are allocated to be direct, for
		// improved efficiency.
		lengthReadBuffer = ByteBuffer.allocateDirect(AbstractOperation.LENGTHBYTES);
		opReadBuffer = ByteBuffer.allocateDirect(AbstractOperation.OPFIELDLENGTH);
		dataReadBuffer = ByteBuffer.allocateDirect(READBUFFERSIZE);

		writeBuffer = ByteBuffer.allocateDirect(WRITEBUFFERSIZE);
	}

	/**
	 * Sets the dataHandler that handles the incoming data. It must be set
	 * before data can be received
	 * 
	 * @param dataHandler
	 *            The dataHandler that handles the incoming data
	 */
	public void setDataHandler(IDataHandler dataHandler){
		this.dataHandler = dataHandler;
	}

	/**
	 * Receives a message from the tool and forwards it to the toolinstance
	 * 
	 * @see IIOHandler#receive(AbstractOperation)
	 * @param operation
	 *            The operation that was received
	 */
	public void receive(AbstractOperation operation){
		dataHandler.receive(operation);
	}

	/**
	 * Reads data from the channel and forwards it to the associated
	 * toolinstance.
	 * 
	 * @param key
	 *            The with the socketchannel associated key
	 */
	public void receive(SelectionKey key){
		synchronized(READLOCK){
			boolean connected = true;
			if(messageLength == -1){
				connected = readLength();
			}
			if(connected && operationID == null){
				connected = readOperation();
			}

			if(!connected){
				disconnected(key);
			}else{
				readData(key);
			}
		}
	}

	/**
	 * Reads the length.
	 * 
	 * @return False if we received a disconnect; true otherwise
	 */
	private boolean readLength(){
		boolean connected = true;

		while(lengthReadBuffer.hasRemaining() && connected){
			connected = read(lengthReadBuffer);
		}

		if(connected){
			lengthReadBuffer.flip();
			byte[] lengthBufferContent = new byte[lengthReadBuffer.limit()];
			lengthReadBuffer.get(lengthBufferContent);
			lengthReadBuffer.clear();

			messageLength = NativeTypeBuilder.makeInt(lengthBufferContent);
			bytesLeftToRead = messageLength;
		}

		return connected;
	}

	/**
	 * Reads the operation.
	 * 
	 * @return False if we received a disconnect; true otherwise.
	 */
	private boolean readOperation(){
		boolean connected = true;

		while(opReadBuffer.hasRemaining() && connected){
			connected = read(opReadBuffer);
		}

		if(connected){
			opReadBuffer.flip();
			byte[] opReadBufferContent = new byte[opReadBuffer.limit()];
			opReadBuffer.get(opReadBufferContent);
			opReadBuffer.clear();

			operationID = new String(opReadBufferContent).intern();
			operationBeingReceived = AbstractOperation.createEmptyOperation(operationID);
		}

		return connected;
	}

	/**
	 * Reads the data.
	 * 
	 * @param key
	 *            The with the socketchannel associated key
	 */
	private void readData(SelectionKey key){
		if(bytesLeftToRead < READBUFFERSIZE){
			dataReadBuffer.limit(bytesLeftToRead);
		}
		
		boolean connected = read(dataReadBuffer);

		dataReadBuffer.flip();
		byte[] data = new byte[dataReadBuffer.limit()];
		dataReadBuffer.get(data);
		dataReadBuffer.clear();
		
		bytesLeftToRead -= data.length;
		
		operationBeingReceived.put(data);

		// If disconnected, handle it.
		if(!connected){
			disconnected(key);
		}else if(bytesLeftToRead == 0){
			if(operationBeingReceived.getOperation() == AbstractOperation.END){
				terminate();
			}else{
				receive(operationBeingReceived);
			}

			// Reset everything
			messageLength = -1;
			operationID = null;
			operationBeingReceived = null;
		}
	}

	/**
	 * Reads from the socket channel and inserts the readed data into the given
	 * buffer.
	 * 
	 * @param buffer
	 *            The buffer to insert the readed data into.
	 * @return True if the socket is still connected; false if the connection
	 *         was closed.
	 */
	private boolean read(ByteBuffer buffer){
		boolean connected = true;
		try{
			int bytesRead = socketChannel.read(buffer);
			if(bytesRead == -1) connected = false;
		}catch(IOException ioex){
			Logger.getInstance().log("An IOException occured while reading from a socket channel.", Logger.ERROR, ioex);
			throw new RuntimeException(ioex);
		}

		return connected;
	}

	/**
	 * Handles disconnects.
	 * 
	 * @param key
	 *            The key associated with the socket connection / channel that
	 *            was closed.
	 */
	private void disconnected(SelectionKey key){
		// Check if the disconnect was expected.
		if(expectingDisconnect){
			Multiplexer.closeConnection(key);
		}else{
			Multiplexer.closeDueToDisconnect(key);
		}

		lengthReadBuffer.clear();
		dataReadBuffer.clear();
	}

	/**
	 * Sends a message to the associated tool.
	 * 
	 * @see IIOHandler#send(AbstractOperation)
	 * @param operation
	 *            The operation that will be send.
	 */
	public void send(AbstractOperation operation){
		addJob(new Job(operation));
	}

	/**
	 * Notifies the associated dataHandler it's are no longer required.
	 * 
	 * @see IIOHandler#terminate()
	 */
	public void terminate(){
		dataHandler.terminate();

		Multiplexer.closeConnection(socketChannel.keyFor(selector));
	}

	/**
	 * Returns the socketChannel this io handler is working on.
	 * 
	 * @return The socketChannel this io handler is working on.
	 */
	public SocketChannel getSocketChannel(){
		return socketChannel;
	}

	/**
	 * Adds a 'write job' to the pool for this channel. Also subscribes the
	 * channel for writing.
	 * 
	 * @param job
	 *            The job that should be added.
	 */
	private void addJob(Job job){
		writeThreadPool.addJob(job);
	}

	/**
	 * Returns the read lock for the channel.
	 * 
	 * @return The read lock for the channel.
	 */
	public Object getReadLock(){
		return READLOCK;
	}

	/**
	 * Represents a 'write job'.
	 * 
	 * @author lankamp
	 */
	public class Job implements Runnable{
		private AbstractOperation operation = null;

		/**
		 * Constructor.
		 * 
		 * @param operation
		 *            The operation to send.
		 */
		public Job(AbstractOperation operation){
			super();

			this.operation = operation;
		}

		/**
		 * Writes the data to the channel.
		 */
		public void run(){
			synchronized(WRITELOCK){
				// Write length
				int dataLength = operation.length();
				byte[] lengthBytes = NativeTypeBuilder.makeBytesFromInt(dataLength);
				ByteBuffer lengthWriteBuffer = ByteBuffer.wrap(lengthBytes);
	
				while(lengthWriteBuffer.hasRemaining()){
					try{
						socketChannel.write(lengthWriteBuffer);
					}catch(IOException ioex){
						Logger.getInstance().log("Writing length to the channel failed.", Logger.ERROR, ioex);
						throw new RuntimeException(ioex);
					}
				}
	
				// Write operation
				String operationIdentifier = operation.getOperation();
				byte[] operationIDBytes = operationIdentifier.getBytes();
				ByteBuffer opWriteBuffer = ByteBuffer.wrap(operationIDBytes);
	
				// If an end message is send, we can expect a disconnect
				if(operationIdentifier == AbstractOperation.END) expectingDisconnect = true;
	
				while(opWriteBuffer.hasRemaining()){
					try{
						socketChannel.write(opWriteBuffer);
					}catch(IOException ioex){
						Logger.getInstance().log("Writing operation to the channel failed.", Logger.ERROR, ioex);
						throw new RuntimeException(ioex);
					}
				}
	
				// Write data
				int offset = 0;
				// Don't stop writing till all bytes are send.
				while(offset < dataLength){
					int bytesToWrite = 0;
	
					int bytesLeft = dataLength - offset;
					if(bytesLeft < WRITEBUFFERSIZE){
						bytesToWrite = bytesLeft;
					}else{
						bytesToWrite = WRITEBUFFERSIZE;
					}
	
					writeBuffer.clear();
					byte[] data = operation.get(offset, bytesToWrite);
					writeBuffer.put(data, 0, data.length);
					writeBuffer.flip();
	
					// Write all the bytes in the buffer; depending on the space
					// left in the output buffer only a part (or even nothing) may
					// be written.
					while(writeBuffer.hasRemaining()){
						try{
							socketChannel.write(writeBuffer);
						}catch(IOException ioex){
							Logger.getInstance().log("Writing data to the channel failed.", Logger.ERROR, ioex);
							throw new RuntimeException(ioex);
						}
						Thread.yield(); 
					}
	
					offset += bytesToWrite;
				}
			}
		}
	}
}
