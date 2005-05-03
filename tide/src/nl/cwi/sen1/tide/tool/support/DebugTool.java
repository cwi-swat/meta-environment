package nl.cwi.sen1.tide.tool.support;

import java.util.*;

import aterm.*;

public class DebugTool extends DebugToolTool {
	private Map adapters;
	private List listeners;

	private Info info;

	//{{{ public DebugTool(ATermFactory factory)

	public DebugTool(ATermFactory factory) {
		super(factory);
		info = new Info("DebugTool");
		adapters = new HashMap();
		listeners = new LinkedList();
	}

	//}}}

	//{{{ public void adapterConnected(ATerm dap)

	public void adapterConnected(ATerm dap) {
		info.info("adapterConnected: " + dap);

		DebugAdapter adapter = new DebugAdapter(this, dap);
		adapters.put(dap, adapter);
		fireAdapterConnected(adapter);
	}

	//}}}
	//{{{ public void adapterDisconnected(ATerm dap)

	public void adapterDisconnected(ATerm dap) {
		info.info("adapterDisconnected: " + dap);
		DebugAdapter adapter = findAdapter(dap);

		adapter.removeAllProcesses();
		fireAdapterDisconnected(adapter);
		adapters.remove(dap);
	}

	//}}}

	//{{{ public void processCreated(ATerm proc, String name)

	public void processCreated(ATerm proc, String name) {
		info.info("processCreated: " + proc + " = " + name);

		ATerm dap = ((ATermAppl) proc).getArgument(0);
		int pid = ((ATermInt) ((ATermAppl) proc).getArgument(1)).getInt();
		DebugAdapter adapter = findAdapter(dap);
		adapter.processCreated(pid, name);
	}

	//}}}
	//{{{ public void processDestroyed(ATerm proc)

	public void processDestroyed(ATerm proc) {
		info.info("processDestroyed: " + proc);
		ATerm dap = ((ATermAppl) proc).getArgument(0);
		int pid = ((ATermInt) ((ATermAppl) proc).getArgument(1)).getInt();
		DebugAdapter adapter = findAdapter(dap);
		adapter.processDestroyed(pid);
	}

	//}}}

	//{{{ public void event(ATerm proc, int rid, ATerm result)

	public void event(ATerm proc, int rid, ATerm result) {
		info.info("event: " + proc + ", rid=" + rid + ", result=" + result);
		ATerm dap = ((ATermAppl) proc).getArgument(0);
		int pid = ((ATermInt) ((ATermAppl) proc).getArgument(1)).getInt();
		DebugAdapter adapter = findAdapter(dap);
		adapter.event(pid, rid, result);
	}

	//}}}

	//{{{ public void recAckEvent(ATerm event)

	public void recAckEvent(ATerm event) {
		List result;

		info.info("recAckEvent: " + event);

		result =
			event.match("evaluate(proc(<term>,<int>),<term>,<term>,<term>))");
		if (result != null) {
			handleEvaluationResults(result);
			return;
		}

		result =
			event.match(
				"create-rule(proc(<term>,<int>),<term>,<term>,"
					+ "<term>,<term>,<term>,<int>)");
		if (result != null) {
			handleRuleCreation(result);
			return;
		}

		result = event.match("delete-rule(proc(<term>,<int>),<int>)");
		if (result != null) {
			handleRuleDeletion(result);
			return;
		}

		result =
			event.match(
				"modify-rule(proc(<term>,<int>),<int>,<term>,<term>,"
					+ "<term>,<term>)");
		if (result != null) {
			handleRuleModification(result);
			return;
		}
	}

	//}}}
	//{{{ public void recTerminate(ATerm msg)

	private void handleEvaluationResults(List result) {
		int index = 0;

		DebugAdapter adapter = findAdapter((ATerm) result.get(index++));
		int pid = ((Integer) result.get(index++)).intValue();
		Expr expr = Expr.fromTerm((ATerm) result.get(index++));
		String tag = result.get(index++).toString();
		Expr value = Expr.fromTerm((ATerm) result.get(index++));
		adapter.evaluationResult(pid, expr, value, tag);
	}

	private void handleRuleCreation(List result) {
		DebugAdapter adapter = findAdapter((ATerm) result.get(0));
		int pid = ((Integer) result.get(1)).intValue();
		Port port = Port.fromTerm((ATerm) result.get(2));
		Expr cond = Expr.fromTerm((ATerm) result.get(3));
		Expr act = Expr.fromTerm((ATerm) result.get(4));
		String tag = result.get(5).toString();
		boolean enabled = result.get(6).equals(factory.parse("true"));
		int rid = ((Integer) result.get(7)).intValue();
		Rule rule = new Rule(rid, port, cond, act, tag, enabled);
		adapter.ruleCreated(pid, rule);
	}

