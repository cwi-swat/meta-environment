package tide.tool.support;

import java.util.*;

import aterm.*;

public class DebugProcess
{
  public static final String[] PORT_TYPES = 
  {
    "step", "stopped", "started"
  };

  private static final String TAG_STARTED = "process-started";
  private static final String TAG_STOPPED = "process-stopped";

  private DebugAdapter adapter;
  private int pid;
  private String name;
  private Rule started;
  private Rule stopped;

  private List rules;
  private Map  ruleTable;

  private int running;

  private List statusChangeListeners;
  private List processListeners;

  private Info info;

  //{{{ public DebugProcess(DebugAdapter adapter, int pid)

  public DebugProcess(DebugAdapter adapter, int pid, String name)
  {
    this.adapter = adapter;
    this.pid     = pid;
    this.name    = name;

    info = new Info("DebugProcess");

    statusChangeListeners = new LinkedList();
    processListeners      = new LinkedList();

    requestRuleCreation(Port.makeStarted(), Expr.makeTrue(),
			Expr.makeTrue(), TAG_STARTED);
    requestRuleCreation(Port.makeStopped(), Expr.makeTrue(),
			Expr.makeTrue(), TAG_STOPPED);

    rules = new LinkedList();
    ruleTable = new HashMap();
  }

  //}}}

  //{{{ public void addProcessStatusChangeListener(ProcessStatusChangeListener listener)

  public void addProcessStatusChangeListener(ProcessStatusChangeListener listener)
  {
    statusChangeListeners.add(listener);
  }

  //}}}
  //{{{ public void removeProcessStatusChangeListener(ProcessStatusChangeListener listener)

  public void removeProcessStatusChangeListener(ProcessStatusChangeListener listener)
  {
    statusChangeListeners.remove(listener);
  }

  //}}}
  //{{{ public void fireProcessStatusChanged()

  public void fireProcessStatusChanged()
  {
    Iterator iter = statusChangeListeners.iterator();

    while (iter.hasNext()) {
      ProcessStatusChangeListener listener = (ProcessStatusChangeListener)iter.next();
      listener.processStatusChanged(this);
    }
  }

  //}}}

  //{{{ public void addDebugProcessListener(DebugProcessListener listener)

  public void addDebugProcessListener(DebugProcessListener listener)
  {
    processListeners.add(listener);
  }

  //}}}
  //{{{ public void removeDebugProcessListener(DebugProcessListener listener)

  public void removeDebugProcessListener(DebugProcessListener listener)
  {
    processListeners.remove(listener);
  }

  //}}}
  //{{{ public void fireRuleCreated(Rule rule)

  public void fireRuleCreated(Rule rule)
  {
    Iterator iter = processListeners.iterator();

    while (iter.hasNext()) {
      DebugProcessListener listener = (DebugProcessListener)iter.next();
      listener.ruleCreated(this, rule);
    }
  }

  //}}}
  //{{{ public void fireRuleDeleted(Rule rule)

  public void fireRuleDeleted(Rule rule)
  {
    Iterator iter = processListeners.iterator();

    while (iter.hasNext()) {
      DebugProcessListener listener = (DebugProcessListener)iter.next();
      listener.ruleDeleted(this, rule);
    }
  }

  //}}}
  //{{{ public void fireRuleModified(Rule rule)

  public void fireRuleModified(Rule rule)
  {
    Iterator iter = processListeners.iterator();

    while (iter.hasNext()) {
      DebugProcessListener listener = (DebugProcessListener)iter.next();
      listener.ruleModified(this, rule);
    }
  }

  //}}}

  //{{{ public String getName()

  public String getName()
  {
    return name;
  }

  //}}}
  //{{{ public int getPid()

  public int getPid()
  {
    return pid;
  }

  //}}}
  //{{{ public boolean isRunning()

  public boolean isRunning()
  {
    return running > 0;
  }

  //}}}

  //{{{ public void ruleCreated(Rule rule)

  public void ruleCreated(Rule rule)
  {
    info.info("ruleCreated: " + rule);

    if (rule.getTag().equals(TAG_STARTED)) {
      started = rule;
    }

    if (rule.getTag().equals(TAG_STOPPED)) {
      stopped = rule;
    }

    rules.add(rule);
    ruleTable.put(new Integer(rule.getRid()), rule);

    fireRuleCreated(rule);
  }

  //}}}
  //{{{ public void ruleDeleted(int rid)

  public void ruleDeleted(int rid)
  {
    Integer ridKey = new Integer(rid);

    Rule rule = (Rule)ruleTable.get(ridKey);
    fireRuleDeleted(rule);

    rules.remove(rule);
    ruleTable.remove(ridKey);

    if (rule == stopped) {
      stopped = null;
    } else if (rule == started) {
      started = null;
    }
  }

  //}}}
  //{{{ public void ruleModified(int rid, Expr cond, Expr action, boolean enabled)

  public void ruleModified(int rid, Port port, Expr cond, Expr action, boolean enabled)
  {
    Integer ridKey = new Integer(rid);

    Rule rule = (Rule)ruleTable.get(ridKey);

    rule.modify(port, cond, action, enabled);

    fireRuleModified(rule);
  }

  //}}}

  //{{{ public Iterator ruleIterator()

  public Iterator ruleIterator()
  {
    return rules.iterator();
  }

  //}}}
  //{{{ public int getNrOfRules()

  public int getNrOfRules()
  {
    return rules.size();
  }

  //}}}
  //{{{ public Rule getRuleAt(int index)

  public Rule getRuleAt(int index)
  {
    return (Rule)rules.get(index);
  }

  //}}}
  //{{{ public int getRuleIndex(Rule rule)

  public int getRuleIndex(Rule rule)
  {
    return rules.indexOf(rule);
  }

  //}}}

  //{{{ public void event(int rid, ATerm result)

  public void event(int rid, ATerm result)
  {
    if (rid == started.getRid()) {
      running++;
      if (running == 1) {
	fireProcessStatusChanged();
      }
    } else if (rid == stopped.getRid()) {
      running--;
      if (running == 0) {
	fireProcessStatusChanged();
      }
    }
  }

  //}}}

  //{{{ public void requestRuleCreation(port, cond, act, tag)

  public void requestRuleCreation(Port port, Expr cond, Expr act,
				  String tag)
  {
    adapter.requestRuleCreation(pid, port, cond, act, tag, true);
  }

  //}}}
  //{{{ public void requestRuleCreation(port, cond, act, tag, enabled)

  public void requestRuleCreation(Port port, Expr cond, Expr act,
				  String tag, boolean enabled)
  {
    adapter.requestRuleCreation(pid, port, cond, act, tag, enabled);
  }

  //}}}
  //{{{ public void requestRuleModification(rule, port, cond, act, enabled)

  public void requestRuleModification(Rule rule, Port port, Expr cond, Expr act,
				      boolean enabled)
  {
    adapter.requestRuleModification(pid, rule, port, cond, act, enabled);
  }

  //}}}
  //{{{ public void requestRuleDeletion(Rule rule)

  public void requestRuleDeletion(Rule rule)
  {
    adapter.requestRuleDeletion(pid, rule);
  }

  //}}}
  //{{{ public void requestBreak()

  public void requestBreak()
  {
    adapter.requestBreak(pid);
  }

  //}}}
  //{{{ public void requestResume()

  public void requestResume()
  {
    adapter.requestResume(pid);
  }

  //}}}
}
