package nl.cwi.sen1.tide.tool.srcviewer;

//{{{ imports

import java.awt.BorderLayout;
import java.awt.FontMetrics;
import java.awt.Graphics;
import java.awt.event.ActionEvent;
import java.io.File;
import java.util.HashMap;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;

import javax.swing.AbstractAction;
import javax.swing.Action;
import javax.swing.JFileChooser;
import javax.swing.JLabel;
import javax.swing.JOptionPane;
import javax.swing.JTabbedPane;
import javax.swing.JToolBar;

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
import nl.cwi.sen1.tide.tool.support.VarFormat;

//}}}

public class SourceViewer
	extends ProcessTool
	implements DebugProcessListener, ProcessStatusChangeListener, DebugAdapterListener {
	//{{{ Constants

	private static final String TAG_STEP_INTO = "sv-step-into";
	private static final String TAG_STEP_OVER = "sv-step-over";
	private static final String TAG_STEP_UP = "sv-step-up";
	private static final String TAG_VIEW_VAR = "sv-view-var";
	private static final String TAG_ADD_SOURCE = "sv-add-source";

	private static final String NO_SOURCE = "*no-source*";

	//}}}

	//{{{ Attributes

	private JToolBar tools;
	private JTabbedPane center;
	private JLabel message;

	private String tag_step_into;
	private String tag_step_over;
	private String tag_step_up;
	private String tag_view_var;
	private String tag_add_source;

	private Action stepInto;
	private Action stepOver;
	private Action stepUp;
	private Action run;
	private Action stop;

	private Action addSourceFile;
	private Action delSourceFile;

	private DebugProcess process;
	private Rule ruleStepInto;
	private Rule ruleStepOver;
	private Rule ruleStepUp;

	private String currentFile;
	private SourceFileViewer currentViewer;
	private Map residentViewers;

	private int prevDepth = -1;
	//}}}

	//{{{ public SourceViewer(ToolManager manager, final DebugProcess process)

	public SourceViewer(ToolManager manager, final DebugProcess process) {
		super(manager, process);


		residentViewers = new HashMap();

		//{{{ Build tags

		tag_step_into = TAG_STEP_INTO + "-" + getId();
		tag_step_over = TAG_STEP_OVER + "-" + getId();
		tag_step_up = TAG_STEP_UP + "-" + getId();
		tag_view_var = TAG_VIEW_VAR + "-" + getId();
		tag_add_source = TAG_ADD_SOURCE + "-" + getId();

		//}}}
		//{{{ Build actions

		stepInto = new AbstractAction("Step Into", loadIcon("step-into.gif")) {
			public void actionPerformed(ActionEvent event) {
				if (process.isStopped()) {
					process.requestRuleEnabling(ruleStepInto, true);
					process.requestResume();
				}
			}
		};
		stepOver = new AbstractAction("Step Over", loadIcon("step-over.gif")) {
			public void actionPerformed(ActionEvent event) {
				if (process.isStopped()) {
					process.requestRuleEnabling(ruleStepOver, true);
					process.requestResume();
				}
			}
		};
		stepUp = new AbstractAction("Step Up", loadIcon("step-up.gif")) {
			public void actionPerformed(ActionEvent event) {
				if (process.isStopped()) {
					process.requestRuleEnabling(ruleStepUp, true);
					process.requestResume();
				}
			}
		};
		run = new AbstractAction("Run", loadIcon("run.gif")) {
			public void actionPerformed(ActionEvent event) {
				if (process.isStopped()) {
					process.requestResume();
				}
			}
		};
		stop = new AbstractAction("Stop", loadIcon("stop.gif")) {
			public void actionPerformed(ActionEvent event) {
				if (process.isRunning()) {
					process.requestBreak();
				}
			}
		};

		boolean stopped = process.isStopped();
		stepInto.setEnabled(stopped);
		stepOver.setEnabled(stopped);
		stepUp.setEnabled(stopped);
		run.setEnabled(stopped);
		stop.setEnabled(!stopped);

		addSourceFile =
			new AbstractAction("Add File", loadIcon("add-source.gif")) {
			public void actionPerformed(ActionEvent event) {
				process.requestEvaluation(
					Expr.makeListSources(),
					tag_add_source);
			}
		};

		delSourceFile =
			new AbstractAction("Remove File", loadIcon("del-source.gif")) {
			public void actionPerformed(ActionEvent event) {
				unhighlightCpe();
				if (currentViewer != null) {
					residentViewers.remove(currentViewer.getFile());
					center.remove(currentViewer);
				}
			}
		};

		//}}}
		//{{{ Build UI

		setLayout(new BorderLayout());

		tools = new JToolBar();
		tools.add(stepInto).setToolTipText("Step Into");
		tools.add(stepOver).setToolTipText("Step Over");
		tools.add(stepUp).setToolTipText("Step Up");
		tools.add(run).setToolTipText("Run");
		tools.add(stop).setToolTipText("Stop");
		tools.addSeparator();
		tools.add(addSourceFile).setToolTipText("Add Sourcefile");
		tools.add(delSourceFile).setToolTipText("Remove Sourcefile");

		message = new JLabel("-");
		message.setBackground(tools.getBackground());
		message.setOpaque(true);

		center = new JTabbedPane();

		add("North", tools);
		add("Center", center);
		add("South", message);

		//}}}

		//{{{ Listen to process events

		this.process = process;
		process.addDebugProcessListener(this);
		process.addProcessStatusChangeListener(this);

		DebugAdapter adapter = process.getAdapter();
		adapter.addDebugAdapterListener(this);

		//}}}
		//{{{ Create appropriate debugging events

		process.requestRuleCreation(
			Port.makeStep(),
			Expr.makeTrue(),
			Expr.makeBreak(),
			tag_step_into,
			false);

		Expr stepOverCondition =
			Expr.make("higher-equal(start-level,stack-level)");
		process.requestRuleCreation(
			Port.makeStep(),
			stepOverCondition,
			Expr.makeBreak(),
			tag_step_over,
			false);

		Expr stepUpCondition =
			Expr.make("less(stack-level,start-level)");
		process.requestRuleCreation(
			Port.makeStep(),
			stepUpCondition,
			Expr.makeBreak(),
			tag_step_up,
			false);
		//}}}

		highlightCpe();
	}

	//}}}
	//{{{ private void cleanup()

	private void cleanup() {
		if (ruleStepInto != null) {
			process.requestRuleDeletion(ruleStepInto);
		}
		if (ruleStepOver != null) {
			process.requestRuleDeletion(ruleStepOver);
		}
		if (ruleStepUp != null) {
			process.requestRuleDeletion(ruleStepUp);
		}

		Iterator iter = residentViewers.values().iterator();
		while (iter.hasNext()) {
			SourceFileViewer viewer = (SourceFileViewer) iter.next();
			viewer.cleanup();
		}

		process.removeDebugProcessListener(this);
		process.removeProcessStatusChangeListener(this);
		process.getAdapter().removeDebugAdapterListener(this);
		
		getManager().removeTool(this);
	}

	//}}}

	//{{{ private void requestSourceFiles()

	private void requestSourceFiles() {
		System.out.println("requesting source files");
	}

	//}}}

	//{{{ public void processDestroyed(DebugAdapter adapter, DebugProcess
	// proc)

	public void processDestroyed(DebugAdapter adapter, DebugProcess proc) {
		if (proc == process) {
			// Rules do not need to be removed!
			ruleStepInto = null;
			ruleStepOver = null;
			ruleStepUp = null;
			destroy();
		}
	}

	//}}}
	//{{{ public void processCreated(DebugAdapter adapter, DebugProcess proc)

	public void processCreated(DebugAdapter adapter, DebugProcess proc) {
	}

	//}}}

	//{{{ public void ruleCreated(DebugProcess process, Rule rule)

	public void ruleCreated(DebugProcess process, Rule rule) {
		if (rule.getTag().equals(tag_step_into)) {
			ruleStepInto = rule;
		} else if (rule.getTag().equals(tag_step_over)) {
			ruleStepOver = rule;
		} else if (rule.getTag().equals(tag_step_up)) {
			ruleStepUp = rule;
		}
	}

	//}}}
	//{{{ public void ruleDeleted(DebugProcess process, Rule rule)

	public void ruleDeleted(DebugProcess process, Rule rule) {
		if (rule == ruleStepInto) {
			ruleStepInto = null;
		}
		if (rule == ruleStepOver) {
			ruleStepOver = null;
		}
		if (rule == ruleStepUp) {
			ruleStepUp = null;
		}
	}

	//}}}
	//{{{ public void ruleModified(DebugProcess process, Rule rule)

	public void ruleModified(DebugProcess process, Rule rule) {
	}

	//}}}
	//{{{ public void ruleTriggered(DebugProcess process, Rule rule, Expr
	// value)

	public void ruleTriggered(DebugProcess process, Rule rule, Expr value) {
	}

	//}}}
	//{{{ public void evaluationResult(process, expr, value, tag)

	public void evaluationResult(
		DebugProcess process,
		Expr expr,
		Expr value,
		String tag) {
		if (tag.equals(tag_view_var)) {
			if (value.isError()) {
				displayError(value);
			} else if (value.isVarUnknown()) {
				message.setText(
					"Unknown variable: " + value.getVarUnknownMessage());
			} else if (value.isVar()) {
				String var = value.getVarName();
				Expr val = value.getVarValue();

				String strval = val.toString();

				int start = value.getVarSourceStart();
				int linenr = value.getVarSourceLineNr();
				int column = value.getVarSourceStartColumn();
				int length = value.getVarSourceLength();

				message.setText(
					"Value of "
						+ var
						+ " at "
						+ linenr
						+ ","
						+ column
						+ " = "
						+ strval);

				ValuePopup popup =
					new ValuePopup(
						getManager(),
						currentViewer,
						process,
						expr,
						var,
						value,
						new VarFormat());
				currentViewer.highlightVariable(start, length, popup);
			} else {
				displayError("Strange variable result: ", value);
			}
		} else if (tag.equals(tag_add_source)) {
			if (value.isError()) {
				displayError(
					"Can't retrieve source files",
					value.getErrorData());
			} else if (value.isSourcePath()) {
				addSourceFromDisk(value.getSourcePath());
			} else if (value.isSourceList()) {
				//addSourceFromDisk(System.getProperty("user.dir"));
				addSourceFromList(value.sourceIterator());
			} else {
				// Not reduced
				addSourceFromDisk(System.getProperty("user.dir"));
			}
		}
	}

	//}}}

	//{{{ public void processStatusChanged(DebugProcess process)

	public void processStatusChanged(DebugProcess process) {
		boolean stopped = process.isStopped();

		stepInto.setEnabled(stopped);
		stepOver.setEnabled(stopped);
		stepUp.setEnabled(stopped);
		run.setEnabled(stopped);
		stop.setEnabled(!stopped);

		if (stopped) {
			if (ruleStepInto.isEnabled()) {
				process.requestRuleEnabling(ruleStepInto, false);
			}

			if (ruleStepOver.isEnabled()) {
				process.requestRuleEnabling(ruleStepOver, false);
			}

			if (ruleStepUp.isEnabled()) {
				process.requestRuleEnabling(ruleStepUp, false);
			}
			highlightCpe();
		} else {
			unhighlightCpe();
		}
	}

	//}}}

	//{{{ void switchToFile(String file)

	void switchToFile(String file) {
		unhighlightCpe();

		currentViewer = (SourceFileViewer) residentViewers.get(file);
		if (currentViewer == null) {
			ToolManager manager = getManager();
			int id = getId();
			currentViewer =
				new SourceFileViewer(manager, process, file, id, tag_view_var);
			residentViewers.put(file, currentViewer);
			synchronized (process) {
				currentViewer.highlightRules(process.ruleIterator());
			}
			File f = new File(file);
			center.insertTab(
				f.getName(),
				null,
				currentViewer,
				file,
				center.getTabCount());
			System.err.println("inserted tab\n");
		}
		
		center.setSelectedComponent(currentViewer);
	}

	//}}}

	//{{{ private void highlightCpe()

	private void highlightCpe() {
		Expr expr = process.getLastLocation();

		if (currentViewer != null) {
			currentViewer.unhighlightCpe();
		}

		if (expr != null && expr.isLocation()) {
			if (expr.isLocationUnknown()) {
				message.setText(
					"Current location is unknown: " + expr.toString());
			} else {
				String file = expr.getLocationFileName();

				if (!file.equals(currentFile)) {
					switchToFile(file);
				}
				
				currentViewer.highlightCpe();
			}
		}
	}

	//}}}
	//{{{ private void unhighlightCpe()

	private void unhighlightCpe() {
		if (currentViewer != null) {
			currentViewer.unhighlightCpe();
		}
	}

	//}}}

	//{{{ public void addSourceFromDisk(String path)

	public void addSourceFromDisk(String path) {
		JFileChooser chooser = new JFileChooser(path);
		int option = chooser.showOpenDialog(this);
		if (option == JFileChooser.APPROVE_OPTION) {
			switchToFile(chooser.getSelectedFile().getAbsolutePath());
		}
	}

	public void addSourceFromList(Iterator iter) {
		List list = new LinkedList();
		while (iter.hasNext()) {
			list.add(iter.next());
		}
		
		if (list.size() > 0) {
			String selected = (String) JOptionPane.showInputDialog(this, 
				null, 
				"Please pick one of the registered files",
				JOptionPane.QUESTION_MESSAGE,
				null,
				list.toArray(), 
				list.get(0));
		
			switchToFile(selected);
		}
	}

	
}



class LongLabel extends JLabel {
	private FontMetrics metrics;

	//{{{ public void paint(Graphics g)

	public void paint(Graphics g) {
		if (metrics == null) {
			metrics = getFontMetrics(getFont());
		}

		String txt = getText();
		String str = txt;
		int width = metrics.stringWidth(txt);
		while (width >= getWidth()) {
			str = str.substring(1);
			txt = "..." + str;
			width = metrics.stringWidth(txt);
		}

		g.drawString(txt, 0, metrics.getMaxAscent());
	}

	//}}}
}
