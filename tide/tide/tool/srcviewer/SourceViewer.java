package tide.tool.srcviewer;

//{{{ imports

import java.awt.*;
import java.awt.event.*;
import java.io.File;
import java.util.*;

import javax.swing.*;
import javax.swing.event.*;

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
  private static final String TAG_ADD_SOURCE = "sv-add-source";

  private static final String NO_SOURCE = "*no-source*";

  //}}}

  //{{{ Attributes

  private JToolBar      tools;
  private JTabbedPane	center;
  private JLabel        message;

  private String tag_step_into;
  private String tag_step_over;
  private String tag_view_var;
  private String tag_add_source;

  private Action stepInto;
  private Action stepOver;
  private Action run;
  private Action stop;

  private Action addSourceFile;
  private Action delSourceFile;

  private DebugProcess process;
  private Rule ruleStepInto;
  private Rule ruleStepOver;

  private String currentFile;
  private SourceFileViewer currentViewer;
  private Map residentViewers;

  //}}}

  //{{{ public SourceViewer(ToolManager manager, final DebugProcess process)

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
    tag_add_source = TAG_ADD_SOURCE + "-" + getId();

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

    addSourceFile = new AbstractAction("Add File",
				       loadIcon("add-source.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	process.requestEvaluation(Expr.makeListSources(),
				  tag_add_source);
      }
    };

    delSourceFile = new AbstractAction("Remove File",
				       loadIcon("del-source.gif"))
    {
      public void actionPerformed(ActionEvent event)
      {
	unhighlightCpe();
	if (currentViewer != null) {
	  residentViewers.remove(currentViewer.getFile());
	  center.remove(currentViewer);
	}
      }
    };


    //}}}
    //{{{ Build UI

    Container content = getContentPane();
    content.setLayout(new BorderLayout());

    tools = new JToolBar();
    tools.add(stepInto).setToolTipText("Step Into");
    tools.add(stepOver).setToolTipText("Step Over");
    tools.add(run).setToolTipText("Run");
    tools.add(stop).setToolTipText("Stop");
    tools.addSeparator();
    tools.add(addSourceFile).setToolTipText("Add Sourcefile");
    tools.add(delSourceFile).setToolTipText("Remove Sourcefile");

    message = new JLabel("-");
    message.setBackground(tools.getBackground());
    message.setOpaque(true);

    center = new JTabbedPane();

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
      Expr.make("higher-equal(start-level,stack-level)");
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

    Iterator iter = residentViewers.values().iterator();
    while (iter.hasNext()) {
      SourceFileViewer viewer = (SourceFileViewer)iter.next();
      viewer.cleanup();
    }

    getManager().removeTool(this);
  }

  //}}}

  //{{{ private void requestSourceFiles()

  private void requestSourceFiles()
  {
    System.out.println("requesting source files");
  }

  //}}}

  //{{{ public void processDestroyed(DebugAdapter adapter, DebugProcess proc)

  public void processDestroyed(DebugAdapter adapter, DebugProcess proc)
  {
    if (proc == process) {
      // Rules do not need to be removed!
      ruleStepInto = null;
      ruleStepOver = null;
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
    } else if (tag.equals(tag_add_source)) {
      if (value.isError()) {
	displayError("Can't retrieve source files",
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

  public void processStatusChanged(DebugProcess process)
  {
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

  //{{{ void switchToFile(String file)

  void switchToFile(String file)
  {
    unhighlightCpe();

    currentViewer = (SourceFileViewer)residentViewers.get(file);
    if (currentViewer == null) {
      ToolManager manager = getManager();
      int id = getId();
      currentViewer = new SourceFileViewer(manager, process,
					   file, id, tag_view_var);
      residentViewers.put(file, currentViewer);
      synchronized (process) {
	currentViewer.highlightRules(process.ruleIterator());
      }
      File f = new File(file);
      center.insertTab(f.getName(), null, currentViewer,
		       file, center.getTabCount());
    }
    center.setSelectedComponent(currentViewer);

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
	message.setText("Current location is unknown: "
			+ expr.toString());
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

  //{{{ public void addSourceFromDisk(String path)

  public void addSourceFromDisk(String path)
  {
    JFileChooser chooser = new JFileChooser(path);
    int option = chooser.showOpenDialog(this);
    if (option == JFileChooser.APPROVE_OPTION) {
      switchToFile(chooser.getSelectedFile().getPath());
    }
  }

  //}}}
  //{{{ public void addSourceFromList(Iterator iter)

  public void addSourceFromList(Iterator iter)
  {
    FileSelector selector = new FileSelector(this, iter);
    getManager().showDialog(selector);
  }

  //}}}
}

class FileOption
{
  private File file;

  //{{{ public FileOption(String path)

  public FileOption(String path)
  {
    file = new File(path);
  }

  //}}}
  //{{{ public String toString()

  public String toString()
  {
    return file.getName();
  }

  //}}}
  //{{{ public String getFilename()

  public String getFilename()
  {
    return file.getPath();
  }

  //}}}
  //{{{ public String getDirectory()

  public String getDirectory()
  {
    return file.getParent();
  }

  //}}}
}

class FileSelector
  extends TideDialog
{
  private SourceViewer viewer;

  private Vector files;
  private JList  list;
  private JLabel path;

  //{{{ public void TideDialog(Iterator iter)

  public FileSelector(SourceViewer viewer, Iterator iter)
  {
    super("File Selector", DIALOG_OK_CANCEL);

    this.viewer = viewer;

    files = new Vector();
    while (iter.hasNext()) {
      String file = (String)iter.next();
      files.addElement(new FileOption(file));
    }

    init();

    setSize(250, 270);
    invalidate();
  }

  //}}}
  //{{{ public void addContent(JPanel panel)

  public void addContent(JPanel panel)
  {
    panel.setLayout(new BorderLayout());
    list = new JList(files);
    MouseListener mouseListener = 
      new MouseAdapter()
      {
	public void mouseClicked(MouseEvent e)
	{
	  if (e.getSource() == list && e.getClickCount() == 2) {
	    okPressed();
	  }
	}
      };
    list.addMouseListener(mouseListener);

    ListSelectionListener selectionListener =
      new ListSelectionListener()
      {
	public void valueChanged(ListSelectionEvent e)
	{
	  if (e.getSource() == list) {
	    FileOption selected = (FileOption)list.getSelectedValue();
	    if (selected == null) {
	      path.setText("");
	    } else {
	      path.setText(selected.getDirectory());
	    }
	  }
	}
      };
    list.addListSelectionListener(selectionListener);

    JScrollPane pane = new JScrollPane(list);
    panel.add("North", new JLabel("Select a file to add",
				  JLabel.CENTER));
    panel.add("Center", pane);
    panel.add("West", Box.createHorizontalStrut(20));
    panel.add("East", Box.createHorizontalStrut(20));

    path = new LongLabel();
    JPanel pathPanel = new JPanel();
    pathPanel.setLayout(new GridLayout(2,1));
    pathPanel.add(new JLabel("Directory:"));
    pathPanel.add(path);
    panel.add("South", pathPanel);
  }

  //}}}
  //{{{ public boolean verifyInput()

  public boolean verifyInput()
  {
    FileOption option = (FileOption)list.getSelectedValue();
    if (option == null) {
      return false;
    }

    viewer.switchToFile(option.getFilename());

    return true;
  }

  //}}}
}

class LongLabel
  extends JLabel
{
  private FontMetrics metrics;

  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
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

