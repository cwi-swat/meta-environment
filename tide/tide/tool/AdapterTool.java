package tide.tool;

import tide.tool.support.DebugAdapter;

abstract public class AdapterTool
  extends TideTool
{
  protected DebugAdapter adapter;

  //{{{ protected AdapterTool(ToolManager manager, DebugAdapter adapter)

  protected AdapterTool(ToolManager manager, DebugAdapter adapter)
  {
    super(manager);
    this.adapter = adapter;
  }

  //}}}
}
