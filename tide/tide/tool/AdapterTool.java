package tide.tool;

import javax.swing.*;

import tide.tool.support.*;

abstract public class AdapterTool
  extends JInternalFrame
{
  protected DebugAdapter adapter;

  //{{{ protected AdapterTool(DebugAdapter adapter)

  protected AdapterTool(DebugAdapter adapter)
  {
    this.adapter = adapter;
  }

  //}}}
}
