package toolbus.process;

import java.util.Iterator;
import java.util.Vector;

import aterm.AFun;
import aterm.ATerm;
import aterm.ATermList;

import toolbus.Environment;
import toolbus.TBTerm;
import toolbus.ToolBus;
import toolbus.ToolBusException;
import toolbus.atom.Atom;
import toolbus.atom.AtomSet;
import toolbus.tool.ToolInstance;

/**
 * @author paulk, Jul 23, 2002
 */
public class ProcessInstance {
  static int processCount = 0;
  static AtomSet empty = new AtomSet();
  private ATerm processId;
  private AtomSet atoms;
  private AtomSet prefix;
  private Environment env;
  private ToolBus toolbus;
  private ToolInstance toolinstance;

  public ProcessInstance(ToolBus TB, String name, ATermList actuals) throws ToolBusException {
  	
  	ProcessDefinition def = TB.getProcessDefinition(name);
  	
  	env = new Environment();
  	ProcessExpression PE = def.compile(this, empty, actuals);
  	
    Vector procs = TB.getProcesses();
    
    AFun afun = TBTerm.factory.makeAFun(name, 1, false);
	processId = TBTerm.factory.makeAppl(afun, TBTerm.factory.makeInt(processCount++));
		
    toolbus = TB;

    atoms = PE.getAtoms();
    for (int i = 0; i < procs.size(); i++) {
      ((ProcessInstance) procs.elementAt(i)).findPartners(atoms);
    }
    prefix = PE.getFirst();
    env.setExecuting();
    
    toolinstance = def.createToolInstance();

    System.out.println(processId + ": " + PE);
    System.out.println(processId + ": atoms: =" + atoms);
    System.out.println(processId + ": prefix = " + prefix);
    for (Iterator it = atoms.getAtomsAsVector().iterator(); it.hasNext();) {
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

  public ATerm getProcessId() {
    return processId;
  }
  
  public ToolInstance getToolInstance(){
  	return toolinstance;
  }
  
  public void terminate(String msg){
  	if(toolinstance != null){
  		toolinstance.terminate(msg);
  	}
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
