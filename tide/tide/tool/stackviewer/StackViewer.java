package tide.tool.stackviewer;

//{{{ imports

import java.awt.*;
import java.awt.event.ActionEvent;
import java.util.*;

import javax.swing.*;
import javax.swing.event.*;

import tide.tool.*;
import tide.tool.support.*;

//}}}

public class StackViewer
  extends ProcessTool
  implements DebugProcessListener, ProcessStatusChangeListener,
             DebugAdapterListener, ListSelectionListener
{
  //{{{ Constants

  private static final String TAG_STACK_TRACE  = "stack-trace";
  private static final String TAG_STACK_UNWIND = "stack-unwind";

  //}}}

  //{{{ Attributes

  private JList		  trace;

  private JToolBar	  tools;
  private JLabel	  frameName;
  private JLabel	  frameDepth;
  private JLabel	  frameLocation;
  private JList		  frameVars;

  private String tag_stack_trace;
  private String tag_stack_unwind;

  private Action unwind;
  private Action viewSource;
  private Action inspectVar;

  private DebugProcess process;
  private Rule ruleStackTrace;
  private Rule ruleStackUnwind;

  private StackFrame selectedFrame;
  
  //}}}

  //{{{ public StackViewer(final DebugProcess process, ToolManager manager)

  public StackViewer(ToolManager manager, final DebugProcess process)
  {
    super(manager, process);

    setSize(480, 250);
    setTitle("StackViewer: " + process.getName());
    setBackground(Color.white);

    //{{{ Build tags

    tag_stack_trace  = TAG_STACK_TRACE  + "-" + getId();
    tag_stack_unwind = TAG_STACK_UNWIND  + "-" + getId();

    //}}}
    //{{{ Build actions

    unwind = new AbstractAction("Unwind", loadIcon("unwind.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	if (process.isStopped()) {
	  // <PO> we need to adjust the rule to break at the
	  // indicate stack level
	  process.requestRuleModification(ruleStackUnwind,
	    Port.makeStep(),
	    Expr.make("higher-equal(" + selectedFrame.getDepth()
		     + ",stack-level)"),
	    Expr.makeBreak(), true);

	  process.requestResume();
	}
      }
    };

    viewSource = new AbstractAction("View Source",
				    loadIcon("view-source.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	getManager().displayError("Not implemented yet!");
      }
    };

    inspectVar = new AbstractAction("Inspect Variable",
					 loadIcon("inspect-var.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	getManager().displayError("Not implemented yet!");
      }
    };

    unwind.setEnabled(false);
    viewSource.setEnabled(false);
    inspectVar.setEnabled(false);


    tools = new JToolBar();
    tools.add(unwind).setToolTipText("Unwind stack upto selected frame");
    tools.add(viewSource).setToolTipText("View source associated with selected frame");
    tools.add(inspectVar).setToolTipText("Inspect selected variable");

    //}}}
    //{{{ Build UI

    Container content = getContentPane();
    content.setLayout(new BorderLayout());

    trace = new JList();
    trace.setSelectionMode(ListSelectionModel.SINGLE_SELECTION);
    trace.setPreferredSize(new Dimension(120, 100));
    JPanel framePanel = new JPanel();

    JSplitPane pane = new JSplitPane(JSplitPane.HORIZONTAL_SPLIT,
				     trace, framePanel);
    content.add("Center", pane);

    trace.addListSelectionListener(this);

    framePanel.setLayout(new BorderLayout());
    Dimension dim = new Dimension(100,100);

    framePanel.setMinimumSize(dim);
    framePanel.setPreferredSize(dim);
    trace.setMinimumSize(dim);

    frameName = new JLabel("-");
    frameDepth = new JLabel("-");
    frameLocation = new JLabel("-");

    JPanel frameLabels = new JPanel();
    frameLabels.setLayout(new BorderLayout());
    JPanel leftLabels = new JPanel();
    leftLabels.setLayout(new GridLayout(0,1));
    leftLabels.add(new JLabel("Selected:"));
    leftLabels.add(new JLabel("Depth:"));
    leftLabels.add(new JLabel("Location:"));

    JPanel rightLabels = new JPanel();
    rightLabels.setLayout(new GridLayout(0,1));
    rightLabels.add(frameName);
    rightLabels.add(frameDepth);
    rightLabels.add(frameLocation);

    frameLabels.add("South", tools);
    frameLabels.add("West", leftLabels);
    frameLabels.add("Center", rightLabels);

    frameVars = new JList();
    
    framePanel.add("North", frameLabels);
    framePanel.add("Center", frameVars);

    //}}}

    //{{{ Listen to internalFrameClosed events

    addInternalFrameListener(new InternalFrameAdapter() 
      {
        public void internalFrameClosed(InternalFrameEvent event) {
	  cleanup();
	}
      }
    );

    //}}}
    //{{{ Listen to process events

    this.process = process;
    process.addDebugProcessListener(this);
    process.addProcessStatusChangeListener(this);

    DebugAdapter adapter = process.getAdapter();
    adapter.addDebugAdapterListener(this);

    //}}}
    //{{{ Create appropriate debugging events

    process.requestRuleCreation(Port.makeStopped(), Expr.makeTrue(),
				Expr.makeStackTrace(),
				tag_stack_trace, true);

    process.requestRuleCreation(Port.makeStep(), Expr.makeTrue(),
				Expr.makeBreak(),
				tag_stack_unwind, false);

    process.requestEvaluation(Expr.makeStackTrace(), tag_stack_trace);

    //}}}
  }

  //}}}
  //{{{ private void cleanup()

  private void cleanup()
  {
    if (ruleStackTrace != null) {
      process.requestRuleDeletion(ruleStackTrace);
    }

    if (ruleStackUnwind != null) {
      process.requestRuleDeletion(ruleStackUnwind);
    }

    getManager().removeTool(this);
  }

  //}}}

  //{{{ public void processDestroyed(DebugAdapter adapter, DebugProcess proc)

  public void processDestroyed(DebugAdapter adapter, DebugProcess proc)
  {
    if (proc == process) {
      // Rules do not need to be removed!
      destroy();
    }
  }

  //}}}
  //{{{ public void processCreated(DebugAdapter adapter, DebugProcess proc)

  public void processCreated(DebugAdapter adapter, DebugProcess proc)
  {
  }

  //}}}

  //{{{ public void displayStackTrace(Expr stackTrace)

  public void displayStackTrace(Expr stackTrace)
  {
    Vector frames = new Vector();

    if (!stackTrace.isStackTrace()) {
      getManager().displayError("not a stacktrace: " + stackTrace);
      return;
    }

    Iterator iter = stackTrace.frameIterator();
    while (iter.hasNext()) {
      Expr frame = (Expr)iter.next();

      if (!frame.isStackFrame()) {
	getManager().displayError("not a stackframe: " + frame);
	continue;
      }
      int depth      = frame.getFrameDepth();
      String name    = frame.getFrameName();
      Expr location  = frame.getFrameLocation();
      Expr variables = frame.getFrameVariables();
      StackFrame stackFrame =
        new StackFrame(depth, name, location, variables);
      frames.addElement(stackFrame);
    }
    trace.setListData(frames);
  }

  //}}}
  //{{{ public void displayStackFrame(StackFrame frame)

  public void displayStackFrame(StackFrame frame)
  {
    selectedFrame = frame;

    if (frame == null) {
      frameName.setText("-");
      frameDepth.setText("-");
      frameLocation.setText("-");
      unwind.setEnabled(false);
      viewSource.setEnabled(false);
      inspectVar.setEnabled(false);
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

      Vector variables = new Vector();
      Iterator iter = frame.variableIterator();
      while (iter.hasNext()) {
	Expr var = (Expr)iter.next();
	variables.addElement(var);
      }
      frameVars.setListData(variables);
    }
  }

  //}}}

  //{{{ public void ruleCreated(DebugProcess process, Rule rule)

  public void ruleCreated(DebugProcess process, Rule rule)
  {
    if (rule.getTag().equals(tag_stack_trace)) {
      ruleStackTrace = rule;
    } else if (rule.getTag().equals(tag_stack_unwind)) {
      ruleStackUnwind = rule;
    }
  }

  //}}}
  //{{{ public void ruleDeleted(DebugProcess process, Rule rule)

  public void ruleDeleted(DebugProcess process, Rule rule)
  {
    if (rule == ruleStackTrace) {
      ruleStackTrace = null;
    } 

    if (rule == ruleStackUnwind) {
      ruleStackUnwind = null;
    }
  }

  //}}}
  //{{{ public void ruleModified(DebugProcess process, Rule rule)

  public void ruleModified(DebugProcess process, Rule rule)
  {
  }

  //}}}
  //{{{ public void ruleTriggered(DebugProcess process, Rule rule, Expr value)

  public void ruleTriggered(DebugProcess process, Rule rule, Expr value)
  {
    if (rule == ruleStackTrace) {
      displayStackTrace(value);
    }
  }

  //}}}
  //{{{ public void evaluationResult(process, expr, value, tag)

  public void evaluationResult(DebugProcess process, Expr expr,
			       Expr value, String tag)
  {
    if (tag.equals(tag_stack_trace)) {
      displayStackTrace(value);
    } else if (tag.equals(tag_stack_unwind)) {
    }
  }

  //}}}

  //{{{ public void processStatusChanged(DebugProcess process)

  public void processStatusChanged(DebugProcess process)
  {
    boolean stopped = process.isStopped();

    unwind.setEnabled(stopped);

    if (stopped) {
      if (ruleStackUnwind.isEnabled()) {
	process.requestRuleEnabling(ruleStackUnwind, false);
      }
    }
  }

  //}}}
  //{{{ public void valueChanged(ListSelectionEvent evt)

  public void valueChanged(ListSelectionEvent evt)
  {
    if (evt.getSource() == trace) {
      displayStackFrame((StackFrame)trace.getSelectedValue());
    }
  }

  //}}}
}

class StackFrame
{
  private int depth;
  private String name;
  private Expr location;
  private Expr vars;

  //{{{ public StackFrame(int depth, String name, Expr location, Expr vars)

  public StackFrame(int depth, String name, Expr location, Expr vars)
  {
    this.depth = depth;
    this.name  = name;
    this.location = location;
    this.vars  = vars;
  }

  //}}}

  //{{{ public String toString()

  public String toString()
  {
    return String.valueOf(depth) + " " + name;
  }

  //}}}
  //{{{ public int getDepth()

  public int getDepth()
  {
    return depth;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return name;
  }

  //}}}
  //{{{ public Expr getLocation()

  public Expr getLocation()
  {
    return location;
  }

  //}}}
  //{{{ public Iterator variableIterator()

  public Iterator variableIterator()
  {
    return vars.iterator();
  }

  //}}}
}
