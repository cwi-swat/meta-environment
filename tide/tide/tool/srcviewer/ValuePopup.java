package tide.tool.srcviewer;

//{{{ imports

import java.awt.*;
import java.awt.event.*;
import java.net.URL;

import javax.swing.*;

import tide.tool.ToolManager;
import tide.tool.ruleinspector.*;
import tide.tool.support.*;

//}}}

class ValuePopup
  extends JPanel
  implements DebugProcessListener, ProcessStatusChangeListener,
             ActionListener
{
  //{{{ Constants

  public final static int ICON_SIZE = 14;

  private final static String TAG_UPDATE     = "vp-update";

  /*
  private final static Color COLOR_BACK_CLEAN= new Color(0xFF,0xCC,0xCC);
  private final static Color COLOR_BACK_DIRTY= new Color(0xFF,0x99,0x99);
  */
  private final static Color COLOR_BACK_CLEAN= new Color(0xEE,0xEE,0x00);
  private final static Color COLOR_BACK_DIRTY= new Color(0xCC,0xCC,0x00);
  private final static Color COLOR_BORDER    = new Color(0x00,0x00,0x00);

  private final static String ITEM_EDIT_RULE     = "Edit Rule";
  private final static String ITEM_VIEW_VARIABLE = "View Variable";

  //}}}

  //{{{ Attributes

  private static int next_id = 0;

  private int id;
  private ToolManager manager;
  private SourceFileViewer viewer;

  private String tag_update;

  private DebugProcess process;
  private Rule updateRule;
  private Expr expr;
  private String label;
  private ExprFormat format;

  private boolean uptodate;
  
  private String content;
  private Font font;
  private FontMetrics metrics;
  private Icon closeIcon;

  private int drag_trans_x;
  private int drag_trans_y;

  private JPopupMenu menu;

  //}}}

  //{{{ public ValuePopup(manager, viewer, process, expr, label, initial)

  public ValuePopup(ToolManager manager, SourceFileViewer viewer,
		    DebugProcess process, Expr expr,
		    String label, Expr initial_value, ExprFormat fmt)
  {
    this.id      = next_id++;
    this.manager = manager;
    this.viewer  = viewer;
    this.process = process;
    this.expr    = expr;
    this.label   = label;
    this.format  = fmt;

    tag_update   = TAG_UPDATE + "-" + id;

    uptodate = true;

    process.addDebugProcessListener(this);
    process.addProcessStatusChangeListener(this);

    closeIcon = loadIcon("mini-close.gif");

    content = label + "=" + format.format(initial_value);

    setLayout(new BorderLayout());

    setBackground(new Color(0xFF, 0xFF, 0x00));
    this.setOpaque(true);
    setDoubleBuffered(true);
    font = new Font("Helvetica", Font.BOLD, 12);
    metrics = getFontMetrics(font);

    setSize(getPreferredSize());

    process.requestRuleCreation(Port.makeStopped(), Expr.makeTrue(),
				expr, tag_update, true);

    //{{{ Create menu

    menu = new JPopupMenu("Variable " + label);
    menu.add(ITEM_EDIT_RULE).addActionListener(this);
    menu.add(ITEM_VIEW_VARIABLE).addActionListener(this);

    //}}}
  }

  //}}}
  //{{{ public Rule getUpdateRule()

  public Rule getUpdateRule()
  {
    return updateRule;
  }

  //}}}
  //{{{ private loadIcon(String name)

  private Icon loadIcon(String name)
  {
    URL url = getClass().getClassLoader().getResource("images/" + name);
    return new ImageIcon(url);
  }

  //}}}
  //{{{ public Dimension getPreferredSize()

  public Dimension getPreferredSize()
  {
    return 
      new Dimension(ICON_SIZE + 4 + metrics.stringWidth(content), 
		    Math.max(ICON_SIZE+4, 
			     2 + metrics.getMaxAscent()
			     + metrics.getMaxDescent()));
  }

  //}}}
  //{{{ public void paint(Graphics g)

  public void paint(Graphics g)
  {
    int width = getSize().width;
    int height = getSize().height;

    g.setFont(font);
    g.setColor(uptodate ? COLOR_BACK_CLEAN : COLOR_BACK_DIRTY);
    g.fillRect(0, 0, width, height);
    g.setColor(COLOR_BORDER);
    g.drawRect(0, 0, width-1, height-1);
    g.setColor(Color.black);

    closeIcon.paintIcon(this, g, 0, (height-ICON_SIZE)/2);
    g.drawString(content, ICON_SIZE + 3, (height-metrics.getHeight())/2
		 + metrics.getMaxAscent()+1);
  }

  //}}}
  //{{{ public void show(JComponent invoker, int x, int y) 

  public void show(JComponent invoker, int x, int y) 
  {
    Point p = new Point(x,y);
    //SwingUtilities.convertPointFromScreen(p,invoker.getRootPane().getLayeredPane());
    this.setBounds(p.x,p.y,getSize().width, getSize().height);
    /*
    invoker.getRootPane().getLayeredPane().add(this,
					       JLayeredPane.POPUP_LAYER,0);
					       */
    invoker.add(this);
    setVisible(true);
    invoker.repaint(p.x, p.y, getSize().width, getSize().height);
  }

  //}}}
  //{{{ public void remove() 

  public void remove() 
  {
    Container parent = getParent();
    Rectangle r = this.getBounds();
    if(parent != null) {
      parent.remove(this);
      parent.repaint(r.x, r.y, r.width, r.height);
    }
  }

  //}}}
  //{{{ public void startDragging(int start_x, int start_y)

  public void startDragging(int start_x, int start_y)
  {
    drag_trans_x = getX() - start_x;
    drag_trans_y = getY() - start_y;
  }

  //}}}
  //{{{ public int getDragTransX()

  public int getDragTransX()
  {
    return drag_trans_x;
  }

  //}}}
  //{{{ public int getDragTransY()

  public int getDragTransY()
  {
    return drag_trans_y;
  }

  //}}}

  //{{{ public void closePopup()

  public void closePopup()
  {
    process.removeProcessStatusChangeListener(this);
    process.removeDebugProcessListener(this);
  }

  //}}}
  //{{{ public void updateValue()

  public void updateValue()
  {
    process.requestEvaluation(expr, tag_update);
  }

  //}}}
  //{{{ public void showMenu(Component parent, int x, int y)

  public void showMenu(Component parent, int x, int y)
  {
    menu.show(parent, x, y);
  }

  //}}}

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    if (event.getActionCommand().equals(ITEM_EDIT_RULE)) {
      String toolName = RuleInspectorFactory.NAME;
      RuleInspector inspector = 
	(RuleInspector)manager.launchProcessTool(toolName, process);
      inspector.editRule(updateRule);
    } else if (event.getActionCommand().equals(ITEM_VIEW_VARIABLE)) {
    }
  }

  //}}}

  //{{{ public void processStatusChanged(DebugProcess process)

  public void processStatusChanged(DebugProcess process)
  {
    if (process.isRunning()) {
      uptodate = false;
      repaint();
    }
  }

  //}}}

  //{{{ private void updateValue(Expr value)

  private void updateValue(Expr value)
  {
    content = label + "=" + format.format(value);
    uptodate = process.isStopped();
    setSize(getPreferredSize());
    repaint();
  }

  //}}}

  //{{{ public void ruleCreated(DebugProcess process, Rule rule)

  public void ruleCreated(DebugProcess process, Rule rule)
  {
    if (rule.getTag().equals(tag_update)) {
      updateRule = rule;
    }
  }

  //}}}
  //{{{ public void ruleDeleted(DebugProcess process, Rule rule)

  public void ruleDeleted(DebugProcess process, Rule rule)
  {
    if (rule == updateRule) {
      viewer.removeValuePopup(this);
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
    if (rule == updateRule) {
      updateValue(value);
    }
  }

  //}}}
  //{{{ public void evaluationResult(process, expr, value, tag)

  public void evaluationResult(DebugProcess process, Expr expr,
			       Expr value, String tag)
  {
    if (tag.equals(tag_update)) {
      updateValue(value);
    }
  }

  //}}}
  //{{{ public void selectRule(DebugProcess process, Rule rule)

  public void selectRule(DebugProcess process, Rule rule)
  {
  }

  //}}}
}

