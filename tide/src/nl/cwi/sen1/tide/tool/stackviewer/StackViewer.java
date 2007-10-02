package nl.cwi.sen1.tide.tool.stackviewer;

import java.awt.BorderLayout;
import java.awt.Dimension;
import java.awt.GridLayout;
import java.awt.event.ActionEvent;
import java.util.Iterator;
import java.util.Vector;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JLabel;
import javax.swing.JList;
import javax.swing.JPanel;
import javax.swing.JScrollPane;
import javax.swing.JSplitPane;
import javax.swing.JToolBar;
import javax.swing.ListSelectionModel;
import javax.swing.event.ListSelectionEvent;
import javax.swing.event.ListSelectionListener;

import nl.cwi.sen1.tide.tool.ProcessTool;
import nl.cwi.sen1.tide.tool.ToolManager;
import nl.cwi.sen1.tide.tool.support.DebugAdapter;
import nl.cwi.sen1.tide.tool.support.DebugAdapterListener;
import nl.cwi.sen1.tide.tool.support.DebugProcess;
import nl.cwi.sen1.tide.tool.support.DebugProcessListener;
import nl.cwi.sen1.tide.tool.support.Expr;
import nl.cwi.sen1.tide.tool.support.Port;
import nl.cwi.sen1.tide.tool.support.ProcessStatusChangeListener;
import nl.cwi.sen1.tide.tool.support.Rule;

