package tide.tool.support;

import aterm.*;

import java.util.*;

public class DebugAdapter
{
  private DebugTool tool;
  private ATerm dap;
  private Map processes;
  private List listeners;
  private Info info;

  //{{{ public DebugAdapter(ATerm dap)

  public DebugAdapter(DebugTool tool, ATerm dap)
  {
    this.tool = tool;
    this.dap = dap;
    processes = new HashMap();
    listeners = new LinkedList();
    info = new Info("DebugAdapter");
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return dap.toString();
  }

  //}}}
  //{{{ public void event(int pid, int rid, ATerm result)

  public void event(int pid, int rid, ATerm result)
  {
/*
    Set keys = processes.keySet();
    Collection values = processes.values();

    Iterator itkeys = keys.iterator();
    Iterator itvalues = values.iterator();


    System.out.println("<---------------- process listing (dap = "+this.getName()+") ------------------>");
    while (itkeys.hasNext()) {
      System.out.println("--- key: "+itkeys.next());
    }
    while (itvalues.hasNext()) {
      DebugProcess procje = (DebugProcess) itvalues.next();
      System.out.println("--- val: "+procje.getName());
    }
*/
    DebugProcess proc = findProcess(pid);
/*
    if (proc==null) {
		 System.out.println("shiiiiiiiiiiiiiiiiiiiiiiiiiiiit geen proc\n");
	 }
    System.out.println("<-------------------------------------------------------->");
//	 System.out.println("[DebugAdapter] event() process: "+proc.getName()+", rid: "+rid+", result: "+result);
*/
    proc.event(rid, result);
  }

  //}}}

  //{{{ public void removeAllProcesses()

  public void removeAllProcesses()
  {
    Iterator iter = processes.values().iterator();
    while (iter.hasNext()) {
      DebugProcess process = (DebugProcess)iter.next();
      fireProcessDestroyed(process);
    }
    processes.clear();
  }

  //}}}
  //{{{ public void addDebugAdapterListener(DebugAdapterListener listener)

  public void addDebugAdapterListener(DebugAdapterListener listener)
  {
    listeners.add(listener);
  }

  //}}}
  //{{{ public void removeDebugAdapterListener(DebugAdapterListener listener)

  public void removeDebugAdapterListener(DebugAdapterListener listener)
  {
    listeners.remove(listener);
  }

  //}}}

  //{{{ private DebugProcess findProcess(int pid)

  private DebugProcess findProcess(int pid)
  {
    return (DebugProcess)processes.get(new Integer(pid));
  }

  //}}}

  //{{{ public void processCreated(int pid, String name)

  public void processCreated(int pid, String name)
  {
    DebugProcess proc = new DebugProcess(this, pid, name);
    processes.put(new Integer(pid), proc);
    fireProcessCreated(proc);
  }

  //}}}
  //{{{ private void fireProcessCreated(DebugProcess proc)

  private void fireProcessCreated(DebugProcess proc)
  {
    DebugAdapterListener listener;

    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      listener = (DebugAdapterListener)iter.next();
      listener.processCreated(this, proc);
    }
  }

  //}}}

  //{{{ public void processDestroyed(int pid)

  public void processDestroyed(int pid)
  {
    DebugProcess proc = findProcess(pid);
    fireProcessDestroyed(proc);
	 System.out.println("===================================================== "+pid+","+proc.getName()+" DESTROYED ==============================================");
    processes.remove(new Integer(pid));
  }

  //}}}
  //{{{ private void fireProcessDestroyed(DebugProcess proc)

  private void fireProcessDestroyed(DebugProcess proc)
  {
    DebugAdapterListener listener;

    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      listener = (DebugAdapterListener)iter.next();
      listener.processDestroyed(this, proc);
    }
  }

  //}}}

  //{{{ public void ruleCreated(int pid, Rule rule)

  public void ruleCreated(int pid, Rule rule)
  {
    DebugProcess process = findProcess(pid);
    process.ruleCreated(rule);
  }

  //}}}
  //{{{ public void ruleDeleted(int pid, int rid)

  public void ruleDeleted(int pid, int rid)
  {
    DebugProcess process = findProcess(pid);
    process.ruleDeleted(rid);
  }

  //}}}
  //{{{ public void ruleModified(int pid, int rid, port, cond, action, enabled)

  public void ruleModified(int pid, int rid, Port port, Expr cond, Expr action,
			   boolean enabled)
  {
    DebugProcess process = findProcess(pid);
    process.ruleModified(rid, port, cond, action, enabled);
  }

  //}}}

  //{{{ public void evaluationResult(pid, expr, value, tag)

  public void evaluationResult(int pid, Expr expr, Expr value,
			       String tag)
  {
    DebugProcess process = findProcess(pid);
    process.evaluationResult(expr, value, tag);
  }

  //}}}

  //{{{ public void requestRuleCreation(pid, port, cond, act, tag)

  public void requestRuleCreation(int pid, Port port,
				  Expr cond, Expr act,
				  String tag, boolean enabled)
  {
    tool.requestRuleCreation(dap, pid, port, cond, act, tag, enabled);
  }

  //}}}
  //{{{ public void requestRuleDeletion(int pid, Rule rule)

  public void requestRuleDeletion(int pid, Rule rule)
  {
    tool.requestRuleDeletion(dap, pid, rule);
  }

  //}}}
  //{{{ public void requestRuleModification(pid, rule, port, cond, act, enabled)

  public void requestRuleModification(int pid, Rule rule, Port port, Expr cond,
				      Expr act, boolean enabled)
  {
    tool.requestRuleModification(dap, pid, rule, port, cond, act, enabled);
  }

  //}}}
  //{{{ public void requestBreak(int pid)

  public void requestBreak(int pid)
  {
    tool.requestBreak(dap, pid);
  }

  //}}}
  //{{{ public void requestResume(int pid)

  public void requestResume(int pid)
  {
    info.info("requestResume: " + pid);
    tool.requestResume(dap, pid);
  }

  //}}}
  //{{{ public void requestEvaluation(int pid, Expr expr, String tag)

  public void requestEvaluation(int pid, Expr expr, String tag)
  {
    info.info("requestEvaluation: " + pid + "," + expr + "," + tag);
    tool.requestEvaluation(dap, pid, expr, tag);
  }

  //}}}
}

