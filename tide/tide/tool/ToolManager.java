package tide.tool;

import java.util.*;
import javax.swing.*;

import tide.tool.support.*;

public class ToolManager
{
  private JDesktopPane desktop;

  private List processToolList;
  private List processActionList;
  private Map processTools;

  private List adapterToolList;
  private List adapterActionList;
  private Map adapterTools;

  //{{{ public ToolManager(JDesktopPane desktop)

  public ToolManager(JDesktopPane desktop)
  {
    this.desktop = desktop;

    processToolList = new LinkedList();
    processActionList = new LinkedList();
    processTools = new HashMap();

    adapterToolList = new LinkedList();
    adapterActionList = new LinkedList();
    adapterTools = new HashMap();
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

  //{{{ public ProcessTool launchProcessTool(String toolName, DebugProcess process)

  public ProcessTool launchProcessTool(String toolName, DebugProcess process)
  {
    ProcessToolFactory factory = (ProcessToolFactory)processTools.get(toolName);
    ProcessTool tool = factory.createTool(process);

    desktop.add(tool, 1);
    tool.show();
    desktop.moveToFront(tool);

    return tool;
  }

  //}}}
  //{{{ public ProcessTool launchAdapterTool(String toolName, DebugAdapter adapter)

  public AdapterTool launchAdapterTool(String toolName, DebugAdapter adapter)
  {
    AdapterToolFactory factory = (AdapterToolFactory)adapterTools.get(toolName);
    AdapterTool tool = factory.createTool(adapter);
    desktop.add(tool);

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
}
