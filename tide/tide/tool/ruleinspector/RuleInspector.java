package tide.tool.ruleinspector;

//{{{ imports

import java.util.*;
import java.awt.*;
import java.awt.event.*;
import javax.swing.*;
import javax.swing.event.*;
import javax.swing.table.*;
import javax.swing.border.*;

import tide.tool.*;
import tide.tool.support.*;

//}}}

public class RuleInspector
  extends ProcessTool
  implements DebugAdapterListener
{
  private RuleSelector selector;
  private RuleEditor   editor;

  //{{{ public RuleInspector(ToolManager manager, final DebugProcess process)

  public RuleInspector(ToolManager manager, final DebugProcess process)
  {
    super(manager, process);

    setSize(360, 350);

    setTitle("RuleInspector: " + process.getName());

    Container cont = getContentPane();
    cont.setLayout(new GridLayout(0,1));

    selector = new RuleSelector(process);
    editor   = new RuleEditor(process);
    selector.addRuleSelectionListener(editor);

    cont.add(selector);
    cont.add(editor);

    selector.setBackground(Color.white);
    editor.setBackground(Color.white);

    addInternalFrameListener(new InternalFrameAdapter() 
      {
        public void internalFrameClosed(InternalFrameEvent event) {
	  cleanup();
	}
      }
    );

    DebugAdapter adapter = process.getAdapter();
    adapter.addDebugAdapterListener(this);
  }

  //}}}
  //{{{ public void editRule(Rule rule)

  public void editRule(Rule rule)
  {
    selector.selectRule(rule);
  }

  //}}}

  //{{{ private void cleanup()

  private void cleanup()
  {
    selector.cleanup();
    editor.cleanup();
    process.getAdapter().removeDebugAdapterListener(this);
    getManager().removeTool(this);
  }

  //}}}

  //{{{ public void processDestroyed(DebugAdapter adapter, DebugProcess proc)

  public void processDestroyed(DebugAdapter adapter, DebugProcess proc)
  {
    if (proc == process) {
      destroy();
    }
  }

  //}}}
  //{{{ public void processCreated(DebugAdapter adapter, DebugProcess proc)

  public void processCreated(DebugAdapter adapter, DebugProcess proc)
  {
  }

  //}}}
}

class RuleSelector
  extends JPanel
  implements DebugProcessListener, ListSelectionListener
{
  private DebugProcess process;

  java.util.List listeners;

  RuleSelectorTableModel tableModel;
  JTable table;

  //{{{ public RuleSelector(DebugProcess process)

  public RuleSelector(DebugProcess process)
  {
    this.process = process;
    listeners = new LinkedList();
    setBorder(new TitledBorder(new LineBorder(Color.gray), "Rule Selector"));

    tableModel = new RuleSelectorTableModel(process);
    table = new JTable(tableModel);

    ListSelectionModel selModel = table.getSelectionModel();
    selModel.addListSelectionListener(this);

    TableColumn column_id = table.getColumn(tableModel.getColumnName(0));
    column_id.setMaxWidth(30);
    DefaultTableCellRenderer renderer = new DefaultTableCellRenderer();
    renderer.setHorizontalAlignment(JLabel.CENTER);
    column_id.setCellRenderer(renderer);

    setLayout(new BorderLayout());
    add(new JScrollPane(table), "Center");

    process.addDebugProcessListener(this);
  }

  //}}}
  //{{{ public void cleanup()

  public void cleanup()
  {
    process.removeDebugProcessListener(this);
  }

  //}}}
  //{{{ public void addRuleSelectionListener(RuleSelectionListener listener)

  public void addRuleSelectionListener(RuleSelectionListener listener)
  {
    listeners.add(listener);
  }

  //}}}
  //{{{ private void fireRuleSelected(Rule rule)

  private void fireRuleSelected(Rule rule)
  {
    Iterator iter = listeners.iterator();
    while (iter.hasNext()) {
      RuleSelectionListener listener = (RuleSelectionListener)iter.next();
      listener.ruleSelected(rule);
    }
  }

  //}}}
  //{{{ public void ruleCreated(DebugProcess process, Rule rule)

  public void ruleCreated(DebugProcess process, Rule rule)
  {
    int index = process.getNrOfRules()-1;
    tableModel.fireTableChanged(new TableModelEvent(tableModel, index, index,
						    TableModelEvent.ALL_COLUMNS,
						    TableModelEvent.INSERT));
  }

  //}}}
  //{{{ public void ruleDeleted(DebugProcess process, Rule rule)

  public void ruleDeleted(DebugProcess process, Rule rule)
  {
    int index = process.getRuleIndex(rule);
    tableModel.fireTableChanged(new TableModelEvent(tableModel, index, index,
						    TableModelEvent.ALL_COLUMNS,
						    TableModelEvent.DELETE));
  }

  //}}}
  //{{{ public void ruleModified(DebugProcess process, Rule rule)

  public void ruleModified(DebugProcess process, Rule rule)
  {
    int index = process.getRuleIndex(rule);
    tableModel.fireTableChanged(new TableModelEvent(tableModel, index, index,
						    TableModelEvent.ALL_COLUMNS,
						    TableModelEvent.UPDATE));
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
  }

  //}}}

  //{{{ void selectRule(Rule rule)

  void selectRule(Rule rule)
  {
    int index = process.getRuleIndex(rule);
    table.changeSelection(index, 0, false, false);
    fireRuleSelected(rule);
  }

  //}}}

  //{{{ public void valueChanged(ListSelectionEvent event)

  public void valueChanged(ListSelectionEvent event)
  {
  	int row = table.getSelectedRow();
  	
  	if (row != -1) {
      Rule rule = process.getRuleAt(row);
      fireRuleSelected(rule);
  	}
  }

  //}}}
}

