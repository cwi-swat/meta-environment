package nl.cwi.sen1.tide.tool.ruleinspector;

import javax.swing.Icon;

import nl.cwi.sen1.tide.tool.ProcessTool;
import nl.cwi.sen1.tide.tool.ProcessToolFactory;
import nl.cwi.sen1.tide.tool.ToolManager;
import nl.cwi.sen1.tide.tool.support.DebugProcess;

public class RuleInspectorFactory
  implements ProcessToolFactory
{
  public static String NAME = "RuleInspector";
  private ToolManager manager;

  //{{{ public RuleInspectorFactory(ToolManager manager)

  public RuleInspectorFactory(ToolManager manager)
  {
    this.manager = manager;
  }

  //}}}
  //{{{ public ProcessTool createTool(DebugProcess process)

  public ProcessTool createTool(DebugProcess process)
  {
    ProcessTool tool = new RuleInspector(manager, process);
    return tool;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return "RuleInspector";
  }

  //}}}
  //{{{ public Icon getIcon()

  public Icon getIcon()
  {
    return null;
  }

  //}}}
}
