package tide.tool.support;

import java.util.*;

import aterm.*;

public class DebugProcess {
	public static final String[] PORT_TYPES = { "step", "stopped", "started" };

	private static final String TAG_STARTED = "process-started";
	private static final String TAG_STOPPED = "process-stopped";
	private static final String TAG_INITIAL_CPE = "initial-cpe";

	private static int next_id;
	private int id;
	private String tag_started;
	private String tag_stopped;
	private String tag_initial_cpe;

	private DebugAdapter adapter;
	private int pid;
	private String name;
	private Rule started;
	private Rule stopped;

	private List rules;
	private Map ruleTable;

	private int running;
	private Expr lastLocation;

	private List statusChangeListeners;
	private List processListeners;

	private Info info;

	//{{{ public DebugProcess(DebugAdapter adapter, int pid)

	public DebugProcess(DebugAdapter adapter, int pid, String name) {
		this.id = next_id++;
		this.adapter = adapter;
		this.pid = pid;
		this.name = name;

		tag_started = TAG_STARTED + "-" + id;
		tag_stopped = TAG_STOPPED + "-" + id;
		tag_initial_cpe = TAG_INITIAL_CPE + "-" + id;

		info = new Info("DebugProcess");

		statusChangeListeners = new LinkedList();
		processListeners = new LinkedList();

		requestRuleCreation(
			Port.makeStarted(),
			Expr.makeTrue(),
			Expr.makeTrue(),
			tag_started);
		requestRuleCreation(
			Port.makeStopped(),
			Expr.makeTrue(),
			Expr.makeCpe(),
			tag_stopped);
		requestEvaluation(Expr.makeCpe(), tag_initial_cpe);

		rules = new LinkedList();
		ruleTable = new HashMap();
	}

	//}}}

	//{{{ public DebugAdapter getAdapter()

	public DebugAdapter getAdapter() {
		return adapter;
	}

	//}}}

	//{{{ public void
	// addProcessStatusChangeListener(ProcessStatusChangeListener listener)

	public void addProcessStatusChangeListener(ProcessStatusChangeListener listener) {
		statusChangeListeners.add(listener);
	}

	//}}}
	//{{{ public void
	// removeProcessStatusChangeListener(ProcessStatusChangeListener listener)

	public void removeProcessStatusChangeListener(ProcessStatusChangeListener listener) {
		statusChangeListeners.remove(listener);
	}

	//}}}
	//{{{ public void fireProcessStatusChanged()

	public void fireProcessStatusChanged() {
		Iterator iter = statusChangeListeners.iterator();

		while (iter.hasNext()) {
			ProcessStatusChangeListener listener =
				(ProcessStatusChangeListener) iter.next();
			listener.processStatusChanged(this);
		}
	}

	//}}}

	//{{{ public void addDebugProcessListener(DebugProcessListener listener)

	public void addDebugProcessListener(DebugProcessListener listener) {
		processListeners.add(listener);
	}

	//}}}
	//{{{ public void removeDebugProcessListener(DebugProcessListener
	// listener)

	public void removeDebugProcessListener(DebugProcessListener listener) {
		processListeners.remove(listener);
	}

	//}}}
	//{{{ public void fireRuleCreated(Rule rule)

	public void fireRuleCreated(Rule rule) {
		Iterator iter =
			((List) ((LinkedList) processListeners).clone()).iterator();

		while (iter.hasNext()) {
			DebugProcessListener listener = (DebugProcessListener) iter.next();
			listener.ruleCreated(this, rule);
		}
	}

	//}}}
	//{{{ public void fireRuleDeleted(Rule rule)

	public void fireRuleDeleted(Rule rule) {
		Iterator iter =
			((List) ((LinkedList) processListeners).clone()).iterator();

		while (iter.hasNext()) {
			DebugProcessListener listener = (DebugProcessListener) iter.next();
			listener.ruleDeleted(this, rule);
		}
	}

	//}}}
	//{{{ public void fireRuleModified(Rule rule)

	public void fireRuleModified(Rule rule) {
		Iterator iter =
			((List) ((LinkedList) processListeners).clone()).iterator();

		while (iter.hasNext()) {
			DebugProcessListener listener = (DebugProcessListener) iter.next();
			listener.ruleModified(this, rule);
		}
	}

	//}}}
	//{{{ public void fireRuleTriggered(Rule rule, Expr value)

	public void fireRuleTriggered(Rule rule, Expr value) {
		Iterator iter =
			((List) ((LinkedList) processListeners).clone()).iterator();

		while (iter.hasNext()) {
			DebugProcessListener listener = (DebugProcessListener) iter.next();
			listener.ruleTriggered(this, rule, value);
		}
	}

	//}}}
	//{{{ public void fireEvaluationResult(Expr expr, Expr value, String tag)

	public void fireEvaluationResult(Expr expr, Expr value, String tag) {
		Iterator iter =
			((List) ((LinkedList) processListeners).clone()).iterator();

		while (iter.hasNext()) {
			DebugProcessListener listener = (DebugProcessListener) iter.next();
			listener.evaluationResult(this, expr, value, tag);
		}
	}

