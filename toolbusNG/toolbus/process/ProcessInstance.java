package toolbus.process;

import java.util.Iterator;
import java.util.Vector;

import toolbus.Environment;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.AtomSet;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance {
  static int processCount = 0;
  static AtomSet empty = new AtomSet();
  private int processId;
  private AtomSet atoms;
  private AtomSet prefix;
  private Environment env;
  private ToolBus toolbus;

  public ProcessInstance(ToolBus TB, ProcessExpression PE) throws ToolBusException {
    Vector procs = TB.getProcesses();
    processId = processCount++;
    env = new Environment();
    toolbus = TB;
    PE.compile(this, empty);
    atoms = PE.getAtoms();
    for (int i = 0; i < procs.size(); i++) {
      ((ProcessInstance) procs.elementAt(i)).findPartners(atoms);
    }
    prefix = PE.getFirst();
    env.setExecuting();

    System.out.println(processId + ": " + PE);
    System.out.println(processId + ": atoms: =" + atoms);
    System.out.println(processId + ": prefix = " + prefix);
    for (Iterator it = atoms.getAtoms().iterator(); it.hasNext();) {
      Atom a = (Atom) it.next();
      System.out.println(processId + ": " + a + " --> " + a.getFollow());
    }
  }

  public Environment getEnv() {
    return env;
  }

  public ToolBus getToolBus() {
    return toolbus;
  }

  public int getProcessId() {
    return processId;
  }

  public void findPartners(AtomSet a) {
    atoms.findPartners(a);
  }

  public AtomSet getPrefix() {
    return prefix;
  }

  public boolean prefixContains(Atom a) {
    return prefix.contains(a);
  }

  public void follow(Atom a) {
    if (!prefix.contains(a))
      System.out.println("*** ProcessInstance.follow: " + a + " not in prefix " + prefix);
    prefix = a.getFollow();
    //System.out.println("proc " + processId + ": follow(" + a + ") -> " + prefix);
  }

  public boolean step() throws ToolBusException {
    //System.out.println(this);
    return prefix.execute();
  }

  public boolean isTerminated() {
    return (atoms.size() == 0);
  }

  public String toString() {
    return "proc " + processId + " " + prefix;
  }
}
