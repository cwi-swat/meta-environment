package tide.adapters.gdb;

import java.util.HashMap;
import java.util.List;
import java.util.Map;

import tide.adapters.DebugAdapterProcess;
import tide.adapters.DebugAdapterRule;
import aterm.ATerm;
import aterm.ATermFactory;

public class GdbProcess extends DebugAdapterProcess implements Runnable {
	private GdbAdapter adapter;
	private Thread thread;

	private String name;
	private int pid = -1;
	private String file;
	private int line;
	private int stackLevel;
	private Map rulesByBreak;
	private Map breaksByRule;

	private ATermFactory factory;

	public GdbProcess(GdbAdapter adapter, String name) {
		super(adapter, name);
		this.adapter = adapter;
		this.name = name;
		this.factory = adapter.getFactory();

		rulesByBreak = new HashMap();
		breaksByRule = new HashMap();
	}

	public int getPid() {
		return pid;
	}
	public void setPid(int pid) {
		this.pid = pid;
	}
	
	public void setCpe(String file, int line) {
		this.file = file;
		this.line = line;
	}
	public void setStackLevel(int level) {
		stackLevel = level;
	}

	public void handleRuleCreation(DebugAdapterRule rule) {
		super.handleRuleCreation(rule);
		List result;

		result = rule.getAction().match("location(pos(<str>,<int>,<int>))");
		if (result != null) {
			String file = (String) result.get(0);
			int linenr = ((Integer) result.get(1)).intValue();
			SetBreakpointCmd cmd = new SetBreakpointCmd(adapter, file, linenr);
			adapter.evaluate(cmd);
			Integer brk = new Integer(cmd.getBreakpoint());
			breaksByRule.put(rule, brk);
			rulesByBreak.put(brk, rule);
			adapter.writeln("disable " + brk);
		}
	}

	public void handleRuleDestruction(DebugAdapterRule rule) {
		super.handleRuleDestruction(rule);
		Integer brk = (Integer) breaksByRule.get(rule);
		if (brk != null) {
			adapter.writeln("delete " + brk);
			breaksByRule.remove(rule);
			rulesByBreak.remove(brk);
		}
	}

	public void handleRuleEnabling(DebugAdapterRule rule) {
		super.handleRuleEnabling(rule);
		Integer brk = (Integer) breaksByRule.get(rule);
		if (brk != null) {
			adapter.writeln("enable " + brk);
		}
	}
	public void handleRuleDisabling(DebugAdapterRule rule) {
		super.handleRuleDisabling(rule);
		Integer brk = (Integer) breaksByRule.get(rule);
		if (brk != null) {
			adapter.writeln("disable " + brk);
		}
	}

	public void doResume() {
		System.out.println("doResume called");
		fireRules(DebugAdapterRule.PORT_STARTED);
		super.doResume();

		thread = new Thread(this);
		thread.start();
	}

	private void debugMsg(String msg) {
		System.err.println(msg);
	}

	public void doBreak() {
		debugMsg("break not supported (yet!)");
		super.doBreak();
		
		/* TODO: find out what this is supposed to do
		try {
			Runtime.getRuntime().exec("/usr/bin/kill -INT " + pid);
		} catch (IOException e) {
			System.err.println(
				"could not execute '/usr/bin/kill' to kill program: "
					+ e.getMessage());
		}
		*/
	}

	public ATerm actionCpe() {
		if (file == null) {
			debugMsg("current cpe is unknown");
			return factory.make("cpe(unknown)");
		} else {
			debugMsg("current cpe is in file:" + file + ", line: " + line);
			return factory.make(
				"location(line(<str>,<int>))",
				file,
				new Integer(line));
		}
	}

	public ATerm actionSourceVar(ATerm file, ATerm offset, ATerm line, ATerm col, ATerm text) {
		RetrieveVarCmd cmd = new RetrieveVarCmd(adapter, file, offset, line, col, text);
		adapter.evaluate(cmd);
		return cmd.getValue();
	}

	private String getVariableName(ATerm col, ATerm text) {
		
		return name;
	}

	public int getStackLevel() {
		return stackLevel;
	}

	public void run() {
		fireRules(DebugAdapterRule.PORT_STARTED);
		while (getExecState() == STATE_RUNNING) {
			ContinueCmd cmd = new ContinueCmd(adapter, this);
			adapter.evaluate(cmd);
			fireRules(DebugAdapterRule.PORT_STEP);
			// TODO: find out why this was necessary?
            //	fireLocationRules(file, line, 0, line, -1);
		}
		fireRules(DebugAdapterRule.PORT_STOPPED);
	}

	//}
}
