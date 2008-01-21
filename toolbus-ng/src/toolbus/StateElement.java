package toolbus;

import java.util.List;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.parsercup.PositionInformation;
import toolbus.process.ProcessInstance;
import aterm.ATerm;

/**
 * The interface StateElement captures all operations that can be performed on an element of a
 * State. Recall that all proces expressions are compiled to a finite automaton consisting of States
 * and transitions. The most typical example of a StateElement is an Atom.
 */
public interface StateElement{
	
	/**
	 * Check whether a StateElement contains another StateElement. In the simplest case of Atom this
	 * is just an identity test. In composite cases (e.g. Merge), it requires a recursive search.
	 * 
	 * @param elem
	 *            the StateElement
	 * @return true (contained in) or false (not contained in)
	 */
	boolean contains(StateElement elem);
	
	/**
	 * Add a test to this state element. Tests implement conditionals but not delays / timeouts.
	 * 
	 * @param test
	 * @param env
	 *            to be used for executing the test
	 * @throws ToolBusException
	 */
	void setTest(ATerm test, Environment env) throws ToolBusException;
	
	/**
	 * Returns a collection containing all tests that are associated with this state element.
	 * 
	 * @return A collection containing all tests that are associated with this state element.
	 */
	List<ATerm> getTests();
	
	/**
	 * Is this StateElelement enabled for execution, i.e., are its associated tests all true? If
	 * enabled, the StateElement is ready for execution.
	 * 
	 * @return true (enabled) or false (not enabled).
	 * @throws ToolBusException
	 */
	boolean isEnabled() throws ToolBusException;
	
	/**
	 * @return the ProcessInstance to which the StateElement belongs
	 */
	ProcessInstance getProcess();
	
	/**
	 * Activate the StateElement, i.e. make it ready for execution. This may involve initialization
	 * and the setting of timers.
	 */
	void activate();
	
	/**
	 * Execute this StateElement
	 * 
	 * @return true if execution was completed.
	 * @throws ToolBusException
	 */
	boolean execute() throws ToolBusException;
	
	/**
	 * @return the successor State of the StateElement
	 */
	State gotoNextStateAndActivate();
	
	/**
	 * Get the successor of the StateElement for a given other StateElement elem. This typically
	 * used for a composite StateElement to get a specific successor. TODO: Probably this method
	 * should be combined with the previous one.
	 * 
	 * @param elem
	 * @return the successor State of the StateElement
	 */
	State gotoNextStateAndActivate(StateElement elem);
	
	/**
	 * Returns the position information associated to the implementing state element.
	 * @return The position information associated to the implementing state element.
	 */
	PositionInformation getPosInfo();
	
	/**
	 * @see toolbus.process.ProcessExpression#getFollow()
	 */
	State getFollow();
}