public class StackViewer extends ProcessTool implements DebugProcessListener,
		ProcessStatusChangeListener, DebugAdapterListener,
		ListSelectionListener {
	private static final String TAG_STACK_TRACE = "stack-trace";
	private static final String TAG_STACK_UNWIND = "stack-unwind";

	private JList trace;

	private JToolBar tools;
	private JLabel frameName;
	private JLabel frameDepth;
	private JLabel frameLocation;
	private JList frameVars;

	private String tag_stack_trace;
	private String tag_stack_unwind;

	private Action unwind;
	private Action viewSource;
	private Action inspectVar;

	private DebugProcess process;
	private Rule ruleStackTrace;
	private Rule ruleStackUnwind;

	private StackFrame selectedFrame;

	public StackViewer(ToolManager manager, final DebugProcess process) {
		super(manager, process);

		tag_stack_trace = TAG_STACK_TRACE + "-" + getId();
		tag_stack_unwind = TAG_STACK_UNWIND + "-" + getId();

		unwind = new AbstractAction("Unwind", loadIcon("unwind.gif")) {
			public void actionPerformed(ActionEvent event) {
				if (selectedFrame == null) {
					getManager().displayError("Select a stackframe.");
				} else if (process.isStopped()) {
					process.requestRuleModification(ruleStackUnwind, Port
							.makeStep(), Expr.make("higher-equal("
							+ selectedFrame.getDepth() + ",stack-level)"), Expr
							.makeBreak(), true);

					process.requestResume();
				}
			}
		};

		viewSource = new AbstractAction("View Source",
				loadIcon("view-source.gif")) {
			public void actionPerformed(ActionEvent event) {
				getManager().displayError("Not implemented yet!");
			}
		};

		inspectVar = new AbstractAction("Inspect Variable",
				loadIcon("inspect-var.gif")) {
			public void actionPerformed(ActionEvent event) {
				getManager().displayError("Not implemented yet!");
			}
		};

		unwind.setEnabled(false);
		viewSource.setEnabled(false);
		inspectVar.setEnabled(false);

		tools = new JToolBar();
		tools.add(unwind).setToolTipText("Unwind stack upto selected frame");
		tools.add(viewSource).setToolTipText(
				"View source associated with selected frame");
		tools.add(inspectVar).setToolTipText("Inspect selected variable");

		setLayout(new BorderLayout());

		trace = new JList();
		trace.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
		trace.setPreferredSize(new Dimension(120, 100));
		JPanel framePanel = new JPanel();

		JSplitPane pane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT, trace,
				framePanel);
		add("Center", pane);

		trace.addListSelectionListener(this);

		framePanel.setLayout(new BorderLayout());
		Dimension dim = new Dimension(100, 100);

		framePanel.setMinimumSize(dim);
		framePanel.setPreferredSize(dim);
		trace.setMinimumSize(dim);

		frameName = new JLabel("-");
		frameDepth = new JLabel("-");
		frameLocation = new JLabel("-");

		JPanel frameLabels = new JPanel();
		frameLabels.setLayout(new BorderLayout());
		JPanel leftLabels = new JPanel();
		leftLabels.setLayout(new GridLayout(0, 1));
		leftLabels.add(new JLabel("Selected:"));
		leftLabels.add(new JLabel("Depth:"));
		leftLabels.add(new JLabel("Location:"));

		JPanel rightLabels = new JPanel();
		rightLabels.setLayout(new GridLayout(0, 1));
		rightLabels.add(frameName);
		rightLabels.add(frameDepth);
		rightLabels.add(frameLocation);

		frameLabels.add("South", tools);
		frameLabels.add("West", leftLabels);
		frameLabels.add("Center", rightLabels);

		frameVars = new JList();
		JScrollPane scrollFrameVars = new JScrollPane(frameVars);

		framePanel.add("North", frameLabels);
		framePanel.add("Center", scrollFrameVars);

		this.process = process;
		process.addDebugProcessListener(this);
		process.addProcessStatusChangeListener(this);

		DebugAdapter adapter = process.getAdapter();
		adapter.addDebugAdapterListener(this);

		process.requestRuleCreation(Port.makeStopped(), Expr.makeTrue(), Expr
				.makeStackTrace(), tag_stack_trace, true);

		process.requestRuleCreation(Port.makeStep(), Expr.makeTrue(), Expr
				.makeBreak(), tag_stack_unwind, false);

		process.requestEvaluation(Expr.makeStackTrace(), tag_stack_trace);
	}

	public void processDestroyed(DebugAdapter adapter, DebugProcess proc) {
		if (proc == process) {
			// Rules do not need to be removed!
			ruleStackTrace = null;
			ruleStackUnwind = null;
			destroy();
		}
	}

	public void processCreated(DebugAdapter adapter, DebugProcess proc) {
	}

	public void displayStackTrace(Expr stackTrace) {
		Vector<StackFrame> frames = new Vector<StackFrame>();

		if (!stackTrace.isStackTrace()) {
			getManager().displayError("not a stacktrace: " + stackTrace);
			return;
		}

		Iterator<Expr> iter = stackTrace.frameIterator();
		while (iter.hasNext()) {
			Expr frame = iter.next();

			if (!frame.isStackFrame()) {
				getManager().displayError("not a stackframe: " + frame);
				continue;
			}
			int depth = frame.getFrameDepth();
			String name = frame.getFrameName();
			Expr location = frame.getFrameLocation();
			Expr variables = frame.getFrameVariables();
			StackFrame stackFrame = new StackFrame(depth, name, location,
					variables);
			frames.addElement(stackFrame);
		}
		displayStackFrame(frames.firstElement());
		trace.setListData(frames);
	}

	public void displayStackFrame(StackFrame frame) {
		selectedFrame = frame;

		if (frame == null) {
			frameName.setText("-");
			frameDepth.setText("-");
			frameLocation.setText("-");
			unwind.setEnabled(false);
			viewSource.setEnabled(false);
			inspectVar.setEnabled(false);
			frameVars.removeAll();
		} else {
			String name = frame.getName();
			int depth = frame.getDepth();
			Expr location = frame.getLocation();
			frameName.setText(name);
			frameDepth.setText(String.valueOf(depth));
			frameLocation.setText(location.toString());
			unwind.setEnabled(true);
			viewSource.setEnabled(!location.isLocationUnknown());
			inspectVar.setEnabled(false);

			Vector<Expr> variables = new Vector<Expr>();
			Iterator<Expr> iter = frame.variableIterator();
			while (iter.hasNext()) {
				Expr var = iter.next();
				variables.addElement(var);
			}
			frameVars.setListData(variables);
		}
	}

	public void ruleCreated(DebugProcess process, Rule rule) {
		if (rule.getTag().equals(tag_stack_trace)) {
			ruleStackTrace = rule;
		} else if (rule.getTag().equals(tag_stack_unwind)) {
			ruleStackUnwind = rule;
		}
	}

	public void ruleDeleted(DebugProcess process, Rule rule) {
		if (rule == ruleStackTrace) {
			ruleStackTrace = null;
		}

		if (rule == ruleStackUnwind) {
			ruleStackUnwind = null;
		}
	}

	public void ruleModified(DebugProcess process, Rule rule) {
	}

	public void ruleTriggered(DebugProcess process, Rule rule, Expr value) {
		if (rule == ruleStackTrace) {
			displayStackTrace(value);
		}
	}

	public void evaluationResult(DebugProcess process, Expr expr, Expr value,
			String tag) {
		if (tag.equals(tag_stack_trace)) {
			displayStackTrace(value);
		} else if (tag.equals(tag_stack_unwind)) {
		}
	}

	public void processStatusChanged(DebugProcess process) {
		boolean stopped = process.isStopped();

		unwind.setEnabled(stopped);

		if (stopped) {
			if (ruleStackUnwind.isEnabled()) {
				process.requestRuleEnabling(ruleStackUnwind, false);
			}
		}
	}

	public void valueChanged(ListSelectionEvent evt) {
		if (evt.getSource() == trace) {
			displayStackFrame((StackFrame) trace.getSelectedValue());
		}
	}
}

class StackFrame {
	private int depth;
	private String name;
	private Expr location;
	private Expr vars;

	public StackFrame(int depth, String name, Expr location, Expr vars) {
		this.depth = depth;
		this.name = name;
		this.location = location;
		this.vars = vars;
	}

	public String toString() {
		return String.valueOf(depth) + " " + name;
	}

	public int getDepth() {
		return depth;
	}

	public String getName() {
		return name;
	}

	public Expr getLocation() {
		return location;
	}

	public Iterator<Expr> variableIterator() {
		return vars.iterator();
	}
}
