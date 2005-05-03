package nl.cwi.sen1.tide.adapters;

import java.io.IOException;
import java.util.HashMap;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import aterm.ATerm;
import aterm.ATermFactory;

public class DebugAdapter implements DebugAdapterTif {
	private Map processes;
	private DebugAdapterBridge bridge;
	private ATermFactory factory;

	protected DebugAdapter(ATermFactory factory, String[] args, int port)
		throws IOException {
		bridge = new DebugAdapterBridge(factory, this);
		this.factory = factory;
		processes = new HashMap();

		bridge.init(args);
		bridge.connect("debug-adapter", null, port);
	}

	public ATermFactory getFactory() {
		return factory;
	}

	public void postEvent(ATerm event) {
		bridge.postEvent(event);
	}

	protected void processCreated(DebugAdapterProcess process) {
		processes.put(new Integer(process.getPid()), process);
		List args = new LinkedList();
		args.add(new Integer(process.getPid()));
		args.add(process.getProcessName());
		postEvent(factory.make("process-created(<int>,<str>)", args));
	}

	public DebugAdapterProcess getProcess(int id) {
		return (DebugAdapterProcess) processes.get(new Integer(id));
	}

	public void event(int pid, DebugAdapterRule rule, ATerm value) {
		List args = new LinkedList();
		args.add(new Integer(pid));
		args.add(new Integer(rule.getId()));
		args.add(value);

		postEvent(factory.make("event(<int>,<int>,<term>)", args));
	}

	private void debugMsg(String msg) {
		System.err.println(msg);
	}

	public ATerm createRule(
		int pid,
		ATerm port,
		ATerm cond,
		ATerm act,
		ATerm tag,
		ATerm enabled) {
		
		DebugAdapterProcess proc = getProcess(pid);
		DebugAdapterRule rule =
			proc.createRule(
				pid,
				port,
				cond,
				act,
				tag,
				enabled.equals(factory.parse("true")));

		
		List args = new LinkedList();
		args.add(new Integer(rule.getId()));

		return factory.make("snd-value(rule-created(<int>))", args);
	}

	public ATerm enableRule(int pid, int rid) {
		DebugAdapterProcess proc = getProcess(pid);
		proc.enableRule(rid);
		return constValue("rule-enabled");
	}

	private ATerm constValue(String value) {
		return factory.parse("snd-value(" + value + ")");
	}
	public ATerm disableRule(int pid, int rid) {
		DebugAdapterProcess proc = getProcess(pid);
		proc.disableRule(rid);
		return constValue("rule-disabled");
	}

	public ATerm modifyRule(
		int pid,
		int rid,
		ATerm port,
		ATerm cond,
		ATerm act,
		ATerm enabled) {
		debugMsg("modify rule received...");
		DebugAdapterProcess proc = getProcess(pid);
		proc.modifyRule(
			rid,
			port,
			cond,
			act,
			enabled.equals(factory.parse("true")));
		return constValue("rule-modified");
	}

	public ATerm deleteRule(int pid, int rid) {
		DebugAdapterProcess proc = getProcess(pid);
		proc.deleteRule(rid);
		return constValue("rule-deleted");
	}

	public ATerm evaluate(int pid, ATerm act) {
		DebugAdapterProcess proc = getProcess(pid);
		ATerm result = proc.evaluate(act);
		List args = new LinkedList();
		args.add(result);

		return factory.make("snd-value(evaluated(<term>))", args);
	}

	public void recTerminate(ATerm arg) {
	}

	public void recAckEvent(ATerm event) {
	}

	public void run() {
		bridge.run();
	}
}
