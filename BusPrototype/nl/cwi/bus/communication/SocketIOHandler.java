package nl.cwi.bus.communication;

import java.io.IOException;
import java.nio.ByteBuffer;
import java.nio.channels.ClosedChannelException;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.util.ArrayList;
import java.util.List;

import nl.cwi.bus.communication.operations.AbstractOperation;
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

	private final Object READLOCK = new Object();
	private final Object WRITELOCK = new Object();

	private Selector selector = null;
	private Object selectionPreventionLock = null;
	private SocketChannel socketChannel = null;

	private List jobs = null;

	private IDataHandler dataHandler = null;

	private ByteBuffer lengthReadBuffer = null;
	private int messageLength = -1;
	private int bytesLeftToRead = -1;

	private ByteBuffer opReadBuffer = null;
	private String operationID = null;
	private AbstractOperation operationBeingReceived = null;

	private ByteBuffer dataReadBuffer = null;
	private ByteBuffer leftOverDataReadBuffer = null;

	private ByteBuffer writeBuffer = null;

	// Will be set to true when we send an END message. This way we can
	// anticipate the incoming disconnect.
	private boolean expectingDisconnect = false;

	/**
	 * Constructor
	 * 
	 * @param selectorCreator
	 *            contains the selector the multiplexer is using
	 * @param socketChannel
	 *            The channel to read and write to/from
	 */
	public SocketIOHandler(SelectorCreator selectorCreator, SocketChannel socketChannel){
		super();

		this.selector = selectorCreator.getSelector();
		this.selectionPreventionLock = selectorCreator.getSelectionPreventionLock();
		this.socketChannel = socketChannel;

		jobs = new ArrayList();

		// Allocate the buffers.
		// All large buffers that will be reused are allocated to be direct, for
		// improved efficiency.
		lengthReadBuffer = ByteBuffer.allocate(AbstractOperation.LENGTHBYTES);
		opReadBuffer = ByteBuffer.allocate(AbstractOperation.OPFIELDLENGTH);
		dataReadBuffer = ByteBuffer.allocateDirect(READBUFFERSIZE);
		leftOverDataReadBuffer = null;

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
		// Temp
		// System.out.println("REC " + operation.getOperation());
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
			byte[] lengthBufferContent = lengthReadBuffer.array();

			messageLength = NativeTypeBuilder.makeInt(lengthBufferContent);

			// Resize the data buffer is nessacary.
			if(dataReadBuffer.capacity() != messageLength) dataReadBuffer = ByteBuffer.allocate(messageLength);

			lengthReadBuffer.clear();

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
			byte[] opReadBufferContent = opReadBuffer.array();

			operationID = new String(opReadBufferContent).intern();
			operationBeingReceived = AbstractOperation.createEmptyOperation(operationID);

			opReadBuffer.clear();
		}
		// Temp
		// System.out.println("REC OP: " + operationID);

		return connected;
	}

	/**
	 * Reads the data.
	 * 
	 * @param key
	 *            The with the socketchannel associated key
	 */
	private void readData(SelectionKey key){
		// NOTE: This method contains some duplicate code, but who cares.
		boolean connected = false;
		if(messageLength < READBUFFERSIZE){
			leftOverDataReadBuffer = ByteBuffer.allocate(messageLength);

			connected = read(leftOverDataReadBuffer);

			leftOverDataReadBuffer.flip();
			byte[] data = new byte[leftOverDataReadBuffer.limit()];
			leftOverDataReadBuffer.get(data);
			operationBeingReceived.put(data);

			bytesLeftToRead -= data.length;

			leftOverDataReadBuffer = null;
		}else{
			connected = read(dataReadBuffer);

			dataReadBuffer.flip();
			byte[] data = new byte[dataReadBuffer.limit()];
			dataReadBuffer.get(data);
			operationBeingReceived.put(data);

			bytesLeftToRead -= data.length;

			dataReadBuffer.clear();
		}

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
		}

		return connected;
	}

	/**
	 * Writes the queued messages to the channel.
	 * 
	 * @throws ClosedChannelException
	 *             Thrown when the channel is closed while writing to it.
	 */
	public void write() throws ClosedChannelException{
		synchronized(WRITELOCK){
			// Start at the back of the list because we're also removing stuff,
			// otherwise we might skip something.
			for(int i = jobs.size() - 1; i >= 0; i--){
				Job job = (Job) jobs.get(i);
				jobs.remove(i);

				job.run();
			}

			socketChannel.register(selector, SelectionKey.OP_READ, this);
		}
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
		// Temp
		// System.out.println("SND " + operation.getOperation());
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
		synchronized(WRITELOCK){
			jobs.add(job);

			synchronized(selectionPreventionLock){
				selector.wakeup();
				synchronized(selector){
					try{
						// Register for writing
						socketChannel.register(selector, SelectionKey.OP_READ | SelectionKey.OP_WRITE, this);
					}catch(ClosedChannelException ccex){
						Logger.getInstance().log("Failed to register for writing (the channel was closed).", Logger.ERROR, ccex);
					}
				}
			}
		}
	}

	/**
	 * Removes a job from the pool.
	 * 
	 * @param job
	 *            The job to remove.
	 */
	public void removeJob(Job job){
		synchronized(WRITELOCK){
			jobs.remove(job);
		}
	}

	/**
	 * Returns the write lock for the channel.
	 * 
	 * @return The write lock for the channel.
	 */
	public Object getWriteLock(){
		return WRITELOCK;
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
			// Write length
			int dataLength = operation.length();
			byte[] lengthBytes = NativeTypeBuilder.makeBytesFromInt(dataLength);
			ByteBuffer lengthWriteBuffer = ByteBuffer.wrap(lengthBytes);

			try{
				socketChannel.write(lengthWriteBuffer);
			}catch(IOException ioex){
				Logger.getInstance().log("Writing length to the channel failed.", Logger.ERROR, ioex);
			}

			// Write operation
			String operationIdentifier = operation.getOperation();
			byte[] operationIDBytes = operationIdentifier.getBytes();
			ByteBuffer opWriteBuffer = ByteBuffer.wrap(operationIDBytes);

			// If an end message is send, we can expect a disconnect
			if(operationIdentifier == AbstractOperation.END) expectingDisconnect = true;

			try{
				socketChannel.write(opWriteBuffer);
			}catch(IOException ioex){
				Logger.getInstance().log("Writing operation to the channel failed.", Logger.ERROR, ioex);
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
					}
				}

				offset += bytesToWrite;

				Thread.yield();
			}
			// Temp
			// System.out.println("SND done with OP: " +
			// operation.getOperation());
		}
	}
}
