/**
 * @author paulk
 */

package toolbus;
import toolbus.atom.*;
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
    initParser();
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

  private Hashtable Funs = new Hashtable();

  private static final int AckEvent = 0;
  private static final int Assign = 1;
  private static final int Create = 2;
  private static final int Delta = 3;
  private static final int Do = 4;
  private static final int Eval = 5;
  private static final int Event = 6;
  private static final int Print = -1;
  private static final int RecMsg = 7;
  private static final int RecVal = 8;
  private static final int ShutDown = 9;
  private static final int SndMsg = 10;
  private static final int Tau = 11;

  private static final int Alternative = 12;
  private static final int Disrupt = 13;
  private static final int IfElse = 14;
  private static final int IfThen = 15;
  private static final int Iteration = 16;
  private static final int LetDefinition = 17;
  private static final int Merge = 18;
  private static final int ProcessCall = 19;
  private static final int Sequence = 20;
  private static final int ProcessDefinition = 21;

  private static final int vardecl = 22;
  private static final int resvardecl = 23;
  private static final int var = 24;
  private static final int resvar = 25;
  private static final int apply = 26;
  private static final int natcon = 27;
  private static final int realcon = 28;
  private static final int posint = 29;
  private static final int negint = 30;

  private void initParser() {
    Funs.put("AckEvent", new Integer(AckEvent));
    Funs.put("Assign", new Integer(Assign));
    Funs.put("Create", new Integer(Create));
    Funs.put("Delta", new Integer(Delta));
    Funs.put("Do", new Integer(Do));
    Funs.put("Eval", new Integer(Eval));
    Funs.put("Event", new Integer(Event));
    Funs.put("Print", new Integer(Print));
    Funs.put("RecMsg", new Integer(RecMsg));
    Funs.put("RecVal", new Integer(RecVal));
    Funs.put("ShutDown", new Integer(ShutDown));
    Funs.put("SndMsg", new Integer(SndMsg));
    Funs.put("Tau", new Integer(Tau));

    Funs.put("Alternative", new Integer(Alternative));
    Funs.put("Disrupt", new Integer(Disrupt));
    Funs.put("IfElse", new Integer(IfElse));
    Funs.put("IfThen", new Integer(IfThen));
    Funs.put("Iteration", new Integer(Iteration));
    Funs.put("LetDefinition", new Integer(LetDefinition));
    Funs.put("Merge", new Integer(Merge));
    Funs.put("ProcessCall", new Integer(ProcessCall));
    Funs.put("Sequence", new Integer(Sequence));
    Funs.put("ProcessDefinition", new Integer(ProcessDefinition));

    Funs.put("vardecl", new Integer(vardecl));
    Funs.put("resvardecl", new Integer(resvardecl));
    Funs.put("var", new Integer(var));
    Funs.put("resvar", new Integer(resvar));
    Funs.put("apply", new Integer(apply));
    Funs.put("natcon", new Integer(natcon));
    Funs.put("realcon", new Integer(realcon));
    Funs.put("posint", new Integer(posint));
    Funs.put("negint", new Integer(negint));

  }
  private ATerm mkSomeVar(String V, ATerm name, ATerm type) {
    AFun afun = factory.makeAFun(V, 3, false);
    ATerm cargs[] = new ATerm[] { factory.makeInt(-1), type, name };
    return factory.makeAppl(afun, cargs);
  }

  private ATerm mkVar(ATerm name, ATerm type) {
    return mkSomeVar("var", name, type);
  }

  private ATerm mkResVar(ATerm name, ATerm type) {
    return mkSomeVar("rvar", name, type);
  }

  private Object build(ATerm t) throws ToolBusException {

    switch (t.getType()) {
      case ATerm.BLOB :
      case ATerm.INT :
      case ATerm.PLACEHOLDER :
      case ATerm.REAL :
        return t;

      case ATerm.LIST :
        ATermList lst = t.getFactory().makeList();
        for (int i = 0; i < ((ATermList) t).getLength(); i++) {
          lst = lst.append((ATerm) build(((ATermList) t).elementAt(i)));
        }
        return lst;

      case ATerm.APPL :
        String name = ((ATermAppl) t).getName();
        ATerm args[] = ((ATermAppl) t).getArgumentArray();
        int index = ((Integer) Funs.get(name)).intValue();

        switch (index) {

          case vardecl : // vardecl(name, type) => var(-1,type,name)
            return mkVar(args[0], args[1]);
          case resvardecl : // resvardecl(name, type) => rvar(-1,type,name)
            return mkResVar(args[0], args[1]);
          case var : // var(name) => var(-1, -1, name)
            return mkVar(args[0], factory.make("none"));
          case resvar : // resvar(name) => rvar(-1, -1, name)
            return mkResVar(args[0], factory.make("none"));
          case apply : // apply(name, arglist)
            if (args.length != 2)
              throw new ToolBusException("apply: wrong number of args");

            ATermList args1 = (ATermList) args[1];
            String fname = ((ATermAppl) args[0]).getName();
            AFun afun = factory.makeAFun(fname, args1.getLength(), false);
            ATermList realargs = factory.makeList();

            for (int i = 0; i < args1.getLength(); i++) {
              realargs.append((ATerm) build(args1.elementAt(i)));
            }
            return factory.makeAppl(afun, realargs);

          case natcon : // natcon(str)
            return factory.makeInt(Integer.parseInt(((ATermAppl) args[0]).getName()));
          case realcon : // realcon(str, str)
          case posint : // posint(str)
          case negint : //negint(str)

          default :

            Object[] oargs = new Object[args.length];

            for (int i = 0; i < args.length; i++) {
              oargs[i] = build(args[i]);
            }
            switch (index) {

              case Alternative :
                return new Alternative((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);
              case Disrupt :
                return new Disrupt((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);
              case IfElse :
                return new IfElse((ATerm) oargs[0], (ProcessExpression) oargs[1], (ProcessExpression) oargs[2]);
              case IfThen :
                return new IfThen((ATerm) oargs[0], (ProcessExpression) oargs[1]);
              case Iteration :
                return new Iteration((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);
              case LetDefinition :
                return new LetDefinition((ATermList) oargs[0], (ProcessExpression) oargs[1]);

              case Merge :
                return new Merge((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);
        //      case ProcessCall :
       //         return new ProcessCall(((ATerm) oargs[0]), (ProcessExpression) oargs[1]);
        //      case ProcessDefinition :
        //        return new ProcessDefinition((ATerm) oargs[0], (ATermList) oargs[1], (ProcessExpression) oargs[2]);
              case Sequence :
                return new Sequence((ProcessExpression) oargs[0], (ProcessExpression) oargs[1]);
              case AckEvent :
                return new AckEvent((ATerm) oargs[0]);
              case Assign :
                return new Assign((ATerm) oargs[0], (ATerm) oargs[1]);
              case Create :
                return new Create((ATerm) oargs[0], (ATerm) oargs[1]);
              case Delta :
                return new Delta();
              case Do :
                return new Do((ATerm) oargs[0]);
          //    case Eval :
          //      return new Eval((ATerm) oargs[0], (ATerm) oargs[1]);
             case Event :
                return new Event((ATerm) oargs[0]);
              case Print :
                return new Print((ATerm) oargs[0]);
              case RecMsg :
                return new RecMsg((ATerm) oargs[0]);
              case RecVal :
                return new RecVal((ATerm) oargs[0]);
              case ShutDown :
                return new ShutDown((ATerm) oargs[0]);
              case SndMsg :
                return new SndMsg((ATerm) oargs[0]);
              case Tau :
                return new Tau();
                default: throw new ToolBusException("illegal symbol " + name);
            }

        }
    }
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

    ATerm args[] = ((ATermAppl) interm).getArgumentArray();

    ATermList decls = (ATermList) args[0];

    for (int i = 0; i < args.length; i++) {
      ProcessDefinition def = (ProcessDefinition) build(args[i]);
      addProcessDefinition(def);
    }
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