	private void handleRuleModification(List result) {
		int arg = 0;
		DebugAdapter adapter = findAdapter((ATerm) result.get(arg++));
		int pid = ((Integer) result.get(arg++)).intValue();
		int rid = ((Integer) result.get(arg++)).intValue();
		Port port = Port.fromTerm((ATerm) result.get(arg++));
		Expr cond = Expr.fromTerm((ATerm) result.get(arg++));
		Expr act = Expr.fromTerm((ATerm) result.get(arg++));
		boolean enabled = result.get(arg++).equals(factory.parse("true"));
		adapter.ruleModified(pid, rid, port, cond, act, enabled);

		//}}}
		return;
	}

	private void handleRuleDeletion(List result) {
		DebugAdapter adapter = findAdapter((ATerm) result.get(0));
		int pid = ((Integer) result.get(1)).intValue();
		int rid = ((Integer) result.get(2)).intValue();
		adapter.ruleDeleted(pid, rid);
	}

	public void recTerminate(ATerm msg) {
	}

	public void addDebugToolListener(DebugToolListener listener) {
		listeners.add(listener);
	}

	public void removeDebugToolListener(DebugToolListener listener) {
		listeners.remove(listener);
	}

	private DebugAdapter findAdapter(ATerm dap) {
		return (DebugAdapter) adapters.get(dap);
	}

	private void fireAdapterConnected(DebugAdapter adapter) {
		DebugToolListener listener;

		Iterator iter = listeners.iterator();
		while (iter.hasNext()) {
			listener = (DebugToolListener) iter.next();
			listener.adapterConnected(this, adapter);
		}
	}

	private void fireAdapterDisconnected(DebugAdapter adapter) {
		DebugToolListener listener;

		Iterator iter = listeners.iterator();
		while (iter.hasNext()) {
			listener = (DebugToolListener) iter.next();
			listener.adapterDisconnected(this, adapter);
		}
	}

	public void requestRuleCreation(
		ATerm dap,
		int pid,
		Port port,
		Expr cond,
		Expr act,
		String tag,
		boolean enabled) {
		String pat =
			"create-rule(proc(<term>,<int>),<term>,<term>,<term>,<term>,<term>)";
		ATerm event =
			factory.make(
				pat,
				dap,
				new Integer(pid),
				port.toTerm(),
				cond.toTerm(),
				act.toTerm(),
				factory.parse(tag),
				factory.parse(enabled ? "true" : "false"));

		info.info("requesting rule creation: " + event);
		postEvent(event);
	}

	public void requestRuleDeletion(ATerm dap, int pid, Rule rule) {
		ATerm event =
			factory.make(
				"delete-rule(proc(<term>,<int>),<int>)",
				dap,
				new Integer(pid),
				new Integer(rule.getRid()));
		postEvent(event);
	}

	public void requestRuleModification(
		ATerm dap,
		int pid,
		Rule rule,
		Port port,
		Expr cond,
		Expr act,
		boolean enabled) {
		String pat =
			"modify-rule(proc(<term>,<int>),<int>,<term>,<term>,<term>,<term>)";
		ATerm event =
			factory.make(
				pat,
				dap,
				new Integer(pid),
				new Integer(rule.getRid()),
				port.toTerm(),
				cond.toTerm(),
				act.toTerm(),
				factory.parse(enabled ? "true" : "false"));

		info.info("requesting rule modification: " + event);
		postEvent(event);
	}

	public void requestBreak(ATerm dap, int pid) {
		ATerm event =
			factory.make(
				"evaluate(proc(<term>,<int>),break,tag-break)",
				dap,
				new Integer(pid));
		info.info("request break: " + event);
		postEvent(event);
	}

	public void requestResume(ATerm dap, int pid) {
		ATerm event =
			factory.make(
				"evaluate(proc(<term>,<int>),resume,tag-resume)",
				dap,
				new Integer(pid));
		info.info("request resume: " + event);
		postEvent(event);
	}

	public void requestEvaluation(ATerm dap, int pid, Expr expr, String tag) {
		ATerm event =
			factory.make(
				"evaluate(proc(<term>,<int>),<term>,<term>)",
				dap,
				new Integer(pid),
				expr.toTerm(),
				factory.parse(tag));
		info.info("request evaluation: " + event);
		postEvent(event);
	}
}
