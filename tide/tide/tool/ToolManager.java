package tide.tool;

import java.awt.*;
import java.beans.PropertyVetoException;
import java.io.IOException;
import java.util.*;

import javax.swing.*;

import tide.PreferenceSet;
import tide.tool.ruleinspector.*;
import tide.tool.support.*;

public class ToolManager
{
  private JDesktopPane desktop;

  private Map tideTools;

  private java.util.List processToolList;
  private java.util.List processActionList;
  private Map processTools;

  private java.util.List adapterToolList;
  private java.util.List adapterActionList;
  private Map adapterTools;

  private Map toolInstances;

  private PreferenceSet preferences;

  //{{{ public ToolManager(JDesktopPane desktop, Properties defaults)

  public ToolManager(JDesktopPane desktop, Properties defaults)
  {
    this.desktop = desktop;

    tideTools = new HashMap();

    processToolList = new LinkedList();
    processActionList = new LinkedList();
    processTools = new HashMap();

    adapterToolList = new LinkedList();
    adapterActionList = new LinkedList();
    adapterTools = new HashMap();

    toolInstances = new HashMap();

    preferences = new PreferenceSet(defaults);

    try {
      preferences.loadPreferences();
    } catch (IOException e) {
      System.err.println("Warning: could not load preferences: "
			 + e.getMessage());
    }
  }

  //}}}

  //{{{ public PreferenceSet getPreferences()

  public PreferenceSet getPreferences()
  {
    return preferences;
  }

  //}}}

  //{{{ public TideTool getTool(String toolName, Object target)

  public TideTool getTool(String toolName, Object target)
  {
    Map tools = (Map)toolInstances.get(toolName);
    if (tools != null) {
      return (TideTool)tools.get(target);
    }

    return null;
  }

  //}}}
  //{{{ public void putTool(String toolName, Object target, TideTool tool)

  public void putTool(String toolName, Object target, TideTool tool)
  {
    tool.setName(toolName);
    tool.setTarget(target);
    Map tools = (Map)toolInstances.get(toolName);
    if (tools == null) {
      tools = new HashMap();
      toolInstances.put(toolName, tools);
    }

    tools.put(target, tool);
  }

  //}}}
  //{{{ public void removeTool(TideTool tool)

  public void removeTool(TideTool tool)
  {
    Map tools = (Map)toolInstances.get(tool.getName());
    tools.remove(tool.getTarget());
  }

  //}}}

  //{{{ public void registerTool(TideToolFactory factory)

  public void registerTool(TideToolFactory factory)
  {
    String name = factory.getName();
    tideTools.put(name, factory);
  }

  //}}}

  //{{{ public void registerProcessTool(ProcessToolFactory factory)

  public void registerProcessTool(ProcessToolFactory factory)
  {
    String name = factory.getName();
    processToolList.add(name);
    processActionList.add(new ProcessAction(name, factory.getIcon(), this));
    processTools.put(name, factory);
  }

  //}}}
  //{{{ public void registerAdapterTool(AdapterToolFactory factory)

  public void registerAdapterTool(AdapterToolFactory factory)
  {
    String name = factory.getName();

    adapterToolList.add(name);
    adapterActionList.add(new AdapterAction(name, factory.getIcon(), this));
    adapterTools.put(name, factory);
  }

  //}}}

  //{{{ public Iterator processToolIterator()

  public Iterator processToolIterator()
  {
    return processToolList.iterator();
  }

  //}}}
  //{{{ public Iterator adapterToolIterator()

  public Iterator adapterToolIterator()
  {
    return adapterToolList.iterator();
  }

  //}}}
  //{{{ public Iterator processActionIterator()

  public Iterator processActionIterator()
  {
    return processActionList.iterator();
  }

  //}}}
  //{{{ public Iterator adapterActionIterator()

  public Iterator adapterActionIterator()
  {
    return adapterActionList.iterator();
  }

  //}}}

  //{{{ public TideTool launchTool(String toolName)

