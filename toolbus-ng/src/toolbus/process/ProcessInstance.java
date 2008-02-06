package toolbus.process;

import java.util.HashSet;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Set;
import java.util.Stack;

import toolbus.AtomSet;
import toolbus.State;
import toolbus.StateElement;
import toolbus.TBTermFactory;
import toolbus.ToolBus;
import toolbus.atom.Atom;
import toolbus.environment.Environment;
import toolbus.exceptions.ToolBusException;
import toolbus.process.debug.ExecutionResult;
import aterm.ATerm;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance{
	private static State empty = new State();
	
	private final ProcessDefinition definition;
	private final String processName;
	private final int processId;
	
	private final AtomSet elements;
	
	private final State initialState; // Needed for debugging purposes.
	private State currentState;
	
	private final ToolBus toolbus;
	private final TBTermFactory tbfactory;
	
	private final List<ATerm> subscriptions;
	private final List<ATerm> notes;
	
	private boolean running = true;
	
	public ProcessInstance(ToolBus TB, ProcessCall call, int processId) throws ToolBusException{
		toolbus = TB;
		tbfactory = TB.getTBTermFactory();
		this.processId = processId;
		subscriptions = new LinkedList<ATerm>();
		notes = new LinkedList<ATerm>();
		call.setEvalArgs(false);
		processName = call.getName();
		
		definition = TB.getProcessDefinition(processName, call.actuals.getLength());
		
		call.computeFirst();
		call.replaceFormals(new Environment(tbfactory));
		Stack<String> stack = new Stack<String>();
		stack.push("TOPLEVEL");
		call.compile(this, stack, empty);
		
		elements = call.getAtoms();
		
		currentState = call.getFirst();
		initialState = call.PE.getFirst();
		currentState.activate();
		
		addPartnersToAllProcesses(elements);
	}
	
	public TBTermFactory getTBTermFactory(){
		return tbfactory;
	}
	
	public void addToAtomSignature(AtomSet atoms){
		Iterator<Atom> atomSetIterator = atoms.iterator();
		while(atomSetIterator.hasNext()){
			Atom a = atomSetIterator.next();
			
			toolbus.addToSignature(a.toATerm());
		}
	}
	
	public ToolBus getToolBus(){
		return toolbus;
	}
	
	public long getRunTime(){
		return toolbus.getRunTime();
	}
	
	public int getProcessId(){
		return processId;
	}
	
	public String getProcessName(){
		return processName;
	}
	
	public void terminate(ATerm msg){
		running = false;
		
		Iterator<ProcessInstance> processInstanceIterator = toolbus.getProcesses().iterator();
		while(processInstanceIterator.hasNext()){
			ProcessInstance pi = processInstanceIterator.next();
			
			if(pi != this){
				pi.delPartners(elements);
			}
		}
	}
	
	public void addElements(AtomSet atoms){
		Iterator<Atom> atomSetIterator = atoms.iterator();
		while(atomSetIterator.hasNext()){
			Atom a = atomSetIterator.next();
			
			elements.addAtom(a);
		}
	}
	
	public void delElements(AtomSet atoms){
		Iterator<Atom> atomSetIterator = atoms.iterator();
		while(atomSetIterator.hasNext()){
			Atom a = atomSetIterator.next();
			
			elements.delAtom(a);
		}
	}
	
	/**
	 * Add potential partners to this StateElement. This may optimize execution. Typical examples:
	 * partnering SndMsg with RecMsg, and SndNote with Subscribe
	 * 
	 * @param atoms
	 *            containing the potential partners
	 */
	public void addPartners(AtomSet atoms){
		// LoggerFactory.log(this.getProcessName(), "add the partners " + atoms,
		// IToolBusLoggerConstants.MESSAGES);
		Iterator<Atom> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			Atom e = elementsIterator.next();
			
			e.addPartners(atoms);
		}
	}
	
	/**
	 * Delete partners from this StateElement. This is necessary when processes die and partners are
	 * no longer available.
	 * 
	 * @param atoms
	 *            containing the partners
	 */
	public void delPartners(AtomSet atoms){
		Iterator<Atom> elementsIterator = elements.iterator();
		while(elementsIterator.hasNext()){
			Atom e = elementsIterator.next();
			
			e.delPartners(atoms);
		}
	}
	
	public void addPartnersToAllProcesses(AtomSet atoms){
		// System.err.println("Enter addPartnersToAllProcesses for: " + this.getProcessName());
		Iterator<ProcessInstance> processInstanceIterator = toolbus.getProcesses().iterator();
		while(processInstanceIterator.hasNext()){
			ProcessInstance pi = processInstanceIterator.next();
			
			// System.err.println("[" + this.getProcessName() + "] addPartnersToAllProcesses: " +
			// P.getProcessName());
			if(pi != this){
				// LoggerFactory.log(this.getProcessName(), "add partners to " + P.getProcessName(),
				// IToolBusLoggerConstants.MESSAGES);
				pi.addPartners(atoms);
			}
		}
	}
	
	public void delPartnersFromAllProcesses(AtomSet atoms){
		Iterator<ProcessInstance> processInstanceIterator = toolbus.getProcesses().iterator();
		while(processInstanceIterator.hasNext()){
			ProcessInstance pi = processInstanceIterator.next();
			
			if(pi != this){
				pi.delPartners(atoms);
			}
		}
	}
	
	/*
	 * Note manipulation
	 */

	public void subscribe(ATerm pat){
		//LoggerFactory.log(definition.getName(), "subscribe " + pat, IToolBusLoggerConstants.NOTES);
		if(!subscriptions.contains(pat)) subscriptions.add(pat);
	}
	
	public void unsubscribe(ATerm pat){
		//LoggerFactory.log(definition.getName(), "unsubscribe: " + pat, IToolBusLoggerConstants.NOTES);
		subscriptions.remove(pat);
	}
	
	public boolean getNoteFromQueue(ATerm pat, Environment env){
		Iterator<ATerm> notesIterator = notes.iterator();
		while(notesIterator.hasNext()){
			ATerm note = notesIterator.next();
			if(tbfactory.matchPatternToValue(pat, env, note)){
				notesIterator.remove();
				//LoggerFactory.log(definition.getName(), "getNotefromQueue: " + note, IToolBusLoggerConstants.NOTES);
				return true;
			}
		}
		return false;
	}
	
	public boolean noNoteInQueue(ATerm pat, Environment env){
		//LoggerFactory.log(definition.getName(), "noNoteinQueue: " + pat, IToolBusLoggerConstants.NOTES);
		Iterator<ATerm> notesIterator = notes.iterator();
		while(notesIterator.hasNext()){
			ATerm note = notesIterator.next();
			if(tbfactory.patternMatchesToValue(pat, env, note)){
				return false;
			}
		}
		return true;
	}
	
	public boolean putNoteInQueue(ATerm note){
		//LoggerFactory.log(definition.getName(), "putNoteinQueue: " + note, IToolBusLoggerConstants.NOTES);
		
		Iterator<ATerm> subscriptionsIterator = subscriptions.iterator();
		while(subscriptionsIterator.hasNext()){
			ATerm sub = subscriptionsIterator.next();
			if(tbfactory.mightMatch(sub, note)){
				notes.add(note);
				return true;
			}
		}
		return false;
	}
	
	public boolean hasNotes(){
		return !notes.isEmpty();
	}
	
	public List<ATerm> getSubscriptions(){
		return subscriptions;
	}
	
	public List<ATerm> getNoteQueue(){
		return notes;
	}
	
	public State getProcessState(){
		return currentState;
	}
	
	public boolean contains(StateElement a){
		return currentState.contains(a);
	}
	
	public State getCurrentState(){
		return currentState;
	}
	
	public void gotoNextStateAndActivate(){
		currentState = currentState.gotoNextStateAndActivate();
	}
	
	public void gotoNextStateAndActivate(StateElement se){
		currentState = currentState.gotoNextStateAndActivate(se);
	}
	
	public boolean step() throws ToolBusException{
		if(running && currentState.execute()){
			gotoNextStateAndActivate();
			return true;
		}
		return false;
	}
	
	/**
	 * Executes on step in debug mode, where the state element that was executed is returned as result.
	 * 
	 * @return The result of the execution (if contains the state element and partners); null if
	 * nothing was executed.
	 * @throws ToolBusException Thrown if something went wrong.
	 */
	public ExecutionResult debugStep() throws ToolBusException{
		if(running){
			ExecutionResult executionResult = currentState.debugExecute();
			if(executionResult != null){
				StateElement stateElement = executionResult.stateElement;
				if(stateElement instanceof ProcessCall){ // If we just encountered a process call, find out what element it executed (so we can pretent it got inlined).
					executionResult = new ExecutionResult(((ProcessCall) stateElement).getExecutedStateElement(), executionResult.partners);
				}
				gotoNextStateAndActivate();
				return executionResult;
			}
		}
		return null;
	}
	
	public boolean isTerminated(){
		if(!running || currentState.size() == 0){
			return true;
		}
		return false;
	}
	
	public String toString(){
		return "ProcessInstance(" + definition.getName() + ", " + processId + ", " + currentState + ")";
	}
	
	public String showStatus(){
		String r1 = "process " + definition.getName() + "(" + processId + "):\n  " + elements.size() + " elements\n" + currentState;
		if(subscriptions.size() > 0){
			String r2 = "\n  Subscriptions: {";
			Iterator<ATerm> SubscriptionsIterator = notes.iterator();
			while(SubscriptionsIterator.hasNext()){
				ATerm sub = SubscriptionsIterator.next();
				r2 = r2 + "\n    " + sub.toString();
			}
			if(notes.size() > 0){
				String r3 = "}\n  Note queue:{";
				Iterator<ATerm> notesIterator = notes.iterator();
				while(notesIterator.hasNext()){
					ATerm note = notesIterator.next();
					
					r3 = r3 + "\n    " + note.toString();
				}
				r3 = r3 + "}";
				return r1 + r2 + r3;
			}
			return r1 + r2;
		}
		return r1;
	}
	
	public void showAutomaton(){
		// LoggerFactory.log("process " + processId + ": " + call, IToolBusLoggerConstants.CALLS);
		// LoggerFactory.log("process " + processId + ": atoms: =" + elements, IToolBusLoggerConstants.CALLS);
		// LoggerFactory.log("process " + processId + ": currentState = " + currentState, IToolBusLoggerConstants.CALLS);
		/*Iterator<Atom> atomSetIterator = elements.iterator();
		while(atomSetIterator.hasNext()){
			Atom a = atomSetIterator.next();
			//LoggerFactory.log(definition.getName(), a + " --> " + a.getFollow(), IToolBusLoggerConstants.CALLS);
		}*/
	}
	
	/**
	 * Returns a complete list of state elements in this process instance.
	 * This method is only required for obtaining a reference to a state element, so we can set a
	 * break point on it when running the toolbus in debug mode.
	 * 
	 * @return A complete list of atoms in this process instance.
	 */
	public Set<StateElement> getStateElements(){
		Set<StateElement> stateElementsSet = new HashSet<StateElement>();
		List<StateElement> stateElementsToDo = new LinkedList<StateElement>();
		
		stateElementsToDo.addAll(initialState.getElementsAsList());
		do{
			StateElement stateElement = stateElementsToDo.remove(0);
			State state = stateElement.getFollow();
			List<StateElement> stateElements = state.getElementsAsList();
			Iterator<StateElement> stateElementsIterator = stateElements.iterator();
			while(stateElementsIterator.hasNext()){
				StateElement se = stateElementsIterator.next();
				if(!stateElementsSet.contains(se)){
					stateElementsToDo.add(se);
				}
				stateElementsSet.add(se);
			}
		}while(!stateElementsToDo.isEmpty());
		
		return stateElementsSet;
	}
}
