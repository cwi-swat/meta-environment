/**
 * @author paulk
 */
package toolbus;

import java.util.ArrayList;
import java.util.IdentityHashMap;
import java.util.Iterator;
import java.util.List;
import toolbus.atom.Atom;
import toolbus.atom.msg.SndMsg;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.process.ProcessInstance;
import toolbus.process.debug.ExecutionResult;
import aterm.ATerm;

/**
 * class State represents one state in the state diagram of a process. It consists of StateElements
 */
public class State{
	private final List<StateElement> elements;
	
	private final IdentityHashMap<StateElement, Boolean> cache;
	
	private int nElements = 0;
	
	private int lastElement = 0;
	
	private boolean allAtoms = true;
	
	public State(){
		elements = new ArrayList<StateElement>();
		
		cache = new IdentityHashMap<StateElement, Boolean>();
	}
	
	public void addElement(StateElement a){
		if(!elements.contains(a)){
			elements.add(a);
			nElements += 1;
			if(!(a instanceof Atom)){
				allAtoms = false;
			}
		}
	}
	
	public void delElement(StateElement a){
		if(elements.remove(a)) nElements -= 1;
	}
	
	public State union(State b){
		State c = new State();
		
		Iterator<StateElement> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			StateElement se = elementsIterator.next();
			
			c.addElement(se);
		}
		
		Iterator<StateElement> stateIterator = b.getElementsAsList().iterator();
		while(stateIterator.hasNext()){
			StateElement se = stateIterator.next();
			
			c.addElement(se);
		}
		return c;
	}
	
	public List<StateElement> getElementsAsList(){
		return elements;
	}
	
	public int size(){
		return elements.size();
	}
	
	public void setTest(ATerm test, Environment env) throws ToolBusException{
		if(test != null){
			Iterator<StateElement> elementsIterator = elements.iterator();
			while(elementsIterator.hasNext()){
				StateElement a = elementsIterator.next();
				
				a.setTest(test, env);
			}
		}
	}
	
	public boolean isEnabled(){
		Iterator<StateElement> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			StateElement a = elementsIterator.next();
			
			try{
				if(a.isEnabled()){
					return true;
				}
			}catch(ToolBusException e){
				// TODO Auto-generated catch block
				e.printStackTrace();
			}
		}
		return false;
	}
	
	public String toString(){
		String sep = "";
		
		String s = "{";
		
		Iterator<StateElement> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			StateElement a = elementsIterator.next();
			
			s += sep + a;
			sep = ",\n  ";
		}
		
		s += "}";
		
		return s;
	}
	
	public boolean contains(StateElement a){
		if(cache.containsKey(a)){
			Boolean bval = cache.get(a);
			return bval.booleanValue();
		}
		Iterator<StateElement> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			StateElement b = elementsIterator.next();
			
			if(b.contains(a)){
				if(allAtoms) cache.put(a, Boolean.TRUE);
				return true;
			}
		}
		if(allAtoms) cache.put(a, Boolean.FALSE);
		
		return false;
	}
	
	public State gotoNextStateAndActivate(){
		if(nElements > 0){
			return elements.get(lastElement).gotoNextStateAndActivate();
		}
		return this;
	}
	
	public State gotoNextStateAndActivate(StateElement a){
		Iterator<StateElement> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			StateElement b = elementsIterator.next();
			
			// System.err.println("State.getNextState2: trying " + b);
			if(b.equals(a) || b.contains(a)){
				return b.gotoNextStateAndActivate(a);
			}
		}
		System.err.println("State.GetNextState2: no element " + a);
		return null;
	}
	
	public void activate(){
		// System.err.println("State.activate: " + this);
		Iterator<StateElement> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			StateElement e = elementsIterator.next();
			
			e.activate();
		}
	}
	
	/**
	 * Execute one step for an element in this state.
	 */
	public boolean execute() throws ToolBusException{
		if(nElements == 0) return false;
		
		for(int index = (lastElement + 1) % nElements, nleft = nElements; nleft > 0; index = (index + 1) % nElements, nleft--){
			StateElement a = elements.get(index);
			
			if(a.execute()){
				lastElement = index;
				//LoggerFactory.log(a.getProcess().getProcessName(), "execute: " + a, IToolBusLoggerConstants.EXECUTE);
				
				return true;
			}
		}
		return false;
	}
	
	/**
	 * Executes one step in debug mode and returns the executed state element as result.
	 * 
	 * @return The result of the execution (if contains the state element and partners); null if
	 * none was executed.
	 * @throws ToolBusException Thrown if something went wrong.
	 */
	public ExecutionResult debugExecute() throws ToolBusException{
		if(nElements == 0) return null;
		
		for(int index = (lastElement + 1) % nElements, nleft = nElements; nleft > 0; index = (index + 1) % nElements, nleft--){
			StateElement a = elements.get(index);
			
			ProcessInstance[] partners = a.debugExecute();
			if(partners != null){
				lastElement = index;
				
				return new ExecutionResult(a, partners);
			}
		}
		return null;
	}
	
	/**
	 * Returns the last executed state element in the current state.
	 * (This method is used for debugging only).
	 * @return The last executed state element in the current state.
	 */
	public StateElement getLastExecutedStateElement(){
		return elements.get(lastElement);
	}
	
	public List<StateElement> getUnhandledMessages(){
		List<StateElement> unhandledMessages = new ArrayList<StateElement>();
		
		int nrOfElements = elements.size();
		
		try{
			while((--nrOfElements) >= 0){
				StateElement element = elements.get(nrOfElements);
				if(element instanceof SndMsg){
					unhandledMessages.add(element);
				}
			}
		}catch(RuntimeException rex){
			// This will never happen, it's here just in case.
		}
		
		return unhandledMessages;
	}
}
