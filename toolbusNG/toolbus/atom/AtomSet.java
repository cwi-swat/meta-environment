/**
 * @author paulk
 */

package toolbus.atom;
import java.util.*;

import toolbus.ToolBusException;
import toolbus.process.ProcessInstance;

import aterm.ATerm;

public class AtomSet {
  private Vector atoms;
  private static Random rand = new Random();

  public AtomSet() {
    atoms = new Vector();
  }

  public void add(Atom a) {
    if (!atoms.contains(a)) {
      atoms.addElement(a);
    }
  }

  public AtomSet union(AtomSet b) {
    AtomSet c = new AtomSet();

    for (Iterator it = atoms.iterator(); it.hasNext();)
      c.add((Atom) it.next());

    for (Iterator it = b.getAtomsAsVector().iterator(); it.hasNext();)
      c.add((Atom) it.next());

    //System.out.println("union(" + this + ", " + b + ") => " + c);
    return c;
  }

  public Vector getAtomsAsVector() {
    return atoms;
  }

  public int size() {
    return atoms.size();
  }

  public boolean contains(Atom a) {
    return atoms.contains(a);
  }

  public void findPartners(AtomSet set) {
    for (Iterator ita = atoms.iterator(); ita.hasNext();) {
      Atom a = (Atom) ita.next();

      for (Iterator itb = set.getAtomsAsVector().iterator(); itb.hasNext();) {
        Atom b = (Atom) itb.next();
        if (a.canCommunicate(b)) {
          a.addPartner(b);
          b.addPartner(a);
        }
      }
    }
  }

  public void setTest(ATerm test) throws ToolBusException {
    for (Iterator it = atoms.iterator(); it.hasNext();) {
      Atom a = (Atom) it.next();
      a.setTest(test);
    }
  }

  public boolean execute() throws ToolBusException {
    int size = atoms.size();

    if (size == 0)
      return false;

    for (int index = rand.nextInt(size), nleft = size; nleft > 0; index = (index + 1) % size, nleft--) {
      Atom a = (Atom) atoms.elementAt(index);

      if (a.execute()) {
        ProcessInstance pa = a.getProcess();
        System.out.println("--- " + pa.getProcessId() + " / " + a.toString() + " / " + pa.getEnv() + " / ");
        pa.follow(a);
        return true;
      }
    }
    return false;
  }

  public String toString() {
    String s = "{";
    String sep = "";
    for (Iterator it = atoms.iterator(); it.hasNext();) {
      Atom a = (Atom) it.next();
      s += sep + a;
      sep = ", ";
    }
    return s + "}";
  }
}
