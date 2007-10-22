package toolbus.communication;

import java.nio.channels.SelectableChannel;

/**
 * Implement this interface if you're a multiplexer that is able to select on read events.
 * 
 * @author Arnold Lankamp
 */
public interface IReadMultiplexer{
	
	
	/**
	 * Registers the given channel for reading.
	 * 
	 * @param channel
	 *            The channel that needs to be registered for reading.
	 * @param ioHandler
	 *            The I/O handler that is associated with the given channel.
	 */
	void registerForRead(SelectableChannel channel, SocketIOHandler ioHandler);
	
	
	/**
	 * Deregisters the given channel for reading (if nessecary).
	 * 
	 * @param channel
	 *            The channel that needs to be deregistered for reading.
	 */
	void deregisterForRead(SelectableChannel channel);
}