class RuleSelectorTableModel
  extends AbstractTableModel
{
  private DebugProcess process;

  //{{{ public RuleSelectorTableModel(DebugProcess process)

  public RuleSelectorTableModel(DebugProcess process)
  {
    this.process = process;
  }

  //}}}
  //{{{ public int getRowCount()

  public int getRowCount()
  {
    return process.getNrOfRules();
  }

  //}}}
  //{{{ public int getColumnCount()

  public int getColumnCount()
  {
    return 3;
  }

  //}}}
  //{{{ public Object getValueAt(int row, int col)

  public Object getValueAt(int row, int col)
  {
    Rule rule = process.getRuleAt(row);
    switch (col) {
      case 0:
	return new Integer(rule.getRid());
      case 1:
	return rule.getTag();
      case 2:
	return rule.getPort().toTerm();
    }

    throw new RuntimeException("illegal column: " + col);
  }

  //}}}
  //{{{ public String getColumnName(int col)

  public String getColumnName(int col)
  {
    switch (col) {
      case 0: return "Id";
      case 1: return "Tag";
      case 2: return "Port";
    }
    throw new RuntimeException("illegal column: " + col);
  }

  //}}}
  //{{{ public Class getColumnClass(int col)

  public Class getColumnClass(int col)
  {
    return getValueAt(0, col).getClass();
  }

  //}}}
}