  public TideTool launchTool(String toolName)
  {
    TideTool tool = (TideTool)getTool(toolName, this);
    if (tool == null) {
      TideToolFactory factory =
	(TideToolFactory)tideTools.get(toolName);
      tool = factory.createTool();
      putTool(toolName, this, tool);

      desktop.add(tool, 1);
      tool.show();
    }
    try {
      tool.setIcon(false);
    } catch (PropertyVetoException e) {
      System.err.println("Warning: cannot deiconify process tool: " +
			 toolName);
    }
    desktop.moveToFront(tool);

    return tool;

  }

  //}}}
  //{{{ public void displayError(String msg)

  public void displayError(String msg)
  {
    ErrorWindow error = new ErrorWindow(msg);
    showDialog(error);
  }

  //}}}
  //{{{ public void showDialog(TideDialog dialog)

  public void showDialog(TideDialog dialog)
  {
    desktop.add(dialog, 0);
    dialog.show();
  }

  //}}}

  //{{{ public ProcessTool launchProcessTool(String toolName, DebugProcess process)

  public ProcessTool launchProcessTool(String toolName, DebugProcess process)
  {
    ProcessTool tool = (ProcessTool)getTool(toolName, process);
    if (tool == null) {
      ProcessToolFactory factory =
	(ProcessToolFactory)processTools.get(toolName);
      tool = factory.createTool(process);
      putTool(toolName, process, tool);

      desktop.add(tool, 1);
      tool.show();
    }
    try {
      tool.setIcon(false);
    } catch (PropertyVetoException e) {
      System.err.println("Warning: cannot deiconify process tool: " +
			 toolName);
    }
    desktop.moveToFront(tool);

    return tool;
  }

  //}}}
  //{{{ public ProcessTool launchAdapterTool(String toolName, DebugAdapter adapter)

  public AdapterTool launchAdapterTool(String toolName, DebugAdapter adapter)
  {
    AdapterTool tool = (AdapterTool)getTool(toolName, adapter);
    if (tool == null) {
      AdapterToolFactory factory =
	(AdapterToolFactory)adapterTools.get(toolName);
      tool = factory.createTool(adapter);
      putTool(toolName, adapter, tool);
      desktop.add(tool);
      tool.show();
    }
    try {
      tool.setIcon(false);
    } catch (PropertyVetoException e) {
      System.err.println("Warning: cannot deiconify adapter tool: " +
			 toolName);
    }
    desktop.moveToFront(tool);

    return tool;
  }

  //}}}

  //{{{ public void setCurrentProcess(DebugProcess process)

  public void setCurrentProcess(DebugProcess process)
  {
    Iterator iter = processActionIterator();
    while (iter.hasNext()) {
      ProcessAction action = (ProcessAction)iter.next();
      action.setProcess(process);
    }
  }

  //}}}
  //{{{ public void setCurrentAdapter(DebugAdapter adapter)

  public void setCurrentAdapter(DebugAdapter adapter)
  {
    Iterator iter = adapterActionIterator();
    while (iter.hasNext()) {
      AdapterAction action = (AdapterAction)iter.next();
      action.setAdapter(adapter);
    }
  }

  //}}}

  //{{{ public void editRule(DebugProcess process, Rule rule)

  public void editRule(DebugProcess process, Rule rule)
  {
    String toolName = RuleInspectorFactory.NAME;
    RuleInspector inspector = 
      (RuleInspector)launchProcessTool(toolName, process);
    inspector.editRule(rule);
  }

  //}}}
}

class ErrorWindow
  extends TideDialog
{
  private JButton ok;
  private JLabel label;

  //{{{ public ErrorWindow(String msg)

  public ErrorWindow(String msg)
  {
    super("Tide Error!", DIALOG_OK);
    label = new JLabel(msg, JLabel.CENTER);
    init();
  }

  //}}}

  //{{{ public void addContent(JPanel panel)

  public void addContent(JPanel panel)
  {
    panel.setLayout(new GridLayout(3, 1));

    label.setForeground(Color.red);

    panel.add(new JPanel());
    panel.add(label);
    panel.add(new JPanel());
  }

  //}}}
}
