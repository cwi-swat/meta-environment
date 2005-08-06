/**
 * @author paulk
 */

package toolbus;
import java.util.*;

import toolbus.atom.MsgAtom;
import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;
import aterm.*;


/**
 * class State represents one state in the state diagram of a process. It consists of StateElements
 *
 */

public class State {
  private Vector elements;
  
  private int lastElement = 0;

  public State() {
    elements = new Vector();
  }

  public void add(StateElement a) {
    if (!elements.contains(a)) {
      elements.addElement(a);
    }
  }

  public State union(State b) {
    State c = new State();

    for (Iterator it = elements.iterator(); it.hasNext();)
      c.add((StateElement) it.next());

    for (Iterator it = b.getElementsAsVector().iterator(); it.hasNext();)
      c.add((StateElement) it.next());

    //System.err.println("union(" + this + ", " + b + ") => " + c);
    return c;
  }

  public Vector getElementsAsVector() {
    return elements;
  }

  public int size() {
    return elements.size();
  }

  public void findPartners(State set) {
    //System.err.println("StateElementSet.findpartners: " + elements + " / " + set);
    for (Iterator ita = elements.iterator(); ita.hasNext();) {
      StateElement a = (StateElement) ita.next();
      if (!(a instanceof MsgAtom)) {
        continue;
      }
      MsgAtom ca = (MsgAtom) a;

      for (Iterator itb = set.getElementsAsVector().iterator(); itb.hasNext();) {
        StateElement b = (StateElement) itb.next();
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
	    for (Iterator it = elements.iterator(); it.hasNext();) {
	      StateElement a = (StateElement) it.next();
	      a.setTest(test, env);
	    }
  	}
  }
  
  public boolean isEnabled(){
  	 for (Iterator it = elements.iterator(); it.hasNext();) {
	      StateElement a = (StateElement) it.next();
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
    for (Iterator it = elements.iterator(); it.hasNext();) {
      StateElement a = (StateElement) it.next();
      s += sep + a;
      sep = ", ";
    }
    return s + "}";
  }

  // The State interface

  public boolean contains(StateElement a) {
    return elements.contains(a);
  }
  
  public State getNextState(){
  return ((StateElement) elements.elementAt(lastElement)).getNextState();
  }

  /**
   * Execute one step for each element in this state.
   */
  
  public boolean execute() throws ToolBusException {
    int size = elements.size();

    if (size == 0)
      return false;

 //   for (int index = ToolBus.nextInt(size), nleft = size; nleft > 0; index = (index + 1) % size, nleft--) {
    for(int index = (lastElement + 1) % size, nleft = size; nleft > 0; index = (index + 1) % size, nleft--){
      StateElement a = (StateElement) elements.elementAt(index);

      if (a.execute()) {
      	lastElement = index;
 
        if (ToolBus.isVerbose()) {
           // ProcessInstance pa = a.getProcess();
          //System.err.println("--- " + pa.getProcessId() + " / " + a.toString() + " / " + pa.getEnv() + " / ");
        }
        return true;
      }
    }
    return false;
  }

}
