package toolbus.environment;

/**
 * The Bindings interface maintains (at least conceptually) a
 * list of Bindings. Newer bindings appear at the begiing of the list.
 *
 */
interface Bindings {

	/**
	 * @return deep copy of the Bindings object
	 */
	public Bindings clone();

	/**
	 * Return the first binding of for a given key value
	 * @param key
	 * @return its binding or null
	 */
	public Binding get(String key);

	/**
	 * Introduce a new (key, binding) pair
	 * @param key
	 * @param binding
	 */
	public void put(String key, Binding binding);

	/**
	 * Remove the first binding for key
	 * @param key
	 */
	public void remove(String key);

	/**
	 * @return a string representation
	 */
	public String toString();
}