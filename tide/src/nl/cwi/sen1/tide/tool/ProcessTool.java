package nl.cwi.sen1.tide.tool;

import nl.cwi.sen1.tide.tool.support.DebugProcess;

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
