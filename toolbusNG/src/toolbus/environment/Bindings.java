package toolbus.environment;

import java.util.List;

/**
 * The Bindings interface maintains (at least conceptually) a list of Bindings. Newer bindings
 * appear at the begiing of the list.
 */
interface Bindings{
	
	/**
	 * @return deep (**** qualify this !!! ****) copy of the Bindings object
	 */
	Bindings clone();
	
	int size();
	
	/**
	 * Return the first binding of for a given key value
	 * 
	 * @param key
	 * @return its binding or null
	 */
	Binding get(String key);
	
	/**
	 * Introduce a new (key, binding) pair
	 * 
	 * @param key
	 * @param binding
	 */
	void put(String key, Binding binding);
	
	/**
	 * Remove the first binding for key
	 * 
	 * @param key
	 */
	void remove(String key);
	
	/**
	 * Returns a copy of the content of the bindings as a list.
	 * @return A copy of the content of the bindings as a list.
	 */
	List<Binding> getBindingsAsList();
	
	/**
	 * @return a string representation
	 */
	String toString();
}
