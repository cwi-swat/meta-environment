package nl.cwi.bus.communication;

/**
 * Interface specificly for communication with the bus.
 * 
 * @author Arnold Lankamp
 */
public interface IBusDataHandler extends IDataHandler{
	
	/**
	 * Sets the iohandler through which communication with the bus is possible.
	 * @param ioHandler The ioHandler this bus data handler should use for communication with the bus.
	 */
	void setIOHandler(IIOHandler ioHandler);
}
