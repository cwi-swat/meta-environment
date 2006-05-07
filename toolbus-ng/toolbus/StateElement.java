package toolbus;

import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * The interface StateElement captures all operations that can be performed on
 * an element of a State. Recall that all proces expressions are compiled to a
 * finite automaton consisting of States and transitions.
 * 
 * The most typical example of a StateElement is an Atom.
 * 
 */
public interface StateElement {

	/**
	 * Check whether a StateElement contains another StateElement. In the
	 * simplest case of Atom this is just an identity test. In composite cases
	 * (e.g. Merge), it requires a recursive search.
	 * 
	 * @param elem
	 *            the StateElement
	 * @return true (contained in) or false (not contained in)
	 */
	public boolean contains(StateElement elem);

	/**
	 * Add a test to this StateElem. Tests implement conditionals as well as
	 * delay/timeout.
	 * 
	 * @param test
	 * @param env
	 *            to be used for executing the test
	 * @throws ToolBusException
	 */
	public void setTest(ATerm test, Environment env) throws ToolBusException;

	/**
	 * Add potential partners to this StateElement. This may optimize execution.
	 * Typical examples: partnering SndMsg with RecMsg, and SndNote with
	 * Subscribe
	 * 
	 * @param atoms
	 *            containing the potential partners
	 * @throws ToolBusException
	 */
	
	//public void addPartners(AtomSet atoms) throws ToolBusException;

	/**
	 * Delete partners from this StateElement. This is necessary when processes
	 * die and partners are no longer available.
	 * 
	 * @param atoms
	 *            containing the partners
	 * @throws ToolBusException
	 */
	//public void delPartners(AtomSet atoms) throws ToolBusException;

	/**
	 * Is this StateElelement enabled for execution, i.e., are its associated
	 * tests all true? If enabled, the StateElement is ready for execution.
	 * 
	 * @return true (enabled) or false (not enabled).
	 * @throws ToolBusException
	 */
	public boolean isEnabled() throws ToolBusException;
	

	/**
	 * 
	 * @return the ProcessInstance to which the StateElement belongs
	 */
	public ProcessInstance getProcess();

	/**
	 * Activate the StateElement, i.e. make it ready for execution. This may
	 * involve initialization and the setting of timers.
	 */
	public void activate();

	/**
	 * Execute this StateElement
	 * 
	 * @return true if execution was completed.
	 * @throws ToolBusException
	 */
	public boolean execute() throws ToolBusException;

	/**
	 * @return the successor State of the StateElement
	 */
	public State gotoNextStateAndActivate();

	/**
	 * Get the successor of the StateElement for a given other StateElement
	 * elem. This typically used for a composite StateElement to get a specific
	 * successor.
	 * 
	 * @param elem
	 * @return
	 */
	public State gotoNextStateAndActivate(StateElement elem);
}
