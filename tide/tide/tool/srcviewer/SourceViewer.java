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
import tide.tool.ruleinspector.*;

//}}}

public class SourceViewer
  extends ProcessTool
  implements DebugProcessListener, ProcessStatusChangeListener,
             DebugAdapterListener, ActionListener, PopupMenuListener,
	     MouseMotionListener, MouseListener
{
  //{{{ Constants

  private static final String TAG_STEP_INTO  = "sv-step-into";
  private static final String TAG_STEP_OVER  = "sv-step-over";
  private static final String TAG_BREAKPOINT = "sv-breakpoint";
  private static final String TAG_WATCHPOINT = "sv-watchpoint";
  private static final String TAG_VIEW_VAR   = "sv-view-var";

  private static final String PAT_SOURCE_VAR =
    "source-var(<int>,<int>,<int>,<str>)";
  private static final String PAT_VAR =
    "var(<str>,<term>,<int>,<int>,<int>,<int>)";

  static final Color COLOR_CPE        = new Color(0xDD,0xDD,0xFF);
  static final Color COLOR_VARIABLE   = new Color(0xEE,0xEE,0x00);
  static final Color COLOR_BREAK      = new Color(0xFF,0xCC,0xCC);
  static final Color COLOR_BREAKPOINT = new Color(0xCC,0x00,0x00);
  static final Color COLOR_WATCH      = new Color(0xCC,0xFF,0xCC);
  static final Color COLOR_WATCHPOINT = new Color(0x00,0x99,0x00);
  static final Color COLOR_LINEBG     = new Color(0xF0,0xF0,0xF0);

  private static final String ITEM_ADD_BREAKPOINT = "Add Breakpoint";
  private static final String ITEM_ADD_WATCHPOINT = "Add Watchpoint";
  private static final String ITEM_EDIT_RULE      = "Edit Rule";
  private static final String ITEM_DELETE_RULE    = "Delete Rule";

  private static final Font SOURCE_FONT = new Font("Monospaced", 0, 12);
  private static final Font LINENR_FONT = new Font("Monospaced", 0, 10);

  //}}}

  //{{{ Attributes

  private JToolBar      tools;
  private SourceBrowser text;
  private JComponent    glass;
  private LineNumberCanvas lineNumbers;
  private JLabel        message;
  private JPopupMenu    menu;

  private String tag_step_into;
  private String tag_step_over;
  private String tag_breakpoint;
  private String tag_watchpoint;
  private String tag_view_var;

  private Action stepInto;
  private Action stepOver;
  private Action run;
  private Action stop;

  private DebugProcess process;
  private Rule ruleStepInto;
  private Rule ruleStepOver;

  private String currentFile;
  private DefaultHighlighter highlighter;

  private Highlighter.HighlightPainter cpePainter;
  private Object cpeHighlight;

  private Highlighter.HighlightPainter variablePainter;

  private Highlighter.HighlightPainter breakpointPainter;
  private Highlighter.HighlightPainter watchpointPainter;
  private Map ruleHighlights;

  private Map variableHighlights;

  private int lastSelected;
  private Rule lastSelectedRule;
  private ValuePopup draggedPopup;

  //}}}

  //{{{ public SourceViewer(final DebugProcess process, ToolManager manager)

  public SourceViewer(ToolManager manager, final DebugProcess process)
  {
    super(manager, process);

    setSize(360, 350);
    setTitle("SourceViewer: " + process.getName());
    setBackground(Color.white);

    //{{{ Build tags

    tag_step_into  = TAG_STEP_INTO  + "-" + getId();
    tag_step_over  = TAG_STEP_OVER  + "-" + getId();
    tag_breakpoint = TAG_BREAKPOINT + "-" + getId();
    tag_watchpoint = TAG_WATCHPOINT + "-" + getId();
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

    text = new SourceBrowser();
    text.setFont(SOURCE_FONT);


    lineNumbers = new LineNumberCanvas(text);
    lineNumbers.setFont(LINENR_FONT);
    lineNumbers.setBackground(COLOR_LINEBG);

    message = new JLabel("-");
    message.setBackground(tools.getBackground());
    message.setOpaque(true);

    JPanel textPanel = new JPanel();
    textPanel.setLayout(new BorderLayout());
    textPanel.add("Center", text);
    textPanel.add("West", lineNumbers);

    glass = new JPanel();
    glass.setOpaque(false);
    glass.setBackground(Color.red);
    glass.setLayout(null);

    JLayeredPane pane = new JLayeredPane();
    pane.setLayout(new OverlayLayout(pane));
    pane.add(textPanel, new Integer(1));
    pane.add(glass, new Integer(2));

    content.add("North", tools);
    content.add("Center", new JScrollPane(pane));
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
    //{{{ Listen to MouseEvents

    glass.addMouseListener(this);
    glass.addMouseMotionListener(this);

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

    //{{{ Prepare highlighting stuff

    highlighter = new DefaultHighlighter();
    highlighter.setDrawsLayeredHighlights(true);
    text.setHighlighter(highlighter);
    text.setEditable(false);

    breakpointPainter =
      new DefaultHighlighter.DefaultHighlightPainter(COLOR_BREAK);
    watchpointPainter =
      new DefaultHighlighter.DefaultHighlightPainter(COLOR_WATCH);

    cpePainter =
      new DefaultHighlighter.DefaultHighlightPainter(COLOR_CPE);

    variablePainter =
      new DefaultHighlighter.DefaultHighlightPainter(COLOR_VARIABLE);

    ruleHighlights = new HashMap();

    variableHighlights = new HashMap();

    highlightCpe();

    //}}}

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

    highlightRule(rule);
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

    unhighlightRule(rule);
  }

  //}}}
  //{{{ public void ruleModified(DebugProcess process, Rule rule)

  public void ruleModified(DebugProcess process, Rule rule)
  {
    unhighlightRule(rule);
    highlightRule(rule);
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
      Iterator args = value.toTerm().match(PAT_VAR).iterator();
      String var = (String)args.next();
      Expr val   = Expr.make((ATerm)args.next());

      if (val.toTerm().isEqual(Expr.factory.parse("unknown"))) {
	message.setText("Unknown variable: " + var);
	return;
      }

      int start  = ((Integer)args.next()).intValue();
      int linenr = ((Integer)args.next()).intValue();
      int column = ((Integer)args.next()).intValue();
      int length = ((Integer)args.next()).intValue();
      String strval = val.toString();

      message.setText("Value of " + var + " at " + linenr + ","
		      + column + " = " + strval);

      ValuePopup popup = new ValuePopup(getManager(), this, process,
					expr, var, value,
					new VarFormat());
      highlightVariable(start, length, popup);

      try {
	Rectangle rect = text.modelToView(start+length);
	popup.show(glass, text.getX() + rect.x+10,
		   text.getY() + rect.y-10);
      } catch (BadLocationException e) {
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

  //{{{ private void switchToFile(String file)

  private void switchToFile(String file)
  {
    unhighlightCpe();
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
  }

  //}}}

  //{{{ private Object addHighlight(Expr location, painter)

  private Object addHighlight(Expr location,
			      Highlighter.HighlightPainter painter,
			      boolean whole_line, boolean is_cpe)
  {
    String file = location.getLocationFileName();

    if (file.equals(currentFile)) {
      try {
	int start =
	  text.getLineStartOffset(location.getLocationStartLine()-1);

	if (!whole_line) {
	  start += location.getLocationStartColumn();
	}

	int end;
	int end_line = location.getLocationEndLine();
	int end_col = location.getLocationEndColumn();

	if (is_cpe) {
	  lineNumbers.setCpe(end_line);
	}


	if (whole_line || end_col == -1) {
	  end = text.getLineEndOffset(end_line-1);
	} else {
	  end = text.getLineStartOffset(end_line-1) + end_col;
	}

	return highlighter.addHighlight(start, end, painter);
      } catch (BadLocationException e) {
	System.err.println("bad coordinates: " + location
			   + ", source changed ???");
      }

    }

    return null;
  }

  //}}}

  //{{{ private void highlightVariable(int start, int length, varWindow)

  private void highlightVariable(int start, int length,
				 ValuePopup varWindow)
  {
    try {
      Object highlight = highlighter.addHighlight(start, start+length,
						  variablePainter);
      variableHighlights.put(varWindow, highlight);
    } catch (BadLocationException e) {
    }
  }

  //}}}

  //{{{ private void highlightCpe()

  private void highlightCpe()
  {
    Expr expr = process.getLastLocation();

    if (expr != null && expr.isLocation()) {
      Expr location = expr;

      String file = location.getLocationFileName();

      if (!file.equals(currentFile)) {
	switchToFile(file);
      } else {
	unhighlightCpe();
      }

      cpeHighlight = addHighlight(location, cpePainter, false, true);
    }
  }

  //}}}
  //{{{ private void unhighlightCpe()

  private void unhighlightCpe()
  {
    if (cpeHighlight != null) {
      highlighter.removeHighlight(cpeHighlight);
      cpeHighlight = null;
      lineNumbers.clearCpe();
      repaint();
    }
  }

  //}}}

  //{{{ private void highlightRule(Rule rule)

  private void highlightRule(Rule rule)
  {
    Expr location = rule.getLocation();
    if (location != null) {
      Highlighter.HighlightPainter painter;

      if (rule.isBreakpoint()) {
	painter = breakpointPainter;
	text.addBreakpoint(rule, location);
      } else {
	painter = watchpointPainter;
	text.addWatchpoint(rule, location);
      }
      Object highlight = addHighlight(location, painter, true, false);
      if (highlight != null) {
	ruleHighlights.put(rule, highlight);
      }
    }
  }

  //}}}
  //{{{ private void unhighlightRule(Rule rule)

  private void unhighlightRule(Rule rule)
  {
    Object highlight = ruleHighlights.remove(rule);
    if (highlight != null) {
      highlighter.removeHighlight(highlight);
      text.removeWatchpoint(rule);
      text.removeBreakpoint(rule);
      repaint();
    }
  }

  //}}}

  //{{{ private void showMenu(int x, int y)

  private void showMenu(int x, int y)
  {
    lastSelected = text.viewToModel(new Point(x, y));
    text.setSelectedPosition(lastSelected);

    menu = new JPopupMenu("Location Rules");
    menu.addPopupMenuListener(this);

    Rule rule = text.getRuleAt(x, y);
    lastSelectedRule = rule;
    if (rule == null) {
      menu.add(ITEM_ADD_BREAKPOINT).addActionListener(this);
      menu.add(ITEM_ADD_WATCHPOINT).addActionListener(this);
    } else {
      menu.add(ITEM_DELETE_RULE).addActionListener(this);
      menu.add(ITEM_EDIT_RULE).addActionListener(this);
    }
    menu.show(this, x, y);
  }

  //}}}
  //{{{ public void popupMenuWillBecomeVisible(PopupMenuEvent event)

  public void popupMenuWillBecomeVisible(PopupMenuEvent event)
  {
  }

  //}}}
  //{{{ public void popupMenuWillBecomeInvisible(PopupMenuEvent event)

  public void popupMenuWillBecomeInvisible(PopupMenuEvent event)
  {
    text.clearSelectedPosition();
  }

  //}}}
  //{{{ public void popupMenuCanceled(PopupMenuEvent event)

  public void popupMenuCanceled(PopupMenuEvent event)
  {
  }

  //}}}

  //{{{ private void showVariable(int x, int y)

  private void showVariable(int x, int y)
  {
    try {
      int pos = text.viewToModel(new Point(x, y));
      int linenr = text.getLine(pos);
      int col  = text.getColumn(pos);
      int start = text.getLineStartOffset(linenr-1);
      int end   = text.getLineEndOffset(linenr-1);
      String line = text.getText(start, end-start);

      if (line.equals("") || line.equals("\n")) {
	return;
      }

      Expr expr =
	Expr.make(Expr.factory.make(PAT_SOURCE_VAR,
				    new Integer(pos),
				    new Integer(linenr),
				    new Integer(col), line));
      process.requestEvaluation(expr, tag_view_var);
    } catch (BadLocationException e) {
      System.err.println(e.getMessage());
    }
  }

  //}}}

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (event.getActionCommand().equals(ITEM_ADD_BREAKPOINT)) {
      //{{{ Handle adding of breakpoints

      Expr location = Expr.makeLocation(currentFile,
					text.getLine(lastSelected),
					text.getColumn(lastSelected));
      process.requestRuleCreation(Port.makeStep(), location,
				  Expr.makeBreak(), tag_breakpoint, true);

      //}}}
    } else if (event.getActionCommand().equals(ITEM_ADD_WATCHPOINT)) {
      //{{{ Handle adding of watchpoints

      Expr location = Expr.makeLocation(currentFile,
					text.getLine(lastSelected),
					text.getColumn(lastSelected));
      Expr value = null;
      String expr = "";
      String title = "What value do you want to watch?";
      while (value == null) {
	expr = (String) JOptionPane.showInternalInputDialog(this, title,
	   "Watchpoint", JOptionPane.PLAIN_MESSAGE, null, null, expr);
	if (expr == null) {
	  return;
	}
	try {
	  value = Expr.make(expr);
	} catch (aterm.ParseError e) {
	  title = "Please enter a valid expression";
	}
      }
      process.requestRuleCreation(Port.makeStep(), location, value,
				  tag_watchpoint, true);

      //}}}
    } else if (event.getActionCommand().equals(ITEM_EDIT_RULE)) {
      //{{{ Handle editing of rules

      String toolName = RuleInspectorFactory.NAME;
      RuleInspector inspector = 
	(RuleInspector)getManager().launchProcessTool(toolName, process);
      inspector.editRule(lastSelectedRule);

      //}}}
    } else if (event.getActionCommand().equals(ITEM_DELETE_RULE)) {
      //{{{ Handle deletion of rules

      process.requestRuleDeletion(lastSelectedRule);

      //}}}
    }
  }

  //}}}

  //{{{ void removeValuePopup(ValuePopup popup)

  void removeValuePopup(ValuePopup popup)
  {
    popup.closePopup();
    Object highlight = variableHighlights.remove(popup);
    highlighter.removeHighlight(highlight);
    glass.remove(popup);
    repaint();
  }

  //}}}

  //{{{ public void mouseDragged(MouseEvent event)

  public void mouseDragged(MouseEvent event)
  {
    int x = event.getX() - text.getX();
    int y = event.getY() - text.getY();

    if ((event.getModifiers() & InputEvent.BUTTON1_MASK) != 0) {
      if (draggedPopup != null) {
	x += draggedPopup.getDragTransX();
	y += draggedPopup.getDragTransY();
	draggedPopup.setLocation(x, y);
	repaint();
      } else {
	Component comp = glass.findComponentAt(event.getX(), event.getY());
	if (comp instanceof ValuePopup) {
	  ValuePopup popup = (ValuePopup)comp;
	  popup.startDragging(x, y);
	  draggedPopup = popup;
	}
      }
    }
  }

  //}}}
  //{{{ public void mouseMoved(MouseEvent event)

  public void mouseMoved(MouseEvent event)
  {
  }

  //}}}
  //{{{ public void mouseClicked(MouseEvent e)

  public void mouseClicked(MouseEvent event)
  {
    if (!event.isShiftDown() && !event.isMetaDown()
	&& !event.isControlDown()) {
      Component comp = glass.findComponentAt(event.getX(), event.getY());
      if (comp instanceof ValuePopup) {
	ValuePopup popup = (ValuePopup)comp;
	if (event.getX() - popup.getX() < ValuePopup.ICON_SIZE) {
	  process.requestRuleDeletion(popup.getUpdateRule());
	} else {
	  popup.updateValue();
	}
      }
    }
  }

  //}}}
  //{{{ public void mouseEntered(MouseEvent e)

  public void mouseEntered(MouseEvent e)
  {
  }

  //}}}
  //{{{ public void mouseExited(MouseEvent e)

  public void mouseExited(MouseEvent e)
  {
  }

  //}}}
  //{{{ public void mousePressed(MouseEvent event)

  public void mousePressed(MouseEvent event)
  {
    Component comp = glass.findComponentAt(event.getX(), event.getY());
    if (comp instanceof ValuePopup) {
      ValuePopup popup = (ValuePopup)comp;
      if (event.isPopupTrigger()) {
	popup.showMenu(glass, event.getX(), event.getY());
      }
    } else {
      if (event.isPopupTrigger() && event.getX() > text.getX()) {
	showMenu(event.getX()-text.getX(), event.getY());
      } else {
	if (event.getClickCount() > 1
	    && comp == glass && event.getX() > text.getX()) {
	  showVariable(event.getX()-text.getX(), event.getY());
	}
      }
    }
  }

  //}}}
  //{{{ public void mouseReleased(MouseEvent e)

  public void mouseReleased(MouseEvent e)
  {
    draggedPopup = null;
  }

  //}}}
}

class SourceBrowser
  extends JTextArea
{
  private static final Color COLOR_SELECTED_POSITION = Color.red;

  private int selectedPosition;
  
  private Map breakpointLocations;
  private Map watchpointLocations;

  //{{{ public SourceBrowser()

  public SourceBrowser()
  {
    selectedPosition = -1;
    breakpointLocations = new HashMap();
    watchpointLocations = new HashMap();
  }

  //}}}
  //{{{ public void switchToFile(String fileName)

  public void clear()
  {
    breakpointLocations.clear();
    watchpointLocations.clear();
  }

  //}}}

  //{{{ public void setSelectedPosition(int pos)

  public void setSelectedPosition(int pos)
  {
    selectedPosition = pos;
    repaint();
  }

  //}}}
  //{{{ public void clearSelectedPosition()

  public void clearSelectedPosition()
  {
    selectedPosition = -1;
    repaint();
  }

  //}}}

  //{{{ int getLine(int offset)

  int getLine(int offset)
  {
    Document doc = getDocument();
    Element root = doc.getDefaultRootElement();
    return root.getElementIndex(offset)+1;
  }

  //}}}
  //{{{ int getColumn(int offset)

  int getColumn(int offset)
  {
    Document doc = getDocument();
    Element root = doc.getDefaultRootElement();
    Element line = root.getElement(root.getElementIndex(offset));

    return offset - line.getStartOffset();
  }

  //}}}

  //{{{ private void paintLocation(Graphics g, Expr loc)

  private void paintLocation(Graphics g, Expr loc)
  {
    try {
      int line = loc.getLocationStartLine();
      int col  = loc.getLocationStartColumn();
      int pos  = getLineStartOffset(loc.getLocationStartLine()-1);
      pos += col;
      Rectangle rect1 = modelToView(pos);
      Rectangle rect2 = modelToView(pos+1);
      int x = rect1.x - 1;
      int y = rect1.y;
      int w = rect2.x - x - 1;
      int h = rect1.height;
      g.drawRect(x, y, w, h);
      g.drawRect(x+1, y+1, w-2, h-2);
    } catch (BadLocationException e) {
    }
  }

  //}}}
  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
    super.paint(g);

    if (selectedPosition >= 0) {
      try {
	FontMetrics metrics = getFontMetrics(getFont());
	Rectangle rect = modelToView(selectedPosition);
	Rectangle rect_end = modelToView(selectedPosition+1);

	g.setColor(COLOR_SELECTED_POSITION);

	g.drawOval(rect.x-1, rect.y, rect_end.x-rect.x+1, rect.height);
      } catch (BadLocationException e) {
	selectedPosition = -1;
      }
    }
    
    // Paint watchpoints and breakpoints
    Iterator iter;

    g.setColor(SourceViewer.COLOR_WATCHPOINT);
    iter = watchpointLocations.values().iterator();
    while (iter.hasNext()) {
      paintLocation(g, (Expr)iter.next());
    }

    g.setColor(SourceViewer.COLOR_BREAKPOINT);
    iter = breakpointLocations.values().iterator();
    while (iter.hasNext()) {
      paintLocation(g, (Expr)iter.next());
    }
  }

  //}}}

  //{{{ public void addWatchpoint(Rule rule, Expr location)

  public void addWatchpoint(Rule rule, Expr location)
  {
    watchpointLocations.put(rule, location);
  }

  //}}}
  //{{{ public void removeWatchpoint(Rule rule)

  public void removeWatchpoint(Rule rule)
  {
    watchpointLocations.remove(rule);
  }

  //}}}
  //{{{ public void addBreakpoint(Rule rule, Expr location)

  public void addBreakpoint(Rule rule, Expr location)
  {
    breakpointLocations.put(rule, location);
  }

  //}}}
  //{{{ public void removeWatchpoint(Rule rule)

  public void removeBreakpoint(Rule rule)
  {
    breakpointLocations.remove(rule);
  }

  //}}}

  //{{{ public Rule getRuleAt(int x, int y)

  public Rule getRuleAt(int x, int y)
  {
    int pos = viewToModel(new Point(x, y));
    int linenr = getLine(pos);
    int column = getColumn(pos);

    Iterator iter;
    iter = breakpointLocations.keySet().iterator();
    while (iter.hasNext()) {
      Rule rule = (Rule)iter.next();
      Expr location = (Expr)breakpointLocations.get(rule);
      if (location.getLocationStartLine() == linenr &&
	  location.getLocationStartColumn() == column) {
	return rule;
      }
    }

    iter = watchpointLocations.keySet().iterator();
    while (iter.hasNext()) {
      Rule rule = (Rule)iter.next();
      Expr location = (Expr)watchpointLocations.get(rule);
      if (location.getLocationStartLine() == linenr &&
	  location.getLocationStartColumn() == column) {
	return rule;
      }
    }

    return null;
  }

  //}}}
}

