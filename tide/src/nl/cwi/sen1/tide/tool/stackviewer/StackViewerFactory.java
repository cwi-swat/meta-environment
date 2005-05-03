package nl.cwi.sen1.tide.tool.stackviewer;

import javax.swing.Icon;

import nl.cwi.sen1.tide.tool.ProcessTool;
import nl.cwi.sen1.tide.tool.ProcessToolFactory;
import nl.cwi.sen1.tide.tool.ToolManager;
import nl.cwi.sen1.tide.tool.support.DebugProcess;

public class StackViewerFactory
  implements ProcessToolFactory
{
  private ToolManager manager;

  //{{{ public StackViewerFactory(ToolManager manager)

  public StackViewerFactory(ToolManager manager)
  {
    this.manager = manager;
  }

  //}}}
  //{{{ public ProcessTool createTool(DebugProcess process)

  public ProcessTool createTool(DebugProcess process)
  {
    ProcessTool tool = new StackViewer(manager, process);
    return tool;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return "StackViewer";
  }

  //}}}
  //{{{ public Icon getIcon()

  public Icon getIcon()
  {
    return null;
  }

  //}}}
}
