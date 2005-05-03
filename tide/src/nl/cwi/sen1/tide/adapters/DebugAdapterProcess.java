package nl.cwi.sen1.tide.adapters;

import java.lang.reflect.InvocationTargetException;
import java.lang.reflect.Method;
import java.util.LinkedList;
import java.util.List;
import java.util.Vector;

import aterm.ATerm;
import aterm.ATermAppl;
import aterm.ATermFactory;
import aterm.ATermInt;
import aterm.ATermList;
import aterm.ParseError;

abstract public class DebugAdapterProcess {
	private static final int MAXIMUM_METHOD_ARITY = 8;
	public final static int STATE_STOPPED = 0;
	public final static int STATE_RUNNING = 1;

	private Class[][] protos = new Class[MAXIMUM_METHOD_ARITY][];
	final static int MAX_RULES = 256;
	public DebugAdapter adapter;

	static private int processId = 0;
	private String processName;

	private boolean debug = true;

	public DebugAdapterRule[] rules = new DebugAdapterRule[MAX_RULES];
	public List[] rulesPerPort = new List[DebugAdapterRule.NR_PORT_TYPES];
	public DebugAdapterRule current_rule = null;

	int exec_state = STATE_STOPPED;
	int start_level = 0;

	private ATermFactory factory;

	ATerm termTrue;
	ATerm termFalse;
	ATerm termRunning;
	ATerm termStopped;
	ATerm termUnknown;

	public String getProcessName() {
		return processName;
	}
	public DebugAdapterProcess(DebugAdapter adapter, String name) {
		this.adapter = adapter;
		this.processName = name;
		this.factory = adapter.getFactory();

		for (int i = 0; i < DebugAdapterRule.NR_PORT_TYPES; i++) {
			rulesPerPort[i] = new Vector();
		}

		initializeATermClassObjects();

		try {
			termTrue = factory.parse("true");
			termFalse = factory.parse("false");
			termRunning = factory.parse("running");
			termStopped = factory.parse("stopped");
			termUnknown = factory.parse("unknown");
		} catch (ParseError e) {
			throw new RuntimeException(
				"internal error, malformed term: " + e.getMessage());
		}
	}

	private void initializeATermClassObjects() {
		try {
			Class aterm = Class.forName("aterm.ATerm");
			for (int i = 0; i < MAXIMUM_METHOD_ARITY; i++) {
				protos[i] = new Class[i];
				for (int j = 0; j < i; j++)
					protos[i][j] = aterm;
			}
		} catch (ClassNotFoundException e) {
			throw new RuntimeException("could not find class: aterm.ATerm");
		}
	}
	public int getPid() {
		return processId;
	}

	public int getExecState() {
		return exec_state;
	}

	public void changeExecState(int newstate) {
		if (exec_state != newstate) {
			exec_state = newstate;
			switch (exec_state) {
				case STATE_STOPPED :
					fireRules(DebugAdapterRule.PORT_STOPPED);
					break;
				case STATE_RUNNING :
					fireRules(DebugAdapterRule.PORT_STARTED);
					break;
			}
		}
	}

	public boolean isRunning() {
		return exec_state == STATE_RUNNING;
	}

	public void fireLocationRules(
		String filename,
		int sl,
		int sc,
		int el,
		int ec) {
		List result;
		Object[] elems;
		String file;
		int line, col;
		/*
		 * elems = rulesPerPort[DebugAdapterRule.PORT_LOCATION].toArray();
		 * for(int i=0; i <elems.length; i++) { DebugAdapterRule rule =
		 * (DebugAdapterRule)elems[i]; ATerm port = rule.getPort();
		 * 
		 * result = port.match("location(pos( <str> , <int> , <int> ))");
		 * if(result != null) { file = (String)result.get(0); line =
		 * ((Integer)result.get(1)).intValue(); col =
		 * ((Integer)result.get(2)).intValue(); } else { result =
		 * port.match("location(line( <str> , <int> ))"); if(result != null) {
		 * file = (String)result.get(0); line =
		 * ((Integer)result.get(1)).intValue(); col = 0; } else { throw new
		 * RuntimeException("strange port spec: " + port); } }
		 * 
		 * System.out.println("port = " + port); System.out.println("filename=" +
		 * filename + ",sl=" + sl + ",sc=" + sc + ",el=" + el + ",ec=" + ec +
		 * ",file=" + file + ",line=" + line + ",col=" + col);
		 * 
		 * if(filename.equals(file)) { if(line > sl || (line == sl && col >=
		 * sc)) { // Start is ok if(line
		 * < el || (line == el && (col <= ec || ec == -1))) { // End is also ok
		 * fireRule(rule); } } } }
		 */
	}

