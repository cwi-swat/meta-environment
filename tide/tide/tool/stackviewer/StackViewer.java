package tide.tool.stackviewer;

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

import tide.*;
import tide.tool.*;
import tide.tool.support.*;

//}}}

public class StackViewer
  extends ProcessTool
  implements DebugProcessListener, ProcessStatusChangeListener,
             DebugAdapterListener
{
  //{{{ Constants

  private static final String TAG_STACK_TRACE  = "stack-trace";
  private static final String TAG_STACK_UNWIND = "stack-unwind";

  //}}}

  //{{{ Attributes

  private JToolBar      tools;
  private JTabbedPane	center;
  private JLabel        message;

  private String tag_stack_trace;
  private String tag_stack_unwind;

  private Action unwind;

  private DebugProcess process;
  private Rule ruleStackTrace;
  private Rule ruleStackUnwind;

  //}}}

  //{{{ public StackViewer(final DebugProcess process, ToolManager manager)

  public StackViewer(ToolManager manager, final DebugProcess process)
  {
    super(manager, process);

    setSize(360, 350);
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
	  process.requestRuleEnabling(ruleStackUnwind, true);
	  process.requestResume();
	}
      }
    };

    boolean stopped = process.isStopped();
    unwind.setEnabled(stopped);

    //}}}
    //{{{ Build UI

    Container content = getContentPane();
    content.setLayout(new BorderLayout());

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
  }

  //}}}
  //{{{ public void evaluationResult(process, expr, value, tag)

  public void evaluationResult(DebugProcess process, Expr expr,
			       Expr value, String tag)
  {
    if (tag.equals(tag_stack_trace)) {
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
}

