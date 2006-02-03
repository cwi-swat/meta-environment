/**
 * @author paulk
 */

package toolbus;
import java.util.HashMap;
import java.util.Vector;

import toolbus.atom.Atom;
import toolbus.atom.MsgAtom;
import aterm.ATerm;


/**
 * class State represents one state in the state diagram of a process. It consists of StateElements
 *
 */

public class State {
	
  private Vector<StateElement> elements;
  
  private int nElements = 0;
  
  private int lastElement = 0;
  
  private boolean allAtoms = true;
  
  private HashMap<StateElement,Boolean> cache = new HashMap<StateElement,Boolean>(10);

  public State() {
    elements = new Vector<StateElement>();
  }

  public void add(StateElement a) {
    if (!elements.contains(a)) {
      elements.addElement(a);
      nElements += 1;
      if(!(a instanceof Atom)){
    	  allAtoms = false;
      }
    }
  }

  public State union(State b) {
    State c = new State();

    //for (Iterator it = elements.iterator(); it.hasNext();)
    //   c.add((StateElement) it.next());
    
    for(StateElement se : elements){
    	c.add(se);
    }

   // for (Iterator it = b.getElementsAsVector().iterator(); it.hasNext();)
   //   c.add((StateElement) it.next());
    
    for(StateElement se : b.getElementsAsVector()){
    	c.add(se);
    }

    return c;
  }

  public Vector<StateElement> getElementsAsVector() {
    return elements;
  }

  public int size() {
    return elements.size();
  }

  public void findPartners(State set) {
    for (StateElement a : elements) {
      if (!(a instanceof MsgAtom)) {
        continue;
      }
      MsgAtom ca = (MsgAtom) a;

      for (StateElement b : set.getElementsAsVector()) {
        if (!(b instanceof MsgAtom)) {
          continue;
        }
        MsgAtom cb = (MsgAtom) b;
        if (ca.canCommunicate(cb)) {
          ca.addMsgPartner(cb);
          cb.addMsgPartner(ca);
        }
      }
    }
  }

  public void setTest(ATerm test, Environment env) throws ToolBusException {
  	if (test != null){
	    for (StateElement a : elements) {
	      a.setTest(test, env);
	    }
  	}
  }
  
  public boolean isEnabled(){
  	 for (StateElement a : elements) {
	      try {
			if(a.isEnabled()){
			  	return true;
			  }
		} catch (ToolBusException e) {
			// TODO Auto-generated catch block
			e.printStackTrace();
		}
  	 }
  	 return false;
  }

  public String toString() {
    String s = "{";
    String sep = "";
    for (StateElement a : elements) {
      s += sep + a;
      sep = ", ";
    }
    return s + "}";
  }

  public boolean contains(StateElement a) {
	  if(cache.containsKey(a)){
		  Boolean bval = cache.get(a);
		  return bval.booleanValue();
	 }
	 for (StateElement b : elements) {
	      if(b.contains(a)){
	    	  if (allAtoms)
				cache.put(a, Boolean.TRUE);
	      	return true;
	      }
	 }
	if(allAtoms)
		cache.put(a, Boolean.FALSE);
    return false;
  }
  
  public State getNextState(){
  return elements.elementAt(lastElement).getNextState();
  }
  
  public State getNextState(StateElement a){
	 for (StateElement b : elements) {
	      //System.err.println("State.getNextState2: trying " + b);
	      if(b.equals(a) || b.contains(a)){
	      	return b.getNextState(a);
	      }
	 }
     System.err.println("State.GetNextState2: no element " + a);
     return null;
    }
  
  public void activate(){
  	for (StateElement e : elements){
  		e.activate();
  	}
  }
  
  /**
   * Execute one step for an element in this state.
   */
  
  public boolean execute() throws ToolBusException {
    if (nElements == 0)
       return false;

    for(int index = (lastElement + 1) % nElements, nleft = nElements; nleft > 0; index = (index + 1) % nElements, nleft--){
      StateElement a = elements.elementAt(index);

      if (a.execute()) {
      	lastElement = index;
 
        //if (ToolBus.isVerbose()) {
           //ProcessInstance pa = a.getProcess();
          //System.err.println("--- " + pa.getProcessId() + " / " + a.toString());
       // }
        return true;
      }
    }
    return false;
  }

}
