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

  public static int nextInt(int n) {
    return rand.nextInt(n);
  }

  public static boolean nextBoolean() {
    return rand.nextBoolean();
  }

  private ATerm build(ATerm t) throws ToolBusException {

    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.APPL :
        String name = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();

        if (name == "vardecl") { // vardecl(name, type) => var(-1,type,name)
          AFun afun = factory.makeAFun("var", 3, false);
          ATerm cargs[] = new ATerm[] { factory.makeInt(-1), args[1], args[0] };
          return factory.makeAppl(afun, cargs);
          
        } else if (name == "resvardecl") { // resvardecl(name, type) => rvar(-1,type,name)
          AFun afun = factory.makeAFun("rvar", 3, false);
          ATerm cargs[] = new ATerm[] { factory.makeInt(-1), args[1], args[0] };
          return factory.makeAppl(afun, cargs);
        } else if (name == "var") { // var(name) => var(-1, -1, name)
          AFun afun = factory.makeAFun("var", 3, false);
          ATerm cargs[] = new ATerm[] { factory.makeInt(-1), factory.makeInt(-1), args[0] };
          return factory.makeAppl(afun, cargs);
        } else if (name == "resvar") { // resvar(name) => rvar(-1, -1, name)
          AFun afun = factory.makeAFun("rvar", 3, false);
          ATerm cargs[] = new ATerm[] { factory.makeInt(-1), factory.makeInt(-1), args[0] };
          return factory.makeAppl(afun, cargs);
        } else if (name == "apply") {   // apply(name, arglist)
          if (args.length != 2)
            throw new ToolBusException("apply: wrong number of args");
 
          ATermList args1 = (ATermList) args[1];
          String fname = ((ATermAppl) args[0]).getName();
          AFun afun = factory.makeAFun(fname, args1.getLength(), false);
          ATermList realargs = factory.makeList();
          
          for(int i = 0; i < args1.getLength(); i++){
            realargs.append(build(args1.elementAt(i)));
          }
          return factory.makeAppl(afun, realargs);

        } else if (name == "natcon") {  // natcon(str)
        } else if (name == "realcon") { // realcon(str, str)
        } else if (name == "posint") {  // posint(str)
        } else if (name == "negint") {   //negint(str)
        } else
          throw new ToolBusException("illegal symbol " + name);
      case ATerm.LIST :
        ATermList lst = t.getFactory().makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          lst = lst.append(build(((ATermList) t).elementAt(i)));
        }
        return lst;
    }
    throw new ToolBusInternalError("illegal ATerm in build: " + t);
  }

  public void parse(String filename) throws ToolBusException {
    ATerm interm;
    try {
      interm = factory.readFromFile(filename);
    } catch (IOException e) {
      throw new ToolBusException(e.getMessage());
    }

    if (interm.getType() != ATerm.APPL || ((ATermAppl) interm).getName() != "Tscript" || interm.getChildCount() != 2) {
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
