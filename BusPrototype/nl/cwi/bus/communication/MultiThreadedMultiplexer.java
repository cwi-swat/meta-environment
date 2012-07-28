package nl.cwi.bus.communication;

import java.io.IOException;
import java.nio.channels.SelectionKey;
import java.util.Iterator;
import java.util.Set;

import nl.cwi.bus.config.Config;
import nl.cwi.util.BlockingThreadPool;
import nl.cwi.util.logging.Logger;

/**
 * Multithreaded version of the multiplexer
 * 
 * @author Arnold Lankamp
 */
public class MultiThreadedMultiplexer extends Multiplexer{
	private BlockingThreadPool threadPool = null;

	private SelectorCreator selectorCreator = null;

	/**
	 * Constructor.
	 * 
	 * @param selectorCreator
	 *            The selectorCreator that contains the selector is used for
	 *            activity notifications.
	 * @param mode
	 *            The 'mode' this multiplexer is running in (server/client mode,
	 *            servers are also capable of accepting incoming connections).
	 * @param toolDataHandlerFactory
	 *            A factory for creating tooldataHandlers (only needed when
	 *            running in server mode).
	 */
	public MultiThreadedMultiplexer(SelectorCreator selectorCreator, byte mode, ToolDataHandlerFactory toolDataHandlerFactory){
		super(selectorCreator, mode, toolDataHandlerFactory);

		threadPool = new BlockingThreadPool(Config.getNrOfConcurrentThreads(), true);

		this.selectorCreator = selectorCreator;
	}

	/**
	 * The main loop of this multiplexer. It waits for something to happen, then
	 * notifies the associated ioHandler
	 */
	public void run(){
		setRunning(true);

		while(isRunning()){
			try{
				getSelector().select();
			}catch(IOException ioex){
				Logger.getInstance().log("An exception occured during the exection of the multiplexer (select())", Logger.ERROR, ioex);
			}

			Set readyKeys = getSelector().selectedKeys();
			Iterator iterator = readyKeys.iterator();
			while(iterator.hasNext()){
				final SelectionKey key = (SelectionKey) iterator.next();
				iterator.remove();

				// Acception a connection is a relatively fast operation, so there is no need to do this concurrently.
				if(getMode() == SERVERMODE && key.isAcceptable()){
					try{
						accept(key);
					}catch(IOException ioex){
						Logger.getInstance().log("An exception occured during the exection of the multiplexer (read()). The connection on which the exception occurred will be closed.", Logger.ERROR, ioex);

						closeDueToDisconnect(key);
					}
				}
				if(key.isReadable()){
					register(key.channel(), 0, key.attachment());
					
					threadPool.addJob(new Runnable(){
						public void run(){
							read(key);
							
							// Only re-register when the key is still valid (not cancelled).
							if(key.isValid()) register(key.channel(), SelectionKey.OP_READ, key.attachment());
						}
					});
				}
			}

			synchronized(selectorCreator.getSelectionPreventionLock()){
				// This is just a barrier, hopefully the compiler doesn't remove
				// this empty block.
				// If it does we have a problem, since we have no way of
				// preventing the select() call from obtaining the lock we need
				// for registering a channel.
				// If the design for the selector wasn't so severly broken we
				// wouldn't need this crap.
			}
		}
	}
}
