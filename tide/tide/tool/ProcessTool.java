package tide.tool;

import javax.swing.*;

import tide.tool.support.*;

abstract public class ProcessTool
  extends TideTool
{
  protected DebugProcess process;

  //{{{ protected ProcessTool(ToolManager manager, DebugProcess process)

  protected ProcessTool(ToolManager manager, DebugProcess process)
  {
    super(manager);

    this.process = process;
  }

  //}}}
}
