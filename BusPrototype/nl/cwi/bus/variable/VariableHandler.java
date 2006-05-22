package nl.cwi.bus.variable;

import java.util.HashMap;
import java.util.Map;


/**
 * Container for all reachable variables on 'this' tool. Follows singleton
 * design pattern.
 * 
 * @author Arnold Lankamp
 */
public class VariableHandler{
	private Map variables = null;

	/**
	 * Default constructor.
	 */
	public VariableHandler(){
		super();

		variables = new HashMap();
	}
	/**
	 * Adds a variable to this collection.
	 * 
	 * @param variable
	 *            The variable that needs to be added.
	 */
	public synchronized void add(Variable variable){
		long variableID = variable.getVariableID();
		Variable presentVariable = get(variableID);

		if(presentVariable == null) variables.put(new Long(variableID), variable);
	}

	/**
	 * Retreives a variable from this collection.
	 * 
	 * @param variableID
	 *            The identifier of the variable.
	 * @return The variable that needed to be retreived (null if there is no
	 *         variable with the given id present in this collection).
	 */
	public synchronized Variable get(long variableID){
		Long referenceKey = getKeyReference(variableID);
		Variable variable = null;
		if(referenceKey != null) variable = (Variable) variables.get(referenceKey);
		
		return variable;
	}

	/**
	 * Removes the variable associated with the given identifier from the list.
	 * 
	 * @param variableID
	 *            The variable's identifier.
	 */
	public synchronized void remove(long variableID){
		Long referenceKey = getKeyReference(variableID);
		
		if(referenceKey != null) variables.remove(referenceKey);
	}
	
	/**
	 * Returns the reference to the key that identifies what we're looking for
	 * in the map (if you understand what I mean).
	 * 
	 * @param variableID
	 *            The identification of the thing we're looking for.
	 * @return The reference to the key we need.
	 */
	private Long getKeyReference(long variableID){
		Long foundkey = null;

		Object[] keys = variables.keySet().toArray();
		for(int i = 0; i < keys.length; i++){
			Long key = (Long)keys[i];
			if(key.longValue() == variableID){
				foundkey = key;
				break;
			}
		}

		return foundkey;
	}
}
