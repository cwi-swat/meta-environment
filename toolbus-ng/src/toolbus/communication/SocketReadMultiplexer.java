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
 * This class handles the multiplexing of socket channels that we are registered for read
 * operations.
 * 
 * @author Arnold Lankamp
 */
public class SocketReadMultiplexer implements IReadMultiplexer, Runnable{
	private final Latch selectionPreventionLatch = new Latch();
	
	private final AbstractConnectionHandler connectionHandler;
	
	private final Selector selector;
	private volatile boolean running = false;

	/**
	 * Constructor.
	 * 
	 * @param connectionHandler
	 *            The connection handler this read multiplexer was created by.
	 */
	public SocketReadMultiplexer(AbstractConnectionHandler connectionHandler){
		super();

		this.connectionHandler = connectionHandler;

		try{
			selector = Selector.open();
		}catch(IOException ioex){
			LoggerFactory.log("Unable to create a selector for the read multiplexer.", ioex, ILogger.FATAL, IToolBusLoggerConstants.COMMUNICATION);
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
	 * able to read from.
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
			LoggerFactory.log("Unable to close the selector of the read multiplexer.", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
		}
	}

	/**
	 * Notifies the with the selection key associated I/O handler that we are able to receive data.
	 * 
	 * @param key
	 *            The key associated with the channel that we can read from.
	 */
	private void read(SelectionKey key){
		SocketIOHandler ioHandler = (SocketIOHandler) key.attachment();
		ioHandler.read();
	}

	/**
	 * @see IReadMultiplexer#registerForRead(SelectableChannel, SocketIOHandler)
	 */
	public void registerForRead(SelectableChannel channel, SocketIOHandler ioHandler){
		selectionPreventionLatch.acquire();
		
		try{
			selector.wakeup();
	
			try{
				SelectionKey key = channel.keyFor(selector);
				if(key == null){
					channel.register(selector, SelectionKey.OP_READ, ioHandler);
				}else{
					synchronized(key){
						key.interestOps(SelectionKey.OP_READ);
						key.attach(ioHandler);
					}
				}
			}catch(IOException ioex){
				LoggerFactory.log("Registering a channel for reading failed", ioex, ILogger.ERROR, IToolBusLoggerConstants.COMMUNICATION);
	
				connectionHandler.closeDueToException((SocketChannel) channel, ioHandler);
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
	
			SelectionKey key = channel.keyFor(selector);
	
			if(key != null){
				synchronized(key){
					if(key.isValid()) key.interestOps(0);
					else key.cancel();
		
					// Remove the attachment (if any), so it can be GCed
					key.attach(null);
				}
			}
		}finally{
			selectionPreventionLatch.release();
		}
	}
}
