package tide.tool.support;

import java.util.*;

import aterm.*;

public class DebugTool
  extends DebugToolTool
{
  private Map adapters;
  private List listeners;

  private Info info;

  //{{{ public DebugTool(ATermFactory factory)

  public DebugTool(ATermFactory factory)
  {
    super(factory);
    info = new Info("DebugTool");
    adapters  = new HashMap();
    listeners = new LinkedList();
  }

  //}}}

  //{{{ public void adapterConnected(ATerm dap)

  public void adapterConnected(ATerm dap)
  {
    info.info("adapterConnected: " + dap);

    DebugAdapter adapter = new DebugAdapter(this, dap);
    adapters.put(dap, adapter);
    fireAdapterConnected(adapter);
  }

  //}}}
  //{{{ public void adapterDisconnected(ATerm dap)

  public void adapterDisconnected(ATerm dap)
  {
    info.info("adapterDisconnected: " + dap);
    DebugAdapter adapter = findAdapter(dap);
    fireAdapterDisconnected(adapter);
    adapters.remove(dap);
  }

  //}}}
  
  //{{{ public void processCreated(ATerm proc, String name)

  public void processCreated(ATerm proc, String name)
  {
    info.info("processCreated: " + proc + " = " + name);

    ATerm dap = ((ATermAppl)proc).getArgument(0);
    int pid = ((ATermInt)((ATermAppl)proc).getArgument(1)).getInt();
    DebugAdapter adapter = findAdapter(dap);
    adapter.processCreated(pid, name);
  }

  //}}}
  //{{{ public void processDestroyed(ATerm proc)

  public void processDestroyed(ATerm proc)
  {
    info.info("processDestroyed: " + proc);
    ATerm dap = ((ATermAppl)proc).getArgument(0);
    int pid = ((ATermInt)((ATermAppl)proc).getArgument(1)).getInt();
    DebugAdapter adapter = findAdapter(dap);
    adapter.processDestroyed(pid);
  }

  //}}}

  //{{{ public void event(ATerm proc, int rid, ATerm result)

  public void event(ATerm proc, int rid, ATerm result)
  {
    info.info("event: " + proc + ", rid=" + rid + ", result=" + result);
    ATerm dap = ((ATermAppl)proc).getArgument(0);
    int pid = ((ATermInt)((ATermAppl)proc).getArgument(1)).getInt();
    DebugAdapter adapter = findAdapter(dap);
    adapter.event(pid, rid, result);
  }

  //}}}

  //{{{ public void recAckEvent(ATerm event)

  public void recAckEvent(ATerm event)
  {
    List result;

    info.info("recAckEvent: " + event);
    result = event.match("create-rule(proc(<term>,<int>),<term>,<term>," +
			 "<term>,<term>,<term>,<int>)");
    if (result != null) {
      //{{{ Handle rule creation

      DebugAdapter adapter = findAdapter((ATerm)result.get(0));
      int  pid  = ((Integer)result.get(1)).intValue();
      Port port = Port.fromTerm((ATerm)result.get(2));
      Expr cond = Expr.fromTerm((ATerm)result.get(3));
      Expr act  = Expr.fromTerm((ATerm)result.get(4));
      String tag = result.get(5).toString();
      boolean enabled = result.get(6).equals(factory.parse("true"));
      int  rid  = ((Integer)result.get(7)).intValue();
      Rule rule = new Rule(rid, port, cond, act, tag, enabled);
      adapter.ruleCreated(pid, rule);

      //}}}
      return;
    }

    result = event.match("delete-rule(proc(<term>,<int>),<int>)");
    if (result != null) {
      //{{{ Handle rule deletion

      DebugAdapter adapter = findAdapter((ATerm)result.get(0));
      int pid = ((Integer)result.get(1)).intValue();
      int rid = ((Integer)result.get(2)).intValue();
      adapter.ruleDeleted(pid, rid);

      //}}}
      return;
    }

    result = event.match("modify-rule(proc(<term>,<int>),<int>,<term>,<term>,"
			 + "<term>,<term>)");
    if (result != null) {
      //{{{ Handle rule modification

      int arg = 0;
      DebugAdapter adapter = findAdapter((ATerm)result.get(arg++));
      int  pid  = ((Integer)result.get(arg++)).intValue();
      int  rid  = ((Integer)result.get(arg++)).intValue();
      Port port = Port.fromTerm((ATerm)result.get(arg++));
      Expr cond = Expr.fromTerm((ATerm)result.get(arg++));
      Expr act  = Expr.fromTerm((ATerm)result.get(arg++));
      boolean enabled = result.get(arg++).equals(factory.parse("true"));
      adapter.ruleModified(pid, rid, port, cond, act, enabled);

      //}}}
      return;
    }
  }

  //}}}
  //{{{ public void recTerminate(ATerm msg)

  public void recTerminate(ATerm msg)
  {
  }

  //}}}

  //{{{ public void addDebugToolListener(DebugToolListener listener)

  public void addDebugToolListener(DebugToolListener listener)
  {
    listeners.add(listener);
  }

  //}}}
  //{{{ public void removeDebugToolListener(DebugToolListener listener)

  public void removeDebugToolListener(DebugToolListener listener)
  {
    listeners.remove(listener);
  }

  //}}}

  //{{{ private DebugAdapter findAdapter(ATerm dap)

  private DebugAdapter findAdapter(ATerm dap)
  {
    return (DebugAdapter)adapters.get(dap);
  }

  //}}}
  //{{{ private void fireAdapterConnected(DebugAdapter adapter)

  private void fireAdapterConnected(DebugAdapter adapter)
  {
    DebugToolListener listener;

    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      listener = (DebugToolListener)iter.next();
      listener.adapterConnected(this, adapter);
    }
  }

  //}}}
  //{{{ private void fireAdapterDisconnected(DebugAdapter adapter)

  private void fireAdapterDisconnected(DebugAdapter adapter)
  {
    DebugToolListener listener;

    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      listener = (DebugToolListener)iter.next();
      listener.adapterDisconnected(this, adapter);
    }
  }

  //}}}

  //{{{ public void requestRuleCreation(dap, pid, port, cond, act, tag, enabled)

  public void requestRuleCreation(ATerm dap, int pid, Port port,
				  Expr cond, Expr act, String tag,
				  boolean enabled)
  {
    String pat =
      "create-rule(proc(<term>,<int>),<term>,<term>,<term>,<term>,<term>)";
    ATerm event = factory.make(pat, dap, new Integer(pid),
			       port.toTerm(factory), cond.toTerm(factory),
			       act.toTerm(factory), factory.parse(tag),
			       factory.parse(enabled ? "true" : "false"));

    info.info("requesting rule creation: " + event);

    postEvent(event);
  }

  //}}}
  //{{{ public void requestRuleDeletion(ATerm dap, int pid, Rule rule)

  public void requestRuleDeletion(ATerm dap, int pid, Rule rule)
  {
    ATerm event = factory.make("delete-rule(proc(<term>,<int>),<int>)",
			       dap, new Integer(pid), new Integer(rule.getRid()));
    postEvent(event);
  }

  //}}}
  //{{{ public void requestRuleModification(dap, pid, rule, port, cond, act, enabled)

  public void requestRuleModification(ATerm dap, int pid, Rule rule, Port port,
				      Expr cond, Expr act, boolean enabled)
  {
    String pat =
      "modify-rule(proc(<term>,<int>),<int>,<term>,<term>,<term>,<term>)";
    ATerm event = factory.make(pat, dap, new Integer(pid),
			       new Integer(rule.getRid()),
			       port.toTerm(factory),
			       cond.toTerm(factory),
			       act.toTerm(factory), 
			       factory.parse(enabled ? "true" : "false"));

    info.info("requesting rule modification: " + event);

    postEvent(event);
  }

  //}}}
  //{{{ public void requestBreak(ATerm dap, int pid)

  public void requestBreak(ATerm dap, int pid)
  {
    ATerm event = factory.make("evaluate(proc(<term>,<int>),break)",
			       dap, new Integer(pid));
    info.info("request break: " + event);
    postEvent(event);
  }

  //}}}
  //{{{ public void requestResume(ATerm dap, int pid)

  public void requestResume(ATerm dap, int pid)
  {
    ATerm event = factory.make("evaluate(proc(<term>,<int>),resume)",
			       dap, new Integer(pid));
    info.info("request resume: " + event);
    postEvent(event);
  }

  //}}}
}
