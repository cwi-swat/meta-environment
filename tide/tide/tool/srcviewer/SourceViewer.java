package tide.tool.srcviewer;

//{{{ imports

import java.util.*;
import java.io.*;
import java.net.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.border.*;
import javax.swing.text.*;
import javax.swing.plaf.TextUI;

import aterm.*;

import tide.tool.*;
import tide.tool.support.*;

//}}}

public class SourceViewer
  extends ProcessTool
  implements DebugProcessListener, ProcessStatusChangeListener,
             DebugAdapterListener
{
  //{{{ Constants

  private static final String TAG_STEP_INTO  = "sv-step-into";
  private static final String TAG_STEP_OVER  = "sv-step-over";
  private static final String TAG_VIEW_VAR   = "sv-view-var";

  private static final String NO_SOURCE = "*no-source*";

  //}}}

  //{{{ Attributes

  private JToolBar      tools;
  private JPanel        center;
  private JLabel        message;

  private CardLayout    cardLayout;

  private String tag_step_into;
  private String tag_step_over;
  private String tag_view_var;

  private Action stepInto;
  private Action stepOver;
  private Action run;
  private Action stop;

  private DebugProcess process;
  private Rule ruleStepInto;
  private Rule ruleStepOver;

  private String currentFile;
  private SourceFileViewer currentViewer;
  private Map residentViewers;

  //}}}

  //{{{ public SourceViewer(final DebugProcess process, ToolManager manager)

  public SourceViewer(ToolManager manager, final DebugProcess process)
  {
    super(manager, process);

    setSize(360, 350);
    setTitle("SourceViewer: " + process.getName());
    setBackground(Color.white);

    residentViewers = new HashMap();

    //{{{ Build tags

    tag_step_into  = TAG_STEP_INTO  + "-" + getId();
    tag_step_over  = TAG_STEP_OVER  + "-" + getId();
    tag_view_var   = TAG_VIEW_VAR   + "-" + getId();

    //}}}
    //{{{ Build actions

    stepInto = new AbstractAction("Step Into", loadIcon("step-into.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	if (process.isStopped()) {
	  process.requestRuleEnabling(ruleStepInto, true);
	  process.requestResume();
	}
      }
    };
    stepOver = new AbstractAction("Step Over", loadIcon("step-over.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	if (process.isStopped()) {
	  process.requestRuleEnabling(ruleStepOver, true);
	  process.requestResume();
	}
      }
    };
    run      = new AbstractAction("Run", loadIcon("run.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	if (process.isStopped()) {
	  process.requestResume();
	}
      }
    };
    stop     = new AbstractAction("Stop", loadIcon("stop.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	if (process.isRunning()) {
	  process.requestBreak();
	}
      }
    };

    boolean stopped = process.isStopped();
    stepInto.setEnabled(stopped);
    stepOver.setEnabled(stopped);
    run.setEnabled(stopped);
    stop.setEnabled(!stopped);

    //}}}
    //{{{ Build UI

    Container content = getContentPane();
    content.setLayout(new BorderLayout());

    tools = new JToolBar();
    tools.add(stepInto);
    tools.add(stepOver);
    tools.add(run);
    tools.add(stop);

    message = new JLabel("-");
    message.setBackground(tools.getBackground());
    message.setOpaque(true);

    center = new JPanel();
    cardLayout = new CardLayout();
    center.setLayout(cardLayout);

    JLabel noSource = new JLabel("No source (yet)");
    center.add(NO_SOURCE, noSource);

    content.add("North", tools);
    content.add("Center", center);
    content.add("South", message);

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

    process.requestRuleCreation(Port.makeStep(), Expr.makeTrue(),
				Expr.makeBreak(), tag_step_into, false);

    Expr stepOverCondition =
      Expr.make("higher-equal(stack-level,start-level)");
    process.requestRuleCreation(Port.makeStep(), stepOverCondition,
				Expr.makeBreak(), tag_step_over, false);

    //}}}

    highlightCpe();
  }

  //}}}
  //{{{ private void cleanup()

  private void cleanup()
  {
    if (ruleStepInto != null) {
      process.requestRuleDeletion(ruleStepInto);
    }

    if (ruleStepOver != null) {
      process.requestRuleDeletion(ruleStepOver);
    }
  }

  //}}}
  //{{{ private loadIcon(String name)

  private Icon loadIcon(String name)
  {
    URL url = getClass().getClassLoader().getResource("images/" + name);
    return new ImageIcon(url);
  }

  //}}}

  //{{{ public void processDestroyed(DebugAdapter adapter, DebugProcess proc)

  public void processDestroyed(DebugAdapter adapter, DebugProcess proc)
  {
    if (proc == process) {
      // Rules do not need to be removed!
      ruleStepInto = null;
      ruleStepOver = null;
      //getParent().remove(this);
      dispose();
    }
  }

  //}}}
  //{{{ public void processCreated(DebugAdapter adapter, DebugProcess proc)

  public void processCreated(DebugAdapter adapter, DebugProcess proc)
  {
  }

  //}}}

  //{{{ public void ruleCreated(DebugProcess process, Rule rule)

  public void ruleCreated(DebugProcess process, Rule rule)
  {
    if (rule.getTag().equals(tag_step_into)) {
      ruleStepInto = rule;
    } else if (rule.getTag().equals(tag_step_over)) {
      ruleStepOver = rule;
    }
  }

  //}}}
  //{{{ public void ruleDeleted(DebugProcess process, Rule rule)

  public void ruleDeleted(DebugProcess process, Rule rule)
  {
    if (rule == ruleStepInto) {
      ruleStepInto = null;
    } 

    if (rule == ruleStepOver) {
      ruleStepOver = null;
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
  }

  //}}}
  //{{{ public void evaluationResult(process, expr, value, tag)

  public void evaluationResult(DebugProcess process, Expr expr,
			       Expr value, String tag)
  {
    if (tag.equals(tag_view_var)) {
      if (value.isError()) {
	displayError(value);
      } else if (value.isVarUnknown()) {
	message.setText("Unknown variable: "
			+ value.getVarUnknownMessage());
      } else if (value.isVar()) {
	String var = value.getVarName();
        Expr val   = value.getVarValue();

	String strval = val.toString();

	int start  = value.getVarSourceStart();
	int linenr = value.getVarSourceLineNr();
	int column = value.getVarSourceStartColumn();
	int length = value.getVarSourceLength();

	message.setText("Value of " + var + " at " + linenr + ","
			+ column + " = " + strval);

	ValuePopup popup = new ValuePopup(getManager(), currentViewer,
					  process, expr, var, value,
					  new VarFormat());
	currentViewer.highlightVariable(start, length, popup);
      } else {
	displayError("Strange variable result: ", value);
      }
    }
  }

  //}}}

  //{{{ public void processStatusChanged(DebugProcess process)

  public void processStatusChanged(DebugProcess process)
  {
    System.out.println("processStatusChanged: " + process);
    boolean stopped = process.isStopped();

    stepInto.setEnabled(stopped);
    stepOver.setEnabled(stopped);
    run.setEnabled(stopped);
    stop.setEnabled(!stopped);

    if (stopped) {
      if (ruleStepInto.isEnabled()) {
	process.requestRuleEnabling(ruleStepInto, false);
      }

      if (ruleStepOver.isEnabled()) {
	process.requestRuleEnabling(ruleStepOver, false);
      }
      highlightCpe();
    } else {
      unhighlightCpe();
    }
  }

  //}}}

  //{{{ private void switchToFile(String file)

  private void switchToFile(String file)
  {
    System.out.println("switching to file: " + file);
    unhighlightCpe();

    currentViewer = (SourceFileViewer)residentViewers.get(file);
    if (currentViewer == null) {
      currentViewer = new SourceFileViewer(getManager(), process,
					   file, getId(), tag_view_var);
      residentViewers.put(file, currentViewer);
      synchronized (process) {
	currentViewer.highlightRules(process.ruleIterator());
      }
      center.add(currentViewer, file);
      //cardLayout.addLayoutComponent(file, currentViewer);
      cardLayout.show(center, file);
    } else {
      cardLayout.show(center, file);
    }

    /*
    text.clear();

    Iterator highlights = ruleHighlights.values().iterator();
    while (highlights.hasNext()) {
      highlighter.removeHighlight(highlights.next());
    }
    ruleHighlights.clear();

    try {
      text.read(new BufferedReader(new FileReader(file)), null);
    } catch (IOException e) {
      System.err.println("cannot find source file " + file);
    }
    currentFile = file;

    synchronized (process) {
      Iterator rules = process.ruleIterator();
      while (rules.hasNext()) {
	Rule rule = (Rule)rules.next();
	highlightRule(rule);
      }
    }
     */
  }

  //}}}

  //{{{ private void highlightCpe()

  private void highlightCpe()
  {
    Expr expr = process.getLastLocation();

    if (currentViewer != null) {
      currentViewer.unhighlightCpe();
    }

    if (expr != null && expr.isLocation()) {
      if (expr.isLocationUnknown()) {
	showNoSource();
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

  private void unhighlightCpe()
  {
    if (currentViewer != null) {
      currentViewer.unhighlightCpe();
    }
  }

  //}}}
  //{{{ private void showNoSource()

  private void showNoSource()
  {
    cardLayout.show(center, NO_SOURCE);
  }

  //}}}
}

