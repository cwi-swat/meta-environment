package nl.cwi.bus.communication;

import java.lang.reflect.Constructor;
import java.lang.reflect.InvocationTargetException;

import nl.cwi.util.InstanceOf;
import nl.cwi.util.logging.Logger;

/**
 * Factory for creating datahandlers of a specified type.
 * 
 * @author Arnold Lankamp
 */
public class ToolDataHandlerFactory{
	private Class dataHandlerType = null;

	/**
	 * Constructor.
	 * 
	 * @param dataHandlerType
	 *            The type of datahandler to construct. Must be an
	 *            implementation of IDataHandler.
	 */
	public ToolDataHandlerFactory(Class dataHandlerType){
		super();

		if(!InstanceOf.isImplementationOf(dataHandlerType, IToolDataHandler.class)) throw new IllegalArgumentException(dataHandlerType + " is not of type " + IToolDataHandler.class);

		this.dataHandlerType = dataHandlerType;
	}

	/**
	 * Creates a toolDataHandler.
	 * 
	 * @param ioHandler
	 *            The iohandler the toolDataHandler should use.
	 * @return The created toolDatahandler.
	 */
	public IDataHandler createToolDataHandler(IIOHandler ioHandler){
		IDataHandler dataHandler = null;

		try{
			Constructor c = dataHandlerType.getConstructor(new Class[] {IIOHandler.class});
			dataHandler = (IDataHandler) c.newInstance(new Object[] {ioHandler});
		}catch(NoSuchMethodException nsmex){
			Logger.getInstance().log("DataHandler didn't have a proper constructor", Logger.ERROR, nsmex);
		}catch(IllegalAccessException iaex){
			Logger.getInstance().log("The dataHandlers contructor isn't public", Logger.ERROR, iaex);
		}catch(InstantiationException iex){
			Logger.getInstance().log("The dataHandler is abstract and can't be instantiated", Logger.ERROR, iex);
		}catch(InvocationTargetException itex){
			Logger.getInstance().log("The constructor of the dataHandler throw and exception", Logger.ERROR, itex);
		}

		return dataHandler;
	}
}