	public void fireRules(int porttype) {
		Object[] elems = rulesPerPort[porttype].toArray();
		for (int i = 0; i < elems.length; i++) {
			DebugAdapterRule rule = (DebugAdapterRule) elems[i];
			fireRule(rule);
		}
	}

	private void debugMsg(String msg) {
		if (debug) {
			System.err.println(msg);
		}
	}

	public void fireRule(DebugAdapterRule rule) {
		DebugAdapterRule old_rule = current_rule;
		current_rule = rule;

		ATerm cond = rule.getCondition();
		ATerm result = evaluate(cond);
		if (result.isEqual(termTrue)) {
			result = evaluate(rule.getAction());
			adapter.event(getPid(), current_rule, result);
		}

		current_rule = old_rule;
	}

	public DebugAdapterRule createRule(
		int pid,
		ATerm port,
		ATerm cond,
		ATerm act,
		ATerm tag,
		boolean enabled) {
		int rid;

		/* Find a free rule */
		for (rid = 0; rid < MAX_RULES; rid++) {
			if (rules[rid] == null) {
				break;
			}
		}

		if (rid >= MAX_RULES) {
			throw new RuntimeException("too many rules: " + rid);
		}

		DebugAdapterRule rule =
			new DebugAdapterRule(rid, port, cond, act, tag, enabled);

		rules[rule.getId()] = rule;

		if (enabled) {
			enableRule(rid);
		}

		handleRuleCreation(rule);

		return rule;
	}

	public void enableRule(int rid) {
		DebugAdapterRule rule = rules[rid];
		int porttype = rule.getPortType();

		rule.setEnabled(true);
		synchronized (rulesPerPort[porttype]) {
			rulesPerPort[porttype].add(rule);
		}
		handleRuleEnabling(rule);
	}

	public void disableRule(int rid) {
		DebugAdapterRule rule = rules[rid];
		int porttype = rule.getPortType();

		rule.setEnabled(false);
		synchronized (rulesPerPort[porttype]) {
			rulesPerPort[rule.getPortType()].remove(rule);
		}
		handleRuleDisabling(rule);
	}

	public void modifyRule(
		int rid,
		ATerm port,
		ATerm cond,
		ATerm act,
		boolean enabled) {
		int oldtype, newtype;
		boolean wasEnabled;

		DebugAdapterRule rule = rules[rid];

		debugMsg("oldrule" + rule);

		oldtype = rule.getPortType();
		wasEnabled = rule.isEnabled();

		rule.modify(port, cond, act, enabled);
		newtype = rule.getPortType();

		debugMsg("newrule" + rule);

		if (wasEnabled && newtype != oldtype) {
			synchronized (rulesPerPort[oldtype]) {
				synchronized (rulesPerPort[newtype]) {
					rulesPerPort[oldtype].remove(rule);
					rulesPerPort[newtype].add(rule);
				}
			}
		}
		if (enabled) {
			enableRule(rid);
		}
	}

	public void deleteRule(int rid) {
		DebugAdapterRule rule = rules[rid];
		int porttype = rule.getPortType();
		synchronized (rulesPerPort[porttype]) {
			rulesPerPort[porttype].remove(rule);
		}
		rules[rid] = null;
		handleRuleDestruction(rule);
	}

