package tide.tool.srcviewer;

//{{{ imports

import java.awt.*;
import java.awt.event.*;
import java.io.*;
import java.util.*;

import javax.swing.*;
import javax.swing.event.*;
import javax.swing.text.*;

import tide.*;
import tide.tool.ToolManager;
import tide.tool.support.*;

//}}}

class SourceFileViewer
  extends JScrollPane
  implements MouseListener, MouseMotionListener, PopupMenuListener,
             ActionListener, DebugProcessListener,
	     PreferenceListener
{
  //{{{ Constants

  private static final String ITEM_ADD_BREAKPOINT = "Add Breakpoint";
  private static final String ITEM_ADD_WATCHPOINT = "Add Watchpoint";
  private static final String ITEM_EDIT_RULE      = "Edit Rule";
  private static final String ITEM_DELETE_RULE    = "Delete Rule";

  static final Color COLOR_CPE        = new Color(0xDD,0xDD,0xFF);
  static final Color COLOR_VARIABLE   = new Color(0xEE,0xEE,0x00);
  static final Color COLOR_BREAK      = new Color(0xFF,0xCC,0xCC);
  static final Color COLOR_BREAKPOINT = new Color(0xCC,0x00,0x00);
  static final Color COLOR_WATCH      = new Color(0xCC,0xFF,0xCC);
  static final Color COLOR_WATCHPOINT = new Color(0x00,0x99,0x00);
  static final Color COLOR_LINEBG     = new Color(0xF0,0xF0,0xF0);

  private static final String TAG_BREAKPOINT = "sv-breakpoint";
  private static final String TAG_WATCHPOINT = "sv-watchpoint";

  //}}}

  //{{{ Attributes

  private ToolManager manager;
  private PreferenceSet prefs;
  private DebugProcess process;
  private String file;
  private String tag_view_var;
  private int id;

  private JPopupMenu    menu;

  private String tag_breakpoint;
  private String tag_watchpoint;

  private JLayeredPane pane;
  private LineNumberCanvas lineNumbers;
  private SourceBrowser text;
  private JPanel glass;

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

  //{{{ public SourceFileViewer(manager, process, file, id, tag_vv)

  public SourceFileViewer(ToolManager manager, DebugProcess process,
			  String file, int id, String tag_view_var)
  {
    this.manager = manager;
    this.process = process;
    this.file = file;
    this.tag_view_var = tag_view_var;
    process.addDebugProcessListener(this);

    prefs = manager.getPreferences();
    prefs.addPreferenceListener(this);

    tag_breakpoint = TAG_BREAKPOINT + "-" + id;
    tag_watchpoint = TAG_WATCHPOINT + "-" + id;

    glass = new JPanel();
    glass.setOpaque(false);
    glass.setLayout(null);

    text = new SourceBrowser();

    lineNumbers = new LineNumberCanvas(text);
    lineNumbers.setBackground(COLOR_LINEBG);

    preferencesChanged(prefs);

    JPanel textPanel = new JPanel();
    textPanel.setLayout(new BorderLayout());
    textPanel.add("Center", text);
    textPanel.add("West", lineNumbers);

    ScrollablePane pane = new ScrollablePane(textPanel, glass, text);
    setViewportView(pane);

    //{{{ Listen to MouseEvents

    glass.addMouseListener(this);
    glass.addMouseMotionListener(this);

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

    //}}}

    try {
      text.read(new BufferedReader(new FileReader(file)), null);
    } catch (IOException e) {
      System.err.println("cannot find source file " + file);
    }
  }

  //}}}

  //{{{ public String getFile()

  public String getFile()
  {
    return file;
  }

  //}}}
  
  //{{{ protected void cleanup()

  protected void cleanup()
  {
    process.removeDebugProcessListener(this);
    prefs.removePreferenceListener(this);
  }

  //}}}

  //{{{ protected void highlightRules(Iterator rules)

  protected void highlightRules(Iterator rules)
  {
    while (rules.hasNext()) {
      Rule rule = (Rule)rules.next();
      highlightRule(rule);
    }
  }

  //}}}
  //{{{ private void highlightRule(Rule rule)

  private void highlightRule(Rule rule)
  {
    Expr location = rule.getLocation();
    if (location != null
	&& location.isLocation()
	&& location.getLocationFileName().equals(file)) {

      lineNumbers.addLocationRule(rule, location.getLocationStartLine());
      //Highlighter.HighlightPainter painter;

      if (rule.isBreakpoint()) {
	//painter = breakpointPainter;
	text.addBreakpoint(rule, location);
      } else {
	//painter = watchpointPainter;
	text.addWatchpoint(rule, location);
      }
      /*
      Object highlight = addHighlight(location, painter, true, false);
      if (highlight != null) {
	ruleHighlights.put(rule, highlight);
      }
      */
      repaint();
    }
  }

  //}}}
  //{{{ private void unhighlightRule(Rule rule)

  private void unhighlightRule(Rule rule)
  {
    /*Object highlight = ruleHighlights.remove(rule);
    if (highlight != null) {
      highlighter.removeHighlight(highlight);
    */
    text.removeWatchpoint(rule);
    text.removeBreakpoint(rule);
    lineNumbers.removeLocationRule(rule);
    repaint();
  }

  //}}}

  //{{{ protected void highlightCpe()

  protected void highlightCpe()
  {
    if (cpeHighlight != null) {
      unhighlightCpe();
    }
    Expr location = process.getLastLocation();
    cpeHighlight = addHighlight(location, cpePainter, false, true);
    centerAround(location);
  }

  //}}}
  //{{{ protected void unhighlightCpe()

  protected void unhighlightCpe()
  {
    if (cpeHighlight != null) {
      highlighter.removeHighlight(cpeHighlight);
      cpeHighlight = null;
      lineNumbers.clearCpe();
      repaint();
    }
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

      Expr expr = Expr.makeSourceVar(file, pos, linenr, col, line);
      process.requestEvaluation(expr, tag_view_var);
    } catch (BadLocationException e) {
      System.err.println(e.getMessage());
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

  //{{{ private void centerAround(Expr location)

  private void centerAround(Expr location)
  {
    try {
      int start =
	text.getLineStartOffset(location.getLocationStartLine()-1);
      Rectangle rect = text.modelToView(start);
      if (rect != null) {
	JViewport viewport = getViewport();

	// Make rectangle relative to viewport, and add
	// some extra context to make behaviour more intuitive
	rect.x -= (viewport.getViewPosition().x + 20);
	rect.y -= (viewport.getViewPosition().y + 20);
	rect.height += 40;
	rect.width += 40;
	viewport.scrollRectToVisible(rect);
      }
      /*
      if (rect != null) {
	JScrollBar vertical = getVerticalScrollBar();
	vertical.setValue(Math.max(rect.y-20, rect.y));
      }
      */
      //System.out.println("rect = " + rect);
    } catch (BadLocationException e) {
      System.out.println("bad location of cpe: " + e.getMessage());
    }
  }

  //}}}

  //{{{ protected Object addHighlight(Expr location, painter)

  protected Object addHighlight(Expr location,
				Highlighter.HighlightPainter painter,
				boolean whole_line, boolean is_cpe)
  {
    String file = location.getLocationFileName();

    if (file.equals(this.file)) {
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
  //{{{ protected void highlightVariable(start, length, varWindow)

  protected void highlightVariable(int start, int length,
				   ValuePopup varWindow)
  {
    try {
      Object highlight = highlighter.addHighlight(start, start+length,
						  variablePainter);
      variableHighlights.put(varWindow, highlight);
      Rectangle rect = text.modelToView(start+length);
      varWindow.show(glass, text.getX() + rect.x+10,
		     text.getY() + rect.y-10);
    } catch (BadLocationException e) {
      System.err.println("bad location: " + e.getMessage());
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
    menu.show(glass, x, y);
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

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (event.getActionCommand().equals(ITEM_ADD_BREAKPOINT)) {
      //{{{ Handle adding of breakpoints

      Expr location = Expr.makeLocation(file,
					text.getLine(lastSelected),
					text.getColumn(lastSelected));
      process.requestRuleCreation(Port.makeStep(), location,
				  Expr.makeBreak(), tag_breakpoint, true);

      //}}}
    } else if (event.getActionCommand().equals(ITEM_ADD_WATCHPOINT)) {
      //{{{ Handle adding of watchpoints

      Expr location = Expr.makeLocation(file,
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

      manager.editRule(process, lastSelectedRule);

      //}}}
    } else if (event.getActionCommand().equals(ITEM_DELETE_RULE)) {
      //{{{ Handle deletion of rules

      process.requestRuleDeletion(lastSelectedRule);

      //}}}
    }
  }

  //}}}

  //{{{ public void ruleCreated(DebugProcess process, Rule rule)

  public void ruleCreated(DebugProcess process, Rule rule)
  {
    highlightRule(rule);
  }

  //}}}
  //{{{ public void ruleDeleted(DebugProcess process, Rule rule)

  public void ruleDeleted(DebugProcess process, Rule rule)
  {
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
  //{{{ public void evaluationResult(DebugProcess process, Expr expr,

  public void evaluationResult(DebugProcess process, Expr expr,
			       Expr value, String tag)
  {
  }

  //}}}

  //{{{ public void preferencesChanged(PreferenceSet set)

  public void preferencesChanged(PreferenceSet prefs)
  {
    String prefName = SourceViewerFactory.PREF_SOURCECODE_FONT;
    Font font = prefs.getFontPreference(prefName);
    text.setFont(font);
    getVerticalScrollBar().setUnitIncrement(getFontMetrics(font).getHeight());
    prefName = SourceViewerFactory.PREF_LINENUMBER_FONT;
    lineNumbers.setFont(prefs.getFontPreference(prefName));
    repaint();
  }

  //}}}
  //{{{ public void preferenceChanged(prefs, name, oldValue, newValue)

  public void preferenceChanged(PreferenceSet prefs, String name,
				String oldValue, String newValue)
  {
    if (name.equals(SourceViewerFactory.PREF_SOURCECODE_FONT) ||
	name.equals(SourceViewerFactory.PREF_LINENUMBER_FONT)) {
      preferencesChanged(prefs);
    }
  }

  //}}}
  //{{{ public void preferencesStatusChanged(PreferenceSet set, boolean clean)

  public void preferencesStatusChanged(PreferenceSet set, boolean clean)
  {
  }

  //}}}
}

class ScrollablePane
  extends JLayeredPane
  implements Scrollable
{
  private SourceBrowser text;

  //{{{ public ScrollablePane(JPanel textPanel, JPanel glass, text)

  public ScrollablePane(JPanel textPanel, JPanel glass, SourceBrowser text)
  {
    this.text = text;

    setLayout(new OverlayLayout(this));
    add(textPanel, new Integer(1));
    add(glass, new Integer(2));
  }

  //}}}
  //{{{ public int getScrollableBlockIncrement(visibleRect, orientation, direction)

  public int getScrollableBlockIncrement(Rectangle visibleRect, int orientation,
					 int direction)
  {
    if (orientation == SwingConstants.HORIZONTAL) {
      return visibleRect.width;
    } else {
      return visibleRect.height;
    }
  }

  //}}}
  //{{{ public int getScrollableUnitIncrement(visibleRect, orientation, direction)

  public int getScrollableUnitIncrement(Rectangle visibleRect, int orientation,
					int direction)
  {
    Font font = text.getFont();
    FontMetrics metrics = text.getFontMetrics(font);

    if (orientation == SwingConstants.HORIZONTAL) {
      return metrics.getMaxAdvance();
    } else {
      return metrics.getHeight();
    }
  }

  //}}}

  //{{{ public Dimension getPreferredScrollableViewportSize()

  public Dimension getPreferredScrollableViewportSize()
  {
    return text.getPreferredSize();
  }

  //}}}
  //{{{ public boolean getScrollableTracksViewportHeight()

  public boolean getScrollableTracksViewportHeight()
  {
    return false;
  }

  //}}}
  //{{{ public boolean getScrollableTracksViewportWidth()

  public boolean getScrollableTracksViewportWidth()
  {
    return false;
  }

  //}}}
}