class LineNumberCanvas
  extends JComponent
{
  private final static int BORDER = 2;
  JTextArea text;
  FontMetrics fontMetrics;
  FontMetrics sourceMetrics;
  int cpe;
  Polygon cpePoly;

  //{{{ public LineNumberCanvas(JTextArea text)

  public LineNumberCanvas(JTextArea text)
  {
    this.text = text;
  }

  //}}}

  //{{{ private void checkMetrics()

  private void checkMetrics()
  {
    if (fontMetrics != getFontMetrics(getFont())
	|| sourceMetrics != text.getFontMetrics(text.getFont())) {
      fontMetrics = getFontMetrics(getFont());
      sourceMetrics = text.getFontMetrics(text.getFont());

      cpePoly = new Polygon();
      cpePoly.addPoint(0, 0);
      cpePoly.addPoint(fontMetrics.stringWidth("1999"),
		       sourceMetrics.getHeight()/2);
      cpePoly.addPoint(0, sourceMetrics.getHeight());
    }
  }

  //}}}

  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
    Dimension dim = getSize();
    Rectangle clip = g.getClipBounds();

    checkMetrics();

    g.setColor(getBackground());
    g.fillRect(clip.x, clip.y, clip.width, clip.height);

    int line = clip.y/sourceMetrics.getHeight();
    int y =  line * sourceMetrics.getHeight();
    line++;

    while (y < (clip.y + clip.height)) {
      if (line == cpe) {
	g.setColor(SourceViewer.COLOR_CPE);
	cpePoly.translate(0, y);
	g.fillPolygon(cpePoly);
	cpePoly.translate(0, -y);
      }

      g.setColor(getForeground());
      String label = String.valueOf(line++);
      g.drawString(label, dim.width-fontMetrics.stringWidth(label)-BORDER,
		   y+sourceMetrics.getMaxAscent());
      y += sourceMetrics.getHeight();
    }

  }

  //}}}
  //{{{ public Dimension getPreferredSize()

  public Dimension getPreferredSize()
  {
    checkMetrics();

    return new Dimension(fontMetrics.stringWidth("1999") + BORDER, 0);
  }

  //}}}
  //{{{ public Dimension getMinimumSize()

  public Dimension getMinimumSize()
  {
    return getPreferredSize();
  }

  //}}}

  //{{{ public void setCpe(int line)

  public void setCpe(int line)
  {
    cpe = line;
    repaint();
  }

  //}}}
  //{{{ public void clearCpe()

  public void clearCpe()
  {
    cpe = -1;
    repaint();
  }

  //}}}
}

class GlassPane
  extends JLayeredPane
{
  private JComponent glass;
  private JComponent component;

  //{{{ public GlassPane(JComponent glass, JComponent component)

  public GlassPane(JComponent glass, JComponent component)
  {
    this.glass = glass;
    this.component = component;

    setLayout(new GridLayout(2,0));

    add(component, new Integer(1));
    add(glass, new Integer(2));

    component.setLocation(0,0);
    glass.setLocation(0,0);
  }

  //}}}

  //{{{ public Dimension getPreferredSize()

  public Dimension getPreferredSize()
  {
    return component.getPreferredSize();
  }

  //}}}
}
