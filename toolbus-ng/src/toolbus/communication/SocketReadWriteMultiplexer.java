package toolbus.communication;

import java.io.IOException;
import java.nio.channels.SelectableChannel;
import java.nio.channels.SelectionKey;
import java.nio.channels.Selector;
import java.nio.channels.SocketChannel;
import java.util.Iterator;
import java.util.Set;

import toolbus.logging.ILogger;
import toolbus.logging.IToolBusLoggerConstants;
import toolbus.logging.LoggerFactory;
import toolbus.util.concurrency.Latch;

/**
 * This class handles the multiplexing of socket channels that we are registered for either read or
 * write operations.
 * 
 * @author Arnold Lankamp
 */
public class SocketReadWriteMultiplexer implements IReadMultiplexer, IWriteMultiplexer, Runnable{
	private final Latch selectionPreventionLatch = new Latch();
	private final Object registrationLock = new Object();
	
	private final AbstractConnectionHandler connectionHandler;
	
	private final Selector selector;
	private volatile boolean running = false;

	/**
	 * Constructor.
	 * 
	 * @param connectionHandler
	 *            The connection handler this multiplexer was created by.
	 */
	public SocketReadWriteMultiplexer(AbstractConnectionHandler connectionHandler){
		super();

		this.connectionHandler = connectionHandler;

		try{
			selector = Selector.open();
		}catch(IOException ioex){
			LoggerFactory.log("Unable to create a selector for the read / write multiplexer.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(ioex);
		}
		
		running = true; // This is placed here, instead of at the start of the run loop because of a potential concurrency problem.
	}

	/**
	 * Checks if this multiplexer is running or not.
	 * 
	 * @return True if this multiplexer is running, false otherwise.
	 */
	public boolean isRunning(){
		return running;
	}

	/**
	 * Stops the execution of this multiplexer after then next iteration. The running state will be
	 * set to false and the selector will be forced to return directly.
	 */
	public void stopRunning(){
		running = false;
	}

	/**
	 * The main loop of this multiplexer. It blocks until there is a registered channel which we are
	 * able to read or write from.
	 */
	public void run(){
		while(running){
			boolean ready = false;
			while(!ready){
				try{
					// This barrier is for preventing this thread from obtaining the monitor we need for
					// registering a channel. The select() call obtains several monitors and then
					// blocks. Effectively this causes just about every method of the selector (and
					// associated objects) to block indefinately when the select() call is in progress!
					// Thanks Sun for this (incredibly) crappy design / implementation. Long live the
					// community projects ... yeah NOT!
					selectionPreventionLatch.await();
					ready = true;
				}catch(InterruptedException irex){
					// Ignore
				}
			}
			
			try{
				selector.select(); // Wait till we got stuff to do or get woken up.
			}catch(IOException ioex){
				LoggerFactory.log("An exception occured during the select call in the read multiplexer.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			}

			Set<SelectionKey> readyKeys = selector.selectedKeys();
			Iterator<SelectionKey> iterator = readyKeys.iterator();
			while(iterator.hasNext()){
				SelectionKey key = iterator.next();
				iterator.remove();

				try{
					if(key.isReadable()){
						read(key);
					}
					if(key.isValid() && key.isWritable()){
						write(key);
					}
				}catch(RuntimeException rex){
					// Catch all RuntimeExceptions. We don't want to risk the termination of this thread.
					LoggerFactory.log("A runtime exception occured during the execution of the read multiplexer; killing associated connection.", rex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
					connectionHandler.closeDueToException((SocketChannel) key.channel(), (SocketIOHandler) key.attachment());
				}
			}
		}

		// Close the selector once this thread stops running.
		try{
			selector.close();
		}catch(IOException ioex){
			LoggerFactory.log("Unable to close the selector of the read / write multiplexer.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		}
	}

	/**
	 * Notifies the with the selection key associated I/O handler that we are able to receive data.
	 * 
	 * @param key
	 *            The key associated with the channel that we can read from.
	 */
	private void read(SelectionKey key){
		SelectableChannel channel = key.channel();
		
		synchronized(channel){
			SocketIOHandler ioHandler = (SocketIOHandler) key.attachment();
			ioHandler.read();
		}
	}

	/**
	 * Notifies the with the selection key associated I/O handler that we are able to send data.
	 * 
	 * @param key
	 *            The key associated with the channel that we can write to.
	 */
	private void write(SelectionKey key){
		SelectableChannel channel = key.channel();
		
		synchronized(registrationLock){
			SocketIOHandler ioHandler = (SocketIOHandler) key.attachment();
	
			ioHandler.write();
	
			// If there is not more data that needs to be written or the channel has been closed in the
			// mean time, de-register it.
			if(!ioHandler.hasMoreToWrite() || !channel.isOpen()) deregisterForWrite(channel);
		}
	}

	/**
	 * @see IReadMultiplexer#registerForRead(SelectableChannel, SocketIOHandler)
	 */
	public void registerForRead(SelectableChannel channel, SocketIOHandler ioHandler){
		selectionPreventionLatch.acquire();
		
		try{
			selector.wakeup();

			synchronized(registrationLock){
				try{
					SelectionKey key = channel.keyFor(selector);
					int interestOps = SelectionKey.OP_READ;
					if(key != null) interestOps |= key.interestOps();
					channel.register(selector, interestOps, ioHandler);
				}catch(IOException ioex){
					LoggerFactory.log("Registering a channel for reading failed", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		
					connectionHandler.closeDueToException((SocketChannel) channel, ioHandler);
				}
			}
		}finally{
			selectionPreventionLatch.release();
		}
	}

	/**
	 * @see IReadMultiplexer#deregisterForRead(SelectableChannel)
	 */
	public void deregisterForRead(SelectableChannel channel){
		selectionPreventionLatch.acquire();
		
		try{
			selector.wakeup();
			
			synchronized(registrationLock){
				SelectionKey key = channel.keyFor(selector);
				if(key != null){
					if(key.isValid()){
						key.interestOps(key.interestOps() & (~SelectionKey.OP_READ));
		
						// Remove the attachment (if any), so it can be GCed
						if(key.interestOps() == 0) key.attach(null);
					}else{
						key.cancel();
						key.attach(null);
					}
				}
			}
		}finally{
			selectionPreventionLatch.release();
		}
	}

	/**
	 * @see IWriteMultiplexer#registerForWrite(SelectableChannel, SocketIOHandler)
	 */
	public void registerForWrite(SelectableChannel channel, SocketIOHandler ioHandler){
		selectionPreventionLatch.acquire();
		
		try{
			selector.wakeup();
			
			synchronized(registrationLock){
				try{
					SelectionKey key = channel.keyFor(selector);
					int interestOps = SelectionKey.OP_WRITE;
					if(key != null) interestOps |= key.interestOps();
					channel.register(selector, interestOps, ioHandler);
				}catch(IOException ioex){
					LoggerFactory.log("Registering a channel for writing failed", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		
					connectionHandler.closeDueToException((SocketChannel) channel, ioHandler);
				}
			}
		}finally{
			selectionPreventionLatch.release();
		}
	}

	/**
	 * @see IWriteMultiplexer#deregisterForWrite(SelectableChannel)
	 */
	public void deregisterForWrite(SelectableChannel channel){
		selectionPreventionLatch.acquire();
		
		try{
			selector.wakeup();
			
			synchronized(registrationLock){
				SelectionKey key = channel.keyFor(selector);
				if(key != null){
					if(key.isValid()){
						key.interestOps(key.interestOps() & (~SelectionKey.OP_WRITE));
		
						// Remove the attachment (if any), so it can be GCed
						if(key.interestOps() == 0) key.attach(null);
					}else{
						key.cancel();
						key.attach(null);
					}
				}
			}
		}finally{
			selectionPreventionLatch.release();
		}
	}
}