	public ATerm evaluate(ATerm act) {
		int i;

		switch (act.getType()) {
			case ATerm.LIST :
				//{ Evaluate all elements in a list

				ATermList list = (ATermList) act;
				List result = new LinkedList();
				while (!list.isEmpty()) {
					ATerm elem = list.getFirst();
					ATerm val = evaluate(elem);
					list = list.getNext();
					if (!val.equals(termTrue))
						result.add(elem);
				}
				if (result.isEmpty())
					return termTrue;
				list = factory.makeList();
				for (int idx = result.size() - 1; idx >= 0; idx--)
					list = factory.makeList((ATerm) result.get(idx), list);
				return list;

				//}

			case ATerm.APPL :
				//{ Evaluate a function

				ATermAppl appl = (ATermAppl) act;
				if (appl.isQuoted()) {
					return act;
				} else {
					String action = appl.getName();
					Class myclass = getClass();
					String name = "action" + capitalize(action, true);
					int arity = appl.getArity();

					boolean found = false;

					do {
						try {
							Method method =
								myclass.getDeclaredMethod(name, protos[arity]);
							found = true;
							Object[] args = new Object[arity];
							for (i = 0; i < arity; i++) {
								args[i] = evaluate(appl.getArgument(i));
							}
							debugMsg("invoking method: " + name);
							return (ATerm) method.invoke(this, args);
						} catch (NoSuchMethodException e) {
							found = false;
						} catch (InvocationTargetException e) {
							return factory.make("error(\"the function " + name + " has thrown an exception\")");
						} catch (IllegalAccessException e) {
							e.printStackTrace();
							found = false;
						}
						myclass = myclass.getSuperclass();
					} while (!found && myclass.getSuperclass() != null);

					if (!found) {
						return factory.make(
							"error(\"unknown function: "
								+ action + " (" + name + ")"
								+ " with arity "
								+ arity
								+ "\")");
					}
				}
			default :
				return act;
		}
	}

	static private String capitalize(String str, boolean firstCap) {
		StringBuffer name = new StringBuffer();
		for (int i = 0; i < str.length(); i++) {
			if (str.charAt(i) == '-')
				firstCap = true;
			else {
				if (firstCap) {
					name.append(Character.toUpperCase(str.charAt(i)));
					firstCap = false;
				} else
					name.append(str.charAt(i));
			}
		}
		return name.toString();
	}

	public void handleRuleCreation(DebugAdapterRule rule) {
	}

	public void handleRuleDestruction(DebugAdapterRule rule) {
	}

	public void handleRuleEnabling(DebugAdapterRule rule) {
	}

	public void handleRuleDisabling(DebugAdapterRule rule) {
	}

	public void doBreak() {
		changeExecState(STATE_STOPPED);
	}

	public void doResume() {
		exec_state = STATE_RUNNING;
		start_level = getStackLevel();
	}

	public void doDisable(DebugAdapterRule rule) {
		disableRule(rule.getId());
		List args = new LinkedList();
		args.add(new Integer(getPid()));
		args.add(new Integer(rule.getId()));
		adapter.postEvent(
			factory.make("rule-disabled(proc(<str>),<int>)", args));
	}

	public ATerm actionTrue() {
		return termTrue;
	}

	public ATerm actionFalse() {
		return termFalse;
	}

	public ATerm actionBreak() {
		doBreak();
		return termTrue;
	}

	public ATerm actionResume() {
		doResume();
		return termTrue;
	}

	public ATerm actionState() {
		switch (exec_state) {
			case STATE_RUNNING :
				return termRunning;
			case STATE_STOPPED :
				return termStopped;
			default :
				return termUnknown;
		}
	}

	public ATerm actionDisable() {
		doDisable(current_rule);
		return termTrue;
	}

	public ATerm actionHigherEqual(ATerm t1, ATerm t2) {
		if (t1.getType() == ATerm.INT && t2.getType() == ATerm.INT) {
			ATermInt i1 = (ATermInt) t1;
			ATermInt i2 = (ATermInt) t2;
			if (i1.getInt() >= i2.getInt())
				return termTrue;
		}
		return termFalse;
	}

	public ATerm actionEqual(ATerm t1, ATerm t2) {
		return t1.isEqual(t2) ? termTrue : termFalse;
	}

	public ATerm actionStartLevel() {
		return factory.parse("" + start_level);
	}

	public ATerm actionStackLevel() {
		return factory.parse("" + getStackLevel());
	}

	public abstract ATerm actionCpe();
	public abstract ATerm actionSourceVar(ATerm var, ATerm offset, ATerm line, ATerm col, ATerm dontknow);
	
	public abstract int getStackLevel();
}
