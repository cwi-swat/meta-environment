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
    DebugProcess proc = findProcess(pid);
    proc.event(rid, result);
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
    tool.requestResume(dap, pid);
  }

  //}}}
}