class RuleEditor
  extends JPanel
  implements RuleSelectionListener, ActionListener, DebugProcessListener
{
  private final static Color COLOR_MODIFIED   = Color.red;
  private final static Color COLOR_UNMODIFIED = Color.black;

  DebugProcess process;
  Rule rule;
  TitledBorder border;

  boolean modified;

  //{{{ UI attributes

  JLabel     tag;
  JCheckBox  enabled;
  JLabel     portLabel;
  JComboBox  port;
  JLabel     conditionLabel;
  JTextField condition;
  JLabel     actionLabel;
  JTextArea  action;

  JButton createButton;
  JButton applyButton;
  JButton revertButton;
  JButton deleteButton;

  //}}}

  //{{{ public RuleEditor(DebugProcess process)

  public RuleEditor(DebugProcess process)
  {
    this.process = process;

    //{{{ Create UI components 

    border = new TitledBorder(new LineBorder(Color.gray), "Rule Editor");
    setBorder(border);

    tag = new JLabel();
    tag.setForeground(COLOR_UNMODIFIED);
    enabled = new JCheckBox("Enabled");
    portLabel = new JLabel("Port:");
    port = new JComboBox();
    port.setEnabled(false);

    for (int i=0; i<DebugProcess.PORT_TYPES.length; i++) {
      port.addItem(DebugProcess.PORT_TYPES[i]);
    }

    conditionLabel = new JLabel("Condition:");
    condition = new JTextField();
    actionLabel = new JLabel("Action:", JLabel.CENTER);
    action = new JTextArea();
    createButton = new JButton("Create");
    applyButton = new JButton("Apply");
    revertButton = new JButton("Revert");
    deleteButton = new JButton("Delete");


    //}}}

    //{{{ Add event listeners

    process.addDebugProcessListener(this);

    enabled.addActionListener(this);
    createButton.addActionListener(this);
    applyButton.addActionListener(this);
    revertButton.addActionListener(this);
    deleteButton.addActionListener(this);
    port.addActionListener(this);
    condition.addActionListener(this);
    
    condition.getDocument().addDocumentListener(new DocumentListener()
      {
        public void changedUpdate(DocumentEvent evt) { 
	  conditionLabel.setForeground(COLOR_MODIFIED);
	  setModified(true);
	}
        public void insertUpdate(DocumentEvent evt) { 
	  conditionLabel.setForeground(COLOR_MODIFIED);
	  setModified(true);
	}
        public void removeUpdate(DocumentEvent evt) { 
	  conditionLabel.setForeground(COLOR_MODIFIED);
	  setModified(true);
	}
      });

    action.addInputMethodListener(new InputMethodListener()
      {
        public void caretPositionChanged(InputMethodEvent evt) { }
	public void inputMethodTextChanged(InputMethodEvent evt) {
	  actionLabel.setForeground(COLOR_MODIFIED);
	}
      });

    //}}}

    //{{{ Build UI

    setLayout(new BorderLayout());
    JPanel top = new JPanel();
    top.setLayout(new BorderLayout());
    JPanel labels = new JPanel();
    labels.setLayout(new GridLayout(3,1));

    JLabel tagLabel = new JLabel("Tag:");
    tagLabel.setForeground(COLOR_UNMODIFIED);
    labels.add(tagLabel);
    labels.add(portLabel);
    labels.add(conditionLabel);
    top.add("West", labels);

    JPanel controls = new JPanel();
    controls.setLayout(new GridLayout(3,1));

    JPanel tagAndEnabling = new JPanel();
    tagAndEnabling.setLayout(new BorderLayout());
    tagAndEnabling.add("West", tag);
    tagAndEnabling.add("East", enabled);
    controls.add(tagAndEnabling);
    controls.add(port);
    controls.add(condition);
    top.add("Center", controls);

    JPanel bottom = new JPanel();
    bottom.setLayout(new BorderLayout());
    bottom.add(actionLabel, "North");
    bottom.add(action, "Center");

    JPanel buttons = new JPanel();
    buttons.setLayout(new GridLayout(1,0));
    buttons.add(createButton);
    buttons.add(applyButton);
    buttons.add(revertButton);
    buttons.add(deleteButton);

    add("North",  top);
    add("Center", bottom);
    add("South",  buttons);


    //}}}

    clear();
  }

  //}}}
  //{{{ public void cleanup()

  public void cleanup()
  {
    process.removeDebugProcessListener(this);
  }

  //}}}
  //{{{ public void clear()

  public void clear()
  {
    tag.setText("-");
    enabled.setSelected(false);
    enabled.setEnabled(false);
    port.setSelectedIndex(0);
    port.setEnabled(false);
    condition.setText("");
    condition.setEnabled(false);
    action.setText("");
    action.setEnabled(false);


    applyButton.setEnabled(false);
    revertButton.setEnabled(false);
    deleteButton.setEnabled(false);

    enabled.setForeground(COLOR_UNMODIFIED);
    portLabel.setForeground(COLOR_UNMODIFIED);
    conditionLabel.setForeground(COLOR_UNMODIFIED);
    actionLabel.setForeground(COLOR_UNMODIFIED);
  }

  //}}}
  //{{{ public void ruleSelected(Rule rule)

  public void ruleSelected(Rule rule)
  {
    this.rule = rule;
    border.setTitle("Rule Editor: Rule " + rule.getRid());

    tag.setText(rule.getTag());
    enabled.setSelected(rule.isEnabled());
    enabled.setEnabled(true);
    port.setSelectedItem(rule.getPort().toTerm().toString());
    port.setEnabled(true);
    condition.setText(rule.getCondition().toTerm().toString());
    condition.setEnabled(true);
    action.setText(rule.getAction().toTerm().toString());
    action.setEnabled(true);

    applyButton.setEnabled(false);
    revertButton.setEnabled(false);
    deleteButton.setEnabled(true);

    enabled.setForeground(COLOR_UNMODIFIED);
    portLabel.setForeground(COLOR_UNMODIFIED);
    conditionLabel.setForeground(COLOR_UNMODIFIED);
    actionLabel.setForeground(COLOR_UNMODIFIED);

    setModified(false);


    repaint();
  }

  //}}}
  //{{{ public void ruleCreated(DebugProcess process, Rule rule)

  public void ruleCreated(DebugProcess process, Rule rule)
  {
  }

  //}}}
  //{{{ public void ruleDeleted(DebugProcess process, Rule rule)

  public void ruleDeleted(DebugProcess process, Rule rule)
  {
    if (rule == this.rule) {
      clear();
      rule = null;
    }
  }

  //}}}
  //{{{ public void ruleModified(DebugProcess process, Rule rule)

  public void ruleModified(DebugProcess process, Rule rule)
  {
    if (rule == this.rule) {
      ruleSelected(rule);
    }
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
  }

  //}}}
  //{{{ private void setModified(boolean on)

  private void setModified(boolean on)
  {
    modified = on;
    revertButton.setEnabled(on);
    applyButton.setEnabled(on);
  }

  //}}}

  //{{{ public void actionPerformed(ActionEvent event)

  public void actionPerformed(ActionEvent event)
  {
    Object source = event.getSource();

    if (source == enabled) {
      //{{{ Change enabled button to modified

      enabled.setForeground(COLOR_MODIFIED);
      setModified(true);

      //}}}
    } else if (source == port) {
      //{{{ Change port combobox to modified

      if (port.isEnabled()) {
	portLabel.setForeground(COLOR_MODIFIED);
	setModified(true);
      }

      //}}}
    } else if (source == createButton) {
      //{{{ Handle create rule

      String tag = (String)
	JOptionPane.showInternalInputDialog(this,
					    "What tag should the new rule have?",
					    "Create a new Rule",
					    JOptionPane.PLAIN_MESSAGE,
					    null, null, "manual-rule");
      if (tag != null) {
	process.requestRuleCreation(Port.makeStep(), Expr.makeTrue(), Expr.makeTrue(),
				    tag, false);
      }

      //}}}
    } else if (source == revertButton) {
      //{{{ Handle revert rule

      ruleSelected(rule);

      //}}}
    } else if (source == applyButton) {
      //{{{ Handle apply changes

      String portItem = (String)port.getSelectedItem();
      Port port = Port.parse(portItem);
      if (port == null) {
	JOptionPane.showInternalMessageDialog(this, "Illegal port: " + portItem,
					      "Illegal Port",
					      JOptionPane.ERROR_MESSAGE);
	return;
      }

      String condTxt = condition.getText();
      Expr cond = Expr.parse(condTxt);
      if (cond == null) {
	JOptionPane.showInternalMessageDialog(this, "Not an expression: " + condTxt,
					      "Illegal Condition",
					      JOptionPane.ERROR_MESSAGE);
	return;
      }

      String actTxt = action.getText();
      Expr act = Expr.parse(actTxt);
      if (act == null) {
	JOptionPane.showInternalMessageDialog(this, "Not an expression: " + actTxt,
					      "Illegal Action",
					      JOptionPane.ERROR_MESSAGE);
	return;
      }

      boolean enabled = this.enabled.isSelected();

      process.requestRuleModification(rule, port, cond, act, enabled);

      //}}}
    } else if (source == deleteButton) {
      //{{{ Handle delete rule

      process.requestRuleDeletion(rule);

      //}}}
    }
  }

  //}}}
}

//{{{ interface RuleSelectionListener

interface RuleSelectionListener
{
  public void ruleSelected(Rule rule);
}

//}}}