	//}}}

	//{{{ public String getName()

	public String getName() {
		return name;
	}

	//}}}
	//{{{ public int getPid()

	public int getPid() {
		return pid;
	}

	//}}}
	//{{{ public boolean isRunning()

	public boolean isRunning() {
		return running > 0;
	}

	//}}}
	//{{{ public boolean isStopped()

	public boolean isStopped() {
		return running <= 0;
	}

	//}}}
	//{{{ public Expr getLastLocation()

	public Expr getLastLocation() {
		return lastLocation;
	}

	//}}}

	//{{{ public void ruleCreated(Rule rule)

	synchronized public void ruleCreated(Rule rule) {
		info.info("ruleCreated: " + rule);

		if (rule.getTag().equals(tag_started)) {
			started = rule;
		}

		if (rule.getTag().equals(tag_stopped)) {
			stopped = rule;
		}

		rules.add(rule);
		ruleTable.put(new Integer(rule.getRid()), rule);

		fireRuleCreated(rule);
	}

	//}}}
	//{{{ public void ruleDeleted(int rid)

	synchronized public void ruleDeleted(int rid) {
		Integer ridKey = new Integer(rid);

		Rule rule = (Rule) ruleTable.get(ridKey);
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
	//{{{ public void ruleModified(int rid, Expr cond, Expr action, boolean
	// enabled)

	public void ruleModified(
		int rid,
		Port port,
		Expr cond,
		Expr action,
		boolean enabled) {
		Integer ridKey = new Integer(rid);

		Rule rule = (Rule) ruleTable.get(ridKey);

		rule.modify(port, cond, action, enabled);

		fireRuleModified(rule);
	}

	//}}}

	//{{{ public void evaluationResult(Expr expr, Expr value, String tag)

	public void evaluationResult(Expr expr, Expr value, String tag) {
		if (tag.equals(tag_initial_cpe)) {
			lastLocation = value;
		}
		fireEvaluationResult(expr, value, tag);
	}

	//}}}

	//{{{ public Iterator ruleIterator()

	public Iterator ruleIterator() {
		return rules.iterator();
	}

	//}}}
	//{{{ public int getNrOfRules()

	public int getNrOfRules() {
		return rules.size();
	}

	//}}}
	//{{{ public Rule getRuleAt(int index)

	public Rule getRuleAt(int index) {
		return (Rule) rules.get(index);
	}

	//}}}
	//{{{ public int getRuleIndex(Rule rule)

	public int getRuleIndex(Rule rule) {
		return rules.indexOf(rule);
	}

	//}}}

	//{{{ public void event(int rid, ATerm result)

	public void event(int rid, ATerm result) {
		info.info("event: " + result);

		Rule rule = (Rule) ruleTable.get(new Integer(rid));
		Expr value = Expr.fromTerm(result);

		fireRuleTriggered(rule, value);
		if (rule == started) {
			running++;
			info.info("rule == started, running = " + running);
			if (running == 1) {
				fireProcessStatusChanged();
			}
		} else if (rule == stopped) {
			running--;
			info.info("rule == stopped, running = " + running);
			if (running == 0) {
				info.info("running is now 0, firing processStatusChanged");
				lastLocation = value;
				fireProcessStatusChanged();
			}
		}
	}

	//}}}

	//{{{ public void requestRuleCreation(port, cond, act, tag)

	public void requestRuleCreation(
		Port port,
		Expr cond,
		Expr act,
		String tag) {
		adapter.requestRuleCreation(pid, port, cond, act, tag, true);
	}

	//}}}
	//{{{ public void requestRuleCreation(port, cond, act, tag, enabled)

	public void requestRuleCreation(
		Port port,
		Expr cond,
		Expr act,
		String tag,
		boolean enabled) {
		adapter.requestRuleCreation(pid, port, cond, act, tag, enabled);
	}

	//}}}
	//{{{ public void requestRuleModification(rule, port, cond, act, enabled)

	public void requestRuleModification(
		Rule rule,
		Port port,
		Expr cond,
		Expr act,
		boolean enabled) {
		adapter.requestRuleModification(pid, rule, port, cond, act, enabled);
	}

	//}}}
	//{{{ public void requestRuleDeletion(Rule rule)

	public void requestRuleDeletion(Rule rule) {
		adapter.requestRuleDeletion(pid, rule);
	}

	//}}}
	//{{{ public void requestRuleEnabling(Rule rule, boolean enabled)

	public void requestRuleEnabling(Rule rule, boolean enabled) {
		requestRuleModification(
			rule,
			rule.getPort(),
			rule.getCondition(),
			rule.getAction(),
			enabled);
	}

	//}}}
	//{{{ public void requestBreak()

	public void requestBreak() {
		adapter.requestBreak(pid);
	}

	//}}}
	//{{{ public void requestResume()

	public void requestResume() {
		adapter.requestResume(pid);
	}

	//}}}
	//{{{ public void requestEvaluation(Expr expr, String tag)

	public void requestEvaluation(Expr expr, String tag) {
		adapter.requestEvaluation(pid, expr, tag);
	}

	//}}}
}
