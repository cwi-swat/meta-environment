package tide.tool;

import tide.tool.support.DebugProcess;

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
