package tide.tool.stackviewer;

import javax.swing.Icon;

import tide.tool.*;
import tide.tool.support.*;

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
