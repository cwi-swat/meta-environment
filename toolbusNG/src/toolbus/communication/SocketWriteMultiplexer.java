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

/**
 * This class handles the multiplexing of socket channels that we are registered for write
 * operations.
 * 
 * @author Arnold Lankamp
 */
public class SocketWriteMultiplexer implements IWriteMultiplexer, Runnable{
	private final Object selectPreventionLock = new Object();
	
	private final AbstractConnectionHandler connectionHandler;
	private final Selector selector;
	private volatile boolean running = false;

	/**
	 * Constructor.
	 * 
	 * @param connectionHandler
	 *            The connection handler this write multiplexer was created by.
	 */
	public SocketWriteMultiplexer(AbstractConnectionHandler connectionHandler){
		super();

		this.connectionHandler = connectionHandler;

		try{
			selector = Selector.open();
		}catch(IOException ioex){
			LoggerFactory.log("Unable to create a selector for the write multiplexer.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
			throw new RuntimeException(ioex);
		}
		
		running = true; // This is placed here, instead of at the start of the run loop because of a potential concurrency problem.
	}

	/**
	 * Checks if this multiplexer is running or not.
	 * 
	 * @return True if this handler is running, false otherwise.
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
		// Let the selector return immidiately
		selector.wakeup();
	}

	/**
	 * The main loop of this multiplexer. It blocks until there is a registered channel which we are
	 * able to write to.
	 */
	public void run(){
		while(running){
			try{
				selector.select(); // <-- Wait till we got stuff to do or get woken up.
			}catch(IOException ioex){
				LoggerFactory.log("An exception occured during the select call in the write multiplexer.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			}

			synchronized(selectPreventionLock){
				// This barrier is for preventing this thread from obtaining the monitor we need for
				// registering a channel. The select() call obtains several monitors and then
				// blocks. Effectively this causes just about every method of the selector (and
				// associated objects) to block indefinately when the select() call is in progress!
				// Thanks Sun for this (incredibly) crappy design / implementation. Long live the
				// community projects ... yeah NOT!
			}
			
			try{
				selector.selectNow(); // <-- Checks if we have stuff to do and clears the wakeup if needed.
			}catch(IOException ioex){
				LoggerFactory.log("An exception occured during the select call in the write multiplexer.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
			}
			
			Set<SelectionKey> readyKeys = selector.selectedKeys();
			Iterator<SelectionKey> iterator = readyKeys.iterator();
			while(iterator.hasNext()){
				SelectionKey key = iterator.next();
				iterator.remove();

				if(key.isWritable()){
					try{
						write(key);
					}catch(RuntimeException rex){
						// Catch all RuntimeExceptions. We don't want to risk the termination of
						// this thread.
						LoggerFactory.log("A runtime exception occured during the execution of the write multiplexer; killing associated connection.", rex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
						connectionHandler.closeDueToException((SocketChannel) key.channel(), (SocketIOHandler) key.attachment());
					}
				}
			}
		}

		// Close the selector once this thread stops running.
		try{
			selector.close();
		}catch(IOException ioex){
			LoggerFactory.log("Unable to close the selector of the write multiplexer.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
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
		SocketIOHandler ioHandler = (SocketIOHandler) key.attachment();

		ioHandler.write();

		// If there is not more data that needs to be written or the channel has been closed in the
		// mean time, de-register it.
		synchronized(selectPreventionLock){
			if(!ioHandler.hasMoreToWrite() || !channel.isOpen()) deregisterForWrite(channel);
		}
	}

	/**
	 * @see IWriteMultiplexer#registerForWrite(SelectableChannel, SocketIOHandler)
	 */
	public void registerForWrite(SelectableChannel channel, SocketIOHandler ioHandler){
		synchronized(selectPreventionLock){
			selector.wakeup();
			try{
				SelectionKey key = channel.keyFor(selector);
				if(key == null){
					channel.register(selector, SelectionKey.OP_WRITE, ioHandler);
				}else{
					key.interestOps(SelectionKey.OP_WRITE);
					key.attach(ioHandler);
				}
			}catch(IOException ioex){
				LoggerFactory.log("Registering a channel for writing failed", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);

				connectionHandler.closeDueToException((SocketChannel) channel, ioHandler);
			}
		}
	}

	/**
	 * @see IWriteMultiplexer#deregisterForWrite(SelectableChannel)
	 */
	public void deregisterForWrite(SelectableChannel channel){
		synchronized(selectPreventionLock){
			selector.wakeup();

			SelectionKey key = channel.keyFor(selector);

			if(key != null){
				if(key.isValid()) key.interestOps(0);
				else key.cancel();

				// Remove the attachment (if any), so it can be GCed
				key.attach(null);
			}
		}
	}
}
