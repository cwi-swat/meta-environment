package tide.tool.srcviewer;

import javax.swing.Icon;

import tide.tool.*;
import tide.tool.support.*;

public class SourceViewerFactory
  implements ProcessToolFactory
{
  private ToolManager manager;

  //{{{ public SourceViewerFactory(ToolManager manager)

  public SourceViewerFactory(ToolManager manager)
  {
    this.manager = manager;
  }

  //}}}
  //{{{ public ProcessTool createTool(DebugProcess process)

  public ProcessTool createTool(DebugProcess process)
  {
    ProcessTool tool = new SourceViewer(manager, process);
    return tool;
  }

  //}}}
  //{{{ public String getName()

  public String getName()
  {
    return "SourceViewer";
  }

  //}}}
  //{{{ public Icon getIcon()

  public Icon getIcon()
  {
    return null;
  }

  //}}}
}
