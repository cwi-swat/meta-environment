package nl.cwi.bus.variable;

import java.util.HashMap;
import java.util.Map;

import nl.cwi.bus.variable.Variable.VariableKey;
import nl.cwi.util.logging.Logger;

/**
 * A list with variables of which the data was requested.
 * 
 * @author Arnold Lankamp
 */
public class RequestedVariableHandler{
	private Map variables = null;

	/**
	 * Default constructor.
	 */
	public RequestedVariableHandler(){
		super();

		variables = new HashMap();
	}

	/**
	 * Adds a variable to this collection. If the variable is already present,
	 * nothing is done.
	 * 
	 * @param variable
	 *            The variable that needs to be added.
	 * @return The key the added variable is associated with.
	 */
	public synchronized VariableKey add(Variable variable){
		VariableKey variableKey = variable.createKey();
		Variable presentVariable = get(variableKey);

		if(presentVariable == null) variables.put(variableKey, variable);

		return variableKey;
	}

	/**
	 * Replaces a variable in this collection.
	 * 
	 * @param variable
	 *            The variable that will be put into the collection. If a
	 *            variable with the same id is currently present in the
	 *            collection it will be removed.
	 */
	public synchronized void replace(Variable variable){
		VariableKey variableKey = variable.createKey();

		Variable presentVariable = get(variableKey);
		if(presentVariable != null){
			remove(variableKey);
			add(variable);

			synchronized(presentVariable){
				presentVariable.notifyAll();
			}
		}
	}

	/**
	 * Retreives a variable from this collection.
	 * 
	 * @param variableKey
	 *            The identifier of the variable.
	 * @return The variable that needed to be retreived (null if there is no
	 *         variable with the given id present in this collection).
	 */
	public synchronized Variable get(VariableKey variableKey){
		VariableKey referenceKey = getKeyReference(variableKey);
		Variable variable = null;
		if(referenceKey != null) variable = (Variable) variables.get(referenceKey);

		return variable;
	}

	/**
	 * Removes the variable associated with the given identifier from the list.
	 * 
	 * @param variableKey
	 *            The variables identifier.
	 */
	public synchronized void remove(VariableKey variableKey){
		VariableKey referenceKey = getKeyReference(variableKey);
		if(referenceKey != null) variables.remove(referenceKey);
	}

	/**
	 * Returns the reference to the key that identifies what we're looking for
	 * in the map (if you understand what I mean).
	 * 
	 * @param variableKey
	 *            The identification of the thing we're looking for.
	 * @return The reference to the key we need.
	 */
	private VariableKey getKeyReference(VariableKey variableKey){
		VariableKey foundkey = null;

		Object[] keys = variables.keySet().toArray();
		for(int i = 0; i < keys.length; i++){
			VariableKey key = (VariableKey) keys[i];
			if(key.equals(variableKey)){
				foundkey = key;
				break;
			}
		}

		return foundkey;
	}

	/**
	 * This method will block the calling thread untill the variable which will
	 * be monitored is replaced in this collection.
	 * 
	 * @param variableKey
	 *            The identifier of the variable which will be monitored.
	 */
	public void waitForReplacement(VariableKey variableKey){
		Variable variable = get(variableKey);

		synchronized(variable){
			try{
				variable.wait();
			}catch(InterruptedException irex){
				Logger.getInstance().log("Was interrupted while monitoring a variable (waiting for a replace).", Logger.FATAL, irex);
			}
		}

	}
}
