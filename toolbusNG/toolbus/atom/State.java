/**
 * @author paulk
 */

package toolbus.atom;
import java.util.*;

import toolbus.ToolBusException;
import toolbus.process.*;
import toolbus.process.ProcessInstance;

import aterm.ATerm;

public class State {
  private Vector elements;
  private static Random rand = new Random();

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

    //System.out.println("union(" + this + ", " + b + ") => " + c);
    return c;
  }

  public Vector getElementsAsVector() {
    return elements;
  }

  public int size() {
    return elements.size();
  }

  public void findPartners(State set) {
    System.out.println("StateElementSet.findpartners: " + elements + " / " + set);
    for (Iterator ita = elements.iterator(); ita.hasNext();) {
      StateElement a = (StateElement) ita.next();
      if(!(a instanceof MsgAtom)){
        continue;
      }
      MsgAtom ca = (MsgAtom) a;

      for (Iterator itb = set.getElementsAsVector().iterator(); itb.hasNext();) {
        StateElement b = (StateElement) itb.next();
        if(!(b instanceof MsgAtom)){
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

  public void setTest(ATerm test) throws ToolBusException {
    for (Iterator it = elements.iterator(); it.hasNext();) {
      Atom a = (Atom) it.next();
      a.setTest(test);
    }
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

  // The ProcessState interface

  public boolean contains(StateElement a) {
    return elements.contains(a);
  }

//  public State nextState(StateElement a) {
//    return a.nextState();
//  }

  public boolean execute() throws ToolBusException {
    int size = elements.size();

    if (size == 0)
      return false;

    for (int index = rand.nextInt(size), nleft = size; nleft > 0; index = (index + 1) % size, nleft--) {
      StateElement a = (StateElement) elements.elementAt(index);

      if (a.execute()) {
        ProcessInstance pa = a.getProcess();
        System.out.println("--- " + pa.getProcessId() + " / " + a.toString() + " / " + pa.getEnv() + " / ");
        //a.nextState();
        return true;
      }
    }
    return false;
  }

}
