package tide.tool;

import javax.swing.*;

import tide.tool.support.*;

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
