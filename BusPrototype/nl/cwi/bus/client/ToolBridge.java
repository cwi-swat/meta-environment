package nl.cwi.bus.client;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;

import nl.cwi.bus.communication.IBusDataHandler;
import nl.cwi.bus.communication.IIOHandler;
import nl.cwi.bus.communication.operations.AbstractOperation;
import nl.cwi.bus.communication.operations.AckOperation;
import nl.cwi.bus.communication.operations.EndOperation;
import nl.cwi.bus.communication.operations.FinOperation;
import nl.cwi.bus.communication.operations.PutOperation;
import nl.cwi.bus.communication.operations.RegOperation;
import nl.cwi.bus.variable.Variable;
import nl.cwi.bus.variable.VariableConstantPool;
import nl.cwi.bus.variable.VariableHandler;
import nl.cwi.term.serializable.SerializableStringTerm;
import nl.cwi.util.logging.Logger;

/**
 * Bridge between the tool and the io part of the tool.
 * 
 * @author Arnold Lankamp
 */
public class ToolBridge extends Thread implements IBusDataHandler{
	private final Object waitLock = new Object();
	
	private ITool tool = null;

	private IIOHandler ioHandler = null;

	private long toolID = -1;

	/**
	 * Constructor.
	 * 
	 * @param tool
	 *            The tool that is using this toolbridge.
	 */
	public ToolBridge(ITool tool){
		super();

		this.tool = tool;

		ToolRegistery.getInstance().register(this);
	}

	/**
	 * Associates an iohandlerwith this toolbridge; through which can be
	 * communicated with the bus.
	 * 
	 * @see IBusDataHandler#setIOHandler(IIOHandler)
	 * @param ioHandler
	 *            The ioHandler this toolbridge should use for communication
	 *            with the bus.
	 */
	public void setIOHandler(IIOHandler ioHandler){
		this.ioHandler = ioHandler;
	}

	/**
	 * Returns the unique, by the bus assigned, id for this tool.
	 * 
	 * @return The id of this tool.
	 */
	public long getToolID(){
		return toolID;
	}

	/**
	 * Receives a request from the toolbus and handles it.
	 * 
	 * @param operation
	 *            The request to handle
	 */
	public void receive(AbstractOperation operation){
		String operationID = operation.getOperation().intern();

		if(operationID == AbstractOperation.PUT){
			PutOperation putOperation = (PutOperation) operation;
			Variable variable = putOperation.createVariable();

			// Check if it is present in the constant pool if not add it.
			VariableConstantPool variableConstantPool = ToolRegistery.getInstance().getVariableConstantPool();
			Variable constantVariable = variableConstantPool.add(variable);
			SerializableStringTerm term = constantVariable.getData();
			
			send(new AckOperation(putOperation.getTransactionID()));

			String type = term.getType();

			invokeMethod(type, term);
		}else if(operationID == AbstractOperation.FIN){
			FinOperation finOperation = (FinOperation) operation;
			long variableID = finOperation.getVariableID();
			
			VariableHandler variableHandler = ToolRegistery.getInstance().getVariableHandler();
			variableHandler.remove(variableID);
		}else if(operationID == AbstractOperation.REG){
			RegOperation regOperation = (RegOperation) operation;
			toolID = regOperation.getToolID();
		}
	}

	/**
	 * Invokes a method on the tool
	 * 
	 * @param name
	 *            The name of the method
	 * @param term
	 *            The argument of the method
	 */
	private void invokeMethod(String name, Object term){
		Method method = null;
		try{
			method = tool.getClass().getMethod(name, new Class[] {term.getClass()});
			
			method.invoke(tool, new Object[] {term});
		}catch(NoSuchMethodException nsmex){
			Logger.getInstance().log("Method with name: '"+name+"', doens't exist.", Logger.ERROR, nsmex);
		}catch(IllegalAccessException iaex){
			Logger.getInstance().log("Method with name: '"+name+"', doens't have public access", Logger.ERROR, iaex);
		}catch(InvocationTargetException itex){
			Logger.getInstance().log("Method with name: '"+name+"', caused an exception during execution.", Logger.ERROR, itex);
		}
	}

	/**
	 * Sends a operation to the toolbus. A message can be either be a 'return
	 * value' or an event
	 * 
	 * @param operation
	 *            The operation to send
	 */
	public void send(AbstractOperation operation){
		ioHandler.send(operation);
	}

	/**
	 * Starts running the bridge
	 */
	public void run(){
		try{
			// Prevent the application from terminating (just to be sure)
			synchronized(waitLock){
				waitLock.wait();
			}
		}catch(InterruptedException irex){
			Logger.getInstance().log("The ToolBridge received an unexpected interrupt, this might cause the tool to exit unexpectedly.", Logger.FATAL, irex);
		}
	}
	
	/**
	 * Stops this tool from running and notifies the bus
	 */
	public void stopRunning(){
		// Sends a terminiation message to the toolbus
		send(new EndOperation());

		// Notifies the lock this application is waiting on
		synchronized(waitLock){
			waitLock.notify();
		}

		ToolRegistery.getInstance().deregister(this);
	}

	/**
	 * I called when a termination message is received from the bus.
	 */
	public void terminate(){
		tool.terminate();
	}
}
