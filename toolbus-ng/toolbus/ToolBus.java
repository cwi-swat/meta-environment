/**
 * @author paulk
 */

package toolbus;
import java.io.IOException;
import java.util.*;
import java.util.Vector;

import toolbus.process.*;

import aterm.*;

public class ToolBus {
  
  private static Random rand = new Random();
  private ATermFactory factory;
  private Vector processes;
  private Vector procdefs;

  public ToolBus() {
    this.factory = TBTerm.factory;
    processes = new Vector();
    procdefs = new Vector();
  }

  public ATermFactory getFactory() {
    return factory;
  }

  public Vector getProcesses() {
    return processes;
  }
  
  public static int nextInt(int n){
    return rand.nextInt(n);
  }
  
  public static boolean nextBoolean(){
    return rand.nextBoolean();
  }
  
  public void parse(String filename)throws ToolBusException {
    ATerm interm;
    try {
      interm = factory.readFromFile(filename);
    } catch (IOException e) {
      throw new ToolBusException(e.getMessage());
    }
    
    if(interm.getType() != ATerm.APPL || ((ATermAppl) interm).getName()!= "Tscript" || interm.getChildCount() != 2){
      throw new ToolBusException("ill-formed tree");
    }
    
    ATermList decls = (ATermList) interm.getChildAt(0);
    ATermList calls = (ATermList) interm.getChildAt(1);
    
    System.out.print("decls = " + decls);
    System.out.println("calls = " + calls);
      
  }

  public void addProcessDefinition(ProcessDefinition PD) throws ToolBusException {
    String name = PD.getName();
    for (int i = 0; i < procdefs.size(); i++) {
      ProcessDefinition PD2 = (ProcessDefinition) procdefs.elementAt(i);
      if (name == PD2.getName())
        throw new ToolBusException("duplicate definition of process " + name);
    }
    procdefs.add(PD);
  }

  public ProcessInstance addProcess(String name, ATermList actuals) throws ToolBusException {
    ProcessInstance P = new ProcessInstance(this, name, actuals);
    processes.add(P);
    return P;
  }

  public ProcessInstance addProcess(String name) throws ToolBusException {
    return addProcess(name, (ATermList) factory.make("[]"));
  }

  public ProcessDefinition getProcessDefinition(String name) throws ToolBusException {
    for (int i = 0; i < procdefs.size(); i++) {
      ProcessDefinition PD = (ProcessDefinition) procdefs.elementAt(i);
      if (name == PD.getName())
        return PD;
    }
    throw new ToolBusException("no definition for process " + name);
  }

  public void shutdown(String msg) throws ToolBusDeathException {
    for (int i = 0; i < processes.size(); i++) {
      ProcessInstance P = (ProcessInstance) processes.elementAt(i);
      P.terminate(msg);
    }
    throw new ToolBusDeathException(msg);
  }

  public void execute() {
    boolean work = true;
    int n = 200;

    try {
      while (work) {
        n--;
        work = n > 0;
        for (int i = 0; i < processes.size(); i++) {
          ProcessInstance P = (ProcessInstance) processes.elementAt(i);
          //System.out.println("ToolBus -- " + P);
          P.step();
          //if (P.isTerminated()) {
          //	processes.remove(P);
          //}
        }
      }
    } catch (ToolBusException e) {
      System.out.println(e.getMessage());
    }
    System.out.println("ToolBus halted");
  }
}
