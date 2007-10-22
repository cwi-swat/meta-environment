package toolbus.communication;

import java.nio.channels.SelectableChannel;

/**
 * Implement this interface if you're a multiplexer that is able to select on write events.
 * 
 * @author Arnold Lankamp
 */
public interface IWriteMultiplexer{

	/**
	 * Registers the given channel for writing.
	 * 
	 * @param channel
	 *            The channel that needs to be registered for writing.
	 * @param ioHandler
	 *            The I/O handler that is associated with the given channel
	 */
	void registerForWrite(SelectableChannel channel, SocketIOHandler ioHandler);

	/**
	 * Deregisters the given channel for writing (if nessecary).
	 * 
	 * @param channel
	 *            The channel that needs to be deregistered for writing.
	 */
	void deregisterForWrite(SelectableChannel channel);
}
