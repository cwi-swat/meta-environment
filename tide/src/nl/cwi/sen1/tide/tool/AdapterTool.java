package nl.cwi.sen1.tide.tool;

import nl.cwi.sen1.tide.tool.TideTool;
import nl.cwi.sen1.tide.tool.ToolManager;
import nl.cwi.sen1.tide.tool.support.DebugAdapter;

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
