package nl.cwi.bus.variable;

import java.lang.ref.Reference;
import java.lang.ref.SoftReference;
import java.lang.ref.WeakReference;
import java.util.HashMap;
import java.util.Map;

import nl.cwi.bus.client.ToolRegistery;
import nl.cwi.bus.variable.Variable.VariableKey;

/**
 * Constant pool containing variables. This pool uses soft/weak references for
 * it's values; so no worries about oom problems.
 * 
 * @author Arnold Lankamp
 */
public class VariableConstantPool{
	/**
	 * Soft references will be collected at the GCs discretion (when memory runs
	 * low or when not accessed for a certain period of time).
	 */
	public final static int SOFT = 3;
	/**
	 * Weak references will be collected at the next GC cycle (under the
	 * condition that they are no longer strongly referenced ofcourse). This is
	 * the default.
	 */
	public final static int WEAK = 2;
	
	private int strength = WEAK;

	private Map variables = null;
	
	/**
	 * Default constructor.
	 */
	public VariableConstantPool(){
		super();

		variables = new HashMap();
	}

	/**
	 * Constructor.
	 * Allows you to specify a custom strength for the references in this pool.
	 * 
	 * @param strength
	 *            Defines the strength of the references that will be used to
	 *            store data in this constant pool.
	 */
	public VariableConstantPool(int strength){
		super();

		this.strength = strength;

		variables = new HashMap();
	}

	/**
	 * Adds a variable to this collection. If the variable is already present or
	 * accessable by this pool, nothing is done. A reference to the, through the
	 * constant pool accessable variable, is returned.
	 * 
	 * @param variable
	 *            The variable that needs to be added.
	 * @return The reference to through the in the constant pool reachable
	 *         variable.
	 */
	public synchronized Variable add(Variable variable){
		VariableKey variableKey = variable.createKey();

		// Check if it is present in this pool.
		Variable presentVariable = get(variableKey);
		if(presentVariable == null){
			// If not, check if the currently accessing tool has access to the
			// source of the variable.
			VariableHandler variableHandler = ToolRegistery.getInstance().getVariableHandler();
			Variable sourceVariable = variableHandler.get(variable.getVariableID());

			presentVariable = sourceVariable;

			if(sourceVariable == null){
				// If this variable is unaccessable and not present in this pool
				// add it.
				ValueContainer valueContainer = new ValueContainer(variableKey, variable);
				Reference value = null;
				if(strength == SOFT){
					value = new SoftReference(valueContainer);
				}else if(strength == WEAK){
					value = new WeakReference(valueContainer);
				}else{
					value = new WeakReference(valueContainer);
				}

				variables.put(variableKey, value);

				presentVariable = variable;
			}
		}

		// Return the reference to the variable present in this pool.
		return presentVariable;
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
		Variable variable = null;

		VariableKey referenceKey = getKeyReference(variableKey);
		if(referenceKey != null){
			Reference value = (Reference) variables.get(referenceKey);
			if(value != null){
				ValueContainer ValueContainer = (ValueContainer) value.get();
				variable = ValueContainer.getVariable();
			}
		}

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
	 * Container for variables. This is nessecary for ensuring proper collection
	 * of softly referenced values in the contantpool.
	 * 
	 * @author Arnold Lankamp
	 */
	private class ValueContainer{
		private VariableKey key = null;
		private Variable variable = null;

		/**
		 * Constructor.
		 * 
		 * @param key
		 *            The key of the variable (unique identifier).
		 * @param variable
		 *            The variable itself.
		 */
		public ValueContainer(VariableKey key, Variable variable){
			super();

			this.key = key;
			this.variable = variable;
		}

		/**
		 * Returns the variable contained in this object.
		 * 
		 * @return The variable.
		 */
		public Variable getVariable(){
			return variable;
		}

		/**
		 * Deregisters this object when it is collected.
		 * 
		 * @see java.lang.Object#finalize()
		 */
		public void finalize(){
			remove(key);
		}
	}
}
